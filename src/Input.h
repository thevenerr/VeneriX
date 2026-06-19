#pragma once
#include "Core.h"

// Letters
#define VENERIX_KEY_A 65
#define VENERIX_KEY_B 66
#define VENERIX_KEY_C 67
#define VENERIX_KEY_D 68
#define VENERIX_KEY_E 69
#define VENERIX_KEY_F 70
#define VENERIX_KEY_G 71
#define VENERIX_KEY_H 72
#define VENERIX_KEY_I 73
#define VENERIX_KEY_J 74
#define VENERIX_KEY_K 75
#define VENERIX_KEY_L 76
#define VENERIX_KEY_M 77
#define VENERIX_KEY_N 78
#define VENERIX_KEY_O 79
#define VENERIX_KEY_P 80
#define VENERIX_KEY_Q 81
#define VENERIX_KEY_R 82
#define VENERIX_KEY_S 83
#define VENERIX_KEY_T 84
#define VENERIX_KEY_U 85
#define VENERIX_KEY_V 86
#define VENERIX_KEY_W 87
#define VENERIX_KEY_X 88
#define VENERIX_KEY_Y 89
#define VENERIX_KEY_Z 90

// Numbers (top row)
#define VENERIX_KEY_0 48
#define VENERIX_KEY_1 49
#define VENERIX_KEY_2 50
#define VENERIX_KEY_3 51
#define VENERIX_KEY_4 52
#define VENERIX_KEY_5 53
#define VENERIX_KEY_6 54
#define VENERIX_KEY_7 55
#define VENERIX_KEY_8 56
#define VENERIX_KEY_9 57

// Function keys
#define VENERIX_KEY_F1  290
#define VENERIX_KEY_F2  291
#define VENERIX_KEY_F3  292
#define VENERIX_KEY_F4  293
#define VENERIX_KEY_F5  294
#define VENERIX_KEY_F6  295
#define VENERIX_KEY_F7  296
#define VENERIX_KEY_F8  297
#define VENERIX_KEY_F9  298
#define VENERIX_KEY_F10 299
#define VENERIX_KEY_F11 300
#define VENERIX_KEY_F12 301

// Arrows
#define VENERIX_KEY_RIGHT 262
#define VENERIX_KEY_LEFT  263
#define VENERIX_KEY_DOWN  264
#define VENERIX_KEY_UP    265

// Special keys
#define VENERIX_KEY_SPACE      32
#define VENERIX_KEY_ESCAPE     256
#define VENERIX_KEY_ENTER      257
#define VENERIX_KEY_TAB        258
#define VENERIX_KEY_BACKSPACE  259
#define VENERIX_KEY_LEFT_SHIFT  340
#define VENERIX_KEY_LEFT_CONTROL 341
#define VENERIX_KEY_LEFT_ALT    342

namespace VeneriX {
    class VENERIX_API Input {
    public:
        static bool IsKeyPressed(int keycode);
    };
}