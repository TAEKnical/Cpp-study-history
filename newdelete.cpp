/*
#include <iostream>

using namespace std;

int main(){

	int *p =new int; //new�� c���� malloc�� ����. malloc�� ������ ������ �ּڰ��� �����Ѵ�. ���� int*������ p�� ���� ��.
	*p = 10;

	cout << *p << endl;

	delete p;//p�� �Ҵ�� ������ ����.delete�� new�� ���� ������ ������ ��ȯ ����.

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