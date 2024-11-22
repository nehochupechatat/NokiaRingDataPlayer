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
#define DEVICE_CHANNELS     2
#define DEVICE_SAMPLE_RATE  48000

ma_waveform squareWave;

void TONE(double freq, int ms)
{
	ma_waveform_set_frequency(&squareWave, freq);
	SongDelay(ms);
}

void PlayToneSequence(std::vector<ToneData> seq)
{
    for (int i = 0; i < seq.size(); i++) 
	{
        TONE(seq[i].frequency, seq[i].duration);
    }
	TONE(0,0);
}

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_waveform* pSineWave;

    MA_ASSERT(pDevice->playback.channels == DEVICE_CHANNELS);

    pSineWave = (ma_waveform*)pDevice->pUserData;
    MA_ASSERT(pSineWave != NULL);

    ma_waveform_read_pcm_frames(pSineWave, pOutput, frameCount, NULL);

    (void)pInput;   /* Unused. */
}

int main(int argc, char** argv)
{
	ma_device_config deviceConfig;
	ma_device device;
	ma_waveform_config squareWaveConfig;

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = DEVICE_FORMAT;
    deviceConfig.playback.channels = DEVICE_CHANNELS;
    deviceConfig.sampleRate        = DEVICE_SAMPLE_RATE;
    deviceConfig.dataCallback      = data_callback;
    deviceConfig.pUserData         = &squareWave;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        return -4;
    }

    printf("Device Name: %s\n", device.playback.name);

    squareWaveConfig = ma_waveform_config_init(device.playback.format, device.playback.channels, device.sampleRate, ma_waveform_type_square, 0.2, 0);
    ma_waveform_init(&squareWaveConfig, &squareWave);
	
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