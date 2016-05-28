/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Core
  ********************************************
  */

#ifndef CORE_HPP
#define CORE_HPP

#include <cmath>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "../logger/logger.hpp"
#include "generatorData.hpp"
#include "../noise/PerlinNoise.h"
#include "../noise/ppm.h"
#include "array3d.hpp"
#include "generatorSettings.hpp"
#include "export.hpp"

using namespace std;

enum Block
{
    Grass = 1,
    Dirt,
    Stone,
    Coal,
    Diamond,
    Leaf,
    Wood,
    Bricks,
    Plank
};

class Genek
{
public:
    Genek( FileLogger *logger );
    ~Genek();

    bool generateMap( int seed );
    bool generateMap( settings custom );

    bool saveMap( string filename = "map.pmg" ); // Save whole Generator project #ToDo Tier 2
    bool exportMap( string filename = "map.vox" ); // Export map to Compo Format
private:
    void genHeightMap( int seed, bool writeToFile = false, string filePath = "heightmap.ppm" );
    void genSurface();
    void genBorder();

    void clear();

    vector<unsigned char> h_map;

    Array3D *mapData;

    settings gensettings;
    exporter mExporter;
    FileLogger *mLogger;
    const string mPrefix = "[ MAPGEN ] ";
};

#endif // CORE_HPP
