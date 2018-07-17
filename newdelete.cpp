/*
#include <iostream>

using namespace std;

int main(){

	int *p =new int; //new는 c에서 malloc과 같다. malloc은 생성한 공간의 주솟값을 리턴한다. 따라서 int*형으로 p를 만든 것.
	*p = 10;

	cout << *p << endl;

	delete p;//p에 할당된 공간이 해제.delete는 new에 의해 생성된 공간만 반환 가능.

	return 0;
}*/

#include <iostream>

using namespace std;

int main(){
	int arr_size;

	cout << "array size :";
	cin>> arr_size;

	int *list = new int[arr_size];
	
	for(int i=0; i< arr_size; i++){
		cin>>list[i];
	}

	for(int i=0; i<arr_size;i++){
		cout<<i<<"the element of list : " << list[i] << endl;
	}
	delete [] list;

	return 0;
}