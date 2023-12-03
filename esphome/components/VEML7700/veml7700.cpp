#include "veml7700.h"
#include "esphome/core/log.h"

namespace esphome {
namespace veml7700 {

static const char *const TAG = "veml7700";

void VEML7700Sensor::setup() {
  ESP_LOGCONFIG(TAG, "Setting up VEML7700 '%s'...", this->name_.c_str());

}
uint8_t VEML7700Sensor::getGain(void) { return ALS_Gain->read(); }
uint8_t VEML7700Sensor::getIntegrationTime(void) {
  return ALS_Integration_Time->read();
}
int VEML7700Sensor::getIntegrationTimeValue(void) {
  switch (getIntegrationTime()) {
  case VEML7700_IT_25MS:
    return 25;
  case VEML7700_IT_50MS:
    return 50;
  case VEML7700_IT_100MS:
    return 100;
  case VEML7700_IT_200MS:
    return 200;
  case VEML7700_IT_400MS:
    return 400;
  case VEML7700_IT_800MS:
    return 800;
  default:
    return -1;
  }
}
float VEML7700Sensor::getGainValue(void) {
  switch (getGain()) {
  case VEML7700_GAIN_1_8:
    return 0.125;
  case VEML7700_GAIN_1_4:
    return 0.25;
  case VEML7700_GAIN_1:
    return 1;
  case VEML7700_GAIN_2:
    return 2;
  default:
    return -1;
  }
}
float VEML7700Sensor::getResolution(void) {
  return MAX_RES * (IT_MAX / getIntegrationTimeValue()) *
         (GAIN_MAX / getGainValue());
}
void VEML7700Sensor::read_data_() {
  float lux = getResolution() * rawALS;
    lux = (((6.0135e-13 * lux - 9.3924e-9) * lux + 8.1488e-5) * lux + 1.0023) * lux;
  
  ESP_LOGD(TAG, "Got illuminance=%.1flux", lux);
  this->publish_state(lux);
  this->status_clear_warning();
}
}  // namespace veml7700
}  // namespace esphome
