#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int u=30;

void archer(int u)
{
    circle(25,u,10);     //face
    rectangle(23,u+11,28,u+35); //body
    line(28,u+35,36,u+45); //rleg1
    line(36,u+45,28,u+55); //rleg2
    line(23,u+35,15,u+55); //lleg
    line(26,u+17,45,u+20); //rhand
    line(28,u+14,55,u+15); //lhand
    arc(45,u+15,265,92,10); //bow
    line(45,u+5,45,u+25);  //string
}

void archer1(int u)
{
    circle(22,u,10);
    rectangle(20,u+11,25,u+35);
    line(25,u+35,33,u+45);
    line(33,u+45,25,u+55);
    line(20,u+35,12,u+55);
    line(25,u+14,52,u+15);
    arc(42,u+15,265,92,10);
    line(42,u+5,36,u+15);
    line(36,u+15,42,u+25);
    line(32,u+23,23,u+17);
    line(32,u+23,40,u+17);
}

