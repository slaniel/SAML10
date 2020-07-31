#include "Drivers/USART/usart.h"

namespace Drivers{
	namespace SAML10{
		
		volatile uint16_t MsgUsart::wIndex = 0;
		volatile uint16_t MsgUsart::rIndex = 0;
		volatile uint8_t MsgUsart::data[MAX_SIZE];
		volatile uint8_t MsgUsart::busy = 0;
		
		void RegUsart::init(Sercom* hw, const ConfigUsart& conf){
			if((getSyncBusy(hw) & SERCOM_USART_SYNCBUSY_SWRST) == 0) {
				uint32_t mode = getCtrlA(hw) & SERCOM_USART_CTRLA_MODE_Msk;
				if(getCtrlA(hw) & SERCOM_USART_CTRLA_ENABLE_Msk){
					setCtrlA(hw, (getCtrlA(hw) & (~SERCOM_USART_CTRLA_ENABLE_Msk)));
					waitSync(hw, SERCOM_USART_SYNCBUSY_ENABLE);
				}
				setCtrlA(hw, SERCOM_USART_CTRLA_SWRST | mode);
			}
			waitSync(hw, SERCOM_USART_SYNCBUSY_SWRST);
			
			setCtrlA(hw, conf.Dord, conf.Cpol, conf.Cmode, conf.Form, conf.Sampa, conf.Rxpo, 
					 conf.Txpo, conf.Sampr, conf.Rxinv, conf.Txinv, conf.Ibon, conf.Runstdby,
					 conf.Mode, false, false);
			setCtrlB(hw, conf.Rxen, conf.Txen, conf.Pmode, conf.Enc, conf.Sfde, conf.Colden,
					 conf.Sbmode, conf.Chsize);
			setCtrlC(hw, conf.Maxiter, conf.Dsnack, conf.Inack, conf.Gtime);
			setBaud(hw, conf.Baud_rate, conf.Fractional);
			setRxpl(hw, conf.Receive_pulse_length);
		}
		void RegUsart::setCtrlA(Sercom* hw, uint8_t dord, uint8_t cpol, uint8_t cmode, uint8_t form,
								uint8_t sampa, uint8_t rxpo, uint8_t txpo, uint8_t sampr,
								uint8_t rxinv, uint8_t txinv, uint8_t ibon, uint8_t runstdby,
								uint8_t mode, uint8_t enable, uint8_t swrst){
			hw->USART.CTRLA.bit.CMODE = cmode;
			hw->USART.CTRLA.bit.CPOL = cpol;
			hw->USART.CTRLA.bit.DORD = dord;
			hw->USART.CTRLA.bit.ENABLE = enable;
			hw->USART.CTRLA.bit.FORM = form;
			hw->USART.CTRLA.bit.IBON = ibon;
			hw->USART.CTRLA.bit.MODE = mode;
			hw->USART.CTRLA.bit.RUNSTDBY = runstdby;
			hw->USART.CTRLA.bit.RXINV = rxinv;
			hw->USART.CTRLA.bit.RXPO = rxpo;
			hw->USART.CTRLA.bit.SAMPA = sampa;
			hw->USART.CTRLA.bit.SAMPR = sampr;
			hw->USART.CTRLA.bit.SWRST = swrst;
			hw->USART.CTRLA.bit.TXINV = txinv;
			hw->USART.CTRLA.bit.TXPO = txpo;
		}
		void RegUsart::setCtrlA(Sercom* hw, uint32_t config){
			hw->USART.CTRLA.reg = config;
		}
		void RegUsart::setCtrlB(Sercom* hw, uint8_t rxen, uint8_t txen, uint8_t pmode, uint8_t enc,
								uint8_t sfde, uint8_t colden, uint8_t sbmode, uint8_t chsize){
			hw->USART.CTRLB.bit.CHSIZE = chsize;
			hw->USART.CTRLB.bit.COLDEN = colden;
			hw->USART.CTRLB.bit.ENC = enc;
			hw->USART.CTRLB.bit.PMODE = pmode;
			hw->USART.CTRLB.bit.RXEN = rxen;
			hw->USART.CTRLB.bit.SBMODE = sbmode;
			hw->USART.CTRLB.bit.SFDE = sfde;
			hw->USART.CTRLB.bit.TXEN = txen;
		}
		void RegUsart::setCtrlB(Sercom* hw, uint32_t config){
			hw->USART.CTRLB.reg = config;
		}
		void RegUsart::setCtrlC(Sercom* hw, uint8_t maxiter, uint8_t dsnack, uint8_t inack, uint8_t gtime){
			hw->USART.CTRLC.bit.DSNACK = dsnack;
			hw->USART.CTRLC.bit.GTIME = gtime;
			hw->USART.CTRLC.bit.INACK = inack;
			hw->USART.CTRLC.bit.MAXITER = maxiter;
		}
		void RegUsart::setCtrlC(Sercom* hw, uint32_t config){
			hw->USART.CTRLC.reg = config;
		}
		void RegUsart::setBaud(Sercom* hw, uint16_t baud, uint8_t fractional){
			hw->USART.BAUD.bit.BAUD = baud + SERCOM_USART_BAUD_FRAC_FP(fractional);
		}
		void RegUsart::setRxpl(Sercom* hw, uint8_t rxpl){
			hw->USART.RXPL.bit.RXPL = rxpl;
		}
		void RegUsart::setIntEnClr(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
								   uint8_t rxc, uint8_t txc, uint8_t dre){
			hw->USART.INTENCLR.bit.CTSIC = ctsic;
			hw->USART.INTENCLR.bit.DRE = dre;
			hw->USART.INTENCLR.bit.ERROR = error;
			hw->USART.INTENCLR.bit.RXBRK = rxbrk;
			hw->USART.INTENCLR.bit.RXC = rxc;
			hw->USART.INTENCLR.bit.RXS = rxs;
			hw->USART.INTENCLR.bit.TXC = txc;
		}
		void RegUsart::setIntEnSet(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
								   uint8_t rxc, uint8_t txc, uint8_t dre){
			hw->USART.INTENSET.bit.CTSIC = ctsic;
			hw->USART.INTENSET.bit.DRE = dre;
			hw->USART.INTENSET.bit.ERROR = error;
			hw->USART.INTENSET.bit.RXBRK = rxbrk;
			hw->USART.INTENSET.bit.RXC = rxc;
			hw->USART.INTENSET.bit.RXS = rxs;
			hw->USART.INTENSET.bit.TXC = txc;
		}
		void RegUsart::setIntFlag(Sercom* hw, uint8_t error, uint8_t rxbrk, uint8_t ctsic, uint8_t rxs,
								  uint8_t rxc, uint8_t txc, uint8_t dre){
			hw->USART.INTENSET.bit.CTSIC = ctsic;
			hw->USART.INTENSET.bit.DRE = dre;
			hw->USART.INTENSET.bit.ERROR = error;
			hw->USART.INTENSET.bit.RXBRK = rxbrk;
			hw->USART.INTENSET.bit.RXC = rxc;
			hw->USART.INTENSET.bit.RXS = rxs;
			hw->USART.INTENSET.bit.TXC = txc;
		}
		void RegUsart::setData(Sercom* hw, uint16_t data){
			hw->USART.DATA.bit.DATA = data;
		}

