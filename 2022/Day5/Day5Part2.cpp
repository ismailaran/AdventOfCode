#include <iostream>
#include <fstream>
#include <string>


std::string cargoArray[9];
void ExecuteMoveInstructions(int, int, int);

int main()
{
	std::ifstream input("Input.txt");
	bool countingCargo = true;
	int moveInstructions[3];
	

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {
			if (countingCargo) {
				if (line.empty()) {
					countingCargo = false;
				}
				else {
					for (int i = 0; i < 9; i++) {
						char currentBox = line[i * 4 + 1];
						if (currentBox == '1')break;
						if (currentBox != ' ') {
							cargoArray[i] += currentBox;
						}
					}
				}
			}
			else {		//countingCargo == false
				for (int i = 0; i < 3; i++) {
					int it = line.find(' ');
					line.erase(0, it + 1);
					it = line.find(' ');
					moveInstructions[i] = std::stoi(line.substr(0, it));
					line.erase(0, it + 1);
				}
				ExecuteMoveInstructions(moveInstructions[0], moveInstructions[1], moveInstructions[2]);
			}
		}
		input.close();
		std::string answer;
		for (int i = 0; i < 9; i++) {
			answer += cargoArray[i][0];
		}
		std::cout << "answer: " << answer << std::endl;
	}

	return 0;
}


void ExecuteMoveInstructions(int moveAmount, int moveStartLoc, int moveTowards) {
	std::string grabbedBoxes = cargoArray[moveStartLoc - 1].substr(0, moveAmount);
	cargoArray[moveTowards - 1].insert(0, grabbedBoxes);
	cargoArray[moveStartLoc - 1].erase(0, moveAmount);
}