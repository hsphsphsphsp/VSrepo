#pragma once
#include "pch.h"
//#include "../Refactoring/source.h"
#include "../Refactoring/source.cpp"

TEST(TestCaseName, TestName) {
	vector<string> strs;

	string userdata = "";
	int n = 0;
	FILE* f = new FILE;

	freopen_s(&f, "../Refactoring/input1.txt", "r", stdin);
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;
	cin.clear();
	Score s;
	string ret = s.getScore(userdata, strs);

	EXPECT_EQ(ret, "$6500");
}

TEST(TestCaseName, TestName2) {
	vector<string> strs;

	string userdata = "";
	int n = 0;
	FILE* f = new FILE;

	freopen_s(&f, "../Refactoring/input2.txt", "r", stdin);
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;
	cout << userdata << endl;
	Score s;
	string ret = s.getScore(userdata, strs);

	EXPECT_EQ(ret, "$9500");

}