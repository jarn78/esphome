#include "veml7700.h"
#include "esphome/core/log.h"

namespace esphome {
namespace veml7700 {

static const char *const TAG = "veml7700";

void VEML7700Sensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up VEML7700 '%s'...", this->name_.c_str());

}

}  // namespace veml7700
}  // namespace esphome
