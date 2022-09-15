// required libraries
#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

// declaring variables and functions
int NUM_TRY=3;
int checkGuess (char, string, string&);
void main_menu();
string message = "Play!";

// main function
int main(int argc, char *argv[])
{
	string name;
	char letter;
	string month;

// list for the word tobe guessed in game, here we give months for our game.
    string months[] =
	{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};

	// generating random numbers from 1 to 12
	srand(time(NULL));
	int n=rand()% 12;
	month=months[n];


	string hide_m(month.length(),'X');



	// loop to give user 3 tries to guess the letter
	while (NUM_TRY!=0)
	{
		main_menu();
		cout << "\n\n\t\t\t\t" << hide_m;
		cout << "\n\n\t\t\t\tGuess a letter: ";
		cin >> letter;

		if (checkGuess(letter, month, hide_m)==0)
		{
			message = "Incorrect letter.";
			NUM_TRY = NUM_TRY - 1;
		}
		else
		{
			message = "NICE! You guess a letter";
		}



		if (month==hide_m)
		{
			message = "Congratulations! You got it!";
			main_menu();
			cout << "\n\t\t\t\tThe month is : " << month << endl;
			break;
		}
	}

	// if no tries left
	if(NUM_TRY == 0)
	{
		message = "NOOOOOOO!...you've been hanged.";
		main_menu();
		cout << "\n\t\t\t\tThe month was : " << month << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

// function to check whether the letter guessed is correct or not.
int checkGuess (char guess, string secretmonth, string &guessmonth)
{
	int i;
	int matches=0;
	int len=secretmonth.length();
	for (i = 0; i< len; i++)
	{

		if (guess == guessmonth[i])
			return 0;

		if (guess == secretmonth[i])
		{
			guessmonth[i] = guess;
			matches++;
		}
	}
	return matches;
}

void main_menu()
{
	 system("color 05");
                system("clear");
                 cout<<"\t\t\t\t*\t*";

  cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";

 cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\t\t\tHangman Game!";
				cout << "\n\t\tYou have " << NUM_TRY << " tries to try and guess the month.";
				cout<<"\n\n\t\t\t\t"+message;
 cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

}