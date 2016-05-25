/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Map Data
  ********************************************
  */

#ifndef GENERATORDATA_HPP
#define GENERATORDATA_HPP

typedef unsigned int gSize;

struct material
{
    string name;
    char sizeX = 1;
    char sizeY = 1;
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
    gSize dx, dy, dz;
    char r,  g,  b;
    char ar, ag, ab;
};

#endif // GENERATORDATA_HPP
