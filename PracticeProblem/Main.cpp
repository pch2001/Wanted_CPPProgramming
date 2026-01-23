#include <iostream>


class Calculator {
public:
	int Add(int x, int y) {
		return x + y;
	}
	float Divide(int x, int y) {
		return x / y;

	}
	int Substract(int x, int y) {
		return x - y;

	}
	int Multiply(int x, int y) {
		return x * y;

	}

	void ShowOperationCount();

private:
	int x, y;
	int count[3] = {  };
};




int main() {
	
	return 0;
}

