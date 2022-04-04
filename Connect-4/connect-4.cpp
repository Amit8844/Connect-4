#include <iostream>
#include <stdlib.h>


using namespace std;

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define YELLOW  "\033[33m"      /* Yellow */

//********************* PRINT LOGO ****************************************************

void PrintLogo()
{

    cout << YELLOW << R"(




                                                             $$$$$$\                                                      $$\                 ##\   ##\ 
                                                            $$  __$$\                                                     $$ |                ## |  ## |
                                                            $$ /  \__| @@@@@@\  $$$$$$$\  @@@@@@@\   $$$$$$\   $$$$$$$\ $$$$$$\               ## |  ## |
                                                            $$ |      @@  __@@\ $$  __$$\ @@  __@@\ $$  __$$\ $$  _____|\_$$  _|   |****\     ######## |
                                                            $$ |      @@ /  @@ |$$ |  $$ |@@ |  @@ |$$$$$$$$ |$$ /        $$ |     |****/     \_____#####|
                                                            $$ |  $$\ @@ |  @@ |$$ |  $$ |@@ |  @@ |$$   ____|$$ |        $$ |$$\                   ## |
                                                            \$$$$$$  |\@@@@@@  |$$ |  $$ |@@ |  @@ |\$$$$$$$\ \$$$$$$$\   \$$$$  |                  ## |
                                                             \______/  \______/ \__|  \__|\__|  \__| \_______| \_______|   \____/                   \__|
)"
<< "\n"
<< GREEN << "                                                                                                                                Made by @_Amit"
<< "\n\n";
}

//************************ WELOCME *****************************************************

void WelcomeScreen() {
    cout << BLUE;

    cout << YELLOW << "\n\nHow To Play:-\n\n "
    << BLUE<<"1. Game will always start with player-1 i.e. Red(R)\n2. In Each turn choose the column number in Which you want to drop the Token.\n3. Rows will be filled from bottom to top in every column.\n\n\n";
    cout << GREEN;

    cout << WHITE << "\n\n";
};

//**************************** INITIALIZE BOARD ****************************************

void InitializeBoard(char board[8][7])
{
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 7; j++)
        {
            if (i < 6) board[i][j] = 'O';
            else if (i == 6) board[i][j] = '-';
            else if (i == 7) board[i][j] = '0' + (j + 1);
        }

    }
};

//**************************** PRINT IN BOARD ****************************************

void PrintBoard(char board[8][7])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == 'R')
            {
                cout << RED << board[i][j] << " ";
            }
            else if (board[i][j] == 'B')
            {
                cout << BLUE << board[i][j] << " ";
            }
            else {
                cout << WHITE << board[i][j] << " ";
            }

            cout << "| ";

        }
        cout << "\n";

    }
    cout << WHITE << "\n";


}

//**************************** FOR RED **************************************************

bool EnterRedToken(int col, char board[8][7]) {
    col--;
    if (board[0][col] != 'O') {
        cout << "This Column is Full. Please Select Another.\n";
        return true;
    }
    else {
        for (int i = 5; i >= 0; i--) {
            if (board[i][col] == 'O') {
                board[i][col] = 'R';
                break;
            }
        }
        return false;
    }
};

//************************** FOR BLUE **************************************************

bool EnterBlueToken(int col, char board[8][7]) {
    col--;
    if (board[0][col] != 'O') {
        cout << "\nThis column is full. Please Select another.\n";
        return true;
    }
    else {
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][col] == 'O')
            {
                board[i][col] = 'B';
                break;
            }
        }
        return false;
    }
};

//************************** GAME START **************************************************

bool StartGame() {
    cout << YELLOW << "START GAME  (Y/N) :   ";
    char input;
    cin >> input;
    if (input == 'N') {
        cout << "\n***********************************  THANKS FOR PLAYING *********************************************\n\n";
        return false;
    }
    else if (input != 'Y') {
        cout << "\nPlease Enter correct input \n\n";
        StartGame();
    }
    else {
        return true;
    }
};

//******************* CONDITIONS FOR WIN ***************************************************

bool CheckForWin(char Player, char board[8][7]) {
    bool win = false;

    for (int i = 5; i >= 0; i--) {
        for (int j = 6; j >= 0; j--) {
            if (board[i][j] == Player &&
                board[i - 1][j - 1] == Player &&
                board[i - 2][j - 2] == Player &&
                board[i - 3][j - 3] == Player)
            {
                win = true;
            }

            if (board[i][j] == Player &&
                board[i][j - 1] == Player &&
                board[i][j - 2] == Player &&
                board[i][j - 3] == Player) {
                win = true;
            }

            if (board[i][j] == Player &&
                board[i - 1][j] == Player &&
                board[i - 2][j] == Player &&
                board[i - 3][j] == Player)
            {
                win = true;
            }

            if (board[i][j] == Player &&
                board[i - 1][j + 1] == Player &&
                board[i - 2][j + 2] == Player &&
                board[i - 3][j + 3] == Player)
            {
                win = true;
            }

            if (board[i][j] == Player &&
                board[i][j + 1] == Player &&
                board[i][j + 2] == Player &&
                board[i][j + 3] == Player)
            {
                win = true;
            }
        }
    }

    return win;

};


// ****************************** MAIN ******************************************************************


int main()
{
    PrintLogo();
    WelcomeScreen();
    char board[8][7];
    InitializeBoard(board);



    bool GameEnds = false;
    bool RedTurn = true;
    bool BlueTurn = false;

    if (!StartGame()) {
        return 0;
    }

    while (!GameEnds) {
        // CLEAR SCREEN
        cout << WHITE << "\033[2J\033[0;0H";

        if (RedTurn)      //********* FOR RED TURN *****************
        {
            PrintBoard(board);
            cout << RED << "Player - 1 (RED)\n";
            cout << RED << "RED !!!!" << GREEN << "Enter Column Number to Drop your Token :  ";

            int r;
            cin >> r;
            RedTurn = EnterRedToken(r, board);
            bool won = CheckForWin('R', board);
            if (won) {
                GameEnds = true;
                cout << RED << "\nPlayer - 1 (Red) Won the Game!!!\n\n";
                PrintBoard(board);
                continue;
            }
            BlueTurn = !RedTurn;
            if (RedTurn) continue;
        }

        if (BlueTurn)       //********** For Blue Turn ****************
        {
            PrintBoard(board);
            cout << BLUE << "Player - 2 (BLUE)\n";
            cout << BLUE << "Blue !!!" << YELLOW << " Enter Column Number to Drop your Token:  ";

            int b;
            cin >> b;
            BlueTurn = EnterBlueToken(b, board);
            bool won = CheckForWin('B', board);
            if (won) {
                GameEnds = true;
                cout << BLUE << "\nPlayer - 2 (Blue) Won the Game!!!\n\n";
                PrintBoard(board);
                continue;
            }
            RedTurn = !BlueTurn;
            if (BlueTurn) continue;
        }

    }
}