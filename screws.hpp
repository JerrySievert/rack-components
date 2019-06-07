#pragma once

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;


struct JLHHexScrew : SVGScrew {
  JLHHexScrew() {
    sw->setSVG(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JLHHexScrew.svg")));
    box.size = sw->box.size;
  }
};
