#ifndef FBSIM_H
#define FBSIM_H
#include<FOOTBALL.H>
#include<unistd.h>
#include<POISSON.H>

using namespace std;


void statement(char com[500],int x);
void getsquad(int x, int y[12]);
void getname(int x , char y[18]);
void getplayername(int x,char p[30]);
void playmatch();
void typedelay(char x[30],char y[30]);
float calc(int x,int y[11]);
float aggrcalc(int s[11]);
int getplaystat(int x,int y);
void foul(int x,int y,int z, int t1[11],int t2[11]);
void logupdate(int g1,int g2);

int rep=-1;


void pattern(int x)
{ int i;  char y[30],p[3];
   strcpy(p," ");
  switch(x)
   {  case 0:
  strcpy(y, "GOoooooooooOL");
      typedelay(y,p);

      cout<<endl;
      for(i=0;i<40;i++)
     {   cout<<"*"; usleep(50);
     }
    break;
    case 1:
cout<<setw(22);
strcpy(y,"CONGRATULATIONS");
typedelay(y,p);
cout<<endl;
for(i=0;i<80;i++)
 {cout<<"#"; usleep(50);}
          break;
      }

}

int  arraycheck(int x[6][10],int m)
{int flag=-1,i,j;
 for(i=0;i<6;i++)
 { for(j=0;j<10;j++)
   {  if(x[i][j]!=-1)
	 { if(x[i][j]==m)
            { flag=i;
               break;
	    }
	 }
   }
 }
return flag;}




void arrayset(int x[6][10])
{
 int i,j;
  for(i=0;i<6;i++)
   { for(j=0;j<10;j++)
      x[i][j]=-1;
   }
}





void statcalc(int x ,int y,int z,int a[6][10])
{ int m,i;
    i=0;
    while(i<x+y)
    { m=rand()%90;
      if(arraycheck(a,m)==-1)
        {a[z][i]=m;
          i++;
        }
    }

}




void fbsim(float as1,float as2,float ds1,float ds2,int g1,int g2,int arr[6][10])
{  srand(time(0));
int r,x;
  arrayset(arr);
   x=2+rand()%2;
  if(as1>as2)
   {  r=rand()%3;
     statcalc(x,r,2,arr);
     statcalc(x,0,3,arr);
   }
   else
   { r=rand()%3;
       statcalc(x,r,3,arr);
        statcalc(x,0,2,arr);
   }

   x=2+rand()%2;
   if(ds1>ds2)
   {  r=rand()%3;
     statcalc(x,r,4,arr);
     statcalc(x,0,5,arr);
   }
   else
   { r=rand()%3;
       statcalc(x,r,5,arr);
        statcalc(x,0,4,arr);
   }

  statcalc(g1,0,0,arr);
  statcalc(g2,0,1,arr);
}




void typedelay(char x[500],char y[50])
{ srand(time(0));
int i,j=30+rand()%10;
   for(i=0;x[i]!='\0';i++)
     { 
       if(x[i]=='%')
       cout<<endl;
      else if(x[i]=='$')
      cout<<endl<<"\t\t\t\t\t";
      else
      cout<<x[i]; usleep(j);}
       cout<<y<<endl;


}


void comment(int x,int s1[11],int s2[11])
{  int r,y; char com[500],pname[30];
 srand(time(0));

switch(x)
     {case 0:

statement(com,0);
       r=rand()%5;
       y=s1[r];
       getplayername(y,pname);
typedelay(com,pname);
      pattern(0);
      break;

case 1:

statement(com,1);       
            r=rand()%5;
       y=s2[r];
       getplayername(y,pname);
typedelay(com,pname);
      pattern(0);
      break;

case 2:

statement(com,2);
      r=rand()%5;
       y=s1[r];
      getplayername(y,pname);
      typedelay(com,pname);
      break;

case 3:

statement(com,3);
       r=rand()%5;
       y=s2[r];

       getplayername(y,pname);
      typedelay(com,pname);

      break;
case 4:

statement(com,4);

 r=6+rand()%3;
  y=s1[r];
  getplayername(y,pname);

typedelay(com,pname);
      break;

case 5:

statement(com,5);

 r=6+rand()%3;
  y=s2[r];
  getplayername(y,pname);

typedelay(com,pname);
      break;

case 6:

statement(com,6);

 r=6+rand()%3;
  y=s1[r];
  getplayername(y,pname);
typedelay(com,pname);
 break;

case 7:

statement(com,7);

 r=6+rand()%3;
  y=s2[r];
  getplayername(y,pname);
typedelay(com,pname);
 break;


     }
}





