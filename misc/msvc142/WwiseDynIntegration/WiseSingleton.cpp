#include "pch.h"
/**
* These should be defined over in the header file but couldn't get Ak types recognized there.
* Luckily this is a Singleton class and these are static values.
*/
CAkFilePackageLowLevelIOBlocking g_lowLevelIO;
/**
* To keep things simple this declares a single global game object and a single global listener.
* All events are associated with the global game object which is in turn associated with the global listener.
* This prohibits spatialization but massively simplifies things for this simple test application/integration. 
*/
const AkGameObjectID globalGameObj = 1;
const AkGameObjectID globalListener = 2;

WiseSingleton::WiseSingleton() {
}
WiseSingleton::~WiseSingleton() {
}

int WiseSingleton::InitSoundEngine()
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

    // Tried to load banks explicitly with AK::BANKS ids in header file, refused to work.
    AkUniqueID initBankId;
    AKRESULT initRes = AK::SoundEngine::LoadBank(L"Init.bnk", initBankId);
    assert(initRes == AK_Success);
    AkUniqueID mainBankId;
    AKRESULT mainResult = AK::SoundEngine::LoadBank(L"Main.bnk", mainBankId);
    assert(mainResult == AK_Success);

    // Register global game obj and associated listener.
    AK::SoundEngine::RegisterGameObj(globalGameObj, "Global Game Object");
    AK::SoundEngine::RegisterGameObj(globalListener, "Global Listener");
    AK::SoundEngine::SetDefaultListeners(&globalListener, 1);

    // Initial sound event trigger, use to play theme music.
    AK::SoundEngine::PostEvent(AK::EVENTS::PLAY_BLIP, globalGameObj);
}

void WiseSingleton::ProcessAudio()
{
    AK::SoundEngine::RenderAudio();
}

void WiseSingleton::TerminateSoundEngine()
{
    #ifndef AK_OPTIMIZED
    AK::Comm::Term();
    #endif // AK_OPTIMIZED
    AK::MusicEngine::Term();
    AK::SoundEngine::Term();
    if (AK::IAkStreamMgr::Get()) AK::IAkStreamMgr::Get()->Destroy();
    AK::MemoryMgr::Term();
}

void WiseSingleton::ForwardEvent(int sfx, int entnum)
{
    AK::SoundEngine::PostEvent(AK::EVENTS::PLAY_BLIP, globalGameObj);
    std::ofstream debugLog;
    debugLog.open("C:\\Users\\bh247\\Desktop\\debug.txt", std::ios_base::app);
    debugLog << "SFX: " << sfx << "\n";
    debugLog << "Entnum: " << entnum << "\n";
}

std::unordered_map<int, std::string> eventMap = {
    { 1, "value1"},
    { 1, "value2"},
};
