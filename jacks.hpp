#pragma once

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

struct LocalPort : PortWidget {
	widget::FramebufferWidget *fb;
	widget::SvgWidget *sw;

  LocalPort() {
  	fb = new widget::FramebufferWidget;
  	addChild(fb);

  	sw = new widget::SvgWidget;
  	fb->addChild(sw);
  }

  void setSvg(std::shared_ptr<Svg> svg) {
  	sw->setSvg(svg);
  	fb->box.size = sw->box.size;
  	box.size = sw->box.size;

  	fb->dirty = true;
  }

};

struct RCJackSmallRed : LocalPort {
  RCJackSmallRed() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallRed.svg")));
  }
};

struct RCJackSmallGrey : LocalPort {
  RCJackSmallGrey() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallGrey.svg")));
  }
};

struct RCJackSmallDark : LocalPort {
  RCJackSmallDark() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallDark.svg")));
  }
};


struct RCJackSmallLight : LocalPort {
  RCJackSmallLight() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/JackSmallLight.svg")));
  }
};
