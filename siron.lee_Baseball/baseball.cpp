#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}
	GuessResult guess(const string& guessNumber) {
		assertInvalidArgument(guessNumber);
		GuessResult result = { false, 0,0 };
		if (guessNumber == question) {
			return { true, 3,0 };
		}

		result.strikes = getStrikeCount(guessNumber);

		result.balls = getBallCount(guessNumber);

		if (result.strikes == 3)
			result.solved = true;

		return result;
	}

private:
	string question;
	void assertInvalidArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0];
	}
	int getBallCount(const std::string& guessNumber)
	{
		int ret = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
			for (int j = 0; j < guessNumber.length(); j++) {
				if (i == j) continue;
				if (guessNumber[i] == question[j]) ret++;
			}
		}
		return ret;
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int ret = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
			if (guessNumber[i] == question[i]) {
				ret++;
			}
		}
		return ret;
	}
};