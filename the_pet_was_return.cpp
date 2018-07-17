#include <iostream>

using namespace std;


typedef struct Animal{
	char name[30];
	int age;
	int health;
	int food;
	int clean;
}Animal;

void create_animal(Animal *animal){
		cout<<"animal`s name?";
		cin>>animal->name;
		
		cout<<"animal`s age?";
		cin>>animal->age;

		animal->health = 100;
		animal->food = 100;
		animal->clean = 100;
	}

void play(Animal *animal){
	animal->health += 10;
	animal->food -=20;
	animal->clean-=30;
}

void show_stat(Animal *animal){
	cout << animal->name <<"`s states"<<endl;
	cout << "animal`s health :" << animal->health<<endl;
	cout << "animal`s food :"<< animal->food<<endl;
	cout << "animal`s claen :" << animal->clean<<endl;
}

void one_day_pass(Animal* animal){
	animal->health +=10;
	animal->food-=20;
	animal->clean-=30;
}


int main(){
	struct Animal *list[10];
	int animal_number=0;

	

	for(;;)
	{
		cout<<"1.Add animal"<<endl;
		cout<<"2.Play with animal"<<endl;
		cout<<"3.Show states"<<endl;

		int input;
		cin>>input;

		switch(input){
		case 1:
			list[animal_number] = new Animal;
			create_animal(list[animal_number]);
			animal_number++;
			break;
		case 2:
			cout<<"Who do you wanna play with? :";
			int play_with;
			cin >> play_with;

			if(play_with < animal_number)
				play(list[play_with]);
			break;
		case 3:
			cout<<"Who do you wanna be showed about? : ";
			cin >> play_with;
			if(play_with<animal_number)
				show_stat(list[play_with]);
			break;
		}
		for(int i=0; i!=animal_number;i++)
		{
			one_day_pass(list[i]);
		}
	}

	for(int i=0; i<animal_number;i++){
		delete list[i];
	}

	return 0;
}