#ifndef DRIVERS_SAML10_USART_H_
#define DRIVERS_SAML10_USART_H_

#include "Drivers/USART/config_usart.h"
#include "Drivers/USART/msg_usart.h"
#include "sam.h"

namespace Drivers{
	namespace SAML10{
		class RegUsart{
		public:
			static void init(Sercom* hw, const ConfigUsart& conf);
			static void setCtrlA(Sercom* hw, uint8_t dord, uint8_t cpol, uint8_t cmode, uint8_t form,
						  uint8_t sampa, uint8_t rxpo, uint8_t txpo, uint8_t sampr,
						  uint8_t rxinv, uint8_t txinv, uint8_t ibon, uint8_t runstdby,
						  uint8_t mode, uint8_t enable, uint8_t swrst);
			static void setCtrlA(Sercom* hw, uint32_t config);
			static void setCtrlB(Sercom* hw, uint8_t rxen, uint8_t txen, uint8_t pmode, uint8_t enc,
						  uint8_t sfde, uint8_t colden, uint8_t sbmode, uint8_t chsize);
			static void setCtrlB(Sercom* hw, uint32_t config);
			static void setCtrlC(Sercom* hw, uint8_t maxiter, uint8_t dsnack, uint8_t inack, uint8_t gtime);
			static void setCtrlC(Sercom* hw, uint32_t config);
			static void setBaud(Sercom* hw, uint16_t baud, uint8_t fractional);
			static void setRxpl(Sercom* hw, uint8_t rxpl);
			static void setIntEnClr(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
							 uint8_t rxc, uint8_t txc, uint8_t dre);
			static void setIntEnSet(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
							 uint8_t rxc, uint8_t txc, uint8_t dre);
			static void setIntFlag(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
							uint8_t rxc, uint8_t txc, uint8_t dre);
			static void setData(Sercom* hw, uint16_t data);

			static uint32_t getCtrlA(Sercom* hw);
	 		static uint32_t getCtrlB(Sercom* hw);
	 		static uint32_t getCtrlC(Sercom* hw);
	 		static uint32_t getBaud(Sercom* hw);
	 		static uint32_t getRxpl(Sercom* hw);
	 		static uint32_t getIntEnClr(Sercom* hw);
	 		static uint32_t getIntEnSet(Sercom* hw);
	 		static uint32_t getIntFlag(Sercom* hw);
	 		static uint16_t getData(Sercom* hw);
			static uint32_t getSyncBusy(Sercom* hw);
			static bool		isSyncBusy(Sercom* hw, uint32_t mask);
			static void		waitSync(Sercom* hw, uint32_t mask);
		};
	}
}

#endif /* DRIVERS_SAML10_USART_H_ */