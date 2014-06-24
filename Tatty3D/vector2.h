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
			//默认齐次向量为1
			vector2(T x, T y);
			//拷贝构造函数
			vector2(const vector2<T> &other);

			//置空
			inline void zero();
			//返回向量3D长度 默认为返回双精度的长度
			inline double length() const;
			//使用快速计算向量长度
			inline double lengthFast() const;
			//向量单位化
			inline void normalize();
			//2D向量叉积几何意义为计算当前平行四边形面积
			T& cross(const vector2<T>& v) const;

			//运算符
			vector2<T> operator+(const vector2<T>& other) const ; 

			vector2<T> operator-(const vector2<T>& other) const;

			//向量点积
			T operator*(const vector2<T>& other) const;

			//向量 * 标量
			vector2<T> operator*(const T& scalar) const;

			//标量 * 矩阵

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

		//置空
		template <class T>
		inline void vector2<T>::zero()
		{
			x = 0.0;
			y = 0.0;
		}

		//返回向量3D长度 默认为返回双精度的长度
		template <class T>
		inline double vector2<T>::length() const
		{
			return sqrt(x*x + y*y);
		}

		//使用快速计算向量长度
		template <class T>
		inline double vector2<T>::lengthFast() const
		{
			return sqrtFast2(x, y);
		}

		//向量单位化
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

		//2D向量叉积几何意义为计算当前平行四边形面积
		template <class T>
		T& vector2<T>::cross(const vector2<T>& v) const
		{
			return (x*v.y - v.x*y);
		}

		//运算符
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

		//向量点积
		template <class T>
		T vector2<T>::operator*(const vector2<T>& other) const
		{
			return (other.x*x + other.y*y);
		}

		//向量 * 标量
		template <class T>
		vector2<T> vector2<T>::operator*(const T& scalar) const
		{
			return vector2<T>(x*scalar, y*scalar);
		}

		//标量 * 向量
		template <class S, class T>
		inline vector2<T> operator*(const S& scalar, const vector2<T> &v)
		{
			return v*scalar;
		}

		//简化书写
		typedef vector2<int32> point2i; 
		typedef vector2<int32> vector2i; 

		typedef vector2<float64> point2f; 
		typedef vector2<float64> vector2f; 
	}
}

#endif