#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//functions
int clear;
void Add_account();
void viewlist();
void CheckMyAccount();
void delete();
int atm();
void exit1();
void end();
void searchcountry();
void details();
void interestloan();
void Leave();
void Error();
void addcurrency();
void transaction();

//structure
struct Date
{
    int Day,Month,Year;
};
struct
{

    char Name[30];
    int Account_number;
    int Age;
    char Address[70];
    int Mobile_number;
    struct Date Dob;
    struct Date Deposit;
    struct Date deposit;
    float amount;
} add,verify,del,transac;

struct currency
{
    char S1[100];
    float rate;
};

//main function
int main()
{
    int choice;

    printf("\t\t\t\t     Delta bank\n\n");
    printf("\t\t\t\t Welcome to our bank\n\n");
    printf("\t\t      What would you like to choose from our features\n");
    printf("\n\t 1. Create a new account.");
    printf("\n\t 2. check my account details.");
    printf("\n\t 3. remove account.");
    printf("\n\t 4. see customer list.");
    printf("\n\t 5. ATM feature");
    printf("\n\t 6. Doing transaction");
    printf("\n\t 7. loaninterest");
    printf("\n\t 8. Adding country rates.");
    printf("\n\t 9. Show all country currency rates");
    printf("\n\t 10. Search for specific Country rate\n");



    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Add_account();
        break;
    case 2:
        CheckMyAccount();
        break;
    case 3:
        delete();
        break;
    case 4:
        viewlist();
        break;
    case 5:
        atm();
        break;
    case 6:
        transaction();
        break;
    case 7:
        interestloan();
        break;
    case 8:
        addcurrency();
        break;
    case 9:
        details();
        break;
    case 10:
        searchcountry();
        break;
    }
    return 0;

}

//adding account
void Add_account()
{
    int choice;
    FILE *ptr;
Account_number:
    ptr=fopen("record.txt","a+");

    system("cls");
    printf("\t\t\tCreating new Account:");
    printf("\n\n\n Give Today's Date: ");
    scanf("%d/%d/%d",&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year);
    printf("Enter desired account number:");
    scanf("%d",&verify.Account_number);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",&add.Account_number,add.Name,&add.Dob.Day,&add.Dob.Month,&add.Dob.Year,&add.Age,add.Address,&add.Mobile_number,&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year)!=EOF)

    {
        if(verify.Account_number==add.Account_number)
        {
            printf("Account no. already in use");
            goto Account_number;
        }
    }

    add.Account_number=verify.Account_number;
    printf("\nEnter your nick name: ");
    scanf("%s",add.Name);
    printf("\nEnter your date of birth in this format(d/m/y). ");
    scanf("%d/%d/%d",&add.Dob.Day,&add.Dob.Month,&add.Dob.Year);
    printf("\nEnter the age:");
    scanf("%d",&add.Age);
    printf("\nEnter the address:");
    scanf("%s",add.Address);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.Mobile_number);

    fprintf(ptr,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);
    fclose(ptr);
    printf("\nAccount created. Thank you");
add_invalid:
    printf("\n\n\n\n\t\tEnter 1 to goto main menu and 0 to exit.");
    scanf("%d",&clear);
    system("cls");
    if(clear==1)
    {
        main();
    }
    else if(clear==0)
    {
        end();

    }
    else
    {
        printf("\nInvalid choice");
        goto add_invalid;
    }

}

