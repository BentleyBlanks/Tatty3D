#include"DirectXDriver.h"

namespace Tatty3D
{

#ifdef T3WINDOWS

	struct stD3DVertex
	{
		float64 x, y, z, rhw;
		unsigned long color;
	};


#define D3DFVF_VERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

	namespace graphics
	{
		DirectXDriver::DirectXDriver(HWND hwnd)
		{
			this->hwnd = hwnd;

			g_D3D = NULL;
			g_D3DDevice = NULL;
			g_VertexBuffer = NULL;

			std::cout<<"成功创建DirectX驱动\n Press ENTER to start"<<std::endl;
			getchar();

		}

		//驱动初始化
		bool DirectXDriver::init()
		{
			D3DDISPLAYMODE displayMode;

			//Create the D3D object
			g_D3D = Direct3DCreate9(D3D_SDK_VERSION);
			if (g_D3D == NULL)
				return false;

			//Get the desktop display mode
			if (FAILED(g_D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode)))
				return false;

			//set up the structure used to create the D3DDevice
			D3DPRESENT_PARAMETERS d3dpp;
			ZeroMemory(&d3dpp, sizeof(d3dpp));

			if (config::fullScreen)
			{
				d3dpp.Windowed = FALSE;
				d3dpp.BackBufferWidth = 640;
				d3dpp.BackBufferHeight = 480;
			}
			else
			{
				d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
				d3dpp.Windowed = TRUE;
			}

				
			d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			d3dpp.BackBufferFormat = displayMode.Format;

			//Create the D3DDevice
			if (FAILED(g_D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING,
				&d3dpp, &g_D3DDevice)))
				return false;

			return true;
		}


		//开始绘制
		void DirectXDriver::begin()
		{
			//Clear the backbuffer
			g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

			//Begin the scene , Start rendering
			g_D3DDevice->BeginScene();

			//g_D3DDevice->DrawPrimitive(D3DPT_LINELIST, 0, 2);
		}

		//结束绘制
		void DirectXDriver::end()
		{
			//End the scene , Stop rendering
			g_D3DDevice->EndScene();

			//Display the scene
			g_D3DDevice->Present(NULL, NULL, NULL, NULL);
		}

		//绘制一条2D直线
		void DirectXDriver::draw2DLine(core::point2f &a, core::point2f &b)
		{
			Color col(255, 255, 255);

			core::point4f start(a.x, a.y, 0.0, 1.0), end(b.x, b.y, 0.0, 1.0);

			vertex3 v[2];
			v[0].color = col;
			v[1].color = col;
			v[0].position = start;
			v[1].position = end;

			////create the vertex buffer
			if(FAILED(g_D3DDevice->CreateVertexBuffer(sizeof(v), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &g_VertexBuffer, NULL)))
				return;

			g_D3DDevice->SetFVF(D3DFVF_VERTEX);
			g_D3DDevice->SetStreamSource(0, g_VertexBuffer, 0, sizeof(vertex3));
			g_D3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 2, v, sizeof(vertex3));

			g_VertexBuffer->Release();
		}

		//绘制一条3D/4D直线
		void DirectXDriver::draw3DLine(core::point4f &a, core::point4f &b)
		{				
			graphics::Color col(255, 255, 255);

			graphics::vertex3 v[2];
			v[0].color = col;
			v[1].color = col;
			v[0].position = a;
			v[1].position = b;

			////create the vertex buffer
			if(FAILED(g_D3DDevice->CreateVertexBuffer(sizeof(v), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &g_VertexBuffer, NULL)))
				return;

			g_D3DDevice->SetFVF(D3DFVF_VERTEX);
			g_D3DDevice->SetStreamSource(0, g_VertexBuffer, 0, sizeof(vertex3));
			g_D3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 2, v, sizeof(vertex3));

			g_VertexBuffer->Release();
		}
	}
}

#endif