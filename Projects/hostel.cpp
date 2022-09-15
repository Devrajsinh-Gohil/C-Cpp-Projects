#include<iostream>
using namespace std;
#include<fstream>
#include<stdio.h>

class Booking

{

    int room;

    char name[30];

    char address[50];

    char phone[10];



    public:

    void main_menu();

    int add();

    void display();

    int rooms();

    int edit();

    int check(int);

    int modify(int);

    int delete_rec(int);

};



void Booking::main_menu()

{



    int choice=0;



    while(choice!=5)

    {
        cout<<"\n\t\t\t\t* HOME *";


        cout<<"\n\n\n\t\t\t1.Book A Room";

        cout<<"\n\t\t\t2.student Record";

        cout<<"\n\t\t\t3.Rooms Allotted";

        cout<<"\n\t\t\t4.Edit Record";

        cout<<"\n\t\t\t5.Exit";

        cout<<"\n\n\t\t\tEnter Your Choice: ";

        cin>>choice;



        switch(choice)

        {

            case 1: add();

                    break;

            case 2: display();

                    break;

            case 3: rooms();

                    break;

            case 4: edit();

                    break;

            case 5: break;

            default:
                    cout<<"\n\n\t\t\tWrong choice!!!";

                    cout<<"\n\t\t\tTo continue press enter";
        }
    }
}
int Booking::add()

{

    int r,flag;

    ofstream fout("Record.txt",ios::app);



    cout<<"\n Enter Customer Detalis";

    cout<<"\n **********************";

    cout<<"\n\n Room no: ";

    cin>>r;

    flag=check(r);



    if(flag)

        cout<<"\n Required room is already booked";

    else

    {

        room=r;

        cout<<"\n Name:\t ";

        cin>>name;

        cout<<"\n Address:\t ";

        cin>>address;

        cout<<"\n Phone No:\t ";

        cin>>phone;

              cout<<endl;

        fout.write((char*)this,sizeof(*this));

        cout<<"\n Room is booked!!!";

    }



    cout<<"\n To continue press enter";

  ;

    fout.close();

    return 0;

}



void Booking::display()

{



    ifstream fin("Record.txt",ios::in);

    int r;

    cout<<"\n Enter room no: ";

    cin>>r;



    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));



           if(room = r)

                 {

            cout<<"\n Cusromer Details";

            cout<<"\n ****************";

            cout<<"\n\n Room no: "<<room;

            cout<<"\n Name: "<<name;

            cout<<"\n Address: "<<address;

            cout<<"\n Phone no: "<<phone;



              }

       else{

        cout<<"\n NOT FOUND";

              cout<<"\n\n To continue press enter";}

    ;

    fin.close();


              }}



int Booking::rooms()

{
    ifstream fin("Record.txt",ios::in);

    cout<<"\n\t\t\tList Of Rooms Allotted";

    cout<<"\n\t\t\t*********************";

    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";



       while(!fin.eof())

    {



        fin.read((char*)this,sizeof(*this));

        cout<<"\n\n "<<room<<"\t\t"<<name;

        cout<<"\t\t"<<address<<"\t\t"<<phone;



       }



    cout<<"\n\n\n\t\t\tTo continue press enter";

       ;

    fin.close();

    return 0;

}



int Booking::edit()

{



    int choice,r;



    cout<<"\n EDIT MENU";

    cout<<"\n *********";

    cout<<"\n\n 1.Modify Customer Record";

    cout<<"\n 2.Delete Customer Record";



    cout<<"\n Enter your choice: ";

    cin>>choice;



       cout<<"\n Enter room no: ";

    cin>>r;





    switch(choice)

    {

        case 1: modify(r);

                break;

        case 2: delete_rec(r);

                break;

        default: cout<<"\n Wrong Choice!!";

    }



    cout<<"\n To continue press enter";

    return 0;

  ;

}



int Booking::check(int r)

{

    int flag=0;

    ifstream fin("Record.txt",ios::in);

    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));

        if(room==r)

        {

            flag=1;

                break;

        }

    }



    fin.close();

    return(flag);

}



int Booking::modify(int r)

{

    long pos , flag;

    fstream file("Record.txt",ios::in|ios::out|ios::binary);

    flag=0;

    while(!file.eof())

       {

         pos=file.tellg();

        file.read((char*)this,sizeof(*this));

        if(room==r)

            {

                cout<<"\n Enter New Details";

                cout<<"\n *****************";

                cout<<"\n Name: ";

                cin>>name;
                cout<<" Address: ";
                cin>>address;
                cout<<" Phone no: ";
                cin>>phone;
                file.seekg(pos);
                file.write((char*)this,sizeof(*this));
                cout<<"\n RECORD UPDATED";
                flag=1;
                break;
            }
        }

    if(flag==0)
              cout<<"\n NOT FOUND";
              file.close();
              return 0;
       }

int Booking::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.txt",ios::out);



    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));

        if(room==r)
        {
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Press 'y' to delete this record else 'n''''': ";
            cin>>ch;

            if(ch=='n')
            {
            fout.write((char*)this,sizeof(*this));
            flag=1;
            }
        }
        else
            fout.write((char*)this,sizeof(*this));
    }

    fin.close();
    fout.close();

    if(flag==0)
    {
            cout<<"\n NOT FOUND";
            return 0;
    }
    else
    {
        remove("Record.txt");
        rename("temp.txt","Record.txt");
        return 1;
    }
}

int main()

{

    Booking h;
    cout<<"\n\t\t\t****************************";

    cout<<"\n\t\t\t* HOSTEL MANAGEMENT PROJECT *";

    cout<<"\n\t\t\t****************************";

//    cout<<"Press any key to continue!!";

    h.main_menu();
}