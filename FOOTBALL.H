#include<iostream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>




float agoal=2.33;



void displaylog(int e);
int idcheck(int x, int y);
int team(int p,int *x,int y);
int buildsquad(int *x,int m,char y[10]);
int buyplayer(int *x);
void playmatch();







class player
{
public:
int playerid,prating,paggression,price;
char playername[20],category[10],position[10];

void getdata();
void display()
{ cout<<playername<<"\t\t"<<prating<<"\t\t"<<playerid<<"\t\t"<<price<<"\t\t"<<category;
cout<<endl;
}
};

 void player:: getdata()
{ int x;
cout<<"enter player id";
cin>>x;
while(idcheck(1,x)==0)
{ cout<<"used by another player. please enter new playerid "<<endl;
   cin>>x;
}
playerid=x;
cout<<"Enter the player rating\n";
cin>>prating;
cout<<"Enter player aggression rate\n";
cin>>paggression;
cout<<"Enter player name\n";
gets(playername);
cout<<"Enter the category\n";
gets(category);
cout<<"Enter position in which the player plays\n";
gets(position);
cout<<"Enter price of the player \n";
cin>>price;
}




class user
{
public:
int userid,level;
char username[30],tname[20];
int squad[11];
int *amount;

void getdata();

void display()
{ cout<<userid<<"\t\t"<<tname<<endl;}

 };

void user::getdata()
{int x;
cout<<"enter userid";
cin>>x;
 while(idcheck(0,x)==0)
{ cout<<"used by another account..please enter new user id"<<endl;
cin>>x;}
userid=x;
cout<<"Enter the user name \n";
gets(username);
cout<<"Enter the team name \n";
gets(tname);

char ch,pass[10]; int flag=-1;
cout<<" are you vip user (y/n)";
cin>>ch;
if(ch=='y'||ch=='Y')
{ cout<<"enter password";
  gets(pass);
   if(strcmp(pass,"betafox")==0)
     { level =10;
       *amount = 30000; flag=0;}
else cout<<"incorrect password";
}
if(flag==-1)
{ level=5; *amount =15000;}

int i=0;
while(i<11)
 { int x=-1;
   x=team(i,amount,level);
   if(x!=-1)
    {cout<<"you have to purchase "<<10-i<<"players";
     squad[i]=x;
     i++;}
 }
}

void getplayername(int x,char p[30])
{
 player p1;
ifstream ifile("player.dat",ios::in||ios::binary);
if(!ifile)
{
cout<<"The file cannot be opened \n";
exit(0);
}
while(!ifile.eof())
{ifile.read((char*)&p1,sizeof(p1));
if(x==p1.playerid)
{strcpy(p,p1.playername);
break;}
}

}


void userdefine(int uid)
{
int m,u;
 user u1;
cout<<"What would you like to do ?\n";
cout<<"1.Display squad \n ";
cin>>m;
switch(m)
{

case 1:
ifstream ifile("user.dat",ios::in||ios::binary);
while(ifile)
{ ifile.read((char*)&u1,sizeof(u1));
  if(uid==u1.userid)
 {

   clrscr();


  cout<<"ATTACKERS \n";
  for(int i=0;i<3;i++)
  {
  char p[30];
  u=u1.squad[i];
  getplayername(u,p);
  cout<<p<<"\t";
  }cout<<endl;

  cout<<"MIDFIELDERS \n";
  for(i=3;i<6;i++)
  {
  char q[30];
  u=u1.squad[i];
  getplayername(u,q);
  cout<<q<<"\t";
  }cout<<endl;

  cout<<"DEFENDERS \n";
  for(i=6;i<10;i++)
  {char o[30];
  u=u1.squad[i];
  getplayername(u,o);
  cout<<o<<"\t";
  }
cout<<endl;
  cout<<"GOALKEEPER \n";
  char g[30];
  u=u1.squad[10];
  getplayername(u,g);
  cout<<g<<"\n";
}
}
break;

}
}


