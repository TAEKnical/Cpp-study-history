//int, float �� �⺻ �ڷ����� ��ü�� ����ؾ� �ϴ� ���
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
	Int x = 3;	//Int x = Int(3).operator int(); �� ����.
	int a = x+4; // Ÿ�� ��ȯ �����ڴ� operator Ÿ��() ���·� ����.

	x=a*2+x+4;
	cout << x << endl;
}