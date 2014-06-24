#include"timer.h"

namespace Tatty3D
{
	timer::timer()
	{
		FPS = 0.0;
		//��֡��СΪ��󸡵��� ������֡
		lockFPS = FLT_MAX;

#ifdef T3WINDOWS
		//�������ܺ���ʼ������
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartCount);
#endif
	}

	//��ʼ��
	void timer::init(float64 lockFPS)
	{
		this->lockFPS = lockFPS;
	}

	//Ĭ�ϲ���֡�ĳ�ʼ��
	void timer::init()
	{
		//��֡��СΪ��󸡵��� ������֡
		lockFPS = FLT_MAX;
	}

	//�δ�
	void timer::tick()
	{
#ifdef T3WINDOWS
		LARGE_INTEGER CurrentCounter;

		//ֻ����ʵ��֡��С�ڵ����Զ���֡��ʱ�Ž�����һ��
		do
		{
			//��ѯ��ǰ�ļ���������
			QueryPerformanceCounter(&CurrentCounter);

			//��֮֡���ʱ���� =(��ǰ������ - ��һ�μ�����) / ����Ƶ��
			double DeltaTime = (double) (CurrentCounter.LowPart - LastCounter.LowPart) / Frequency.LowPart ;

			//����ʵ����ʾ֡��
			FPS = 1.0 / DeltaTime;

		} while(FPS >= lockFPS);

		//��һ֡�ļ����������� 
		LastCounter = CurrentCounter;
#endif
	}

	//��õ�ǰ֡��
	double timer::getFPS()
	{
		return FPS;
	}
}
