/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Surface
  ********************************************
  */

#include "core.hpp"

void Genek::genBorder()
{
    for ( gSize z = 0; z < gensettings.sizeZ - 1; z++ )
    {
        for( gSize x = 0; x < gensettings.sizeX; x++ )
        {
            mapData->get( x, 0, z ) = -1;
            mapData->get( x, gensettings.sizeY - 1, z ) = -1;
        }

        for( gSize y = 0; y < gensettings.sizeY; y++ )
        {
            mapData->get( 0, y, z ) = -1;
            mapData->get( gensettings.sizeX - 1, y, z ) = -1;
        }
    }

    return;
}
