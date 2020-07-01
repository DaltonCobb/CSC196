// Gussanumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;
#define DEBUG

int main()
{
	srand((unsigned int)time(0));
	int answer = (rand() % 20) + 1;

#ifdef DEBUG

	cout << "Answer: " << answer << endl;
#endif // DEBUG



    cout << "Enter a number between 1 and 20: " <<endl;
	int guess;
	cin >> guess;
	int numOfGuess = 4;
	char playAgain{};
		do
		{
			
	numOfGuess--;
	while (!(cin >> guess))
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Inalid input.\n";
	}


			if (guess < answer)
		{
				cout << "Too low.\n";
				cout << "You have: " << numOfGuess << " left" << endl;
				
		}
		else if (guess > answer)
		{
			cout << "Too high.\n";
			cout << "You have : " << numOfGuess << " left" << endl;
			

		}
		else 		{
			cout << "Correct: " << guess <<  " You Win" << endl;
		}
		} while (guess != answer && numOfGuess != 0);
		if (numOfGuess == 0)
		{
			cout << " You Lose " << endl;
			cout << "Play again? ";
			while (!(cin >> playAgain) || !(playAgain == 'y' || playAgain == 'n'))
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Invalid input\n";
				cout << "Play again? ";
			}
			cout << playAgain << endl;
		} while (playAgain == 'y' || playAgain == 'Y');
		

		return 0;

}


