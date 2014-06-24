#include"NullDriver.h"

namespace Tatty3D
{
	namespace graphics
	{
		NullDriver::NullDriver()
		{

		}

		//��ʼ����
		void NullDriver::begin()
		{

		}

		//������ʼ��
		bool NullDriver::init()
		{
			return true;
		}

		//��������
		void NullDriver::end()
		{

		}

		//����һ��2Dֱ��
		void NullDriver::draw2DLine(core::point2f &a, core::point2f &b)
		{
			
		}

		//����һ��3D/4Dֱ��
		void NullDriver::draw3DLine(core::point4f &a, core::point4f &b)
		{
			std::cout << "HelloWorld";
		}
	}
}