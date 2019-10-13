#pragma once
#ifdef HPR_BUILD_DLL
#define HPR_API __declspec(dllexport)
#else
#define HPR_API __declspec(dllimport)
#endif