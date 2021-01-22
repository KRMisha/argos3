/**
 * @file <argos3/plugins/robots/foot-bot/control_interface/ci_spiri_proximity_sensor.h>
 *
 * @brief This file provides the definition of the spiri proximity sensor.
 *
 * This file provides the definition of the spiri proximity sensor.
 * The sensors are evenly spaced on a ring around the base of the robot.
 * Therefore, they do not turn with the turret. The readings are normalized
 * between 0 and 1, and are in the following order (seeing the robot from TOP,
 * battery socket is the BACK):
 *
 *              front
 *
 *                0
 *             -     -
 *           -         -
 *         -             -      r
 * l     -                 -    i
 * e   1                     -  g
 * f   -                     3  h
 * t     -                 -    t
 *         -             -
 *           -         -
 *            -     -
 *              2 -
 *
 *              back
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 * @author Pierre-Yves Lajoie <lajoie.py@gmail.com>
 */

#ifndef CCI_SPIRI_PROXIMITY_SENSOR_H
#define CCI_SPIRI_PROXIMITY_SENSOR_H

namespace argos {
   class CCI_SpiriProximitySensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/angles.h>

namespace argos {

   class CCI_SpiriProximitySensor : public CCI_Sensor {

   public:

      struct SReading {
         Real Value;
         CRadians Angle;

         SReading() :
            Value(0.0f) {}

         SReading(Real f_value,
                  const CRadians& c_angle) :
            Value(f_value),
            Angle(c_angle) {}
      };

      typedef std::vector<SReading> TReadings;

   public:

      /**
       * Class constructor
       */
      CCI_SpiriProximitySensor();

      /**
       * Class destructor
       */
      virtual ~CCI_SpiriProximitySensor() {}

      /**
       * Returns the readings of this sensor
       */
      const TReadings& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      TReadings m_tReadings;

   };

   std::ostream& operator<<(std::ostream& c_os, const CCI_SpiriProximitySensor::SReading& s_reading);
   std::ostream& operator<<(std::ostream& c_os, const CCI_SpiriProximitySensor::TReadings& t_readings);

}

#endif
