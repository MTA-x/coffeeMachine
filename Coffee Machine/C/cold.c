#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#define Max_Coffee()
//#define Max_Coin()


void Printing_Menu(char str[] , float s , float m , float l)
{

    system("clear"); //Common Language Specification

    printf("***********************************************************************\n");
    if(s == 0)
        printf("*  1) Small    X                                                      *\n");
    else
        printf("*  1) Small    %5.1f                                                  *\n",s);

    if(m == 0)
        printf("*  2) Medium   X                                                      *\n");
    else
        printf("*  2) Medium   %5.1f                                                  *\n",m);

    if(l == 0)
        printf("*  3) Large    X                                                      *\n");
    else
        printf("*  3) Large    %5.1f                                                  *\n",l);

    printf("***********************************************************************\n");

}

void addBalance(float* credit , float price , float* calculate , float* add_balance)
{

    *calculate = price - *credit;

    printf("Your Balance Is : %5.1f\n" , *credit);

    printf("You Have To Add : %5.1f " , *calculate);
    scanf("%f" , add_balance);

    *credit += *add_balance;
    printf("Your Balance Is : %5.1f BAM \n" , *credit);

}

int wrong_money_number(float credit1)
{       //wrong money enterence<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        if( credit1 == 0.5  ||  credit1 == 1.0  ||  credit1 == 2.0  ||  credit1 == 5.0 )
        {
            return 0;
        }

        return 1;
}


void prepareAndServeCoffee(char *size , float* calculate)
{
    printf("Here Is Your Change : %5.1f \n", *calculate);
    printf("You Choose : %s size\n" , size);
    sleep(1);
    printf("Your Coffee Is Preparing...\n");
    sleep(2);
    printf("Enjoy Your Coffee\n");
    sleep(4);

}

int isSizeValid(int* size)
{

    printf("Which Size Would You Like To Drink : ");
    scanf("%d" , size);

    return ( (*size == 1 || *size == 2 || *size == 3) ? 0 : 1 ); // 0 is Valid, don't get in if statement
}

void moneyProcess(float credit1 , float price , float calculate , float* calculate2 , float add_balance)
{
    do
    {
        if (credit1 < price)

            addBalance(&credit1, price, &calculate, &add_balance);

        if (credit1 == price)
        {

            *calculate2 = 0;
            continue;
        }
        if (credit1 > price)
        {

            *calculate2 = credit1 - price;
            break;
        }
    } while (credit1 != price);
}

/*void Max_Coffee(int* max_coffee , int* coffee_counter , int* calculate3 , float credit1)
{   
    do
    {   
        //max_coffee = coffee_counter++;
        calculate3 = max_coffee - *coffee_counter;
        

    } while (! (coffee_counter == max_coffee) );
        printf("Sorry We Are Full...");
        printf("Here Is Your Change : %5.1lf" , credit1);  

}*/

