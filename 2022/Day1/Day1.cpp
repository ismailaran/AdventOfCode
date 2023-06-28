#include <iostream>
#include <fstream>
#include <string>

int main() 
{
	std::ifstream input("Input.txt");

	int CaloryValue = 0;
	int BestElfValue = 0;
	int BestElf = 0;
	int currentElf = 1;

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {
			if (line.empty()) {
				if (CaloryValue > BestElfValue) {
					BestElf = currentElf;
					BestElfValue = CaloryValue;
				}
				currentElf++;
				CaloryValue = 0;
			}
			else {
				int ReadValue = std::stoi(line);
				CaloryValue += ReadValue;
			}
		}
		input.close();
		std::cout << "BestElf: " << BestElf << std::endl;
		std::cout << "CaloryValue: " << BestElfValue << std::endl;
	}

	return 0;
}