#ifndef DRIVERS_SAML10_MSG_USART_H_
#define DRIVERS_SAML10_MSG_USART_H_

namespace Drivers{
	namespace SAML10{
		class MsgUsart{
		public:
			static const uint16_t MAX_SIZE = 256;
			static volatile uint8_t data[MAX_SIZE];
			static volatile uint16_t wIndex;
			static volatile uint16_t rIndex;
			static volatile uint8_t busy;
			
			MsgUsart(void){}
			MsgUsart(uint8_t* buffer, uint16_t length){
				if(buffer != nullptr && !busy){
					for (int i = 0 ; i < length ; ++i) {
						busy = true;
						data[wIndex++] = buffer[i];
						wIndex %= MAX_SIZE;
					}
				}
			}
			~MsgUsart(void){}
			
			static uint8_t Next(uint8_t* next){
				if(next != nullptr && rIndex != wIndex){
					*next = data[rIndex++];
					rIndex %= MAX_SIZE;
					if(isEmpty()) { 
						busy = false; 
					}
					return true;
				}
				return false;
			}
			
			static uint8_t isEmpty(void) { return wIndex == rIndex; }
			static uint8_t isBusy(void)  { return busy; }
		};
	}
}

#endif /* DRIVERS_SAML10_MSG_USART_H_ */