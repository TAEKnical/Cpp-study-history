#include <iostream>

using namespace std;

void print_square(int arg){
	cout<<"���� : "<< arg*arg << endl;
}

int main(){

	int i;
	cout << "������ ��" << endl;
	cin>>i;

	print_square(i);

return 0;
}