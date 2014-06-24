#ifndef T3COLOR_H
#define T3COLOR_H

#include"types.h"

namespace Tatty3D
{
	namespace graphics
	{
		class Color
		{
		public:
			Color()
			{
				color = 0;
			}

			//由一个数字带来32位色
			Color(lint32 clr) :color(clr)
			{
			}

			//指定颜色分量
			Color(lint32 r, lint32 g, lint32 b, lint32 a = 1)
				: color(((a & 0xff) << 24) | ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff))
			{
			}

			//返回颜色分量值
			lint32 getAlpha() const
			{
				return color >> 24;
			}

			lint32 getRed() const
			{
				return (color >> 16) & 0xff;
			}

			lint32 getGreen() const
			{
				return (color >> 8) & 0xff;
			}

			lint32 getBlue() const
			{
				return color & 0xff;
			}

			//指定颜色分量值
			void setAlpha(lint32 a)
			{
				color = ((a & 0xff) << 24) | (color & 0x00ffffff);
			}

			void setRed(lint32 r)
			{
				color = ((r & 0xff) << 16) | (color & 0xff00ffff);
			}

			void setGreen(lint32 g)
			{
				color = ((g & 0xff) << 8) | (color & 0xffff00ff);
			}

			void setBlue(lint32 b)
			{
				color = (b & 0xff) | (color & 0xffffff00);
			}

			lint32 color;
		};
	}
}

#endif