#pragma once

#include <glad/glad.h>

#include <string>
#include <sstream>
#include <glm/glm.hpp>

namespace OGLRenderer {
    enum ShaderType
    {
        VERTEX,
        FRAGMENT,
        PROGRAM
    };

    class Shader
    {
    public:
        Shader(const char* vertexPath, const char* fragmentPath);

        void use() const
        {
            glUseProgram(id);
        }

        void setBool(const std::string& name, bool value) const
        {
            glUniform1i(glGetUniformLocation(id, name.c_str()), static_cast<int>(value));
        }

        void setInt(const std::string& name, int value) const
        {
            glUniform1i(glGetUniformLocation(id, name.c_str()), value);
        }

        void setFloat(const std::string& name, float value) const
        {
            glUniform1f(glGetUniformLocation(id, name.c_str()), value);
        }

        void setMat4(const std::string& name, const glm::mat4& mat) const
        {
            glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
    private:
        unsigned int id;

        static void CheckCompileErrors(unsigned int shader, ShaderType type);
    };
}
