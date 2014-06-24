#include"vertex3.h"

namespace Tatty3D
{
	namespace graphics
	{
		vertex3::vertex3(int32 &x, int32 &y, int32 &z, int32 &w, graphics::Color &color)
		{
			core::point4f *point = new core::point4f(x, y, z, w);

			position = *point;

			this->color = color;
		}
	}
}
