/*
* Eli and Jesse
* Purpose:
*	To create a disc golf score keeper
* 11/30/22
*/

#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int holeCount;
string playerName;
vector<string> nameList;
map<int, vector<int>> playerScores;

void playerScoresInput(int playerCount, vector<string> nameList, map<int, vector<int>> &playerScores)
{
	int playerNumber;
	for (int i = 0; i < playerCount; i++)
	{
		
		
		cout << "\nWhat is " << nameList[i] << "'s score? ";
		cin >> playerNumber;
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
			cout << "\n| " << nameList[i] << " |\n";	// Prints name for score board

			for (int x = holeCount; x > 0; x--)		// Prints top line for board
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

	while(getPlayerNameCounter > 0)
	{
		nameFiles(playerName);
		getPlayerNameCounter--; 
	}
	
	scoreCard(holeCount, playerCount, nameList, playerScores);
	playerScoresInput(playerCount, nameList, playerScores);
	scoreCard(holeCount, playerCount, nameList, playerScores);
	playerScoresInput(playerCount, nameList, playerScores);
	scoreCard(holeCount, playerCount, nameList, playerScores);

}

