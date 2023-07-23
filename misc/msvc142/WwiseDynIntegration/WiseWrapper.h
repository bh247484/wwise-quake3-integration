#pragma once

#ifdef WISEWRAPPER_EXPORTS
#define WISEWRAPPER_API __declspec(dllexport)
#else
#define WISEWRAPPER_API __declspec(dllimport)
#endif

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC WISEWRAPPER_API void WiseInit();

EXTERNC WISEWRAPPER_API void WiseFrameTick();

EXTERNC WISEWRAPPER_API void WiseTerminate();

EXTERNC WISEWRAPPER_API void WiseForward(int sfx, int entnum);

//WISEWRAPPER_API bool InitSoundEngine();

#undef EXTERNC
