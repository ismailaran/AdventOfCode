#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() 
{
	std::ifstream input("Input.txt");
	
	int score = 0;

	//A & X = rock
	//B & Y = paper
	//C & Z = scissors
	std::unordered_map<std::string, int> resultsLookuptable = {
		{"A X", 4},
		{"A Y", 8},
		{"A Z", 3},
		{"B X", 1},
		{"B Y", 5},
		{"B Z", 9},
		{"C X", 7},
		{"C Y", 2},
		{"C Z", 6},
	};

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {
			auto result = resultsLookuptable.find(line);
			if (result != resultsLookuptable.end()) {
				int resultValue = result->second;
				score += resultValue;
			}
		}
		input.close();
		std::cout << "Endscore: " << score << std::endl;
	}

	return 0;
}