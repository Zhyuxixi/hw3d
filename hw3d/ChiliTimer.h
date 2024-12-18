#pragma once
#include <chrono> //ʱ���

class ChiliTimer
{
public:
	ChiliTimer() noexcept;
	float Mark() noexcept;			//ʱ����
	float Peek() const noexcept;		//ʱ���ۻ�
private:
	std::chrono::steady_clock::time_point last;
};