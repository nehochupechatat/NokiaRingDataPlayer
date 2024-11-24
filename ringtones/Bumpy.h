//(C) 2024 HMD Global. All rights reserved.
//Composed by Markus Castren

#ifdef RINGDATA_INCLUDE_SEQUENCIES
const std::vector<ToneData> ring_jumpin_seq = {
        /*Tempo: 300bpm*/        
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(175)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_H, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_B, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_B, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_B, TONE_TIME_IN_MS(100)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(100)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_B, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_B, TONE_TIME_IN_MS(100)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(100)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(175)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_C, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(100)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(100)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(125)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(175)},
        {AUD_TONE_RING_FREQ_F, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_G, TONE_TIME_IN_MS(25)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(100)},
        {AUD_TONE_RING_FREQ_D, TONE_TIME_IN_MS(25)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(75)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(100)},
        {AUD_TONE_FREQ_OFF, TONE_TIME_IN_MS(175)},
        {AUD_TONE_RING_FREQ_E, TONE_TIME_IN_MS(25)}
};
#endif