#pragma once
#include <iostream>


class Account {
public:
	Account() {
		id = 0;
		name = nullptr;
		balance = 0;
	}
	Account(const Account& account) {
		id = account.id;
		balance = account.balance;
		int length = strlen(account.name) + 1;
		name = new char[length];
		strcpy_s(name, length, account.name);
	}

	Account(int id, char* name, int balance) {
		this->id = id;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->balance = balance;
	}
	~Account() {
		delete[] name;
	}

	int GetID() { return id; }
	char* GetName() { return name; }
	int GetBalance() { return balance; }
	int SetBalance(int money) { return (this->balance += money); }
private:
	int id;
	char* name;
	int balance;
};