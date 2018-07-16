#include <iostream>
using namespace std;

int main(){
	int arr[3] = {1,2,3};
	int (&ref)[3]=arr;

	ref[0]=5;
	ref[1]=6;
	ref[2]=7;

	cout << arr[0] << arr[1] << arr[2] << endl;

	return 0;
}

