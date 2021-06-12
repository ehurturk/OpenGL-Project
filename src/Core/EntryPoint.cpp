//
// Created by Emir Hürtürk on 2.06.2021.
//

#include "Engine.h"

int main()
{
    Engine::getEngine().start();

    while (!Engine::getEngine().getWindow().shouldWindowClose())
        Engine::getEngine().update();

    Engine::getEngine().free();
}
