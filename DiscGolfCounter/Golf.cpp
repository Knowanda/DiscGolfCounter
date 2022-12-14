/*
* Eli and Jesse
* Purpose:
*    To create a disc golf score keeper
* 11/30/22
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;




int playerNumber;
int holeCount;
string playerName;
vector<string> nameList;
map<int, vector<int>> playerScores;



void playerScoresInput(int playerCount, vector<string> nameList, map<int, vector<int>>& playerScores)
{
    double strokes;
    double par;
    double dist;
    double avgdist;
    double abvblwpar;
    for (int i = 0; i < playerCount; i++)
    {


        cout << "\nWhat is " << nameList[i] << "'s score? ";
        cin >> playerNumber;
        cout << "Can you provide further info on the hole you just played?" << endl;
        cout << "\n What was the distance of the hole you just played?" << endl;
        cin >> dist;
        cout << "Now what was the par of the hole?" << endl;
        cin >> strokes;



        avgdist = dist / strokes;
        abvblwpar = playerNumber - strokes;



        cout << "Your avrage throw distance was " << avgdist << " feet." << endl;
        cout << "Also your score for this hole was" << abvblwpar << endl;
        playerScores[i].push_back(playerNumber);

    }
}




void nameFiles(string playerName)
{
    cout << "Enter new players name: ";
    cin >> playerName;
    fstream playerFile;



    nameList.push_back(playerName);
    playerFile.open(playerName + ".txt");



    playerFile << " ";
    playerFile.close();

}



void scoreCard(int holeCount, int playerCount, vector<string> nameList, map<int, vector<int>> playerScores)
{
    for (int i = 0; i < playerCount; i++)
    {

        for (int x = 1; x > 0; x--)
        {
            cout << "\n| " << nameList[i] << " |\n";    // Prints name for score board



            for (int x = holeCount; x > 0; x--)        // Prints top line for board
            {
                cout << "+";
                for (int x = 3; x > 0; x--)
                {
                    cout << "-";
                }
            }
            cout << "+\n";



            // prints number for board


            for (int x = 1; x > 0; x--)
            {
                for (auto& it : playerScores[i])
                {
                    cout << "| " << it << " ";
                }
            }

            cout << "|\n";




            for (int x = holeCount; x > 0; x--)
            {
                cout << "+";
                for (int x = 3; x > 0; x--)
                {
                    cout << "-";
                }
            }
            cout << "+";
        }

    }
}



int main()
{
    int getPlayerNameCounter;
    int playerCount;



    cout << "How many holes are you playing today? ";
    cin >> holeCount;
    cout << "How many players are playing today? ";
    cin >> playerCount;
    getPlayerNameCounter = playerCount;



    for (int y = 0; y < playerCount; y++)
    {
        ofstream playerFileScores;
        playerFileScores.open(playerName + "Scores.txt");
        playerFileScores.clear();
        playerFileScores.close();
    }



    while (getPlayerNameCounter > 0)
    {
        nameFiles(playerName);
        getPlayerNameCounter--;
    }

    for (int x = 0; x < holeCount; x++) {
        scoreCard(holeCount, playerCount, nameList, playerScores);
        playerScoresInput(playerCount, nameList, playerScores);

    }
    scoreCard(holeCount, playerCount, nameList, playerScores);
}


