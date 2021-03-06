/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Height Map
  ********************************************
  */

#include "core.hpp"

void Genek::genHeightMap( int seed, bool writeToFile, string filePath )
{
    mLogger->Log( INFO, mPrefix + "Generating height map..." );
	PerlinNoise pn( seed );

	for( gSize i = 0; i < gensettings.sizeY; ++i) {     // y
		for( gSize j = 0; j < gensettings.sizeX; ++j) {  // x
			double x = (double)j/((double)gensettings.sizeX);
			double y = (double)i/((double)gensettings.sizeY);
            double n = 4 * pn.noise( gensettings.sizeX / 40 * x,
                                           gensettings.sizeY / 40 * y,
                                           0.8);
			h_map.push_back( (255 * n) / 5 );
		}
	}

	if( writeToFile == true )
    {
        mLogger->Log( INFO, mPrefix + "Writing height map to file..." );
        ppm image( gensettings.sizeX, gensettings.sizeY);

        for( unsigned int i = 0; i < h_map.size(); i++ )
        {
            image.r[i] = h_map[i];
			image.g[i] = h_map[i];
			image.b[i] = h_map[i];
        }

        image.write( filePath );
    }


}
