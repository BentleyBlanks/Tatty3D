#ifndef TATTYDRIVER_H
#define TATTYDRIVER_H

#include"vector2.h"
#include"vector4.h"

namespace Tatty3D
{
	namespace graphics
	{
		class TattyDriver
		{
		public:
			//TattyDriver();

			//驱动初始化 返回值判断是否创建成功
			virtual bool init()=0;

			//开始绘制
			virtual void begin()=0;

			//结束绘制
			virtual void end()=0;

			//绘制一条2D直线
			virtual void draw2DLine(core::point2f &a, core::point2f &b) = 0;

			//绘制一条3D/4D直线
			virtual void draw3DLine(core::point4f &a, core::point4f &b)=0;
		};
	}
}

#endif