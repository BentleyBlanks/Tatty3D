#ifndef VECTOR2_H
#define VECTOR2_H

#include"t3Math.h"

namespace Tatty3D
{
	namespace core
	{
		template <class T>
		class vector2
		{
		public:
			vector2();
			//Ĭ���������Ϊ1
			vector2(T x, T y);
			//�������캯��
			vector2(const vector2<T> &other);

			//�ÿ�
			inline void zero();
			//��������3D���� Ĭ��Ϊ����˫���ȵĳ���
			inline double length() const;
			//ʹ�ÿ��ټ�����������
			inline double lengthFast() const;
			//������λ��
			inline void normalize();
			//2D���������������Ϊ���㵱ǰƽ���ı������
			T& cross(const vector2<T>& v) const;

			//�����
			vector2<T> operator+(const vector2<T>& other) const ; 

			vector2<T> operator-(const vector2<T>& other) const;

			//�������
			T operator*(const vector2<T>& other) const;

			//���� * ����
			vector2<T> operator*(const T& scalar) const;

			//���� * ����

			T x;
			T y;
		};


		template <class T>
		vector2<T>::vector2()
		{
			x = 0.0;
			y = 0.0;
		}

		template <class T>
		vector2<T>::vector2(T x, T y)
		{
			this->x = x;
			this->y = y;
		}

		template <class T>
		vector2<T>::vector2(const vector2<T> &other)
		{
			*this = other;
		}

		//�ÿ�
		template <class T>
		inline void vector2<T>::zero()
		{
			x = 0.0;
			y = 0.0;
		}

		//��������3D���� Ĭ��Ϊ����˫���ȵĳ���
		template <class T>
		inline double vector2<T>::length() const
		{
			return sqrt(x*x + y*y);
		}

		//ʹ�ÿ��ټ�����������
		template <class T>
		inline double vector2<T>::lengthFast() const
		{
			return sqrtFast2(x, y);
		}

		//������λ��
		template <class T>
		inline void vector2<T>::normalize()
		{
			double length = sqrt(x*x + y*y);

			if(length == 0)
				return;

			double lengthInv = 1/length;

			x *= lengthInv;
			y *= lengthInv;
		}

		//2D���������������Ϊ���㵱ǰƽ���ı������
		template <class T>
		T& vector2<T>::cross(const vector2<T>& v) const
		{
			return (x*v.y - v.x*y);
		}

		//�����
		template <class T>
		vector2<T> vector2<T>::operator+(const vector2<T>& other) const
		{
			return vector2<T>(other.x+x, other.y+y);
		}

		template <class T>
		vector2<T> vector2<T>::operator-(const vector2<T>& other) const
		{
			return vector2<T>(other.x-x, other.y-y);
		}

		//�������
		template <class T>
		T vector2<T>::operator*(const vector2<T>& other) const
		{
			return (other.x*x + other.y*y);
		}

		//���� * ����
		template <class T>
		vector2<T> vector2<T>::operator*(const T& scalar) const
		{
			return vector2<T>(x*scalar, y*scalar);
		}

		//���� * ����
		template <class S, class T>
		inline vector2<T> operator*(const S& scalar, const vector2<T> &v)
		{
			return v*scalar;
		}

		//����д
		typedef vector2<int32> point2i; 
		typedef vector2<int32> vector2i; 

		typedef vector2<float64> point2f; 
		typedef vector2<float64> vector2f; 
	}
}

#endif