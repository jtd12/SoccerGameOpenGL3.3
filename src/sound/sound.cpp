#include"sound.hpp"



sound::sound() {
    device = alcOpenDevice(nullptr);
    if (!device) {
        std::cerr << "OpenAL: échec ouverture device audio.\n";
        return;
    }

    context = alcCreateContext(device, nullptr);
    if (!context || !alcMakeContextCurrent(context)) {
        std::cerr << "OpenAL: échec création contexte.\n";
        return;
    }

    alGenSources(1, &source);
    alGenBuffers(1, &buffer);
}

sound::~sound() {
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(nullptr);
    if (context) alcDestroyContext(context);
    if (device) alcCloseDevice(device);
}

bool sound::loadWavData(const std::string& filename, ALenum& format, ALvoid*& data, ALsizei& size, ALsizei& freq) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) return false;

    char chunk[4];
    file.read(chunk, 4); // "RIFF"
    file.ignore(4);      // chunk size
    file.read(chunk, 4); // "WAVE"

    file.read(chunk, 4); // "fmt "
    int subchunk1Size;
    file.read(reinterpret_cast<char*>(&subchunk1Size), 4);

    short audioFormat, numChannels, bitsPerSample;
    file.read(reinterpret_cast<char*>(&audioFormat), 2);
    file.read(reinterpret_cast<char*>(&numChannels), 2);
    file.read(reinterpret_cast<char*>(&freq), 4);
    file.ignore(6); // byte rate + block align
    file.read(reinterpret_cast<char*>(&bitsPerSample), 2);

    file.read(chunk, 4); // "data"
    while (strncmp(chunk, "data", 4) != 0) {
        int skipSize;
        file.read(reinterpret_cast<char*>(&skipSize), 4);
        file.ignore(skipSize);
        file.read(chunk, 4);
    }

    file.read(reinterpret_cast<char*>(&size), 4);
    data = new char[size];
    file.read(reinterpret_cast<char*>(data), size);

    // Détermine format OpenAL
    if (numChannels == 1)
        format = (bitsPerSample == 8) ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
    else if (numChannels == 2)
        format = (bitsPerSample == 8) ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
    else
        return false;

    return true;
}

bool sound::loadWav(const std::string& filename) {
    ALenum format;
    ALvoid* data;
    ALsizei size, freq;

    if (!loadWavData(filename, format, data, size, freq)) {
        std::cerr << "Erreur de lecture WAV : " << filename << std::endl;
        return false;
    }

    alBufferData(buffer, format, data, size, freq);
    delete[] static_cast<char*>(data);

    alSourcei(source, AL_BUFFER, buffer);
    alSourcef(source, AL_GAIN, 1.0f);
    alSourcef(source, AL_PITCH, 1.0f);
 	alSourcei(source, AL_LOOPING, AL_TRUE);  // Active la boucle

    return true;
}

void sound::play() {

    alSourcePlay(source);
}

void sound::stop() {
    alSourceStop(source);
}

bool sound::isPlaying() const {
    ALint state;
    alGetSourcei(source, AL_SOURCE_STATE, &state);
    return state == AL_PLAYING;
}

