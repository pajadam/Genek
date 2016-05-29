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

    gSize bridgeSpacing = 32;
    gSize bridgeMaxLength = 64;
    gSize bridgeMinLength = 8;

    bool generateBridges = true;
    bool generateLights = true;
    bool generateTrees = true;
    bool saveHeightMap = false;

    sun sunlight;
    startpos player;

    vector<material> materials;
    vector<light> lights;
    vector<model> models;
};

#endif // GENERATORSETTINGS_HPP
