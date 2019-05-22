#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class biodata
{
    char dob[30];
    char name[50];
    char address[20];
    char bld[6];
    int height , weight ,  age;
   
   

  public:
    void readdata()
    {
     
           cout<<"\n\tEnter name of the member: ";
           cin.getline(name, 100);
           cout<<"\tEnter date of birth: ";
            cin.getline(dob, 100);
           cout<<"\tEnter the address   ";
           cin.getline(address, 100);   
           cout<<"\n\tENTER MEDICAL INFORMATION: ";
           cout<<"\n\tEnter height: " ;
            cin>>height;
           cout<<"\n\tEnter weight:  ";
           cin>>weight;       
           cout<<"\n\tEnter bloodgroup: ";
           cin.getline(bld, 100);
           cout<<"\tEnter age: ";
            cin>>age;
          
     }
   
    void show()
    {
        cout<<"\n\n\n\tName of member: ";
        puts(name);
        cout<<"\tDate of birth: ";
        puts(dob);
        cout<<"\tAddress: ";
        puts(address);
        cout<<"\nMEDICAL INFORMATION: ";
        cout<<"\n\tHeight: " ;
         cout<<height;
        cout<<"\n\tWeight:  ";
        cout<<weight;       
        cout<<"\n\tBloodgroup: ";
        puts(bld);
        cout<<"\tAge: ";
         cout<<age;
    }
   
    void modify()
    {
         cout<<"\n\tEnter height: ";
        cin>>height;
        cout<<"\n\tEnter weight: ";
        cin>>weight;
        cout<<"\n\tEnter age: ";
        cin>>age;
        cout<<"\n\n\tRecord changed!";
    }
   
    int compare(char A[])
    {
        return strcmp(name,A);
    }
   
   
};

void write()
{
      ofstream fout;
      biodata obj;
      char ch;
      fout.open("biodata.dat", ios::out|ios::binary|ios::app);
      do
      {
              obj.readdata();
              fout.write((char*)&obj,sizeof(obj));
              cout<<"do you want to enter more?";
              cin>>ch;
      }while(ch=='y');
      fout.close();
      cout<<"\n\n\tRecord created!";

}

void sho()
{
    ifstream fin;
    fin.open("biodata.dat",ios::in|ios::binary);
    biodata obj;
    while(fin.read((char*)&obj,sizeof(obj)))
    {
        obj.show();
    }
    fin.close();   
}

void mod()
{
    char found='f';
    fstream fp;
    fp.open("biodata.dat",ios::in|ios::binary);
    char Name[50];
    biodata obj;
    cout<<"\t Enter the name: ";
    cin.getline(Name, 100);
    int check=0;
    while(!fp.eof())
    {
        fp.read((char*)&obj,sizeof(obj));
        check=obj.compare(Name);
        if(check==1)
        {    found='t';
            fp.seekp(-1*sizeof(obj),ios::cur);
            cout<<"\n\t MEDICAL INFORMATION: \n";
            obj.modify();
            fp.write((char*)&obj,sizeof(obj));
        }
    }
    if(found=='f')
    cout<<"\n\t Record not found!! \n\n";
    fp.close();
}
void BIODATA()
{
    int ch;
    cout<< "       | :::::::::::::::::::::   BIODATA   ::::::::::::::::::::: |\n\n" ;
    start:;
    cout<<"\n\n\t 1: ENTER DETAILS";
    cout<<"\n\n\t 2: SEARCH DETAILS";
    cout<<"\n\n\t 3: MODIFY DETAILS";
    cout<<"\n\n\t 4: Exit";
    cout<<"\n\n\t Enter your choice (1-4): ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   ENTER DETAILS   ::::::::::::::::::::: |\n\n" ;
                write();
                goto start;
            }
        case 2:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   SHOW DETAILS    ::::::::::::::::::::: |\n\n" ;
                sho();
                goto start;
            }
        case 3:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   MODIFY DETAILS  ::::::::::::::::::::: |\n\n" ;
                mod();
                goto start;
            }
        case 4:
            break;
        default:
            {    cout<<"\n\t Choice Invalid \n";
                goto start;
            }
    }
   
}

