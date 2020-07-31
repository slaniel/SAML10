#include "Drivers/GCLK/gclk.h"

using namespace Drivers::SAML10;
namespace Def = Drivers::SAML10::DefRegGclk;

const uint32_t Def::SYNCBUSY::GENCTRL[5] = { GCLK_SYNCBUSY_GENCTRL0_Msk, GCLK_SYNCBUSY_GENCTRL1_Msk, GCLK_SYNCBUSY_GENCTRL2_Msk, GCLK_SYNCBUSY_GENCTRL3_Msk, GCLK_SYNCBUSY_GENCTRL4_Msk };

void RegGclk::reset(bool _wait){
	//! Soft Reset on all GCLK registers except channels of PCHTRL where WRTLOCK = 1
	GCLK->CTRLA.bit.SWRST = 1;
	//! If Wait is asked by user, stays in while until Reset sync is done.
	while(_wait && isSyncBusy(Def::SYNCBUSY::SWRST));
}
bool RegGclk::isSyncBusy(uint32_t _val){
	//! Return if the bit asked is busy (true = busy)
	return ((GCLK->SYNCBUSY.reg & _val) != 0);
}
void RegGclk::setGenCtrl(Def::GENCTRL::Channel _channel, uint32_t _config){
	//! Set Config one shot deal. Mask applied to make sure _config doesn't affect RESERVED Bits
	GCLK->GENCTRL[_channel].reg = (GCLK_GENCTRL_Msk & _config);
}
void RegGclk::setGenCtrl(Def::GENCTRL::Channel _channel, uint16_t DIV, bool RUNSTDBY, bool DIVSEL, bool OE, bool OOV, bool IDC, bool GENEN, uint8_t SRC){
	//! Set config of channel bits by bits
	GCLK->GENCTRL[_channel].bit.DIV			= DIV;
	GCLK->GENCTRL[_channel].bit.RUNSTDBY	= RUNSTDBY;
	GCLK->GENCTRL[_channel].bit.OE			= OE;
	GCLK->GENCTRL[_channel].bit.OOV			= OOV;
	GCLK->GENCTRL[_channel].bit.IDC			= DIV;
	GCLK->GENCTRL[_channel].bit.GENEN		= GENEN;
	GCLK->GENCTRL[_channel].bit.SRC			= SRC;
}
uint32_t RegGclk::getGenCtrl(Def::GENCTRL::Channel _channel){
	//! Return Generator channel register value
	return GCLK->GENCTRL[_channel].reg;
}
void RegGclk::setPchCtrl(Def::PCHCTRL::Channel _channel, uint32_t _config){
	//! Set Config one shot deal. Mask applied to make sure _config doesn't affect RESERVED Bits
	GCLK->PCHCTRL[_channel].reg = (GCLK_PCHCTRL_Msk & _config);
}
void RegGclk::setPchCtrl(Def::PCHCTRL::Channel _channel, bool WRTLOCK, bool CHEN, uint8_t GEN){
	//! Set config of channel bits by bits
	volatile int ch = (int)_channel;
	GCLK->PCHCTRL[ch].bit.WRTLOCK = WRTLOCK;
	GCLK->PCHCTRL[ch].bit.CHEN = CHEN;
	GCLK->PCHCTRL[ch].bit.GEN = GEN;
}
uint32_t RegGclk::getPchCtrl(Def::PCHCTRL::Channel _channel){
	return GCLK->PCHCTRL[_channel].reg;
}