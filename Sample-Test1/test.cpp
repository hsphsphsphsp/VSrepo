#include <iostream>
#include "pch.h"
#include "../Project1/ALU.cpp"
#include "../Project1/Result.cpp"

TEST(ALU, ADDTest1) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(30, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, ADDTest2) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, ADDTest3) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.setOPCODE("ADD");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, SUBTest1) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(-10, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, SUBTest2) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, SUBTest3) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.setOPCODE("SUB");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, MULTest1) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(200, ret.getResult());
	EXPECT_EQ(0, ret.getStatus());
}

TEST(ALU, MULTest2) {
	ALU alu;
	alu.setOperand1(-1);
	alu.setOperand2(20);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(1, ret.getStatus());
}

TEST(ALU, MULTest3) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.setOPCODE("MUL");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(2, ret.getStatus());
}

TEST(ALU, ERRTEST) {
	ALU alu;
	alu.setOperand1(10);
	alu.setOperand2(-1);
	alu.setOPCODE("ERR");

	Result ret;
	alu.enableSignal(&ret);

	EXPECT_EQ(65535, ret.getResult());
	EXPECT_EQ(3, ret.getStatus());
}