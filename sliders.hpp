#pragma once

#include <cstdint>

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

struct RCSlider : SVGFader {
	RCSlider() {
		Vec margin = Vec(4, 4);
		maxHandlePos = Vec(1.3, -7).plus(margin);
		minHandlePos = Vec(1.3, 79).plus(margin);
		setBackgroundSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/Slider.svg");
		background->wrap();
		background->box.pos = margin;
		box.size = background->box.size.plus(margin.mult(2));
		setHandleSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/SliderHandle.svg"));
		handle->wrap();
	}
};
