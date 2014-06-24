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
	//���������� ���ݽṹ ���󶼿����������ҵ�����
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
		//����һ�����������ƽ̨���豸
		static TattyDevice* create(int32 windowWidth, int32 windowHeight, bool fullScreen = false)
		{
			int32 driverType;

			const char* const names[] = {"1.DirectX", "2.OpenGL"};
			std::cout<<"��ѡ��һ����Ҫ����������:\n";

			for(int32 i=0; i<2; i++)
			{
				std::cout<<names[i]<<std::endl;
			}

			int32 c;
			std::cin >> c;

			//���ݲ�ͬѡ����в�ͬ������Ⱦ
			if(c == 1)
				driverType = T3DIRECTX;
			else if(c == 2)
				driverType = T3OPENGL;

			TattyDevice* device;

			if(windowHeight == 0)
				windowHeight = 640;
			if(windowWidth == 0)
				windowWidth = 960;

			//������������
			config::fullScreen = fullScreen;

			//��ʼ���豸���ò���
			config::windowWidth = windowWidth;
			config::windowHeight = windowHeight;

			//��׳���ж�
			if(config::windowWidth <= 0)
				config::windowWidth = 0;
			if(config::windowHeight <= 0)
				config::windowHeight = 0;

			config::fullScreen = fullScreen;

			config::screenWidth = GetSystemMetrics(SM_CXSCREEN);
			config::screenHeight = GetSystemMetrics(SM_CYSCREEN);

			//�������� ʵ������ͬѡ����豸����
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