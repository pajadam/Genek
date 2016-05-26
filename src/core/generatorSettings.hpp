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


typedef unsigned int gSize;

struct settings
{
    gSize sizeX = 256;
    gSize sizeY = 256;
    gSize sizeZ = 96;

    gSize surfaceLevel = 108;
    gSize dirtLevel = 4;
    gSize waterLevel = 4;

    gSize treeSize = 10;
    gSize treeAmount = 10;

    gSize grassAmount = 10;

    bool generateStructures = true;
    bool generateFlowers = true;
    bool generateGrass = true;
    bool generateLights = true;

    sun sunlight;
    startpos player;

    vector<material> materials;
    vector<light> lights;
    vector<model> models;
};

#endif // GENERATORSETTINGS_HPP
