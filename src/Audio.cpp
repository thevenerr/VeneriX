#include "Audio.h"
#include <iostream>

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

namespace VeneriX {

    static ma_engine engine;
    static ma_sound bgmSound;
    static bool isMusicLoaded = false;

    void Audio::Init() {
        if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
            std::cout << "Engine Error: Failed to initialize Audio Engine!" << std::endl;
        }
        else {
            std::cout << "Audio Engine Initialized." << std::endl;
        }
    }

    void Audio::Shutdown() {
        if (isMusicLoaded) {
            ma_sound_uninit(&bgmSound);
        }
        ma_engine_uninit(&engine);
    }

    void Audio::PlaySFX(const std::string& filepath) {
        ma_engine_play_sound(&engine, filepath.c_str(), NULL);
    }

    void Audio::PlayMusic(const std::string& filepath) {
        if (isMusicLoaded) {
            ma_sound_uninit(&bgmSound);
        }

        ma_result result = ma_sound_init_from_file(&engine, filepath.c_str(), 0, NULL, NULL, &bgmSound);
        if (result == MA_SUCCESS) {
            ma_sound_set_looping(&bgmSound, MA_TRUE);
            ma_sound_start(&bgmSound);
            isMusicLoaded = true;
        }
        else {
            std::cout << "Engine Error: Failed to load music file: " << filepath << std::endl;
        }
    }

    void Audio::StopMusic() {
        if (isMusicLoaded) {
            ma_sound_stop(&bgmSound);
        }
    }
}