#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class FirstGame
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

    void game() {
        bool fool = true;
        //cout << randNumber();
        int n = randNumber();
        for (int i = 0; i < 10; i++) {
            string aln;
            cout << i + 1 << " ";
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
        }

        if (fool) {
            cout << "fool";
            cout << n;
        }
    }
};

