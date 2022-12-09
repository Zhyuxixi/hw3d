#pragma once
#include "Window.h"
#include "ChiliTimer.h"
#include "TBDraw.h"

class DTVApp
{
public:
	DTVApp();
	// master frame / message loop
	int Go();
	~DTVApp();
private:
	void DoFrame();
private:
	Window wnd;
	ChiliTimer timer;
	std::unique_ptr<TBDraw> DTVDraw;
	std::vector<std::unique_ptr<class Drawable>> drawables;
};