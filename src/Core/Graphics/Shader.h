//
// Created by Emir Hürtürk on 4.06.2021.
//

#ifndef COPENGLTEST_SHADER_H
#define COPENGLTEST_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class Shader
{
  public:
    // Default constructor
    // ------------------------------------------------------------------------
    Shader() = default;
    // Create the shader
    // ------------------------------------------------------------------------
    void attach(const char* vertexPath, const char* fragmentPath);
    // activate the shader
    // ------------------------------------------------------------------------
    void use();
    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const;
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const;
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const;

  private:
    unsigned int ID;
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, const std::string& type);

};

#endif //COPENGLTEST_SHADER_H
