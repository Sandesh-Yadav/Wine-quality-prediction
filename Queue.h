/*
 * Queue.h
 *
 *  Created on: 13-Jan-2021
 *      Author: Sandesh Yadav
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	Queue();
	int *queue;
	int size;

	void add(int a);

	void remove();

	void printQueue();

	Queue operator+(Queue &obj);
};

#endif /* QUEUE_H_ */
