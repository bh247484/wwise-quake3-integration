// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
// Core lib includes.
#include <iostream>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <string>
// Wwise includes.
#include <Wwise_IDs.h> // contains bank and events ids in GeneratedSoundBanks header
#include <AK/SoundEngine/Common/AkMemoryMgr.h>
#include <AK/SoundEngine/Common/AkModule.h>
#include <AK/SoundEngine/Common/IAkStreamMgr.h>
#include <AK/MusicEngine/Common/AkMusicEngine.h>
#ifndef AK_OPTIMIZED
#include <AK/Comm/AkCommunication.h>
#endif // AK_OPTIMIZED
#include <AK/Tools/Common/AkPlatformFuncs.h>
#include <AkFilePackageLowLevelIOBlocking.h>
#include <AkFilePackage.h>
#include <AkFilePackageLUT.h>
// Custom implementation includes.
#include "WiseWrapper.h"
#include "WiseSingleton.h"

#endif //PCH_H
