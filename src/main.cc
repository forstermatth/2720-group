
#include "Scheduler.h"
#include <iostream>
using namespace std;

int main(){
	Scheduler _scheduler;

	string userinput;

	cout << "XML Input (filename including .xml): ";
	cin >> userinput;

	_scheduler.grab(userinput);
	_scheduler.work();
	_scheduler.print();
	
}