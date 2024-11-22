#include "ringdataplayer.h"
#include <thread>
#include <chrono>

void SongDelay(int ms) 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

//stub
void ringing_tone_data(char id, char name, char unk, int unk2)
{

}

int TONE_TIME_IN_MS(int ms)
{
	return ms;
}