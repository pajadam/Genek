/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Get Local time
  ********************************************
  */

#ifndef TIME_HPP
#define TIME_HPP

#include <time.h>
#include <sstream>

using namespace std;

class Time
{
public:
    void Update(); // Update time

    string c_hour();
    string c_min();
    string c_sec();
    string c_day();
    string c_year();
    string c_month();
private:
    time_t t;
    struct tm * c;
};
#endif // TIME_HPP
