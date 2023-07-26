#include "pch.h"
#define BANKNAME_INIT L"Init.bnk"

static std::unique_ptr<WiseSingleton> WiseMain = std::make_unique<WiseSingleton>();

void WiseInit()
{
    WiseMain->InitSoundEngine();
}

void WiseFrameTick()
{
    WiseMain->ProcessAudio();
}

void WiseTerminate()
{
    WiseMain->TerminateSoundEngine();
}

void WiseForward(int sfx, int entnum)
{
    WiseMain->ForwardEvent(sfx, entnum);
}

void InterceptSFXName(int hash, const char* name)
{
    std::ofstream debugLog;
    debugLog.open("C:\\Users\\bh247\\Desktop\\hashdebug.txt", std::ios_base::app);
    debugLog << "Hash: " << hash << "\n";
    debugLog << "Name: " << name << "\n";
}