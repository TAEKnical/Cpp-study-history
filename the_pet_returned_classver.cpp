#include <iostream>

using namespace std;

class Animal
{
private://�ڱ� ��ü ���ּ��� ���� ����.
	int food;
	int weight;

public: //��ü �ܺο����� ���� ����. main���� ȣ�� ������ ����.
	void set_animal(int _food, int _weight){
		food=_food;
		weight = _weight;
	}

	void increase_food(int inc){
		food += inc;
		weight += (inc/3);
	}

	void view_stat(){
		cout<<"the food ot this animal : "<<food<<endl;
		cout<<"the weight of this animal : "<<weight<<endl;
	}
}; // must be here!

int main(){
	Animal animal;
	animal.set_animal(100,50);
	animal.increase_food(30);
	animal.view_stat();


return 0;
}
