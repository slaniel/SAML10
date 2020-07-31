#ifndef DRIVERS_SAML10_UUID_H_
#define DRIVERS_SAML10_UUID_H_

#include "sam.h"

namespace Drivers{
	namespace SAML10{
		class RegUuid{
		public:
			static bool Read(uint32_t* buffer){
				if(buffer != nullptr){
					buffer[0] = *((uint32_t*)(0x0080A00C));
					buffer[1] = *((uint32_t*)(0x0080A040));
					buffer[2] = *((uint32_t*)(0x0080A044));
					buffer[3] = *((uint32_t*)(0x0080A048));
					return true;
				}
				return false;
			}
		};
	}
}

#endif /* DRIVERS_SAML10_UUID_H_ */