// name: Jemmy Seang
// unikey: jsea2356

#include <iostream>
using namespace std;

char tttboard[3][3] = { '1', '2', '3', 
                        '4', '5', '6', 
                        '7', '8', '9' };
char cloneboard[3][3] = { ' ', ' ', ' ', 
                        ' ', ' ', ' ', 
                        ' ', ' ', ' ' };
string player1, player2, the_player, binput, res;
char ppl = 'x';
int int_binput, int_res, win = 0, count = 0;

void welcome_msg()
{
    cout << " ~~ Tic Tac Toe (Demo 2) by Jemmy Seang ~~" << endl;

	cout << "--> Player 1 Name: ";
	getline(cin, player1); the_player = player1;
	cout << "--> Player 2 Name: ";
	getline(cin, player2);
    
    cout << endl << " << Welcome " << player1 << "(x) and " << player2 << "(o) >>" << endl;
}

void pboard()
{
    cout << endl;
    cout << "\t " << cloneboard[0][0] << " | " << cloneboard[0][1]  << " | " << cloneboard[0][2]  << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << cloneboard[1][0] << " | " <<  cloneboard[1][1]  << " | " << cloneboard[1][2]  << endl;
    cout << "\t-----------" << endl;
    cout << "\t " << cloneboard[2][0] << " | " <<  cloneboard[2][1]  << " | " << cloneboard[2][2]  << endl;
    cout << endl;
}

void my_input()
{
    cout << "[" << the_player << " (" << ppl << ")] Enter a number from 1-9: ";
    retry:
    getline(cin, binput);

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

void switch_ppl()
{
    if (ppl == 'x') {
        ppl = 'o';
        the_player = player2;
    } else {
        ppl = 'x';
        the_player = player1;
    }
}

void status()
{
    if (tttboard[0][0] == tttboard[0][1] && tttboard[0][1] == tttboard[0][2])
    {
        win = 1;
    }

    if (tttboard[1][0] == tttboard[1][1] && tttboard[1][1] == tttboard[1][2])
    {
        win = 1;
    }

    if (tttboard[2][0] == tttboard[2][1] && tttboard[2][1] == tttboard[2][2])
    {
        win = 1;
    }

    if (tttboard[0][0] == tttboard[1][0] && tttboard[1][0] == tttboard[2][0])
    {
        win = 1;
    }

    if (tttboard[0][1] == tttboard[1][1] && tttboard[1][1] == tttboard[2][1])
    {
        win = 1;
    }

    if (tttboard[0][2] == tttboard[1][2] && tttboard[1][2] == tttboard[2][2])
    {
        win = 1;
    }

    if(tttboard[0][0] == tttboard[1][1] &&  tttboard[1][1] == tttboard[2][2])
    {
        win = 1;
    }

    if(tttboard[0][2] == tttboard[1][1] && tttboard[1][1] == tttboard [2][0])
    {
        win = 1;
    }

}

void drawtttboard()
{
    int i = (int_binput-1) / 3 ;
    int j = (int_binput-1) % 3 ;
    
    if (tttboard[i][j] == 'x' or tttboard[i][j] == 'o')
        {
            cout << "[" << the_player << " (" << ppl << ")] Board position is occupied! Try again!" << endl;
        } else {
            tttboard[i][j] = ppl;
            cloneboard[i][j] = ppl;
            status();
            if (win != 1) {
                switch_ppl();
            }
            count++;
            pboard();
        }
}

void restarting()
{
    cout << "[System] Do you want to restart the game? (Enter 0 or 1)" << endl << "[System] --> ";
    retry2:
    getline(cin, res);

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

int main()
{
    system("cls");
    restart:
    welcome_msg();
    pboard();
    while (win != 1)
    {
        my_input();
        drawtttboard();
        
        
        if (win == 1)
        {
            cout << "~~>> Player " << the_player << " (" << ppl << ") wins! <<~~" << endl << endl;
            break;
        }
        if (count == 9) {
            cout << " ~~>> DRAW <<~~" << endl << endl;
            break;
        }
    }

    restarting();
    if (int_res == 1)
    {
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

        goto restart;

    } else {

        cout << endl << " ~~>> BYEEEEEEEEEEEEEEEE <3 <<~~" << endl;
        
    }

    system("pause");
    return 0;
}