#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int countLong(std::vector<std::string>& array) {
	int longest = 0;
	for (int i = 0; i < array.size(); i++) {
		if (array[i].length() > longest) {
			longest = array[i].length();
		}
	}
	return longest;
}

bool isVowel(char c) {
	std::string vowels = "AaEeIiOoUuYy";

	for (wchar_t v : vowels) {
		if (c == v) return true;
	}
	return false;
}

std::vector<std::string> Get_listofsomechars(std::vector<std::string>& array) {
	std::vector<std::string> listofsomechars;
	for (const auto& formula : array) {
		if (formula.find("um") != std::string::npos) {
			listofsomechars.push_back(formula);
		}
	}
	return listofsomechars;
}

int find_glasnye(std::vector<std::string>& array) {
	int count = 0;
	for (const auto& formula : array) {
		for (char c : formula){
			if (isVowel(c)) {
				count += 1;
			}
		}
	}
	return count;
}

std::string createAcronym(const std::vector<std::string>& array) {
	std::string acronym;
	for (const auto& formula : array) {
		if (!formula.empty()) {
			acronym += formula[0];
		}
	}
	return acronym;
}

std::vector<std::string> sortFormulasByLength(const std::vector<std::string>& array) {
	std::vector<std::string> sorted = array;
	std::sort(sorted.begin(), sorted.end(), [](const std::string& a, const std::string& b) {
		return a.length() < b.length();
		});
	return sorted;
}



int main() {
	/*
	int zd = 100;
	int mana = 50;
	int speed = 75;
	int zdnew, mananew, speednew;
	zdnew = mana;
	mananew = speed;
	speednew = zd;
	std::cout << "Do preobrazovaniia " << zd << " " << mana << " " << speed << "\n";
	std::cout << "Posle " << zdnew << " " << mananew << " " << speednew;
	*/

	/*
	int time = 0;
	std::cin >> time;
	if (time >= 6 and time <= 11) {
		std::cout << "Time to create magic";
	}
	else if (time >= 12 and time <= 17) {
		std::cout << "Time to optimize code";
	}
	else if (time >= 18 and time <= 23) {
		std::cout << "Time study new scrolls";
	}
	else if (time >= 0 and time <= 5) {
		std::cout << "Time to vostannovit mana";
	}
	*/

	/*
	int count = 0;
	std::string str1 = "";
	for (int i = 1; i <= 50; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			std::cout << i << "\n";
		}
	}

	for (int i = 1; i <= 20; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			std::cout << "MagicCode" << "\n";
		}
		else if (i % 3 == 0) {
			std::cout << "Magic" << "\n";
		}
		else if (i % 5 == 0) {
			std::cout << "Code" << "\n";
		}
		else {
			std::cout << i << "\n";
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) {
			count += i;
		}
	}

	std::cout << count << "\n";

	for (int i = 1; i <= 5; i++) {
		std::string str2 = std::to_string(i);
		str1 += str2;
		std::cout << str1 << "\n";
	}
	*/

	std::vector<std::string> spells = {"Abracadabra", "Lumos maksima", "Expeliarmus", "Vingardium Leviosa", "Reducto"};

	std::cout << countLong(spells) << "\n";

	for (int i = 0; i < Get_listofsomechars(spells).size(); i++) {
		std::cout << Get_listofsomechars(spells)[i] << "\n";
	}
	
	std::cout << find_glasnye(spells) << "\n";

	std::cout << createAcronym(spells) << "\n";

	for (int i = 0; i < sortFormulasByLength(spells).size(); i++) {
		std::cout << sortFormulasByLength(spells)[i] << "\n";
	}

}