void GRAPHCALC()
{
    int i,j,k,ch,start;
    float size=10;
    start:
    printf("\033c");
   
    cout << "    | :::::::::::::::::::::   GRAPHIC CALCULATOR   ::::::::::::::::::::: |\n" ;
    cout<<"\n\n\t 1 : LINEAR EQUATION \n";
     cout<<"\n\t 2 : QUADRATIC EQUATION \n";
     cout<<"\n\t 3 : CUBIC EQUATION \n";
     cout<<"\n\t 4 : EXIT  \n\n";
     cout<<"\t Enter your choice: ";
    ch = getchar();

    if(ch=='1')                    //LINEAR START
    {   
        printf("\033c");                                                                                     
        cout << "    | :::::::::::::::::::::    LINEAR  EQUATION    ::::::::::::::::::::: |\n" ;
       
        float x, y, a, b ;
        cout <<    "\n Enter coefficient of 'x'\t: " ;
        cin >> a ;
        cout << "\n Enter Constant ('0' if None)\t: " ;
        cin >> b ;
        cout << "\n Your Equation : y = " << a << "(x^1) + " << b << " \n\n\n"  ;
       
        if(a==0)                               //CHECK FOR LINEAR                  
        {
            cout << "\n\n  ::::::::::::::ERROR: Co-efficient Of 'x^1' Cannot Be Zero::::::::::::::    \n\n" ;
            cout << "\n\tPress Any Key To Go To Main Menu "  ;
            getchar() ;
            goto start;
           

        }
       
        float nsize = (-1*size) ;
        for(x=nsize; x<size ; x++) // LOOP TO PRINT * AT CO-ORDINATES
        {
            y = (x*a) + b ;
            cout<<setw(y+200) << "*" << "  ("<<x<<","<<y<< ")\n" ;
        }
        cout << "\n\tPress Any Key To Go To Main Menu "  ;
        getchar() ;
        goto start ;
    }
   
    else if(ch=='2')
        {
            system("cls") ;
            cout << "    | :::::::::::::::::::::   QUADRATIC EQUATION   ::::::::::::::::::::: |\n" ;
                       
            float a ,b, c, x ,y ;

            cout <<    "\n\tEnter coefficient of 'x^2'\t: " ;
            cin >> a ;
            cout <<    "\n\tEnter coefficient of 'x'\t: " ;
            cin >> b ;
            cout << "\n\tEnter Constant ('0' If None)\t: " ;
            cin >> c ;
            cout << "\n\tYour Equation\t: y = " << a << "(x^2) + " << b << "(x^1) + " << c <<" \n\n\n";

            if(a==0)                        // QUADRATIC EQUATION VERIFICATION
            {
                cout << "\n\n  ::::::::::::::ERROR: Co-efficient Of 'x^2' Cannot Be Zero::::::::::::::    \n\n" ;
                cout << "\n\tPress Any Key To Go To Main Menu "  ;
                getchar() ;
                goto start ;
            }

            float nsize = (-1*size) ;
            for(x=nsize; x<=size; x+=0.5)
            {
                y = (a*x*x) + (b*x) + c ;
                cout<<setw(y+200) << "*" << "  ("<<x<<","<<y<< ")\n" ;
            }

            cout << "\n\tPress Any Key To Go To Main Menu "  ;
            getchar() ;
            goto start ;

        }
       
        else if(ch=='3')

        {
            system("cls") ;
            cout << "    | :::::::::::::::::::::     CUBIC EQUATION     ::::::::::::::::::::: |\n" ;
           
            float a, b, c, d , x, y ;

            cout <<  "\n\tEnter coefficient of 'x^3'\t: " ;
                cin >> a ;
            cout <<  "\n\tEnter coefficient of 'x^2'\t: " ;
                cin >> b ;
            cout <<    "\n\tEnter coefficient of 'x'\t: " ;
                cin >> c ;
            cout << "\n\tEnter Constant ('0' If None)\t: " ;
                cin >> d ;
            cout << "\n\tYour Equation\t: y = " << a << "(x^3) + " << b << "(x^2) + " << c << "(x^1) + " << d << "\n\n\n" ;

            if(a==0)                            // CUBIC EQUATION VERIFICATION
            {
                cout << "\n\n\t\tERROR: Co-efficient Of 'x^3' Cannot Be Zero\n\n" ;
                cout << "\n\tPress Any Key To Go To Main Menu "  ;
            getchar() ;
            goto start ;
            }

            float nsize = (-1*size) ;
            for(x=nsize; x<=size; x+=1)
            {
                y = (a*x*x*x) + (b*x*x) + (c*x) + d ;
                cout<<setw(y+200) << "*" << "  ("<<x<<","<<y<< ")\n" ;
            }

            cout << "\n\tPress Any Key To Go To Main Menu "  ;
            getchar() ;
            goto start ;
        }
       
        else if(ch=='4')    
        {
              system("cls") ;
        }

        else                                       
            {   
                printf("\033c");
                cout     << "\a\n\n :::::::::::::::::::::::  ERROR:  Invalid Choice  :::::::::::::::::::::::\n\n";
                cout<<"\n\tpress any key";
                getchar();
                goto start ;
            }
}

