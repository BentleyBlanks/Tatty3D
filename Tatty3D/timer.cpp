#include"timer.h"

namespace Tatty3D
{
	timer::timer()
	{
		FPS = 0.0;
		//锁帧大小为最大浮点数 即不锁帧
		lockFPS = FLT_MAX;

#ifdef T3WINDOWS
		//计算性能和起始计数器
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartCount);
#endif
	}

	//初始化
	void timer::init(float64 lockFPS)
	{
		this->lockFPS = lockFPS;
	}

	//默认不锁帧的初始化
	void timer::init()
	{
		//锁帧大小为最大浮点数 即不锁帧
		lockFPS = FLT_MAX;
	}

	//滴答
	void timer::tick()
	{
#ifdef T3WINDOWS
		LARGE_INTEGER CurrentCounter;

		//只有在实际帧数小于等于自定义帧数时才进行下一步
		do
		{
			//查询当前的计数器次数
			QueryPerformanceCounter(&CurrentCounter);

			//两帧之间的时间间隔 =(当前计数器 - 上一次计数器) / 运算频率
			double DeltaTime = (double) (CurrentCounter.LowPart - LastCounter.LowPart) / Frequency.LowPart ;

			//计算实际显示帧率
			FPS = 1.0 / DeltaTime;

		} while(FPS >= lockFPS);

		//上一帧的计数次数保存 
		LastCounter = CurrentCounter;
#endif
	}

	//获得当前帧率
	double timer::getFPS()
	{
		return FPS;
	}
}
