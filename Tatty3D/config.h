#ifndef CONFIG_H
#define CONFIG_H

#include"types.h"

namespace Tatty3D
{
	namespace config
	{
		//��Ļ��� �߶�
		static int32 screenWidth = 0, screenHeight = 0;

		//��굱ǰλ�� �� ���ԭ��λ��
		static int32 mouseX = 0, mouseY = 0, 
			pmouseX = 0, pmouseY = 0;

		//���ڿ��
		static int32 windowWidth = 0, windowHeight = 0;

		//�Ƿ�ȫ��
		static bool fullScreen = false;
	}
}

//Windowsƽ̨��֧��
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define T3WINDOWS
#endif


//Macƽ̨��֧��
#if defined(__APPLE__) && defined(__MACH__) || defined(MACOSX)
#if !defined(MACOSX)
#define MACOSX
#endif
#define T3OSX
#endif


//Linuxƽ̨��֧��
#if defined(__linux__) || defined(linux) || defined(__linux)
#define T3LINUX
#endif

//��ʾ��������
#define T3DIRECTX 1
#define T3OPENGL 2

#endif