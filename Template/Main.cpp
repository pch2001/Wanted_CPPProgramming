#include <iostream>

// 두 변수의 값을 서로 교화하는 함수

template<typename t>
void Swap(t& a, t& b) 
{
	t temp = a;
	a = b;
	b = temp;

}

//void Swap(float a, float b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//
//}


int main() {
	int a = 10;
	int b = 20;
	std::swap(a, b);

	float fa = 10.0f;
	float fb = 20.0f;
	std::swap(fa, fb);




	std::cin.get();
}


/*
class TEST {
	TEST() {
		int a = 10;
		//Swap(a);
	}
};


inline void change(int& a){
	a += 20;
}

int main() {
	int a = 0;
	change(a);
	a += 20;

}*/