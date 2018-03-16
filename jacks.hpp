#pragma once

#include "asset.hpp"
#include "rack.hpp"

extern Plugin *plugin;

struct RCJackSmallRed : SVGPort {
  RCJackSmallRed() {
    background->svg = SVG::load(assetPlugin(plugin, "res/JackSmallRed.svg"));
    background->wrap();
    box.size = background->box.size;
  }
};
