#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& string) {
		throw std::length_error("Must be three letters");
	}
};