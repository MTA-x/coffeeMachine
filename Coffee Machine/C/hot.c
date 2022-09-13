#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void Printing_Menu(char str[] , float s , float m , float l)
{

    system("clear"); //Common Language Specification

    printf("***********************************************************************\n");
    if(s == 0)
        printf("*  1) Small    X                                                  *\n");
    else
        printf("*  1) Small    %5.1f                                              *\n",s);

    if(m == 0)
        printf("*  2) Medium   X                                                  *\n");
    else
        printf("*  2) Medium   %5.1f                                              *\n",m);

    if(l == 0)
        printf("*  3) Large    X                                                  *\n");
    else
        printf("*  3) Large    %5.1f                                              *\n",l);

    printf("***********************************************************************\n");

}

void addBalance(float* credit , float price , float* calculate , float* add_balance)
{

    *calculate = price - *credit;

    printf("Your Balance Is : %5.1f\n" , *credit);

    printf("You Have To Add : %5.1f " , *calculate);
    scanf("%f" , add_balance);

    /*if(wrong_money_number(credit1))
    {
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                return 0;
    }*/


    *credit += *add_balance;
    printf("Your Balance Is : %5.1f BAM \n" , *credit);

    //return credit;
}

int wrong_money_number(float credit1){//wrong money enterence<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        if( credit1 == 0.5  ||  credit1 == 1.0  ||  credit1 == 2.0  ||  credit1 == 5.0 ){
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
    do{
        if (credit1 < price)

            addBalance(&credit1, price, &calculate, &add_balance);

        if (credit1 == price){

            *calculate2 = 0;
            continue;
        }
        if (credit1 > price){

            *calculate2 = credit1 - price;
            break;
        }
    } while (credit1 != price);
}

int main()
{
    int credit;
    credit = 0;

    int count;
    count = 0;

    int size;

    float inpt;
    float credit1;
    float input;
    float calculate;
    float add_balance;


    float calculate2;
    calculate = 0;

    float price1 , price2 , price3 , price4, price5 , price6 , price7 , price8;

    price1 = 1.5;
    price2 = 2.0;
    price3 = 2.5;
    price4 = 3.0;
    price5 = 3.5;
    price6 = 4.0;
    price7 = 4.5;
    price8 = 5.0;

    int choice = 0;


    do
    {
        system("clear");
        //system("clear");

        printf("**********************************************************************************\n");
        printf("*           1) EXPRESSO                       5) LATTE MACCHIATO  		 *\n");
        printf("*           2) HOT COFFE W/MILK               6) NESCAFEE                        *\n");
        printf("*           3) AMERICANO                      7) HOT CHOCOLATE                   *\n");
        printf("*           4) CAPPUCCINO                     8) FILTER CAFFEE                	 *\n");
        printf("*           9) BACK                           99) EXIT                        	 *\n");
        printf("*                                                                                *\n");
        printf("**********************************************************************************\n");
        printf("Which Coffee Would You Like To Drink : ");
        scanf("%d" , &choice);

        switch (choice)
        {

        //-------------------- < EXPRESSO > //--------------------

        case 1:
        {

            Printing_Menu("EXPRESSO", 1.5, 0.0, 2.5);// (for menu)

            if(isSizeValid(&size))
            {
                printf(" %d IS INVALID CHOICE\n" , size);
                sleep(2);
                break;

            }

            printf("Your Credit is %d You Need To Add Credit '0.5 km- 1km - 2km - 5km : " , credit);
            scanf("%f" , &credit1);

            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


           if(wrong_money_number(credit1)){
                printf(" %5.1f IS INVALID CHOICE\n" , credit1);
                sleep(2);
                break;
           }
           printf("\n");



            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



            if (size == 1)
            {
                moneyProcess(credit1, price1, calculate,  &calculate2, add_balance);


                prepareAndServeCoffee("Small" ,  &calculate2);
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
                moneyProcess(credit1, price3, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }

        }
        //-------------------- < HOT COFFE W\MILK > //--------------------

        case 2:
        {

            Printing_Menu("HOT COFFEE W/MILK", 2.0, 2.5, 3.0);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE" , size);
                sleep(2);
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
                moneyProcess(credit1, price2, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small", &calculate2);
                break;

            }

            else if (size == 2)
            {
                moneyProcess( credit1 , price3 , calculate, &calculate2 , add_balance);
                prepareAndServeCoffee("Medium" , &calculate2);
                break;

            }

            else if (size == 3)
            {
                moneyProcess( credit1, price4, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }
        //-------------------- < AMERICANO > //--------------------

        case 3:
        {

            Printing_Menu("AMERICANO", 2.0, 0.0, 3.0);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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
                moneyProcess(credit1 , price2 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Small" , &calculate2);
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
                moneyProcess( credit1 , price4 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < CAPPUCCINO > //--------------------

        case 4:
        {

            Printing_Menu("CAPPUCCINO", 3.0, 4.0, 5.0); //(for menu)

            if(isSizeValid(&size))
            {

                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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
                moneyProcess(credit1, price4, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small", &calculate2);
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

        //-------------------- < LATTE MACCHIATO > //--------------------

        case 5:
        {

            Printing_Menu("LATTE MACCHIATO" , 3.0, 4.0, 5.0); //(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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
                moneyProcess( credit1 , price4 , calculate , &calculate2 , add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
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

        //-------------------- < NESCAFEE > //--------------------

        case 6:
        {

            Printing_Menu("NESCAFEE", 2.5, 3.5, 4.5);//(for menu)

            if(isSizeValid(&size))
            {

                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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
                moneyProcess( credit1, price3, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {
                moneyProcess( credit1, price5, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }

            else if (size == 3)
            {
                moneyProcess( credit1, price7, calculate,  &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < HOT CHOCOLATE > //--------------------

        case 7:
        {

            Printing_Menu("HOT CHOCOLATE", 3.5, 4.5, 5.0);//(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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
                moneyProcess(credit1, price5, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Small" ,  &calculate2);
                break;
            }

            else if (size == 2)
            {

                moneyProcess( credit1 , price7 , calculate, &calculate2 , add_balance);

                prepareAndServeCoffee("Medium" , &calculate2);
                break;
            }

            else if (size == 3)
            {

                moneyProcess( credit1, price8, calculate, &calculate2, add_balance);

                prepareAndServeCoffee("Large" , &calculate2);
                break;
            }
        }

        //-------------------- < FILTER CAFFEE > //--------------------

        case 8:
        {

            Printing_Menu("FILTER CAFFEE", 2.0, 2.5, 3.5); //(for menu)

            if(isSizeValid(&size))
            {
                printf("%d IS INVALID CHOICE\n" , size);
                sleep(2);
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

                moneyProcess( credit1, price5, calculate,  &calculate2, add_balance);

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
            
            sleep(1);
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
