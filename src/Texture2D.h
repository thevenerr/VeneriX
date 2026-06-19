#pragma once
#include "Core.h"
#include <string>

namespace VeneriX {
    class VENERIX_API Texture2D {
    public:
        // Конструктор принимает путь к файлу (например "assets/grass.jpg")
        Texture2D(const std::string& path);
        ~Texture2D();

        // Функции для активации текстуры перед отрисовкой
        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }

    private:
        unsigned int m_RendererID;
        int m_Width, m_Height, m_Channels;
    };
}