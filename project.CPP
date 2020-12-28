#include<fbsim.h>
#include<loading.h>
 void main()
{ int ch;
 char ch1;
 clrscr();

 loading ();
  cout<<"welcome to crxbyt soccer club management \n";
  do{cout<<"1.manage \n 2.play match \n";
  cout<<"enter your choice \n";
   cin>>ch;
   switch(ch)
   { case 1:
    intro();
    break;
    case 2:
    playmatch();
    break;
    }
    cout<<"do you want to continue";
    cin>>ch1;
    }while(ch1=='y'||ch1=='Y');


 getch();
}
