#include "ShaderUtils.h"

namespace ShaderUtils {
    std::string fileToCString(std::string filepath) {
        std::ifstream f(filepath);
        std::string str;
        if (f) {
            std::ostringstream ss;
            ss << f.rdbuf();
            str = ss.str();
        }
        else {
            char buffer[1024];
            strerror_s(buffer, errno);
            std::cerr << buffer << std::endl;
        }
        return str;
    }

    
    GLuint compileShader(std::string filepath, GLuint shader_type) {
        std::string shader_string = fileToCString(filepath);
        const GLchar* shader_text = shader_string.c_str();

        GLuint shader = glCreateShader(shader_type);
        glShaderSource(shader, 1, &shader_text, NULL);
        glCompileShader(shader);

        GLint compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (compiled == GL_TRUE)
            std::cout << "Shader at " << filepath << " OK\n";
        else
        {
            GLint infoLogLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
            GLchar* message = new GLchar[infoLogLength + 1];
            glGetShaderInfoLog(shader, infoLogLength, NULL, message);
            std::cout << "Shader error in " << filepath << ": " << message << std::endl;
            delete[] message;
        }

        return shader;
    }

    GLuint setupProgram(std::vector<GLuint> shaders) {
        GLuint program = glCreateProgram();
        for (GLuint s : shaders) {
            glAttachShader(program, s);
        }
        glLinkProgram(program);
        glUseProgram(program);

        GLint program_linked;
        glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
        if (program_linked == GL_TRUE)
            std::cout << "Program OK\n";
        else
        {
            GLint infoLogLength;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
            GLchar* message = new GLchar[infoLogLength + 1];
            glGetProgramInfoLog(program, infoLogLength, NULL, message);
            std::cout << "Program error: " << message << std::endl;
            delete[] message;
        }

        return program;
    }























}