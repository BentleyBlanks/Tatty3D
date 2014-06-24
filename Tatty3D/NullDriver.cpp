#include"NullDriver.h"

namespace Tatty3D
{
	namespace graphics
	{
		NullDriver::NullDriver()
		{

		}

		//开始绘制
		void NullDriver::begin()
		{

		}

		//驱动初始化
		bool NullDriver::init()
		{
			return true;
		}

		//结束绘制
		void NullDriver::end()
		{

		}

		//绘制一条2D直线
		void NullDriver::draw2DLine(core::point2f &a, core::point2f &b)
		{
			
		}

		//绘制一条3D/4D直线
		void NullDriver::draw3DLine(core::point4f &a, core::point4f &b)
		{
			std::cout << "HelloWorld";
		}
	}
}