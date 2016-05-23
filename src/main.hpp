/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Voxel Map Generator - Genek
  ********************************************
  */
#include <iostream>
#include "logger/logger.hpp"
#include "gui/gui.hpp"
#include "core/core.hpp"

#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif
#include <windows.h>

#define LOG_FILE "data/log.txt"

using namespace std;

const string mPrefix = "[  MAIN  ] ";

FileLogger *logger;
Time *_time;

BOOL WINAPI ClearConsole( DWORD );

void gui();
void console( string );
void usage();
