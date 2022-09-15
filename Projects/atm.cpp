#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    double B , D , W;
    int choice;
    B=100; //default balance
    do{

	cout<<"\n\t***************MENU***************";

	cout<<"\n\t*                                *";

	cout<<"\n\t*      1. Check Balance          *";

	cout<<"\n\t*      2. Deposit                *";

	cout<<"\n\t*      3. Withdraw               *";

	cout<<"\n\t*      4. Transfer               *";

	cout<<"\n\t*      5. Exit                   *";

	cout<<"\n\t*                                *";

	cout<<"\n\t**********************************";

	cout<<"\n\t Please Choose an option: ";

	cin>>choice;

	switch(choice)

	{

		case 1:

			cout<<"\n\tYour Balance is: INR "<<B<<endl;

			break;

		case 2:

			cout<<"\n\tAmount You Want to deposit: INR";

			cin>>D;

			B += D; // balance =balance + deposit;

			cout<<"\n\t Your Current Balance : INR "<<B<<endl;

			break;

		case 3:

			cout<<"\n\tHow much do you want to withdraw? INR ";

               cin>>W;

			if(B<W)

			   cout<<"\n\tYou do not have enough money in your account to withdraw"<<endl;

			else

			B -= W; // balance =balance - deposit;

			cout<<"\n\t Your Current Balance : INR "<<B<<endl;

			break;

		case 4:

			cout<<"\n\t This Service is Currently Not Available!!!"<<endl;

			break;

		default:

			if(choice !=5)

			cout<<"\n\t Invalid option Please Try Again"<<endl;

			break;



			}



}while(choice !=5);

system("pause");



	return 0;

	getch();

}