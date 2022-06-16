#pragma once
#include "AScene.h"

class Level1Scene :
    public AScene
{
public:
    Level1Scene();
    ~Level1Scene();

    void onLoadResources() override;
    void onLoadObjects() override;

};

