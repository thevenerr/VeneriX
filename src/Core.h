#pragma once

#ifdef VENERIX_BUILD_DLL
#define VENERIX_API __declspec(dllexport)
#else
#define VENERIX_API __declspec(dllimport)
#endif