#include <iostream>
#include <string.h>
using namespace std;

struct HOTEL
{
    int var = 1;
    int jan = 0;
    char name[3][10];
    HOTEL *NEXT;
    HOTEL *PREV;
};
class DEMO
{
    HOTEL *dim[3];
    HOTEL *net;

public:
    DEMO()
    {
        for (int x = 0; x < 3; x++)
            dim[x] = NULL;
    }
    DEMO create()
    {
        for (int x = 0; x< 3; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                HOTEL *nn = new HOTEL;
                nn->NEXT = NULL;
                nn->PREV = NULL;
                if (dim[x] == NULL)
                {
                    dim[x] = nn;
                    nn->var = 1;
                }
                else
                {
                    HOTEL *net = dim[x];
                    while (net->NEXT != NULL)
                    {
                        net = net->NEXT;
                    }
                    if (y == 3 || y == 5 || y == 7 || y == 8)
                    {
                        net->var = 3;
                    }
                    if (y == 2 || y == 4 || y == 6)
                    {
                        net->var = 2;
                    }
                    net->NEXT = nn;
                    nn->PREV = net;
                }
            }
        }
    }
    DEMO display()
    {
        int y = 0, k = 0, l = 0;
        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int x = 1; x < 4; x++)
        {
            cout << "| Floor varber : "<< x << " \t\t";
        }
        cout << "|\n" ;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        net = dim[y];
        HOTEL *sn = dim[y + 1];
         HOTEL *tn = dim[y + 2];
        cout << "\n ";
        while (net != NULL)
        {
            if (net->jan != net->var && net->var != 0)
            {
                y++;
                cout << "| room no : "<< y;
                cout << "->Vacant cots->"<< net->var;
            }
            else
            {
                y++;
                cout << "| room no : "<< y;
                cout << "->Present ";
            }
            if (sn->jan != sn->var && sn->var != 0)
            {
                k++;
                cout << "\t | room no : "<< y;
                cout << "->Vacant cots->"<< sn->var;
            }
            else
            {
                k++;
                cout << " \t | room no : "<< y;
                cout << "->Present ";
            }
            if (tn->jan != tn->var && tn->var != 0)
            {
                l++;
                cout << "\t | room no : "<< y;
                cout << "->Vacant cots->"<< tn->var << "| ";
            }
            else
            {
                l++;
                cout << "\t | room no : "<< y;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int x = 0; x < 48; x++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            net = net->NEXT;
            sn = sn->NEXT;
            tn = tn->NEXT;
        }
    }
    DEMO book(int people)
    {
        int floor, room;
        cout << "\nEnter the floor varber : ";
        cin >> floor;
        try
        {
            if (floor < 0 || floor > 4)

            {
                throw(floor);
            }
            net = dim[floor - 1];

            cout << "\nEnter the room varber : ";
            cin >> room;
            try
            {

                if (room < 0 || room > 10)
                {
                    throw(room);
                }
                else
                {
                    int i = 1;
                    while (i < room)
                    {
                        net = net->NEXT;
                        i++;
                    }
                    if (net->var >= people)
                    {
                        cout << "\nroom is vacant you can apply for room" ;

                        int count = 0;
                        while (net->jan - 1 <= net->var)
                        {

                            cout << "\nEnter name "<< net -> jan + 1 << " : ";

                            cin >> net->name[net->jan];
                            count++;
                            net->jan++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        net->var = net->var - people;
                    }

                    else
                    {
                        cout << "\nroom is not vacant... SORRY !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\ninvalid room varber : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid floor varber : " << r;
        }
    }
    DEMO cancle(int check)
    {
        char namecheck[10];
        int flag = 0;
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)
                    {
                        throw(room);
                    }
                    else
                    {
                        cout << " Enter the name to be delete :";

                        cin >> namecheck;
                        net = dim[check - 1];
                        while (i < room)
                        {
                            net = net->NEXT;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {

                            if (!strcmp(namecheck, net -> name[i]))

                            {
                                flag = 1;
                                break;
                                i = 0;
                            }
                            else
                                i++;
                        }
                        if (flag == 1 && net->jan != 0)
                        {
                            cout << "\nrecord deleted : "<< net -> name[i];

                            net->name[i][0] ='A';
                            net->name[i][1] ='\0';
                            net->jan--;
                            net->var++;
                        }
                        else

                            cout << "\nrecord not present ";
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room varber : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << " \n floor dosn't exist : " << r;
        }
    }
    DEMO upgrade(int check)
    {
        char namecheck[10];
        int room, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)

                    {
                        throw(room);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";

                        cin >> namecheck;
                        net = dim[check - 1];
                        while (i < room)
                        {
                            net = net->NEXT;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {
                            if (!strcmp(namecheck, net -> name[i]))

                            {
                                cout << "\nenter updated name : " ;

                                cin >> net->name[i];
                                break;
                            }
                            else
                                i++;
                        }
                        if (i >= 3)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : "<< namecheck << "\nupdated name : "<< net->name[i];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room varber : "<< r;
                }
            }
        }

        catch (int r)

        {
            cout << "\n floor dosn't exist : "<< r;
        }
    }
};
int main()
{

     DEMO obj;
    int key;
    char ch;
    int floorcheck;
    obj.create();
    do
    {
        cout << "\n1.Book a room for 1 person\n2.Book a room for 2person\n3.Book a room for 3 person\n4.Display the current status of rooms\n5.cancle a cot\n6.upgrade"<< endl;
        cout << " Enter your choice : "   ;
        cin >> key;
        switch (key)
        {
        case 1:
        {
            obj.book(1);
            break;
        }
        case 2:
        {
            obj.book(2);
            break;
        }
        case 3:
        {
            obj.book(3);
            break;
        }
        case 4:
        {
            obj.display();
            break;
        }
        case 5:
        {
            cout << "Enter floor varber : ";
            cin >> floorcheck;
            obj.cancle(floorcheck);
            break;
        }
        case 6:
        {
            cout << "Enter floor varber : ";
            cin >> floorcheck;
            obj.upgrade(floorcheck);
            break;
        }

        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
    } while (ch =='Y'|| ch =='y');
}