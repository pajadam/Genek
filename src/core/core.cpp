/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Core
  ********************************************
  */
#include "core.hpp"

Genek::Genek( FileLogger *logger )
{
    mLogger = logger;
    mLogger->Log( INFO, mPrefix + "Initializing Map Generator..." );
}

Genek::~Genek()
{
    mLogger->Log( INFO, mPrefix + "Destructor." );
    clear();
}

bool Genek::generateMap( int Seed )
{
    mLogger->Log( INFO, mPrefix + "Generating map using seed: " + to_string( Seed ) + " ..." );

    genHeightMap( Seed, true );

    mLogger->Log( INFO, mPrefix + "Height map size: " + to_string( h_map.size() ) );

    mLogger->Log( INFO, mPrefix + "Allocating memory: "
                 + to_string( sizeof( char  ) * ( gensettings.sizeX * gensettings.sizeY * gensettings.sizeZ )  ) + " ..." );
    mapData = new Array3D( gensettings.sizeX, gensettings.sizeY, gensettings.sizeZ );

    genSurface();

    return 0;
}

bool Genek::generateMap( int Seed, settings custom )
{
    mLogger->Log( INFO, mPrefix + "Generating map using custom settings and seed: " + to_string( Seed ) + " ..." );
    return 0;
}

bool Genek::saveMap( string filename )
{
    // ToDo Tier 2
    return 0;
}

bool Genek::exportMap( string filename )
{
    mLogger->Log( INFO, mPrefix + "Exporting map to file: '" + filename + "'" );
    gensettings.player.x = 1;
    gensettings.player.y = 1;
    gensettings.player.z = 0;

    material mat;
    mat.name = "karol-trawa";
    gensettings.materials.push_back(mat);

    mat.name = "bricks";

    gensettings.materials.push_back(mat);

    mat.name = "karol-zwir";
    gensettings.materials.push_back(mat);

    return mExporter.Export( filename, gensettings, *mapData );
}

void Genek::clear()
{
    delete mapData;
    h_map.clear();
}
