#include "Debug.h"

bool GLLog(const char *func, const char *file, int line)
{
    GLenum error = glGetError();
    if (!error) {
        std::cout << "[OpenGL ERORR]: (" << error << "): " << func << ":" << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR)
        ;
}