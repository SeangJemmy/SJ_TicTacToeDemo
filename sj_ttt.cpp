// name: Jemmy Seang
// unikey: jsea2356

#include <iostream>
#include <unistd.h>
using namespace std;

char tttboard[3][3] = { '1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9' }; // Original Board Array
char cloneboard[3][3] = { ' ', ' ', ' ',
                        ' ', ' ', ' ',
                        ' ', ' ', ' ' }; // A clone to original board to display empty board
string player1, player2, the_player, binput, res; // player names, player's turn, board input and restart status 
char ppl = 'x'; // initiate with x
int int_binput, int_res, win = 0, count = 0; // board input and restart input as int, initiate win and count with 0

void welcome_msg() // print out banners and ask player names
{
    cout << " ~~ Tic Tac Toe (Demo 3) by Jemmy Seang ~~" << endl;

	cout << "--> Player 1 Name: ";
	getline(cin, player1); the_player = player1;
	cout << "--> Player 2 Name: ";
	getline(cin, player2);

    cout << endl << " << Welcome " << player1 << "(x) and " << player2 << "(o) >>" << endl;
}

void pboard() // print board function
{
    cout << endl;
    cout << "\t " << cloneboard[0][0] << " | " << cloneboard[0][1]  << " | " << cloneboard[0][2]  << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << cloneboard[1][0] << " | " <<  cloneboard[1][1]  << " | " << cloneboard[1][2]  << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << cloneboard[2][0] << " | " <<  cloneboard[2][1]  << " | " << cloneboard[2][2]  << endl;
    cout << endl;
}

void my_input() // Prompt player for input on the board
{
    cout << "[" << the_player << " (" << ppl << ")] Enter a number from 1-9: ";
    retry:
    getline(cin, binput);

    // Check if the input is an integer from 1-9 or else try again
    if (binput.length() != 1)
    {
        cout << " -->> Invalid input! Enter a number from 1-9: ";
        goto retry;
    }

    if(isdigit(binput[0]))
    {
        int_binput = stoi(binput);
        if (int_binput < 1 or int_binput > 9)
        {
            cout << " -->> Invalid input! Enter a number from 1-9: ";
            goto retry;
        }
    } else {
        cout << " -->> Invalid input! Enter a number from 1-9: ";
        goto retry;
    }
}

void switch_ppl() // switch between x and o player
{
    if (ppl == 'x') {
        ppl = 'o';
        the_player = player2;
    } else {
        ppl = 'x';
        the_player = player1;
    }
}

void status() // Check win status
{
    if (tttboard[0][0] == tttboard[0][1] && tttboard[0][1] == tttboard[0][2]) // first row containing same x or o
    {
        win = 1;
    }

    if (tttboard[1][0] == tttboard[1][1] && tttboard[1][1] == tttboard[1][2]) // second row containing same x or o
    {
        win = 1;
    }

    if (tttboard[2][0] == tttboard[2][1] && tttboard[2][1] == tttboard[2][2]) // third row containing same x or o
    {
        win = 1;
    }

    if (tttboard[0][0] == tttboard[1][0] && tttboard[1][0] == tttboard[2][0]) // first column containing same x or o
    {
        win = 1;
    }

    if (tttboard[0][1] == tttboard[1][1] && tttboard[1][1] == tttboard[2][1]) // second column containing same x or o
    {
        win = 1;
    }

    if (tttboard[0][2] == tttboard[1][2] && tttboard[1][2] == tttboard[2][2]) // third column containing same x or o
    {
        win = 1;
    }

    if(tttboard[0][0] == tttboard[1][1] &&  tttboard[1][1] == tttboard[2][2]) // check diagonally top left to bottom right containing same x or o
    {
        win = 1;
    }

    if(tttboard[0][2] == tttboard[1][1] && tttboard[1][1] == tttboard [2][0]) // check diagonally top right to bottom left containing same x or o
    {
        win = 1;
    }

}

void drawtttboard() // function that updates the board according to user input
{
    int i = (int_binput-1) / 3 ;
    int j = (int_binput-1) % 3 ;

    if (tttboard[i][j] == 'x' or tttboard[i][j] == 'o') // If the board already containing x or o
        {
            cout << "[" << the_player << " (" << ppl << ")] Board position is occupied! Try again!" << endl;
        } else {
            tttboard[i][j] = ppl; // update the board to x or o
            cloneboard[i][j] = ppl; // clone the update
            status(); // check status if win or not
            if (win != 1) { // if not win, switch player
                switch_ppl();
            }
            count++; // update the count (max is 9)
            pboard(); // display the updated board
        }
}

void restarting() // collect restarting input
{
    cout << "[System] Do you want to restart the game? (Enter 0 or 1)" << endl << "[System] --> ";
    retry2:
    getline(cin, res);

    // check for valid input 0 or 1
    if (res.length() != 1)
    {
        cout << "[System] Invalid input! Enter 0 or 1: ";
        goto retry2;
    }

    if(isdigit(res[0]))
    {
        int_res = stoi(res);
        if (int_res < 0 or int_res > 1)
        {
            cout << "[System] Invalid input! Enter 0 or 1: ";
            goto retry2;
        }
    } else {
        cout << "[System] Invalid input! Enter 0 or 1: ";
        goto retry2;
    }
}

int main() // main program
{
    system("cls"); // clear terminal screen
    restart: // a restart checkpoint
    welcome_msg(); // print welcome banner
    pboard(); // print the empty board
    usleep(0.3*1000000); // pause system for 0.3 seconds (this is optional, I just wanna make it feels like the real game hehe)
    while (win != 1) // run always if not yet win
    {
        my_input(); // get player's input
        usleep(0.2*1000000); // pause system for 0.2 seconds
        c8: // a checkpoint when the count is 8, perform auto input
        drawtttboard(); // update board


        if (win == 1) // if win 
        {
            cout << "[System] ~~>> Player " << the_player << " (" << ppl << ") wins! <<~~" << endl << endl;
            break; // stop the while loop for checking win status and prompt restart
        }

        if (count == 8) // when board has 8 inputs aka count is 8
        {
          for (int i = 0; i < 3; i++)
          {
            for (int j = 0; j < 3; j++) // iterate each element of the board
            {
              if (tttboard[i][j] == 'x' or tttboard[i][j] == 'o') // if the board containg x or o, do nothing
              {} else { 
                // if not, fill it with x or o (this always x since we start with x)
                // but the code still work if u switch the start with o and it will end with o
                int_binput = i*3 + (j + 1);
                cout << "[" << the_player << " (" << ppl << ")] Auto Input: " << int_binput
                << endl;
                break; // stop the for loop
              }
            }
          }
          goto c8; // go to c8 checkpoint to finish auto input
        }

        if (count == 9) // if all the board are filled and no win is triggered
        { 
            cout << "[System] ~~>> DRAW <<~~" << endl << endl;
            break; // stop the game with draw and prompt restart
        }
    }

    restarting(); // collect restart input
    if (int_res == 1) // if it is 1
    {
        // reset game elements to initial state without ending the program
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = i*3 + (j + 1);
                tttboard[i][j] = '0' + num;
                cloneboard[i][j] = ' ';
            }
        }
        ppl = 'x';
        int_binput = int_res = win = count = 0;

        system("cls");
        cout << "[System] Restarting..." << endl;
        usleep(0.5*1000000);

        goto restart;

    } else { 
        
        // if it is 0, stop the program with bye text

        cout << endl << "[System] ~~>> BYEEEEEEEEEEEEEEEE <3 <<~~" << endl;

    }
    system("pause");
    return 0;
}
