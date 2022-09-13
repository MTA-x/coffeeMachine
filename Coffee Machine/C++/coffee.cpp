#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
using namespace std;



void Hot(void);
void Cold(void);
void Exit(void);


int main()
{
        int choice;

    do
    {
        system("cls");

        cout<<"*********************************\n";
        cout<<"*                               *\n";
        cout<<"*         1) HOT                *\n";
        cout<<"*                               *\n";
        cout<<"*         2) COLD               *\n";
        cout<<"*                               *\n";
        cout<<"*         3) EXIT               *\n";
        cout<<"*                               *\n";
        cout<<"*********************************\n";

        cout<<"WOULD YOU LIKE TO DRINK HOT OR COLD  \n\n";
        cout<<"Please Press 1 For Hot Drink Menu    \n\n";
        cout<<"Please Press 2 For Cold Drink Menu   \n\n";
        cin>>choice;

        if ( (choice != 1) && (choice != 2) && (choice != 3) ){
            cout<<choice<<"  Is INVALID CHOICE";
            break;
        }
        else
            switch(choice){
                case 1:
                {
                    Hot();
                    break;
                }
                case 2:
                {
                    Cold();
                    break;
                }
                case 3:
                {
                	  cout<<"Exiting From The Machine";
                      sleep(1);
                    return 0;
                    break;
                }
            default:
            {
                if ( !(choice >=1) || choice != 9 || !(choice != 99) ){
                    cout<<"Invalid Choice\n";
                    sleep(2);
                    break;
                }
                break;
            }

            }
        return 0;

        }while (choice != 99);

        return 0;
    }
void Hot(){
    system("g++ -std=c++11 hot.cpp -o hot");
    system("cls");
    system("hot.exe");
}
void Cold(){
    system("g++ -std=c++11 cold.cpp -o cold");
    system("cls");
    system("cold.exe");
}
void Exit(){

            cout<<"Exiting From The Machine";
            sleep(1);
}
