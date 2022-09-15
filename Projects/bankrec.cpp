#include<iostream>
#include<fstream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
class bank_account
{
private:
    char Acc_no[20];
    char first_name[10];
    char last_name[10];
    float total_Balance;
public:
    void READ();
    void SHOW();
    void WRITE();
    void READ_R();
    void SEARCH_R();
    void EDIT_R();
    void DELETE_R();
};
void bank_account::READ()
{
    cout<<"\nEnter Account Number: ";
    cin>>Acc_no;
    cout<<"Enter First Name: ";
    cin>>first_name;
    cout<<"Enter Last Name: ";
    cin>>last_name;
    cout<<"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}
void bank_account::SHOW()
{
    cout<<"Account Number: "<<Acc_no<<endl;
    cout<<"First Name: "<<first_name<<endl;
    cout<<"Last Name: "<<last_name<<endl;
    cout<<"Current Balance: Rs.  "<<total_Balance<<endl;
    cout<<"-------------------------------"<<endl;
}
void bank_account::WRITE()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    READ();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void bank_account::READ_R()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Data from file****"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)) != \0)
        {
            SHOW();
        }
    }
    infile.close();
}
void bank_account::SEARCH_R()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    SHOW();
}
void bank_account::EDIT_R()
{
    int n;
    fstream iofile;
    iofile.open("record.bank", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    SHOW();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    READ();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void bank_account::DELETE_R()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.bank");
    rename("tmpfile.bank", "record.bank");
}
int main()
{
    bank_account A;
    int choice;
    cout<<"***Acount Information System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.WRITE();
            break;
        case 2:
            A.READ_R();
            break;
        case 3:
            A.SEARCH_R();
            break;
        case 4:
            A.EDIT_R();
            break;
        case 5:
            A.DELETE_R();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";
            exit(0);
        }
    }
    system("pause");
    return 0;
}