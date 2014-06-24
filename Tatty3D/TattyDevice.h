#ifndef TATTYDEVICE_H
#define TATTYDEVICE_H

#include"timer.h"
#include"config.h"
#include"TattyDriver.h"
class TattyDriver;

#include"DirectXDriver.h"
class DirectXDriver;

namespace Tatty3D
{
	namespace device
	{
		class TattyDevice
		{
		public:
			TattyDevice();
			//提供窗口大小 颜色位数 是否全屏 驱动类型

			//帧循环
			virtual bool run()=0;

			//获得一个当前设备的显示驱动
			graphics::TattyDriver* getGraphicDriver();

			//获得一个文件系统管理器

			//获得帧率
			virtual double getFPS()=0;

			//设置窗口标题
			virtual void setWindowCaption(wchar_t *text)=0;

			//获得场景管理器

		protected:
			//运行时钟
			timer time;
			//显示适配驱动
			graphics::TattyDriver *driver;

			//显示驱动类型 
			//在除Windows平台上存在DirectX与OpenGL双选以外 其余都由OpenGL渲染
			int32 driverType;
		};
	}

}

#endif