//see list
void viewlist()
{

    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\nAccount.Number\tName\t\t\tAddress\t\t\tMobile number\n");


    while(fscanf(view,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",&add.Account_number,add.Name,&add.Dob.Day,&add.Dob.Month,&add.Dob.Year,&add.Age,add.Address,&add.Mobile_number,&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year)!=EOF)

    {
        printf("\n%6d\t%10s\t\t\t%10s\t\t%d",add.Account_number,add.Name,add.Address,add.Mobile_number);
        test++;
    }

    fclose(view);
    if(test==0)
    {
        system("cls");
        printf("\nThere is no records yet");
    }
viewlist_invalid:
    printf("\n\n Enter 1 for going to main function or 0 to exit.");
    scanf("%d",&clear);
    system("cls");
    if(clear==1)
        main();
    else if(clear==0)
        end();
    else
    {
        printf("\nInvalid choice");
        goto viewlist_invalid;
    }
}

void transaction()

{
    int choice,test=0;

    FILE *old,*newrec;

    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    system("cls");

    printf("Enter the account no. of the customer:");

    scanf("%d",&transac.Account_number);

    while(fscanf(old,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",&add.Account_number,add.Name,&add.Dob.Day,&add.Dob.Month,&add.Dob.Year,&add.Age,add.Address,&add.Mobile_number,&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year)!=EOF)

    {
        if(add.Account_number==transac.Account_number)
        {
            test=1;
            //if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
            {
                //printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");

                // system("cls");
                //menu();

            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
            {

                printf("Enter the amount you want to deposit:$ ");
                scanf("%f",&transac);
                add.amount+=transac.amount;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);

                printf("\n\nDeposited successfully!");

            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f",&transac.amount);
                add.amount-=transac.amount;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);

                printf("\n\nWithdrawn successfully!");

            }

        }
        else
        {
            fprintf(newrec,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);

        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");
    if(test!=1)
    {
        printf("\n\nRecord not found!!");
transac_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&clear);
        system("cls");
        if (clear==0)
            transaction();
        else if (clear==1)
            main();
        else if (clear==2)
            end();
        else
        {
            printf("\nInvalid!");
            goto transac_invalid;
        }

    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit or 2 to do transaction again");
        scanf("%d",&clear);
        system("cls");
        if (clear==1)
        {
            system("cls");
            main();
        }
        else if (clear==0)
        {
            end();
        }
        else
        {
            system("cls");
            transaction();
        }
    }


}



//see details
void CheckMyAccount()
{
    FILE *ptr;
    int test=0,choice;
    ptr=fopen("record.txt","r");
    printf("Enter your account number: ");
    scanf("%d",&verify.Account_number);

    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",&add.Account_number,add.Name,&add.Dob.Day,&add.Dob.Month,&add.Dob.Year,&add.Age,add.Address,&add.Mobile_number,&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year)!=EOF)

    {
        if(add.Account_number==verify.Account_number)
        {
            system("cls");
            test=1;
            printf("\nA/C:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nPhone number:%d\n\nDate Of Deposit:%d/%d/%d\n\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,
                   add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);
        }
    }
    fclose(ptr);
    if(test!=1)
    {
        system("cls");
        printf("\nThere is no such type of account number.\nEnter a valid account number");
CheckMyAccount_invalid:
        printf("\n\n Enter 1 for going to main function or 0 to exit or 2 to try again.");
        scanf("%d",&clear);
        system("cls");
        if(clear==1)
            main();
        else if(clear==0)
            end();
        else if(clear==2)
            CheckMyAccount();
        else
        {
            system("cls");
            printf("\nInvalid choice");
            goto CheckMyAccount_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to return to main function or 0 to exit");
        scanf("%d",&clear);

        if(clear==1)
        {

            system("cls");
            main();
        }
        else
        {
            system("cls");
            end();
        }
    }
}


//delete account
void delete()
{
    system("cls");
    FILE *old, *newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("\n\n\tEnter your account number: ");
    scanf("%d",&del.Account_number);

    while(fscanf(old,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",&add.Account_number,add.Name,&add.Dob.Day,&add.Dob.Month,&add.Dob.Year,&add.Age,add.Address,&add.Mobile_number,&add.Deposit.Day,&add.Deposit.Month,&add.Deposit.Year)!=EOF)
    {

        if(add.Account_number!=del.Account_number)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %d %d/%d/%d\n",add.Account_number,add.Name,add.Dob.Day,add.Dob.Month,add.Dob.Year,add.Age,add.Address,add.Mobile_number,add.Deposit.Day,add.Deposit.Month,add.Deposit.Year);

        else
        {

            test++;
            printf("\nRecord deleted.sorry if you faced any trouble using our bank.\n");
        }
    }


    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");
    if(test==0)
    {

        printf("\n\n\tInvalid account number\n");
delete_invalid:

        printf("\n\n Enter 1 for going to main function or 0 to exit or 2 to try again.");
        scanf("%d",&clear);

        system("cls");

        if(clear==1)

            main();

        else if(clear==0)

            exit1();

        else if(clear==2)

        {
            system("cls");
            delete();
        }
        else
        {
            system("cls");
            printf("\nInvalid choice");
            goto delete_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to return to main function or 0 to exit");
        scanf("%d",&clear);

        if(clear==1)
        {
            system("cls");
            main();
        }
        else if(clear==0)

            exit1();
    }

}

void end()
{

    printf("\n\n\t\tThank you for choosing our bank.");
}

void exit1()
{

    printf("\n\n\t sorry for the reason that led to deleting your account from our bank.\n\n");
    printf("\n If there is any complain inform our customer service. Number is 1616\n");
}
// atm function
int atm()
{
    system("cls");
    void ATMMenu();
    void CheckBalance(double Amount);
    int Deposit(double Amount);
    int Withdraw(double Amount);
    void error();
    void leave();

    int i;

    int login(void)
    {
        int number = 5555;
        int pin;
        printf("\n\n\t\tEnter the PIN No:");
        scanf("%d", &pin);

        if (pin == number)
        {

            system("cls");
            ATMMenu();
        }
        else
        {
            printf("Invalid PIN Try Again");
            login();
        }
        return 0;
    }

    double Amount = 500.00;

    int choice;

    login();

    while (1)
    {
        printf("Enter your choice: ");

        scanf("%d", &choice);
        system("CLS");

        switch (choice)
        {
        case 1:
            CheckBalance(Amount);
            break;
        case 2:
            Amount = Deposit(Amount);
            break;
        case 3:
            Amount= Withdraw(Amount);
            break;
        case 4:
            Leave();
            return 0;

        default:
            Error();
            break;
        }
        ATMMenu();
    }
    return 0;

}
//atm menu
void ATMMenu()
{


    printf("\t\t  Welcome to our ATM service\n\n");
    printf("\t\t  What would you like to choose from our features\n\n\n");
    printf("\n\t\t 1.  Check Balance\n");
    printf("\n\t\t 2.  Deposit\n");
    printf("\n\t\t 3. Withdraw\n");
    printf("\n\t\t 4.  Exit\n\n");

}
//total amount
void CheckBalance(double Amount)
{
    system("cls");
    printf("\n\n\n\t\t\tYour Available Balance is:$%.2lf\n\n", Amount);


}
//add money
int Deposit(double Amount)
{
    system("cls");
    double Deposit;

    printf("\t\tEnter your amount to Deposit\n");

    scanf("%lf", &Deposit);


    Amount=Amount+ Deposit;

    printf("\n\n\t\t\tYour New Balance is: $%.2lf\n\n",Amount);
    return Amount;


}

int Withdraw(double Amount)
{
    system("cls");
    double withdraw;

    printf("You choose to Withdraw a money\n");
    printf("\n\n\n\n\t\t\tYour Balance is: $%.2lf\n\n", Amount);


    printf("\n\n\nEnter your amount to withdraw:\n");
    scanf("%lf", &withdraw);


    if (withdraw < Amount)
    {

        Amount= Amount-withdraw;
        system("cls");
        printf("\n\n\n\t\tYour New Balance is:   $%.2lf\n\n", Amount);

    }

    else
    {
        system("cls");
        printf("\n\n\n\t\tYou don't have enough money\n\n");
        printf("\n\n\n\t\tYour Balance is: $%.2lf\n", Amount);

    }

    return Amount;


}
void Leave()
{

    printf("\n\n\n\n\n\t\t\t Thank you for using our ATM service\n");
}

void Error()
{

    printf("\t\t\t invalid choice");
}

void searchcountry()
{
    system("CLS");
    FILE *view;
    int test=0,choice;
    view=fopen("rates.txt","r");
    char s2[100];
    struct currency rt;
    printf("\n\tWelcome To Search Option");
    printf("\n\n\tEnter Your Country Name :");
    scanf("%s",&s2);

    while(fscanf(view,"%s %f",&rt.S1,&rt.rate)!=EOF)
    {
        if(strcmp(rt.S1,s2)==0)
        {
            test++;
            printf("\n\tCountry :%s\t\t Rate:%.4f",rt.S1,rt.rate);
        }
    }
    fclose(view);
    if(test==0)
        printf("\n\tRecord not found!!");
    printf("\n\nEnter 1 to go to the main menu and 2 to Search Again:");
    scanf("%d",&choice);

    if (choice==1)
    {
    system("cls");

    system("cls");
        main();
        }
    else if(choice==2)
        searchcountry();
    else
    {
        printf("\nInvalid!\a");

    }
}

void details()
{

    system("CLS");
    FILE *view;
    view=fopen("rates.txt","r");
    int test=0,choice;
    struct currency rt;
    printf("\n\tCountry\t\t\tRate\t\t\t\n");

    while(fscanf(view,"%s %f",&rt.S1,&rt.rate)!=EOF)
    {
        printf("\t%s\t\t Rate:%.4f",rt.S1,rt.rate);
        test++;
    }
    fclose(view);

    if (test==0)
    {
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 2 to exit:");
    scanf("%d",&choice);

    if (choice==1)
    {
        system("cls");
        main();
        }
    else if(choice==2)
         end();
    else
    {
        printf("\nInvalid!\a");

    }
}


void interestloan()
{

    system("cls");
    int amount;

    double rate,years,interest,time;

    printf("Enter your amount: ");
    scanf("%d",&amount);

    printf("Enter your interest rate: ");
    scanf("%lf",&rate);

    printf("Enter your year: ");
    scanf("%lf",&years);

    interest=(amount*rate*years)/100;


    printf("Your interest rate is: %.3lf\n",interest);

    printf("\nEnter 1 to return to main function or 0 to exit");
    scanf("%d",&clear);

    if(clear==1)
    {
        system("cls");
        main();
    }
    else if(clear==0)

        end();
}

void addcurrency()
{
    system("CLS");
    FILE *currency;

    int add,i,choice;

    currency = fopen("rates.txt","a+");

    printf("\n\t\t\t  ADD CURRENCY DATA \n\n");

    printf("Enter How Many Country You Want To Add :");
    scanf("%d",&add);
    struct currency rt;
    for(i=1; i<=add; i++)
    {
        printf("%d.Enter Your Country :",i);
        scanf("%s",&rt.S1);
        printf("%d Enter Your Country Rate:",i);
        scanf("%f",&rt.rate);
        printf("\t%d. Country :%s   rate= %.4f\n\n",i,rt.S1,rt.rate);
        fprintf(currency,"%s\t\t%.4f\n",rt.S1,rt.rate);
    }

    fclose(currency);
    printf("\n\t\t\t<<<<<< Country added successfully!>>>>>>>");

    printf("\nEnter 1 to return to main function or 0 to exit");
    scanf("%d",&clear);

    if(clear==1)
    {
        system("cls");

        main();
    }
    else if(clear==0)
    {
        system("cls");
        end();
    }

}








