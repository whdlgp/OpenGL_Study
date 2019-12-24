#include "texture_loader.hpp"

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Image loader
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int texture_loader(image_t& image)
{
    //fliping option
    stbi_set_flip_vertically_on_load(true);

    // Create texture object
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // load image
    unsigned char *data = stbi_load(image.name.c_str(), &image.width, &image.height, &image.channel, 0);

    if (data)
    {
        switch(image.type)
        {
            case JPG:
            // copy texture to GPU
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            // MIPMAP
            glGenerateMipmap(GL_TEXTURE_2D);
            break;

            case PNG:
            // copy texture to GPU
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            // MIPMAP
            glGenerateMipmap(GL_TEXTURE_2D);
            break;

            default:
            std::cout << "Can not support this type" << std::endl;
            break;
        }

    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    // un-load image
    stbi_image_free(data);

    return texture;
}