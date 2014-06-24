#include"WinDevice.h"

#ifdef T3WINDOWS
//消息处理函数本体
LRESULT WINAPI WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(1);
		break;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
#endif

namespace Tatty3D
{
	namespace device
	{
		WinDevice::WinDevice(int32 windowWidth, int32 windowHeight, bool fullScreen, int32 driverType)
		{
			time.init(60.0);

			//窗口即将被创建
			close = false;

			this->driverType = driverType;

			//获得当前进程中exe文件的句柄
			HINSTANCE hInstance = GetModuleHandle(0);
			const TCHAR* ClassName = TEXT("Tatty3D Win32");

			WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0, 0, hInstance,
				NULL, NULL, NULL, NULL, ClassName, NULL };

			RegisterClassEx(&wc);

		    hwnd = CreateWindow(ClassName, TEXT("Tatty3D"),
				WS_OVERLAPPEDWINDOW, 100, 100, windowWidth, windowHeight,
				GetDesktopWindow(), NULL, wc.hInstance, NULL);

			RECT clientSize;
			clientSize.top = 0;
			clientSize.left = 0;
			clientSize.right = windowWidth;
			clientSize.bottom = windowHeight;

			//生成适配驱动
			createDriver();

			//显示窗口
			ShowWindow(hwnd, SW_SHOWDEFAULT);
			UpdateWindow(hwnd);

			const int32 realWidth = clientSize.right - clientSize.left;
			const int32 realHeight = clientSize.bottom - clientSize.top;

			int32 windowLeft = (config::screenWidth - realWidth) / 2;
			int32 windowTop = (config::screenHeight - realHeight) / 2;

			if ( windowLeft < 0 )
				windowLeft = 0;
			if ( windowTop < 0 )
				windowTop = 0;

			MoveWindow(hwnd, windowLeft, windowTop, realWidth, realHeight, TRUE);
		}

		//帧循环
		bool WinDevice::run()
		{
			time.tick();

			//处理系统消息
			handleMessage();

			if(close == true)
				return false;

			return true;
		}

		//获得帧率
		double WinDevice::getFPS()
		{
			return time.getFPS();
		}

		//设置窗口标题
		void WinDevice::setWindowCaption(wchar_t *text)
		{
			// We use SendMessage instead of SetText to ensure proper
			// function even in cases where the HWND was created in a different thread
			DWORD_PTR dwResult;
			SendMessageTimeoutW(hwnd, WM_SETTEXT, 0,
								reinterpret_cast<LPARAM>(text),
								SMTO_ABORTIFHUNG, 2000, &dwResult);

			//SendMessage(hwnd, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(text));
		}

		//创建指定的显示驱动
		void WinDevice::createDriver()
		{
			if(driverType == T3DIRECTX)
			{
				driver = new graphics::DirectXDriver(hwnd);
				//初始化驱动相关
				driver->init();
			}
			else
			{
				//创建OGL对应驱动
				driver = NULL;

				std::cout<<"成功创建OpenGL驱动\nPress ENTER to start"<<std::endl;
				getchar();
				close = true;
			}
		}

		void WinDevice::handleMessage()
		{
			// No message translation because we don't use WM_CHAR and it would conflict with our
			// deadkey handling.
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
					close = true;
			}

			//按下Esc退出
			if((GetAsyncKeyState(VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				close = true;
			}
		}
	}
}