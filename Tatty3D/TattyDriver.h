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

			//������ʼ�� ����ֵ�ж��Ƿ񴴽��ɹ�
			virtual bool init()=0;

			//��ʼ����
			virtual void begin()=0;

			//��������
			virtual void end()=0;

			//����һ��2Dֱ��
			virtual void draw2DLine(core::point2f &a, core::point2f &b) = 0;

			//����һ��3D/4Dֱ��
			virtual void draw3DLine(core::point4f &a, core::point4f &b)=0;
		};
	}
}

#endif