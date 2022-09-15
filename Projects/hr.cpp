#include<iostream>
#include<math.h>
#include<cstdlib>
#include<string>

using namespace std;

class INDIVIDUAL
{
     private :

    string F_N;
    string L_N;
    int Identity ;
    double Pay ;
    double Time ;
    double C_P_R ;

        public :

               void A();
               void B();
               void C();
               void D();
               void E();
               void F();
               void G();
               void H();
               void I();
               void J();
    };


class SOCIETY
{
     private :


    INDIVIDUAL var[100] ;
    INDIVIDUAL part[100];
    public :

      void Add_people();
      void Delete_people();
      void Search_people();
      void Update_people();
      void Data();

};
                                   ////global variables declared
int N=0,j=0,X=8248001,Y[100];
bool flag=0;
int  Z[100];
string H[100];
double Sale[100];
int guide=0;


void ::SOCIETY::Add_people() {

        int x;
        char redo;

         do
           {
         N++;
        var[j].A();
        j++;

                     cout<<"\nInformation of the employees is as given below:"<<endl;
                     cout<<"\nFirst Name       Last Name       Personal ID         Pay per year (Euros)";
                     cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
                     //cout<<"naaaaaaaaaaaam"<< n<<endl;
           for(int j=0; j<N; j++){
                                 var[j].B();
                                 }


        cout<<"Want to add information of other employee?"<<endl;
         cin>>redo;
        }
        while((redo=='y'||redo=='Y'));

        }




        void SOCIETY::Delete_people() {

        int empId;
        bool lol;
        char redo1,redo2;
        lol =false;
         lebel:
        cout << "To remove an employee, enter Id: ";

         while(!(cin>>empId))
      {
                   cout << "Enter a number: ";
                   cin.clear ();
                  cin.ignore (1000, '\n'); 
      }




        for ( j = 0; j < N; ++j) {


                if (Y[j]==empId) {
                    var[j]=var[j+1];
                   lol=true;
                     var[j].E();
      cin>>redo2;
       if(redo2=='Y'||redo2=='y'){
        int a;
        a=N;

cout<<"\nInformation of the employees is as given below:"<<endl;
 cout<<"\nFirst Name       Last Name       Personal ID         Pay per year (Euros)";
 cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
        for(int j=0; j<a; j++){

                              var[j].B();
                              cout<<"hahahahah="<<N<<endl;
      a--;
      N=a;
      N++;
                                }


                                              ///      goto lebel1;
                                                    }

     cout <<endl;

                           //Delete function
                                  }

                          }





         if (lol==false) {
             cout<<"Invalid entry. No record of employee with entered Id exist"
                 <<" Do you wish to delete (y/n)?:";
             cin>>redo1;
 if(redo1=='Y'||redo1=='y'){
                              goto lebel;
                              cout<<endl<<endl;
                            }
                 }







}

void SOCIETY::Update_people(){

        int empId;
        char redo1,redo2;

         lebel:
               cout << "ID of employee to modify data: ";

         while(!(cin>>empId))
      {
               cout << "Please  enter a number!  Try again: ";
               cin.clear ();
               cin.ignore (1000, '\n');
      }




      int flag1=0;
for (int j = 0; j < N; ++j) {

                if (Y[j]!=empId) {
                flag1++;

                                 }
                          }


     cout <<endl;
     lebel1:

       for (int j = 0; j < N; ++j) {


                if (Y[j]==empId) {

                   cout<<"matching="<< Y[j];

       flag=true;
       int choice = 0;
       char redo;

        do {
                cout << endl << endl;
               cout << "Enter the option number from the given list:" << endl;
                cout <<"1. Name" << endl;
               cout << "2. Family name" << endl;
               cout << "3. Working hours per week" << endl;
               cout << "4. Payment for one hour" << endl;
               cout << std::endl;

                cin >> choice;
                if (choice == 1) {
                        cout << " Name: ";
                       var[j].G();
                }
                else if (choice == 2) {
                       cout << " Family name: ";
                       var[j].H();
                }
                else if (choice == 3) {
                        cout << " Working hours per week: ";
                         var[j].I();
                }
                else if (choice == 4) {
                        cout << " Payment for one hour: ";
                         var[j].J();
                }
                cout<<"Do you want to update some other information(Y/N)=";
                cin>>redo;
        } while (redo=='y'||redo=='Y');
        }
        }
       int a;
        a=N;
         cout<<"\nThe information of the employees is updated in the system:"<<endl;
         cout<<"\nFirst Name       Last Name       Personal ID         Pay per year (Euros)";
         cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
        for(int i=0; i<a; i++){
        var[i].B();

        cout<<"hahahahah="<<N<<endl;

        }
          }



