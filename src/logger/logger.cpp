/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * File Logger
  ********************************************
  */
#include "Logger.hpp"
using namespace std;

/*********************************************
  * Konstr( plik_wyjść, refer_do_czasu );
  ********************************************/
FileLogger::FileLogger( const string OutputFile, Time *gTime )
    :mFile( OutputFile )
{
    pTime = gTime;
    mErrors = mWarnings = 0;
    cout << "#############################################################################" << endl
         << "               "<< mTitle << endl
         << "#############################################################################" << endl;
    mFile    << "#############################################################################" << endl
             << "               "<< mTitle << endl
             << "#############################################################################" << endl;
}

/*********************************************
  * Log( typ_informacji, wiadomość );
  ********************************************/
void FileLogger::Log( log_type Type, const string Message)
{
    pTime->Update();
    mTimePrefix = ( "[" + pTime->c_year() + "." + pTime->c_month() + "."
                    + pTime->c_day() +  " " + pTime->c_hour()  + ":"
                    + pTime->c_min() +  ":" + pTime->c_sec()   + "]") ;

    switch( Type )
    {
    case log_type::INFO:
        cout << mTimePrefix << "[  INFO   ] " << Message << endl;
        mFile << mTimePrefix << "[  INFO   ] " << Message << endl;
        break;
    case log_type::WARNING:
        cout << mTimePrefix << "[ WARNING ] " << Message << endl;
        mFile << mTimePrefix << "[ WARNING ] " << Message << endl;
        mWarnings++;
        break;
    case log_type::ERROR:
        cerr << mTimePrefix << "[  ERROR  ] " << Message << endl;
        mFile << mTimePrefix << "[  ERROR  ] " << Message << endl;
        mErrors++;
        break;
    case log_type::CRITICAL_ERROR:
        cerr << mTimePrefix << "[ CRITICAL ERROR  ] " << Message << endl;
        mFile << mTimePrefix << "[ CRITICAL ERROR  ] " << Message << endl;
        mErrors++;
        break;
    default:
        break;
    }
}

/*********************************************
  * ~Destruktor
  ********************************************/
FileLogger::~FileLogger()
{
    pTime->Update();
    Log( log_type::INFO, mPrefix + "Destructor");
    cout << "#############################################################################" << endl
         << "           Warnings: " << mWarnings << endl
         << "             Errors: " << mErrors << endl
         << "#############################################################################";
    mFile   << "#############################################################################" << endl
            << "           Warnings: " << mWarnings << endl
            << "             Errors: " << mErrors << endl
            << "#############################################################################";
    mFile.close();
}
