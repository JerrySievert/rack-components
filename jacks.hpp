#pragma once

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

struct RCJackSmallRed : app::SvgPort {
  RCJackSmallRed() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallRed.svg")));
  }
};

struct RCJackSmallGrey : app::SvgPort {
  RCJackSmallGrey() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallGrey.svg")));
  }
};

struct RCJackSmallDark : app::SvgPort {
  RCJackSmallDark() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallDark.svg")));
  }
};


struct RCJackSmallLight : app::SvgPort {
  RCJackSmallLight() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallLight.svg")));
  }
};
