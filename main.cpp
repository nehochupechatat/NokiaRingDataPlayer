#define MA_NO_DECODING
#define MA_NO_ENCODING
#define RINGDATA_INCLUDE_SEQUENCIES
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include "ringdataplayer.h"
#include "jamsession.h"

#include <stdio.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

void main_loop__em()
{
}
#endif

#define DEVICE_FORMAT       ma_format_f32
#define DEVICE_CHANNELS     1
#define DEVICE_SAMPLE_RATE  96000

ma_pulsewave squareWave;

void TONE(double freq, int ms)
{
	ma_pulsewave_set_frequency(&squareWave, freq);
	if(freq == 0)
		ma_pulsewave_set_amplitude(&squareWave, 0.0);
	else
		ma_pulsewave_set_amplitude(&squareWave, 0.2);
	SongDelay(ms);
}

float CubicInterpolate(float p0, float p1, float p2, float p3, float t) 
{
    float a0 = p3 - p2 - p0 + p1;
    float a1 = p0 - p1 - a0;
    float a2 = p2 - p0;
    float a3 = p1;

    return a0 * t * t * t + a1 * t * t + a2 * t + a3;
}

void PlayToneSequence(std::vector<ToneData> seq)
{
    for (int i = 0; i < seq.size(); i++) 
	{
        TONE(seq[i].frequency, seq[i].duration);
    }
	TONE(0,0);
}

void AudioCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_pulsewave* pSineWave;

    MA_ASSERT(pDevice->playback.channels == DEVICE_CHANNELS);
	float* rawOutput = (float*)pOutput;
    pSineWave = (ma_pulsewave*)pDevice->pUserData;
    MA_ASSERT(pSineWave != NULL);
	
	std::vector<float> interpolatedOutput(frameCount);
    ma_pulsewave_read_pcm_frames(pSineWave, rawOutput, frameCount, NULL);
	
	for (ma_uint32 i = 1; i < frameCount - 2; ++i) 
	{
        float t = (i / float(frameCount));

        // Apply cubic interpolation between four neighboring samples
        interpolatedOutput[i] = CubicInterpolate(rawOutput[i-1], rawOutput[i], rawOutput[i+1], rawOutput[i+2], t);
    }

    // Handle the boundary conditions (for simplicity, linear interpolation)
    interpolatedOutput[0] = rawOutput[0];
    interpolatedOutput[frameCount - 1] = rawOutput[frameCount - 1];

    // Copy the interpolated samples to the output
    memcpy(rawOutput, interpolatedOutput.data(), frameCount * sizeof(float));

    (void)pInput;   /* Unused. */
}

int main(int argc, char** argv)
{
	ma_device_config deviceConfig;
	ma_device device;
	ma_pulsewave_config squareWaveConfig;

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = DEVICE_FORMAT;
    deviceConfig.playback.channels = DEVICE_CHANNELS;
    deviceConfig.sampleRate        = DEVICE_SAMPLE_RATE;
    deviceConfig.dataCallback      = AudioCallback;
    deviceConfig.pUserData         = &squareWave;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        return -4;
    }

    printf("Playing monophonic ringtone...\n");

    squareWaveConfig =  ma_pulsewave_config_init(device.playback.format, device.playback.channels, device.sampleRate, (double)42/1024, 0.2, 0);
    ma_pulsewave_init(&squareWaveConfig, &squareWave);
    if (ma_device_start(&device) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        return -5;
    }
	PlayToneSequence(ring_undefined_seq);
    ma_device_uninit(&device);
    
    (void)argc;
    (void)argv;
    return 0;
}