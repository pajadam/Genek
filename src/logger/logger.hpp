/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * File Logger
  ********************************************
  */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

#include "time.hpp"

using namespace std;

enum log_type
{
    WARNING,
    ERROR,
    INFO,
    CRITICAL_ERROR
};

class FileLogger
{
public:
    FileLogger( const string outputFile, Time *gTime );
    ~FileLogger();


    void Log( log_type Type, const string Message);
private:
    ofstream mFile;
    string mTimePrefix;
    const string mPrefix = "[ Logger ] ";
    const string mTitle = " Genek - Voxel Map Generator - by pajadam";

    Time *pTime;

    unsigned int mErrors, mWarnings;
};
#endif // LOGGER_HPP
