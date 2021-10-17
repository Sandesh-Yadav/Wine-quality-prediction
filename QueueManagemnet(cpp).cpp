//============================================================================
// Name        : QueueManagemnet(cpp).cpp
// Author      : Sandesh Yadav
// Version     :
// Copyright   : Your copyright notice
// Description : Queue Management in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q1, q2, q3;
	q1.add(1); q1.add(2); q1.add(3); q1.add(4); q1.add(5);
	q2.add(6); q2.add(7); q2.add(8); q2.add(9); q2.add(10);
	q1.printQueue();
	q2.printQueue();
	/*q3 = q1 + q2;
	q3.printQueue();*/
	q2.remove();
	q2.printQueue();
	return 0;
}
