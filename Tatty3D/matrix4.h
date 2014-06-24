#ifndef MATRIX4_H
#define MATRIX4_H

#include"types.h"

//��ѧ����Ҫ��֤Ч�� ���������������
namespace Tatty3D
{
	namespace core
	{
		//��ģ��
		template <class T>
		class matrix4
		{
		public:
			matrix4();
			//���ƹ��캯��
			matrix4(const matrix4<T>& a);

			//����ǰ����λ��
			inline void identify();
			//����ǰ������0
			inline void zero();
			//��ʼ��
			inline void init(T m00, T m01, T m02, T m03, 
				T m10, T m11, T m12, T m13,
				T m20, T m21, T m22, T m23,
				T m30, T m31, T m32, T m33);

			//���㵱ǰ���������ʽ
			inline void det() const;

			//���ʾ����ڲ�Ԫ��
			T& operator[](int32 index)
			{
				return M[index];
			}
			const T& operator[](int32 index) const
			{
				return M[index];
			}
			//����һ���������
			//β��const��֤��ǰ����ĳ�Ա������ֵ�����ı�
			matrix4<T> operator+(const matrix4<T> &other) const;

			//����һ���������
			matrix4<T> operator-(const matrix4<T> &other) const;

			//����һ��4X4�������
			matrix4<T> operator*(const matrix4<T> &other) const;

			//���� * ����
			matrix4<T> operator*(const T& scalar) const; 

			//���� * ����
			//friend matrix4<T> operator*(const T& scalar, const matrix4<T> &me);

		private:
				//ʵ�ʴ洢λ��
				T M[16];
		};

		template <class T>
		matrix4<T>::matrix4()
		{
			//Ĭ�ϳ�ʼ������Ϊ��λ����
			identify();
		}

		template <class T>
		matrix4<T>::matrix4(const matrix4<T> &other)
		{
			*this = other;
		}

		template <class T>
		inline void matrix4<T>::zero()
		{
			//��M��ά�����ڵ�ǰ16*sizeof(T)�ֽ�������Ϊ0
			memset(M, 0, 16*sizeof(T));
		}

		template <class T>
		inline void matrix4<T>::identify()
		{
			//��M��ά�����ڵ�ǰ16*sizeof(T)�ֽ�������Ϊ0
			memset(M, 0, 16*sizeof(T));
			//��λ���Խ���1
			M[0] = M[5] = M[10] = M[15] = 1;
		}


		template <class T>
		inline void matrix4<T>::init(T m00, T m01, T m02, T m03, 
			T m10, T m11, T m12, T m13,
			T m20, T m21, T m22, T m23,
			T m30, T m31, T m32, T m33)
		{
			M[0] = m00;	M[1] = m00; M[2] = m02; M[3] = m03; 
			M[4] = m00; M[5] = m11; M[6] = m12; M[7] = m13;
			M[8] = m00; M[9] = m21; M[10] = m22; M[11] = m23;
			M[12] = m00; M[13] = m31; M[14] = m32; M[15] = m33;
		}

		//�����
		template <class T>
		inline matrix4<T> matrix4<T>::operator+(const matrix4<T> &other) const
		{
			matrix4<T> temp;

			temp[0] = M[0]+other[0];
			temp[1] = M[1]+other[1];
			temp[2] = M[2]+other[2];
			temp[3] = M[3]+other[3];
			temp[4] = M[4]+other[4];
			temp[5] = M[5]+other[5];
			temp[6] = M[6]+other[6];
			temp[7] = M[7]+other[7];
			temp[8] = M[8]+other[8];
			temp[9] = M[9]+other[9];
			temp[10] = M[10]+other[10];
			temp[11] = M[11]+other[11];
			temp[12] = M[12]+other[12];
			temp[13] = M[13]+other[13];
			temp[14] = M[14]+other[14];
			temp[15] = M[15]+other[15];

			return temp;
		}