void CALC()
{
    int ch;
     int ch1;
     int ch2;
     int ch3;
     int ch4;
     float a,b;
     double a1,b1;
     float result;
     double result1;
     do
     {
         printf("\033c");
        cout << "\n    | :::::::::::::::::::::   SCIENTIFIC CALCULATOR   ::::::::::::::::::::: |\n" ;
        cout<<"\n\n\t 1 : ARITHMETIC FUNCTIONS \n";
         cout<<"\n\t 2 : TRIGONOMETRIC FUNCTIONS \n";
         cout<<"\n\t 3 : LOGARITHIMIC FUNCTIONS \n";
         cout<<"\n\t 4 : POWER FUNCTIONS \n";
         cout<<"\n\t 5 : EXIT  \n\n";
         cout<<"\t Enter your choice: ";
        ch = getchar();
           
            switch(ch)
             {   
                case '1':
                  {       
                      printf("\033c");
                    cout << "    | :::::::::::::::::::::    ARITHMETIC OPERATIONS    ::::::::::::::::::::: |\n" ;
                    ari: cout<<"\n";
                    cout<<"\t 1 : Addition \n";
                      cout<<"\t 2 : Subtraction \n";
                      cout<<"\t 3 : Multipilication \n";
                      cout<<"\t 4 : Division \n\n";
                      cout<<"\t Enter your choice: ";
                      ch1 = getchar();
                      printf("\033c");
                     switch(ch1)
                      {
                        case '1':
                            {
                                cout<<"ADDITION: ";
                                cout<<"\n\nEnter first number: ";
                                cin>>a;
                                cout<<"Enter another number: ";
                                cin>>b;
                                result=a+b;
                            cout<<"Result of addition = "<<result<<endl;
                            system("pause");
                            break;
                        }               
                    case '2':
                        {
                               cout<<"SUBTRACTION: ";
                            cout<<"\n\nEnter first number: ";
                            cin>>a;
                            cout<<"Enter another number: ";
                            cin>>b;
                               result=a-b;
                               cout<<"Result of subtraction = "<<result<<endl;
                               system("pause");
                            break;
                        }

                    case '3':
                        {
                               cout<<"MULTIPLICATION: ";
                            cout<<"\n\nEnter first number: ";
                            cin>>a;
                            cout<<"Enter another number: ";
                            cin>>b;
                               result=a*b;
                               cout<<"Result of multiplication = "<<result<<endl;
                               system("pause");
                            break;
                           }
              
                    case '4':       
                        {
                            cout<<"DIVISION: ";
                            div: ;
                            cout<<"\n\nEnter first number: ";
                            cin>>a;
                            cout<<"Enter another number: ";
                            cin>>b;
                              if(b!=0)
                               {
                                result=a/b;
                                  cout<<"Result of division = "<<result<<endl;
                                  system("pause");
                               }
                               else
                               {
                                   cout<<"\nERROR: Not divisible by zero.\n";
                                   cout<<"Enter again: ";
                                   goto div;
                            }
                            break;
                        }
                   
                    default:
                        {
                            cout<<"\t Choice invalid\n";
                            goto ari;
                        }
                  
                  }// end of inner switch
                  break;
            }// end of case 1 arithmatic operation

             case '2':
             {
                  printf("\033c");
                cout << "  | :::::::::::::::::::::   TRIGONOMETRIC FUNCTIONS    ::::::::::::::::::::: |\n" ;
                trig: cout<<"\n";
                cout<<"\t 1 : Sin function \n";
                  cout<<"\t 2 : Cos function \n";
                  cout<<"\t 3 : Tan function \n";
                cout<<"\t Enter your choice: ";
                ch2=getchar();
                printf("\033c");
               
                switch(ch2)
                {
                    case '1':
                         {
                             cout<<"SINE FUNCTION: ";
                            cout<<"\n\nEnter a number: ";
                             cin>>a1;
                             result1=(sin(a1));
                            cout<<"sine("<<a1<<") = "<<result1<<endl;
                             system("pause");
                             break;
                        }
   
                    case '2':
                         {
                            cout<<"COS FUNCTION: ";
                            cout<<"\n\nEnter a number: ";
                             cin>>a1;
                            result1=(cos(a1));
                              cout<<"cos("<<a1<<") = "<<result1<<endl;
                              system("pause");
                            break;
                           }
   
                    case '3':
                         {
                            cout<<"TAN FUNCTION: ";
                             cin>>a1;
                            result1=(tan(a1));
                              cout<<"tan("<<a1<<") = "<<result1<<endl;
                              system("pause");
                              break;

                        }
                   
                    default:
                        {
                            cout<<"\t Choice invalid\n";
                            goto trig;
                        }   

                   }// inner switch
                break;
             }//inner case 2 trignomatic
              
            case '3':
             {
                   printf("\033c");
                cout << "  | :::::::::::::::::::::   LOGARITHIMIC FUNCTIONS    ::::::::::::::::::::: |\n" ;
                log: cout<<"\n";
                cout<<"\t 1 : Natural log\n";
                cout<<"\t 2 : log with base 10 \n";
                cout<<"\t Enter your choice: ";
                ch3=getchar();
                printf("\033c");
               
                switch(ch3)
                   {
                    case '1':
                         {
                            cout<<"NATURAL LOG: ";
                            cout<<"\n\nEnter a number: ";
                             cin>>a1;
                            result1=log(a1);
                            cout<<"log("<<a1<<") = "<<result1<<endl;
                            system("pause");
                            break;
                           }
                    case '2':
                         {
                             cout<<"COMMON LOG: ";
                            cout<<"\n\nEnter a number: ";
                             cin>>a1;
                            result1= log10(a1);
                             cout<<"log10("<<a1<<") = "<<result1<<endl;
                             system("pause");
                             break;
                         }
                     default :
                         {
                             cout<<"\t Choice invalid\n";
                            goto log;
                        }
                   }// end of switch
                   break;
             }// end of case 3 logrithmic
   
            case '4':
             {
                 printf("\033c");
                 cout << "      | :::::::::::::::::::::   POWER FUNCTIONS    ::::::::::::::::::::: |\n" ;
                powr: cout<<"\n";
                cout<<"\t 1 : Press 1 for Power \n";
                cout<<"\t 2 : Press 2 for Square root \n";
                cout<<"\t Enter your choice: ";
                ch4=getchar();
                printf("\033c");
               
                switch(ch4)
                {
                    case '1':
                        {
                              cout<<"POWER: ";
                            cout<<"\n\nEnter a number: ";
                              cin>>a1;
                              cout<<"Enter power: ";
                              cin>>b1;
                              result1=pow(a1,b1);
                              cout<<a1<<"^"<<b1<<"= "<<result1<<endl;
                              system("pause");
                              break;
                         }
                    case '2':
                         {
                              cout<<"SQUARE ROOT: ";
                            cout<<"\n\nEnter a number: ";
                              cin>>a;
                              result1=sqrt(a);
                              cout<<"Square root of "<<a<<"= "<<result1<<endl;
                              system("pause");
                              break;
                         }
                    default :
                         {
                             cout<<"\t Choice invalid\n";
                            goto powr;
                        }   
                }// end of switch
                   break;
            }// end of case power function
   
              case '5': break;
           
            default: cout<<"\n\t Choice invalid\n";
        }// outer switch
       
    }while(ch!='5');
}


char turn;
int draw = 0;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void display_board()
{
    printf("\033c");
    cout << "        | :::::::::::::::::::::   TIC TAC TOE    ::::::::::::::::::::: |\n" ;
    cout << "\n\t Player 1 (X)  -  Player 2 (O)" << "\n";
    cout << "\n";
    cout <<"\t"<< "     |     |     " << "\n";
    cout <<"\t"<< "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout <<"\t"<< "_____|_____|_____" << "\n";
    cout <<"\t"<< "     |     |     " << "\n";
    cout <<"\t"<< "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout <<"\t"<< "_____|_____|_____" << "\n";
    cout <<"\t"<< "     |     |     " << "\n";
    cout <<"\t"<< "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout <<"\t"<< "     |     |     " << "\n";
}

