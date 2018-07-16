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

	//cout<<fn1(x)++<<endl;//오류발생 -> 함수는 int형인데 리턴값은 reference임.
	//cout<<x<<endl;

	cout<<fn2(x)++<<endl;
	cout<<x<<endl;

	return 0;
}

