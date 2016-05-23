/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Settings
  ********************************************
  */

#ifndef GENERATORSETTINGS_HPP
#define GENERATORSETTINGS_HPP

typedef unsigned int gSize;

struct settings
{
    gSize sizeX = 100;
    gSize sizeY = 100;
    gSize sizeZ = 100;

    gSize surfaceLevel = 50;
    gSize waterLevel = 50;
    gSize lavaLevel = 16;

    gSize mountainSize = 25;

    gSize canyonDepth = 25;
    gSize canyonLength = 25;

    gSize treeSize = 10;
    gSize treeAmount = 10;

    gSize grassAmount = 10;

    bool generateStructures = true;
    bool generateFlowers = true;
    bool generateGrass = true;
    bool generateLights = true;
};

#endif // GENERATORSETTINGS_HPP