void player_turn()
{
    int choice;
    int row = 0, column = 0;
   
    if (turn == 'X')
    cout<<"\n\t" << " Player 1 turn [X]: ";
   
    else if (turn == 'O')
    cout<<"\n\t" << " Player 2 turn [O]: ";
    cin >> choice;
   
    switch (choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "You didn't enter a correct number! Try again\n";
            player_turn();
    }
   
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "The cell you chose is used! Try again\n";
        player_turn();
    }

}

int gameover()
{
    for (int i = 0; i < 3; i++)//Check for a win
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;
       
    }
   
    for (int i = 0; i < 3; i++)//Check for draw
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            return 0;
        }
    }
    draw = 1;
    return 1;
}

void GAME()
{
    char ch;
    cout<< "        | :::::::::::::::::::::   TIC TAC TOE    ::::::::::::::::::::: |\n\n" ;
    cout<<"\t HOW TO PLAY\n";
    cout<< "\t Player 1 [X] --- Player 2 [O]\n";
    cout<<"\t Choose any tile numbered from 1-9 for your respective X and O \n\n";
    cout<<"\t Press P to start playing or X to exit: ";
    ch=getchar();
    switch(ch)
    {  
        case 'x': break;
        case 'X': break;
        default:
            {
                turn = 'X';
                while (!gameover())
                {
                    display_board();
                    player_turn();
                    gameover();
                }   
   
                if (turn == 'O' && !draw)
                {
                    display_board();
                    cout << "\n" << "\n" << "\t Player 1 [X] Wins! Game Over!\n";
                   }
                else if (turn == 'X' && !draw)
                {
                    display_board();
                    cout << "\n" << "\n" << "\t Player 2 [O] Wins! Game Over!\n";
                }
                else
                {
                    display_board();
                    cout << "\n" << "\n" << "\t It's a draw! Game Over!\n";
                }
            }
        break;
    }
   
}

class listi
{       
    char ITEM[45];
    char QUANTITY[15];
   
    public:
        void getdata()
        {
            cout<<"\n\n\tEnter Item name: ";
            cin>>ITEM;
            cout<<"\tEnter Quantity: ";
            cin>>QUANTITY;
           
        }
       
        void printdata()
        {
            cout<<"\tItem: ";
            puts(ITEM);
            cout<<"\tQuantity: ";
            puts(QUANTITY);
            cout<<"\n";
        }
};

void additem()
{
    printf("\033c");
    cout<< "       | :::::::::::::::::::::   ENTER ITEM    ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\tEnter the items you want to add: ";
    ofstream fout;
    fout.open("List.dat",ios::out|ios::binary|ios::app);
    listi obj;
    char ch;
    do
    {   
        obj.getdata();
        fout.write((char*)&obj,sizeof(obj));
        cout<<"\n\tDo you want to enter more? : (y/n) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fout.close();
}

void showitem()
{
    printf("\033c");
    cout<< "       | :::::::::::::::::::::   LIST    ::::::::::::::::::::: |\n\n" ;
    ifstream fin;
    fin.open("List.dat",ios::in|ios::binary);
    listi obj;
    while(fin.read((char*)&obj,sizeof(obj)))
    {
        obj.printdata();
    }
    getchar();
    fin.close();
}

void SHOPLIST()
{   
    char ch;
    star:;
    printf("\033c");
    cout<< "       | :::::::::::::::::::::   SHOPPING LIST    ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\n\t ::::::MENU::::::";
    cout<<"\n\t 1: Enter item.";
    cout<<"\n\t 2: See list";
    cout<<"\n\t 3: Exit";
    cout<<"\n\t Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case '1':
            {
                additem();
                goto star;
                break;
            }
        case '2':
            {   
                showitem();
                getchar();
                printf("\033c");
                SHOPLIST();
            }
        case '3':
            break;
        default:
            goto star;
           
    }
   
}

class Schedule
{
    int Year;
    int Month;
    int Date;
    char Event[70];
    char Location[30];
    char Time[10];
   
    public:
        void entevent()
        {
            cout<<"\t Enter Date (YYYY MM DD): ";
            cin>>Year>>Month>>Date;           
            cout<<"\t Enter Time (HH:MM) : ";
            cin.getline(Time, 100);
            cout<<"\t Enter event: ";
            cin.getline(Event, 100);
            cout<<"\t Enter Lcation: ";
            cin.getline(Location, 100);
        }
       
        void shwevent()
        {
            cout<<"\n\t Event date: ";
            cout<<Date<<"/"<<Month<<"/"<<Year;
            cout<<"\t Event time: ";
            puts(Time);
            cout<<"\t Event description: ";
            puts(Event);
            cout<<"\t Event location: ";
            puts(Location);
            cout<<"\n";
        }
        int compare(int year, int month, int date)
        {
            if(Year==year && Month==month && Date==date)
            return 1;
        }
        int compare(int year, int month, int date, char T[])
        {
            if(Year==year && Month==month && Date==date && strcmp(Time,T)==0)
            return 1;
        }   
};

