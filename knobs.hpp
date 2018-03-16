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

struct RCKnobWhiteLarge : RoundKnob {
  RCKnobWhiteLarge() {
    setSVG(SVG::load(assetPlugin(plugin, "res/KnobWhiteLarge.svg")));
  }
};

struct RCKnobWhiteLargeSnap : RCKnobWhiteLarge {
  RCKnobWhiteLargeSnap() {
    snap = true;
  }
};

struct RCKnobWhite : RoundKnob {
  RCKnobWhite() {
    setSVG(SVG::load(assetPlugin(plugin, "res/KnobWhite.svg")));
  }
};

struct RCKnobWhiteSnap : RCKnobWhite {
  RCKnobWhiteSnap() {
    snap = true;
  }
};

struct RCKnobWhiteSmall : RoundKnob {
  RCKnobWhiteSmall() {
    setSVG(SVG::load(assetPlugin(plugin, "res/KnobWhiteSmall.svg")));
  }
};

struct RCKnobWhiteSmallSnap : RCKnobWhiteSmallSnap {
  RCKnobWhiteSmallSnap() {
    snap = true;
  }
};
