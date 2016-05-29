/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Bridge
  ********************************************
  */

#include "core.hpp"

void Genek::genBridges()
{
    mLogger->Log( INFO, mPrefix + "Generating bridges..." );

    gSize z = gensettings.surfaceLevel / ( 256 / gensettings.sizeZ);

    bool created = false;

    // x -->>
    for( int y = 4; y < gensettings.sizeY - 4; y++ )
    {
        for( int x = 4; x < gensettings.sizeX - 4; x++ )
        {
            if( mapData->get( x, y, z) != 0            && mapData->get( x, y + 1, z) != 0 &&
                mapData->get( x + 1, y, z) == 0        && mapData->get( x + 1, y + 1, z) == 0 &&
                mapData->get( x, y, z) != Block::Plank && mapData->get( x, y + 1, z) != Block::Plank &&
                mapData->get( x, y, z + 1) == 0        && mapData->get( x, y + 1, z + 1) ==  0 )
            {
                int length = 0;

                for( int i = x + 1; i < gensettings.sizeX - 4; i++ )
                {
                    length++;
                    if(  mapData->get( i, y, z) != 0     && mapData->get( i, y + 1, z) != 0 &&
                        (mapData->get( i, y, z + 1) == 0 || mapData->get( i, y + 1, z + 1) == 0) )
                    {
                        if( length > gensettings.bridgeMaxLength || length < gensettings.bridgeMinLength )
                        {
                            length = 0;
                            break;
                        }else
                        {
                            for( int j = 0; j < length; j++ )
                            {
                                // WYPEŁNIANE MOSTU Y->>>>
                                mapData->get( x + j, y, z )     = Block::Plank;
                                mapData->get( x + j, y + 1, z ) = Block::Plank;
                            }
                            created = true;
                        }
                    }
                }
            }
            if( created == true )
            {
                created = false;
                if( y + gensettings.bridgeSpacing < gensettings.sizeY - 4 )
                {
                    y += gensettings.bridgeSpacing;
                    x = 0;
                }else
                {
                    x = gensettings.sizeX;
                    y = gensettings.sizeY;
                }
            }
        }
    }

    // y -->>

    for( int x = 4; x < gensettings.sizeX - 4; x++ )
    {
        for( int y = 4; y < gensettings.sizeY - 4; y++ )
        {
            if( mapData->get( x, y, z) != 0            && mapData->get( x + 1, y, z) != 0 &&
                mapData->get( x, y + 1, z) == 0        && mapData->get( x + 1, y + 1, z) == 0 &&
                mapData->get( x, y, z) != Block::Plank && mapData->get( x + 1, y, z) != Block::Plank &&
                mapData->get( x, y, z + 1) == 0        && mapData->get( x + 1, y, z + 1) ==  0 )
            {
                int length = 0;

                for( int i = y + 1; i < gensettings.sizeY - 4; i++ )
                {
                    length++;
                    if( mapData->get( x, i, z) == Block::Plank || mapData->get( x + 1, i, z) == Block::Plank )
                    {
                        break;
                    }else
                    if( mapData->get( x, i, z) != 0     && mapData->get( x + 1, i, z) != 0 &&
                        mapData->get( x, i, z) != Block::Plank && mapData->get( x + 1, i, z) != Block::Plank &&
                        ( mapData->get( x, i, z + 1) == 0 || mapData->get( x + 1, i, z + 1) == 0 ) )
                    {
                        if( length > gensettings.bridgeMaxLength || length < gensettings.bridgeMinLength )
                        {
                            length = 0;
                            break;
                        }else
                        {
                            for( int j = 0; j < length; j++ )
                            {
                                // WYPEŁNIANE MOSTU Y->>>>
                                mapData->get( x, y + j, z )     = Block::Wood;
                                mapData->get( x + 1, y + j, z ) = Block::Wood;
                            }
                            created = true;
                            break;
                        }
                    }
                }
            }
            if( created == true )
            {
                created = false;
                if( x + gensettings.bridgeSpacing < gensettings.sizeX - 4 )
                {
                    x += gensettings.bridgeSpacing;
                    y = 0;
                }else
                    return;
            }
        }
    }

    return;
}
