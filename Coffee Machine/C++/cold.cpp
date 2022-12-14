#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;



void printMenu(string str, float s, float m, float l){ 						// str selected beverage type


   system("cls");//Common Language Specification
    cout<<"***************************************************************************\n";
    cout<<"*             "<<str<<"                                                   *\n";
    cout<<"*  1) Small   "<< ( s > 0 ? to_string(s).substr(0, 3) : "X" ) <<"         *\n";
    cout<<"*  2) Medium  "<< ( m > 0 ? to_string(m).substr(0, 3) : "X" ) <<"         *\n";
    cout<<"*  3) Big     "<< ( l > 0 ? to_string(l).substr(0, 3) : "X" ) <<"         *\n";
    cout<<"***************************************************************************\n";

}

void addBalance(float& credit, float price, float& calculate,float add_balance){

    calculate = price - credit;

    cout<<"Your Balance Is : " << credit <<endl;

    cout<<"You Have To Add: " << calculate << ": ";
    cin>>add_balance;

    credit += add_balance;
    cout<<"Your Balance Is : "<<credit<<" km"<<endl<<endl;
}

int wrong_money_number(float credit1){//wrong money enterence<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        if( credit1 == 0.5  ||  credit1 == 1.0  ||  credit1 == 2.0  ||  credit1 == 5.0 )
        {
            return 0;
        }

        return 1;
}

void prepareAndServeCoffee(std::string str, float calculate){
  															  //cout<<"Here Is Your Change : " << calculate <<std::endl;
    cout<<"Here Is Your Change : " << calculate <<endl;
    cout<<"You Choose: "<< str <<" size"<<endl;
    sleep(1);
    cout<<"Your Coffe Is Preparing...\n";
    sleep(2);
    cout<<"Enjoy Your Coffe\n";
    sleep(4);
}

int isSizeValid(int& size){

    cout<<"Which Size Would You Like To Drink : ";
    cin>>size;

    return ( (size==1 || size==2 || size==3) ? 0 : 1 );// 0 is Valid, don't get in if statement
}

