#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <iomanip>>
#include "Functions.h"
using namespace std;

int main()
{
    int choice;
    cout << "Library!" << endl;
    do
    {
        Main_menu();
        cin >> choice;
        switch(choice)
        {
        case 1:
            write_book();
            break;
        case 2:
            modify_book();
            break;
        case 3:
            char bnum[10];
            cout <<"\n ENTER BOOK ID:\n" << endl;
            cin >> bnum;
            display_spb(bnum);
            break;
        case 4:
            delete_book();
            break;
        case 5:
            display_allb();
            break;
        case 6:

        default:
            cout<<"\a";
        }
    }
    while(choice!=6);
    cout << "SEE YOU NEXT TIME"<<endl;
         return(1337);
}
