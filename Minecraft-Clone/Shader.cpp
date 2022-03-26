#include "Shader.h"

#include <iostream>
#include <fstream>

namespace OGLRenderer
{
    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        std::string vertexCode, fragmentCode;
        std::ifstream vShaderFile, fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    	
        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;

            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "Shader file not read properly" << std::endl;
        }
    	
        const char* VertexShaderSource = vertexCode.c_str();
        const char* FragmentShaderSource = fragmentCode.c_str();
        unsigned int VertexShader, FragmentShader;

        VertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(VertexShader, 1, &VertexShaderSource, nullptr);
        glCompileShader(VertexShader);
        CheckCompileErrors(VertexShader, VERTEX);

        FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(FragmentShader, 1, &FragmentShaderSource, nullptr);
        glCompileShader(FragmentShader);
        CheckCompileErrors(FragmentShader, FRAGMENT);

        id = glCreateProgram();
        glAttachShader(id, VertexShader);
        glAttachShader(id, FragmentShader);
        glLinkProgram(id);
        CheckCompileErrors(id, PROGRAM);

        glDeleteShader(VertexShader);
        glDeleteShader(FragmentShader);
    }

    void Shader::CheckCompileErrors(const unsigned int shader, ShaderType type)
    {
        int success;
        char infoLog[1024];
        if (type != PROGRAM)
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << std::endl;
            }
        }
    }
}
