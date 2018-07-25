//int, float 등 기본 자료형을 객체로 사용해야 하는 경우
#include <iostream>

using namespace std;

class Int
{
	int data;
	
public:
	Int(int data) : data(data){}
	Int(const Int& i) : data(i.data) {}
	operator int()
	{
		return data;
	}

};


int main()
{
	Int x = 3;	//Int x = Int(3).operator int(); 와 같음.
	int a = x+4; // 타입 변환 연산자는 operator 타입() 형태로 쓴다.

	x=a*2+x+4;
	cout << x << endl;
}