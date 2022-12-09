#include "DTVApp.h"
#include "TBDraw.h"
#include "Melon.h"
#include "Pyramid.h"
#include "Box.h"
#include "Sheet.h"
#include <memory>
#include <algorithm>
#include "ChiliMath.h"

DTVApp::DTVApp()
	:
	wnd(800, 600, "The DTV App")
{
	TBDraw draw(wnd.Gfx());
	DTVDraw = std::make_unique<TBDraw>(wnd.Gfx());

	wnd.Gfx().SetProjection(DirectX::XMMatrixPerspectiveLH(1.0f, 3.0f / 4.0f, 0.5f, 40.0f));
}

void DTVApp::DoFrame()
{
	wnd.Gfx().ClearBuffer(0.1f, 0.1f, 0.1f);
	DTVDraw->Draw(wnd.Gfx());
	wnd.Gfx().EndFrame();
}

DTVApp::~DTVApp()
{}


int DTVApp::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}