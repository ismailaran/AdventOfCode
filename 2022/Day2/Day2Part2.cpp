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
		{"A X", 3},
		{"A Y", 4},
		{"A Z", 8},
		{"B X", 1},
		{"B Y", 5},
		{"B Z", 9},
		{"C X", 2},
		{"C Y", 6},
		{"C Z", 7},
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