void enter()
{
    ofstream fout;
    fout.open("Schedule.dat",ios::out|ios::binary|ios::app);
    Schedule obj;
    char ch;
    do
    {   
        obj.entevent();
        fout.write((char*)&obj,sizeof(obj));
        cout<<"\n\t Do you want to enter more events? : (y/n) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fout.close();
}

void show()
{
    ifstream fin;
    fin.open("Schedule.dat",ios::in|ios::binary);
    Schedule obj;
    time_t t=time(0);
    struct tm*now=localtime(&t);
    int year=now->tm_year+1900;
    int month=now->tm_mon+1;
    int date=now->tm_mday;
    int check=0;
    while(fin.read((char*)&obj,sizeof(obj)))
    {
        check=obj.compare(year,month,date);
        if(check==1)
        obj.shwevent();
    }
    fin.close();   
}

void search()
{
    int Year, Month, Date;
    char found='f';
    ifstream fin;
    fin.open("Schedule.dat",ios::in|ios::binary);
    Schedule obj;
    cout<<"\t Enter Date (YYYY MM DD) to be searched: ";
    cin>>Year>>Month>>Date;
    int check=0;
    while(!fin.eof())
    {
        fin.read((char*)&obj,sizeof(obj));
        found='t';
        check=obj.compare(Year,Month,Date);
        if(check==1)
        obj.shwevent();
    }
    if(found=='f')
    cout<<"\n\t Record not found!! ";
    fin.close();
   
}

void modify()
{
    int Year, Month, Date;
    char Time[5],found='f';
    fstream fp;
    fp.open("Schedule.dat",ios::in|ios::binary);
    Schedule obj;
    cout<<"\t Enter Date (YYYY MM DD) to be searched: ";
    cin>>Year>>Month>>Date;
    cout<<"\t Enter the time  of the task (HH:MM):";
    cin.getline(Time, 100);
    int check=0;
    while(!fp.eof())
    {
        fp.read((char*)&obj,sizeof(obj));
        check=obj.compare(Year,Month,Date,Time);
        if(check==1)
        {    found='t';
            fp.seekp(-1*sizeof(obj),ios::cur);
            cout<<"\n\t Enter new data: \n";
            enter();
            fp.write((char*)&obj,sizeof(obj));
        }
    }
    if(found=='f')
    cout<<"\n\t Record not found!! \n\n";
    fp.close();
}

void del()
{
    fstream f1,f2;
    f1.open("Schedule.dat",ios::in|ios::binary);
    f2.open("Temp.dat",ios::in|ios::binary);
    int Year, Month, Date;
    char Time[5],con, found='f';
    Schedule obj;
    cout<<"\t Enter Date (YYYY MM DD) to be searched: ";
    cin>>Year>>Month>>Date;
    cout<<"\t Enter the time  of the task (HH:MM): ";
    int check=0;
    while(!f1.eof())
    {
        f1.read((char*)&obj,sizeof(obj));
        check=obj.compare(Year,Month,Date,Time);
        if(check==1)
        {   
            obj.shwevent();
            found='t';
            cout<<"\n\t Are you sure you want to delete the event? : (y/n) ";
            cin>>con;
            if(con=='n'||con=='N')
            f2.write((char*)&obj, sizeof(obj));
        }
        else
        f2.write((char*)&obj, sizeof(obj));
    }
    if(found=='f')
    cout<<"\n\t Record not found!! ";
    f1.close();
    f2.close();
    remove("Schedule.dat");
    rename("temp.dat","Schedule.dat");
}

void SCHEDULER()
{
    int ch;
    cout<< "       | :::::::::::::::::::::   TASK SCHEDULER    ::::::::::::::::::::: |\n\n" ;
    cout<<"\t Today's Events: \n";
    show();
    start:;
    cout<<"\n\t ::::::MENU::::::";
    cout<<"\n\t 1: Enter event.";
    cout<<"\n\t 2: Search event";
    cout<<"\n\t 3: Modify event";
    cout<<"\n\t 4: Delete event";
    cout<<"\n\t 5: Exit";
    cout<<"\n\t Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   ENTER EVENT    ::::::::::::::::::::: |\n\n" ;
                enter();
                goto start;
            }
        case 2:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   SEARCH EVENT    ::::::::::::::::::::: |\n\n" ;
                search();
                goto start;
            }
        case 3:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   MODIFY EVENT   ::::::::::::::::::::: |\n\n" ;
                modify();
                goto start;
            }
        case 4:
            {    printf("\033c");
                cout<< "       | :::::::::::::::::::::   DELETE EVENT   ::::::::::::::::::::: |\n\n" ;
                del();
                goto start;
            }
        case 5:
            break;
        default:
            {    cout<<"\n\t Choice Invalid \n";
                goto start;
            }
    }
   
}

class student
{
    char name[50],ename[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade;
    int std;
    void calculate()
    {
        per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
        if(per>=60)
            grade='A';
        else if(per>=50 && per<60)
            grade='B';
        else if(per>=33 && per<50)
            grade='C';
        else
            grade='F';
    }
public:
    void getdata()
    {
        cout<<"\n\n\tEnter The Name of student ";
        cin.getline(name, 100);
        cout<<"\n\tEnter the name of the Examination: ";
        cin.getline(ename, 100);
        cout<<"\n\tEnter The marks in physics out of 100 : ";
        cin>>p_marks;
        cout<<"\n\tEnter The marks in chemistry out of 100 : ";
        cin>>c_marks;
        cout<<"\n\tEnter The marks in maths out of 100 : ";
        cin>>m_marks;
        cout<<"\n\tEnter The marks in english out of 100 : ";
        cin>>e_marks;
        cout<<"\n\tEnter The marks in computer science out of 100 : ";
        cin>>cs_marks;
        calculate();
    }

    void showdata()
    {
        cout<<"\n\n\tName of student : ";
        puts(name);
        cout<<"\n\tName of Examination : ";
        puts(ename);
        cout<<"\tMarks in Physics out of 100: "<<p_marks;
        cout<<"\n\tMarks in Chemistry out of 100: "<<c_marks;
        cout<<"\n\tMarks in Maths out of 100: "<<m_marks;
        cout<<"\n\tMarks in English out of 100: "<<e_marks;
        cout<<"\n\tMarks in Computer Science out of 100: "<<cs_marks;
        cout<<"\n\tPercentage of student is out of 100: "<<setprecision(2)<<per;
        cout<<"\n\tGrade of student is :"<<grade;
    }
   
    char*search()
    {
        return ename;
    }

};

fstream fp;
student st;

void REPORTCARD();
void write_student()
{
    fp.open("student.dat",ios::out|ios::app);
    st.getdata();
    fp.write((char*)&st,sizeof(student));
    fp.close();
    cout<<"\n\tStudent record Has Been Created. ";
    getchar();
    printf("\033c");
    REPORTCARD();
}

void display_all()
{
    printf("\033c");
    cout<< "       | :::::::::::::::::::::   DISPLAY RECORD   ::::::::::::::::::::: |\n\n" ;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        st.showdata();
        cout<<"\n\n\t====================================\n";
    }
    fp.close();
    getchar();
    REPORTCARD();
}

