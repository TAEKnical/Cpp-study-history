#include <iostream>
#include <algorithm> //min함수를 이용하기 위한 헤더
using namespace std;

class MyString{

private:
	int string_length;
	char* string_content;
	int memory_capacity;

public:
	MyString(const char c);
	MyString(const char *s);
	MyString(const MyString &s);
	~MyString();

	MyString& assign(MyString &str);
	MyString& assign(const char* str);
	
	MyString& insert(int loc, char c);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, MyString& str);

	MyString& erase(int loc, int num);

	
	int find(int find_from, char c); //find_from에서 시작해서 가장 처음 나오는 대상 찾는 함수
	int find(int find_from, const char* str);
	int find(int find_from, MyString& str);

	int compare(MyString& str);

	char what_string(int i);
	int capacity() const;
	void reserve(int size);
	int size() const;
	void print();
	void println();
};

MyString::MyString(const char c)
{
	string_length=1;
	string_content = new char[1];
	string_content[1] = c;
	memory_capacity=1;
}
MyString::MyString(const char *s)
{
	string_length=strlen(s);
	string_content = new char[string_length];
	for(int i=0;i<string_length;i++){
		string_content[i] = s[i];
	}
	memory_capacity = string_length;
}

MyString::MyString(const MyString &s)
{
	string_length = s.string_length;
	string_content = new char[string_length];
	memory_capacity = string_length;

	for(int i = 0; i != string_length; i ++)
		string_content[i] = s.string_content[i];
}

MyString::~MyString()
{
	delete [] string_content;
}

int MyString::size() const
{
	return string_length;
}

void MyString::print()
{
	for(int i=0; i<string_length; i++)
		cout<<string_content[i];
	//cout<<string_content; 안 된다. 왜 안될까?
}

void MyString::println()
{
	for(int i=0; i<string_length; i++)
		cout<<string_content[i];
	cout<<endl;
}

MyString& MyString::assign(MyString &str)
{	
	memory_capacity = string_length;
	if(memory_capacity < str.string_length)
	{
		delete [] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	string_length = str.string_length;

	for(int i=0;i<string_length;i++)
	{
		string_content[i] = str.string_content[i];
	}

	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if(memory_capacity < str_length)
	{
		delete [] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for(int i=0;i<str_length;i++)
	{
		string_content[i] = str[i];
	}

	string_length = str_length;
	return *this;
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if(size > memory_capacity){
		char *prev_string_content=string_content;
		string_content = new char [size];
		memory_capacity = size;

		for(int i=0; i<string_length;i++)
			string_content[i] = prev_string_content[i];
		delete [] prev_string_content;
	}
}
char MyString::what_string(int i)
{
	if(i>=string_length || i< 0)
		return NULL;
	else
		return string_content[i];
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, MyString& str)
{
	//i의 바로 앞에 문자열을 삽입
	//범위를 벗어나는 문자열에 대해서는 삽입을 수행하지 않는다.

	if(loc<0 || loc > string_length)
		return *this;

	if(string_length + str.string_length > memory_capacity){

		if(memory_capacity*2 > string_length+str.string_length)
			memory_capacity*=2;
		else
			memory_capacity=string_length+str.string_length;


		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		
		int i;

		for(i=0; i<loc; i++)  //insert 되는 부분 직전까지 내용 복사
			string_content[i] = prev_string_content[i];
		
		for(int j=0; j<str.string_length;j++)  //새롭게 insert되는 문자열을 넣는다.
			string_content[i+j]=str.string_content[j];
		
		for(;i<string_length;i++)  //원래 문자열의 나머지 뒷 부분을 복사한다.
			string_content[str.string_length+i] = prev_string_content[i];

		delete [] prev_string_content;
		string_length = string_length+str.string_length;
		return *this;
	}

	//만약 memory_capacity를 초과하지 않는다면
	for(int i=string_length-1;i>=loc;i--)
		string_content[i+loc] = string_content[i];
	string_length=string_length+str.string_length;
	return *this;
}
MyString& MyString::erase(int loc, int num)
{
	//loc 포함 num개의 문자를 지운다.
	if(num < 0 || loc < 0 || loc>string_length)
		return *this;
	for(int i = loc+num; i<string_length; i++) 
		string_content[i-num]=string_content[i]; 

	string_length-=num;
	return *this;
}

int MyString::find(int find_from, MyString& str)
{
	int i,j;
	if(str.string_length==0)
		return -1;
	
	for(i=find_from; i<string_length-str.string_length; i++){
		for(j=0;j<str.string_length;j++){
			if(string_content[i+j] != str.string_content[j])
				break;
		}
		if(j==str.string_length)
			return i;
	}

	return -1;
}

int MyString::find(int find_from, const char* str)
{
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c)
{
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(MyString& str)
{	//사전식 비교
	//(*this)-(str)을 수행해서 1,0,-1로 결과를 리턴
	//1은 (*this)가 더 뒤에 온다는 의미. 0은 같은 경우. -1은 (*this)가 더 앞이라는 의미.
	for(int i=0; i<min(string_length, str.string_length); i++){
		if(string_content[i] > str.string_content[i])
			return 1;
		else if(string_content[i] < str.string_content[i])
			return -1;
	}

	if(string_length == str.string_length)
		return 0;

	else if(string_length > str.string_length)
		return 1;

	return -1;
}

int main()
{
	MyString str1("abcdef");
	MyString str2("abcde");

	cout << "str1 and str2 compare : " << str1.compare(str2) << endl;
}
