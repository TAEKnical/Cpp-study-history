#include <iostream>

using namespace std;
int main(){
	int user_input;
	cout << "Print my information" <<endl;
	cout<<"1.name"<<endl;
	cout<<"2.age"<<endl;
	cout<<"3.sex"<<endl;
	cin>>user_input;

	switch(user_input){
	case 1:
		cout<<"LJT!"<<endl;
		break;
	case 2:
		cout<<"230 year old"<<endl;
		break;
	case 3:
		cout<<"God has no gender"<<endl;
		break;
	default:
		cout<<"Get away"<<endl;
		break;
	}
	return 0;
}