#pragma once

#include <cstdint>

#include "asset.hpp"
#include "rack.hpp"

using namespace rack;

extern Plugin *pluginInstance;

struct WaveSelect : TransparentWidget {
  uint8_t *value;
  std::shared_ptr<Font> font;

	WaveSelect ( ) {
    value = NULL;
    font = APP->window->loadFont(asset::plugin(pluginInstance, "res/digit.ttf"));
  }

  void draw (const DrawArgs &args) override {
    nvgFontSize(args.vg, 8);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextLetterSpacing(args.vg, 1);

		nvgFillColor(args.vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      switch (*value) {
      case 0:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "SIN", NULL);
        break;
      case 1:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "TRI", NULL);
        break;
      case 2:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "SAW", NULL);
        break;
      case 3:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "SQR", NULL);
        break;
      default:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "ERR", NULL);
        break;
      }
    } else {
      nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "NUL", NULL);
    }
  }
};

struct ValueDisplay : TransparentWidget {
  float *value;
  std::shared_ptr<Font> font;

	ValueDisplay ( ) {
    value = NULL;
    font = APP->window->loadFont(asset::plugin(pluginInstance, "res/digit.ttf"));
  }

  void draw (const DrawArgs &args) override {
    char text[12];
    nvgFontSize(args.vg, 8);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextLetterSpacing(args.vg, 1);

		nvgFillColor(args.vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      sprintf(text, "%6.2f", *value);
    } else {
      sprintf(text, "ERROR");
    }

    nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, text, NULL);
  }
};

struct LEDDisplay : TransparentWidget {
  float *value;

	LEDDisplay ( ) {
    value = NULL;
  }

  void draw (const DrawArgs &args) override {
    NVGcolor red = nvgRGBA(192, 0, 0, 255);
    NVGcolor yellow = nvgRGBA(255, 192, 0, 255);
    NVGcolor green = nvgRGBA(0, 192, 0, 255);
    NVGcolor grey = nvgRGBA(64, 64, 64, 255);
    float val = *value ? *value : 0.0f;

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 0, 8, 8);
    if (fabs(val) >= 4.5) {
      nvgFillColor(args.vg, red);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);


    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 11, 8, 8);
    if (fabs(val) >= 4.0) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 22, 8, 8);
    if (fabs(val) >= 3.5) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 33, 8, 8);
    if (fabs(val) >= 3.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 44, 8, 8);
    if (fabs(val) >= 2.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 55, 8, 8);
    if (fabs(val) >= 2.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 66, 8, 8);
    if (fabs(val) >= 1.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 77, 8, 8);
    if (fabs(val) >= 1.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 88, 8, 8);
    if (fabs(val) >= 0.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 99, 8, 8);
    if (fabs(val) > 0.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);
  }
};

struct LEDSmallDisplay : TransparentWidget {
  float *value;

	LEDSmallDisplay ( ) {
    value = NULL;
  }

  void draw (const DrawArgs &args) override {
    NVGcolor red = nvgRGBA(192, 0, 0, 255);
    NVGcolor yellow = nvgRGBA(255, 192, 0, 255);
    NVGcolor green = nvgRGBA(0, 192, 0, 255);
    NVGcolor grey = nvgRGBA(64, 64, 64, 255);
    float val = *value ? *value : 0.0f;

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 0, 8, 6);
    if (fabs(val) >= 4.5) {
      nvgFillColor(args.vg, red);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);


    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 8, 8, 6);
    if (fabs(val) >= 4.0) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 16, 8, 6);
    if (fabs(val) >= 3.5) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 24, 8, 6);
    if (fabs(val) >= 3.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 32, 8, 6);
    if (fabs(val) >= 2.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 40, 8, 6);
    if (fabs(val) >= 2.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 48, 8, 6);
    if (fabs(val) >= 1.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 56, 8, 6);
    if (fabs(val) >= 1.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 64, 8, 6);
    if (fabs(val) >= 0.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 72, 8, 6);
    if (fabs(val) > 0.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);
  }
};

struct LEDWideDisplay : TransparentWidget {
  float *value;

