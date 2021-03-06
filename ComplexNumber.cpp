#include <iostream>
using namespace std;

class Complex{
private :
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img);
	Complex(const Complex& c);
	Complex(const char* str);
	Complex operator + (const Complex& c);
	Complex operator - (const Complex& c);
	Complex operator * (const Complex& c);
	Complex operator / (const Complex& c);
	Complex& operator = (const Complex& c);
	Complex& operator += (const Complex& c);
	Complex& operator -= (const Complex& c);
	Complex& operator *= (const Complex& c);
	Complex& operator /= (const Complex& c);
	void println()
	{
		cout<<"("<<real<<","<<img<<")"<<endl;
	}
	Complex operator + (const char* str);
	Complex operator - (const char* str);
	Complex operator * (const char* str);
	Complex operator / (const char* str);
	
	friend Complex operator+(const Complex& a, const Complex& b);
};

Complex::Complex(double real, double img) : real(real), img(img){}
Complex::Complex(const Complex& c)
{
	real = c.real;
	img = c.img;
}
Complex::Complex(const char* str)
{
	int begin=0, end=strlen(str);
	real=0.0;
	img=0.0;

	int pos_i=-1;
	for(int i=0;i<end;i++)
	{
		if(str[i]=='i'){
			pos_i=i;
			break;
		}
	}

	if(pos_i==-1) // 실수라는 뜻
	{
		real = get_number(str,begin,end-1);
	}
	//복소수라면 실수/허수 나누어 처리
	real = get_number(str,begin,pos_i-1);
	img = get_number(str,pos_i+1,end-1);
	
	if(pos_i>=1 && str[pos_i-1] == '-')
		img*=-1.0;
}
Complex Complex::operator + (const Complex& c)
{
	Complex temp(real+c.real, img+c.img);
	return temp;
}
Complex operator + (const Complex& a, const Complex& b)
{
	Complex temp(a);
	return temp.operator+(b);
}
Complex Complex::operator - (const Complex& c)
{
	Complex temp(real-c.real, img-c.img);
	return temp;
}
Complex Complex::operator * (const Complex& c)
{
	Complex temp(real*c.real-img*c.img,real*c.img+img*c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c)
{
	Complex temp((real*c.real+img*c.img)/(c.real*c.real+c.img*c.img),(img*c.real-real*c.img) / (c.real*c.real+c.img * c.img));
	return temp;
}
Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;

	return *this;
}
Complex& Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
	(*this) = (*this) / c;
	return *this;
}
double Complex::get_number(const char* str, int from, int to)
{
	bool minus = false;
	if(from>to) return 0;

	if(str[from] == '-')
		minus = true;
	if(str[from]=='-' || str[from]=='+')
		from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for(int i=from; i<=to; i++)
	{
		if(isdigit(str[i]) && integer_part){
			num*=10.0;
			num+=(str[i]-'0');
		}
		else if(str[i] == '.')
			integer_part = false;
		else if(isdigit(str[i]) && !integer_part)
		{
			decimal /=10.0;
			num += ((str[i]-'0')*decimal);
		}
		else
			break;//그 외 이상한 문자가 있는 경우
	}
	if(minus)
		num*=-1.0;
	return num;

}
Complex Complex:: operator + (const char* str)
{
	Complex temp = (str);
	return (*this) + temp;
}
Complex Complex:: operator - (const char* str)
{
	Complex temp = (str);
	return (*this) - temp;
}
Complex Complex:: operator * (const char* str)
{
	Complex temp = (str);
	return (*this) * temp;
}
Complex Complex:: operator / (const char* str)
{
	Complex temp = (str);
	return (*this) / temp;
}

int main()
{
	/*Complex a(0, 0);
	a = a + "-1.1+i1.823";
				//a = a.operator+("-1.1+i1.823");를 컴파일러는 a = a+"-1.1+i1.823"과 같이 해석함.
				//따라서 a = "-1.1 + i1.823" + a 는 같은 식이지만 180724v 에서는 계산 불가능했음.
	a.println();
	a = a - "1.2 -i1.823";
	a.println();
	a = a * "2.3+i22";
	a.println();
	a = a / "-12+i55";
	a.println();
	*/
	Complex a(0,0);
	a="-1.1+i3.923"+a;
	a.println();
}


//Some_Class a = b;  // ①
//Some_Class a; // ②
//a = b;

//1과 2는 완전히 다른 문장. 1은 복사생성자를 호출하는 것, 2는 대입연산자를 호출하는 것.