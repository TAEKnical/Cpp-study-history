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
//  �׷����� �ι�° ������ '����' ��� ���� �����׿�. �½��ϴ�.
//���۷�����, � �ٸ� ������ '����', �� '�ٸ� �̸�' �̶� �ǹ̸� ������ �ֽ��ϴ�.
//�׷��� ���� C++ ���� ���۷����� ������ ��� ������.
//�� ��� p �� number ������ '�ٸ� �̸�' �� �Ǵ� ���Դϴ�.
//���� p = 3; �̶� ����� number = 3; �� ��Ȯ�� ��ġ�ϴ� ����� �ǰ�����. 
//�������� ���� �߿��� Ư������ �ݵ�� ���� �� �ʱ�ȭ �Ǿ�� �Ѵ� �Դϴ�.

//����� �����ڸ� ���۷����� �� �� �ʱ�ȭ �Ǹ� �ٸ� ������ ������ �� �� �����ϴ�. ���� ��

    //int a = 10;
	//int &ref = a;
	//int b = 3;
	//ref = b;

 
//�� �ϸ� ref = b; ���� ref �� b �� ����Ű�� ���� �ƴ϶�, a = b; , �� a �� 3 �� ���ԵǴ� ���Դϴ�.