void iuser()
{int ch,usid;
 char ch1;
 user u1;
 do{cout<<"1.create\n2.login";
 cin>>ch;
 switch(ch)
 { case 1:
 char ch1;
   ofstream ofile;
 ofile.open("user.dat",ios::app||ios::binary);
if(!ofile)
{
cout<<"The file cannot be opened \n";
exit(0);
}

do{u1.getdata();
 ofile.write((char*)&u1,sizeof(u1));


cout<<"do you want to continue (y/n)"<<endl;
cin>>ch1;
}while(ch1=='y'||ch1=='Y');
ofile.close();
break;

case 2:
cout<<"Enter the user id to login \n";
cin>>usid;
int flag=-1;
ifstream ifile("user.dat",ios::in||ios::binary);

while(ifile)
{
ifile.read((char*)&u1,sizeof(u1));
if(usid==u1.userid)
{cout<<"WELCOME BACK "<<u1.username<<endl;
 delay(20);flag=0;
userdefine(usid);
}

}
if(flag==-1)
cout<<"account not found .."<<endl;
break;
}
cout<<"do you want to continue"<<endl;
cin>> ch1;
}while(ch1=='y'||ch1=='Y');
}


void admin()
{ player p1;
char dum[10];
char pass[10];
strcpy(pass,"alphawolf");
cout<<"enter the password ";
gets(dum);
if(strcmp(dum,pass)==0)
{
int ch; char ch1;
do{cout<<"What would you like to do \n";
cout<<"1.Insert player data\n2.Display player data\n3.enter average goal\n4.display log\n";
cin>>ch;
switch(ch)
{

case 1:
char ch;
ofstream ofile;
ofile.open("player.dat",ios::out||ios::binary);

cout<<"please enter player position as fwd,mid,def,gk"<<endl;

do{p1.getdata();
 ofile.write((char*)&p1,sizeof(p1));
cout<<"do you want to continue "<<endl;
 cin>>ch;
}while(ch=='y'||ch=='Y');
ofile.close();
break;

case 2:
ifstream ifile("player.dat",ios::in||ios::binary);
if(!ifile)
{
cout<<"The file cannot be opened \n";
exit(0);
}
while(!ifile.eof())
{
ifile.read((char*)&p1,sizeof(p1));
p1.display();
}
break;

case 3:
int s;
cout<<"1.manually enter avg goal \n 2.set avg goal from log ";
cin>>s;
switch(s)
{
case 1:
float x;
 cout<<"enter average goal";
 cin>>x;
 agoal=x;
 break;

case 2:
ifstream ifile;  float m,y,avg; int log,log1; 
ifile.open("mlog.dat",ios::in||ios::binary);
while(ifile)
{  ifile.read((char*)&log,sizeof(log));
m+=log;}
ifile.close();
ifile.open("glog.dat",ios::in||ios::binary);
while(ifile)
{  ifile.read((char*)&log1,sizeof(log1));
 y+=log1;}
ifile.close();

cout<<"total matches"<<m<<endl;
 cout<<"total goal "<<y<<endl;
avg=y/m;
agoal=avg;
cout<<"average goal"<<agoal;
break;
}
break;



case 4:

int e;
cout<<"1.user log \n 2.player log \n 3.match log \n 4. total goal \n";
cin>>e;

displaylog(e);


break;
}
cout<<"do you want to continue"<<endl;
cin>>ch1;
}while(ch1=='y'||ch1=='Y');

}
}

void intro()
{ int ch;
  cout<<" are you 1.user \n 2.admin ";

  cin>>ch;
  switch(ch)
  { case 1: iuser();
    break;
    case 2: admin();
    break;
  }


}

int buildsquad(int *amount,int level,char y[10])
{ int ch,x;
  char choice;
  player p1;
ifstream ifile;
ifile.open("player.dat",ios::in||ios::binary);

rebuy:
cout<<"Enter the category of players you would like to purchase \n";

cout<<"1.Elite\n2.Gold\n3.Silver\n";

cin>>ch;



switch(ch)


{

case 1:

if(level<10)

{cout<<"You cannot purchase elite players\n";

goto rebuy;}
else

{



while(ifile)
{ ifile.read((char*)&p1,sizeof(p1));

if(strcmpi(p1.category,"elite")==0 &&strcmpi(p1.position,y)==0)

{

p1.display();

cout<<"\t";

}
}
 do
{x=buyplayer(amount);}while(x==-1);

}
break;



case 2:



while(ifile)
{ifile.read((char*)&p1,sizeof(p1));
if(strcmpi(p1.category,"gold")==0 && strcmpi(p1.position,y)==0)

{

p1.display();

cout<<"\t";


}
}

 do
{x=buyplayer(amount);}while(x==-1);
break;



case 3:


while(ifile)
{ifile.read((char*)&p1,sizeof(p1));

if(strcmpi(p1.category,"silver")==0 && strcmpi(p1.position,y)==0)

{

p1.display();

cout<<"\t";


}
}
 do
{x=buyplayer(amount);}while(x==-1);

break;

}

ifile.close();
return x;
}







