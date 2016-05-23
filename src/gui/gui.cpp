/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Graphic User Interface
  ********************************************
  */
#include "gui.hpp"

GUI::GUI( FileLogger *logger )
{
    mLogger = logger;
    mLogger->Log( INFO, mPrefix + "Initializing GUI..." );
}

GUI::~GUI()
{
    mLogger->Log( INFO, mPrefix + "Destructor." );
}

void GUI::Start()
{
    mLogger->Log( INFO, mPrefix + "Running GUI..." );
}
