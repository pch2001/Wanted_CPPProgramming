#pragma once

#include <iostream>
#include "Account.h"

class Bank {

public:
	Bank() {
		accounts[0] = new Account();
	}
	~Bank() {
		for (int i = 0; i < peopleCount; i++) {
			delete accounts[i];
		}
	}
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void Inquire();

private:
	Account* accounts[100];
	int peopleCount = 0;
};