void display_sp(char A[])
{
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmp(st.search(),A)==0)
        {
            st.showdata();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nrecord not exist";
    getchar();
    REPORTCARD();
}

void REPORTCARD()
{
    printf("\033c");
    char ch2;
    cout<< "       | :::::::::::::::::::::   REPORT CARD    ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\n\t1.CREATE RECORD";
    cout<<"\n\n\t2.DISPLAY ALL RECORDS";
    cout<<"\n\n\t3.SEARCH RECORD ";
    cout<<"\n\n\t4.EXIT";
    cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
    ch2=getchar();
    switch(ch2)
    {
    case '1':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   ENTER RECORD    ::::::::::::::::::::: |\n\n" ;
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        char A[15];
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   SEARCH RECORD    ::::::::::::::::::::: |\n\n" ;
        cout<<"\n\n\tPlease Enter The name of examination: ";
        cin.getline(A, 100);
        display_sp(A);
        break;
    case '4':
        break;
    default:
        cout<<"\a";
        REPORTCARD();
    }
}

class budget
{
    char month[10];
    double income;
    double housing;
    double utilities;
    double household_expenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
    double total;
    double savings;
   
    void calculate()
    {
        total= housing + utilities + household_expenses + transportation + food + medical + insurance + entertainment + clothing + miscellaneous;
        savings = income-total;
    }
   
    public:
        void getdata()
        {
            cout<<"\n\tEnter Month: ";
            cin.getline(month, 100);
            cout<<"\tEnter Income: ";
            cin>>income;
            cout<<"\tEnter housing: ";
            cin>>housing;
            cout<<"\tEnter utilities: ";
            cin>>utilities;
            cout<<"\tEnter household_expenses: ";
            cin>>household_expenses;
            cout<<"\tEnter transportation: ";
            cin>>transportation;
            cout<<"\tEnter food: ";
            cin>>food;
            cout<<"\tEnter medical: ";
            cin>>medical;
            cout<<"\tEnter insurance: ";
            cin>>insurance;
            cout<<"\tEnter entertainment: ";
            cin>>entertainment;
            cout<<"\tEnter clothing: ";
            cin>>clothing;
            cout<<"\tEnter imiscellaneous: ";
            cin>>miscellaneous;
        }   
       
        void printdata()
        {
            cout<<"\n\n\tMonth: ";
            puts(month);
            cout<<"\tIncome: ";
            cout<<income;
            cout<<"\n\thousing: ";
            cout<<housing;
            cout<<"\n\tutilities: ";
            cout<<utilities;
            cout<<"\n\thousehold_expenses: ";
            cout<<household_expenses;
            cout<<"\n\ttransportation: ";
            cout<<transportation;
            cout<<"\n\tfood: ";
            cout<<food;
            cout<<"\n\tmedical: ";
            cout<<medical;
            cout<<"\n\tinsurance: ";
            cout<<insurance;
            cout<<"\n\tentertainment: ";
            cout<< entertainment;
            cout<<"\n\tclothing: ";
            cout<<clothing;
            cout<<"\n\tmiscellaneous: ";
            cout<<miscellaneous;
            calculate();
            cout<<"\n\tTotal: ";
            cout<<total;
            cout<<"\n\tSavings: ";
            cout<<savings;
        }
       
    char*getmon()
        {
            return month;
        }
       
   
   
};