int buyplayer(int *x)
{
player p;
char plname[20]; int y;


cout<<"Enter the name of the player you would like to purchase \n";
gets(plname);

ifstream  ifile;
 ifile.open("player.dat",ios::in||ios::binary);
while(ifile)
{
ifile.read((char*)&p,sizeof(p));
if(strcmpi(p.playername,plname)==0)
{
   p.display();
   if(*x<p.price)
   {cout<<"can't purchase player"<<endl;
   cout<<"please purchase free silver players to complete squad"<<endl;
   y=-1;break;}
   else
   {*x=*x-p.price;
   y=p.playerid;
   cout<<"The player "<<p.playername<<"has been successfully purchased for a price "<<p.price<<endl;
   cout<<"the remaining amount is "<<*x<<endl;}
   break;
 }
else
{cout<<"invalid player name"; y=-1;break;}
}

return y;}



int team(int i, int* amount, int level)
{ int x,p;    player p1; char y[10];
 if(i<3)
 x=1;
 else if(i<6)
x=2;
else if(i<10)
x=3;
else if(i==10)
x=4;


switch(x)
{ case 1:

cout<<"\t\t\t FORWARD "<<endl;
strcpy(y,"fwd");

break;

case 2:
cout<<"\t\t\t MIDFIELDER "<<endl;
strcpy(y,"mid");

break;

case 3:
cout<<"\t\t\t DEFENDER "<<endl;
strcpy(y,"def");

break;

case 4:

cout<<"\t\t\t GOAL KEEPER "<<endl;
strcpy(y,"gk");

break;

}

p=buildsquad(amount,level,y);
return p;
}





int idcheck(int x, int y)
{
 int flag=-1;
   ifstream ifile;

switch(x)
 {
   case 0:

  user u1;

  ifile.open("user.dat",ios::in||ios::binary);
  while(ifile)
  { ifile.read((char*)&u1,sizeof(u1));
   if(y==u1.userid)
     {flag=0;break;}
  }

 ifile.close();
 break;

 case 1:
 player p1;
 ifile.open("player.dat",ios::in||ios::binary);
 while(ifile)
 { ifile.read((char*)&u1,sizeof(u1));
  if(y==p1.playerid)
    {flag=0;break;}
  }

 ifile.close();
 break;

 }
 return flag;}



void displaylog(int e)
{ ifstream ifile;
 switch(e)
 {
 case 1:
 ifile.open("user.dat",ios::in||ios::binary);
 user u1; int i=0;
 if(!ifile){ cout<<"cannot open"; exit(0);}

 while(ifile)
  { ifile.read((char*)&u1,sizeof(u1));
    u1.display();
    cout<<endl; i++;
  }
 ifile.close();
cout<<endl;
 cout<<"total number of users "<<i;
 break;
 case 2:
 int p=0; player p1;
 ifile.open("player.dat",ios::in||ios::binary);
 if(!ifile){ cout<<"cannot open"; exit(0);}

 while(ifile)
  { ifile.read((char*)&p1,sizeof(p1));
     p1.display(); cout<<endl; p++;
  }
 ifile.close();
cout<<endl;
cout<<" total number of players :"<<p;
 
break;


 case 3:
 int x,log;
 ifile.open("mlog.dat",ios::in||ios::binary);

 if(!ifile){ cout<<"cannot open"; exit(0);}

 while(ifile)
 {  ifile.read((char*)&log,sizeof(log));
 x+=log;}

  cout<<"total number of matches "<<x<<endl;
 ifile.close();
 break;


 case 4:
 int log1;
 ifile.open("glog.dat",ios::in||ios::binary);
 if(!ifile){ cout<<"cannot open"; exit(0);}

 while(ifile)
 { ifile.read((char*)&log1,sizeof(log1));
    cout<<"total goal in each match"<<log1<<endl;
 }
 ifile.close();
 break;


}
}