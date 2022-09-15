#include<fstream>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class ADMINISTRATION
{
	string people;
	public:
	int X()
	{


		cout<<"Enter admin code here:"<<endl;
		cin>>people;
		if(people=="adminA1"||people=="adminA2"||people=="adminA3")
		{

			 int p=encrypt();
			 if (p==1)
			 {
			 	cout<<"LOGIN SUCCESSFUL"<<endl;
			 	return 1;
			 }



		}
		else{
			cout<<"INVALID CREDENTIALS ENTERED. USER NOT FOUND"<<endl;
			X();
			cout<<"LOGIN FAILED"<<endl;
			return 0;
		}
	}
	int encrypt();

};

int ADMINISTRATION::encrypt()
{
	string Y;
	cout<<"ENTER PASSWORD"<<endl;
	cin>>Y;
	if(Y=="gymadmin123")
	{
		cout<<"WELCOME"<<endl;
		return 1;
	}
	else{
		cout<<"LOGIN UNSUCCESSFULL. ENTERED PASSWORD IS INCORRECT"<<endl;
		encrypt();
		return 0;
	}
}
void FUNC1(int G,int C)
{
    if(G!=0)
    {
        cout<<G<<endl;

        cout<<"Gym trainer is alloted\n";
    }
     else
     {
         cout<<"No trainer alloted\n";

     }
}

void FUNC2(int G,int C)
{
    if(C!=0)
    {
        cout<<C<<endl;

        cout<<"Gym trainer is alloted\n";
    }
     else
     {
         cout<<"\nNo trainer alloted\n";
         if(G!=0)
         {
             cout<<"Choose another class\n";
             FUNC1(G,C);
         }

     }
}


int FUNC3(char* Z)
{	char group[10];
    int j,G_C=3,S_C=5;
    strcpy(group,Z);



           		if((G_C!=0) || (S_C)!=0)
                    {




                        if(strcmp(group,"gold")==0)
                        {
                            G_C--;
                            FUNC1(G_C,S_C);

                        }
                        else if(strcmp(group,"silver")==0)
                        {
                            S_C--;
                            FUNC2(G_C,S_C);
                        }

                    }

                    else
                    {

                        cout<<"Trainer is not available\n";
                        return 1;
                    }






}


