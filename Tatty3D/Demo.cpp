#define	_CRT_SECURE_NO_WARNINGS
#include"Tatty3D.h"
#include<iostream>

using namespace std;
using namespace Tatty3D;

int main()
{
	device::TattyDevice *device = device::create(800, 600);
	graphics::TattyDriver *driver = device->getGraphicDriver();

	char *fps;
	fps = (char*) malloc(10 * sizeof(char));

	wchar_t *wfps;
	wfps = (wchar_t*) malloc(10 * sizeof(wchar_t));

	int frame = 0;

	while(device->run())
	{
		double FPS = device->getFPS();
		cout<< FPS <<endl;
		//sprintf(fps, "FPS: %f", FPS);

		//size_t len = strlen(fps) + 1;
		//size_t converted = 0;

		//mbstowcs_s(&converted, wfps, len, fps, _TRUNCATE);

		driver->begin();
		driver->draw3DLine(core::point4f(10, 10, 10), core::point4f(100, 100, 100));
		driver->draw2DLine(core::point2f(10, 20), core::point2f(300, 400));
		driver->end();

		//if(++frame == 1000)
		//{
		//	device->setWindowCaption(wfps);
		//	frame = 0;
		//}
	}
}