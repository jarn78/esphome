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
class VEML7700Sensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
 public:
  /** Set the time that sensor values should be accumulated for.
   *
   * Longer means more accurate, but also mean more power consumption.
   *
   * Possible values are:
   *
   *  - `sensor::TSL2561_INTEGRATION_14MS`
   *  - `sensor::TSL2561_INTEGRATION_101MS`
   *  - `sensor::TSL2561_INTEGRATION_402MS` (default)
   *
   * @param integration_time The new integration time.
   */
  void set_integration_time(VEML7700IntegrationTime integration_time);

  /** Set the internal gain of the sensor. Can be useful for low-light conditions
   *
   * Possible values are:
   *
   *  - `sensor::TSL2561_GAIN_1X` (default)
   *  - `sensor::TSL2561_GAIN_16X`
   *
   * @param gain The new gain.
   */
  void set_gain(VEML7700Gain gain);

  /** The "CS" package of this sensor has a slightly different formula for
   * converting the raw values. Use this setting to indicate that this is a CS
   * package. Defaults to false (not a CS package)
   *
   * @param package_cs Is this a CS package.
   */
 // void set_is_cs_package(bool package_cs);

  // ========== INTERNAL METHODS ==========
  // (In most use cases you won't need these)
  void setup() override;
  void dump_config() override;
  void update() override;
  float get_setup_priority() const override;

  bool tsl2561_read_byte(uint8_t a_register, uint8_t *value);
  bool tsl2561_read_uint(uint8_t a_register, uint16_t *value);
  bool tsl2561_write_byte(uint8_t a_register, uint8_t value);

 protected:
  float get_integration_time_ms_();
  void read_data_();
  float calculate_lx_(uint16_t ch0, uint16_t ch1);

  TSL2561IntegrationTime integration_time_{TSL2561_INTEGRATION_402MS};
  TSL2561Gain gain_{TSL2561_GAIN_1X};

};
}  // namespace veml7700
}  // namespace esphome