void BUDGET();
void budent()
{
    ofstream fout;
    fout.open("Budget.dat",ios::out|ios::binary|ios::app);
    budget obj;
    char ch;
    do
    {   
        obj.getdata();
        fout.write((char*)&obj,sizeof(obj));
        cout<<"\n\tDo you want to enter more? : (y/n) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fout.close();
    cout<<"\n\tBudget Has Been Created. ";
    getchar();
    printf("\033c");
    BUDGET();
}

void budshow()
{
    ifstream fin;
    fin.open("Budget.dat",ios::in|ios::binary);
    budget obj;
    while(!fin.eof())
    {
        fin.read((char*)&obj,sizeof(obj));
        obj.printdata();
    }
    fin.close();
    getchar();
    printf("\033c");
    BUDGET();   
}

void budsearch()
{
    char found='f';
    char month[10];
    ifstream fin;
    fin.open("Budget.dat",ios::in|ios::binary);
    budget obj;
    cout<<"\t Enter Month to be searched: ";
    cin.getline(month, 100);
    while(!fin.eof())
    {
        fin.read((char*)&obj,sizeof(obj));
        found='t';
        if(strcmp(obj.getmon(),month)==0)
        obj.printdata();
    }
    if(found=='f')
    cout<<"\n\t Record not found!! ";
    fin.close();
    getchar();
    printf("\033c");
    BUDGET();
   
}

void BUDGET()
{
    printf("\033c");
    char ch2;
    cout<< "       | :::::::::::::::::::::   BUDGET    ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\t :::::: MENU ::::::";
    cout<<"\n\n\t1.Enter expenses";
    cout<<"\n\t2.Display all expenses";
    cout<<"\n\t3.Search for monthly expense ";
    cout<<"\n\t4.Exit";
    cout<<"\n\tPlease Enter Your Choice (1-4) ";
    ch2=getchar();
    switch(ch2)
    {
    case '1':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   ENTER EXPENSES    ::::::::::::::::::::: |\n\n" ;
        budent();
        break;
    case '2':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   DISPLAY EXPENSES   ::::::::::::::::::::: |\n\n" ;
        budshow();
        break;
    case '3':
        char A[15];
        printf("\033c");
        cout<< "   | :::::::::::::::::::::   SEARCH MONTHLY EXPENSE    ::::::::::::::::::::: |\n\n" ;
        budsearch();
        break;
    case '4':
        break;
    default:
        cout<<"\a";
        REPORTCARD();
    }   
   
}

class quiz
{
    char que[200];
    char opta[50];
    char optb[50];
    char optc[50];
    char optd[50];
    char cor;
   
    public:
       
        void entques()
        {
            cout<<"\tEnter the question: ";
            cin.getline(que, 100);
            cout<<"\tEnter option 'a': ";
            cin.getline(opta, 100);
            cout<<"\tEnter option 'b': ";
            cin.getline(optb, 100);
            cout<<"\tEnter option 'c': ";
            cin.getline(optc, 100);
            cout<<"\tEnter option 'd': ";
            cin.getline(optd, 100);
            cout<<"\tEnter the correct option: ";
            cin>>cor;
        }
       
        void showques()
        {
            cout<<"\n\tQuestion: ";
            puts(que);
            cout<<"\tOption 'a': ";
            puts(opta);
            cout<<"\tOption 'b': ";
            puts(optb);
            cout<<"\tOption 'c': ";
            puts(optc);
            cout<<"\tOption 'd': ";
            puts(optd);
        }
       
        int check()
        {
            char ch;
            cout<<"\tEnter answer: ";
            cin>>ch;
            if(ch==cor)
            {
                cout<<"\tCorrect answer!! Correct answer is: "<<cor;
                return 1;
            }
            else
            cout<<"\tWrong answer!! Correct answer is: "<<cor;
        }
};

void QUIZ();
void quesent()
{
    ofstream fout;
    fout.open("Quiz.dat",ios::out|ios::binary|ios::app);
    quiz obj;
    char ch;
    do
    {   
        obj.entques();
        fout.write((char*)&obj,sizeof(obj));
        cout<<"\n\tDo you want to enter more? : (y/n) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fout.close();
    cout<<"\n\tOuestion Has Been Added. ";
    getchar();
    printf("\033c");
    QUIZ();
}

void quesshow()
{
    ifstream fin;
    fin.open("Quiz.dat",ios::in|ios::binary);
    quiz obj;
    char ch;
    int score=0;
    while(fin.read((char*)&obj,sizeof(obj)))
    {
        obj.showques();
        if(obj.check()==1)
        ++score;
        cout<<"\n\tScore is: "<<score;
        cout<<"\n\tDo you want to quit?? (y/n) ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
            cout<<"\n\tFinal score is: "<<score;
            break;
        }
    }
    fin.close();
    getchar();
    printf("\033c");
    QUIZ();   
}

void QUIZ()
{
    printf("\033c");
    char ch2;
    cout<< "       | :::::::::::::::::::::        QUIZ        ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\t1.ENTER QUESTION";
    cout<<"\n\n\t2.TAKE QUIZ";
    cout<<"\n\n\t3.EXIT";
    cout<<"\n\n\tPlease Enter Your Choice (1-3) ";
    ch2=getchar();
    switch(ch2)
    {
    case '1':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   ENTER QUESTIONS    ::::::::::::::::::::: |\n\n" ;
        quesent();
        break;
    case '2':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   QUIZ   ::::::::::::::::::::: |\n\n" ;
        quesshow();
        break;
    case '3':
        break;
    default:
        cout<<"\a";
        QUIZ();
    }
}

class phonebook
 {  
     char pname[40];
     char paddress[50];
     float phoneno;
 
     public:void phone_book()
    {
        cout<<"\n\tEnter the name : ";
        cin.getline(pname, 100);
        cout<<"\t Enter the address : ";
        cin.getline(paddress, 100);
        cout<<"\n\tEnter the phone number : ";
        cin>>phoneno;
    }
    void show_book()
    {
        cout<<"\n\tAdress : ";
        puts(paddress);
        cout<<"\tName : ";
        puts(pname);       
        cout<<"\tphone number : "<<phoneno;
   
    }
    int retname(char a[])
    {
       if(strcmp(pname,a)==0)
       return 0;
       else
       return 1;
    }
       
   
  
};


void phwrite()
{ 
      ofstream fout;
      phonebook obj;
      char ch;
      fout.open("phone.dat", ios::out|ios::binary|ios::app);
      do
      {
           
           obj.phone_book();
           fout.write((char*)&obj,sizeof(obj));
           cout<<"\n\tDo you want to enter more?";
              cin>>ch;
      }while(ch=='y');
      fout.close();
     
}
void phread()
{
   
      ifstream fin;
      phonebook obj;
      char mname[30];
     
      fin.open("phone.dat",ios::in|ios::binary);
      while(fin.read((char*)&obj,sizeof(obj)))
      { cout<<"\n\tEnter the name to be searched: ";
        cin.getline(mname, 100);
          if(obj.retname(mname)==0)
          obj.show_book();
      }
      fin.close();
     
}
void PHONEBOOK()
{
    pho:;
    printf("\033c");
    char ch2;
    cout<< "       | :::::::::::::::::::::    PHONEBOOK    ::::::::::::::::::::: |\n\n" ;
    cout<<"\n\t :::::: MENU ::::::";
    cout<<"\n\t1.Enter phoneno.";
    cout<<"\n\n\t2.Search phoneno.";
    cout<<"\n\n\t3.Exit";
    cout<<"\n\n\tPlease Enter Your Choice (1-3) ";
    cin>>ch2;
    switch(ch2)
    {
    case '1':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   ENTER PHONENO.    ::::::::::::::::::::: |\n\n" ;
        phwrite();
        getchar();
        goto pho;
        break;
    case '2':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   SEARCH PHONENO.   ::::::::::::::::::::: |\n\n" ;
        phread();
        getchar();
        goto pho;
        break;
    case '3':
        break;
    default:
        cout<<"\a";
        PHONEBOOK();
    }   
}

int main()
{
    cout<< "\n    ______________________________________________________________________\n" ;
    cout<< "    |                                          |\n" ;
    cout<< "    | «««««««««««««««««««  HOME MANGEMENT SOFTWARE   »»»»»»»»»»»»»»»»»»» |\n" ;
    cout<< "    |                                          |\n" ;
    cout<< "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
    cout<<"\t\t            By Ishan \n\n";
    getchar();
    label:;
    printf("\033c");
    cout<< "       | :::::::::::::::::::::   HOME MANGEMENT    ::::::::::::::::::::: |\n\n" ;
    char ch;
    cout<<"\n\t :::::: MENU ::::::";
    cout<<"\n\n\t 1: Biodata";
    cout<<"\n\t 2: Children's corner";
    cout<<"\n\t 3: Parent's corner";
    cout<<"\n\t 4: Exit";
    cout<<"\n\n\t Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case '1':
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   BIODATA    ::::::::::::::::::::: |\n\n" ;
        write();
        getchar();
        goto label;
        break;
    case '2':
        chil:;
        printf("\033c");
        char ch1;
        cout<< "       | :::::::::::::::::::::   CHILDREN'S CORNER   ::::::::::::::::::::: |\n\n" ;
        cout<<"\n\t :::::: MENU ::::::";
        cout<<"\n\n\t 1: Quiz";
        cout<<"\n\t 2: Game";
        cout<<"\n\t 3: Report card";
        cout<<"\n\t 4: Calculator";
        cout<<"\n\t 5: Graphic calculator";
        cout<<"\n\t 6: Exit";
        cout<<"\n\n\t Enter your choice: ";
        cin>>ch1;
        switch(ch1)
        {
            case '1':
                QUIZ();
                goto chil;
                break;
            case '2':
                printf("\033c");
                GAME();
                getchar();
                goto chil;
                break;
            case '3':
                printf("\033c");
                REPORTCARD();
                goto chil;
                break;
            case '4':
                printf("\033c");
                CALC();
                goto chil;
                break;
            case '5':
                printf("\033c");
                GRAPHCALC();
                goto chil;
                break;           
            case '6':
                goto label;
            default:
                goto chil;
        }
       
        break;
    case '3':
        part:;
        printf("\033c");
        cout<< "       | :::::::::::::::::::::   PARENT'S CORNER   ::::::::::::::::::::: |\n\n" ;
        cout<<"\n\t :::::: MENU ::::::";
        cout<<"\n\n\t 1: Budget";
        cout<<"\n\t 2: Task scheduler";
        cout<<"\n\t 3: Phonebook";
        cout<<"\n\t 4: Shopping list";
        cout<<"\n\t 5: Calculator";
        cout<<"\n\t 6: Exit";
        cout<<"\n\n\t Enter your choice: ";
        cin>>ch1;
        switch(ch1)
        {
            case '1':
                printf("\033c");
                BUDGET();
                goto part;
                break;
            case '2':
                printf("\033c");
                SCHEDULER();
                goto part;
                break;
            case '3':
                printf("\033c");
                PHONEBOOK();            
                goto part;
                break;
            case '4':
                printf("\033c");
                SHOPLIST();
                goto part;
                break;
            case '5':
                printf("\033c");
                CALC();
                goto part;
                break;           
            case '6':
                goto label;
            default:
                goto part;
        }
       
        break;   
   
    case '4':
        printf("\033c");
        cout << "\n\n\n\n\n\n" ;
            cout << "  \t\t\f\f\f\f\f\f    \f\f\f       \f\f\f    \f\f\f\f\f\f  \f\f\f\f\f\f  \n" ;
            cout << "  \t\t\f\f\f\f\f\f     \f\f\f     \f\f\f    \f\f\f\f\f\f  \f\f\f\f\f\f \n" ;
            cout << "  \t\t\f\f        \f\f\f   \f\f\f       \f\f      \f\f   \n" ;
            cout << "  \t\t\f\f         \f\f\f \f\f\f        \f\f      \f\f   \n" ;
            cout << "  \t\t\f\f\f\f\f\f      \f\f\f\f\f         \f\f      \f\f   \n" ;
            cout << "  \t\t\f\f         \f\f\f \f\f\f        \f\f      \f\f   \n" ;
            cout << "  \t\t\f\f        \f\f\f   \f\f\f       \f\f      \f\f   \n" ;
            cout << "  \t\t\f\f\f\f\f\f   \f\f\f     \f\f\f    \f\f\f\f\f\f    \f\f   \n" ;
            cout << "  \t\t\f\f\f\f\f\f  \f\f\f       \f\f\f   \f\f\f\f\f\f    \f\f   \n" ;
        break;
    default:
        cout<<"\a";
        main();
    }
   

}