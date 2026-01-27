#include <iostream>
#include "Account.h"
#include "Bank.h"

void Run() {
	bool ing = true;
	char choice;

	Bank newAccount;

	while (ing) {
		std::cout << "=============================\n";
		std::cout << "1. 계좌 개설 (CreateAccount)\n";
		std::cout << "2. 입금 (Deposit)\n";
		std::cout << "3. 출금 (Withdraw)\n";
		std::cout << "4. 전체 고객 잔액 조회 (Inquire)\n";
		std::cout << "Q. 종료\n";

		std::cout << "원하는 기능 숫자를 입력하세요 >> ";
		std::cin >> choice;

		if (choice == '1') { newAccount.CreateAccount(); }
		else if (choice == '2') { newAccount.Deposit(); }
		else if (choice == '3') { newAccount.Withdraw(); }
		else if (choice == '4') { newAccount.Inquire(); }
		else if (choice == 'q' || choice == 'Q') { ing = false; }
		std::cout << "\n";
	}

	
	 
}

int main() {
	Run();
}