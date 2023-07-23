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

EXTERNC WISEWRAPPER_API int WiseForward(int sfx, int entnum);

EXTERNC WISEWRAPPER_API int WiseInitSoundEngine();

EXTERNC WISEWRAPPER_API void WiseProcessAudio();

EXTERNC WISEWRAPPER_API void WiseTerminateSoundEngine();

//WISEWRAPPER_API bool InitSoundEngine();

#undef EXTERNC
