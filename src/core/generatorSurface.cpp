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
    srand( gensettings.seed );
    mLogger->Log( INFO, mPrefix + "Generating surface..." );
    unsigned short mUSL = ((gensettings.surfaceLevel / ( 256 / gensettings.sizeZ)) / 25) * 2;
    unsigned int h = 0;
    for( gSize i = 0; i < gensettings.sizeY; i++ ){
        for( gSize j = 0; j < gensettings.sizeX; j++ ){
            unsigned char pos = h_map[h] / ( 256 / gensettings.sizeZ);
            if( pos < gensettings.surfaceLevel / ( 256 / gensettings.sizeZ)  )
            {
                for( gSize x = pos; x > 0; x-- )
                {
                    if( x > (gensettings.waterLevel / ( 256 / gensettings.sizeZ)) + pos / 25 )
                    {
                        if( x <= mUSL )
                            mapData->get( j, i, x) = Block::Water;
                        else
                            mapData->get( j, i, x ) = 0;
                    }
                    else
                    {
                        mapData->get( j, i, x ) = Block::Grass;
                    }
                }
            }else
            {
                gSize k = 0;
                for( gSize y = pos; y > 0; y-- )
                {
                    if( k == 0)
                    {
                        mapData->get( j, i, y ) = Block::Grass;
                    }else
                    if( k < gensettings.dirtLevel * ( (std::rand() % 2) + 1 ) )
                    {
                        mapData->get( j, i, y ) = Block::Dirt;
                    }else
                    {
                        int ran = ( std::rand() % 100 );
                        if( ran > 90 )
                        {
                            if( ran > 92 )
                                mapData->get( j, i, y ) = Block::Coal;
                            else
                                mapData->get( j, i, y ) = Block::Diamond;
                        }else
                        {
                            mapData->get( j, i, y ) = Block::Stone;
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
