#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <iomanip>>
using namespace std;

class book
{
    char no[30];
    char name[50];
    char auth[20];
public:
    void create_book()
    {
        cout<<"\nCreating new book entry\n";
        cout<<"\nEnter book id:\n";
        cin>>no;
        cout<<"\nEnter name of the book:\n";
        cin>>name;
        cout<<"\nEnter author:\n";
        cin>>auth;
    }

    void modify_book()
    {
        cout<<"\nBook id : "<<no;
        cout<<"\nModify Book Name :\n ";
        cin>>name;
        cout<<"\nModify Author's Name of Book :\n ";
        cin>>auth;
    }
    void show_book()
    {
        cout<<"\nBook id : "<<no;
        cout<<"\nBook Name : \n";
        cout<<name;
        cout<<"\nAuthor Name : \n";
        cout<<auth << endl;
    }
    char* retno()
    {
        return no;
    }

    void report()
    {
        cout<<no<<setw(30)<<name<<setw(30)<<auth<<endl;
    }
};

void write_book();
void modify_book();
void delete_book();
void display_allb();
void display_spb(char n[]);
void Main_menu();
#endif