void match(float as1,float as2,float ds1,float ds2,int g1,int g2,float ag1,float ag2,int t1id,int t2id)
 {
   int arr[6][10],i,x,s1[11],s2[11];
  char t1[18],t2[18];

  getname(t1id,t1);
  getname(t2id,t2);
  getsquad(t1id,s1);
  getsquad(t2id,s2);

   fbsim(as1,as2,ds1,ds2,g1,g2,arr);

   

/*  cout<<"time for goal 1 " ; cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[0][i]!=-1)
	cout<<arr[0][i]<<"th min :"<<setw(1);
     }
  cout<<endl;


  cout<<"time for goal 2 " ;  cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[1][i]!=-1)
	cout<<arr[1][i]<<"th min :"<<setw(1);
     }
  cout<<endl;



  cout<<"time for attack by team 1 " ; cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[2][i]!=-1)
	cout<<arr[2][i]<<"th min :"<<setw(1);
     }
  cout<<endl;




  cout<<"time for attack  by team 2 " ; cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[3][i]!=-1)
	cout<<arr[3][i]<<"th min :"<<setw(1);
     }
  cout<<endl;



  cout<<"time for defence by team 1 " ; cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[4][i]!=-1)
	cout<<arr[4][i]<<"th min :"<<setw(1);
     }
  cout<<endl;



  cout<<"time for defence by team 1 " ; cout<<endl;
    for(i=0;i<10;i++)
     { if(arr[5][i]!=-1)
	cout<<arr[5][i]<<"th min :"<<setw(1);
     }
  cout<<endl;

  */
   usleep(30);

   cout<<"ENTER ANY KEY TO CONTINUE";

   getchar();
   cout<<"MATCH	BEGINS"<<endl;
   usleep(300);



logupdate(g1,g2);
cout<<t1<<setw(12)<<"V.S"<<setw(12)<<t2;

   cout<<endl<<endl;
for(i=0;i<90;i++)
    {  
        
        
     if(i==0)
     { cout<<"\t\t\t\t KICK OFF "<<endl;i=i+1;}
      
       foul(ag1,ag2,i,s1,s2);

         if(i==44)
	 {cout<<setw(30)<<"HALF TIME"<<endl;
	usleep(500);}
	if(i==89)
	 {  cout<<setw(30)<<"FULL	TIME"<<endl<<endl;
	     if(g1>g2)
	     { cout<<setw(20)<<t1<< " WINS  "<<endl; pattern(1);}
	      else if (g2>g1)
	      {cout<<setw(20)<<t2<<" WINS  "<<endl; pattern(1);}
	      else if (g1==g2)
	      {cout<<setw(20)<<"   DRAW  "<<endl; pattern(1);}

		 cout<<t1<<" : "<<g1<<"  _______________   "<<t2<<" : "<<g2<<endl;
		   usleep(500);break;}


	    x=arraycheck(arr,i);
	 if(x!=-1)
	    { cout<<i<<"th min :";
	       comment(x,s1,s2);
	       cout<<endl<<endl;
	       usleep(2000);

	    }
    }
 }



void getname(int y, char x[18])
{ user u1;
  ifstream ifile;
  ifile.open("user.dat",ios::in|ios::binary);
   while(ifile)
   { ifile.read((char*)&u1,sizeof(u1));
	    if(y==u1.userid)
	  //strcpy(x,u1.tname);
    strcpy(x,"sample");
        }
}

void getsquad(int id, int arr[11])
{user u1; int i;
  ifstream ifile;
  ifile.open("user.dat",ios::in|ios::binary);
   while(ifile)
   { ifile.read((char*)&u1,sizeof(u1));
       if(id==u1.userid)
	  { for(i=0;i<11;i++)
	     arr[i]=u1.squad[i];
	  }
   }
}


void playmatch()
{ user u1;
int t1,t2;
float as1,as2,ds1,ds2,avg,agg1,agg2;

 cout<<"enter userid";
 cin>>t1;

cout<<"ENTER ANY KEY TO CONTINUE ";
getchar();
ifstream ifile;
   ifile.open("user.dat",ios::in|ios::binary);
cout<<endl;
while(ifile)
{   ifile.read((char*)&u1,sizeof(u1));
     u1.display();
}
cout<<"enter opponent id";
cin>>t2;
avg=agoal;
int s1[11],s2[11];
getsquad(t1,s1);
getsquad(t2,s2);
as1=calc(0,s1);
ds1=calc(1,s1);
as2=calc(0,s2);
ds2=calc(1,s2);
int a[2],g1,g2;
poisson(as1,as2,ds1,ds2,avg,a);
g1=a[0];
g2=a[1];
agg1=aggrcalc(s1);
agg2=aggrcalc(s2);
match(as1,as2,ds1,ds2,g1,g2,agg1,agg2,t1,t2);
}

 float calc(int x, int arr[11])
{ int i,j;
  float y,p;
   switch(x)
{ case 0:
 for(i=0;i<6;i++)
  {j=arr[i];
   p+=getplaystat(0,j);}
  y=(p/6)/80;
  break;
 case 1:
 for(i=6;i<11;i++)
 {j=arr[i];
 p+=getplaystat(0,j);}
y=(p/5)/80;
 break;
}
return y;
}

  
void statement(char com[500],int x)
{ srand(time(0)); int y;
 switch(x)
 { case 0:
   y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"And here he goes for the goal... % majestic finish by..");
     break;
    case 2:
    strcpy(com,"owww..what a goal by..");
    break;
    case 3:
    strcpy(com,"superbly done by..");
    break;
    case 4:
    strcpy(com,"GOAL...great header by..");
    break;
  }
