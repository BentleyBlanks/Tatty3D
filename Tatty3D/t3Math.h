#ifndef T3MATH_H
#define T3MATH_H

#include"types.h"
#include<math.h>

namespace Tatty3D
{
	namespace core
	{
		//交换两者内容
		template <class T>
		inline void _swap(T &a, T &b)
		{
			T temp;
			temp=a; a=b; b=temp;
		}

		//返回两者最小值
		template <class T>
		inline T* _min(T &a, T &b)
		{
			return a < b? a, b;
		}

		//返回两者最大值
		template <class T>
		inline T* _max(T &a, T &b)
		{
			return a > b? a, b;
		}

		//快速开根号计算三维长度
		template <class T>
		inline float64 sqrtFast3(T fx, T fy, T fz)
		{
			T x,y,z; // used for algorithm

			// make sure values are all positive
			x = abs(fx) * 1024;
			y = abs(fy) * 1024;
			z = abs(fz) * 1024;

			// sort values
			if (y < x) _swap(x,y);

			if (z < y) _swap(y,z);

			if (y < x) _swap(x,y);

			T dist = (z + 11 * (y >> 5) + (x >> 2) );

			// compute distance with 8% error
			return((T)(dist >> 10));
		}

		//快速开根号计算二维长度
		template <class T>
		inline int32 sqrtFast2(int32 x, int32 y)
		{
			x = abs(x);
			y = abs(y);

			// compute the _minimum of x,y
			int mn = _min(x,y);

			// return the distance
			return(x+y-(mn>>1)-(mn>>2)+(mn>>4));
		}
	}
}


#endif