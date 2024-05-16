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

		//하나씩 처리
		//26글자 for 돌면서 퀴즈 참석자가 하나씩 시도를 하는 것
		for (char userAlpha : userdata) {

			//1. 2000 달러 찬스를 얻었는지 검사

			sum += get2000Bonus(strs, chance, userdata, userAlpha);
			//2중 for 돌면서 정답 문자열을 하나씩 검사해서
			//퀴즈참가자가 던진 문자가 존재하는지 검사
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
				//동일한 문자 개수를 Counting한다.
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
				//만약 퀴즈참석자가 요청한 문자가, 
				//정답문자열과 동일하다면
				if (strs[y][x] != userAlpha) continue;
				if (ffirst[y] != 0) continue;

				//Let's First 점수인지 확인한다.
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
					//획득 성공시 2000달러를 얻는다.
					sum += 2000;
					break;

				}
				chance[y] = -1;
			}
		}
		return sum;
	}

};