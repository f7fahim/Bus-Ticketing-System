
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[50];
    int bus_num;
    int num_of_seats;

}pd;
void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
void login();
int main()
{
    system("cls");
    system("COLOR 0A");
    printf("\t\t=================================================\n");
    printf("\t\t                                                 \n");
    printf("\t\t                                                 \n");
    printf("\t\t         -------------------------------         \n");
    printf("\t\t            BUS TICKET RESERVATIO                \n");
    printf("\t\t                    SYSTEM                       \n");
    printf("\t\t        -------------------------------          \n");
    printf("\t\t                                                 \n");
    printf("\t\t                                                 \n");
    printf("\t\t                                                 \n");
    printf("\t\t                                                 \n");
    printf("\t\t                                                 \n");
    printf("\t\t=================================================\n");

    printf(" \n Press any key to continue:");
    getch();
    system("cls");
    login();
    int menu_choice,choice_return;
    start:
        system("cls");
        printf("=========================================");
        printf("         BUS RESERVATION SYSTEM         ");
        printf("=========================================");
        printf("\n1>>       Reserve A Ticket         ");
        printf("\n-----------------------------------");
        printf("\n2>>    View All Available Bus    ");
        printf("\n-----------------------------------");
        printf("\n3>> Exit");
        printf("\n-->");
        scanf("%d",&menu_choice);

    switch(menu_choice)
    {
    case 1:
        reservation();
        break;
    case 2:
        viewdetails();
        printf("\n\nPress any key to go to Main Menu..");
        getch();
        break;
    case 3:
        return(0);
    default:
        printf("\nInvalid Choice");
    }
    goto start;
    return(0);
}


void viewdetails(void)
{
    system("cls");
    printf("-----------------------------------------------------");
    printf("\nBus.No\t\tName\t\tDestinations  \t\tCharges  \t\tTime\n");
    printf("-----------------------------------------------------");
    printf("\n1001\tRoyal Express      \tDhaka to Jhenidah      \tRs.550    \t\t09:00 AM");
    printf("\n1002\tRoyal Express      \tDhaka to Jhenidah      \tRs.550    \t\t09:00 PM");
    printf("\n1003\tGreen Line         \tDhaka to Jashore       \tRs.550    \t\t10:00 AM");
    printf("\n1004\tGreen Line         \tDhaka to Jashore       \tRs.550    \t\t10:00 PM");
    printf("\n1005\tShohag Paribahan   \tDhaka to Khulna        \tRs.550    \t\t07:00 AM");
    printf("\n1006\tShohag Paribahan   \tDhaka to Khulna        \tRs.550    \t\t07:00 PM");
    printf("\n1007\tShohag Paribahan   \tDhaka to Jashore       \tRs.550    \t\t08:00 AM");
    printf("\n1008\tShohag Paribahan   \tDhaka to Jashore       \tRs.550    \t\t08:00 PM");
    printf("\n1009\tHanif  Enterprise  \tDhaka to Khulna        \tRs.550    \t\t11:00 AM");
    printf("\n1010\tHanif  Enterprise  \tDhaka to Khulna        \tRs.550    \t\t11:00 PM");
    printf("\n1011\tShyamoli Paribahan \tDhaka to Chuadanga     \tRs.550    \t\t09:00 AM");
    printf("\n1012\tShyamoli Paribahan \tDhaka to Chuadanga     \tRs.550    \t\t09:00 PM");

}
void reservation(void)
{
    char confirm;
    int i=0;
    float charges;
    pd passdetails;
    FILE *fp;
    fp=fopen("seats_reserved.txt","a");
    system("cls");

    printf("\nEnter Your Name:> ");
    fflush(stdin);
    gets(passdetails.name);
    printf("\nEnter Number of seats:> ");
    scanf("%d",&passdetails.num_of_seats);
    printf("\n\n>>Press Enter To View Available Bus<< ");
    getch();
    system("cls");
    viewdetails();
    printf("\n\nEnter Bus Number:> ");
    start1:
        scanf("%d",&passdetails.bus_num);

        if(passdetails.bus_num>=1001 && passdetails.bus_num<=1012)
        {
            charges=charge(passdetails.bus_num,passdetails.num_of_seats);
            printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
        }
        else
        {
            printf("\nInvalid Bus Number! Enter again--> ");
            goto start1;
        }
        printf("\nConfirm Ticket (y/n):>");
        start:
            scanf("%c",&confirm);
            if(confirm=='y')
            {
                fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
                printf("=================================");
                printf("\n         Reservation Done     \n");
                printf("=================================");
                printf("\nPress any key to go back to Main menu");
            }
            else
            {
                if(confirm=='n')
                {
                    printf("\nReservation Not Done!\nPress any key to go back to Main menu!");
                }
                else
                {
                    printf("\nInvalid choice entered!Enter again----> ");
                    goto start;
                }
            }
            fclose(fp);
            getch();
}
float charge(int bus_num,int num_of_seats)
{
    if(bus_num==1001)
    {
        return(500*num_of_seats);
    }
    if(bus_num==1002)
    {
        return(500*num_of_seats);
    }
    if(bus_num==1003)
    {
        return(450*num_of_seats);
    }
    if(bus_num==1004)
    {
        return(450*num_of_seats);
    }
    if(bus_num==1005)
    {
        return(400*num_of_seats);
    }
    if(bus_num==1006)
    {
        return(400*num_of_seats);
    }
    if(bus_num==1007)
    {
        return(350*num_of_seats);
    }
    if(bus_num==1008)
    {
        return(350*num_of_seats);
    }
    if(bus_num==1009)
    {
        return(600*num_of_seats);
    }
    if(bus_num==1010)
    {
        return(600*num_of_seats);
    }
    if(bus_num==1011)
    {
        return(500*num_of_seats);
    }
    if(bus_num==1012)
    {
        return(500*num_of_seats);


}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
    system("cls");
    printf("------------------------------------\n");
    printf("\tTICKET\n");
    printf("------------------------------------\n");
    printf("Name: \t\t\t%s",name);
    printf("\nNumber of Seats: \t%d",num_of_seats);
    printf("\nBus Number :\t\t%d",bus_num);
    specificbus(bus_num);
    printf("\nCharges: \t\t%.2f",charges);
}