	LEDWideDisplay ( ) {
    value = NULL;
  }

  void draw (const DrawArgs &args) override {
    NVGcolor red = nvgRGBA(192, 0, 0, 255);
    NVGcolor yellow = nvgRGBA(255, 192, 0, 255);
    NVGcolor green = nvgRGBA(0, 192, 0, 255);
    NVGcolor grey = nvgRGBA(64, 64, 64, 255);
    float val = *value ? *value : 0.0f;

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 0, 16, 8);
    if (fabs(val) >= 4.5) {
      nvgFillColor(args.vg, red);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);


    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 11, 16, 8);
    if (fabs(val) >= 4.0) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 22, 16, 8);
    if (fabs(val) >= 3.5) {
      nvgFillColor(args.vg, yellow);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 33, 16, 8);
    if (fabs(val) >= 3.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 44, 16, 8);
    if (fabs(val) >= 2.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 55, 16, 8);
    if (fabs(val) >= 2.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 66, 16, 8);
    if (fabs(val) >= 1.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 77, 16, 8);
    if (fabs(val) >= 1.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 88, 16, 8);
    if (fabs(val) >= 0.5) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);

    nvgBeginPath(args.vg);
    nvgRect(args.vg, 0, 99, 16, 8);
    if (fabs(val) > 0.0) {
      nvgFillColor(args.vg, green);
    } else {
      nvgFillColor(args.vg, grey);
    }
    nvgFill(args.vg);
  }
};

template <typename BASE>
struct ButtonLight : BASE {
	ButtonLight() {
	  //this->box.size = Vec(20.0, 20.0);
	  this->box.size = mm2px(Vec(6.0, 6.0));
	}
};

struct FrequencyDisplay : TransparentWidget {
  float *value;
  std::shared_ptr<Font> font;

	FrequencyDisplay ( ) {
    value = NULL;
    font = APP->window->loadFont(asset::plugin(pluginInstance, "res/digit.ttf"));
  }

  void draw (const DrawArgs &args) override {
    char text[16];
    nvgFontSize(args.vg, 7);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextLetterSpacing(args.vg, 0.5);

		nvgFillColor(args.vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      sprintf(text, "%5.0fHz", *value);
    } else {
      sprintf(text, "ERROR");
    }

    nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, text, NULL);
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
  uint8_t *value = nullptr;
  std::shared_ptr<Font> font;

	EqTypeDisplay ( ) {
    value = nullptr;
    font = APP->window->loadFont(asset::plugin(pluginInstance, "res/digit.ttf"));
  }

  void draw (const DrawArgs &args) override {
    nvgFontSize(args.vg, 6);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextLetterSpacing(args.vg, 0.5);

		nvgFillColor(args.vg, nvgRGBA(0x00, 0xff, 0x00, 0xff));

    if (value) {
      switch (*value) {
      case 0:
        nvgText(args.vg, box.pos.x + 12, box.pos.y + 2, "LOW", NULL);
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
        break;
      case 1:
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 2, "HIGH", NULL);
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
        break;
      case 2:
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 2, "BAND", NULL);
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 10, "PASS", NULL);
        break;
      case 3:
        nvgText(args.vg, box.pos.x + 7, box.pos.y + 6, "NOTCH", NULL);;
        break;
      case 4:
        nvgText(args.vg, box.pos.x + 8, box.pos.y + 6, "PEAK", NULL);;
        break;
      case 5:
        nvgText(args.vg, box.pos.x + 12, box.pos.y + 2, "LOW", NULL);
        nvgText(args.vg, box.pos.x + 7, box.pos.y + 10, "SHELF", NULL);
        break;
      case 6:
        nvgText(args.vg, box.pos.x + 10, box.pos.y + 2, "HIGH", NULL);
        nvgText(args.vg, box.pos.x + 7, box.pos.y + 10, "SHELF", NULL);
        break;
      default:
        nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "ERROR", NULL);
      }
    } else {
      nvgText(args.vg, box.pos.x + 1, box.pos.y + 1, "ERROR", NULL);;
    }

  }
};
