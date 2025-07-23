#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArguemnt(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch(exception e){
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