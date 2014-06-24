#ifndef LINUXDEVICE_H
#define LINUXDEVICE_H

#include"config.h"
#include"TattyDevice.h"

class TattyDevice;

namespace Tatty3D
{
	namespace device
	{
		class LinuxDevice: public TattyDevice
		{
		public:
			LinuxDevice();
		};
	}
}
#endif