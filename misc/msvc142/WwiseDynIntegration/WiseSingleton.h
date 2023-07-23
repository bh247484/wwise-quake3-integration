#pragma once

class WiseSingleton {
public:
    WiseSingleton();
    ~WiseSingleton();
    int InitSoundEngine();
    void ProcessAudio();
    void TerminateSoundEngine();
    void ForwardEvent(int sfx, int entnum);
};
