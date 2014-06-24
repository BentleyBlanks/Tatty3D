#ifndef TATTY3D_H
#define TATTY3D_H

#include<iostream>

#include"config.h"
#include"matrix4.h"
#include"vector4.h"
#include"vector2.h"
#include"timer.h"
#include"TattyDevice.h"
#include"TattyDriver.h"


#ifdef T3WINDOWS
#include"WinDevice.h"
#include"DirectXDriver.h"
#endif

#ifdef T3LINUX
#include"LinuxDevice.h"
#endif

#ifdef T3OSX
#include"OSXDevice.h"
#endif

namespace Tatty3D
{
	//基本的向量 数据结构 矩阵都可以在这里找到定义
	namespace core
	{

	}

	namespace graphics
	{

	}

	namespace config
	{

	}

	namespace device
	{
		//创建一个适配与操作平台的设备
		static TattyDevice* create(int32 windowWidth, int32 windowHeight, bool fullScreen = false)
		{
			int32 driverType;

			const char* const names[] = {"1.DirectX", "2.OpenGL"};
			std::cout<<"请选择一你想要的驱动类型:\n";

			for(int32 i=0; i<2; i++)
			{
				std::cout<<names[i]<<std::endl;
			}

			int32 c;
			std::cin >> c;

			//根据不同选项进行不同驱动渲染
			if(c == 1)
				driverType = T3DIRECTX;
			else if(c == 2)
				driverType = T3OPENGL;

			TattyDevice* device;

			if(windowHeight == 0)
				windowHeight = 640;
			if(windowWidth == 0)
				windowWidth = 960;

			//更新引擎配置
			config::fullScreen = fullScreen;

			//初始化设备配置参数
			config::windowWidth = windowWidth;
			config::windowHeight = windowHeight;

			//健壮性判断
			if(config::windowWidth <= 0)
				config::windowWidth = 0;
			if(config::windowHeight <= 0)
				config::windowHeight = 0;

			config::fullScreen = fullScreen;

			config::screenWidth = GetSystemMetrics(SM_CXSCREEN);
			config::screenHeight = GetSystemMetrics(SM_CYSCREEN);

			//条件编译 实例化不同选择的设备类型
#ifdef T3WINDOWS
			device = new WinDevice(windowWidth, windowHeight, fullScreen, driverType);
#endif

#ifdef T3LINUX
			device = new LinuxDevice();
#endif

#ifdef T3OSX
			device = new OSXDevice();
#endif
			return device;
		}
	}
}


#endif