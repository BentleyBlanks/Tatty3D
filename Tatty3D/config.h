#ifndef CONFIG_H
#define CONFIG_H

#include"types.h"

namespace Tatty3D
{
	namespace config
	{
		//屏幕宽度 高度
		static int32 screenWidth = 0, screenHeight = 0;

		//鼠标当前位置 和 鼠标原先位置
		static int32 mouseX = 0, mouseY = 0, 
			pmouseX = 0, pmouseY = 0;

		//窗口宽高
		static int32 windowWidth = 0, windowHeight = 0;

		//是否全屏
		static bool fullScreen = false;
	}
}

//Windows平台的支持
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define T3WINDOWS
#endif


//Mac平台的支持
#if defined(__APPLE__) && defined(__MACH__) || defined(MACOSX)
#if !defined(MACOSX)
#define MACOSX
#endif
#define T3OSX
#endif


//Linux平台的支持
#if defined(__linux__) || defined(linux) || defined(__linux)
#define T3LINUX
#endif

//显示驱动类型
#define T3DIRECTX 1
#define T3OPENGL 2

#endif