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
}

bool Genek::generateMap( int Seed )
{
    mLogger->Log( INFO, mPrefix + "Generating map using seed: " + to_string( Seed ) + " ..." );
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

    return 0;
}
