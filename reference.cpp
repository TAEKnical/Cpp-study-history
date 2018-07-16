/*#include <iostream>

using namespace std;

void change_val(int *p)
{
	*p=3;
}

int main(){
	int number=5;

	cout<<number<<endl;
	change_val(&number);
	cout<<number<<endl;
}*/

#include <iostream>
using namespace std;

void change_value(int &p){
	p=3;
}

int main (void){
	
	int number=5;

	cout << number << endl;
	change_value(number);
	cout << number << endl;

	return 0;
}
//  그랬더니 두번째 뜻으로 '참고' 라는 말이 나오네요. 맞습니다.
//레퍼런스란, 어떤 다른 변수의 '참고', 즉 '다른 이름' 이란 의미를 가지고 있습니다.
//그래서 흔히 C++ 에서 레퍼런스를 참조자 라고도 하지요.
//위 경우 p 가 number 변수의 '다른 이름' 이 되는 것입니다.
//따라서 p = 3; 이란 명령은 number = 3; 과 정확히 일치하는 명령이 되겠지요. 
//참조자의 가장 중요한 특성으로 반드시 정의 시 초기화 되어야 한다 입니다.

//참고로 말하자면 레퍼런스는 한 번 초기화 되면 다른 변수의 별명이 될 수 없습니다. 예를 들어서

    //int a = 10;
	//int &ref = a;
	//int b = 3;
	//ref = b;

 
//를 하면 ref = b; 에서 ref 가 b 를 가리키는 것이 아니라, a = b; , 즉 a 에 3 이 대입되는 것입니다.

