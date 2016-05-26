/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Surface
  ********************************************
  */

#include "core.hpp"

void Genek::genSurface()
{
    mLogger->Log( INFO, mPrefix + "Generating surface..." );
    unsigned int h = 0;
    for( unsigned int i = 0; i < gensettings.sizeY; i++ ){
        for( unsigned int j = 0; j < gensettings.sizeX; j++ ){
            char pos = (h_map[h] / ( 256 / gensettings.sizeZ)) + 1;
            mapData->get( j, i, pos ) = 1;
            mapData->get( j, i, pos - 1 ) = 2;
            h++;
        }
    }

    return;
}
