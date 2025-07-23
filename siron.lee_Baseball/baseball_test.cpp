#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowException01) {
	Baseball game;
	try {
		game.guess(string("12"));
		FAIL();
	}
	catch (exception e) {

	}
}

TEST(BaseballGame, ThrowException02) {
	Baseball game;
	try {
		game.guess(string("12s"));
		FAIL();
	}
	catch(exception e){

	}

}