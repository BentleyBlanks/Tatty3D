#include"TattyDevice.h"

namespace Tatty3D
{
	namespace device
	{
		TattyDevice::TattyDevice()
		{
			//Ĭ��ʹ��OpenGL��Ⱦ�����Է����ƽ̨
			driverType = T3OPENGL;
			time.init();
		}

		////֡ѭ��
		//bool TattyDevice::run()
		//{
		//	//�δ��ʱ
		//	time.tick();

		//	return true;
		//}

		//���һ����ǰ�豸����ʾ����
		graphics::TattyDriver* TattyDevice::getGraphicDriver()
		{
			return driver;
		}

		//���һ���ļ�ϵͳ������

		////���֡��
		//double TattyDevice::getFPS()
		//{
		//	return time.getFPS();
		//}
	}

}