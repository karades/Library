#include "Functions.h"
fstream fp,fp1;
book bk;

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
    fp.close();
}
void display_spb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retno(),n)==0)
        {
            bk.show_book();
            flag=1;
        }
    }

    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}
void modify_book()
{
    char n[6];
    int found=0;
    cout<<"\n\nMODIFY BOOK REOCORD.... ";
    cout<<"\n\nEnter The book id of The book" << endl;
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.retno(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book\n"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\n\n Record Updated";
            found=1;
        }
    }

    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}
void delete_book()
{
    char n[6];
    cout<<"\nDELETE BOOK ...";
    cout<<"\n\nEnter The Book id of the Book You Want To Delete : \n";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }

    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    cout<<"\n\nRecord Deleted ..";
    getch();
}
void display_allb()
{

    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\n\nBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getch();
}
void Main_menu()
{

    cout << "MAIN MENU:" << endl;
    cout << "1.ADD BOOK:" << endl;
    cout << "2.MODIFY BOOK:" << endl;
    cout << "3.SHOW SPECIFIC BOOK:" << endl;
    cout << "4.DELETE BOOK:" << endl;
    cout << "5.SHOW ALL BOOKS:" << endl;
    cout << "6.EXIT"<<endl;
    cout << "ENTER YOUR CHOICE (1-6):" << endl;
}
