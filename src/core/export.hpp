/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Map exporter
  ********************************************
  */

#ifndef EXPORT_HPP
#define EXPORT_HPP

#include "generatorSettings.hpp"
#include <fstream>
#include "Array3D.hpp"

using namespace std;

class exporter
{
public:
    exporter();
    ~exporter();

    bool Export( string filename, settings &gen, Array3D &_map );
private:
    void sHeader();
    void sData();
    void sFooter();
};

#endif // EXPORT_HPP
