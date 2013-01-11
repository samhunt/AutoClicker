#include "StdAfx.h"
#include "ListenToClicks.h"

using namespace std;

ListenToClicks& ListenToClicks::instance()
{
	static ListenToClicks instance;
	return instance;
}

void ListenToClicks::PrintList(){
	if(click_list_.empty()){
		cout << "There are no entries." << endl;
	}else{
		cout << "List is as follows:" << endl;
		for ( it=click_list_.begin() ; it != click_list_.end(); it++ ){
			if(it->getChar() == 'l')
				cout << "\tLeft Click at: ("<< it->getPoint().x << ", " << it->getPoint().y << ")" << endl;
			else
				cout << "\tRight Click at: ("<< it->getPoint().x << ", " << it->getPoint().y << ")" << endl;
		}
	}
}

void ListenToClicks::CheckForPause(){
	paused_ = false;
	while(clicked_start_ || paused_){
		Sleep(50);
		if((GetKeyState(VK_F12) & 0x80) != 0){
			while((GetKeyState(VK_F12) & 0x80) != 0){
				// the button is currently pressed down.
			}
			paused_ = true;
			clicked_start_ = false;
			cout << "STOPPING." << endl;
		}
		if((GetKeyState(VK_F11) & 0x80) != 0){
			while((GetKeyState(VK_F11) & 0x80) != 0){
				// the button is currently pressed down.
			}
			if(!paused_){
				paused_ = true;
				cout << "paused." << endl;
			}else{
				paused_ = false;
				cout << "unpaused." << endl;
			}
		}
	}
	_endthread();
}

void ListenToClicks::ListenClicks(){
	POINT pt;
	Click c;
	while(clicked_record_){
		Sleep(50);
		if((GetKeyState(VK_LBUTTON) & 0x80) != 0){
			while((GetKeyState(VK_LBUTTON) & 0x80) != 0){
				// the button is currently pressed down.
			}
			GetCursorPos(&pt);
			c = Click(pt, 'l');
			click_list_.push_back(c);
			cout << "Left Button Pressed: (" <<  pt.x << ", " << pt.y << ")" << endl;
			//mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0,0,0,0);
		}
		if((GetKeyState(VK_RBUTTON) & 0x80) != 0){
			while((GetKeyState(VK_RBUTTON) & 0x80) != 0){
				// the button is currently pressed down.
			}
			GetCursorPos(&pt);
			c = Click(pt, 'r');
			click_list_.push_back(c);
			cout << "Right Button Pressed: (" <<  pt.x << ", " << pt.y << ")" << endl;
			//mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0,0,0,0);
		}
	}
	//free(&pt);
	_endthread();
}

void ListenToClicks::LineBresenham(int p1x, int p1y, int p2x, int p2y)
{

	HDC panel = GetDC(HWND_TOP);
	COLORREF black = RGB(255,0,0);
	int F, x, y;

	if (p1x > p2x)  // Swap points if p1 is on the right of p2
	{
		swap(p1x, p2x);
		swap(p1y, p2y);
	}

	// Handle trivial cases separately for algorithm speed up.
	// Trivial case 1: m = +/-INF (Vertical line)
	if (p1x == p2x)
	{
		if (p1y > p2y)  // Swap y-coordinates if p1 is above p2
		{
			swap(p1y, p2y);
		}

		x = p1x;
		y = p1y;
		while (y <= p2y)
		{
			SetPixel(panel, x, y, black);
			//setPixel(x, y);
			y++;
		}
		return;
	}
	// Trivial case 2: m = 0 (Horizontal line)
	else if (p1y == p2y)
	{
		x = p1x;
		y = p1y;

		while (x <= p2x)
		{
			//setPixel(x, y);
			SetPixel(panel, x, y, black);
			x++;
		}
		return;
	}


	int dy            = p2y - p1y;  // y-increment from p1 to p2
	int dx            = p2x - p1x;  // x-increment from p1 to p2
	int dy2           = (dy << 1);  // dy << 1 == 2*dy
	int dx2           = (dx << 1);
	int dy2_minus_dx2 = dy2 - dx2;  // precompute constant for speed up
	int dy2_plus_dx2  = dy2 + dx2;


	if (dy >= 0)    // m >= 0
	{
		// Case 1: 0 <= m <= 1 (Original case)
		if (dy <= dx)   
		{
			F = dy2 - dx;    // initial F

			x = p1x;
			y = p1y;
			while (x <= p2x)
			{
				//setPixel(x, y);
				SetPixel(panel, x, y, black);
				if (F <= 0)
				{
					F += dy2;
				}
				else
				{
					y++;
					F += dy2_minus_dx2;
				}
				x++;
			}
		}
		// Case 2: 1 < m < INF (Mirror about y=x line
		// replace all dy by dx and dx by dy)
		else
		{
			F = dx2 - dy;    // initial F

			y = p1y;
			x = p1x;
			while (y <= p2y)
			{
				//setPixel(x, y);
				SetPixel(panel, x, y, black);
				if (F <= 0)
				{
					F += dx2;
				}
				else
				{
					x++;
					F -= dy2_minus_dx2;
				}
				y++;
			}
		}
	}
	else    // m < 0
	{
		// Case 3: -1 <= m < 0 (Mirror about x-axis, replace all dy by -dy)
		if (dx >= -dy)
		{
			F = -dy2 - dx;    // initial F

			x = p1x;
			y = p1y;
			while (x <= p2x)
			{
				//setPixel(x, y);
				SetPixel(panel, x, y, black);
				if (F <= 0)
				{
					F -= dy2;
				}
				else
				{
					y--;
					F -= dy2_plus_dx2;
				}
				x++;
			}
		}
		// Case 4: -INF < m < -1 (Mirror about x-axis and mirror 
		// about y=x line, replace all dx by -dy and dy by dx)
		else    
		{
			F = dx2 + dy;    // initial F

			y = p1y;
			x = p1x;
			while (y >= p2y)
			{
				//setPixel(x, y);
				SetPixel(panel, x, y, black);
				if (F <= 0)
				{
					F += dx2;
				}
				else
				{
					x++;
					F += dy2_plus_dx2;
				}
				y--;
			}
		}
	}
}

