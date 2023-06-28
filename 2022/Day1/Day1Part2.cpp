#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main()
{
	std::ifstream input("Input.txt");

	int CaloryValue = 0;


	std::list<int> top3elfValues = { 0,0,0 };

	if (input.is_open()) {
		std::string line;

		while (std::getline(input, line)) {
			if (line.empty()) {
				for (int i = 2; i >= 0; i--) {
					auto it = std::next(top3elfValues.begin(), i);
					int value = *it;
					if (CaloryValue > value) {
						top3elfValues.insert(it, 1, CaloryValue);
						top3elfValues.pop_back();
					}
				}
				CaloryValue = 0;
			}
			else {
				int ReadValue = std::stoi(line);
				CaloryValue += ReadValue;
			}
		}
		input.close();
		
		int CombinedCaloryValue = 0;
		for (const auto& value : top3elfValues) {
			CombinedCaloryValue += value;
		}
		std::cout << "Top 3 values combined: " << CombinedCaloryValue << std::endl;
	}

	return 0;
}