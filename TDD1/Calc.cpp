class Calc {
public:

	Calc(int balance) : balance(balance)
	{
	}

	int getBalance() {
		return balance;
	}

	void deposit(int money) {
		balance += money;
	}

	void withdraw(int money) {
		balance -= money;
	}
	

private:
	int balance;
};