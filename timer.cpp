//Program: timer.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the timer class (for sake of simplicity/ avoiding repetition).
//Date: March 30, 2021

#include<iostream>
#include<iomanip>
#include"timer.h"
#include<time.h>

Timer::Timer()
{
	start_time = 0;
	end_time = 0;
}

void Timer::start_timer()
{
	start_time = clock();
}

void Timer::end_timer()
{
	end_time = clock();
}

double Timer::get_time()
{
	double elapsed_time = (double(end_time - start_time) / (CLOCKS_PER_SEC));
	return elapsed_time;
}

void Timer::reset_timer()
{
	start_time = 0;
	end_time = 0;
}

void Timer::print_time()
{
	std::cout << "Elapsed time: " << std::setprecision(3) << get_time() << "s" << std::endl;
}
