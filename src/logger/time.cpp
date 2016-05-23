/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Get Local Time
  ********************************************
  */

#include "Time.hpp"
using namespace std;

void Time::Update()
{
    t = time( nullptr );
    c = localtime( &t );
}

string Time::c_year()
{
    return to_string( ( c->tm_year - 100 ) ) ;
}

string Time::c_month()
{
    if( c->tm_mon < 9 )
        return "0" + to_string( ( c->tm_mon + 1 ) );
    else return to_string( c->tm_mon + 1 ) ;
}

string Time::c_day()
{
    if( c->tm_mday < 10 )
        return "0" + to_string( c->tm_mday );
    else return to_string( c->tm_mday );
}

string Time::c_hour()
{
    if( c->tm_hour < 10 )
        return "0" + to_string( c->tm_hour );
    else return to_string( c->tm_hour );
}

string Time::c_min()
{
    if( c->tm_min < 10 )
        return "0" + to_string( c->tm_min );
    else return to_string( c->tm_min );
}

string Time::c_sec()
{
    if( c->tm_sec < 10 )
        return "0" + to_string( c->tm_sec );
    else return to_string( c->tm_sec );
}
