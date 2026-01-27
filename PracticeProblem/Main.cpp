#include <iostream>


class Calculator {
public:
	int Add(int x, int y) {
		count[0]++;
		return x + y;
	}
	float Divide(float x, float y) {
		count[3]++;
		return x / y;
	}
	int Substract(int x, int y) {
		count[1]++;
		return x - y;
	}
	int Multiply(int x, int y) {
		count[2]++;
		return x * y;
	}

	void ShowOperationCount() {
		std::cout << "덧셈: " << count[0] << "  뺄셈: " << count[1] <<"  곱셈: "<<count[2]<<"  나눗셈: "<<count[3];
	}

private:
	int x, y;
	int count[4] = {  };
};

class Printer {
public :
	void ShowString() {
		if (str) {
			std::cout << "Can’t show the string value";
		}
		else {
			int count=0;
			while (str[count]) {
				std::cout << str[count++];
			}
		}
		std::cout << "\n";
	}
	void SetString(const char* words) {
		size_t length = strlen(words) + 1;
		str = new char[length];
		strcpy_s(str, length, words);
		/*for (int ix = 0; ix < length; ix++) {
			*str[ix] = words[ix];
		}*/
	}
	~Printer() {
		delete str;
		str = nullptr;

	}
private :
	char* str = nullptr;
};

class Rectangle {
public:

	Rectangle(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int GetArea() {
		return x * y;
	}
	int GetGirth() {
		return 2 * x + 2 * y;
	}

private :
	int x;
	int y;
};

class Circle {
public:

	Circle(float x) {
		this->x = x;
	}

	float GetArea() {
		return x * x * 3.14;
	}
	float GetGirth() {
		return x * 2 * 3.14;
	}

private:
	float x;
};


class NameCard {
public :
	NameCard();
	NameCard(const char* one, const char* two, const char* three, const char* four) {
		int onelength = strlen(one)+1;
		int twolength = strlen(two)+1;
		int threelength = strlen(three)+1;
		int fourlength = strlen(four)+1;

		name = new char[onelength];
		number = new char[twolength];
		email = new char[threelength];
		job = new char[fourlength];

		strcpy_s(name, onelength, one);
		strcpy_s(number, twolength, two);
		strcpy_s(email, threelength, three);
		strcpy_s(job, fourlength, four);
	}

	void ShowData() {
		std::cout << "이    름: " << name<<"\n";
		std::cout << "전화번호: " << number<<"\n";
		std::cout << "이 메 일: " << email<<"\n";
		std::cout << "직    업: " << job;

	}

	~NameCard() {
		delete[] name;
		delete[] number;
		delete[] email;
		delete[] job;
	}
private:
	char* name = nullptr;
	char* number = nullptr;
	char* email = nullptr;
	char* job = nullptr;
};

void SettingData(const int& number) {
	char name[100];
	char phonenumber[100];
	char email[100];
	char job[100];

	NameCard* cardpack[3];

	for (int i = 0; i < number; i++) {
		std::cout << "이름 입력 : ";
		std::cin >> name;

		std::cout << "전화번호 입력 :";
		std::cin >> phonenumber;

		std::cout << "메일 입력 :";
		std::cin >> email;

		std::cout << "직업 입력 :";
		std:: cin >> job;

		cardpack[i] = new NameCard(name, phonenumber, email, job);
	}

	for (int i = 0; i < number; i++) {
		cardpack[i]->ShowData();
		std::cout << "\n";
		delete cardpack[i];
	}
}

void Problem1() {
	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();
}

void Problem2() {
	Printer printer;
	printer.ShowString();

	printer.SetString("Hello C++");
	printer.ShowString();

	printer.SetString("I Want to be a Good Developer");
	printer.ShowString();
}

void Problem3() {
	Rectangle rect = Rectangle(3, 4);    // Rectangle(가로길이, 세로길이)
	std::cout << "면적: " << rect.GetArea() << "\n";
	std::cout << "둘레: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);    // Circle(원의 반지름)
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetGirth() << "\n";
}

void Problem4() {
	NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
	jang.ShowData();
}

//클래스 상속 연습 문제
class Person {
public:
	Person(int age, const char* name) {
		this->age = age;
		int strlength = strlen(name) + 1;
		this->name = new char[strlength];
		strcpy_s(this->name, strlength, name);
	}
	Person(const Person& other) {
		this->age = other.age;
		int strlength = strlen(other.name)+1;
		this->name = new char[strlength];
		strcpy_s(this->name, strlength, other.name);
	}

	virtual ~Person() {
		delete[] name;
		name = nullptr;
	}
	virtual void ShowData() {
		std::cout << "이름 : " << name << "\n";
		std::cout << "나이 : " << age << "\n";
	}
private :
	int age;
	char* name;
};



class Student : public Person{
public :
	Student(int age, const char* name, const char* job): Person(age, name){
		int strlength = strlen(job) + 1;
		this->major = new char[strlength];
		strcpy_s(this->major, strlength, job);
	}
	Student(const Student& other) : Person(other){
		int strlength = (int)strlen(other.major) + 1;
		this->major = new char[strlength];
		strcpy_s(this->major, strlength, other.major);
	}
	virtual ~Student() {
		delete major;
		major = nullptr;
	}
	void ShowData() override {
		Person::ShowData();
		std::cout << "전공 : " << major << "\n";
	}
private:
	char* major;
};

void ClassTest() {
	Student Jang1 = Student(20, "Jang Se Yun", "Computer Science");
	Jang1.ShowData();

	Student Jang2 = Jang1;
	Jang2.ShowData();
}

int main()
{
	//Problem1();
	//Problem2();
	//Problem3();
	//Problem4();
	
	//SettingData(3);

	ClassTest();

	std::cin.get();
}
