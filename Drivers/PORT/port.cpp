#include "Drivers/PORT/port.h"

using namespace SAML10::Register;

//void regPort::enableClock(void){
	//
//}

void regPort::setAsOutput(uint32_t pin){
	//! The peripheral multiplexer is disable, PORT reg controls Dir and Out !//
	PORT->Group->PINCFG[pin].bit.PMUXEN = 0;
	//! The Data direction is output
	PORT->Group->DIRSET.reg = (0x1u << pin);
	//! Disable Power Drive by default
	PORT->Group->PINCFG[pin].bit.DRVSTR = 0;
	//! Disable Pull by default
	disablePull(pin);
	//! Disable Input buffer by default
	PORT->Group->PINCFG[pin].bit.INEN = 0;
}

void regPort::setAsInput(uint32_t pin){
	//! The peripheral multiplexer is disable, PORT reg controls Dir and Out
	PORT->Group->PINCFG[pin].bit.PMUXEN = 0;
	//! The Data direction is output
	PORT->Group->DIRCLR.reg = (0x1u << pin);
	//! Disable Pull by default
	disablePull(pin);
	//! Enable Input buffer by default
	PORT->Group->PINCFG[pin].bit.INEN = 1;
}
void regPort::setAsPeripheral(uint32_t pin, enum regPort::enum_PERIPHERAL peripheral){
	//! The peripheral multiplexer is enable
	PORT->Group->PINCFG[pin].bit.PMUXEN = 1;
	//! Choose peripherals
	if(pin % 2){ //! Odd Number
		PORT->Group->PMUX[pin/2].bit.PMUXO = peripheral;
	} else {	 //! Even Number
		PORT->Group->PMUX[pin/2].bit.PMUXE = peripheral;
	}
	
}
uint32_t regPort::getLevel(uint32_t pin){
	//! If pin is an output
	if(PORT->Group->DIR.reg & (0x1u << pin)) {
		//! Read directly from out register
		return ((PORT->Group->OUT.reg & (0x1u << pin)) != 0);
	} else { //! If pin is an input
		//! Read from input register
		return ((PORT->Group->IN.reg & (0x1u << pin)) != 0);
	}
}
void regPort::setLevel(uint32_t pin, uint8_t level){
	//! If pin is an output, change value
	if(PORT->Group->DIR.reg & (0x1u << pin)) {
		//! Set Logic depending on parameter level
		if(level){
			PORT->Group->OUTSET.reg = (0x1u << pin);
		} else {
			PORT->Group->OUTCLR.reg = (0x1u << pin);
		}
	}
}
void regPort::toggleLevel(uint32_t pin){
	//! If pin is an output, change value
	if(PORT->Group->DIR.reg & (0x1u << pin)) {
		//! Toggle Logic
		PORT->Group->OUTTGL.reg = (0x1u << pin);
	}
}

void regPort::setPullUp(uint32_t pin){
	//! Enable Pull
	PORT->Group->PINCFG[pin].bit.PULLEN = 1;
	//! Set PullDown
	PORT->Group->OUTSET.reg = (0x1u << pin);
}
void regPort::setPullDown(uint32_t pin){
	//! Enable Pull
	PORT->Group->PINCFG[pin].bit.PULLEN = 1;
	//! Set PullDown
	PORT->Group->OUTCLR.reg = (0x1u << pin);
}
void regPort::disablePull(uint32_t pin){
	//! Disable Pull
	PORT->Group->PINCFG[pin].bit.PULLEN = 0;
}