		template <class T>
		inline matrix4<T> matrix4<T>::operator-(const matrix4<T> &other) const
		{
			matrix4<T> temp;

			temp[0] = M[0]-other[0];
			temp[1] = M[1]-other[1];
			temp[2] = M[2]-other[2];
			temp[3] = M[3]-other[3];
			temp[4] = M[4]-other[4];
			temp[5] = M[5]-other[5];
			temp[6] = M[6]-other[6];
			temp[7] = M[7]-other[7];
			temp[8] = M[8]-other[8];
			temp[9] = M[9]-other[9];
			temp[10] = M[10]-other[10];
			temp[11] = M[11]-other[11];
			temp[12] = M[12]-other[12];
			temp[13] = M[13]-other[13];
			temp[14] = M[14]-other[14];
			temp[15] = M[15]-other[15];

			return temp;
		}

		//���� * ����
		template <class S, class T>
		inline matrix4<T> operator*(const S& scalar, const matrix4<T>& me) 
		{
			return me*scalar;
		}

		//���� * ����
		template <class T>
		inline matrix4<T> matrix4<T>::operator*(const T& scalar) const
		{
			matrix4<T> temp;

			temp[0] = M[0]*scalar;
			temp[1] = M[1]*scalar;
			temp[2] = M[2]*scalar;
			temp[3] = M[3]*scalar;
			temp[4] = M[4]*scalar;
			temp[5] = M[5]*scalar;
			temp[6] = M[6]*scalar;
			temp[7] = M[7]*scalar;
			temp[8] = M[8]*scalar;
			temp[9] = M[9]*scalar;
			temp[10] = M[10]*scalar;
			temp[11] = M[11]*scalar;
			temp[12] = M[12]*scalar;
			temp[13] = M[13]*scalar;
			temp[14] = M[14]*scalar;
			temp[15] = M[15]*scalar;

			return temp;
		}

		//4X4���� * 4X4����
		template <class T>
		inline matrix4<T> matrix4<T>::operator*(const matrix4<T> &other) const
		{

			matrix4<T> m3;
			const T *m1 = M;

			m3[0] = m1[0]*other[0] + m1[4]*other[1] + m1[8]*other[2] + m1[12]*other[3];
			m3[1] = m1[1]*other[0] + m1[5]*other[1] + m1[9]*other[2] + m1[13]*other[3];
			m3[2] = m1[2]*other[0] + m1[6]*other[1] + m1[10]*other[2] + m1[14]*other[3];
			m3[3] = m1[3]*other[0] + m1[7]*other[1] + m1[11]*other[2] + m1[15]*other[3];

			m3[4] = m1[0]*other[4] + m1[4]*other[5] + m1[8]*other[6] + m1[12]*other[7];
			m3[5] = m1[1]*other[4] + m1[5]*other[5] + m1[9]*other[6] + m1[13]*other[7];
			m3[6] = m1[2]*other[4] + m1[6]*other[5] + m1[10]*other[6] + m1[14]*other[7];
			m3[7] = m1[3]*other[4] + m1[7]*other[5] + m1[11]*other[6] + m1[15]*other[7];

			m3[8] = m1[0]*other[8] + m1[4]*other[9] + m1[8]*other[10] + m1[12]*other[11];
			m3[9] = m1[1]*other[8] + m1[5]*other[9] + m1[9]*other[10] + m1[13]*other[11];
			m3[10] = m1[2]*other[8] + m1[6]*other[9] + m1[10]*other[10] + m1[14]*other[11];
			m3[11] = m1[3]*other[8] + m1[7]*other[9] + m1[11]*other[10] + m1[15]*other[11];

			m3[12] = m1[0]*other[12] + m1[4]*other[13] + m1[8]*other[14] + m1[12]*other[15];
			m3[13] = m1[1]*other[12] + m1[5]*other[13] + m1[9]*other[14] + m1[13]*other[15];
			m3[14] = m1[2]*other[12] + m1[6]*other[13] + m1[10]*other[14] + m1[14]*other[15];
			m3[15] = m1[3]*other[12] + m1[7]*other[13] + m1[11]*other[14] + m1[15]*other[15];

			return m3;
		}

		//����д
		typedef matrix4<int32> matrix4i; 
		typedef matrix4<float64> matrix4f; 
	}
}

#endif