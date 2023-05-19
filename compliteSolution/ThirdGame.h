#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "SecondGame.h"

using namespace std;

class ThirdGame
{
private:
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

    string allegedNumber(string numberStr, string realNumberStr) {

        string res = "";

        for (int i = 0; i < numberStr.length(); i++) {
            for (int j = 0; j < numberStr.length(); j++) {
                if (realNumberStr[i] == numberStr[j] && i == j) {
                    res += "x";
                }
                else if (realNumberStr[i] == numberStr[j] && i != j) {
                    res += "o";
                }
            }
        }

        return res;
    }

public:
    SecondGame secondGame;
    bool firstMove = true;

    void game() {
        bool fool = true;
        int n = randNumber();
        for (int i = 0; i < 10; i++) {
            string aln;
            cout << i + 1 << " your turn ";
            cin >> aln;
            string res = allegedNumber(to_string(n), aln);
            if (res != "xxxx")
            {
                cout << res << endl;
            }
            else
            {
                cout << "win" << endl;
                fool = false;
                break;
            }

            string cb;
            if (firstMove) {
                cout << secondGame.solveMisteryNumber("start") << endl;
                cout << "what about " << secondGame.guessedNumber << " " << endl;
                cin >> cb;
                cout << secondGame.solveMisteryNumber(cb) << endl;
                firstMove = false;
            }
            else {
                cout << "what about " << secondGame.guessedNumber << " " << endl;
                cin >> cb;
                cout << secondGame.solveMisteryNumber(cb) << endl;
            }
        }

        if (fool) {
            cout << "fool";
            cout << n;
        }
    }
};

