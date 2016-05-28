/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Settings
  ********************************************
  */

#ifndef GENERATORSETTINGS_HPP
#define GENERATORSETTINGS_HPP

#include <vector>
#include "generatorData.hpp"

typedef unsigned short gSize;

struct settings
{
    gSize sizeX = 256;
    gSize sizeY = 256;
    gSize sizeZ = 64;

    int seed;

    gSize surfaceLevel = 108;
    gSize dirtLevel = 4;
    gSize waterLevel = 4;

    gSize bridgeSpacing = 8;

    bool generateStructures = true;
    bool generateLights = true;
    bool generateTrees = true;

    sun sunlight;
    startpos player;

    vector<material> materials;
    vector<light> lights;
    vector<model> models;
};

#endif // GENERATORSETTINGS_HPP
