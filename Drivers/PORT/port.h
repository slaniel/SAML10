#include "sam.h"

#ifndef DRIVERS_SAML10_REGPORT_H_
#define DRIVERS_SAML10_REGPORT_H_

namespace Drivers {
	namespace SAML10{
		class RegPort{
		public:
			enum enum_PERIPHERAL{
				PERIPHERAL_A = 0x00UL,
				PERIPHERAL_B = 0x01UL,
				PERIPHERAL_C = 0x02UL,
				PERIPHERAL_D = 0x03UL,
				PERIPHERAL_E = 0x04UL,
		//		PERIPHERAL_F,
				PERIPHERAL_G = 0x06UL,
				PERIPHERAL_H = 0x07UL,
				PERIPHERAL_I = 0x08UL
			};
	
			//static void enableClock(void);
			static void setAsOutput(uint32_t pin);
			static void setAsInput(uint32_t pin);
			static void setAsPeripheral(uint32_t pin, enum enum_PERIPHERAL peripheral);
			static uint32_t getLevel(uint32_t pin);
			static void setLevel(uint32_t pin, uint8_t level);
			static void toggleLevel(uint32_t pin);
			static void setPullUp(uint32_t pin);
			static void setPullDown(uint32_t pin);
			static void disablePull(uint32_t pin);
	
		private:
			// Prevent creating instance of object
			RegPort(void);
			~RegPort(void);
		};
	}
}

#endif /* DRIVERS_SAML10_REGPORT_H_ */