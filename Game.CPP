#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include "ArcherShape.cpp"
int score=0;
int lvl=1;
int lvs=5;
int aim=1,chan=5;

class spd
{
public:
    int gs,e;
    int arsp;
    int speed;
}obj;

char name[20];
int lvl1;
int points;

void life()
{
    if(lvs<=0)
    {
        cleardevice();
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        outtextxy(getmaxx()/2 - 100,getmaxy()/2 - 100,"GAME OVER");
        gotoxy(20,15);
        cout<<"You have cleared level : "<<lvl-1<<endl;
        gotoxy(20,18);
        cout<<"Your score : "<<score<<endl;
//Highscore storage
        ifstream hs1;
        hs1.open("ak47",ios::in);
        hs1>>lvl1>>points>>name;

        if(lvl1<=lvl)
        {
            if(points<score||lvl1<=lvl)
            {
                hs1.close();
                ofstream hs;
                outtextxy(getmaxx()/2 - 100,getmaxy()/2 - 50,"New Highscore !");
                gotoxy(20,20);
                cout<<"Enter your name";
                hs.open("ak47",ios::out);
                gotoxy(40,20);
                cin>>name;
                hs<<lvl<<" "<<score<<" "<<name;
                hs.close();
            }
            else goto show;
        }
        else
        {
            show:
            gotoxy(30,19);
            cout<<"Current Highscore : "<<endl;
            gotoxy(30,21);
            cout<<"Level : "<<lvl1;
            gotoxy(30,23);
            cout<<"Score : "<<points;
            gotoxy(30,25);
            cout<<"Held by : "<<name;
            hs1.close();
            getch();
        }
        exit(0);
    }
}


void level()
{
    if(lvl<=3){aim=1; obj.speed=1; obj.arsp=3;}
    else
        if(lvl<=6){aim=2; obj.speed=2; obj.arsp=5;}
    else
        if(lvl<10){aim=3; obj.speed=3; lvs++; obj.arsp=7;}
    else
        if(lvl==10){aim=4; obj.speed=4; lvs++; }
    else
        if(lvl>10){aim++; lvs++; obj.speed=6;}
}

void shoot(int&cn,int&x);
int pop(int&con,int&c,int&d,int&count)
{
    gotoxy(3,20);
    cout<<"Score : "<<score;
    gotoxy(3,19);
    cout<<"Level : "<<lvl;
    gotoxy(3,21);
    cout<<"Aim : "<<aim;
    gotoxy(3,22);
    cout<<"Lives : "<<lvs;
    if(count==chan)
    {
        if(score<aim)
        {
            lvs=0;
        }
        if(score>=aim)
        {
            cleardevice();
            gotoxy(20,10);
            cout<<"Your Score :";
            gotoxy(40,10);
            cout<<score;
            delay(1500);
            lvl++;
            gotoxy(20,10);
            cout<<"Proceeding to level: "<<lvl;
            delay(1500);
            count=score=0;

            cleardevice();
            level();
        }

    }



    if(c<=0||c>=getmaxy())
    {
        int col;
        count++;
        col=random(16);
        if(col==9) col++;
        setfillstyle(SOLID_FILL,col);
        goto y;
    }


    if(con==1)goto cir;

    if(con==0)
    {
        y:
        d=random(521)+100;
        c=getmaxy();
        con=1;
    }
    cir:
    delay(3);
    cleardevice();
    fillellipse(d,c,10,20);
    c=c-obj.speed;

    return d,c;
}

void shoot(int&cn,int&x)
{

    archer1(obj.gs);
    line(x+10,obj.gs+12,x+obj.e+10,obj.gs+12);
    x=x+obj.arsp;
    if(x>=600)
    {
        x=0;
        cn=0;
    }

}


void main()
{
    clrscr();
    obj.gs=0;
    obj.e=20;
    obj.arsp=3;
    obj.speed=1;

    int gd=DETECT,gm,con=0;
    int c,d,x=10,a,cn=0,count=0,choice=0;
    initgraph(&gd,&gm,"D:/TC/BGI");
    setbkcolor(LIGHTBLUE);
    c=getmaxy();
    randomize();
    settextstyle(3,HORIZ_DIR,5);
    setfillstyle(SOLID_FILL,GREEN);
    outtextxy(getmaxx()/2 - 150,getmaxy()/2 - 100,"THE ARCHER !");
    getch();


    start:

    cleardevice();
    settextstyle(1,HORIZ_DIR,2);
    setbkcolor(LIGHTBLUE);
    cleardevice();
    outtextxy(150,150,"1. Play Game");
    outtextxy(150,200,"2. Instructions");
    outtextxy(150,250,"3. Exit");

    choice=getch();

    if(choice=='2')
    {

        cleardevice();
        settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
        outtextxy(18,100,"Shoot as many balloons as possible by pressing the right arrow.");
        outtextxy(18,130,"You can use the up and down arrow keys to move the archer.");
        outtextxy(18,160,"ALL THE BEST ! Press space bar to go back.");
        int cv;
        cv=getch();
        if(cv==32)
        {
            goto start;
        }
    }
    if(choice=='3')
    {
        exit(0);
    }

    if(choice=='1')
    {

        st:
//left 75 right 77 up 72 down 80 space 32


        a=getch();
        l:

        switch(a)
        {

            case 72 :
            {
                life();
                pop(con,c,d,count);
                obj.gs-=5;
                a=1000;
                archer(obj.gs);
                if((d>=x&&d<=(x+obj.e))&&(c<=(obj.gs+20)&&c>=(obj.gs-20)))
                {
                    score++;
                    x=602;
                    c=getmaxy();
                }
                else
                    if(c<=0)
                        { lvs--;}
                }
                goto l;

                case 80 :
                {
                    life();
                    pop(con,c,d,count);
                    obj.gs+=5;
                    a=1000;
                    archer(obj.gs);
                    if((d>=x&&d<=(x+obj.e))&&(c<=(obj.gs+20)&&c>=(obj.gs-20)))
                    {
                        score++;
                        x=602;
                        c=getmaxy();
                    }
                    else
                        if(c<=0)
                            { lvs--;}

                    }
                    goto l;

                    case 77:
                    while(!kbhit())
                    {
                        life();
                        cn=2;
                        shoot(cn,x);
                        pop(con,c,d,count);
                        if(cn!=2)
                        {
                            a=1000;
                            goto l;
                        }
                        if((d>=x&&d<=(x+obj.e))&&(c<=(obj.gs+20)&&c>=(obj.gs-20)))
                        {
                            score++;
                            x=602;
                            c=getmaxy();
                        }
                        else if(c<=0)lvs--;
                    }

                    goto st;

                    default:
                    while(!kbhit())
                    {
                        life();
                        pop(con,c,d,count);
                        archer(obj.gs);
                        if(cn==2)
                        {
                            shoot(cn,x);
                        }

                        if((d>=x&&d<=(x+obj.e))&&(c<=(obj.gs+20)&&c>=(obj.gs-20)))
                        {
                            score++;
                            x=602;
                            c=getmaxy();
                        }
                        else if(c<=0)lvs--;

                    }

                    goto st;

                    case 'e' : exit(0);
                }
            }

            getch();
        }

