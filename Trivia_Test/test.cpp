#include <iostream>
#include "pch.h"
#include "../Trivia/IGame.h"
#include "../Trivia/game.cpp"
#include "../Trivia/game_better.cpp"


class ParameterizedTestFixture : public testing::TestWithParam<int> {
public:
	std::string playGame(IGame& aGame, int seed) {
		std::ostringstream oss;
		auto oldCoutStreamBuf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf());

		bool notAWinner = true;

		aGame.add("Chet");
		aGame.add("Pat");
		aGame.add("Sue");

		srand(seed);
		do {
			aGame.rolling(rand() % 6 + 1);

			if (rand() % 9 == 7) {
				notAWinner = aGame.wrongAnswer();
			}
			else {
				notAWinner = aGame.wasCorrectlyAnswered();
			}
		} while (notAWinner);

		std::cout.rdbuf(oldCoutStreamBuf);
		return oss.str();
	}
};

INSTANTIATE_TEST_CASE_P(
	goldenMaster,
	ParameterizedTestFixture,
	testing::Values(
		1, 50, 100, 777
	)
);

TEST_P(ParameterizedTestFixture, goldenMaster) {
	int seed = GetParam();
	Game game_origin;
	GameBetter game_refactor;
	
	string expected = playGame(game_origin, seed);
	string actual = playGame(game_refactor, seed);

	EXPECT_EQ(expected, actual);
}