#ifndef DIRECTXDRIVER_H
#define DIRECTXDRIVER_H

#include<iostream>

#include"types.h"
#include"color.h"
#include"matrix4.h"
#include"vertex3.h"
#include"config.h"
#include"vector2.h"
#include"vector4.h"
#include"NullDriver.h"
class NullDriver;

#ifdef T3WINDOWS

#include<d3d9.h>
#pragma comment(lib , "d3d9.lib")
#pragma comment(lib , "d3dx9.lib")

namespace Tatty3D
{
	namespace graphics
	{
		class DirectXDriver:public NullDriver
		{
		public:
			DirectXDriver(HWND hwnd);

			//D3D是否初始化创建成功
			virtual bool init();

			//开始绘制
			virtual void begin();

			//结束绘制
			virtual void end();

			//绘制一条2D直线
			virtual void draw2DLine(core::point2f &a, core::point2f &b);

			//绘制一条3D/4D直线
			virtual void draw3DLine(core::point4f &a, core::point4f &b);

		private:
			//D3D针对的更新绘制窗口
			HWND hwnd;
			HRESULT hr;

			LPDIRECT3D9 g_D3D;
			LPDIRECT3DDEVICE9 g_D3DDevice;
			LPDIRECT3DVERTEXBUFFER9 g_VertexBuffer;

			IDirect3DTexture9*        g_pRenderTexture = NULL;
			IDirect3DSurface9*        g_pRenderSurface = NULL;

		};
	}
}

#endif

#endif