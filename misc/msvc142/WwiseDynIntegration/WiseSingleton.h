#pragma once

class WiseSingleton {
public:
    WiseSingleton();
    ~WiseSingleton();
    int InitSoundEngine();
    void ProcessAudio();
    void TerminateSoundEngine();
    void ForwardEvent(int sfx, int entnum);
private:
    std::unordered_map<int, std::string> eventMap;
};
