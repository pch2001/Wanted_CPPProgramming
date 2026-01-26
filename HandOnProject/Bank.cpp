#include "Bank.h"
#include <iostream>

void Bank::CreateAccount() {
	int id;
	char name[50];
	int balance;

	std::cout << "계좌번호 : ";
	std::cin >> id;
	std::cout << "고객 이름 : ";
	std::cin >> name;
	std::cout << "고객의 잔액 : ";
	std::cin >> balance;

	peopleCount++;
	accounts[peopleCount] = new Account(id, name, balance);
}
void Bank::Deposit() {
	int accountnumber;
	std::cout << "계좌번호 : ";
	std::cin >> accountnumber;

	int money;
	std::cout << "입금 금액 :";
	std::cin >> money;
	accounts[peopleCount]->SetBalance(money);
	std::cout << "입금 후 금액 : " << accounts[peopleCount]->GetBalance() << "\n";
}

void Bank::Withdraw() {
	int money;
	std::cout << "출금 금액 : ";
	std::cin >> money;
	accounts[peopleCount]->SetBalance(-money);
	std::cout << "출금 후 금액 : " << accounts[peopleCount]->GetBalance() << "\n";

}

void Bank::Inquire() {
	for (int i = 1; i <= peopleCount; i++) {
		std::cout << i << "번째 고객)\n계좌 번호 : " << accounts[i]->GetID() << ", 고객 이름 : " << accounts[i]->GetName() << ", 잔액 : " << accounts[i]->GetBalance() << "\n";
	}
}