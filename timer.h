//Program: timer.h
//Author: Mitchell Krystofiak
//Description: Timer class definition.
//Date Created: March 30, 2021

#ifndef TIMER_H
#define TIMER_H

#include<iostream>
#include<time.h>

class Timer 
{
	private:
		//keeps track of starting and ending times
		clock_t start_time;
		clock_t end_time;
	public:
		//constructor
		Timer();
		
		//begin timer
		void start_timer();

		//end timer
		void end_timer();

		//gets time
		double get_time();

		//resets timer
		void reset_timer();

		//print the time
		void print_time();	
};

#endif
