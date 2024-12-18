#include "Window.h"
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static WindowsMessageMap mm;
//	//OutputDebugString(mm(msg, lParam, wParam).c_str());
//	switch (msg)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(69);	//��ϵͳָʾ�߳��ѷ�����ֹ (�˳�) ������
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
//	case WM_CHAR:	//WM_CHAR��Ϣ��TranslateMessage(&msg)��������
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
#include <sstream>
#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	try
	{
		return App{}.Go();
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