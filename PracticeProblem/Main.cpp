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
		std::cout << "µ¡¼À: " << count[0] << "  »¬¼À: " << count[1] <<"  °ö¼À: "<<count[2]<<"  ³ª´°¼À: "<<count[3];
	}

private:
	int x, y;
	int count[4] = {  };
};

class Printer {
public :
	void ShowString() {
		if (str) {
			std::cout << "Can¡¯t show the string value";
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
		std::cout << "ÀÌ    ¸§: " << name<<"\n";
		std::cout << "ÀüÈ­¹øÈ£: " << number<<"\n";
		std::cout << "ÀÌ ¸Þ ÀÏ: " << email<<"\n";
		std::cout << "Á÷    ¾÷: " << job;

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
	Rectangle rect = Rectangle(3, 4);    // Rectangle(°¡·Î±æÀÌ, ¼¼·Î±æÀÌ)
	std::cout << "¸éÀû: " << rect.GetArea() << "\n";
	std::cout << "µÑ·¹: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);    // Circle(¿øÀÇ ¹ÝÁö¸§)
	std::cout << "¸éÀû: " << circle.GetArea() << "\n";
	std::cout << "µÑ·¹: " << circle.GetGirth() << "\n";
}

void Problem4() {
	NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
	jang.ShowData();
}

int main()
{
	//Problem1();
	//Problem2();
	//Problem3();
	Problem4();

	std::cin.get();
}
