#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace ShaderUtils {
    std::string fileToCString(std::string filepath);

    GLuint compileShader(std::string filepath, GLuint shader_type);

    GLuint setupProgram(std::vector<GLuint> shaders);
}