#include "sam.h"

#ifndef DRIVERS_SAML10_DEF_REGGCLK_H_
#define DRIVERS_SAML10_DEF_REGGCLK_H_

namespace Drivers{
	namespace SAML10{
		namespace DefRegGclk{
			class SYNCBUSY{
			public:
				const static uint32_t SWRST = GCLK_SYNCBUSY_SWRST;
				const static uint32_t GENCTRL[5];
			};
			
			class GENCTRL{
				public:
				enum Channel {
					GCLK_GENERATOR_0 = 0,
					GCLK_GENERATOR_1,
					GCLK_GENERATOR_2,
					GCLK_GENERATOR_3,
					GCLK_GENERATOR_4
				};
			};
			
			class PCHCTRL{
				public: 
				enum Channel {
					DPLL = 0,
					GCLK_DPLL_32K,
					GCLK_DFLLULP,
					GCLK_EIC,
					GCLK_FREQM_MSR,
					GCLK_FREQM_REF,
					GCLK_EVSYS_CHANNEL_0,
					GCLK_EVSYS_CHANNEL_1,
					GCLK_EVSYS_CHANNEL_2,
					GCLK_EVSYS_CHANNEL_3,
					GCLK_SERCOM_SLOW,
					GCLK_SERCOM0_CORE,
					GCLK_SERCOM1_CORE,
					GCLK_SERCOM2_CORE,
					GCLK_TC0 = 14,
					GCLK_TC1 = 14,
					GCLK_TC2,
					GCLK_ADC,
					GCLK_AC,
					GCLK_DAC,
					GCLK_PTC,
					GCLK_CCL
				};
			};
		}
	}
}

#endif /* DRIVERS_SAML10_DEF_REGGCLK_H_ */