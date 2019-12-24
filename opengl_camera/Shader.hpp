#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    public:
    // Shader program ID
    unsigned int id;

    // Shader constructor, build shader with shader source files
    Shader(const GLchar* vertex_path, const GLchar* frag_path);

    // activate shader
    void use();
    
    // uniform set-up method
    void set_bool(const std::string &name, bool value) const;
    void set_int(const std::string &name, int value) const;
    void set_float(const std::string &name, float value) const;
    void set_mat4(const std::string &name, glm::mat4 value) const;

    private:
};