/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Graphic User Interface
  ********************************************
  */

#ifndef GUI_HPP
#define GUI_HPP

#define TITLE "Genek - World Generator - by pajadam"
#define GEN_BRIDGE "Generate Bridges"
#define SAVE_HEIGHTMAP "Save heightmap"

#define MIN_SIZE 128
#define MAX_SIZE 1024

#define MIN_HEIGHT 64
#define MAX_HEIGHT 256

#define MAX_SPACING 64
#define MAX_LENGTH 128
#define MIN_MAX_LENGTH 16

#include "../logger/logger.hpp"
#include "../core/core.hpp"
#include <nana/gui.hpp>
#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/checkbox.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/slider.hpp>

using namespace nana;

class GUI
{
public:
    GUI( FileLogger *_logger );
    ~GUI();

    void Start();
private:
    form ui;

    checkbox genBridges,
             saveHeightMap;

    progress prog;

    slider x,
           y,
           z,
           bs,
           bn,
           bm;

    label  lx,
           ly,
           lz,
           ll,
           seedl,
           bridl,
           bspa,
           bmin,
           bmax,
           lprog;

    button gen;

    textbox seedb;
    settings gs;

    string sSeed;

    FileLogger *mLogger;
    const string mPrefix = "[  GUI   ] ";
};

#endif // GUI_HPP
