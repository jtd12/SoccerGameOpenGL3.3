#ifndef DEF_SOUND_HPP
#define DEF_SOUND_HPP
#include<fstream>
#include"C:\library\mathsutils\include\vector.h"
#include<iostream>
#include<cstring>
#include<vector>
#include"C:\library\glm\glm\glm.hpp"
#include <C:/library/glm/glm/gtc/matrix_transform.hpp>
#include"C:\library\OpenAL 1.1 SDK\include\al.h"
#include"C:\library\OpenAL 1.1 SDK\include\alc.h"

using namespace std;

class sound
{
public:
   sound();
   ~sound();

    bool loadWav(const std::string& filename);
    void play();
    void stop();
    bool isPlaying() const;

private:
    ALCdevice* device = nullptr;
    ALCcontext* context = nullptr;
    ALuint source = 0;
    ALuint buffer = 0;

    bool loadWavData(const std::string& filename, ALenum& format, ALvoid*& data, ALsizei& size, ALsizei& freq);
};
#endif
