/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Voxel Map Generator - Genek
  ********************************************
  */

#include "main.hpp"

int main( int argc, char *argv[] )
{
    ClearConsole( 0 );

    if( argc > 2 )
    {
        usage();
        return 1;
    }

    SetConsoleCtrlHandler( ClearConsole, TRUE );

    _time  = new Time;
    logger = new FileLogger( LOG_FILE, _time );

    if( argc == 1 ){
        ShowWindow( GetConsoleWindow(), SW_HIDE );
        gui();
        ShowWindow( GetConsoleWindow(), SW_SHOW );
    }else
    if( argc == 2 ){
        console( argv[1] );
    }

    logger->Log( INFO, mPrefix + "Closing application..." );

    delete logger;
    delete _time;

    return 0;
}

void console( string seed )
{
    logger->Log( INFO, mPrefix + "Starting seed mode..." );
    logger->Log( INFO, mPrefix + "Got  seed: '" + seed + "'" );
    int seedHash = std::hash<std::string>()(seed);
    logger->Log( INFO, mPrefix + "Seed hash: '" + to_string( seedHash ) + "'" );
    Genek generator( logger );
    generator.generateMap( seedHash );
    generator.exportMap();
}

void gui() // ToDo Tier 2
{
    logger->Log( INFO, mPrefix + "Starting GUI mode..." );
    GUI gui( logger );
    gui.Start();
}

void usage()
{
    cout << "Woops! Too much arguments." << endl
         << "Usage:" << endl
         << " GUI  Mode: 'Genek.exe' " << endl
         << " Seed Mode: 'Genek.exe <seed>'" << endl;
    cout << "For much more options, run GUI mode." << endl;
}

BOOL WINAPI ClearConsole( DWORD )
{
    HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo( consoleOutput, &info );

    COORD topleft = { 0, 0 };
    DWORD num;
    FillConsoleOutputCharacter(consoleOutput, ' ', info.dwSize.X * info.dwSize.Y, topleft, &num);

    SetConsoleCursorPosition( consoleOutput, topleft );

    return FALSE;
}