void specificbus(int bus_num)
{
    if(bus_num==1001)
    {
        printf("\nBus: \t\tRoyal Express   ");
        printf("\nDestination: \t\tDhaka to Jhenidah");
        printf("\nDeparture: \t\t09:00 PM ");
    }
    if(bus_num==1002)
    {
        printf("\nBus: \t\tRoyal Express   ");
        printf("\nDestination: \t\tDhaka to Jhenidah");
        printf("\nDeparture: \t\t09:00 AM ");
    }
    if(bus_num==1003)
    {
        printf("\nBus: \t\tGreen Line   ");
        printf("\nDestination: \t\tDhaka to Jashore");
        printf("\nDeparture: \t\t10:00 PM ");
    }
    if(bus_num==1004)
    {
        printf("\nBus: \t\tGreen Line   ");
        printf("\nDestination: \t\tDhaka to Jashore");
        printf("\nDeparture: \t\t10:00 AM ");
    }
    if(bus_num==1005)
    {
        printf("\nBus: \t\tShohag Paribahan");
        printf("\nDestination: \t\tDhaka to Khulna");
        printf("\nDeparture: \t\t07:00 PM ");
    }
    if(bus_num==1006)
    {
        printf("\nBus: \t\tShohag Paribahan");
        printf("\nDestination: \t\tDhaka to Khulna");
        printf("\nDeparture: \t\t07:00 AM ");
    }
    if(bus_num==1007)
    {
        printf("\nBus: \t\tShohag Paribahan");
        printf("\nDestination: \t\tDhaka to Jashore");
        printf("\nDeparture: \t\t08:00 PM ");
    }
    if(bus_num==1008)
    {
        printf("\nBus: \t\tShohag Paribahan");
        printf("\nDestination: \t\tDhaka to Jashore");
        printf("\nDeparture: \t\t08:00 AM ");
    }
    if(bus_num==1009)
    {
        printf("\nBus: \t\tHanif  Enterprise");
        printf("\nDestination: \t\tDhaka to Khulna");
        printf("\nDeparture: \t\t11:00 PM ");
    }
    if(bus_num==1010)
    {
        printf("\nBus: \t\tHanif  Enterprise");
        printf("\nDestination: \t\tDhaka to Khulna");
        printf("\nDeparture: \t\t11:00 AM ");
    }
    if(bus_num==1011)
    {
        printf("\nBus: \t\tShyamoli Paribahan");
        printf("\nDestination: \t\tDhaka to Chuadanga");
        printf("\nDeparture: \t\t09:00 PM ");
    }
    if(bus_num==1012)
    {
        printf("\nBus: \t\tShyamoli Paribahan");
        printf("\nDestination: \t\tDhaka to Chuadanga");
        printf("\nDeparture: \t\t09:00 AM ");
    }
}
void login()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
    {
        printf("\n =================  LOGIN FORM  =================\n ");
        printf("\n                 ENTER USERNAME: ");
        scanf("%s",&uname);
        printf("\n                 ENTER PASSWORD: ");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        i=0;
        if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
        {
            printf(" \n\n\n  WELCOME TO OUR BUS RESERVATION SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n       SORRY !!!! LOGIN IS UNSUCESSFUL");
            a++;

            getch();
            system("cls");
        }
    }
        while(a<=2);
        if(a>2)
        {
            printf("\nSorry you have entered the wrong username and password for four times !!!");
            getch();
        }
        system("cls");
    }

