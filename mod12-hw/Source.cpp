#include <iostream>
#include <string>


// assume the input string is just ASCII
bool isKperiodic(const std::string& input, const size_t k) {
	// handle vacuous cases
	if (k == 0) return true;
	if (input.empty()) return true;

	// the length has to be divisible by k for k-periodicity
	if (input.length() % k != 0) return false;

	// need to have at least 2*k symbols for a k-string to repeat
	// (the condition is flipped to avoid overflow)
	if (k > input.length() / 2) return false;

	for (size_t i = k; i < input.length(); ++i) {
		if (input[i] != input[i - k]) return false;
	}
	return true;
}


int main(void) {
	std::string test_str = "testtesttesttest";
	
	std::cout << "testing the string: \"" << test_str << "\"" << std::endl;
	for (size_t i = 0; i <= test_str.length(); ++i) {
		std::cout << "period " << i << "? " << std::boolalpha << isKperiodic(test_str, i) << std::endl;
	}

	return 0;
}