#include "pch.h"
#include "../TDD1/Calc.cpp"

class AccountFixture : public testing::Test {
public:
	Calc calc{ 10000 };
};


TEST_F(AccountFixture, TestName) {

	EXPECT_EQ(calc.getBalance(), 10000);

	calc.deposit(5000);

	EXPECT_EQ(calc.getBalance(), 15000);

	calc.withdraw(3000);

	EXPECT_EQ(calc.getBalance(), 12000);
}
