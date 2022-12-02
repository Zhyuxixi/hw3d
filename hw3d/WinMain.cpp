#include "Window.h"
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static WindowsMessageMap mm;
//	//OutputDebugString(mm(msg, lParam, wParam).c_str());
//	switch (msg)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(69);	//向系统指示线程已发出终止 (退出) 的请求
//		break;
//	case WM_KEYDOWN:
//		if (wParam == 'F')
//		{
//			SetWindowText(hWnd, "Respects");
//			OutputDebugString(mm(msg, lParam, wParam).c_str());
//		}
//		break;
//	case WM_KEYUP:
//		if (wParam == 'F')
//		{
//			SetWindowText(hWnd, "Hello World");
//			OutputDebugString(mm(msg, lParam, wParam).c_str());
//		}
//		break;
//	case WM_CHAR:	//WM_CHAR消息由TranslateMessage(&msg)函数生成
//	{
//		static std::string title;
//		title.push_back((char)wParam);
//		SetWindowText(hWnd, title.c_str());
//	}
//		break;
//	case WM_LBUTTONDOWN:
//	{
//		POINTS pt = MAKEPOINTS(lParam);
//		std::ostringstream oss;
//		oss << "(" << pt.x << "," << pt.y << ")";
//		SetWindowText(hWnd, oss.str().c_str());
//
//	}
//		break;
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}


#include "Window.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	try
	{
		Window wnd(720, 540, "My Littel QingBao");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.kbd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "Something Happon!", "Space Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
			}
		}

		// check if GetMessage call itself borked
		if (gResult == -1)
		{
			throw CHWND_LAST_EXCEPT();
		}

		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch (const ChiliException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}