void ::INDIVIDUAL::G()
{
     cin>>F_N ;
}
void::INDIVIDUAL::H()
{
 cin>>L_N;
}
void::INDIVIDUAL::I()
{
  cin>>Time;
  Pay=Time*C_P_R*52;
}
void::INDIVIDUAL::J()
{
  cin>>C_P_R;
  Pay=Time*C_P_R*52;
}







void SOCIETY::Data() {

 char op;
 bool doMore;
 cout<<"\nChoose the option given below.\n(1. Family name, 2.Pay)?\n"<<endl;
 //cin>>op;
    while(!(cin>>op))
      {
                   cout << "Please  enter a number!  Try again: ";
                   cin.clear ();
                  cin.ignore (1000, '\n');
      }


         switch(op)
         {
           case '1':
                    cout<<"\nSorting will perform on the basis of family name\n"<<endl;
                    for(int i=0;i<=N;i++)
                    {
                     for(int j=i+1;j<=N-1;j++)
                     {
                        if(H[i]>H[i+1])
                        {
                           part[i]=var[i];
                           var[i]=var[j];
                           var[j]=part[i];
                        }
                     }
                    }


                   for(int i=0;i<N;i++)
                   {
                   var[i].B();
                   }
                     cout<<"\nsorted\n";

                    break;
           case'2':
                    cout<<"\nSorting based on Pay\n"<<endl;
                    for(int h=0;h<N;h++)
                    {
                       for(int q=h+1;q<N;q++)
                       {
                    if(Sale[h]>Sale[h+1]);
                     {
                           part[h]=var[h];
                           var[h]=var[q];
                           var[q]=part[h];
                        }
                     }
                    }
                   for(int j=0;j<N;j++)
                   {
                   var[j].B();
                   }
                    cout<<"\nsortedlist is printed above\n";

                    break;
           }
 }



void SOCIETY::Search_people(){
     int c;
     char redo1;
     string familyname;
     double min,max;
      do{
      cout<<"Searching will be done on the basis of given fields (1.family name, 2.Pay), please enter your choice?="<<endl;
      //cin>>c;
       while(!(cin>>c))
      {
                   cout << "Please enter a valid number ";
                   cin.clear ();
                  cin.ignore (1000, '\n');
      }


      if(c==2)

      {
              cout<<"Please define your search range for Pay of employees ."<<endl;
              cout<<"What is minimum Pay for search (S_min)?="<<endl;
              //cin>>min;
               while(!(cin>>min))
      {
                   cout << "Please  enter a valid number: ";
                   cin.clear ();
                  cin.ignore (1000, '\n');
      }
              cout<<"What is maximum Pay for search (S_max)?="<<endl;
              //cin>>max;
               while(!(cin>>max))
      {
                   cout << "Please  enter a valid number: ";
                   cin.clear ();
                  cin.ignore (1000, '\n');
      }
                    int a;
                    a=N;
         cout<<"\nThe information of the employees is added to your database:"<<endl;
 cout<<"\nFirst Name       Last Name       Personal ID         Pay per year (Euros)";
 cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
              for(int i=0; i<N; i++) {


                   if (Z[i]>min && Z[i]<max) {

                                       cout<<"naaaaaaaaaaaam"<< N<<endl;
                                       var[i].C();
                                       cout<<"matching="<< Z[i];
                                           }
                                     }



       }

       else if(c==1)
      {
                    cout<<"Enter the name of the family member ?"<<endl;
                    cin>>familyname;
                    cout<<"\nThe information of the employees is added to your database::"<<endl;
                    cout<<"\nFirst Name       Last Name       Personal ID         Pay per year (Euros)";
                    cout<<"\n--------------   --------------  ------------       -------------------------"<<endl;
        for(int i=0; i<N; i++) {


       if (H[i]==familyname) {

                    cout<<"naaaaaaaaaaaam"<< N<<endl;
                    var[i].C();
                    cout<<"matching="<< Z[i];
                             }
                                 }
      }

      cout<<"\nWant to search more fields (y/n)?\n"<<endl;
               cin>>redo1;
               }while(redo1=='y'||redo1=='Y');


     }


