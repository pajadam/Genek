/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Graphic User Interface
  ********************************************
  */

#ifndef GUI_HPP
#define GUI_HPP

#include "../logger/logger.hpp"

class GUI
{
public:
    GUI( FileLogger *_logger );
    ~GUI();

    void Start();
private:
    FileLogger *mLogger;
    const string mPrefix = "[  GUI   ] ";
};

#endif // GUI_HPP
