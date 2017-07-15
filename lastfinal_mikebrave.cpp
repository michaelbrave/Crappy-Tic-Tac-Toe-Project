// final_tictactoe_mikebrave.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

// I had to make the arrays, global, shouldn't cause too much of a problem since there is a funciton to reset when the program starts
int master_num_array[9];
char master_char_array[9];
int playerxturn = 1; // turn counter
bool fullarray[9];
bool firsttime = true;
bool instructionsyes = true;

void clear_screen()
{
	system("cls");
}

int number_check()
{
	// this function was repurposed from the midterm, makes sure it's a number and not a letter
	int num;
	bool error = false;

	do
	{
		cin >> num;

		if (cin.fail())
		{
			error = true;
			cout << "that didn't seem to be a number, try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			error = false;
		}
	} while (error == true);

	return num;
}


// problem with array full
void array_full()
{
	
int tiecounter = 0;

	// if all nine spots are full it becomes a draw
	// [0] == (11 || 10) = full - for all 9
	
for (int i = 0; i < 9; i++)
	{
		if ((master_num_array[i] == 10) || (master_num_array[i] == 11))
		{
			fullarray[i] = true;
		}
	}

	// if all 9 are true
	// there has to be a better way
if ((fullarray[0] == true) && (fullarray[1] == true) && (fullarray[2] == true) && (fullarray[3] == true) && (fullarray[4] == true) && (fullarray[5] == true) && (fullarray[6] == true) && (fullarray[7] == true) && (fullarray[8] == true))
	{
		cout << "all possible locations are filled, it's a draw" << endl;
		playerxturn = 0;
	}
}


void winnerwinner()
{
	// this function is to check after every turn if there is a winner
	bool yesthereis = false;
	bool xwins = false;
	bool owins = false;
	bool tie = false;

	// what are all the ways to win
	// if there are 3 with variables of 11 or 3 variables of 10 in a row
	// see if they line up
	// vertical wins = 1,4,7 or 2,5,8 or 3,6,9 -1 so it's the proper cell
	// horizontal wins = 1,2,3 or 4,5,6 or 7,8,9 -1 so it's the proper cell
	// diagonal wins = 1,5,9 or 7,5,3 -1 so it's the proper cell

	// ways for x to win
	// there has to be a way to make this a loop


	// horizontal wins for x
	if ((master_num_array[0] == 11) && (master_num_array[1] == 11) && (master_num_array[2] == 11))
	{
		xwins = true;
	}
	if ((master_num_array[3] == 11) && (master_num_array[4] == 11) && (master_num_array[5] == 11))
	{
		xwins = true;
	}
	if ((master_num_array[6] == 11) && (master_num_array[7] == 11) && (master_num_array[8] == 11))
	{
		xwins = true;
	}

	// vertical wins for x
	if ((master_num_array[0] == 11) && (master_num_array[3] == 11) && (master_num_array[6] == 11))
	{
		xwins = true;
	}
	if ((master_num_array[1] == 11) && (master_num_array[4] == 11) && (master_num_array[7] == 11))
	{
		xwins = true;
	}
	if ((master_num_array[2] == 11) && (master_num_array[5] == 11) && (master_num_array[8] == 11))
	{
		xwins = true;
	}

	// diagonal wins for x
	if ((master_num_array[0] == 11) && (master_num_array[4] == 11) && (master_num_array[8] == 11))
	{
		xwins = true;
	}
	if ((master_num_array[6] == 11) && (master_num_array[4] == 11) && (master_num_array[2] == 11))
	{
		xwins = true;
	}


	//************** begin o section


	// horizontal wins for o
	if ((master_num_array[0] == 10) && (master_num_array[1] == 10) && (master_num_array[2] == 10))
	{
		owins = true;
	}
	if ((master_num_array[3] == 10) && (master_num_array[4] == 10) && (master_num_array[5] == 10))
	{
		owins = true;
	}
	if ((master_num_array[6] == 10) && (master_num_array[7] == 10) && (master_num_array[8] == 10))
	{
		owins = true;
	}

	// vertical wins for o
	if ((master_num_array[0] == 10) && (master_num_array[3] == 10) && (master_num_array[6] == 10))
	{
		owins = true;
	}
	if ((master_num_array[1] == 10) && (master_num_array[4] == 10) && (master_num_array[7] == 10))
	{
		owins = true;
	}
	if ((master_num_array[2] == 10) && (master_num_array[5] == 10) && (master_num_array[8] == 10))
	{
		owins = true;
	}

	// diagonal wins for o
	if ((master_num_array[0] == 10) && (master_num_array[4] == 10) && (master_num_array[8] == 10))
	{
		owins = true;
	}
	if ((master_num_array[6] == 10) && (master_num_array[4] == 10) && (master_num_array[2] == 10))
	{
		owins = true;
	}

	// tie checker was a sepearate function but quit working, trying to combine it here
	//if (movesleft == 0)
	//{
	//	tie = true;
	//}
	
	//if (tie == true)
	//{
	//	cout << "there is a tie" << endl;
	//	yesthereis = true;
	//}


	// then to declare the winner
	if (owins == true)
	{
		cout << "Congratulations o has won!!!" << endl;
		yesthereis = true;
	}

	if (xwins == true)
	{
		cout << "Congratulations x has won!!!" << endl;
		yesthereis = true;
	}


	if (yesthereis == true)
	{
		playerxturn = 0;
	}

}

