#include <iostream>
using namespace std;

char game_elements[10] = {'o','1','2','3','4','5','6','7','8','9'};

int Winner();
void check();

int main()
{
	int plyr = 1,i,C;

    char score;
    do
    {
        check();
        plyr=(plyr%2)?1:2;

        cout << "plyr " << plyr << ", enter a number:  ";
        cin >> C;

        score=(plyr == 1) ? 'X' : 'O';

        if (C == 1 && game_elements[1] == '1')

            game_elements[1] = score;
        else if (C == 2 && game_elements[2] == '2')

            game_elements[2] = score;
        else if (C == 3 && game_elements[3] == '3')

            game_elements[3] = score;
        else if (C == 4 && game_elements[4] == '4')

            game_elements[4] = score;
        else if (C == 5 && game_elements[5] == '5')

            game_elements[5] = score;
        else if (C == 6 && game_elements[6] == '6')

            game_elements[6] = score;
        else if (C == 7 && game_elements[7] == '7')

            game_elements[7] = score;
        else if (C == 8 && game_elements[8] == '8')

            game_elements[8] = score;
        else if (C == 9 && game_elements[9] == '9')

            game_elements[9] = score;
        else
        {
            cout<<"Invalid move ";

            plyr--;
            cin.ignore();
            cin.get();
        }
        i=Winner();

        plyr++;
    }while(i==-1);
    check();
    if(i==1)

        cout<<"==>\aplyr "<<--plyr<<" win ";
    else
        cout<<"==>\agame_elements draw";

    cin.ignore();
    cin.get();
    return 0;
}

/*********************************************
    FUNCTION TO RETURN game_elements STATUS
    1 FOR game_elements IS OVER WITH RESULT
    -1 FOR game_elements IS IN PROGRESS
    O game_elements IS OVER AND NO RESULT
**********************************************/

int Winner()
{
    if (game_elements[1] == game_elements[2] && game_elements[2] == game_elements[3])

        return 1;
    else if (game_elements[4] == game_elements[5] && game_elements[5] == game_elements[6])

        return 1;
    else if (game_elements[7] == game_elements[8] && game_elements[8] == game_elements[9])

        return 1;
    else if (game_elements[1] == game_elements[4] && game_elements[4] == game_elements[7])

        return 1;
    else if (game_elements[2] == game_elements[5] && game_elements[5] == game_elements[8])

        return 1;
    else if (game_elements[3] == game_elements[6] && game_elements[6] == game_elements[9])

        return 1;
    else if (game_elements[1] == game_elements[5] && game_elements[5] == game_elements[9])

        return 1;
    else if (game_elements[3] == game_elements[5] && game_elements[5] == game_elements[7])

        return 1;
    else if (game_elements[1] != '1' && game_elements[2] != '2' && game_elements[3] != '3'
                    && game_elements[4] != '4' && game_elements[5] != '5' && game_elements[6] != '6'
                  && game_elements[7] != '7' && game_elements[8] != '8' && game_elements[9] != '9')

        return 0;
    else
        return -1;
}


/*******************************************************************
     FUNCTION TO DRAW check OF TIC TAC TOE WITH plyrS score
********************************************************************/


void check()
{
    system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "plyr 1 (X)  -  plyr 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << game_elements[1] << "  |  " << game_elements[2] << "  |  " << game_elements[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << game_elements[4] << "  |  " << game_elements[5] << "  |  " << game_elements[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << game_elements[7] << "  |  " << game_elements[8] << "  |  " << game_elements[9] << endl;

    cout << "     |     |     " << endl << endl;
}
/*******************************************************************
                END OF PROJECT
********************************************************************/