/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator Core
  ********************************************
  */

#include "core.hpp"

void Genek::setMaterials()
{
    material mat;

    mat.name = "p_grass";
    gensettings.materials.push_back(mat);

    mat.name = "p_dirt";
    gensettings.materials.push_back(mat);

    mat.name = "p_stone";
    gensettings.materials.push_back(mat);

    mat.name = "p_coal";
    gensettings.materials.push_back(mat);

    mat.name = "p_diamond";
    gensettings.materials.push_back(mat);

    mat.name = "p_leaf";
    gensettings.materials.push_back(mat);

    mat.name = "p_wood";
    gensettings.materials.push_back(mat);

    mat.name = "p_brick";
    gensettings.materials.push_back(mat);

    mat.name = "p_plank";
    gensettings.materials.push_back(mat);

    mat.name = "p_water";
    gensettings.materials.push_back(mat);
}
