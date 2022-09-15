#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;

class MEDICAL
{
public:

    void DEMAND();
    void DELETE();
    void UPDATE();
	void RECORD();
	void SUMMARY();
	void EXIT();
	MEDICAL();           //constuctor

};

 MEDICAL::MEDICAL ()
{

}


struct SCOPE
{
	int Receipt;
	string Cust_name;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string List_medicines[10]={"Royal Propollen","Burnex","Fabuloss 5","Probiotics","Vitamin C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Acid Free C(500mg)"};
	double Medicine[10] = {9.00,2.00,10.00,4.00,10.00,5.00,8.00,4.00,7.00,5.00};
	double TOTAL;

	SCOPE *prev;
	SCOPE *next;
	SCOPE *link;

}*q, *temp;				//pointer declaration


SCOPE *start_ptr = NULL;
SCOPE *head = NULL;
SCOPE *last = NULL;

int main()	// Main function
{

	system("COLOR 0");		//Color to change background
	MEDICAL drug;
	int home;
	do
	{
		system("clear");
		cout<<"\t\t\t    MEDICAL STORE  \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t||\t1. Order the medicines \t\t\t ||\n";
		cout<<"\t\t||\t2. Delete the order\t\t\t ||\n";
		cout<<"\t\t||\t3. Update the order \t\t\t ||\n";
		cout<<"\t\t||\t4. Payment and Receipt \t\t\t ||\n";
		cout<<"\t\t||\t5. Total sale summary per day \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";

		cout<<"Choose option: ";

		cin>>home;

		switch (home)
		{
		case 1:
			{
				drug.DEMAND();	//function add
				break;
			}	//end case 1


		case 2:
			{
				drug.DELETE();	//function delete
				system("PAUSE");
				break;
			}	//end case 2

		case 3:
			{
				drug.UPDATE();	//function UPDATE
				system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
			drug.RECORD();	//function order
				system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				drug.SUMMARY();	//function SUMMARY
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				drug.EXIT();	//function exit
				goto a;
				break;
			}	//end case 6


		default:
			{
				cout<<"Invalid input. Enter a valid entry\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(home!=6);//end do
	a://goto
	cout<<"Thank you"<<endl;
	system ("PAUSE");
	return 0;
}//end  main function


void MEDICAL::DEMAND()		//function to DEMAND
{
	system("clear");
	int i;
    int CHOICE, QUANTITY, PRICE,NONE;

	cout <<"\nADD DETAILS\n";
	cout <<"_____________________________________ \n\n";

	SCOPE *temporary;
	temporary=new SCOPE;

				cout<<"MEDICINES ID"<<"\tMEDICINES TYPE"<<"\t\tMEDICINES NAME" <<"MEDICINES PRICE(RM)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RM 3.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			RM 2.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"    RM 1.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		RM 4.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 7.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"		    	RM 4.00"<<endl;//1353fn
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	     	RM 1.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
                cout<<" "<<endl;

	temporary = new SCOPE;
	cout << "Enter order number: ";
    cin >> temp->Receipt;
	cout<< "Enter Customer Name: ";
	cin>> temp->Cust_name;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "Number of medicines you want to order:"<< endl;
	cout<<"( Maximum quantity is 10 for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The quantity you order exceed the limit !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Name of the medicine: " <<temp->List_medicines[temp->menu2[i]-1]<<endl;
        cout << "Number of medicines: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "Total amount to pay is: " << temp->amount[i]<<" RM"<<endl;
        system("PAUSE");

	}
    cout << "Order submission Successfull"<<endl;
    cout << "Visit receipt menu to pay bill"<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("clear");
}
}//End function DEMAND


void MEDICAL::RECORD()		//Function to display receipt
{
	int i, num, num2;
	bool found;			//variable to search
	system("clear");
	SCOPE *temp;

	temp=start_ptr;
	found = false;

	cout<<" Enter the Receipt Number To Print The Receipt\n";
	cin>>num2;
	cout<<"\n";
	cout <<"\t\tHere is the Order list\n";


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->Receipt==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Receipt Number : "<<temp->Receipt;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->Cust_name<<endl;

		cout<<"Order Date : "<<temp->date<<endl;

		cout << "|  Type of medicine |     Name of medicine    |  	Quantity     |    Total Price |" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->List_medicines[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" RM"<<endl;
		}

		temp->TOTAL = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->TOTAL;
		cout<<"\n";
		cout << "Enter the amount to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment recieved\nThank You\n";
		}


}
}	//End function RECORD


void MEDICAL::DELETE()	//function to DELETE
{
	system("clear");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    SCOPE *q;
	SCOPE *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->Receipt == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Receipt is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

		while((!found) && (q != NULL))
		{
  			if(q->Receipt != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				delete q;
				cout<<"The Receipt is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		}
}	//End function DELETE



void MEDICAL::UPDATE()		//function to UPDATE order
{
 system("clear");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To UPDATE: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO UPDATE..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->Receipt==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->Receipt;
	cout<< "Change Customer Name: ";
	cin>> temp->Cust_name;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->List_medicines[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After UPDATE  is: " << temp->amount[i]<<" RM"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("clear");

	}

 cout<<"RECORD UPDATED....!"<<endl;
 }
 else
 {
 	if(temp != NULL && temp->Receipt != sid)
 	{
 	cout<<"Invalid Receipt Number...!"<<endl;
    }
 }
}
}
}		//End UPDATE function



void MEDICAL::SUMMARY()		//Function to display Daily Summary
{
	int i,num;
	system("clear");
	SCOPE *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tNo such order is available\n\t\t\tEmpty list\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{

				cout <<"Receipt Number : "<<temp->Receipt;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->Cust_name<<endl;

				cout<<"Order Date : "<<temp->date<<endl;


				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->List_medicines[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RM"<<endl;
			}

			temp->TOTAL = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->TOTAL;

			cout <<"\n";


			temp=temp->next;
		}
	}
}		//End daily summary
void MEDICAL::EXIT() //Function to exit
{
	cout<<"\nEND OF THE SYSTEM.\n"<<endl;
}