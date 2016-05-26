/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Map exporter
  ********************************************
  */

#include "export.hpp"

exporter::exporter()
{

}

exporter::~exporter()
{

}

bool exporter::Export( string filename, settings &gen, Array3D &_map )
{
    ofstream mFile( filename );

    if( !mFile.good() )
        return 1;

    //Map Size
    mFile << "size " << gen.sizeX << " "
                     << gen.sizeY << " "
                     << gen.sizeZ << endl;

    // Map Data
    for( unsigned int y = 0; y < gen.sizeY; y++ ){
        for( unsigned int z = 0; z < gen.sizeZ; z++ ){
            mFile << "voxline " << y << " " << z;
            for( unsigned int x = 0; x < gen.sizeX; x++ ){
                mFile << " " << _map.get( x, y, z );
            }
            mFile << endl;
        }
    }

    // Materials
    for( unsigned int i = 0; i < gen.materials.size(); i++ )
    {
        mFile << "material " << gen.materials[ i ].name  << " "
                             << gen.materials[ i ].sizeX << " "
                             << gen.materials[ i ].sizeY << endl;
    }

    // Sky and Sun
    mFile << "sky dusk" << endl;
    mFile << "sun " << gen.sunlight.dx << " "
                    << gen.sunlight.dy << " "
                    << gen.sunlight.dz << " "
                    << gen.sunlight.r  << " "
                    << gen.sunlight.g  << " "
                    << gen.sunlight.b  << " "
                    << gen.sunlight.ar << " "
                    << gen.sunlight.ag << " "
                    << gen.sunlight.ab << endl;

    // Player Spawn
    mFile << "startpos " << gen.player.x << " "
                         << gen.player.y << " "
                         << gen.player.z << endl;

    mFile.close();

    return 0;
}