break;

 case 1:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"                       is..he..the man of the day $..here goes ");
     break;
    case 2:
    strcpy(com,"                         And today's match is controlled by $ ...");
    break;
    case 3:
    strcpy(com,"                            you would have been proud of that header $ silky finish there.. by ");
    break;
    case 4:
    strcpy(com,"                             WOOW...what was that $ the best goal in the season by ");
    break;
  }
break;
   
case 2:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"its a pass.. and a pass..and % great touch by ");
     break;
    case 2:
    strcpy(com,"with a stepover.. % dribbles past four.. % oh he misses it..");
    break;
    case 3:
    strcpy(com," this man..he is making things awkward % for the opposition..");
    break;
    case 4:
    strcpy(com,"great cross there by..");
    break;
  }
break;

case 3:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"                                 he just chipped it over the defender..$ inhuman dribble by.. ");
     break;
    case 2:
    strcpy(com,"                                   he clears past one..and a two..and $ its..over the post..");
    break;
    case 3:
    strcpy(com,"                                 long range effort..oww.. $ great save by the goalkeeper $ ...poor.. ");
    break;
    case 4:
    strcpy(com,"                                 no doubt about this fella $ he's the real master of the pass..");
    break;
  }
break;


case 4:
 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"excellent interception by.. ");
     break;
    case 2:
    strcpy(com,"lunging it, slide tackle by..");
    break;
    case 3:
    strcpy(com,"great clearance by the defence.. % nice job by..");
    break;
    case 4:
    strcpy(com,"ohh...that was nearly a goal from.. % oppostion..good work by..");
    break;
  }
break;



case 5:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"                                  that's good defending $ plain and simple..by ");
     break;
    case 2:
    strcpy(com,"                                          that was a smart interception..$ great play by ... ");
    break;
    case 3:
    strcpy(com,"                                          the defenders..with great precision..$ passes the ball.. ");
    break;
    case 4:
    strcpy(com,"                                           risky interception.. $ could have resulted in foul..");
    break;
  }
break;

case 6:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"an offside by....");
     break;
    case 2:
    strcpy(com," oh...a freekick for the opposition");
    break;
    case 3:
    strcpy(com," a throw taken by.... ");
    break;
    case 4:
    strcpy(com,"aw..a corner.. he takes it.. % tries a lob pass..");
    break;
  }
break;

case 7:

 y= 1+rand()%4;
   
  switch(y)
  {
    case 1: 
    strcpy(com,"                                  ohh..a hand..at this critical movement..$ must be an advantage for $ opposition...");
     break;
    case 2:
    strcpy(com,"                                        he just sent the ball flying.. $ its towards the crowd..$ an  out..");
    break;
    case 3:
    strcpy(com,"                                       passes to the opposition...$ oh..takles the opponent.. $ ow that's a foul");
    break;
    case 4:
    strcpy(com,"                                       ow..a foul.. a freekick for the team.. $ can he change the game...");
    break;
  }
break;




}
}   


float aggrcalc(int s[11]) 
{ int i,y,m; float x;
 
 for(i=0;i<11;i++) 
  {  y=s[i];
     m+=getplaystat(1,y); 
  }
  x=(m/10);
return x;
}



int getplaystat(int x,int y)
{player p1; int m;
 ifstream ifile;
ifile.open("player.dat",ios::in|ios::binary);

switch(x)
{ case 0:
  while(ifile)
 {  ifile.read((char*)&p1,sizeof(p1));
      if(y==p1.playerid)
         m=p1.prating;
 }
 break;
 case 1:
    while(ifile)
 {  ifile.read((char*)&p1,sizeof(p1));
      if(y==p1.playerid)
         m=p1.paggression;
 }
break;
}
return m;
}


void foul(int x,int y,int z,int t1[11],int t2[11])
{ int m,i, flag,a;
 i=z; flag=-1;

if(z==0)
return;

if(z>4)
{if(rep!=-1)
 { if(z<rep-4 || z>rep+4)
   flag=0;
  else
  return;
}
else
rep=z;
} 
 srand(time(0));
  

if(flag==0)
{m=35+rand()%18;
  if(m%13==0)
 { if(x>y)
     {cout<<i<<"th min:";comment(6,t1,t2);rep=i;}
   
    else 
    {cout<<i<<"th min:";comment(7,t1,t2);rep=i;}
}
else if(m%17==0)
{ int t;
  t=rand()%2;
 switch(t)
  { case 0:
    cout<<i<<"th min:";comment(6,t1,t2);rep=i;
    break;
    case 1:
    cout<<i<<"th min:";comment(7,t1,t2);rep=i;
    break;
  }
 }
 }
}



void logupdate(int g1,int g2)

{ofstream ofile;  int log,log1 ,tot;
ofile.open("mlog.dat",ios::app|ios::binary);

 log=1;
 ofile.write((char*)&log,sizeof(log));

ofile.close();

tot=g1+g2;

ofile.open("glog.dat",ios::app|ios::binary);

 log1=tot;
 ofile.write((char*)&log1,sizeof(log1));

ofile.close();
}
#endif