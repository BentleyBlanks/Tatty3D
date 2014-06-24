#include"TattyDevice.h"

namespace Tatty3D
{
	namespace device
	{
		TattyDevice::TattyDevice()
		{
			//默认使用OpenGL渲染绘制以方便跨平台
			driverType = T3OPENGL;
			time.init();
		}

		////帧循环
		//bool TattyDevice::run()
		//{
		//	//滴答计时
		//	time.tick();

		//	return true;
		//}

		//获得一个当前设备的显示驱动
		graphics::TattyDriver* TattyDevice::getGraphicDriver()
		{
			return driver;
		}

		//获得一个文件系统管理器

		////获得帧率
		//double TattyDevice::getFPS()
		//{
		//	return time.getFPS();
		//}
	}

}