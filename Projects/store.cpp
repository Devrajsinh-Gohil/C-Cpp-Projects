#include<bits/stdc++.h>
#include<iostream>
#include<ncurses.h>
using namespace std;

const int var=20;
  class STORE
  {
      int AMT[var],SUB[var],X,Y,Z,amount1;
      int code,code1,cod[var],S,last;
    public:
       float price,price1;
       STORE(void);
       void TAKEN(void);
       void TOTAL(void);
       void OLD_ADD(void);
       void NEW_ADD(void);
       void DISPLAY(void);
     };
    STORE:: STORE(void)
    { S=0;Y=10;Z=40;last=5;AMT[0]=0;
      for(int X=0;X<last;X++)
      { S=S+1;Z=Z+10;
      cod[X]=S;
     AMT[X]=Y;
      SUB[X]=Z;
      }
     }
   void STORE::OLD_ADD(void)
    {
	cout<<"\nITEM CODE:";
      cin>>code1;
      cout<<"\nITEM COST:";
      cin>>price1;
     for(X=0;X<last;X++)
       { if(code1==cod[X])
      { Y=Y+1;
        AMT[X]=Y;
       SUB[X]=price1;
      }


       }
      }
   void STORE::NEW_ADD(void)
   {    cout<<"\nITEM CODE:";
    cin>>code1;
    cout<<"\nQUANTITY OF ITEM:";
    cin>>amount1;
    cout<<"\nPRICE OF ITEM:";
    cin>>price1;

    cod[last]=code1;
    AMT[last]=amount1;
    SUB[last]=price1;
    last++;
     }
    void STORE::DISPLAY(void)
     { for(X=0;X<last;X++)
    {
      cout<<"\nCODE:"<<cod[X]<<"\t";
      cout<<"\nQUANTITY:"<<AMT[X]<<"\t";
      cout<<"\nPRICE:"<<SUB[X]<<endl;
      }
    }
  void STORE::TAKEN(void)
   {
    cout<<"\nPRODUCT CODE:\n";
    cin>>code;
    cout<<"\nPRODUCT PRICE:\n";
    cin>>price;
    }
  void STORE::TOTAL(void)
   {
     cout<<"\n\nITEM CODE:"<<code<<"\n\nITEM PRICE:"<<price;
   }
  int main()
  {
     STORE d[10];
     static int j=0;
     int x,i=0,p,s=0;

    do{
    cout<<"\n\t\tDEPARTMENT STORE MANAGEMENT SYSTEM\n";
       cout<<"\nChoose from the given list:\n";
       cout<<"\n1. Show all stored items:";
       cout<<"\n2. Add an old item:";
       cout<<"\n3. Add a new item:";
       cout<<"\n4. Sell an item:";
       cout<<"\n5. Total sold:";
       cout<<"\n6. Show total items sold:";
       cout<<"\n7. Quit\n";

      cin>>x;
    switch(x)
    {   case 1: d[i].DISPLAY();
            break;
        case 2: d[i].OLD_ADD();
            d[i].DISPLAY();
            break;
        case 3: d[i].NEW_ADD();
            d[i].DISPLAY();
            break;
        case 4: d[i].TAKEN();
            i++,j++;
            break;
        case 5:{ cout<<"Total sale:";
             s=0;

             for(p=0;p<j;p++)
             { s=s+d[p].price;
             }
             cout<<s;
             cout<<"TK.\n";
             }
             break;
        case 6: for(i=0;i<j;i++)
              {  d[i].TOTAL();
               }
              break;
        case 7: break;
         }
         } while(x!=7);
          getch();
          return 0;
}