#ifndef NULLDRIVER_H
#define NULLDRIVER_H
#include<iostream>
#include"vector2.h"
#include"vector4.h"

#include"config.h"
#include"TattyDriver.h"
class TattyDriver;

//#ifdef T3WINDOWS
////使用GDI来完成无驱动的绘制
//#include<Windows.h>
//#endif

namespace Tatty3D
{
	namespace graphics
	{
		class NullDriver:public TattyDriver
		{
		public:

			NullDriver();

			//驱动初始化
			virtual bool init();

			//开始绘制
			virtual void begin();

			//结束绘制
			virtual void end();

			//绘制一条2D直线
			virtual void draw2DLine(core::point2f &a, core::point2f &b);

			//绘制一条3D/4D直线
			virtual void draw3DLine(core::point4f &a, core::point4f &b);
		};
	}
}

#endif