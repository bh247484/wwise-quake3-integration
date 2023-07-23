#include "pch.h"
#define BANKNAME_INIT L"Init.bnk"

CAkFilePackageLowLevelIOBlocking g_lowLevelIO;

int WiseInitSoundEngine()
{
    // Memory Manager.
    AkMemSettings memSettings;
    AK::MemoryMgr::GetDefaultSettings(memSettings);

    if (AK::MemoryMgr::Init(&memSettings) != AK_Success)
    {
        assert(!"Could not create the memory manager.");
        return 0;
    }

    // Streaming Manager.
    AkStreamMgrSettings stmSettings;
    AK::StreamMgr::GetDefaultSettings(stmSettings);

    if (!AK::StreamMgr::Create(stmSettings))
    {
        assert(!"Could not create the Streaming Manager");
        return 0;
    }
    
    // System/OS Device IO.
    //CAkFilePackageLowLevelIOBlocking g_lowLevelIO;
    AkDeviceSettings deviceSettings;
    AK::StreamMgr::GetDefaultDeviceSettings(deviceSettings);

    if (g_lowLevelIO.Init(deviceSettings) != AK_Success)
    {
        assert(!"Could not create the streaming device and Low-Level I/O system");
        return 0;
    }

    // Sound Engine.
    AkInitSettings initSettings;
    AkPlatformInitSettings platformInitSettings;
    AK::SoundEngine::GetDefaultInitSettings(initSettings);
    AK::SoundEngine::GetDefaultPlatformInitSettings(platformInitSettings);

    if (AK::SoundEngine::Init(&initSettings, &platformInitSettings) != AK_Success)
    {
        assert(!"Could not initialize the Sound Engine.");
        return 0;
    }

    // Music Engine.
    AkMusicSettings musicInit;
    AK::MusicEngine::GetDefaultInitSettings(musicInit);

    if (AK::MusicEngine::Init(&musicInit) != AK_Success)
    {
        assert(!"Could not initialize the Music Engine.");
        return false;
    }

    // Comm network for local debugging.
    #ifndef AK_OPTIMIZED
    AkCommSettings commSettings;
    AK::Comm::GetDefaultInitSettings(commSettings);

    if (AK::Comm::Init(commSettings) != AK_Success)
    {
        assert(!"Could not initialize communication.");
        return false;
    }
    #endif // AK_OPTIMIZED

    // Load Sound Banks
    g_lowLevelIO.SetBasePath(AKTEXT("C:\\Users\\bh247\\Documents\\WwiseProjects\\Quake3\\GeneratedSoundBanks\\Windows"));
    AK::StreamMgr::SetCurrentLanguage(AKTEXT("English(US)"));

    AkBankID bankID; // Not used. These banks can be unloaded with their file name.
    AKRESULT eResult = AK::SoundEngine::LoadBank(BANKNAME_INIT, bankID);
    assert(eResult == AK_Success);
}

void WiseProcessAudio()
{
    AK::SoundEngine::RenderAudio();
}

void WiseTerminateSoundEngine()
{
    #ifndef AK_OPTIMIZED
    AK::Comm::Term();
    #endif // AK_OPTIMIZED
    AK::MusicEngine::Term();
    AK::SoundEngine::Term();
    if (AK::IAkStreamMgr::Get()) AK::IAkStreamMgr::Get()->Destroy();
    AK::MemoryMgr::Term();
}

int WiseForward(int sfx, int entnum)
{
    std::ofstream debugLog;
    debugLog.open("C:\\Users\\bh247\\Desktop\\debug.txt", std::ios_base::app);
    debugLog << "SFX: " << sfx << "\n";
    debugLog << "Entnum: " << entnum << "\n";
    return 0;
}

//int main() {
//	std::cout << "test" << std::endl;
//	return 0;
//}