void ::INDIVIDUAL::F() {
     int temp2;
     char temp,temp1;
                                }

void::INDIVIDUAL ::E(){
               cout<<"Want to delete information of the employee"<<F_N<<"\t"<< L_N<< "(y/n)?:";   //Identity=y[i];
                         }


int k=0;
void::INDIVIDUAL ::A(){
             Identity=X;
             X++;
             cout<<N;
          cout<<"First Name=";

         while(!(cin>>F_N))
      {
                   cout << "Please  enter a string!  Try again: ";
                   cin.clear ();
                   cin.ignore (1000, '\n');
      }
                   cout<<"Last Name=";

         while(!(cin>>L_N))
      {
                   cout << "Please  enter a string!  Try again: ";
                   cin.clear ();
                   cin.ignore (1000, '\n');
      }

                   cout<<"Working hours of the employee? =";
           ;
         while(!(cin>>Time))
      {
                  cout << "Please  enter a number!  Try again: ";
                  cin.clear ();
                  cin.ignore (1000, '\n');
      }
                 cout<<"Cost of per hour of the employee ? =";

        while(!(cin>>C_P_R))
      {
                 cout << "Please  enter a number!  Try again: ";
                 cin.clear ();
                 cin.ignore (1000, '\n');
      }

 Pay=C_P_R*52;
 Z[j]= Pay;
 Sale[j]=Pay;
 //H[j]=L_N;
 Y[k]=Identity;

k++;
}

void::INDIVIDUAL ::B(){
                cout<<F_N<<"\t\t"<<L_N<<"\t\t\t"<<Identity<<"\t\t\t"<<Pay<<"\t"<<endl;
                              }



void::INDIVIDUAL ::C(){
                cout<<F_N<<"\t\t"<<L_N<<"\t\t\t"<<Identity<<"\t\t\t"<<Pay<<"\t"<<endl;
                               }



int main()
{



    SOCIETY info ;

   int c;
    char operation,ch;


   do
 {

    cout<<"HUMAN RESOURCE MANAGEMENT SYSTEM";
    cout<<"Enter your choice from the given options:"<<endl<<endl<<endl;
    cout<<"    1. Add new employee"<<endl;
    cout<<"    2. Delete employee information"<<endl;
    cout<<"    3. Update employee information"<<endl;
    cout<<"    4. Make reports based on specific field"<<endl;
    cout<<"    5. Search employee"<<endl;
    cout<<"    6. Quit"<<endl<<endl;


       while(!(cin>>c))
      {
      cout << "Please  enter a number!  Try again: ";
      cin.clear ();
      cin.ignore (1000, '\n');
      }
      switch(c)
  {
  case 1:
                cout<<"\nAdd the information of the new employee"<<endl;
    info.Add_people();
    break;
  case 2:
               info.Delete_people();
               break;
  case 3:
              cout<<"\nEnter the item to delete";
              info.Update_people();
              break;
  case 4:
                cout<<"\nEnter an element to search";
    info.Data();
    break;
  case 5:
             info.Search_people();
            break;
    default :
             cout<<"\nInvalid option try again";

  }
       cout<<"\ndo u want to continue";
      cin>>ch;
 }
 while(ch=='y'||ch=='Y');


    system("pause");
    return 0;
    }