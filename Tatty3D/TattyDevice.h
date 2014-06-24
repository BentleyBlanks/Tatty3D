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
			//�ṩ���ڴ�С ��ɫλ�� �Ƿ�ȫ�� ��������

			//֡ѭ��
			virtual bool run()=0;

			//���һ����ǰ�豸����ʾ����
			graphics::TattyDriver* getGraphicDriver();

			//���һ���ļ�ϵͳ������

			//���֡��
			virtual double getFPS()=0;

			//���ô��ڱ���
			virtual void setWindowCaption(wchar_t *text)=0;

			//��ó���������

		protected:
			//����ʱ��
			timer time;
			//��ʾ��������
			graphics::TattyDriver *driver;

			//��ʾ�������� 
			//�ڳ�Windowsƽ̨�ϴ���DirectX��OpenGL˫ѡ���� ���඼��OpenGL��Ⱦ
			int32 driverType;
		};
	}

}

#endif