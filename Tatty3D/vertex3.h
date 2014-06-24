#ifndef VERTEX3_H
#define VERTEX3_H

#include"types.h"
#include"vector4.h"
#include"color.h"

namespace Tatty3D
{
	namespace graphics
	{
		class vertex3
		{
		public:
			vertex3(){};

			vertex3(int32 &x, int32 &y, int32 &z, int32 &w, graphics::Color &color);

			vertex3(core::point4f &pos, graphics::Color &color) : position(pos), color(color){}


			core::point4f position;

			//һ���������һ����ɫ��Ϣ��һ��λ����Ϣ
			graphics::Color color;
		};
	}

}

#endif