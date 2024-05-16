#pragma once
#include <string>

class IGame {
public:
	virtual bool add(std::string playerName) = 0;
	virtual void rolling(int roll) = 0;
	virtual bool wasCorrectlyAnswered() = 0;
	virtual bool wrongAnswer() = 0;
};