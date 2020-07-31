#ifndef DRIVERS_SAML10_CONFIG_USART_H_
#define DRIVERS_SAML10_CONFIG_USART_H_

#include "sam.h"

namespace Drivers{
	namespace SAML10{
		class ConfigUsart
		{
		public:
			ConfigUsart(	uint8_t Mode, uint8_t Runstdby, uint8_t Ibon,
							uint8_t Txinv, uint8_t Rxinv, uint8_t Sampr,
							uint8_t Txpo, uint8_t Rxpo, uint8_t Sampa,
							uint8_t Form, uint8_t Cmode, uint8_t Cpol,
							uint8_t Dord, uint8_t Chsize, uint8_t Sbmode,
							uint8_t Colden, uint8_t Sfde, uint8_t Enc,
							uint8_t Pmode, uint8_t Txen, uint8_t Rxen,
							uint8_t Gtime, uint8_t Dsnack, uint8_t Inack,
							uint8_t Maxiter, uint16_t Baud_rate, uint8_t Fractional,
							uint8_t Receive_pulse_length, uint8_t Debug_stop_mode) {
				this->Mode = Mode;
				this->Runstdby = Runstdby;
				this->Ibon = Ibon;
				this->Txinv = Txinv;
				this->Rxinv = Rxinv;
				this->Sampr = Sampr;
				this->Txpo = Txpo;
				this->Rxpo = Rxpo;
				this->Sampa = Sampa;
				this->Form = Form;
				this->Cmode = Cmode;
				this->Cpol = Cpol;
				this->Dord = Dord;
				this->Chsize = Chsize;
				this->Sbmode = Sbmode;
				this->Colden = Colden;
				this->Sfde = Sfde;
				this->Enc = Enc;
				this->Pmode = Pmode;
				this->Txen = Txen;
				this->Rxen = Rxen;
				this->Gtime = Gtime;
				this->Dsnack = Dsnack;
				this->Inack = Inack;
				this->Maxiter = Maxiter;
				this->Baud_rate = Baud_rate;
				this->Fractional = Fractional;
				this->Receive_pulse_length = Receive_pulse_length;
				this->Debug_stop_mode = Debug_stop_mode;
			}
			ConfigUsart(void){}
			~ConfigUsart(void){}
			
			uint8_t Mode;
			uint8_t Runstdby;
			uint8_t Ibon;
			uint8_t Txinv;
			uint8_t Rxinv;
			uint8_t Sampr;
			uint8_t Txpo;
			uint8_t Rxpo;
			uint8_t Sampa;
			uint8_t Form;
			uint8_t Cmode;
			uint8_t Cpol;
			uint8_t Dord;
			uint8_t Chsize;
			uint8_t Sbmode;
			uint8_t Colden;
			uint8_t Sfde;
			uint8_t Enc;
			uint8_t Pmode;
			uint8_t Txen;
			uint8_t Rxen;
			uint8_t Gtime;
			uint8_t Dsnack;
			uint8_t Inack;
			uint8_t Maxiter;
			uint16_t Baud_rate;
			uint8_t Fractional;
			uint8_t Receive_pulse_length;
			uint8_t Debug_stop_mode;
		};
	}
}

#endif /* DRIVERS_SAML10_CONFIG_USART_H_ */