		uint32_t RegUsart::getCtrlA(Sercom* hw){ return hw->USART.CTRLA.reg; }
		uint32_t RegUsart::getCtrlB(Sercom* hw){ return hw->USART.CTRLB.reg; }
		uint32_t RegUsart::getCtrlC(Sercom* hw){ return hw->USART.CTRLC.reg; }
		uint32_t RegUsart::getBaud(Sercom* hw){ return hw->USART.BAUD.reg; }
		uint32_t RegUsart::getRxpl(Sercom* hw){ return hw->USART.RXPL.reg; }
		uint32_t RegUsart::getIntEnClr(Sercom* hw){ return hw->USART.INTENCLR.reg; }
		uint32_t RegUsart::getIntEnSet(Sercom* hw){ return hw->USART.INTENSET.reg; }
		uint32_t RegUsart::getIntFlag(Sercom* hw){ return hw->USART.INTFLAG.reg; }
		uint16_t RegUsart::getData(Sercom* hw){ return hw->USART.DATA.reg; }
		uint32_t RegUsart::getSyncBusy(Sercom* hw){ return hw->USART.SYNCBUSY.reg; }
		bool	 RegUsart::isSyncBusy(Sercom* hw, uint32_t mask){ return ((hw->USART.SYNCBUSY.reg & mask) != 0); }
		void	 RegUsart::waitSync(Sercom* hw, uint32_t mask){ while(isSyncBusy(hw, mask) != 0); }
	}
}