int spots_taken()
{ // checks to see if a place in the array is allready filled
	int holdernumber;

	do
	{
		cout << "a number between 1 & 9" << endl;
		holdernumber = number_check(); // sends it to make sure it's actually a number and not a char

		if ((master_num_array[holdernumber - 1] == 10) || (master_num_array[holdernumber - 1] == 11))
		{
			cout << "sorry that spot is allready taken, try a different number between 1-9" << endl;
			holdernumber = number_check();
		}
	} while (holdernumber >= 10 || holdernumber <= 0); // to make sure the range is appropriate

	return holdernumber;
}

void updating_grid()
{
	// ideally will update how the grid looks based on the date stored in placeholder below
	// this function always calls the updated board and shows it
	clear_screen();
	char xmark = 'X';
	char omark = 'O';


	for (int i = 0; i < 9; i++)
	{
		switch (master_num_array[i])
		{
		case 11:
		{
			master_char_array[i] = xmark;
			break;
		}

		case 10:
		{
			master_char_array[i] = omark;
			break;
		}
		}// end of switch

	}// end of for loop

	cout << "you can choose where to place your piece based on this grid" << endl << endl;


	cout << "       |     |      " << endl;
	cout << "    " << master_char_array[0] << "  |  " << master_char_array[1] << "  |  " << master_char_array[2] << "    " << endl;
	cout << "       |     |      " << endl;
	cout << "  ----- ----- ----- " << endl;
	cout << "       |     |      " << endl;
	cout << "    " << master_char_array[3] << "  |  " << master_char_array[4] << "  |  " << master_char_array[5] << "    " << endl;
	cout << "       |     |      " << endl;
	cout << "  ----- ----- ----- " << endl;
	cout << "       |     |      " << endl;
	cout << "    " << master_char_array[6] << "  |  " << master_char_array[7] << "  |  " << master_char_array[8] << "    " << endl;
	cout << "       |     |      " << endl;

	cout << endl << endl;
	cout << "type the corresponding number to location" << endl << endl;
}

void game_start()
{
	char num1 = '1';
	char num2 = '2';
	char num3 = '3';
	char num4 = '4';
	char num5 = '5';
	char num6 = '6';
	char num7 = '7';
	char num8 = '8';
	char num9 = '9';

	if (instructionsyes == true)
	{
		// just the intro menu, should only show up the first time you play
		cout << "Welcome to Tic Tac Toe" << endl;
		cout << "The rules are simple, first one to 3 in a row wins" << endl;
		cout << "X's go first, O's second" << endl;
		cout << "you cannot occupy a space already claimed" << endl;
		cout << "good luck, have fun" << endl << endl;
		system("pause");
	}


	// sets up the initial 1-9 numbers on the grid, one time use in the beginning


	// I need it to loop until all 9 spots are filled
	// each one should populate with just a 1 for [1], 2 for [2] etc
	for (int a = 0; a < 9; a++)
	{
		master_num_array[a] = a + 1;
		
	}
	// now that the values are set, lets set them graphically

	// has to be a better way to initially populate it for display purposes
	master_char_array[0] = num1;
	master_char_array[1] = num2;
	master_char_array[2] = num3;
	master_char_array[3] = num4;
	master_char_array[4] = num5;
	master_char_array[5] = num6;
	master_char_array[6] = num7;
	master_char_array[7] = num8;
	master_char_array[8] = num9;
	// since the array is global now, I don't need to send it up

	
}

void player_choice()
{
	int menu_select;
	bool didyes = false;
	int xoro;

	menu_select = spots_taken(); // check for dupes here, also it sends to other error checks

	switch (menu_select)
	{
	case 1:
	{
		didyes = true;
		break;
	}
	case 2:
	{
		didyes = true;
		break;
	}
	case 3:
	{
		didyes = true;
		break;
	}
	case 4:
	{
		didyes = true;
		break;
	}
	case 5:
	{
		didyes = true;
		break;
	}
	case 6:
	{
		didyes = true;
		break;
	}
	case 7:
	{
		didyes = true;
		break;
	}
	case 8:
	{
		didyes = true;
		break;
	}
	case 9:
	{
		didyes = true;
		break;
	}
	}


	// this gives the value, didn't need to exist in each case, made more useful variables instead
	if (playerxturn == 1) // if it's x's turn
	{
		xoro = 11;
		// output a x
	}
	if (playerxturn == 2) // if it's o's turn
	{
		xoro = 10;
		// output an o
	}
	master_num_array[menu_select - 1] = xoro;
	updating_grid();

	//return didyes;
}

void turns()
{
	// this function is to alternate turns between players

	bool turnyes = false;
	// this one get's passed to determine to display an x or o, could maybe combine with other bool

	do
	{
		// I need a loop that will only run the very first time, for instructions etc, not big enough for it's own function
		if (firsttime == true)
		{
			game_start();
			firsttime = false;
			updating_grid();
			instructionsyes = false;

		}

		// so if they make a selection in player choice, then it will say they took a turn and reset the other players
		while ((playerxturn == 1))
		{
			cout << "player X it's your turn " << endl;
			player_choice(); // allows for input of location on grid
			playerxturn = 2; //reset turn, true is x's turn, false is o's
			winnerwinner(); // check if winner each turn
			array_full(); // check for tie
		}

		// if above worked, playerx should be true, and playerx false (meaning it's o's turn), now for player 2's turn
		while ((playerxturn == 2))
		{
			cout << "player O it's your turn " << endl;
			player_choice();
			playerxturn = 1; // to reset it back to x
			winnerwinner();
			array_full();
		}

	} while (playerxturn != 0);

} // end of turns function

void main()
{
	int exit;

	do
	{
		turns();
		system("pause");
		cout << "press any number to play again, press 0 to exit" << endl;
		cin >> exit;
		if (exit != 0)
		{
			firsttime = true;
			playerxturn = 1;
			clear_screen();
		}

	} while (exit != 0);




}

