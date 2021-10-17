//============================================================================
// Name        : BinarySearch(cpp).cpp
// Author      : Sandesh Yadav
// Version     :
// Copyright   : Your copyright notice
// Description : Binary Search algorithm in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int search, int low, int high){
	int mid = ((low + high) / 2);
	if (low > high){
		return -999;
	}
	if (search == arr[mid]){
		return mid;
	}
	else if (search < arr[mid]){
		high = mid - 1;
		return BinarySearch(arr, search, low, high);
	}
	else {
		low = mid + 1;
		return BinarySearch(arr, search, low, high);
	}
}

int main() {
	int num, ent, a;
	cout << "Enter the number of elements in the array:" << endl;
	cin >> num;
	int list[num];
	for (int i = 0; i < num; i++){
		cout << "Enter the element at the " << i << " position:" << endl;
		cin >> ent;
		list[i] = ent;
	}
	cout << "Enter the element you want to search in the array:" << endl;
	cin >> a;
	int res = BinarySearch(list, a, 0, num-1);
	if (res >= 0){
		cout << "The element found at index: " << res;
		cout << " and position: " << res + 1;
	}
	else{
		cout << "Sorry !! The element not found in the array";
	}
}
