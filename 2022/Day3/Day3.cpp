#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main()
{
	std::ifstream input("Input.txt");

	int PrioritiesSum = 0;
	std::string priority = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {

			int stringHalfLength = line.length() / 2;
			std::string firstHalf = line.substr(0, stringHalfLength);
			std::string secondHalf = line.substr(stringHalfLength, stringHalfLength);

			std::cout << line << "   " << firstHalf << " : " << secondHalf << std::endl;

			for (int i = 0; i < stringHalfLength; i++) {
				char currentItem = firstHalf[i];
				if (secondHalf.find(currentItem) != std::string::npos) {
					PrioritiesSum += priority.find(currentItem) + 1;
					break;
				}
			}
		}
		input.close();
		std::cout << "Sum of priorities: " << PrioritiesSum << std::endl;
	}

	return 0;
}