#include "game_better.h"
#include <iostream>
#include <string>

using namespace std;

GameBetter::GameBetter() : currentPlayer{ 0 }
{
}

bool GameBetter::isPlayable()
{
	return ((int)players.size() >= 2);
}

bool GameBetter::add(string playerName)
{
	players.push_back(new Player(playerName));

	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

void GameBetter::rolling(int roll)
{
	cout << players[currentPlayer]->getName() << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (players[currentPlayer]->getInPenaltyBox()) {
		if (roll % 2 != 0) {
			isGettingOutOfPenaltyBox = true;

			cout << players[currentPlayer]->getName() << " is getting out of the penalty box" << endl;
			players[currentPlayer]->updatePlace(roll);
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}
		else {
			cout << players[currentPlayer]->getName() << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else {
		players[currentPlayer]->updatePlace(roll);
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}
}

void GameBetter::askQuestion()
{
	question.askQuestion(currentCategory());
}


string GameBetter::currentCategory()
{
	if (players[currentPlayer]->getPlace() == 0) return "Pop";
	if (players[currentPlayer]->getPlace() == 4) return "Pop";
	if (players[currentPlayer]->getPlace() == 8) return "Pop";
	if (players[currentPlayer]->getPlace() == 1) return "Science";
	if (players[currentPlayer]->getPlace() == 5) return "Science";
	if (players[currentPlayer]->getPlace() == 9) return "Science";
	if (players[currentPlayer]->getPlace() == 2) return "Sports";
	if (players[currentPlayer]->getPlace() == 6) return "Sports";
	if (players[currentPlayer]->getPlace() == 10) return "Sports";
	return "Rock";
}

bool GameBetter::wasCorrectlyAnswered()
{
	if (players[currentPlayer]->getInPenaltyBox()) {
		if (isGettingOutOfPenaltyBox) {
			players[currentPlayer]->setInPenaltyBox(false);
			cout << "Answer was correct!!!!" << endl;

			players[currentPlayer]->increasePurse();
			
			bool winner = didPlayerWin();
			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;

			return winner;
		}
		else {
			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
			return true;
		}
	}
	else {
		cout << "Answer was correct!!!!" << endl;

		players[currentPlayer]->increasePurse();

		bool winner = didPlayerWin();
		currentPlayer++;
		if (currentPlayer == players.size()) currentPlayer = 0;

		return winner;
	}
}

bool GameBetter::wrongAnswer()
{
	if (players[currentPlayer]->getInPenaltyBox()) {
		if (isGettingOutOfPenaltyBox) {
			cout << "Question was incorrectly answered" << endl;
			cout << players[currentPlayer]->getName() + " was sent to the penalty box" << endl;
			players[currentPlayer]->setInPenaltyBox(true);

			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
			return true;
		}
		else {
			currentPlayer++;
			if (currentPlayer == players.size()) currentPlayer = 0;
			return true;
		}
	}
	else {
		cout << "Question was incorrectly answered" << endl;
		cout << players[currentPlayer]->getName() + " was sent to the penalty box" << endl;
		players[currentPlayer]->setInPenaltyBox(true);

		currentPlayer++;
		if (currentPlayer == players.size()) currentPlayer = 0;
		return true;
	}
}

bool GameBetter::didPlayerWin()
{
	return !(players[currentPlayer]->getPurse() == 6);
}