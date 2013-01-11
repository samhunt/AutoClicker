#pragma once
#include "Click.h"
#include <list>


// Looks after the listening for clicks when recording, clicking when the user wants to replay the clicks,
// finding out smooth lines between two click points, checking whether the user has paused or not.
// and being able to stop the clicker.
class ListenToClicks
{
public:

	// Creates a singleton instance of ListenToClicks, therefore allowing ListenToClicks to
	// be called in multiple locations and only have to be initialized once.
	//
	// This makes sure that every method in Form1 gets the same variables for ListenToClicks.
	static ListenToClicks& instance();
	// Prints out click_list_ on stdout so that you see what the list looks.
	void PrintList();
	// Checks to see if the user has pushed F11, or F12 while the clicker is running.
	// If F11 is pushed it pauses,
	// if F12 is pushed it stops the clicker.
	void CheckForPause();
	// Called when record_button is clicked,
	// Records every click except for the one to click record_button again.
	void ListenClicks();
	// works out the line between every click so that you can see a visual
	// representation of where the mouse is going to go.
	void LineBresenham(int, int, int, int);
	// Draws the line worked out in LineBresenham
	void DrawLines();
	// Smoothly moves the mouse between 2 points (in a straight line)
	// that straight line is worked out in LineBresenham.
	void SmoothMove(Click);
	// Does the auto clicking. as long as the user doesn't pause the clicker.
	void AutoClick();

	// Return and set the private variables.
	bool clicked_record();
	void set_clicked_record(bool);
	double time();
	void set_time(double);
	int offset();
	void set_offset(int);
	bool clicked_start();
	void set_clicked_start(bool);
	bool paused();
	void set_paused(bool);
	int click_list_size();
	void click_list_clear();
	void click_list_pop_back();


private:
	// Private constructor
	// So that only the singleton can call it.
	ListenToClicks(){
		clicked_record_ = false;
		time_ = 1.000;
		offset_ = 0;
		clicked_start_ = false;
		paused_ = false;
	}
	ListenToClicks(ListenToClicks const&);
	void operator=(ListenToClicks const&);

	// private variables
	bool clicked_record_;
	double time_;
	int offset_;
	bool clicked_start_;
	bool paused_;
	std::list<Click> click_list_;
	std::list<Click>::iterator it;
	std::list<Click>::iterator it2;
};

