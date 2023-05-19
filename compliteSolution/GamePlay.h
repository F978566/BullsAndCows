#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "SecondGame.h"
#include "FirstGame.h"
#include "ThirdGame.h"

using namespace std;

class GamePlay
{
private:
    SecondGame secondGame;
    ThirdGame thirdGame;
    FirstGame firstGame;

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

public:

    void playGame() {
        int selectGame;
        cout << "select game \n 1, 2 or 3 ";
        cin >> selectGame;

        if (selectGame == 2) {
            cout << "Enter start ";
            while (true) {
                string cb;
                cin >> cb;
                cout << secondGame.solveMisteryNumber(cb);
            }
        }
        else if (selectGame == 1) {
            firstGame.game();
        }
        else if (selectGame == 3) {
            thirdGame.game();
        }
    }

};

