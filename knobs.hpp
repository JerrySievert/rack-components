#pragma once

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

struct RCKnobRed : RoundKnob {
  RCKnobRed() {
    setSVG(APP->window->loadSvg(assetPlugin(pluginInstance, "res/KnobRed.svg")));
  }
};

struct RCKnobRedSnap : RCKnobRed {
  RCKnobRedSnap ( ) {
    snap = true;
  }
};

struct RCKnobRedLarge : RoundKnob {
  RCKnobRedLarge() {
    setSVG(APP->window->loadSvg(assetPlugin(pluginInstance, "res/KnobRedLarge.svg")));
  }
};

struct RCKnobRedLargeSnap : RCKnobRedLarge {
  RCKnobRedLargeSnap ( ) {
    snap = true;
  }
};

struct RCKnobRedSmall : RoundKnob {
  RCKnobRedSmall() {
    setSVG(APP->window->loadSvg(assetPlugin(pluginInstance, "res/KnobRedSmall.svg")));
  }
};

struct RCKnobRedSmallSnap : RCKnobRedSmall {
  RCKnobRedSmallSnap() {
    snap = true;
  }
};

struct RCKnobWhiteLarge : RoundKnob {
  RCKnobWhiteLarge() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/KnobWhiteLarge.svg")));
  }
};

struct RCKnobWhiteLargeSnap : RCKnobWhiteLarge {
  RCKnobWhiteLargeSnap() {
    snap = true;
  }
};

struct RCKnobWhite : RoundKnob {
  RCKnobWhite() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/KnobWhite.svg")));
  }
};

struct RCKnobWhiteSnap : RCKnobWhite {
  RCKnobWhiteSnap() {
    snap = true;
  }
};

struct RCKnobWhiteSmall : RoundKnob {
  RCKnobWhiteSmall() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/KnobWhiteSmall.svg")));
  }
};

struct RCKnobWhiteSmallSnap : RCKnobWhiteSmall {
  RCKnobWhiteSmallSnap() {
    snap = true;
  }
};
