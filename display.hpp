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

struct FrequencyDisplay : TransparentWidget {
  float *value;
  std::shared_ptr<Font> font;

	FrequencyDisplay ( ) {
    value = NULL;
    font = Font::load(assetPlugin(plugin, "res/digit.ttf"));
  }

  void draw (NVGcontext *vg) override {
    char text[16];
    nvgFontSize(vg, 7);
		nvgFontFaceId(vg, font->handle);
		nvgTextLetterSpacing(vg, 0.5);

		nvgFillColor(vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      sprintf(text, "%5.0fHz", *value);
    } else {
      sprintf(text, "ERROR");
    }

    nvgText(vg, box.pos.x + 1, box.pos.y + 1, text, NULL);
  }
};

/*
bq_type_lowpass = 0,
bq_type_highpass,
bq_type_bandpass,
bq_type_notch,
bq_type_peak,
bq_type_lowshelf,
bq_type_highshelf
*/

struct EqTypeDisplay : TransparentWidget {
  uint8_t *value;
  std::shared_ptr<Font> font;

	EqTypeDisplay ( ) {
    value = NULL;
    font = Font::load(assetPlugin(plugin, "res/digit.ttf"));
  }

  void draw (NVGcontext *vg) override {
    char *text;
    nvgFontSize(vg, 6);
		nvgFontFaceId(vg, font->handle);
		nvgTextLetterSpacing(vg, 0.5);

		nvgFillColor(vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    switch (*value) {
    case 0:
      nvgText(vg, box.pos.x + 12, box.pos.y + 2, "LOW", NULL);
      nvgText(vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
      break;
    case 1:
      nvgText(vg, box.pos.x + 10, box.pos.y + 2, "HIGH", NULL);
      nvgText(vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
      break;
    case 2:
      nvgText(vg, box.pos.x + 10, box.pos.y + 2, "BAND", NULL);
      nvgText(vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
      break;
    case 3:
      nvgText(vg, box.pos.x + 7, box.pos.y + 6, "NOTCH", NULL);;
      break;
    case 4:
      nvgText(vg, box.pos.x + 8, box.pos.y + 6, "PEAK", NULL);;
      break;
    case 5:
      nvgText(vg, box.pos.x + 12, box.pos.y + 2, "LOW", NULL);
      nvgText(vg, box.pos.x + 7, box.pos.y + 10, "SHELF", NULL);
      break;
    case 6:
      nvgText(vg, box.pos.x + 10, box.pos.y + 2, "HIGH", NULL);
      nvgText(vg, box.pos.x + 7, box.pos.y + 10, "SHELF", NULL);
      break;
    default:
      nvgText(vg, box.pos.x + 1, box.pos.y + 1, "ERROR", NULL);;
    }

    nvgText(vg, box.pos.x + 1, box.pos.y + 1, text, NULL);
  }
};
