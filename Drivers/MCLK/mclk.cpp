#include "Drivers/MCLK/mclk.h"

using namespace Drivers::SAML10;
//namespace Def = Drivers::SAML10::DefRegGclk;

void RegMclk::setMainClockSelect(bool _cksel){
	//! Set Main clock selection
	MCLK->CTRLA.bit.CKSEL = _cksel;
}
bool RegMclk::getMainClockSelect(void){
	//! Return Main clock Selection
	return (MCLK->CTRLA.bit.CKSEL);
}
// void RegMclk::disableInterrupt(void)
// void RegMclk::enableInterrupt(void){}
// void RegMclk::clearInterrupt(void){}
void RegMclk::setCpuDiv(uint8_t div){
	//! Set CPU Div = 2^(div-1)
	MCLK->CPUDIV.bit.CPUDIV = div;
}
uint8_t RegMclk::getCpuDiv(void){
	//! Return CPU Div where Div = 2^(div-1)
	return MCLK->CPUDIV.bit.CPUDIV;
}
void RegMclk::setAhbMask(uint32_t _config){
	//! One shot deal config AHB Mask, 
	MCLK->AHBMASK.reg = (_config & MCLK_AHBMASK_Msk);
}
void RegMclk::setAhbMask(bool tram, bool nvmctrl, bool pac, bool dsu, bool dmac, bool apbc, bool apbb, bool apba){
	//! Config bit by bits
	MCLK->AHBMASK.bit.TRAM_ = tram;
	MCLK->AHBMASK.bit.NVMCTRL_ = nvmctrl;
	MCLK->AHBMASK.bit.PAC_ = pac;
	MCLK->AHBMASK.bit.DSU_ = dsu;
	MCLK->AHBMASK.bit.DMAC_ = dmac;
	MCLK->AHBMASK.bit.HPB2_ = apbc;	// HPB2 = APBC in datasheet
	MCLK->AHBMASK.bit.HPB1_ = apbb;	// HPB1 = APBB in datasheet
	MCLK->AHBMASK.bit.HPB0_ = apba;	// HPB0 = APBA in datasheet
}
uint32_t RegMclk::getAhbMask(void){
	//! Return AHB Mask register
	return (MCLK->AHBMASK.reg & MCLK_AHBMASK_Msk);
}
void RegMclk::setApbaMask(uint32_t _config){
	//! One shot deal config APBA Mask
	MCLK->APBAMASK.reg = (_config & MCLK_APBAMASK_Msk);
}
void RegMclk::setApbaMask(bool ac, bool port, bool freqm, bool eic, bool rtc, bool wdt, bool gclk, bool supc, bool osc32kctrl, bool oscctrl, bool rstc, bool mclk, bool pm, bool pac){
	//! Config bit by bits
	MCLK->APBAMASK.bit.AC_ = ac;
	MCLK->APBAMASK.bit.PORT_ = port;
	MCLK->APBAMASK.bit.FREQM_ = freqm;
	MCLK->APBAMASK.bit.EIC_ = eic;
	MCLK->APBAMASK.bit.RTC_ = rtc;
	MCLK->APBAMASK.bit.WDT_ = wdt;
	MCLK->APBAMASK.bit.GCLK_ = gclk;
	MCLK->APBAMASK.bit.SUPC_ = supc;
	MCLK->APBAMASK.bit.OSC32KCTRL_ = osc32kctrl;
	MCLK->APBAMASK.bit.OSCCTRL_ = oscctrl;
	MCLK->APBAMASK.bit.RSTC_ = rstc;
	MCLK->APBAMASK.bit.MCLK_ = mclk;
	MCLK->APBAMASK.bit.PM_ = pm;
	MCLK->APBAMASK.bit.PAC_ = pac;
}
uint32_t RegMclk::getApbaMask(void){
	//! Return APBA Mask register
	return (MCLK->APBAMASK.reg & MCLK_APBAMASK_Msk);
}
void RegMclk::setApbbMask(uint32_t _config){
	//! One shot deal config APBB Mask
	MCLK->APBBMASK.reg = (_config & MCLK_APBBMASK_Msk);
}
void RegMclk::setApbbMask(bool nvmctrl, bool dsu, bool idau){
	//! Config bit by bits
	MCLK->APBBMASK.bit.NVMCTRL_ = nvmctrl;
	MCLK->APBBMASK.bit.DSU_ = dsu;
	MCLK->APBBMASK.bit.IDAU_ = idau;
}
uint32_t RegMclk::getApbbMask(void){
	//! Return APBB Mask register
	return (MCLK->APBBMASK.reg & MCLK_APBBMASK_Msk);
}
void RegMclk::setApbcMask(uint32_t _config){
	//! One shot deal config APBC Mask
	MCLK->APBCMASK.reg = (_config & MCLK_APBCMASK_Msk);
}
void RegMclk::setApbcMask(bool opamp, bool ccl, bool trng, bool ptc, bool dac, bool adc, bool tc2, bool tc1, bool tc0, bool sercom2, bool sercom1, bool sercom0, bool evsys){
	//! Config bit by bits
	MCLK->APBCMASK.bit.OPAMP_ = opamp;
	MCLK->APBCMASK.bit.CCL_ = ccl;
	MCLK->APBCMASK.bit.TRNG_ = trng;
	MCLK->APBCMASK.bit.PTC_ = ptc;
	MCLK->APBCMASK.bit.DAC_ = dac;
	MCLK->APBCMASK.bit.ADC_ = adc;
	MCLK->APBCMASK.bit.TC2_ = tc2;
	MCLK->APBCMASK.bit.TC1_ = tc1;
	MCLK->APBCMASK.bit.TC0_ = tc0;
	MCLK->APBCMASK.bit.SERCOM2_ = sercom2;
	MCLK->APBCMASK.bit.SERCOM1_ = sercom1;
	MCLK->APBCMASK.bit.SERCOM0_ = sercom0;
	MCLK->APBCMASK.bit.EVSYS_ = evsys;
}
uint32_t RegMclk::getApbcMask(void){
	//! Return APBC Mask register
	return (MCLK->APBCMASK.reg & MCLK_APBCMASK_Msk);
}