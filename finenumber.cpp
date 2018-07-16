#include <iostream>
using namespace std;

int main(){
	int lucky_number = 3;
	cout << "find number! " << endl;
	
	int user_input;
	
	while(1){
		cout << "input : ";
		cin>>user_input;

		if(lucky_number==user_input){
			cout<<"Good!"<<endl;
			break;
		}
		else{
			cout <<"try again"<<endl;
		}
	}
	return 0;
}