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

    srand( gensettings.seed );

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
                            if( ( rand() % 100 ) > 50 ) // MOST DREWNIANY
                            {
                                for( int j = 0; j < length; j++ )
                                {
                                    if( j == length - 1 )
                                    {
                                        int col1 = length / 4;
                                        int col2 = (length / 4) * 3;

                                        mapData->get( x + col1, y - 1, z )    = Block::Wood;
                                        mapData->get( x + col2, y - 1, z )    = Block::Wood;
                                        mapData->get( x + col1, y + 2, z )    = Block::Wood;
                                        mapData->get( x + col2, y + 2, z )    = Block::Wood;

                                        for( int c = z - 1; c > 0; c-- )
                                        {
                                            mapData->get( x + col1, y, c )        = Block::Wood;
                                            mapData->get( x + col2, y, c )        = Block::Wood;
                                            mapData->get( x + col1, y + 1, c )    = Block::Wood;
                                            mapData->get( x + col2, y + 1, c )    = Block::Wood;
                                        }
                                    }

                                    if( (mapData->get( x + j, y + 2, z + 1 ) != 0 && mapData->get( x + j, y - 1, z + 1) != 0) )
                                    {
                                        break;
                                    }

                                    mapData->get( x + j, y - 1, z + 1)     = Block::Plank;
                                        mapData->get( x + j, y, z )        = Block::Plank;
                                        mapData->get( x + j, y + 1, z )    = Block::Plank;
                                    mapData->get( x + j, y + 2, z + 1 )    = Block::Plank;
                                }
                            }else // MOST LUKOWY
                            {
                                for( int j = 0; j < length; j++ )
                                {
                                    if( j == length - 1 )
                                    {
                                        float half = length / 2;
                                        float height = z / 3;
                                        float divider = height / half;

                                        for( int c = length / 2; c > 0; c-- )
                                        {
                                            // JEDNA POLOWA
                                            int he = z + divider * c - divider * half;

                                            if( c % 3 == 0 )
                                            {
                                                for( int e = z; e > he; e-- )
                                                {
                                                    mapData->get( x + c, y, e)    = Block::Slab;
                                                    mapData->get( x + c, y + 1, e)    = Block::Slab;
                                                }
                                            }

                                            mapData->get( x + c, y - 1, he )    = Block::Bricks;
                                            mapData->get( x + c, y + 2, he )    = Block::Bricks;
                                        }

                                        for( int c = length / 2; c < length; c++ )
                                        {
                                            // DRUGA POLOWA
                                            int he = z - divider * c + divider * half;

                                            if( c % 3 == 0 )
                                            {
                                                for( int e = z; e > he; e-- )
                                                {
                                                    mapData->get( x + c, y, e)     = Block::Slab;
                                                    mapData->get( x + c, y + 1, e)    = Block::Slab;
                                                }
                                            }

                                            mapData->get( x + c, y - 1, he)     = Block::Bricks;
                                            mapData->get( x + c, y + 2, he)    = Block::Bricks;
                                        }

                                    }

                                    if( (mapData->get( x + j, y + 2, z + 1 ) != 0 && mapData->get( x + j, y - 1, z + 1) != 0) )
                                    {
                                        break;
                                    }

                                    mapData->get( x + j, y - 1, z + 1)     = Block::Bricks;
                                        mapData->get( x + j, y, z )        = Block::Bricks;
                                        mapData->get( x + j, y + 1, z )    = Block::Bricks;
                                    mapData->get( x + j, y + 2, z + 1 )    = Block::Bricks;
                                }
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
                mapData->get( x, y, z) != Block::Bricks&& mapData->get( x + 1, y, z) != Block::Bricks &&
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
                        mapData->get( x, i, z) != Block::Bricks && mapData->get( x + 1, i, z) != Block::Bricks &&
                        ( mapData->get( x, i, z + 1) == 0 || mapData->get( x + 1, i, z + 1) == 0 ) )
                    {
                        if( length > gensettings.bridgeMaxLength || length < gensettings.bridgeMinLength )
                        {
                            length = 0;
                            break;
                        }else
                        {
                            if( ( rand() % 100 ) > 50 ) // MOST DREWNIANY
                            {
                                for( int j = 0; j < length; j++ )
                                {
                                    if( j == length - 1 )
                                    {
                                        int col1 = length / 4;
                                        int col2 = (length / 4) * 3;

                                        mapData->get( x - 1, y + col1, z )    = Block::Wood;
                                        mapData->get( x - 1, y + col2, z )    = Block::Wood;
                                        mapData->get( x + 2, y + col1, z )    = Block::Wood;
                                        mapData->get( x + 2, y + col2, z )    = Block::Wood;

                                        for( int c = z - 1; c > 0; c-- )
                                        {
                                            mapData->get( x, y + col1, c )        = Block::Wood;
                                            mapData->get( x, y + col2, c )        = Block::Wood;
                                            mapData->get( x + 1, y + col1, c )    = Block::Wood;
                                            mapData->get( x + 1, y + col2, c )    = Block::Wood;
                                        }
                                    }

                                    if( (mapData->get( x + 2, y + j, z + 1 ) != 0 && mapData->get( x - 1, y + j, z + 1) != 0) )
                                    {
                                        break;
                                    }

                                    mapData->get( x - 1, y + j, z + 1)     = Block::Plank;
                                        mapData->get( x, y + j, z )        = Block::Plank;
                                        mapData->get( x + 1, y + j, z )    = Block::Plank;
                                    mapData->get( x + 2, y + j, z + 1 )    = Block::Plank;
                                }
                            }else // MOST LUKOWY
                            {
                                for( int j = 0; j < length; j++ )
                                {
                                    if( j == length - 1 )
                                    {
                                        float half = length / 2;
                                        float height = z / 3;
                                        float divider = height / half;

                                        for( int c = length / 2; c > 0; c-- )
                                        {
                                            // JEDNA POLOWA
                                            int he = z + divider * c - divider * half;

                                            if( c % 3 == 0 )
                                            {
                                                for( int e = z; e > he; e-- )
                                                {
                                                    mapData->get( x, y + c, e)     = Block::Slab;
                                                    mapData->get( x + 1, y + c, e) = Block::Slab;
                                                }
                                            }

                                            mapData->get( x - 1, y + c, he )    = Block::Bricks;
                                            mapData->get( x + 2, y + c, he )    = Block::Bricks;
                                        }

                                        for( int c = length / 2; c < length; c++ )
                                        {
                                            // DRUGA POLOWA
                                            int he = z - divider * c + divider * half;

                                            if( c % 3 == 0 )
                                            {
                                                for( int e = z; e > he; e-- )
                                                {
                                                    mapData->get( x, y + c, e)     = Block::Slab;
                                                    mapData->get( x + 1, y + c, e)    = Block::Slab;
                                                }
                                            }

                                            mapData->get( x - 1, y + c, he)     = Block::Bricks;
                                            mapData->get( x + 2, y + c, he)    = Block::Bricks;
                                        }

                                    }

                                    if( (mapData->get( x + 2, y + j, z + 1 ) != 0 && mapData->get( x - 1, y + j, z + 1) != 0) )
                                    {
                                        break;
                                    }

                                    mapData->get( x - 1, y + j, z + 1)     = Block::Bricks;
                                        mapData->get( x, y + j, z )        = Block::Bricks;
                                        mapData->get( x + 1, y + j, z )    = Block::Bricks;
                                    mapData->get( x + 2, y + j, z + 1 )    = Block::Bricks;
                                }
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
