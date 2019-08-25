    #include <iostream>
    #include <conio>
    #include <fstream.h>
    #include <stdio.h>
    #include <iomanip.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <process.h>
    #include <math.h>
    #include <windows.h>
    class genset
    {
         int no;
         char genset[30];
         char company[10];
         int power;
         int consumption;
         public:
         int distance1()
         {
          return power;
         }
         void copy(int r,genset ob2)
         {
           strcpy(genset,ob2.genset);
           no=ob2.no;
           strcpy(company,ob2.company);
           power=ob2.power+r;
           consumption=ob2.consumption;
           }
         int namec(char name1[30])
         {
          if(strcmpi(genset,name1))
           return 1;
          else
           return 0;
          }
         int reno()
         {
            return no;
         }
         void display1()
         {
              cout<<setw(6)<<no
                  <<setw(25)<<genset
                  <<setw(8)<<company
                  <<setw(10)<<power
                  <<setw(16)<<consumption;
         }
         void input()
         {
              cout<<"SERIAL NO:";
              cin>>no;
              cout<<"GENSET:";
              gets(name);
              cout<<"COMPANY:";
              gets(company);
              cout<<"POWER:";
              cin>>power;
              cout<<"COMSUMPTION:";
              cin>>consumption;
         }
    }ob1;
    class info
    {
         char name[20];
         int gensetno;
         char location[30];
         long number;
         int date;
         public:
         int namec(char name1[30])
         {
          if(strcmpi(name,name1))
           return 1;
          else
           return 0;
          }
         void input(int n)
         {
              cout<<"\n\n\nENTER THE NAME: ";
              gets(name);
              cout<<"\n\nENTER THE LOCATION: ";
              gets(adress);
              cout<<"\n\nENTER THE PHONE NUMBER: ";
              cin>>number;
              gensetno=n;
              cout<<"\n\nINPUT THE DATA IN FORMAT (DDMMYY): ";
              cin>>days;
         }
         void display3()
         {
              cout<<setw(3)<<gensetno
                  <<setw(10)<<name
                  <<setw(4)<<age
                  <<setw(12)<<adress
                  <<setw(10)<<number
                  <<setw(10)<<days;
         }
         int cno()
         {
             return gensetno;
         }
    }ob2;
    void modify(int no,int t=0)
    {
         char b[10];
         char a[30];
         if(t==0)
         { strcpy(b,"ob2");
           strcpy(a,"info.dat");
         }
         else
           if(t==1||t==11)
           {
             strcpy(b,"ob1");
             strcpy(a,"silent.dat");
           }
           else
             if(t==2||t==22)
             {
               strcpy(b,"ob1");
               strcpy(a,"notsilent.dat");
             }
         ofstream filin("sefault.dat",ios::binary);
         ifstream filout(a,ios::binary);
         if(t!=0)
         {
           while(filout.read((char *)&ob1,sizeof(ob1)))
                if(ob1.reno()!=no)
                  {
                   filin.write((char *)&ob1,sizeof(ob1));
                  }
         }
         else
           while(filout.read((char *)&ob2,sizeof(ob2)))
                if(ob2.cno()!=no)
                  filin.write((char *)&ob2,sizeof(ob2));
         filin.close();
         filout.close();
         remove(a);   //the problem is here
         rename("sefault.dat",a);
         if(t==1||t==2||t==3)
         {
          ofstream filin1("sefault.dat",ios::binary|ios::app);
          ifstream filout1("!!genset.dat",ios::binary);
           while(filout1.read((char *)&ob1,sizeof(ob1)))
                if(ob1.reno()!=no)
                  filin1.write((char *)&ob1,sizeof(ob1));
         filin1.close();
         filout1.close();
         remove("!!genset.dat");
         rename("sefault.dat","!!genset.dat");
        }
         
    }
    void display(char nameofgenset[],int t=0)
    {
         ifstream filin(nameofgenset,ios::binary);
         cout<<endl<<endl;
         cout<<setw(6)<<"NO"
             <<setw(25)<<"NAME OF THE GENSET"
             <<setw(8)<<"COMPANY"
             <<setw(10)<<"POWER"
             <<setw(18)<<"CONSUMPTION\n\n";
         while(filin.read((char *)&ob1,sizeof(ob1)))
         {
              if(t!=0)
                if(t==ob1.reno())
                {
                  ob1.display1();
                  break;
                }
              if(t==0)
                ob1.display1();
              cout<<"\n";
         }
         filin.close();
    }
    void returning()
    {
         top:
         int no;
         cout<<"\n\nENTER THE REFERENCE NO:";
         cin>>no;
         ifstream filin("info.dat",ios::binary);
         while(filin.read((char*)&ob2,sizeof(ob2)))
          if(ob2.cno()==no)
          {
         cout<<"WHAT TYPE OF GENSET DID YOU RENT";
         cout<<"\n\n  1.SILENT";
         cout<<"\n\n  2.NON-SILENT";
         int op2;
         cout<<"\n\n\n    ENTER YOUR OPTION:";
         cin>>op2;
                 int distance;
                cout<<"\n\nENTER THE DISTANCE TRAVELLED:";
                cin>>distance;
                int n1=ob2.cno();
                char ab[20];
                switch(op2)
                {
                   case 1:
                    display("silent.dat",n1);
                    strcpy(ab,"silent.dat");
                    break;
                   case 2:
                    display("notsilent.dat",n1);
                    strcpy(ab,"notsilent.dat");
                    break;
                }
             int r;
             filin.close();
             genset ob3;
             ofstream filin1(ab,ios::binary|ios::app);
             ifstream filin2("!!genset.dat",ios::binary);
             while(filin2.read((char *)&ob1,sizeof(ob1)))
             {
              cout<<"inside if";
                     getch();
                  if(ob1.reno()==no)
                    {
                     ob3.copy(distance,ob1);
                     filin1.write((char *)&ob3,sizeof(ob3));
                  }
             }
                  filin1.close();
             filin2.close();
         modify(no);
             }
         else
          {
           filin.close();
           cout<<"INVALID NO";
           getch();
           goto top;
           }
    }
    void rent(char nameofgenset[30])
    {
         nor:
         clrscr();
         int no;
         int t=0;
         display(nameofgenset);
         cout<<"\n\nINPUT THE GENSET NO";
         cin>>no;
         ifstream filin(nameofgenset,ios::binary);
         while(filin.read((char *)&ob1,sizeof(ob1)))
              if(ob1.reno()==no)
              {
                clrscr();
                display(nameofgenset,no);
                t=1;
                cout<<"\n\n\n";
                ob2.input(no);
                ofstream file("info.dat",ios::app|ios::binary);
                file.write((char *)&ob2,sizeof(ob2));
                file.close();
                int n;
                if(strcmpi(nameofgenset,"silent.dat")==0)
                 n=11;
                else
                 if(strcmpi(nameofgenset,"notsilent.dat")==0)
                  n=22;
                modify(no,n);
              }
         if(t==0)
         {
           cout<<"\n\n\nINVALID NO";
           getch();
           goto nor;
         }
         filin.close();
         getch();
         clrscr();
    }
    void display2()
    {
     cout<<setw(6)<<" NO"<<setw(6)<<"NAME"<<setw(12)<<"LOCATION"<<setw(12)<<"PHONE NO"<<setw(15)<<"DATE\n\n";
      ifstream filin("info.dat",ios::binary);
      while(filin.read((char *)&ob2,sizeof(ob2)))
      ob2.display3();
     }
    void creator()
    {
         clrscr();
         cout<<"\n\n\n\n\n WHAT DO YOU WANT TO DO:";
         cout<<"\n\n  1.ADD A GENSET";
         cout<<"\n\n  2.EDIT GENSET";
         cout<<"\n\n  3.DELETE A GENSET";
         cout<<"\n\n  4.GENSET DETAILS";
         cout<<"\n\n  5.RENTAL INFORMATION";
         int option;
         cout<<"\n\n\n    ENTER YOUR OPTION";
         cin>>option;
         clrscr();
         cout<<"\n\n";
         switch(option)
         {
            case 1:
            {
             int n;
             char namegenset1[30];
             cout<<"NO OF GENSET TO BE INPUTED: ";
             cin>>n;
             cout<<"\nENTER THE TYPE OF GENSET: ";
             cout<<"\n\n  1.SILENT";
             cout<<"\n\n  2.NON-SILENT";
             int op3;
             cout<<"\n\n\n    ENTER YOUR OPTION: ";
             cin>>op3;
             clrscr();
             cout<<"\n\n";
             switch(op3)
             {
                case 1:
                 strcpy(namegenset1,"silent.dat");
                 break;
                case 2:
                 strcpy(namegenset1,"notsilent.dat");
                 break;
             }
             ofstream filin(namegenset1,ios::binary|ios::app);
             ofstream filin2("genset.dat",ios::binary|ios::app);
             for(int i=0;i<n;i++)
             {
               ob1.input();
               filin.write((char *)&ob1,sizeof(ob1));
               filin2.write((char*)&ob1,sizeof(ob1));
             }
             filin.close();
             filin2.close();
             break;
            }
            case 2:
            {
             cout<<"\n\n\n\nSELECT THE GENSET TO BE MODIFIED";
             cout<<"\nENTER THE TYPE OF GENSET: ";
             cout<<"\n\n  1.SILENT";
             cout<<"\n\n  2.NON-SILENT";
             int op3;
             cout<<"\n\n\n    ENTER YOUR OPTION:";
             cin>>op3;
             clrscr();
             cout<<"\n\n";
             char namegenset1[30];
             switch(op3)
             {
                case 1:
                 strcpy(namegenset1,"silent.dat");
                 break;
                case 2:
                 strcpy(namegenset1,"notsilent.dat");
                 break;
             }
             display(namegenset1);
             cout<<"\n\n\n ENTER THE GENSET  NO:";
             cin>>op3;
             fstream filin(namegenset1,ios::binary|ios::in|ios::out);
             fstream filin2("!!genset.dat",ios::binary|ios::in|ios::out);
             while(filin.read((char *)&ob1,sizeof(ob1)))
             {
                  if(ob1.reno()==op3)
                  {
                    ob1.input();
                    filin.seekp(-sizeof(ob1),ios::cur);
                    filin.write((char *)&ob1,sizeof(ob1));
                  }
             }
              while(filin2.read((char *)&ob1,sizeof(ob1)))
             {
                  if(ob1.reno()==op3)
                  {
                    ob1.input();
                    filin2.seekp(-sizeof(ob1),ios::cur);
                    filin2.write((char *)&ob1,sizeof(ob1));
                  }
             }
             filin.close();
             filin2.close();
            }
            case 3:
            {
             clrscr();
             cout<<"\n\n\n\nSELECT THE GENSET TO BE DELETED";
             cout<<"\nENTER THE TYPE OF GENSET: ";
             cout<<"\n\n  1.SILENT";
             cout<<"\n\n  2.NON-SILENT";
             int op3;
             cout<<"\n\n\n    ENTER YOUR OPTION:";
             cin>>op3;
             clrscr();
             cout<<"\n\n";
             char namegenset1[30];
             int t;
             switch(op3)
             {
                case 1:
                 strcpy(namegenset1,"silent.dat");
                 t=1;
                 break;
                case 2:
                 strcpy(namegenset1,"notsilent.dat");
                 t=2;
                 break;
             }
             display(namegenset1);
             cout<<"\n\n\n ENTER THE REFERENCE NO:";
             int refno;
             cin>>refno;
             modify(refno,t);
             break;
            }
           case 4:
            display("!!genset.dat");
            break;
           case 5:
           display2();
         }
    }
    void box()
    {
    	  char c1=178, c2=177, c3=176;
         gotoxy(1,2);
    	  for(int i=1; i<=1840; i++)
    	  {
            int j=0;
            gotoxy(j,2);
    	     cout<<c3;
            j++;
            if(j>=79)
            j=0;
         }
    }
    void setcolor(unsigned short color) 	//begining of set color funtion
    {
         HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);  	//gets std handle
         SetConsoleTextAttribute(hCon,color); 	//Sets Console Text Attribute HCon color.
    }
    void gensetrental()
    {
         for(int i=0;i<=3;i++)
         {
            clrscr();
            if(i==1||i==3)
              textcolor(BLUE);
            else
              textcolor(BLACK);
            int wait=0;
            while(++wait<1000000000)
                ;
            for(int i=0;i<=3;i++)
            {  cprintf("*");
            }
            cout<<"\n*";
            wait=0;
            while(++wait<1000000000)
                ;
         }
         getch();
    }
    void main()
    {
         textbackground(BLUE);
         setcolor(2);
         box();
         textbackground(BLACK);
         int op;
         do
         {
           clrscr();
           setcolor(5);
           gotoxy(32,8);
           setcolor(3);
           textcolor(RED);
           cprintf("WHAT DO YOU WANT TO DO:");
           gotoxy(32,10);
           setcolor(5);
           cprintf("     1.RENT A GENSET     ");
           gotoxy(32,12);
           setcolor(5);
           cprintf("     2.RETURN A GENSET    ");
           gotoxy(32,14);
           setcolor(5);
           cprintf("     3.MASTER DATA         ");
           gotoxy(33,16);
           cprintf("    4.EXIT     ");
           gotoxy(33,18);
           setcolor(4);
           cprintf("    ENTER THE OPTION:     ");
           cin>>op;
           switch(op)
           {
              case 1:
               rent("genset.dat")
               break;
              case 2:
               returning();
               break;                                  
              case 3:
               creator();
               getch();
               break;
           }
         }while(op<=3);
    }
