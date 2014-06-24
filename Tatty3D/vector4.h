#ifndef VECTOR4_H
#define VECTOR4_H

#include"t3Math.h"

namespace Tatty3D
{
	namespace core
	{

		template <class T>
		class vector4
		{
		public:
			vector4();
			//Ĭ���������Ϊ1
			vector4(T x, T y, T z, T w = 1.0);
			//�������캯��
			vector4(const vector4<T> &other);

			//ת��Ϊ�������
			inline void devideW();
			//�ÿ�
			inline void zero();
			//��������3D���� Ĭ��Ϊ����˫���ȵĳ���
			inline double length() const;
			//ʹ�ÿ��ټ�����������
			inline double lengthFast() const;
			//������λ��
			inline void normalize();
			//�������������������
			vector4<T>& cross(const vector4<T>& v) const;

			//�����
			vector4<T> operator+(const vector4<T>& ohter) const ; 

			vector4<T> operator-(const vector4<T>& ohter) const;
			
			//�������
			T operator*(const vector4<T>& ohter) const;

			//���� * ����
			vector4<T> operator*(const T& scalar) const;

			//���� * ����

			//4D�������
			T x;
			T y;
			T z;
			T w;
		};

		template <class T>
		vector4<T>::vector4()
		{
			this->x = 1.0;
			this->y = 1.0;
			this->z = 1.0;
			this->w = 1.0;
		}

		template <class T>
		vector4<T>::vector4(T x, T y, T z, T w = 1.0)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		template <class T>
		vector4<T>::vector4(const vector4<T> &other)
		{
			*this = other;
		}

		//ת��Ϊ�������
		template <class T>
		inline void vector4<T>::devideW()
		{
			x /= w;
			y /= w;
			z /= w;
			w = 1.0;
		}

		//�ÿ�
		template <class T>
		inline void vector4<T>::zero()
		{
			x = y = z = 0.0;
			w = 1.0;
		}

		//��������3D���� Ĭ��Ϊ����˫���ȵĳ���
		template <class T>
		inline double vector4<T>::length() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		//ʹ�ÿ��ټ�����������
		template <class T>
		inline double vector4<T>::lengthFast() const
		{
			return sqrtFast3(x, y, z);
		}

		//������λ��
		template <class T>
		inline void vector4<T>::normalize()
		{
			//���㵱ǰ��������
			double length = sqrt(x*x + y*y + z*z);

			//����������Ϊ0
			if(length == 0)
				return;

			double lengthInv = 1/length;

			x *= lengthInv;
			y *= lengthInv;
			z *= lengthInv;
			w = 1.0;
		}

		//�������������������
		template <class T> 
		vector4<T>& vector4<T>::cross(const vector4<T>& v) const
		{
			//|i j k|
			//|a b c|
			//|x y z|
			return vector4<T>(v.y*z - v.z*y, v.z*x - v.x*z, v.x*y - v.y*x);
		}

		//�����
		template <class T> 
		vector4<T> vector4<T>::operator+(const vector4<T>& ohter) const
		{
			return vector4<T>(ohter.x+x, ohter.y+y, ohter.z+z, 1.0);
		}

		template <class T> 
		vector4<T> vector4<T>::operator-(const vector4<T>& ohter) const
		{
			return vector4<T>(ohter.x-x, ohter.y-y, ohter.z-z, 1.0);
		}

		//�������
		template <class T> 
		T vector4<T>::operator*(const vector4<T>& ohter) const
		{
			return (ohter.x*x + ohter.y*y + ohter.z*z);
		}

		//���� * ����
		template <class T> 
		vector4<T> vector4<T>::operator*(const T& scalar) const
		{
			return vector4<T>(scalar*x, scalar*y, scalar*z);
		}

		//���� * ����
		template <class S, class T>
		inline vector4<T> operator*(const S& scalar, const vector4<T>& v)
		{
			return v*scalar;
		}


		//����д
		typedef vector4<int32> point4i; 
		typedef vector4<int32> vector4i; 

		typedef vector4<float32> point4f; 
		typedef vector4<float32> vector4f; 
	}
}

#endif