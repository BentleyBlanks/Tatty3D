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
			//�ṩ���ڴ�С ��ɫλ�� �Ƿ�ȫ�� ��������
			WinDevice(int32 windowWidth, int32 windowHeight, bool fullScreen = false, int32 driverType = T3DIRECTX);

			//֡ѭ��
			virtual bool run();

			//���֡��
			virtual double getFPS();

			//���������Ϣ
			void handleMessage();

			//���ô��ڱ���
			virtual void setWindowCaption(wchar_t *text);

			//��ó���������
		private:
			//����ָ������ʾ����
			void createDriver();

			//���ڳߴ�
			int32 windowWidth;
			int32 windowHeight;

			//����ʱ��
			timer time;
			//���ھ��
			HWND hwnd;
			//�Ƿ�ȫ��
			bool fullScreen;
			//�����Ƿ񼴽����ر�
			bool close;

			MSG msg;
		};
	}
}
#endif