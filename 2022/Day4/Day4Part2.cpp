#include <iostream>
#include <fstream>
#include <string>
#include <list>

bool CheckIfSectionOverlapsOtherSection(int, int, int, int);

int main()
{
	std::ifstream input("Input.txt");
	int count = 0;

	if (input.is_open()) {
		std::string line;
		int CoordValluesArray[4];
		std::string value;

		while (std::getline(input, line)) {
			std::string currentValues = line;

			for (int i = 0; i < 4; i++) {

				for (int q = currentValues.length() - 1; q >= 0; q--) {
					if (currentValues[q] == '-' || currentValues[q] == ',') {
						value = currentValues.substr(q + 1, line.length() - q - 1);
						currentValues.erase(q);
						int intValue = std::stoi(value);

						CoordValluesArray[i] = intValue;
						break;
					}
					if (q == 0) {
						value = currentValues;
						int intValue = std::stoi(value);

						CoordValluesArray[i] = intValue;
						break;
					}

				}
			}
			
			if (CheckIfSectionOverlapsOtherSection(CoordValluesArray[3], CoordValluesArray[2], CoordValluesArray[1], CoordValluesArray[0])) {
				count++;
			}
			else if (CheckIfSectionOverlapsOtherSection(CoordValluesArray[1], CoordValluesArray[0], CoordValluesArray[3], CoordValluesArray[2])) {
				count++;
			}	



		}
		input.close();
		std::cout << count << std::endl;
	}

	return 0;
}

bool CheckIfSectionOverlapsOtherSection(int firstStart, int firstEnd, int secondStart, int secondEnd) {

	if (firstStart >= secondStart && firstStart <= secondEnd || firstEnd <= secondEnd && firstEnd >= secondStart) {
		return true;
	}
	else {
		return false;
	}
}