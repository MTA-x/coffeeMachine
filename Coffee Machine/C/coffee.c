#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//void load_menu(void);

void Hot(void);
void Cold(void);
void Exit(void);

// HOT VOIDE ILE COLD AYRI DOSYALAR DA YAIZILP KAHVE DOSYASINDA BIRLESTIRELECEK
// HOT VE COLD ICIN ICINDE AYRI AYRI DOUBLE VE FLOAT VE DIGER DEGISKENLER ATILACAK
// EXIT ICIN DE AYRI BIR VOID OLUSTURULACAK

int main()
{
    int choice;

    do
    {
        system("clear");
        system("\tfiglet COFFE MACHINE");

        printf("*********************************\n");
        printf("*                               *\n");
        printf("* 1) HOT                        *\n");
        printf("*                               *\n");
        printf("* 2) COLD                       *\n");
        printf("*                               *\n");
        printf("* 3) EXIT                       *\n");
        printf("*                               *\n");
        printf("*********************************\n");
        
        printf("WOULD YOU LIKE TO DRINK HOT OR COLD : ");
        scanf("%d",&choice);
        
        if ( (choice != 1) && (choice != 2) && (choice != 3) )
        {
            printf("%d Is INVALID CHOICE" , choice);
            break;
        }
            
        else
            switch(choice)
            {
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
                    Exit();
                    break;
                }
                
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
        
        return 0;
    
        }while (choice != 99);
        
        return 0;
    }

void Hot()
{

    system("gcc hot.c");
    system("clear");
    system("./a.out");
 
}

void Cold()
{
    system("gcc cold.c");
    system("clear");
    system("./a.out");
}

void Exit()
{

    system("gcc exit.c");
    system("clear");
    system("./a.out");
    
}  