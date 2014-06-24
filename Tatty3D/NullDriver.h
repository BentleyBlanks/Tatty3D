#ifndef NULLDRIVER_H
#define NULLDRIVER_H
#include<iostream>
#include"vector2.h"
#include"vector4.h"

#include"config.h"
#include"TattyDriver.h"
class TattyDriver;

//#ifdef T3WINDOWS
////ʹ��GDI������������Ļ���
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

			//������ʼ��
			virtual bool init();

			//��ʼ����
			virtual void begin();

			//��������
			virtual void end();

			//����һ��2Dֱ��
			virtual void draw2DLine(core::point2f &a, core::point2f &b);

			//����һ��3D/4Dֱ��
			virtual void draw3DLine(core::point4f &a, core::point4f &b);
		};
	}
}

#endif