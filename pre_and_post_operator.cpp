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
		cout<<"저전위 증감 연산자"<<endl;
		return *this;
	}
	prepost& operator ++(int x)
	{

		x++;
		cout<<"후위 증감 연산자"<<endl;
		return *this;
	}
}
int main()
{
	prepost x(3);
	x++;
	++x;
}
