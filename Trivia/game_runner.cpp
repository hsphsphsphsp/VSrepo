#include "game.h"

int main()
{
	bool notAWinner;

	Game aGame;

	aGame.add("Chet");
	aGame.add("Pat");
	aGame.add("Sue");

	do {
		aGame.rolling(rand() % 6 + 1);

		if (rand() % 9 == 7) {
			notAWinner = aGame.wrongAnswer();
		}
		else {
			notAWinner = aGame.wasCorrectlyAnswered();
		}
	} while (notAWinner);
}