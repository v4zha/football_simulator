#include<iostream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<math.h>

#include<time.h>

int goalcalc(float k[2][5],int x)
{ randomize();
int n,m,i,b[3];
  float largest;
n=0;
while(n<3)
{
   largest=k[x][0];
   for(i=1;i<6;i++)
	    {
		    if(k[x][i]>largest)
		     largest=k[x][i];
	    }



      for(i=0;i<6;i++)
     { if(k[x][i]==largest)
       { b[n]=i;
	   k[x][i]=-1;
	   n++;
        break; }
    }
}
randomize();
n=random(3);
m= b[n];
return m;

}


int fact(int x)
{
if(x==0 || x==1)
return 1;
else
return x*fact(x-1);
}



void  poisson(float as1,float as2,float ds1,float ds2,float avg,int a[2])
{ double lam1,lam2;
float k[2][5],largest;
int p[2][3],i;
int g1,g2;

lam1=as1*ds2*avg;
lam2=as2*ds1*avg;

clrscr();
for(i=0;i<6;i++)
{k[0][i]=float(100*(exp(-1*lam1)*pow(lam1,i)/fact(i)));

k[1][i]=float(100*(exp(-1*lam2)*pow(lam2,i)/fact(i)));
}

/*cout<<"the no of goals and chance for team 1 \n";

cout<<setw(3)<<"goal"<<setw(6)<<"chance";
cout<<endl;
for(i=0;i<6;i++)
cout<<setw(3)<<i<<"\t"<<k[0][i]<<endl;


cout<<"the no of goals and chance for team 2 \n";

cout<<setw(3)<<"goal"<<setw(6)<<"chance";
cout<<endl;
for(i=0;i<6;i++)
cout<<setw(3)<<i<<"\t"<<k[1][i]<<endl;

*/
g1=goalcalc(k,0);
g2=goalcalc(k,1);

a[0]=g1;
 a[1]=g2; 
}
