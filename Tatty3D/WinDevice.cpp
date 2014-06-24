#include"WinDevice.h"

#ifdef T3WINDOWS
//��Ϣ����������
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

			//���ڼ���������
			close = false;

			this->driverType = driverType;

			//��õ�ǰ������exe�ļ��ľ��
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

			//������������
			createDriver();

			//��ʾ����
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

		//֡ѭ��
		bool WinDevice::run()
		{
			time.tick();

			//����ϵͳ��Ϣ
			handleMessage();

			if(close == true)
				return false;

			return true;
		}

		//���֡��
		double WinDevice::getFPS()
		{
			return time.getFPS();
		}

		//���ô��ڱ���
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

		//����ָ������ʾ����
		void WinDevice::createDriver()
		{
			if(driverType == T3DIRECTX)
			{
				driver = new graphics::DirectXDriver(hwnd);
				//��ʼ���������
				driver->init();
			}
			else
			{
				//����OGL��Ӧ����
				driver = NULL;

				std::cout<<"�ɹ�����OpenGL����\nPress ENTER to start"<<std::endl;
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

			//����Esc�˳�
			if((GetAsyncKeyState(VK_ESCAPE) & 0x8000) ? 1 : 0)
			{
				close = true;
			}
		}
	}
}