class candidate
    {
    	int Sr_no,j;
    	char name[50], std[50],timings[50];
    	float Fees;

	long int contact;
    	public:
     int time_slots()
       {
			int T;


			cout<<"Select the time slots \n For morning 6-7 press1 \n For morning 7-8 press2 \n For morning 8-9 press3 \n";
			cout<<" For evening 4-5 press4 \n For evening 5-6 press5 \n For evening 6-7 press6 ";
			cin>>T;
			switch(T)
			{
				case 1:strcpy(timings,"6AM-7AM");break;
				case 2:strcpy(timings,"7AM-8AM");break;
				case 3:strcpy(timings,"8AM-9AM");break;
				case 4:strcpy(timings,"4PM-5PM");break;
				case 5:strcpy(timings,"5PM-6PM");break;
				case 6:strcpy(timings,"6PM-7PM");break;
                default:
                    return 1;
                    break;
			}
}
    	void create_mem()
    	{	int k,l,j;
    		cout<<endl<<"Please Enter The candidate Number: ";
    		cin>>Sr_no;
    		cout<<endl<<"Please Enter The Name of The candidate: ";
    		getchar();
    		cin.getline(name ,50);
    		cout<<endl<<"Please Enter The contact number: ";
    		cin>>contact;
    		cout<<"1.gold class\n 2.silver class\n";
		cout<<"enter the choice\n";
		cin>>k;
		switch (k)
		{
			case 1:{strcpy(std,"gold");
				Fees=2500;
				cout<<"your monthly fee would be: "<<Fees<<endl;
				l=FUNC3(std);
				}
				break;
			case 2:{strcpy(std,"silver");
				Fees=2000;
				cout<<"your monthly fee would be: "<<Fees<<endl;
				l=FUNC3(std);
				}
				break;

		}
		time_slots();
    	}

    	void show_mem()
    	{
    		cout<<endl<<"candidate code: "<<Sr_no;
    		cout<<endl<<"Name: "<<name;
    		cout<<endl<<"category: "<<std;
    		cout<<endl<<"fee: "<<Fees;
    		cout<<endl<<"contact: "<<contact;
    		cout<<endl<<"timings: "<<timings<<endl;
    	}

    	int getmem()
    	{
    		return Sr_no;
    	}

    	float getfee()
    	{
    		return Fees;
    	}

    	char* getName()
    	{
    		return name;
    	}

    	float getcontact()
    	{
    		return contact;
    	}
    };



    fstream fp;
    candidate m1;


    void save_candidate()
    {
    	fp.open("newdata2.dat",ios::out|ios::app);
    	m1.create_mem();
    	fp.write((char*)&m1,sizeof(m1));
    	fp.close();
    	cout<<endl<<endl<<"the candidate has been succesfully added...";
    	getchar();
    }


    void show_all()
    {
    	system("cls");
    	cout<<endl<<"\t\tRECORDS...";
    	fp.open("newdata2.dat",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		m1.show_mem();
    		getchar();
    	}
    	fp.close();

    }




     void display_record(int num)
    {
    	bool found=false;
    	fp.open("newdata2.dat",ios::in);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()==num)
    		{
    			system("cls");
    			m1.show_mem();
    			found=true;
    		}
    	}

    	fp.close();
    	if(found == true)
    	cout<<"\n\nNo record found";
    	getchar();
    }

     void edit_candidate()
    {
    	int num;
    	bool found=false;
    	system("cls");
    	cout<<endl<<endl<<"\tPlease Enter The candidate number: ";
    	cin>>num;

    	fp.open("newdata2.dat",ios::in|ios::out);
    	while(fp.read((char*)&m1,sizeof(m1)) && found==false)
    	{
    		if(m1.getmem()==num)
    		{
    			m1.show_mem();
    			cout<<"\nPlease Enter The New details of the candidate: "<<endl;
    			m1	.create_mem();
    			int pos=1*sizeof(m1);
    			fp.seekp(pos,ios::cur);
    			fp.write((char*)&m1,sizeof(m1));
    			cout<<endl<<endl<<"\t Record Successfully Updated...";
    			found=true;
    		}
    	}
    	fp.close();
    	if(found==false)
    		cout<<endl<<endl<<"Record Not Found...";
    	getchar();
    }



    void delete_candidate()
    {
    	int num;
    	system("cls");
    	cout<<endl<<endl<<"Please Enter The candidate number: ";
    	cin>>num;
    	fp.open("newdata2.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp2.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&m1,sizeof(m1)))
    	{
    		if(m1.getmem()!=num)
    		{
    			fp2.write((char*)&m1,sizeof(m1));
    		}
    	}
    	fp2.close();
    	fp.close();
    	remove("newdata2.dat");
    	rename("Temp2.dat","newdata2.dat");
    	cout<<endl<<endl<<"\tRecord Deleted...";
    	getchar();
    }

     void fnmanage()
    {
    	for(;;)
    	{


    	system("cls");
    	int option;
    	cout<<"\t***********************************************";
    	cout<<"\n\tPress 1 to CREATE candidate";
    	cout<<"\n\tPress 2 to DISPLAY ALL RECORDS";
    	cout<<"\n\tPress 3 to SEARCH FOR A PARTICULAR RECORD ";
    	cout<<"\n\tPress 4 to EDIT candidate DETAILS";
    	cout<<"\n\tPress 5 to DELETE candidate";
    	cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
    	cout<<"\n\t**********************************************";

    	cout<<"\n\n\tOption: ";
    	cin>>option;
    	switch(option)
    	{
    		case 1: system("cls");
    				save_candidate();
    				break;

    		case 2: show_all();
    				break;

    		case 3:
    				int num;
   				system("cls");
    				cout<<"\n\n\tPlease Enter The candidate Number: ";
    				cin>>num;
    				display_record(num);
    				break;

    		case 4: edit_candidate();
    			break;

    		case 5: delete_candidate();
    		        break;

    		case 6: system("cls");
    				break;

    		default:fnmanage();
    		}
    	}
    }


void fitness()
{
	{cout<<"displaying fitness tips..."<<endl;
			std::ifstream f("tips.txt");

			if (f.is_open())
		        {
				std::cout << f.rdbuf();
		        }}
}
void fnuser()
{
	for(;;){
	int m;
	cout<<"1.join gym\n2.quit gym\n3.edit your profile\n";
	cout<<"enter your choice"<<endl;
	cin>>m;
	switch(m)
	{
		case 1:system("cls");
    				save_candidate();
    				break;
    		case 2:delete_candidate();
    		        break;
    		//case 3:fitness();
    		//	break;
    		case 3:edit_candidate();
    		       break;
	}
}
}


int main()
{

		int i,k;
		string name,code;
		cout<<"SELECT MODE"<<endl<<"1.USER"<<endl<<"2.admin"<<endl;
		cin>>i;

			if(i==1){cout<<"you're in user mode"<<endl;
					fnuser();
					}
			if(i==2){cout<<"you're in admin mode"<<endl;

					ADMINISTRATION ad;
					k=ad.X();
					if(k==1)
					{
						fnmanage();
					}
					else
					{
						cout<<"you cannot access manageral details!";
					}


					}


		return 0;
}