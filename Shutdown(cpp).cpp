//============================================================================
// Name        : Shutdown(cpp).cpp
// Author      : Sandesh Yadav
// Version     :
// Copyright   : Your copyright notice
// Description : Shutdown and Restart in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int choice, in, shut;
	cout << "1.Shutdown your computer" << endl;
	cout << "2.Restart your computer" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch(choice){
	case 1:
		cout << "You system will shutdown in 20 seconds" << endl;
		system("c:\\windows\\system32\\shutdown /s /t 20 \n\n");
		break;
	case 2:
		cout << "You system will restart in 20 seconds" << endl;
		system("c:\\windows\\system32\\shutdown /r /t 20 \n\n");
		break;
	default:
		cout << "Wrong choice..!!" << endl;

	}
	return 0;
}
