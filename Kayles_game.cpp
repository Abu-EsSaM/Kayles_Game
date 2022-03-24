#include <iostream>
#include <cmath>
using namespace std;

//#include <>
void display_board();
using namespace std;
int board[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 } ;
int last_player , num ;
int array_length = sizeof(board)/sizeof(board[0]) ;
bool end_game();
void player_one();
void player_two();
int main() {

    display_board();
    end_game();

    while(end_game() == false)
    {
        player_one();
        player_two();
    }
}

void display_board() {
    cout << "{  " ;
    for (auto i: (board)) {
        if (i == 'X') { cout << 'X' << "  "; }
        else if (i != 'X') { cout << i << "  "; }
    }
    cout << "} \n" ;
}


bool end_game() {
    num = 0;
    for (auto i: (board)) {
        if (i == 'X');
        {
            num += 1;
        }
        if (i == 20)
        {
            cout << "Game Over \n The Winner is " << last_player;
            return true ;
        }
        else
        {
            return false ;
        }
    }
}


void turns()
{
    int turns_number , first_number , second_number ;
    int num  = 0 ;
    cout << "Enter how many numbers you would play ? : \n" ;
    cin >> turns_number ;

    if(turns_number < 1 or turns_number > 2 )
    {
    cout<< "Invalid number! \nplease enter a valid number that is '2' or '1' \n" ;
    turns();
    }

    if(turns_number == 1)
    {
        cout << "Enter The number: \n" ;
        cin >> first_number ;

        // defensive programming for the input of the first number
        while (board[first_number - 1] == 'X')
{
            cout << "This number already token\n Write another number \n" ;
            cin >> first_number ;
}
        // defensive programming for the input of the first number
        while (first_number > 20 or first_number < 1)
{
            cout << "invalid number, enter number between 1 and 20 \n" ;
            cin >> first_number ;
}
    // changing the index of the first number to X
        board[first_number - 1] = 'X' ;
        display_board();
}
    // IF they are 2 turns
    if (turns_number == 2)
{
        // Take the first number from the user
        cout << "Enter the first number: \n" ;
        cin >> first_number ;
        // Make defensive programming to make sure user input a number in the range of array
        while (first_number > 20 or first_number < 1)
{
            cout << "invalid number, enter number between 1 and 20 \n" ;
            cin >> first_number ;
}
        // make defensive programming to make sure the user dont input a number already token
        while (board[first_number - 1] == 'X')
{
            cout << "This number already token\n Write another number \n" ;
            cin >> first_number ;
}
        cout << "Enter the second number: \n" ;
        cin >> second_number ;
        // check if the game ended if he just took the first number only
        for (auto i: (board)) {
            if (i == 'X');
            {
            num += 1;
            }
            if (i == 20)
            {
            cout << "Game Over \n The Winner is " << last_player;
            exit(0);
            }
        }
        //Make defensive programming to make sure user input a number in the range of array
        while (second_number > 20 or second_number < 1)
        {
            cout << "invalid number, enter number between 1 and 20 \n" ;
            cin >> second_number;
        }
        //Make defensive programming to make sure the user dont input a number already token
        while (board[second_number - 1] == 'X')
        {
            cout << "This number already token\n Write another number \n" ;
            cin >> second_number ;
        }
        // If the numbers are ok, they will be removed form board
        if((first_number - second_number) == 1)
        {
            board[first_number - 1] = 'X' ;
            board[second_number - 1] = 'X' ;
            display_board();
        }
        // If the numbers are ok, they will be removed form board
        else if((second_number - first_number) == 1)
        {
            board[first_number - 1] = 'X' ;
            board[second_number - 1] = 'X' ;
            display_board();
        }
        // check if the number aren't after each other then take a new inputs from the user
        else
        {
         while(abs(first_number - second_number) != 1)
        {
            cout << "Enter two numbers one after the other \n";
            cout << "Enter the first number: \n" ;
            cin >> first_number ;
            cout << "Enter the second number: \n" ;
            cin >> second_number ;
            display_board();
        }
        }
        }

}


void player_one()
{
    /*
     This function simply call 2 functions, first is (end_game) to check if the game ended or continue
     playing, second is (turns) that takes the inputs from the user, and if the (game_end) is false
     then it call (turns), at last it saves the last player number in variable called (last_player)
     */
    last_player = 'ONE' ;
     cout << "Player one's turn: \n" ;
    if (end_game() == false)
    {
         turns();
    }
}


void player_two()
{
    /*
     This function simply call 2 functions, first is (end_game) to check if the game ended or continue
     playing, second is (turns) that takes the inputs from the user, and if the (game_end) is false
     then it call (turns), at last it saves the last player number in variable called (last_player)
     */
    last_player = 'TWO' ;
    cout << "Player two's turn: \n" ;
    if (end_game() == false)
    {
        turns();
    }
}
