#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace veml7700 {


enum VEML7700Gain {
  VEML7700_GAIN_1 0x00   ///< ALS gain 1x
  VEML7700_GAIN_2 0x01   ///< ALS gain 2x
  VEML7700_GAIN_1_8 0x02 ///< ALS gain 1/8x
  VEML7700_GAIN_1_4 0x03 ///< ALS gain 1/4x
};
enum VEML7700IntegrationTime {
  VEML7700_IT_100MS 0x00 ///< ALS intetgration time 100ms
  VEML7700_IT_200MS 0x01 ///< ALS intetgration time 200ms
  VEML7700_IT_400MS 0x02 ///< ALS intetgration time 400ms
  VEML7700_IT_800MS 0x03 ///< ALS intetgration time 800ms
  VEML7700_IT_50MS 0x08  ///< ALS intetgration time 50ms
  VEML7700_IT_25MS 0x0C  ///< ALS intetgration time 25ms
};

}  // namespace veml7700
}  // namespace esphome
