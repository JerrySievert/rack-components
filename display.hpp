#pragma once

#include <cstdint>

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *plugin;

struct WaveSelect : TransparentWidget {
  uint8_t *value;
  std::shared_ptr<Font> font;

	WaveSelect ( ) {
    value = NULL;
    font = Font::load(assetPlugin(plugin, "res/digit.ttf"));
  }

  void draw (NVGcontext *vg) override {
    nvgFontSize(vg, 8);
		nvgFontFaceId(vg, font->handle);
		nvgTextLetterSpacing(vg, 1);

		nvgFillColor(vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      switch (*value) {
      case 0:
        nvgText(vg, box.pos.x + 1, box.pos.y + 1, "SIN", NULL);
        break;
      case 1:
        nvgText(vg, box.pos.x + 1, box.pos.y + 1, "TRI", NULL);
        break;
      case 2:
        nvgText(vg, box.pos.x + 1, box.pos.y + 1, "SAW", NULL);
        break;
      case 3:
        nvgText(vg, box.pos.x + 1, box.pos.y + 1, "SQR", NULL);
        break;
      default:
        nvgText(vg, box.pos.x + 1, box.pos.y + 1, "ERR", NULL);
        break;
      }
    } else {
      nvgText(vg, box.pos.x + 1, box.pos.y + 1, "NUL", NULL);
    }
  }
};

struct ValueDisplay : TransparentWidget {
  float *value;
  std::shared_ptr<Font> font;

	ValueDisplay ( ) {
    value = NULL;
    font = Font::load(assetPlugin(plugin, "res/digit.ttf"));
  }

  void draw (NVGcontext *vg) override {
    char text[12];
    nvgFontSize(vg, 8);
		nvgFontFaceId(vg, font->handle);
		nvgTextLetterSpacing(vg, 1);

		nvgFillColor(vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      sprintf(text, "%6.2f", *value);
    } else {
      sprintf(text, "ERROR");
    }

    nvgText(vg, box.pos.x + 1, box.pos.y + 1, text, NULL);
  }
};
