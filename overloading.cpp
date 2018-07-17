#include <iostream>

using namespace std;

class Date{
	int year;
	int month;
	int day;

	public:
		void set_date(int _year, int _month, int _day);
		void add_day(int inc);
		void add_month(int inc);
		void add_year(int inc);
		void show_date();
		
		Date()
		{
			cout<<"기본 생성자 호출!" <<endl;
			year=7777;
			month=7;
			day=7;
		}

		Date(int _year, int _month, int _day){
			cout<<"인자 3개인 생성자 호출!"<<endl;
			year = _year;
			month = _month;
			day = _day;
		}
};

void Date:: set_date(int _year, int _month, int _day){
	
	year=_year;
	month=_month;
	day= _day;
}

void Date:: add_day(int inc){
	int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i = month;

	if(month_day[i-1]-day >=inc){
		day+=inc;
		return;
	}
	else
	{
		add_month(1);
		day=1;
		inc=inc-(month_day[i-1]-day)-1;
		i++;
	}
	while(true){
		if((year%4==0 && year%100!=0) || year%400 ==0){
			month_day[1] = 29; //윤년
		}
		else{
			month_day[1]=28;
		}
		if(inc-month_day[i-1]>=0){
			add_month(1);
			inc=inc-month_day[i-1];
		}
		else if(inc-month_day[i-1]<0){
			day=day+inc;
			break;
		}
		i++;
		if(i>12)
			i=i-12;
	}
}

void Date:: add_month(int inc){
	add_year((inc+month-1)/12);
	month=month+inc%12;
	month=(month==12? 12:month%12);
}

void Date:: add_year(int inc){
	year+=inc;
}

void Date::show_date(){
	cout<<"Today is"<<year<<"y"
		<<month<<"m"
		<<day<<"day"<<endl;
}

int main(){
	
	//Date case1 = Date(2012,3,1); // 생성자로 초기화
	//Date day(2012,3,1)과 같은 암시적 방법을 주로 씀.

	/*case1.set_date(2011,3,1);
	case1.show_date();

	case1.add_year(7);
	case1.show_date();
	*/

	Date day = Date();
	day.show_date();

	Date day2(2018,7,17);
	day2.show_date();


	return 0;
}
