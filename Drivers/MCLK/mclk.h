#include "sam.h"
#include <stdint-gcc.h>
#include <stdbool.h>

#ifndef DRIVERS_SAML10_REGMCLK_H_
#define DRIVERS_SAML10_REGMCLK_H_


namespace Drivers{
	namespace SAML10{
		//namespace Def = DefRegGclk;
		
		class RegMclk {
			public:
				static void setMainClockSelect(bool _cksel);
				static bool getMainClockSelect(void);
				// static void disableInterrupt(void)
				// static void enableInterrupt(void);
				// static void clearInterrupt(void);
				static void setCpuDiv(uint8_t div);
				static uint8_t getCpuDiv(void);
				static void setAhbMask(uint32_t _config);
				static void setAhbMask(bool tram, bool nvmctrl, bool pac, bool dsu, bool dmac, bool apbc, bool apbb, bool apba);
				static uint32_t getAhbMask(void);
				static void setApbaMask(uint32_t _config);
				static void setApbaMask(bool ac, bool port, bool freqm, bool eic, bool rtc, bool wdt, bool gclk, bool supc, bool osc32kctrl, bool oscctrl, bool rstc, bool mclk, bool pm, bool pac);
				static uint32_t getApbaMask(void);
				static void setApbbMask(uint32_t _config);
				static void setApbbMask(bool nvmctrl, bool dsu, bool idau);
				static uint32_t getApbbMask(void);
				static void setApbcMask(uint32_t _config);
				static void setApbcMask(bool opamp, bool ccl, bool trng, bool ptc, bool dac, bool adc, bool tc2, bool tc1, bool tc0, bool sercom2, bool sercom1, bool sercom0, bool evsys);
				static uint32_t getApbcMask(void);
				
			
			private:
			RegMclk(void);
			~RegMclk(void);
		};
	}
}

#endif /* DRIVERS_SAML10_REGMCLK_H_ */