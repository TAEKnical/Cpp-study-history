#include <iostream>

using namespace std;

int fn1(int &a){
	return a;
}

int& fn2(int &a){
	return a;
}

int main(void){
	int x = 0;

	//cout<<fn1(x)++<<endl;//�����߻� -> �Լ��� int���ε� ���ϰ��� reference��.
	//cout<<x<<endl;

	cout<<fn2(x)++<<endl;
	cout<<x<<endl;

	return 0;
}

