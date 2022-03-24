'''
Kayles game
Student: Mohamed Essam El-Din Hassan        ID:20210579
'''

'''
This Game is 2 players game and they have 20 numbers in front of them
They are playing by taking one or two numbers from the board
If the player took two numbers, he can only take two numbers after each other
'''
import math
board = [ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 ]
last_player = 0
def display_board():
    '''
    This function used in displaying the game board
    '''
    print(board)
    print("Rules: please players know that every player can choose one or two numbers, no more no less."
     + "\n know that the first '0' that after the first '9' is 10 then 11 then 12 and so on"
    " untill the last '0' that is 20 ")
display_board()    

def end_game():
    '''
    This function is a condition that check if the game ended or not,
    and return value True if the game ended and return False if the game didn't,
    and also print game over and the winner name if the game ended,
    and move to player one or player two if the game didn't end.
    '''
    num = 0
    for i in (board):
        if i == 'X':
            num += 1
    if num == 20:
        print("Game Over\n" + " player " + last_player + " win" )
        return True
    else:
        return False  
def turns():
    '''
    This function ask the player if he want to play one or two time and if he want one time,
    then it will ask him for a number and if he want two numbers then it will ask him for,
    and we shouldn't forget that it has a lot of defensive programming
    '''
    global turns_number 
    turns_number = int(input("Enter how many numbers you would play ? : "))

    if turns_number < 1 or turns_number > 2 :
        print("Invalid number! \nplease enter a valid number that is '2' or '1' ")
        turns()     
   
    if turns_number == 1 :
        first_number = int(input("Enter the number: "))

        while board[first_number - 1] == 'X' :
            print ("This number already token\n Write another number")
            first_number = int(input("Enter the number: "))

        while first_number > 20 or first_number < 1 :
            print("invalid number, enter number between 1 and 20")
            first_number = int(input("Enter the number: "))

        board[first_number - 1] = 'X'
        print(board)

    elif turns_number == 2 :
        first_number = int(input("Enter the first number: "))

        while first_number > 20 or first_number < 1 :
            print("invalid number, enter number between 1 and 20")
            first_number = int(input("Enter the first number: "))

        while board[first_number - 1] == 'X' :
            print ("This number already token\n Write another number")
            first_number = int(input("Enter the first number: "))

        second_number = int(input("Enter the second number: "))

        while second_number > 20 or second_number < 1 :
            print("invalid number, enter number between 1 and 20")
            second_number = int(input("Enter the second number: "))    

        num = 0
        for i in (board):
            if i == 'X':
                num += 1
        if num == 20:
            print("Player Two Win")
            exit
        else:
            num = 0
        while board[second_number - 1] == 'X' :
            print ("This number already token\n Write another number")
            second_number = int(input("Enter the second number: "))


        if (first_number - second_number) == 1 :
            board[first_number - 1] = 'X'
            board[second_number - 1] = 'X'
            print(board)

        elif (second_number - first_number) == 1 :
            board[first_number - 1] = 'X'
            board[second_number - 1] = 'X'
            print(board)

        else :
            while abs(first_number - second_number) != 1:
                print("Enter two numbers one after the other ") 
                first_number = int(input("Enter the first number: "))            
                second_number = int(input("Enter the second number: "))
                print(board)                
def player_one():
    '''
    This function simply call 2 functions, first is (end_game) to check if the game ended or continue
    playing, second is (turns) that takes the inputs from the user, and if the (game_end) is false
    then it call (turns), at last it saves the last player number in variable called (last_player) 
    '''
    global last_player
    last_player = 'one'
    print("Player one's turn")
    if end_game() == False :
        turns()


def player_two():
    '''
    This function simply call 2 functions, first is (end_game) to check if the game ended or continue
    playing, second is (turns) that takes the inputs from the user, and if the (game_end) is false
    then it call (turns), at last it saves the last player number in variable called (last_player) 
    '''    
    global last_player
    last_player = 'two'
    print("Player two's turn")
    if end_game() == False :
        turns()
       
            
while end_game() == False :
    '''
    This The loop that begin's the game and it will call (player_one) to begin
    '''
    player_one()
    player_two()
    
    