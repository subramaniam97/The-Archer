#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void main()
{
    clrscr();
    int a,b;
    ofstream fout;
    fout.open("ak47",ios::out);
    a=1;
    b=1;
    char c[10]="creator";
    fout<<a<<" "<<b<<" "<<c<<endl;
    fout.close();
    getch();
}
