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
    srand( time( NULL ) );
    mLogger->Log( INFO, mPrefix + "Generating surface..." );
    unsigned int h = 0;
    for( unsigned int i = 0; i < gensettings.sizeY; i++ ){
        for( unsigned int j = 0; j < gensettings.sizeX; j++ ){
            char pos = h_map[h] / ( 256 / gensettings.sizeZ);
            if( pos < gensettings.surfaceLevel / ( 256 / gensettings.sizeZ)  )
            {
                for( unsigned int x = pos; x > 0; x-- )
                {
                    if( x > (gensettings.waterLevel / ( 256 / gensettings.sizeZ)) + pos / 25 )
                        mapData->get( j, i, x ) = 0;
                    else
                        mapData->get( j, i, x ) = Block::Grass;
                }
            }else
            {
                unsigned int k = 0;
                for( unsigned int y = pos; y > 0; y-- )
                {
                    if( k == 0)
                    {
                        mapData->get( j, i, y ) = Block::Grass;
                    }else
                    if( k < gensettings.dirtLevel )
                    {
                        mapData->get( j, i, y ) = Block::Grass;//dirt
                    }else
                    {
                        int ran = ( std::rand() % 100 );
                        if( ran > 50 )
                        {
                            if( ran > 65 )
                                mapData->get( j, i, y ) = Block::Gravel;
                            else
                                mapData->get( j, i, y ) = Block::Grass;
                        }else
                        {
                            mapData->get( j, i, y ) = Block::Bricks;
                        }

                    }
                    k++;
                }
            }
            h++;
        }
    }

    return;
}
