#pragma once

#include <iostream>
#include <time.h>

#include "world.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Window* myWindow = new Window();
    Renderer* myRenderer = new Renderer(myWindow);
    World* myWorld = new World();
    myWorld->StartWorld(myRenderer, myWindow);

    return 0;
}