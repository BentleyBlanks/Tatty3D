#ifndef TIMER_H
#define TIMER_H

#include"types.h"
#include"config.h"
#ifdef T3WINDOWS
#include<Windows.h>
#endif

#include<float.h>

namespace Tatty3D
{
	class timer
	{
	public:
		timer();
		//初始化
		void init(float64 lockFPS);
		//默认不锁帧的初始化
		void init();
		//滴答
		void tick();
		//获得当前帧率
		double getFPS();

	private:
		double FPS;
		double lockFPS;
#ifdef T3WINDOWS
		//性能运算数
		LARGE_INTEGER Frequency;
		//刚开始(程序一开始/某个循环中的一开始)的计数次数
		LARGE_INTEGER StartCount;
		//上一帧计数次数
		LARGE_INTEGER LastCounter;
#endif
	};
}

#endif