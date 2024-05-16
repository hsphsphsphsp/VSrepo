#pragma once
#ifndef GAME_BETTER_H_
#define GAME_BETTER_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "IGame.h"

using namespace std;

class Question {
public:
	Question() {
		for (int i = 0; i < 50; i++) {
			string str1 = "Pop Question " + to_string(i);
			popQuestions.push_back(str1);

			string str2 = "Science Question " + to_string(i);
			scienceQuestions.push_back(str2);

			string str3 = "Sports Question " + to_string(i);
			sportsQuestions.push_back(str3);

			string str4 = "Rock Question " + to_string(i);
			rockQuestions.push_back(str4);
		}
	}

	void askQuestion(string str) {
		if (str == "Pop") {
			cout << popQuestions.front() << endl;
			popQuestions.pop_front();
		}

		if (str == "Science") {
			cout << scienceQuestions.front() << endl;
			scienceQuestions.pop_front();
		}

		if (str == "Sports") {
			cout << sportsQuestions.front() << endl;
			sportsQuestions.pop_front();
		}

		if (str == "Rock") {
			cout << rockQuestions.front() << endl;
			rockQuestions.pop_front();
		}
	}

private:
	list<string> popQuestions;
	list<string> scienceQuestions;
	list<string> sportsQuestions;
	list<string> rockQuestions;
};

class Player {
public:
	Player(string name) : name(name), place(0), purse(0), inPenaltyBox(false)
	{
	}

	string getName()
	{
		return name;
	}
	int getPlace()
	{
		return place;
	}
	int getPurse()
	{
		return purse;
	}
	bool getInPenaltyBox()
	{
		return inPenaltyBox;
	}
	void setInPenaltyBox(bool inPenaltyBox)
	{
		this->inPenaltyBox = inPenaltyBox;
	}
	void updatePlace(int roll) {
		place += roll;
		if (place > 11)
			place -= 12;
		cout << name << "'s new location is " << place << endl;
	}
	void increasePurse() {
		purse++;
		cout << name << " now has "
			<< purse << " Gold Coins." << endl;
	}

private:
	string name;
	int place;
	int purse;
	bool inPenaltyBox;
};

class GameBetter : public IGame {
public:
	GameBetter();

	bool add(string playerName);
	void rolling(int roll);
	bool wasCorrectlyAnswered();
	bool wrongAnswer();

private:
	vector<Player*> players;

	list<string> popQuestions;
	list<string> scienceQuestions;
	list<string> sportsQuestions;
	list<string> rockQuestions;

	Question question;

	int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	void askQuestion();
	string currentCategory();
	bool didPlayerWin();
	bool isPlayable();
};

#endif /* Game_Better_H_ */