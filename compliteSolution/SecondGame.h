#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
using namespace std;

class SecondGame
{
public:
	int guessedNumber;

	int solveMisteryNumber(string cowsBulls) {
		int cows = 0;
		int bulls = 0;

		if (cowsBulls == "start") {
			allPosibleNumbers();
			guessedNumber = findNumber();
			all_number[guessedNumber] = false;
			return guessedNumber;
		}

		for (int i = 0; i < cowsBulls.length(); i++) {
			if (cowsBulls[i] == 'o')
				cows++;
			else if (cowsBulls[i] == 'x')
				bulls++;
		}

		if (cows != 0 && bulls == 0) {
			foundCows(to_string(guessedNumber), cows);
			all_number[guessedNumber] = false;
			guessedNumber = findNumber();
			return guessedNumber;
		}
		else if (cows == 0 && bulls != 0) {
			foundBulls(to_string(guessedNumber), bulls);
			all_number[guessedNumber] = false;
			guessedNumber = findNumber();
			return guessedNumber;
		}
		else if (cows != 0 && bulls != 0) {
			foundBullsAndCows(to_string(guessedNumber), bulls, cows);
			all_number[guessedNumber] = false;
			guessedNumber = findNumber();
			return guessedNumber;
		}
		else {
			nothing(to_string(guessedNumber));
			guessedNumber = findNumber();
			return guessedNumber;
		}
	}

private:
	map<int, bool> all_number;

	bool checkDouble(string number) {
		for (int i = 0; i < number.length() - 1; i++) {
			for (int j = i + 1; j < number.length(); j++) {
				if (number[i] == number[j]) {
					return false;
				}
			}
		}

		return true;
	}

	void allPosibleNumbers() {
		int c = 0;

		for (int i = 1000; i <= 9999; i++) {
			if (checkDouble(to_string(i))) {
				all_number[i] = true;
			}
			else {
				all_number[i] = false;
			}
		}

	}

	void foundCows(string number, int countCows) {
		string strI;
		int c = 0;

		for (int i = 1000; i <= 9999; i++) {
			strI = to_string(i);
			for (int j = 0; j < number.length(); j++) {
				if (strI.find(number[j]) != -1) {
					c++;
				}
			}
			if (strI[0] == number[0]) {
				all_number[i] = false;
			}

			if (c != countCows) {
				all_number[i] = false;
				c = 0;
			}
			else {
				c = 0;
			}
		}
	}


	void foundBulls(string number, int countBulls) {
		string strI;
		int c = 0;

		for (int i = 1000; i <= 9999; i++) {
			strI = to_string(i);
			for (int j = 0; j < strI.length(); j++) {
				if (strI[j] == number[j])
					c++;
			}
			if (c != countBulls) {
				all_number[i] = false;
				c = 0;
			}
			else {
				c = 0;
			}
		}
	}

	void foundBullsAndCows(string number, int countBulls, int countCows) {
		string strI;
		int cBulls = 0;
		int cCows = 0;

		for (int i = 1000; i <= 9999; i++) {
			strI = to_string(i);
			for (int j = 0; j < strI.length(); j++) {
				if (strI[j] == number[j])
				{
					cBulls++;
				}
				else if (strI.find(number[j]) != -1) {
					cCows++;
				}
			}

			//cout << cCows << " " << cBulls << " " << strI << endl;

			if (cBulls != countBulls || cCows != countCows) {
				all_number[i] = false;
				cBulls = 0;
				cCows = 0;
			}
			else {
				cBulls = 0;
				cCows = 0;
			}
		}
	}

	void nothing(string number) {
		string strI;
		for (int i = 1000; i < 9999; i++) {
			strI = to_string(i);
			for (int j = 0; j < strI.length(); j++)
			{
				for (int x = 0; x < number.length(); x++) {
					if (strI[j] == number[x]) {
						all_number[i] = false;
					}
				}
			}
		}
	}

	int randNumber() {
		srand(time(NULL));
		int num;
		string strNum;
		do {
			num = rand() % 9000 + 1000;
			strNum = to_string(num);
		} while (strNum[0] == strNum[1] || strNum[0] == strNum[2] || strNum[0] == strNum[2] || strNum[0] == strNum[3] || strNum[1] == strNum[2] || strNum[1] == strNum[3] || strNum[2] == strNum[3]);

		return num;
	}

	int findNumber() {
		for (int i = 1000; i < 9999; i++) {
			if (all_number[i]) {
				return i;
			}
		}
	}

};