int main()
{
    int credit;
    credit = 0;
    
    int coffee_counter;
    int coin_counter;
    int max_coffee;

    //max_coffee = 50;
    //coffee_counter = -1;
    //coin_counter = 0;

    //int max_money [50];

    int size;
    //int calculate3;
    
    float credit1;
    float input;
    float calculate;
    float add_balance;


    float calculate2;
    calculate = 0;

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


    do
    {
        system("clear");
        system("clear");

        printf("**********************************************************************************\n");
        printf("*           1) COLD COFFEE                       6) ICE CHOCOLATE MOCHA          *\n");
        printf("*           2) COLD COFFEE W/MILK                7) ICE FRAPPUCINO               *\n");
        printf("*           3) ICE LATTE MACCHIATO               8) COLD BREW                    *\n");
        printf("*           4) ICE AMERICANO                     9) BACK                 	 *\n");
        printf("*           5) ICE FILTER COFFE                  99)EXIT                         *\n");
        printf("**********************************************************************************\n");
        printf("Which Coffee Would You Like To Drink : ");
        scanf("%d" , &choice);

        switch (choice)
        {

        //-------------------- < COLD COFFE > //--------------------

        case 1:
        {

            Printing_Menu("COLD COFFEE", 2.5, 3.0, 3.5); //(for menu)

            if(isSizeValid(&size))
            {
                printf(" %d IS INVALID CHOICE\n" , size);
                break;
            }

            printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
            scanf("%f" , &credit1);

        
            if(wrong_money_number(credit1))
            {
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
            }
            printf("\n");

            /*if (&Max_Coffee)
            {   
                printf("Now You can make this %d amount of coffee\n" , calculate3);
                sleep(1);
            }*/
            
            if (size == 1)
            {
                moneyProcess(credit1, price1, calculate,  &calculate2, add_balance);


                prepareAndServeCoffee("Small" ,  &calculate2);
                break;

            }

            else if (size == 2)
            {
                moneyProcess(credit1, price2, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Medium", &calculate2);
                break;

            }
            else if (size == 3)
            {
                moneyProcess(credit1, price3, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }

        }
        //-------------------- < COLD COFFE W\MILK > //--------------------

        case 2:
        {

            Printing_Menu("COLD COFFEE W/MILK", 2.5, 3.0, 3.5);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit is %d , You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");


            if (size == 1)
            {
                moneyProcess(credit1, price1, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small", &calculate2);
                break;

            }

            else if (size == 2)
            {
                moneyProcess( credit1 , price2 , calculate, &calculate2 , add_balance);
                prepareAndServeCoffee("Medium" , &calculate2);
                break;

            }

            else if (size == 3)
            {
                moneyProcess( credit1, price3, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }
        //-------------------- < ICE LATTE MACCHIATO > //--------------------

        case 3:
        {

            Printing_Menu("ICE LATTE MACCHIATO", 4.0, 5.0, 6.0);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");


            if (size == 1)
            {
                moneyProcess(credit1 , price4 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Small" , &calculate2);
                break;

            }
            else if (size == 2)
            {
                moneyProcess( credit1 , price6 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }
            else if (size == 3)
            {
                moneyProcess( credit1 , price8 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < ICE AMERICANO > //--------------------

        case 4:
        {

            Printing_Menu("ICE AMERICANO", 2.5, 0.0, 3.5); //(for menu)

            if(isSizeValid(&size))
            {

                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }

                printf("Your Credit is %d You Need To Add Credit '0.5 km - 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1))
                {
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");


            if (size == 1)
            {
                moneyProcess(credit1, price1, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small", &calculate2);
                break;
            }

            else if (size == 2)
            {

                printf("There Is No Medium Size\n");

                printf("Please Choose Another Size Drink\n");
                sleep(2);;

                printf("Here Is Your Change : %5.1f\n" , credit1);
                sleep(2);;
                break;
            }

            else if (size == 3)
            {
                moneyProcess( credit1 , price3 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < ICE FILTER COFFE > //--------------------

        case 5:
        {

            Printing_Menu("ICE FILTER COFFEE" , 2.5, 3.0, 3.5); //(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");



            if (size == 1)
            {
                moneyProcess( credit1 , price1 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {
                moneyProcess( credit1 , price2 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }

            else if (size == 3)
            {
                moneyProcess( credit1 , price3 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < ICE CHOCOLATE MOCHA > //--------------------

        case 6:
        {

            Printing_Menu("ICE CHOCOLATE MOCHA", 4.5, 5.5, 6.5);//(for menu)

            if(isSizeValid(&size))
            {

                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");




            if (size == 1)
            {
                moneyProcess( credit1, price5, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {
                moneyProcess( credit1, price7, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }

            else if (size == 3)
            {
                moneyProcess( credit1, price9, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < ICE FRAPPUCINO > //--------------------

        case 7:
        {

            Printing_Menu("ICE FRAPPUCINO", 3.5, 4.5, 5.5);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");



            if (size == 1)
            {
                moneyProcess(credit1, price3, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {

                moneyProcess( credit1 , price5 , calculate, &calculate2 , add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }

            else if (size == 3)
            {

                moneyProcess( credit1, price7, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < COLD BREW > //--------------------

        case 8:
        {

            Printing_Menu("COLD BREW", 3.0, 3.5, 4.0); //(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                break;
            }
                printf("Your Credit i  %d , You Need To Add Credit '0.5 km- 1km - 2km - 5km : ", credit);
                scanf("%f" , &credit1);

                if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");


            if (size == 1)
            {

                moneyProcess(credit1 , price2 , calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {

                moneyProcess(credit1, price3, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;

            }

            else if (size == 3)
            {

                moneyProcess( credit1, price4, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < RETURNING MAIN MENU > //--------------------

        case 9:
        {

            printf("Returing To Main Menu");
            sleep(1);

            system("gcc coffee.c");
            system("clear");
            system("./a.out");
			choice = 99;
            break;
        }

        //-------------------- < EXIT FROM PROGRAM > //--------------------

        case 99:
        {

            printf("Exiting From The Machine");
            sleep(1);
            
            system("gcc exit.c");
            system("clear");
            system("./a.out");
            
            break;
        }
        //-------------------- < INVALID CHOICE PROGRAM > //--------------------

        default:
        {

            if ( !(choice >=1) || choice != 9 || !(choice != 99) )
            {

                printf("Invalid Choice\n");
                sleep(2);
                break;
            }
        break;
        }

    }

    }while(choice != 99);

    return 0;
}