void ListenToClicks::DrawLines(){
	POINT prev = click_list_.front().getPoint();
	POINT curr;
	if(click_list_.size() > 1){
		for ( it2=click_list_.begin() ; it2 != click_list_.end(); it2++ ){
			//if(it != ListenToClicks::click_list_.begin()){
			POINT curr = it2->getPoint();
			LineBresenham(prev.x, prev.y, curr.x, curr.y);
			//}
			prev = it2->getPoint();
		}
		curr = click_list_.front().getPoint();
		prev = click_list_.back().getPoint();
		LineBresenham(prev.x, prev.y, curr.x, curr.y);
	}
}

void ListenToClicks::SmoothMove(Click cl){
	//srand(time_(NULL));
	int rand_time_ = rand() % 101;
	int total_time_ = (int)(time_*1000)+rand_time_;
	int wait_time_ = 10;
	int start_x, start_y, finish_x, finish_y, diff_x, diff_y, i;
	double move_x, move_y;
	int moveto_x, moveto_y,total_clicks;
	POINT pt;
	int rand_x,rand_y;
	if(offset_ > 0){
		rand_x = rand()%(offset_*2) - offset_;
		rand_y = rand()%(offset_*2) - offset_;
	}else{
		rand_x = rand_y = 0;
	}

	total_clicks = total_time_/wait_time_;
	GetCursorPos(&pt);
	start_x = pt.x;
	start_y = pt.y;
	finish_x = cl.getPoint().x+rand_x;
	finish_y = cl.getPoint().y+rand_y;
	diff_x = finish_x - start_x;
	diff_y = finish_y - start_y;


	move_x = (double)diff_x/(double)total_clicks;
	move_y = (double)diff_y/(double)total_clicks;

	moveto_x = start_x + (int)((total_clicks)*move_x);
	moveto_y = start_y + (int)((total_clicks)*move_y);
	cout << "Moving to: (" << finish_x << ", " << finish_y << "), (" << moveto_x << ", " << moveto_y << ")" << endl;
	for(i = 1; i <= (total_clicks+1); i++){
		Sleep(wait_time_);
		SetCursorPos(start_x + (int)(i*move_x), start_y + (int)(i*move_y));
	}
	SetCursorPos(finish_x, finish_y);
	Sleep(10);
}

void ListenToClicks::AutoClick(){
	while(clicked_start_){
		DrawLines();
		//Click c;
		for ( it=click_list_.begin() ; it != click_list_.end(); it++ ){
			//c = *it;
			DrawLines();
			while(paused_){
				if(!clicked_start_){
					paused_ = false;
					_endthread();
				}
				cout << "paused_" << endl;
				Sleep(500);
			}
			SmoothMove(*it);

			if(it->getChar() == 'l'){
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0,0,0,0);
			}else if(it->getChar() == 'r'){
				mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0,0,0,0);
			}
			//SetCursorPos(it->getPoint().x,it->getPoint().y);
			DrawLines();
		}
	}
	_endthread();
}

bool ListenToClicks::clicked_record()
{
	return this->clicked_record_;
}

void ListenToClicks::set_clicked_record(bool clicked_record)
{
	this->clicked_record_ = clicked_record;
}

double ListenToClicks::time()
{
	return this->time_;
}

void ListenToClicks::set_time(double time)
{
	this->time_ = time;
}

int ListenToClicks::offset(){
	return this->offset_;
}

void ListenToClicks::set_offset(int offset)
{
	this->offset_ = offset;
}

bool ListenToClicks::clicked_start()
{
	return this->clicked_start_;
}

void ListenToClicks::set_clicked_start(bool clicked_start)
{
	this->clicked_start_ = clicked_start;
}

bool ListenToClicks::paused()
{
	return this->paused_;
}

void ListenToClicks::set_paused(bool paused)
{
	this->paused_ = paused;
}

int ListenToClicks::click_list_size()
{
	return this->click_list_.size();
}

void ListenToClicks::click_list_clear()
{
	click_list_.clear();
}

void ListenToClicks::click_list_pop_back()
{
	click_list_.pop_back();
}