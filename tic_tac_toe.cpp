#include <iostream>
#include <stdlib.h>
using namespace std;

//______________Prototypes_____________
bool horizontal();
bool vertical();
bool diagonal1();
bool diagonal2();
bool isWinner();
void inAarray( string place, char symbol );
void displayShape();
void load();
void store();

//_____________Data Structure__________
const int grid = 3;
char array[ grid ][ grid ];

main()
{
    //_________assigning space character to array________
    for (int r = 0; r < grid; r++)
    {
        for (int c = 0; c < grid; c++)
        {
            array[r][c] = ' ';
        }
    }
    //////////////////////////////////////////////

    char symbol;
    int turn = 0;
    string place;

    cout <<endl <<"Time to play tic tac toe!!!" <<endl;
    
    for (; turn < 9; turn ++)
    {
        displayShape();
        cout <<"Player 'x' place" <<endl;
        symbol = 'x';
        cout <<"Enter the square you want to place your mark: ";
        cin >>place;
        cout <<endl<<endl;
        inAarray( place, symbol );

        if ( isWinner() )
        {
            displayShape();
           cout <<"Player 'x' is the winner.";
           break;
        }
        
        turn ++;
        system("cls");

        displayShape();
        cout <<"Player 'o' place" <<endl;
        symbol = 'o';
        cout <<"Enter the square you want to place your mark: ";
        cin >>place;
        cout <<endl<<endl;
        inAarray( place, symbol );

        if ( isWinner())
        {
            displayShape();
           cout <<"Player 'o' is the winner.";
           break;
        }
    }
}

//___________storing grid into array_________
void inAarray( string place, char symbol )
{
    int row =  int(place[1]);
    row = row - 49;
    int col = int(place[0]);
    col = col - 65;

    if ( array[row][col] == ' ')
    {
        array[row][col] = symbol;
    }
    else
    {
        cout <<"Square already used. You missed your place." <<endl;
    }
}

//____________displaying layout of game__________
void displayShape()
{
    cout <<"   A   B   C" <<endl;
    cout <<"  -------------" <<endl;
    cout <<"1 | "<<array[0][0]<<" | "<<array[0][1]<<" | "<<array[0][2]<<" |" <<endl;
    cout <<"  -------------" <<endl;
    cout <<"2 | "<<array[1][0]<<" | "<<array[1][1]<<" | "<<array[1][2]<<" |" <<endl;
    cout <<"  -------------" <<endl;
    cout <<"3 | "<<array[2][0]<<" | "<<array[2][1]<<" | "<<array[2][2]<<" |" <<endl;
    cout <<"  -------------" <<endl <<endl;
}

//______________Deciding the winner____________
bool isWinner()
{
    if ( horizontal() == 1 || vertical() == 1 || diagonal1() == 1 || diagonal2() == 1 )
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

//______________Checking Horizontal____________
bool horizontal()
{
    bool condition = false;
    int count;

    for (int r = 0; r < grid; r++)
    {
        count = 0;

        for (int c = 1; c < grid; c++)
        {
            if ( array[r][c - 1] != ' ')
            {
                if ( array[r][c - 1] == array[r][c] )
                {
                    count ++;
                }
            }

            if ( count == 2 )
            {
                condition = true;
                break;
            }
        }

        if ( count == 2 )
        {
            condition = true;
            break;
        }
    }
    
    return condition;
}

//______________Checking vertically_____________
bool vertical()
{
    bool condition = false;
    int count;

    for (int c = 1; c < grid; c++)
    {
        count = 0;

        for (int r = 1; r < grid; r++)
        {
            if ( array[r - 1][c - 1] != ' ')
            {
                if ( array[r - 1][c - 1] == array[r][c] )
                {
                    count ++;
                }
            }

            if ( count == 2 )
            {
                condition = true;
                break;
            }
        }

        if ( count == 2 )
        {
            condition = true;
            break;
        }
    }

    return condition;
}

//____________Checking first diagonal___________
bool diagonal1()
{
    bool condition = false;
    int count = 0;

    for (int r = 0; r < (grid - 1); r++)
    {
        for (int c = 0; c < (grid - 1); c++)
        {
            if ( array[r][c] != ' ')
            {
                if ( r == c )
                {
                    if ( array[r][c] == array[r + 1][c + 1])
                    {
                        count ++;
                    }
                }
            }

            if ( count == 2 )
            {
                condition = true;
                break;
            }
        }

        if ( count == 2)
        {
            condition = true;
            break;
        }
    }
    
    return condition;
}

//______________Checking second diagonal_____________
bool diagonal2()
{
    bool condition = false;
    int count = 0;

    for (int r = 1; r < grid - 1; r++)
    {
        for (int c = 2; c >= 0; c--)
        {
            if ( array[r - 1][c] != ' ')
            {
                if ( array[r - 1][c] == array[r][c - 1])
                {
                    count ++;
                }
            }

            if ( count == 2)
            {
                condition = true;
                break;
            }
        }

        if ( count == 2)
        {
            condition = true;
            break;
        }
    }
    
    return condition;
}

