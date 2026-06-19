#pragma once
#include "Core.h"
#include <string>

namespace VeneriX {
    class VENERIX_API Audio {
    public:
        static void Init();
        static void Shutdown();

        static void PlaySFX(const std::string& filepath);

        static void PlayMusic(const std::string& filepath);
        static void StopMusic();
    };
}