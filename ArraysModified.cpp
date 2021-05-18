/*
Arrays.cpp
	Author:	Mathew Ricketts
	Date:	February 15, 2017
	
	This program will use a 2D array to recieve bowling scores, then outputs
	the results for each player, their average, and the overall team average.
*/

#include <iostream>	
#include <iomanip>
#include <math.h>
using namespace std;
using namespace myValidation;

/**	DisplayScores function
 *	@param		scores[,] = A 2D array containing the scores to display.
 *  @param		names[] = A 1D array containing the names of the players.
 *  @param		NUMBER_OF_GAMES = The number of games each player plays.
 *  @param		NUMBER_OF_PLAYERS = The number of players.
*/
void DisplayScores(int scores[][3], string names[], const int NUMBER_OF_GAMES, const int NUMBER_OF_PLAYERS);

int main()
{
	//INPUT
	//Variable Declarations
	string names[] = {"Jessica", "Shawn", "Mathew", "Thom"};
	int scores[4][3];
	int score;
	//Constant Declarations
	const int NUMBER_OF_GAMES = 3;
	const int NUMBER_OF_PLAYERS = 4;
	const int MIN_SCORE = 0;
	const int MAX_SCORE = 300;
	
	//Display Header
	cout << "===================\n"
		 << "      BOWLING\n"
		 << "===================\n";
	
	//Recieve User Input
	//For each player
	for (int player = 0; player < NUMBER_OF_PLAYERS; player++)
	{
		cout << "\nEnter the scores for " << names[player];
		
		//For each game
		for (int game = 0; game < NUMBER_OF_GAMES; game++)
		{
			//Get Input
			cout << "\nGame " << game+1 << ": ";
			cin >> score;
			
			//Data Validation			
			if (score > MAX_SCORE || score < MIN_SCORE)
			{
				cin.clear();
				cin.sync();
				cout << "Please enter in a number between " << MAX_SCORE << " and " << MIN_SCORE << " : ";
				game --;
			}
		   	else if(cin.fail())	
			{
				cin.clear();
				cin.sync();
				cout << "Please enter in a number: ";
				game --;
			}
			else
			{
			//Store the data
			scores[player][game] = score;
		}
		}
	}
	
	//PROCESSING AND OUTPUT
	DisplayScores(scores, names, NUMBER_OF_GAMES, NUMBER_OF_PLAYERS);
}

void DisplayScores(int scores[][3], string names[], const int NUMBER_OF_GAMES, const int NUMBER_OF_PLAYERS)
{
	double playerAverage = 0;
	double teamAverage = 0;
	
	//For each player
	for (int player = 0; player < NUMBER_OF_PLAYERS; player++)
	{
		cout << "\n\nResults for: " << names[player];
		cout << "\n===================================";
		 	 
		//For each game
		for (int game = 0; game < NUMBER_OF_GAMES; game++)
		{
			cout << "\nGame " << game+1 << "     " << scores[player][game];
			playerAverage = playerAverage +  scores [player][game];
		}
		
		playerAverage = playerAverage / NUMBER_OF_GAMES;
		cout << setprecision(2) << fixed << "\n\nThe average for " << names[player] << " is " << playerAverage;
		
		teamAverage = teamAverage + playerAverage;
		playerAverage = 0;
	}
	
	teamAverage = teamAverage / NUMBER_OF_PLAYERS;
	cout << setprecision(2) << fixed << "\n\n====== TEAM AVERAGE ======"<<"\n\nThe average for the team is " << teamAverage;
}









