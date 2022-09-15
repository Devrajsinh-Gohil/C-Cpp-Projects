#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void points();

int main()
{
    string player;
    int Amount;
    int Amount_bid;
    int let;
    int Dice;
    char option;

    srand(time(0));



 cout<<"\n\t\t JOHNSON CASINO ";

    cout <<"\nEnter the name of the player: ";
    getline(cin, player);

    cout <<"\nEnter the initial amount to deposit: $";
    cin >> Amount;

    do
    {
        system("cls");
        points();
        do
        {
            cout <<"\nWELCOME "<<player<<" READY TO PLAY? "<<"\n\n";
 cout<<"Enter Bid Amount: $";
            cin >> Amount_bid;
            if(Amount_bid > Amount)
                cout <<"Bid amount cannot exceed current amount\n"
                       <<"\nRe-enter the bid Amount: ";
        }while(Amount_bid > Amount);

        do
        {
            cout <<"You are supposed to guess a number from 1 to 10:";
            cin >> let;
            if(let <= 0 || let > 10)
                cout << "\nNumber should lie in between 1 to 10\n"
                    <<"\nGuess the Number Again: ";
        }while(let <= 0 || let > 10);

        Dice = rand()%10 + 1;

        if(Dice == let)
        {
            cout <<"\nCONGRATULATIONS YOU WON " << Amount_bid * 10<<"$";
            Amount = Amount + Amount_bid * 10;
        }
        else
        {
            cout << "SORRY YOU LOOSE "<< Amount_bid <<"$\n";
            Amount = Amount - Amount_bid;
        }

        cout << "\nThe winning number is: " << Dice <<"\n";
        cout << "\n"<<player<<", The remaining amount is: " << Amount << "$\n";
        if(Amount == 0)
        {
            cout << "\nNo Money left to play \n";
            break;
        }
        cout << "\nDo you want to play the game again (y/n)? ";
        cin >> option;
    }while(option =='Y'|| option=='y');

    cout << "Thank You for playing this again.\nYour current amount is: " << Amount << "$";



    return 0;
}

void points()
{
    system("cls");
    cout << "Rules for this game are listed below:";
    cout << "\n1. Enter any number from 1 to 10";
    cout << "\n2. WINNIG AMOUNT= 10X BID_AMOUNT";
    cout << "\n3. LOOSE AMOUNT= BID_AMOUNT";
    cout << "\n4. You are free to leave this game anytime";
}