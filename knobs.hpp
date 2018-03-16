#pragma once

#include "asset.hpp"
#include "rack.hpp"

extern Plugin *plugin;

struct RCKnobRed : RoundKnob {
  RCKnobRed() {
    setSVG(SVG::load(assetPlugin(plugin, "res/KnobRed.svg")));
  }
};

struct RCKnobRedSnap : RCKnobRed {
  RCKnobRedSnap ( ) {
    snap = true;
  }
};

struct RCKnobRedLarge : RoundKnob {
  RCKnobRedLarge() {
    setSVG(SVG::load(assetPlugin(plugin, "res/KnobRedLarge.svg")));
  }
};

struct RCKnobRedLargeSnap : RCKnobRedLarge {
  RCKnobRedLargeSnap ( ) {
    snap = true;
  }
};
