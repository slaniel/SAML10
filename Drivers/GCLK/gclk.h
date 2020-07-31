#ifndef DRIVERS_SAML10_REGGCLK_H_
#define DRIVERS_SAML10_REGGCLK_H_

#include "sam.h"
#include "Drivers/GCLK/def_gclk.h"
#include <stdint-gcc.h>
#include <stdbool.h>

namespace Def = Drivers::SAML10::DefRegGclk;

namespace Drivers{
	namespace SAML10{
		
		class RegGclk {
		public:
			static void reset(bool _wait);
			static bool isSyncBusy(uint32_t _val);
			static void setGenCtrl(Def::GENCTRL::Channel _channel, uint32_t _config);
			static void setGenCtrl(Def::GENCTRL::Channel _channel, uint16_t DIV, bool RUNSTDBY, bool DIVSEL, bool OE, bool OOV, bool IDC, bool GENEN, uint8_t SRC);
			static uint32_t getGenCtrl(Def::GENCTRL::Channel _channel);
			static void setPchCtrl(Def::PCHCTRL::Channel _channel, uint32_t _config);
			static void setPchCtrl(Def::PCHCTRL::Channel _channel, bool WRTLOCK, bool CHEN, uint8_t GEN);
			static uint32_t getPchCtrl(Def::PCHCTRL::Channel _channel);
			
		private:
			RegGclk(void);
			~RegGclk(void);
		};
	}
}

#endif /* DRIVERS_SAML10_REGGCLK_H_ */