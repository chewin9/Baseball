#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArguemnt(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowException01) {
	assertIllegalArguemnt("12");
}

TEST_F(BaseballFixture, ThrowException02) {
	assertIllegalArguemnt("12s");
}

TEST_F(BaseballFixture, ThrowException03) {
	assertIllegalArguemnt("121");
}

TEST_F(BaseballFixture, Game01) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Game02) {
	GuessResult result = game.guess("127");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Game03) {
	GuessResult result = game.guess("213");

	EXPECT_TRUE(!result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}