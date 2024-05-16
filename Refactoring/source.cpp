#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Score {
public:
	string getScore(string& userdata, vector<string>& strs) {
		int conCnt = 0;
		int ffirst[5] = { 0 };

		int sum = 0;
		int chance[5] = { -1, -1, -1, -1, -1 };

		//�ϳ��� ó��
		//26���� for ���鼭 ���� �����ڰ� �ϳ��� �õ��� �ϴ� ��
		for (char userAlpha : userdata) {

			//1. 2000 �޷� ������ ������� �˻�

			sum += get2000Bonus(strs, chance, userdata, userAlpha);
			//2�� for ���鼭 ���� ���ڿ��� �ϳ��� �˻��ؼ�
			//���������ڰ� ���� ���ڰ� �����ϴ��� �˻�
			sum += get1000Bonus(strs, userAlpha, ffirst, chance);

			int passCnt = getPassCnt(strs, userAlpha);
			
			if (passCnt) {
				conCnt++;
				sum += (conCnt * 100) * passCnt;
			}
			else {
				conCnt = 0;
				for (int i = 0; i < 5; i++) chance[i] = -1;
			}


		}

		return "$" + to_string(sum);
	}

	int getPassCnt(std::vector<std::string>& strs, char userAlpha)
	{
		int passCnt = 0;
		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				if (strs[y][x] != userAlpha) continue;
				//������ ���� ������ Counting�Ѵ�.
				passCnt++;
			}
		}
		return passCnt;
	}

	int get1000Bonus(std::vector<std::string>& strs, char userAlpha, int  ffirst[5], int  chance[5])
	{
		int sum = 0;
		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				//���� ���������ڰ� ��û�� ���ڰ�, 
				//���乮�ڿ��� �����ϴٸ�
				if (strs[y][x] != userAlpha) continue;
				if (ffirst[y] != 0) continue;

				//Let's First �������� Ȯ���Ѵ�.
				if (x == 0) {
					sum += 1000;
					chance[y] = y;
				}
				ffirst[y] = 1;
			}
		}
		return sum;
	}

	int get2000Bonus(std::vector<std::string>& strs, int  chance[5], std::string& userdata, char userAlpha)
	{
		int sum = 0;
		for (int y = 0; y < strs.size(); y++) {
			if (chance[y] != -1) {
				for (int x = 0; x < strs[chance[y]].size(); x++) {
					if (strs[chance[y]][x] != userAlpha) continue;
					//ȹ�� ������ 2000�޷��� ��´�.
					sum += 2000;
					break;

				}
				chance[y] = -1;
			}
		}
		return sum;
	}

};