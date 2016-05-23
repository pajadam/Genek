/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Core
  ********************************************
  */

#ifndef CORE_HPP
#define CORE_HPP

#include "../logger/logger.hpp"
#include "generatorSettings.hpp"

class Genek
{
public:
    Genek( FileLogger *logger );
    ~Genek();

    bool generateMap( int seed );
    bool generateMap( int seed, settings custom );

    bool saveMap( string filename = "map.pmg" ); // Save whole Generator project #ToDo Tier 2
    bool exportMap( string filename = "map.vox" ); // Export map to Compo Format
private:
    settings gensettings;
    FileLogger *mLogger;
    const string mPrefix = "[ MAPGEN ] ";
};

#endif // CORE_HPP
