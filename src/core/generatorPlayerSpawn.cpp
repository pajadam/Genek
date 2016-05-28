/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Player Spawn
  ********************************************
  */

#include "core.hpp"

void Genek::findPlayerSpawn()
{
    mLogger->Log( INFO, mPrefix + "Setting player spawn..." );

    int h = 0;

    gensettings.player.x = 2;
    gensettings.player.y = 2;
    gensettings.player.z = gensettings.sizeZ;

    int divider = ( 256 / gensettings.sizeZ );
    int minLevel = gensettings.surfaceLevel / divider;

    for( int y = 0; y < gensettings.sizeY; y++ )
    {
        for( int x = 0; x < gensettings.sizeX; x++ )
        {
            unsigned char pos = h_map[h] / divider;
            if( pos > minLevel && x > 2 && x < gensettings.sizeX - 2 && y > 2 && y < gensettings.sizeY - 2 )
            {
                gensettings.player.x = x;
                gensettings.player.y = y;
                gensettings.player.z = h_map[h] / divider + 5;

                return;
            }
            h++;
        }
    }

    mLogger->Log( CRITICAL_ERROR, mPrefix + "Failed to set player spawn!" );
}
