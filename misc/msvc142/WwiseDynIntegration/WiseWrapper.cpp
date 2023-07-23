#include "pch.h"
#define BANKNAME_INIT L"Init.bnk"

WiseSingleton* WiseMain = new WiseSingleton();

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