void moneyProcess(float& credit1,float price,float& calculate, float& calculate2,float& add_balance){
    do{
        if (credit1 < price)

            addBalance(credit1, price, calculate, add_balance);

        if (credit1 == price){

            calculate2=0;
            continue;
        }
        if (credit1 > price){

            calculate2 = credit1 - price;
            break;
        }
    } while (credit1 != price);
}
int main(){

    cout << std::setprecision(2);

    int credit;
    credit = 0;

    int count;
    count = 0;

    int size;

    float inpt;
    float credit1;
    float input;
    float calculate;
    float calculate2=0;
    float add_balance;

    float price1 , price2 , price3 , price4, price5 , price6 , price7 , price8 , price9;

    price1 = 2.5;
    price2 = 3.0;
    price3 = 3.5;
    price4 = 4.0;
    price5 = 4.5;
    price6 = 5.0;
    price7 = 5.5;
    price8 = 6.0;
    price9 = 6.5;

    int choice = 0;

    //-------------------- < MENU < //--------------------

    do{
        system("cls");
        system("cls");

        cout<<"**********************************************************************************\n";
        cout<<"*           1) COLD COFFE                        6) ICE CHOCOLATE MOCHA          *\n";
        cout<<"*           2) COLD COFFE W/MILK                 7) ICE FRAPPOCINO               *\n";
        cout<<"*           3) ICE LATTE MACCHIATO               8) COLD BREW                    *\n";
        cout<<"*           4) ICE AMERICANO                     9) BACK                         *\n";
        cout<<"*           5) ICE FILTER COFFE                  99)EXIT                         *\n";
        cout<<"**********************************************************************************\n";
        cout<<"Which Coffee Would You Like To Drink : ";
        cin>>choice;

        switch (choice){

        //-------------------- < COLD COFFE > //--------------------

        case 1:{

            printMenu("COLD COFFE", 2.5, 3.5, 4.5);// (for menu)

            if(isSizeValid(size)){
                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }

            cout<<"Your Credit is "<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
            cin>>credit1;

            if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }


            if (size == 1){

                moneyProcess( credit1, price1, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;

            }else if (size == 2){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;

            }else if (size == 3){

                moneyProcess( credit1, price5, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }

        }
        //-------------------- < COLD COFFE W\MILK > //--------------------

        case 2:{

            printMenu("COLD COFFE W/MILK", 2.5, 3.0, 3.5);//(for menu)

            if(isSizeValid(size)){
                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

            if (size == 1){

                moneyProcess( credit1, price1, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;

            }
			else if (size == 2){

                moneyProcess( credit1, price2, calculate,  calculate2, add_balance);
                prepareAndServeCoffee("Medium",calculate2);
                break;

            }
			else if (size == 3){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }
        //-------------------- < ICE LATTE MACCHIATO > //--------------------

        case 3:{

            printMenu("ICE LATTE MACCHIATO", 4.0, 5.0, 6.0);//(for menu)

            if(isSizeValid(size)){

                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

            if (size == 1){

                moneyProcess( credit1, price4, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;

            }
            else if (size == 2){

                moneyProcess( credit1, price6, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;
            }
            else if (size == 3){

                moneyProcess( credit1, price8, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }

        //-------------------- < ICE AMERICANO > //--------------------

        case 4:{

            printMenu("ICE AMERICANO", 2.5, 0.0, 3.5);//(for menu)

            if(isSizeValid(size)){

                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

            if (size == 1){

                moneyProcess( credit1, price1, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small",calculate2);
                break;
            }
            else if (size == 2){

                cout<<"There Is No Medium Size\n";

                cout<<"Please Choose Another Size Drink\n";
                sleep(2);

                cout<<"Here Is Your Change : " << credit1;
                sleep(2);
                break;
            }
            else if (size == 3){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }
        //-------------------- < ICE FILTER COFFE > //--------------------

        case 5:{

            printMenu("ICE FILTER COFFE", 2.5, 3.0, 3.5);//(for menu)

            if(isSizeValid(size)){

                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

           printf("\n");

            if (size == 1){

                moneyProcess( credit1, price1, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;
            }
            else if (size == 2){

                moneyProcess( credit1, price2, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;
            }
            else if (size == 3){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }

        //-------------------- < ICE CHOCOLATE MOCHA > //--------------------

        case 6:{

            printMenu("ICE CHOCOLATE MOCHA", 4.5, 5.5, 6.5);//(for menu)

            if(isSizeValid(size)){

                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

            if (size == 1){

                moneyProcess( credit1, price5, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;
            }
            else if (size == 2){

                moneyProcess( credit1, price7, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;
            }
            else if (size == 3){

                moneyProcess( credit1, price9, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }

        //-------------------- < ICE FRAPPUCCINO > //--------------------

        case 7:{

            printMenu("ICE FRAPPUCCINO", 3.5, 4.5, 5.5);//(for menu)

            if(isSizeValid(size)){
                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

             if (size == 1){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;
            }
            else if (size == 2){

                moneyProcess( credit1, price5, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;
            }
            else if (size == 3){

                moneyProcess( credit1, price7, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }

        //-------------------- < COLD BREW > //--------------------

        case 8:{

            printMenu("COLD BREW", 3.0, 3.5, 4.0);//(for menu)

            if(isSizeValid(size)){

                cout<<size<<" IS INVALID CHOICE" << endl;
                sleep(2);
                break;
            }
                cout<<"Your Credit is"<< credit <<", You Need To Add Credit '0.5 km- 1km - 2km - 5km : ";
                cin>>credit1;

                if(wrong_money_number(credit1)){
                cout<<credit1<<" "<<"IS INVALID CHOICE\n";
                sleep(2);
                break;
           }

            if (size == 1){

                moneyProcess( credit1, price2, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Small", calculate2);
                break;
            }
            else if (size == 2){

                moneyProcess( credit1, price3, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Medium",calculate2);
                break;

            }
            else if (size == 3){

                moneyProcess( credit1, price4, calculate,  calculate2, add_balance);

                prepareAndServeCoffee("Large",calculate2);
                break;
            }
        }

        //-------------------- < RETURNING MAIN MENU > //--------------------

        case 9:{

            cout<<"Returing To Main Menu";
            sleep(1);

            system("gcc coffee.cpp -o coffee");
            system("cls");
            system("coffee.exe");
			choice=99;
            break;
        }

        //-------------------- < EXIT FROM PROGRAM > //--------------------

        case 99:{

            cout<<"Exiting From The Machine";
            sleep(1);
            break;
        }
        //-------------------- < INVALID CHOICE PROGRAM > //--------------------

        default:{

            if ( !(choice >=1) || choice != 9 || !(choice != 99) ){

                cout<<"Invalid Choice\n";
                sleep(2);
                break;
            }
            break;
        }

        }
    } while (choice != 99);

    return 0;
}
