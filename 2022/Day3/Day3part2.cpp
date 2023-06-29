#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main()
{
	std::ifstream input("Input.txt");

	int PrioritiesSum = 0;
	int elfcounter = 0;
	std::string priority = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (input.is_open()) {
		std::string line;

		std::string Elf1Inventory;
		std::string Elf2Inventory;
		std::string Elf3Inventory;
		while (std::getline(input, line)) {
			elfcounter++;
			switch (elfcounter) {
				case 1:
					Elf1Inventory = line;
					break;
				case 2:
					Elf2Inventory = line;
					break;
				case 3:
					Elf3Inventory = line;
					
					for (int i = 0; i < Elf1Inventory.length(); i++) {
						char currentItem = Elf1Inventory[i];
						if (Elf2Inventory.find(currentItem) != std::string::npos) {
							if (Elf3Inventory.find(currentItem) != std::string::npos) {
								PrioritiesSum += priority.find(currentItem) + 1;
								break;
							}

						}
					}
					elfcounter = 0;
			}
		}
		input.close();
		std::cout << "Sum of priorities: " << PrioritiesSum << std::endl;
	}

	return 0;
}