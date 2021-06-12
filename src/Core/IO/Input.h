#pragma once

#include <string>

class Input {
  public:
    static int isKeyDown(int key);
    static int isMouseButtonDown(int button);

    static int isKeyUp(int key);
    static int isMouseButtonUp(int button);

    // Returns: tanh(4 * pressed time)
    static float getAxis(const char *axis);

    struct Keys {
        static const int ESCAPE = 256;
        static const int W = 'W';
        static const int S = 'S';
    };
};
