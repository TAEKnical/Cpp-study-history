#include <iostream>
using namespace std;
class prepost
{
	int x;
public:
	prepost(int x) : x(x){}
	prepost& operator ++()
	{
		x++;
		cout<<"������ ���� ������"<<endl;
		return *this;
	}
	prepost& operator ++(int x)
	{

		x++;
		cout<<"���� ���� ������"<<endl;
		return *this;
	}
}
int main()
{
	prepost x(3);
	x++;
	++x;
}
