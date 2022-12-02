#pragma once
#include <chrono> //时间库

class ChiliTimer
{
public:
	ChiliTimer() noexcept;
	float Mark() noexcept;			//时间间隔
	float Peek() const noexcept;		//时间累积
private:
	std::chrono::steady_clock::time_point last;
};