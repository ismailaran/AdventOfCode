#include <iostream>
#include <fstream>
#include <string>


int main()
{
	std::ifstream input("Input.txt");
	int it = 0;

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {
			int lineLenght = line.length();
			while (it < lineLenght) {
				std::string potentialMarker = line.substr(it, 4);
				std::cout << potentialMarker << std::endl;
				for (int i = 0; i < 3; i++) {
					char compareChar = potentialMarker[0];
					potentialMarker.erase(0, 1);
					if (potentialMarker.find(compareChar) != std::string::npos) {
						it ++;
						break;
					}
					else {
						if (i == 2) {
							input.close();
							std::cout << it + 4 << std::endl;
							return 0;
						}
					}
				}
				
			}
		}
		input.close();
	}
	return 0;
}