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
			//默认齐次向量为1
			vector4(T x, T y, T z, T w = 1.0);
			//拷贝构造函数
			vector4(const vector4<T> &other);

			//转化为齐次向量
			inline void devideW();
			//置空
			inline void zero();
			//返回向量3D长度 默认为返回双精度的长度
			inline double length() const;
			//使用快速计算向量长度
			inline double lengthFast() const;
			//向量单位化
			inline void normalize();
			//计算两向量叉积并返回
			vector4<T>& cross(const vector4<T>& v) const;

			//运算符
			vector4<T> operator+(const vector4<T>& ohter) const ; 

			vector4<T> operator-(const vector4<T>& ohter) const;
			
			//向量点积
			T operator*(const vector4<T>& ohter) const;

			//向量 * 标量
			vector4<T> operator*(const T& scalar) const;

			//标量 * 矩阵

			//4D齐次向量
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

		//转化为齐次向量
		template <class T>
		inline void vector4<T>::devideW()
		{
			x /= w;
			y /= w;
			z /= w;
			w = 1.0;
		}

		//置空
		template <class T>
		inline void vector4<T>::zero()
		{
			x = y = z = 0.0;
			w = 1.0;
		}

		//返回向量3D长度 默认为返回双精度的长度
		template <class T>
		inline double vector4<T>::length() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		//使用快速计算向量长度
		template <class T>
		inline double vector4<T>::lengthFast() const
		{
			return sqrtFast3(x, y, z);
		}

		//向量单位化
		template <class T>
		inline void vector4<T>::normalize()
		{
			//计算当前向量长度
			double length = sqrt(x*x + y*y + z*z);

			//被除数不能为0
			if(length == 0)
				return;

			double lengthInv = 1/length;

			x *= lengthInv;
			y *= lengthInv;
			z *= lengthInv;
			w = 1.0;
		}

		//计算两向量叉积并返回
		template <class T> 
		vector4<T>& vector4<T>::cross(const vector4<T>& v) const
		{
			//|i j k|
			//|a b c|
			//|x y z|
			return vector4<T>(v.y*z - v.z*y, v.z*x - v.x*z, v.x*y - v.y*x);
		}

		//运算符
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

		//向量点积
		template <class T> 
		T vector4<T>::operator*(const vector4<T>& ohter) const
		{
			return (ohter.x*x + ohter.y*y + ohter.z*z);
		}

		//向量 * 标量
		template <class T> 
		vector4<T> vector4<T>::operator*(const T& scalar) const
		{
			return vector4<T>(scalar*x, scalar*y, scalar*z);
		}

		//标量 * 矩阵
		template <class S, class T>
		inline vector4<T> operator*(const S& scalar, const vector4<T>& v)
		{
			return v*scalar;
		}


		//简化书写
		typedef vector4<int32> point4i; 
		typedef vector4<int32> vector4i; 

		typedef vector4<float32> point4f; 
		typedef vector4<float32> vector4f; 
	}
}

#endif