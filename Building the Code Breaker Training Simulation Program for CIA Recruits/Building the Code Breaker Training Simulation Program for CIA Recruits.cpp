// KeyWords-II.cpp : Defines the entry point for the console application.
//


#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
#include <cctype>

using namespace std;

char again = 'y';
string Name;
const int MaxWrong = 8;
int numwrongwords = 0;
int numrightwords = 0;
int numtotalwords = 0;

int main()
{
	// Display Title of program to user
	cout << "Code Breaker Training Simulation Program for CIA Recruits" << endl;
	// Ask the recruit to login using thier name
	cout << "Enter your name: ";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> Name;
	// Display an overview of what Keywords II is to the recruit 
	cout << "\nWelcome to KeyWords II: Code breaking simulation " << "rectruit " << Name << "!\n";
	cout << "You will be decoding multiple words.\n\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "Rectruit " << Name << " You will see a series of dashes indicating the length of the word.\n";
	cout << "You will guess letters that are part of that word you will be shown the letters you have used,\nand where the letters go in the word if they are correct.\n";


	// Create a collection of 10 words you had wrote down manually
	vector<string> wordList;
	wordList.push_back("foxtrot");
	wordList.push_back("computer");
	wordList.push_back("sword");
	wordList.push_back("jacket");
	wordList.push_back("elevator");
	wordList.push_back("swordfish");
	wordList.push_back("tango");
	wordList.push_back("hunter");
	wordList.push_back("keyboard");
	wordList.push_back("alpha");


	vector<string>::iterator myIterator;

	// Create an int var to count the number of simulations being run starting at 1
	int numSim = 1;

	do
	{


		// Display the simulation # is staring to the recruit. 
		cout << "you are on simulation # " << numSim;
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 


		srand(static_cast<unsigned int>(time(0)));

		for (int i = 0; i < 3; i++)
		{
			random_shuffle(wordList.begin(), wordList.end());

			const string TheWord = wordList[0];
			string soFar(TheWord.size(), '-');
			string used = "";
			int wrong = 0;

			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MaxWrong) && (soFar != TheWord))
			{

				//Tell recruit how many incorrect guesses he or she has left

				cout << "\n\nYou have " << (MaxWrong - wrong) << " wrong guesses left" << endl;

				//     Show recruit the letters he or she has guessed
				cout << "\nYou have used the following letters: \n" << used << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "\nSo far you the word is:\n" << soFar << endl;
				//     Get recruit's next guess
				char guess;
				cout << "Enter your guess: ";
				cin >> guess;
				tolower(guess);

				//     While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//          Get recruit ’s guess

					cout << "\nYou've already guessed" << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					tolower(guess);
				}

				//     Add the new guess to the group of used letters
				used += guess;
				//     If the guess is in the secret word
				if (TheWord.find(guess) != string::npos)
				{

					//          Tell the recruit the guess is correct
					cout << "Thats correct " << guess << " is in the word\n";

					//     Update the word guessed so far with the new letter
					for (int i = 0; i < TheWord.length(); ++i)
					{
						if (TheWord[i] == guess) {

							soFar[i] = guess;
						}
					}

				}
				//     Otherwise
				else
				{
					//Tell the recruit the guess is incorrect
					cout << "Sorry " << toupper(guess) << " isnt in the word.\n";
					//Increment the number of incorrect guesses the recruit has made
					++wrong;

				}

			}

			// If the recruit has made too many incorrect guesses
			if (wrong == MaxWrong)
			{
				//     Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nYou have FAILED";
				++numwrongwords;

			}
			else// Otherwise
			{
				//     Congratulate the recruit on guessing the secret words
				cout << "\nYou guessed it";
				++numrightwords;
			}
			++numtotalwords;
		}

		// Ask the recruit if they would like to run the simulation again
		cout << "\nWould you like to run it again? (y/n)";
		cin >> again;
		// If the recruit wants to run the simulation again
		if ((again == 'y'))
		{
			//     Increment the number of simiulations ran counter
			numSim++;
		}
		//Move program execution back up to // Display the simulation # is staring to the recruit. 
	} while ((again == 'y'));

	// Otherwise 

	//  Display End of Simulations to the recruit
	cout << "\nYou ran the simulation " << numSim << " times\n";
	cout << "You got " << numrightwords << " words correct\n";
	cout << "and you got " << numwrongwords << " words incorrect\n";
	cout << "out of  " << numtotalwords << " words\n";

	// Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}