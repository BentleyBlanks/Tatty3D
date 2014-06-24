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
		//��ʼ��
		void init(float64 lockFPS);
		//Ĭ�ϲ���֡�ĳ�ʼ��
		void init();
		//�δ�
		void tick();
		//��õ�ǰ֡��
		double getFPS();

	private:
		double FPS;
		double lockFPS;
#ifdef T3WINDOWS
		//����������
		LARGE_INTEGER Frequency;
		//�տ�ʼ(����һ��ʼ/ĳ��ѭ���е�һ��ʼ)�ļ�������
		LARGE_INTEGER StartCount;
		//��һ֡��������
		LARGE_INTEGER LastCounter;
#endif
	};
}

#endif