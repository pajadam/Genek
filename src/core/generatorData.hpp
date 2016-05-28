/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Map Data
  ********************************************
  */

#ifndef GENERATORDATA_HPP
#define GENERATORDATA_HPP

using namespace std;

#include <string>

typedef unsigned int gSize;

struct material
{
    string name;
    int sizeX = 1;
    int sizeY = 1;
};

struct startpos
{
    gSize x, y, z;
    gSize direction = 0;

    bool physics = true; // 0 - Lot, 1 - fizyka
    bool testLightning = false;

    char torchLevel = 1; // 0 - 4
};

struct light
{
    gSize x, y, z;
    char r, g, b;
    gSize range;
};

struct model
{
    string name;
    gSize x, y, z;
    gSize rotation = 0;
    gSize tilt = 0;
    gSize direction = 0;
    gSize scale = 1;
    gSize radius = 1;
    gSize value;
};

struct sun
{
    float dx = .3, dy = -1, dz = .5;
    float r = 1,  g = 1,  b = .4;
    float ar = .6, ag = .6, ab = .6;
};

#endif // GENERATORDATA_HPP
