/*
 * Queue.cpp
 *
 *  Created on: 13-Jan-2021
 *      Author: Sandesh Yadav
 */

#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	queue = new int[100];
	size = 0;
}
void Queue::add(int a) {
	queue[size] = a;
	size++;
}
void Queue::remove(){
	if(size == 0){
		cout << "The queue is empty" << endl;
		return;
	}
	else{
		for(int i = 0; i < size - 1; i++){
			queue[i] = queue[i + 1];
		}
		size--;
	}
}
void Queue::printQueue(){
	if(size == 0){
		cout << "The queue is empty" << endl;
		return;
	}
	else{
		for(int i = 0; i < size; i++){
			cout << queue[i] << " ";
		}
		cout << endl;
		return;
	}
}
Queue Queue::operator +(Queue &obj){
	Queue res;
	res.size = size + obj.size;
	res.queue = new int[res.size];
	for(int i; i < size; ++i){
		res.queue[i] = queue[i];
	}
	for(int i = 0; i < obj.size; ++i){
		res.queue[size + i] = obj.queue[i];
	}
	return res;
}


