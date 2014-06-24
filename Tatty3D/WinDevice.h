#ifndef WINDEVICE_H
#define WINDEVICE_H

#include"config.h"
#include"TattyDevice.h"

#ifdef T3WINDOWS
#include<Windows.h>
#endif

class TattyDevice;

namespace Tatty3D
{
	namespace device
	{
		class WinDevice: public TattyDevice
		{
		public:
			//提供窗口大小 颜色位数 是否全屏 驱动类型
			WinDevice(int32 windowWidth, int32 windowHeight, bool fullScreen = false, int32 driverType = T3DIRECTX);

			//帧循环
			virtual bool run();

			//获得帧率
			virtual double getFPS();

			//处理基本消息
			void handleMessage();

			//设置窗口标题
			virtual void setWindowCaption(wchar_t *text);

			//获得场景管理器
		private:
			//创建指定的显示驱动
			void createDriver();

			//窗口尺寸
			int32 windowWidth;
			int32 windowHeight;

			//运行时钟
			timer time;
			//窗口句柄
			HWND hwnd;
			//是否全屏
			bool fullScreen;
			//窗口是否即将被关闭
			bool close;

			MSG msg;
		};
	}
}
#endif