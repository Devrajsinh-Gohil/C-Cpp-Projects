#include<iostream>
#include<ncurses.h>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct CRICKET1
{
char player_name[20],mode[70], INDICA;
int R, S, Total_runs, Total_over, Extras;
};

struct CRICKET2
{
char name[20];
int X,Y,Z;
};
int main()
{

int player_no;
int player_type;
CRICKET1 pl1[3];
CRICKET2 pl2[3];



cout<<"Enter the details of Batsmen:"<<endl;
for (int i=0;i<3;i++)
{
cout<<"Name of the player "<<i+1<<endl;
gets (pl1[i].player_name);
cout<<"Runs scored by the player "<<i+1<<endl;
cin>>pl1[i].R;
cout<<"Overs played by the player"<<i+1<<endl;
cin>>pl1[i].Total_over;
cout<<"Status of the player \nif out (N)or not(Y)"<<endl;
cin>>pl1[i].INDICA;
}



cout<<"Enter the details of Bowlers "<<endl;
for (int i=0;i<3;i++)
{
cout<<"Name of the player "<<i+1<<endl;
gets(pl2[i].name);
cout<<"Runs scored by the player "<<i+1<<endl;
cin>>pl2[i].Y;
cout<<"Wickets taken by the player "<<i+1<<endl;
cin>>pl2[i].Z;
cout<<"Total overs played by the  bowler "<<i+1<<endl;
cin>>pl2[i].X;
}


cout<<"THANKS"<<endl;
xyz:
cout<<"Press 1 to see Batsmen details OR Press 2 to see bowlers details"<<endl;
abc:
cin>>player_type;


switch (player_type)
{


case 1:
cout<<"Enter the batsman number to see his details "<<endl<<endl<<endl;
cin>>player_no;
player_no--;
cout<<"batsman number :"<<player_no+1<<endl;
cout<<"batsman name :";
puts(pl1[player_no].player_name);
cout<<"Runs scored by the batsman :"<<pl1[player_no].R<<endl;
cout<<"Total overs played by the batsman :"<<pl1[player_no].Total_over<<endl;
cout<<"Player status out "<<pl1[player_no].INDICA<<endl;
break;



case 2:
cout<<"Enter the bowlers number to see his details "<<endl<<endl<<endl;
cin>>player_no;
player_no--;
cout<<"Bowlers name :";
puts(pl2[player_no].name);
cout<<"Runs given by the player is :"<<pl2[player_no].Y<<endl;
cout<<"Total overs played by the player :"<<pl2[player_no].X<<endl;
cout<<"Total wickets taken by the user :"<<pl2[player_no].Z<<endl;
break;


default:
cout<<"Enter a valid value"<<endl;
goto abc;
}

cout<<endl<<endl<<endl<<"Do you wish to continue? Y-1 N-2"<<endl;
cin>>player_no;
if (player_no==1)
goto xyz;
else
cout<<"THANKS.....\nPress any key to exit";
getch();
}
