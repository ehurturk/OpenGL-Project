#pragma once

#include <iostream>
#include <stdlib.h>
#include <glad/glad.h>

#define ASSERT(x) \
    if (!(x)) exit(EXIT_FAILURE)

// Call to Debug a specific function.
#define GLDebug(x)  \
    GLClearError(); \
    x;              \
    ASSERT(GLLog(#x, __FILE__, __LINE__))

bool GLLog(const char *func, const char *file, int line);

void GLClearError();