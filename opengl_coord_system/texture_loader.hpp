#pragma once

// ETC
#include <iostream>
#include <string>

// Texture loader
enum image_types
{
    JPG = 0,
    PNG = 1
};
typedef struct image_t
{
    int width;
    int height;
    int channel;
    int type;
    std::string name;
}image_t;
unsigned int texture_loader(image_t& image);
