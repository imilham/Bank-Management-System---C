#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include <process.h>

int regAccount;
int num1 = 0;
void compName();
//void forDelay();
void loginMenu();
void loadingArtWork();
void staffMenu();
void addnewAccount();
void viewAccountAllDetails();
void managerMenu();
void withdrawMoney();
void depositMoney();
void deleteAccount();
void updateAccountDetails();
void loanMenu();
void addNewLoan();
void repayLoanAmount();
void viewLoanCustomers();
void closeLoan();
void delay();
void changePassword();
void accountStatment(int num);
void deletedAccountList();

struct date {
    int day,month,year;
};

struct variable{
    char userName[10];
    char password[10];

    int accNumber;
    char name[15];

    char emailID[35];
    char address[30];
    char idNumber[15];
    char telePhoneNum[13];
    char accountType[10];
    float amount;

    struct date dateOfBirth;





}new,old,newT,oldT,first,last,add,view,deposit,withdraw,delete,update,loan,loanFirst,loanLast,loanDep,close,repay;


void delay(){

    printf("\n\t.");
    for(int a = 0; a<8; a++)
    {
        printf(".");
        forDelay(100000000);
    }
    printf("\n");
}

void forDelay(int x){
    int a,b;

    for(a = 1; a<x; a++)
    {
        b = a;
    }

}

void loadingArtWork(){

    printf("\n\tLoading");
    for(int a = 0; a<10; a++)
    {
        printf(".");
        forDelay(100000000);
    }

}

void compName(){

    printf("\n\n\t\t ABC Banking company\n\n");

}

void loginMenu(){

    int choice = 0;

    system("COLOR 0A");
    compName();

    printf("\n\t[1] = Manager - Admin login \n\t[2] = Teller - Staff login\n\t[3] = Exit\n");
    printf("\n\tEnter your option : ");
    scanf("%d",&choice);

    if (choice == 1){

        FILE  *ptr;
        ptr = fopen("managerLogins.dat","r");
        fscanf(ptr,"%s %s",old.userName,old.password);

        username:
        printf("\n\tEnter your user name : ");
        scanf("%s",new.userName);

        password:
        printf("\tEnter your password : ");
        scanf("%s",new.password);

                if(strcmp(new.userName,old.userName)==0)
                {
                    if(strcmp(new.password,old.password)==0)
                    {
                        //loadingArtWork();
                        printf("\n\tWelcome\n");
                        loadingArtWork();
                        managerMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid password, try again");
                        delay();
                        goto password;
                    }
                }
                else
                {
                        printf("\n\tInvalid username, try again");
                        delay();
                        goto username;
                }

        fclose(ptr);

    }

    else if (choice == 2){

        FILE  *ptr;
        ptr = fopen("tellerLogins.dat","r");
        fscanf(ptr,"%s %s",old.userName,old.password);

        usernameSTF:
        printf("\n\tEnter your user name : ");
        scanf("%s",new.userName);

        passwordSTF:
        printf("\tEnter your password : ");
        scanf("%s",new.password);

                if(strcmp(new.userName,old.userName)==0)
                {
                    if(strcmp(new.password,old.password)==0)
                    {
                        //loadingArtWork();
                        printf("\n\tWelcome\n");
                        loadingArtWork();
                        staffMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid password, try again");
                        delay();
                        goto passwordSTF;
                    }
                }
                else
                {
                        printf("\n\tInvalid username, try again");
                        delay();
                        goto usernameSTF;
                }

        fclose(ptr);




    }
    else if (choice == 3){

        printf("\n\n\tThank you for using our system!!!\n\n\n\n");
        //delay();
        exit(1);
    }
    else{

       printf("\n\tInvalid Input\n");
       delay();
       system("cls");
       loginMenu();

    }
}

void staffMenu()
{


    system("cls");
    compName();
    system("COLOR 0B");

    printf("\n\tYou are logged in as a teller - staff\n\n");

    int choice = 0;

    printf("\n\t[1] = Add new account \n\t[2] = View account\n\t[3] = Transaction\n\t[4] = Account statement\n\t[5] = Change user password\n\t[6] = Exit & Logout\n");
    printf("\n\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice) {

        case 1 :
                    addnewAccount();
            break;
        case 2:
                    viewAccountAllDetails();
            break;
        case 3:
                    dipwithMenu:

                    system("cls");
                    compName();
                    int choicewithDip = 0;

                    printf("\t[1] = Deposit\n\t[2] = Withdraw\n\t[3] = Go back\n\n");
                    printf("\tEnter your choice : ");
                    scanf("%d",&choicewithDip);


                    if(choicewithDip == 1){
                                                    num1 = 5;
                                                    depositMoney();
                    }
                    else if(choicewithDip == 2){
                                                     num1 = 10;
                                                     withdrawMoney();
                    }
                    else if(choicewithDip == 3)
                    {
                        staffMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid Input\n");
                        loadingArtWork();
                        system("cls");
                        goto dipwithMenu;
                    }
            break;
        case 4:
                        accountStatment(5);
            break;
        case 5:
                    changePassword(5);
            break;
        case 6 :
            printf("\nThank you for banking with us!\n\n");
            system("cls");
            loginMenu();
            break;

        default :
            printf("\nInvalid input, Please try again \n");
            system("cls");
            staffMenu();

        break;

    }

}

void managerMenu(){

    //system("cls");
    //compName();

    system("cls");
    compName();
    system("COLOR 0B");

    printf("\n\tYou are logged in as a manager\n\n");

    int choice = 0;

    printf("\n\t[1]  =  Add new account \n\t[2]  =  Delete / Erase account \n\t[3]  =  View account \n\t[4]  =  Transactions \n\t[5]  =  Account statement \n\t[6]  =  Update / Edit account details\n\t[7]  =  Loans\n\t[8]  =  Change login password \n\t[9]  =  Deleted account list \n\t[10] =  Exit & Logout\n");
    printf("\n\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice) {

        case 1 :
                    num1 = 5;
                    addnewAccount();
            break;
        case 2:
                    deleteAccount();
            break;
        case 3:
                    num1 = 10;
                     viewAccountAllDetails();
            break;
        case 4:
                    dipwithMenu:

                    system("cls");
                    compName();
                    int choicewithDip = 0;

                    printf("\t[1] = Deposit\n\t[2] = Withdraw\n\t[3] = Go back\n\n");
                    printf("\tEnter your choice : ");
                    scanf("%d",&choicewithDip);


                    if(choicewithDip == 1){
                                                    depositMoney();
                    }
                    else if(choicewithDip == 2){
                                                    withdrawMoney();
                    }
                    else if(choicewithDip == 3)
                    {
                        managerMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid Input\n");
                        delay();
                        system("cls");
                        goto dipwithMenu;
                    }
            break;
        case 5:
                        accountStatment(10);
            break;

        case 6:
                    updateAccountDetails();

            break;
        case 7:
                    loanMenu();

            break;
        case 8:
                    changePassword(10);

            break;
        case 9:
                    deletedAccountList();
        break;

        case 10 :
            printf("\nThank you for banking with us!\n\n");
            system("cls");
            loginMenu();
            break;

        default :
            printf("\n\tInvalid input, Please try again \n");
            delay();
            system("cls");
            managerMenu();
        break;

    }

}

void addnewAccount() {
    int choice = 0;
    char status[25] = {"Account_Opening"};
    system("cls");

    system("COLOR 0B");
    compName();
    FILE *accPTR;

    FILE *ptr;
/*
    ptr = fopen("record.txt","r");
    FILE *accPTR;

    while(fscanf(ptr,"%d %s %s %s %d/%d/%d %s %s %s %f %s\n",&view.accNumber, view.idNumber, first.name, last.name, &view.dateOfBirth.day, &view.dateOfBirth.month, &view.dateOfBirth.year, view.address, view.emailID, view.telePhoneNum, &view.amount,view.accountType)!=EOF)
    {

    }
    fclose(ptr);
*/
    accPTR = fopen("oldAccNums.txt","r"); //Account num storing file
    fscanf(accPTR,"%d",&view.accNumber);
    fclose(accPTR);

    if(view.accNumber == 0)
    {
        view.accNumber = 122449;
    }

    view.accNumber++;
    //printf("number is %d",view.accNumber);


    //printf("\n\tEnter the account number                  : ");
    //scanf("%d",&add.accNumber);

    printf("\tEnter your (NIC or Passport) number       : ");
    scanf("%s",add.idNumber);

    printf("\tEnter the first name                      : ");
    scanf("%s",first.name);

    printf("\tEnter the last name                       : ");
    scanf("%s",last.name);

    printf("\tEnter the DOB in (DD/MM/YYYY)             : ");
    scanf("%d/ %d/ %d",&add.dateOfBirth.day, &add.dateOfBirth.month, &add.dateOfBirth.year);

    printf("\tEnter your address (Town)                 : ");
    scanf("%s",add.address);

    printf("\tEnter your email id                       : ");
    scanf("%s",add.emailID);

    printf("\tEnter the telephone number                : ");
    scanf("%s",add.telePhoneNum);

    printf("\n\tNew fixed account service under hold by management\n\n\t# Savings   # Current\n\n ");
    printf("\tEnter the account type                    : ");
    scanf("%s",add.accountType);

    printf("\tEnter the initial deposit amount in LKR   : ");
    scanf("%f",&add.amount);

    printf("\n\n\tYour account number is               :  %d ",view.accNumber);
    printf("\n\tAccount created successfully\n");


    loadingArtWork();

    ptr = fopen("record.txt","a+");
    fprintf(ptr,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", view.accNumber, add.idNumber, first.name, last.name, add.dateOfBirth.day, add.dateOfBirth.month, add.dateOfBirth.year, add.address, add.emailID, add.telePhoneNum,add.amount, add.accountType);
    fclose(ptr);

    old.amount = 0000;

    FILE *ptrState;
    ptrState = fopen("statement.csv","a+");
    fprintf(ptrState,"%d,%.2f,%.2f,%.2f,%s\n",view.accNumber,old.amount,add.amount,add.amount,status);
    fclose(ptrState);

    accPTR = fopen("oldAccNums.txt","w");
    fprintf(accPTR,"%d",view.accNumber);
    fclose(accPTR);




    system("cls");
    compName();


    there:
    printf("\n\t[1] = Add new account \n\t[2] = Main menu\n\n\tEnter your option : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        addnewAccount();
    }
    else if(choice == 2)
    {
        system("cls");
        if (num1 == 5)
        {
            num1 = 0;
            managerMenu();
        }
        staffMenu();
    }
    else
    {
        system("cls");
        compName();
        printf("\n\n\tInvalid input please try again\n");

        goto there;
    }

}

void viewAccountAllDetails()
{
    int count = 0,choice = 0;
    float amount = 0;

    system("COLOR 0B");
    system("cls");
    compName();
    printf("\n  Acc Num\t  ID num\t  Name\t\t  DOB\t\t   Address\t    Email\t   phone num\t Amount\t    Acc Type\n\n");

    FILE *ptr;
    ptr = fopen("record.txt","r");

    while(fscanf(ptr,"%d %s %s %s %d/%d/%d %s %s %s %f %s\n",&view.accNumber, view.idNumber, first.name, last.name, &view.dateOfBirth.day, &view.dateOfBirth.month, &view.dateOfBirth.year, view.address, view.emailID, view.telePhoneNum, &amount,view.accountType)!=EOF)
    {
       printf("  %d\t%s\t%s %s\t %d/%d/%d\t   %s\t%s  %s %.2f       %s\n", view.accNumber, view.idNumber, first.name, last.name, view.dateOfBirth.day, view.dateOfBirth.month, view.dateOfBirth.year, view.address, view.emailID, view.telePhoneNum, amount,view.accountType);

    count = 1;
    }
    fclose(ptr);

        if(count == 0)
        {
            system("cls");
            compName();
            printf("\tNo records in your system\n");
        }

    there:
    printf("\n\t[1] = Main menu\n\n\tSelect your choice : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        system("cls");
        if (num1 == 10)
        {
            num1 = 0;
            managerMenu();
        }

        staffMenu();
    }
    else
    {
        system("cls");
        compName();
        printf("\n\n\tInvalid input please try again\n");

        goto there;
    }

}

void withdrawMoney(){

    system("cls");
    compName();
    int withCount = 0;
    char *withdraws = {"withdrawal"};

    FILE  *ptr;
    FILE *newRec;

    FILE *ptrState;
    ptrState = fopen("statement.csv","a+");
    fclose(ptrState);




    ptr = fopen("record.txt","r");
    newRec = fopen("tempFile.txt","a+");

    printf("\n\tEnter the account number to withdraw money : ");
    scanf("%d",&withdraw.accNumber);

    while(fscanf(ptr," %d %s %s %s %d/%d/%d %s %s %s  %f %s \n",&new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType)!=EOF)
    {
            if(withdraw.accNumber == new.accNumber)
            {
                old.amount = new.amount;

                printf("\n\n\tAccount is available\n");
                withCount = 1;

                withradagain:
                printf("\n\tYou can withdraw upto : %.2f\n\n",new.amount);

                printf("\n\tEnter the amount to withdraw : ");
                scanf("%f",&withdraw.amount);

                    if(new.amount >= withdraw.amount)
                    {
                        new.amount = new.amount - withdraw.amount;

                        fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);

                        printf("\n\tTransaction succesfull");

                    ptrState = fopen("statement.csv","a+");
                    fprintf(ptrState,"%d,%.2f,%.2f,%.2f,%s\n",new.accNumber,old.amount,deposit.amount,new.amount,withdraws);
                    fclose(ptrState);

                    old.amount = new.amount;

                    }
                    else{
                        printf("\n\tInsufficient account balance");
                       // printf("\n\n\tYou can withdraw upto : %.2f\n\n",new.amount);
                       // printf();
                       goto withradagain;
                    }


            }
            else
            {
                fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);

            }
    }
    fclose(ptr);
    fclose(newRec);

    remove("record.txt");
    rename("tempFile.txt","record.txt");

            if(withCount == 0)
            {
                printf("\n\n\tRecord not found\n\n\tRedirecting to the main menu\n\n");
                delay();
            }
            else if(withCount == 1)
            {
                printf("\n\tYour new account balance is : %.2f\n",old.amount);
                delay();
            }

    if (num1 == 10)
        {
            num1 = 0;
            staffMenu();
        }

    managerMenu();

}

void depositMoney(){

    system("cls");
    compName();
    int depCount = 0;
    char *dep = {"Deposit"};

    FILE  *ptr;
    FILE *newRec;
    FILE *ptrState;

    ptrState = fopen("statement.csv","a+");
    fclose(ptrState);






    ptr = fopen("record.txt","r");
    newRec = fopen("tempFile.txt","a+");

    printf("\n\tEnter the account number to withdraw money : ");
    scanf("%d",&deposit.accNumber);

    while(fscanf(ptr," %d %s %s %s %d/%d/%d %s %s %s  %f %s \n",&new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType)!=EOF)
    {
        if(deposit.accNumber == new.accNumber)
                {

                    old.amount = new.amount;

                    printf("\n\n\tAccount is available\n\n");
                    depCount = 1;

                    printf("\n\tEnter the amount to deposit : ");
                    scanf("%f",&deposit.amount);

                    new.amount = new.amount + deposit.amount;

                    fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);


                    printf("\n\tTransaction succesfull");


                    ptrState = fopen("statement.csv","a+");
                    fprintf(ptrState,"%d,%.2f,%.2f,%.2f,%s\n",new.accNumber,old.amount,deposit.amount,new.amount,dep);
                    fclose(ptrState);
                    old.amount = new.amount;

                }
                else
                {
                    fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);

                }


    }
            if(depCount == 0)
            {
                printf("\n\n\tRecord not found\n\n\tRedirecting to the main menu\n\n");
                delay();
            }
            else if(depCount == 1)
            {
                printf("\n\tYour new account balance is : %.2f\n",old.amount);
                delay();
            }

    fclose(ptr);
    fclose(newRec);

    remove("record.txt");
    rename("tempFile.txt","record.txt");

    if (num1 == 5)
        {
            num1 = 0;
            staffMenu();
        }

    managerMenu();




}

void deleteAccount()
{

    system("cls");
    compName();
    system("COLOR 0B");
    int delCount = 0;
    char status[25] = {"Account_Deleted"};

    FILE  *ptr;
    FILE *newRec;
    FILE *ptrDelete;

    ptr = fopen("record.txt","r");
    newRec = fopen("tempFile.txt","a+");

    printf("\n\tEnter the account number to delete : ");
    scanf("%d",&deposit.accNumber);

    while(fscanf(ptr,"%d %s %s %s %d/%d/%d %s %s %s  %f %s \n",&new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType)!=EOF)
    {
        if(deposit.accNumber == new.accNumber)
        {
            //printf("\n\n\tAccount is available\n\n");
            printf("\n\tAccount deleted successfully\n");

            delCount = 1;
            old.amount = 0;
            ptrDelete = fopen("statement.csv","a+");
            fprintf(ptrDelete,"%d,%.2f,%.2f,%.2f,%s\n",new.accNumber,new.amount,new.amount,old.amount,status);
            fclose(ptrDelete);

            ptrDelete = fopen("deletedAccountList.csv","a+");
            fprintf(ptrDelete,"%d %s %s %s %d/%d/%d %s %s %s  %.2f %s \n",new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, new.amount,new.accountType);

            fclose(ptrDelete);
        }
        else
        {
            fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);

        }
    }

    fclose(ptr);
    fclose(newRec);

    remove("record.txt");
    rename("tempFile.txt","record.txt");

                    if(delCount == 0)
                    {
                        printf("\n\tRecord not found\n\n\tYou will be Back to main menu\n");
                    }
    delay();
    managerMenu();
}

void updateAccountDetails(){

    system("cls");
    system("COLOR 0B");
    compName();

    int upCount = 0;
    int upChoice = 0;
    int upCount1 = 0;

    FILE  *ptr;
    FILE *newRec;
    ptr = fopen("record.txt","r");
    newRec = fopen("tempFile.txt","a+");

    printf("\n\tYour in the update menu!\n\n");
    printf("\tEnter the account number to update details : ");
    scanf("%d",&update.accNumber);

    while(fscanf(ptr," %d %s %s %s %d/%d/%d %s %s %s  %f %s \n",&new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType)!=EOF)
    {

            if(update.accNumber == new.accNumber)
            {
                upCount = 1;
                upCount1 = 1;

                update:

                printf("\tAccount is available\n\n");
                printf("\t[1] = To update the email address\n\t[2] = To update the phone number\n\t[3] = Go back\n\n");
                printf("\tEnter your selectiion : ");
                scanf("%d",&upChoice);

                if(upChoice == 1){

                    printf("\n\tEnter the new email id to update : ");
                    scanf("%s",update.emailID);

                    fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, update.emailID, new.telePhoneNum,new.amount, new.accountType);
                    printf("\n\tEmail ID updated succesfully");



                }
                else if (upChoice == 2){

                    printf("\n\tEnter the telephone number to update : ");
                    scanf("%s",update.telePhoneNum);

                    fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, update.telePhoneNum,new.amount, new.accountType);
                    printf("\n\tTelephne number updated succesfully");


                }
                else if(upChoice == 3)
                {
                    managerMenu();
                }
                else {
                    printf("\tInvalid input try again!");
                    system("cls");

                    compName();
                    printf("\n\tYour in the update menu!\n\n");

                    goto update;

                }




            }
            else
            {
                upCount1 = 1;

                fprintf(newRec,"%d %s %s %s %d/%d/%d %s %s %s %.2f %s\n", new.accNumber, new.idNumber, first.name, last.name, new.dateOfBirth.day, new.dateOfBirth.month, new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum,new.amount, new.accountType);

            }
    }
    if(upCount == 0){
        printf("\n\tAccount not found\n\n\tYou will redericet to main menu");

    }
    if(upCount1 == 0){
      ///  printf("\n\tNo records  found\n\n\tYou will redericet to main menu");

    }
    delay();



    fclose(ptr);
    fclose(newRec);

    remove("record.txt");
    rename("tempFile.txt","record.txt");



    managerMenu();



}

void loanMenu(){

    int loanChoice = 0;
    system("COLOR 0B");

    loanMenu:
    system("cls");
    compName();

    printf("\n\tYour are in the loans menu\n\n");
    printf("\t[1] = New loan\n\t[2] = Repay loan amount\n\t[3] = View all loan customers\n\t[4] = Pay whole amount & close the loan\n\t[5] = Exit to the Manager menu\n\n ");

    printf("\tEnter your option : ");
    scanf("%d",&loanChoice);

    if(loanChoice == 1){

        addNewLoan();
    }
    else if(loanChoice == 2){
        repayLoanAmount();
    }
    else if(loanChoice == 3){
        viewLoanCustomers();
    }
    else if(loanChoice == 4){
        closeLoan();
    }
    else if (loanChoice == 5){

            managerMenu();

    }
    else
    {
        printf("\tInvalid input try again");
        system("cls");
        goto loanMenu;
    }


}

void addNewLoan(){

    system("cls");
    compName();
    system("COLOR 0B");

    printf("\tYou are add new loan menu\n\n");

    printf("\tEnter loan account number                 : ");
    scanf("%d",&loan.accNumber);

    printf("\tEnter your (NIC or Passport) number       : ");
    scanf("%s",loan.idNumber);

    printf("\tEnter the first name                      : ");
    scanf("%s",loanFirst.name);

    printf("\tEnter the last name                       : ");
    scanf("%s",loanLast.name);

    printf("\tEnter the DOB in (DD/MM/YYYY)             : ");
    scanf("%d/ %d/ %d",&loan.dateOfBirth.day, &loan.dateOfBirth.month, &loan.dateOfBirth.year);

    printf("\tEnter your address (Town)                 : ");
    scanf("%s",loan.address);

    printf("\tEnter your email id                       : ");
    scanf("%s",loan.emailID);

    printf("\tEnter the telephone number                : ");
    scanf("%s",loan.telePhoneNum);

    printf("\tEnter the loan amount                     : ");
    scanf("%f",&loan.amount);

    FILE *ptrLoan;

    ptrLoan = fopen("recordLoans.txt","a+");
    fprintf(ptrLoan,"%d %s %s %s %d/%d/%d %s %s %s %.2f\n", loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, loan.dateOfBirth.day, loan.dateOfBirth.month, loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum,loan.amount);
    fclose(ptrLoan);

    printf("\tLoan account created succesfully!\n");
    loanMenu();


}

void repayLoanAmount(){

    system("cls");
    compName();
    system("COLOR 0B");

    printf("\n\tYou are in the loan repayment menu\n\n");

    printf("\tEnter the loan account number to deposit money : ");
    scanf("%d",&loanDep.accNumber);

    FILE *ptrLoan;
    FILE *ptrTempLoan;

    ptrLoan = fopen("recordLoans.txt","r");
    ptrTempLoan = fopen("tempLoan.txt","a+");


    while(fscanf(ptrLoan,"%d %s %s %s %d/%d/%d %s %s %s %f\n", &loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, &loan.dateOfBirth.day, &loan.dateOfBirth.month, &loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum,&loan.amount)!=EOF)
    {
        if(loanDep.accNumber == loan.accNumber){
            printf("\n\tLoan account is available\n");

            printf("\n\tEnter the amount to pay : ");
            scanf("%f",&repay.amount);

            loan.amount = loan.amount - repay.amount;
            fprintf(ptrTempLoan,"%d %s %s %s %d/%d/%d %s %s %s %.2f\n", loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, loan.dateOfBirth.day, loan.dateOfBirth.month, loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum,loan.amount);

        }
        else
        {
            fprintf(ptrTempLoan,"%d %s %s %s %d/%d/%d %s %s %s %.2f\n", loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, loan.dateOfBirth.day, loan.dateOfBirth.month, loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum,loan.amount);

        }

    }
    fclose(ptrLoan);
    fclose(ptrTempLoan);

    remove("recordLoans.txt");
    rename("tempLoan.txt","recordLoans.txt");

    loanMenu();






}

void viewLoanCustomers(){

    system("cls");
    system("COLOR 0B");

    compName();

    printf("\nYou are in loan account viewing menu\n");

    FILE *ptrLoan;

    ptrLoan = fopen("recordLoans.txt","r");

    printf("\nLoan acc num loan id num    loan name   loan date of birth  loan address    loan email id   loan telephone number   loan amount\n\n");

    while(fscanf(ptrLoan,"%d %s %s %s %d/%d/%d %s %s %s %f\n", &loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, &loan.dateOfBirth.day, &loan.dateOfBirth.month, &loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum, &loan.amount)!=EOF)
    {

        printf("%d %s %s %s %d/%d/%d %s %s %s %.2f\n", loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, loan.dateOfBirth.day, loan.dateOfBirth.month, loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum, loan.amount);

        //printf("\n\tLoan account is available");

    }
    fclose(ptrLoan);

    int choice;

    there:
    printf("\n\t[1] = Main menu\n\n\tSelect your choice : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        system("cls");
        if (num1 == 10)
        {
            num1 = 0;
            managerMenu();
        }

        loanMenu();
    }
    else
    {
        system("cls");
        printf("\n\n\tInvalid input please try again\n");

        goto there;
    }

}

void closeLoan(){

    system("cls");
    compName();
    system("COLOR 0B");

     int choiceLoan = 0;
     float closeAmount = 0;
     float payAmount = 0;

        printf("\n\tYou are in the loan closing menu\n\n");

        printf("\tEnter the account number to close the loan : ");
        scanf("%d",&close.accNumber);

        FILE *ptrLoan;

        ptrLoan = fopen("recordLoans.txt","r");

        while(fscanf(ptrLoan,"%d %s %s %s %d/%d/%d %s %s %s %f\n", &loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, &loan.dateOfBirth.day, &loan.dateOfBirth.month, &loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum, &loan.amount)!=EOF)
        {
            if(close.accNumber == loan.accNumber)
                {
                    printf("\n\tAccount is available");
                    closeAmount = loan.amount;
                }
        }
        fclose(ptrLoan);

        printf("\n\tPay remaining : %.2f",closeAmount);

        repay:
        printf("\n\n\tEnter the amount to pay : ");
        scanf("%f",&payAmount);

        if(closeAmount <= payAmount)
        {
            printf("\n\tYour loan is closed succesfully");

        }
        else
        {
            closeAmount = closeAmount - payAmount;
            printf("\n\tYou have to pay all remaining : %.2f ",closeAmount);
            goto repay;
        }


            FILE *ptrTempLoan;

            ptrLoan = fopen("recordLoans.txt","r");
            ptrTempLoan = fopen("tempLoan.txt","a+");

            while(fscanf(ptrLoan,"%d %s %s %s %d/%d/%d %s %s %s %f\n", &loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, &loan.dateOfBirth.day, &loan.dateOfBirth.month, &loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum, &loan.amount)!=EOF)
            {
                if(close.accNumber == loan.accNumber)
                    {
                        printf("\n\tYour are redirecting to loan menu");

                    }
                else
                {
                        fprintf(ptrTempLoan,"%d %s %s %s %d/%d/%d %s %s %s %.2f\n", loan.accNumber, loan.idNumber, loanFirst.name, loanLast.name, loan.dateOfBirth.day, loan.dateOfBirth.month, loan.dateOfBirth.year, loan.address, loan.emailID, loan.telePhoneNum,loan.amount);

                }
            }
            fclose(ptrLoan);
            fclose(ptrTempLoan);



            remove("recordLoans.txt");
            rename("tempLoan.txt","recordLoans.txt");
            delay();

            loanMenu();







}

void changePassword(int num)
{
    system("cls");
    system("COLOR 0A");
    compName();
    int choiceCP = 0;

    if(num == 5)
    {

        //printf("You came from staff menu");
        printf("\n\tYou are in STAFF password changing menu\n\n");

        FILE *ptr;
        ptr = fopen("tellerLogins.dat","r");
        fscanf(ptr,"%s %s",update.userName,update.password);
        fclose(ptr);

        //printf("old password is : %s old user name is %s",update.userName,update.password);

        rechange:
        printf("\n\tEnter the old password to go ahead : ");
        scanf("%s",new.password);

                if(strcmp(new.password,update.password)==0)
                {
                   reenter:
                    printf("\n\t[1] = To change username \n\t[2] = To change password\n\t[3] = Go back to main menu \n\n\tEnter your choice : ");
                    scanf("%d",&choiceCP);

                    if(choiceCP == 1)
                    {
                        printf("\n\tEnter the new user name : ");
                        scanf("%s",update.userName);

                    }
                    else if(choiceCP == 2)
                    {
                        printf("\n\tEnter the new password : ");
                        scanf("%s",update.password);
                    }
                    else if(choiceCP == 3)
                    {
                        staffMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid input try again");
                        delay();
                        system("cls");
                        compName();
                        goto reenter;
                    }


                    printf("\n\tChanges updated\n");
                    ptr = fopen("tellerLogins.dat","w");
                    fprintf(ptr,"%s %s",update.userName,update.password);
                    fclose(ptr);

                        reenterchoice:
                        printf("\n\t[1] = To do more change \n\t[2] = Main menu \n\n\tEnter your choice : ");
                        scanf("%d",&choiceCP);
                        if(choiceCP == 1)
                        {
                            system("cls");
                            compName();
                            printf("\n\tYou are in STAFF password changing menu\n\n");
                            goto rechange;
                        }
                        if(choiceCP == 2)
                        {
                            staffMenu();
                        }
                        else
                        {
                            printf("\n\tInvalid input try again");
                            delay();
                            system("cls");
                            compName();
                            printf("\n\tYou are in STAFF password changing menu\n\n");

                            goto reenterchoice;

                        }

                }
                else
                {
                    printf("\n\tIncorrect password.. Redirecting to main menu");
                    delay();
                    staffMenu();
                }

    }



    else if(num == 10)
    {
        printf("\n\tYou are in MANAGER password changing menu\n\n");

        FILE *ptr;
        ptr = fopen("managerLogins.dat","r");
        fscanf(ptr,"%s %s",update.userName,update.password);
        fclose(ptr);

        //printf("old password is : %s old user name is %s",update.userName,update.password);

        rechangeM:
        printf("\n\tEnter the old password to go ahead : ");
        scanf("%s",new.password);

                if(strcmp(new.password,update.password)==0)
                {
                   reenterM:
                    printf("\n\t[1] = To change username \n\t[2] = To change password\n\t[3] = Go back to main menu \n\n\tEnter your choice : ");
                    scanf("%d",&choiceCP);

                    if(choiceCP == 1)
                    {
                        printf("\n\tEnter the new user name : ");
                        scanf("%s",update.userName);

                    }
                    else if(choiceCP == 2)
                    {
                        printf("\n\tEnter the new password : ");
                        scanf("%s",update.password);
                    }
                    else if(choiceCP == 3)
                    {
                        managerMenu();
                    }
                    else
                    {
                        printf("\n\tInvalid input try again");
                        delay();
                        system("cls");
                        compName();
                        printf("\n\tYou are in MANAGER password changing menu\n\n");

                        goto reenterM;
                    }


                    printf("\n\tChanges updated\n");
                    ptr = fopen("managerLogins.dat","w");
                    fprintf(ptr,"%s %s",update.userName,update.password);
                    fclose(ptr);

                        reenterchoiceM:
                        printf("\n\t[1] = To do more change \n\t[2] = Main menu \n\n\tEnter your choice : ");
                        scanf("%d",&choiceCP);
                        if(choiceCP == 1)
                        {
                            system("cls");
                            compName();
                            printf("\n\tYou are in MANAGER password changing menu\n\n");
                            goto rechangeM;
                        }
                        if(choiceCP == 2)
                        {
                            staffMenu();
                        }
                        else
                        {
                            printf("\n\tInvalid input try again");
                            delay();
                            system("cls");
                            compName();
                            printf("\n\tYou are in MANAGER password changing menu\n\n");

                            goto reenterchoiceM;

                        }

                }
                else
                {
                    printf("\n\tIncorrect password.. Redirecting to main menu");
                    delay();
                    managerMenu();
                }
    }



}

void accountStatment(int num)
{
    char *status[15];
    int count = 0,choice = 0;
    system("cls");
    compName();
    FILE *accState;
    FILE *printFIle;
    accState = fopen("statement.csv","r");
    remove("printfFIle.txt");
    printFIle = fopen("printfFIle.txt","a+");
    fprintf(printFIle,"\n\n\t\t\t\tABC BANKING COMPANY\n\n");
    fprintf(printFIle,"Below is the bank statement of your account,\n\n\n");
    fclose(printFIle);

        printf("\n\tYou are logged in to view account statement\n\n");
        printf("\tEnter the account nuber to view the statement : ");
        scanf("%d",&view.accNumber);

        printf("\n\n");

        printf("\tAccount Num   Old Balance     Deposit/Withdrawal      New Balance         Transaction Status\n\n");

        while(fscanf(accState,"%d,%f,%f,%f,%s",&new.accNumber,&old.amount,&deposit.amount,&new.amount,status)!=EOF)
        {
            if(view.accNumber == new.accNumber)
            {   count = 1;
                printf("\t%d        %.2f                %.2f          %.2f                 %s\n",new.accNumber,old.amount,deposit.amount,new.amount,status);

                printFIle = fopen("printfFIle.txt","a+");
                fprintf(printFIle,"%d        %.2f                %.2f          %.2f                 %s\n",new.accNumber,old.amount,deposit.amount,new.amount,status);
                fclose(printFIle);


            }






        }
        fclose(accState);

            if(count == 0)
            {
                printf("\n\tNo record for the account you seached\n\n");
            }

        reenterChoice:
        printf("\n\t[1] = Print statement \n\t[2] = Main menu \n\n\tEnter your choice : ");
        scanf("%d",&choice);

        if(choice == 1)
         {
            printFIle = fopen("printfFIle.txt","a+");
            fprintf(printFIle,"\n\n\tThis is an electronically generated document, does not require any signature.\n\n");
            fclose(printFIle);

            system(system("cd  /D \"C:\\Windows\\System32\" & rundll32.exe mshtml.dll,PrintHTML \" D:\\HR\\NIBM____________\\First semester 01\\Programing_Fundemetals\\Project\\MY\\printfFIle.txt"));
            printf("\n\tStatement is printed succefully \n\tLoading Main menu\n");
            remove("printfFIle.txt");
            delay();
            if(num == 5)
           {
                staffMenu();
           }
           else if(num == 10)
           {
                managerMenu();
           }

        }
        else if(choice == 2)
        {
           if(num == 5)
           {
                remove("printfFIle.txt");
                staffMenu();
           }
           else if(num == 10)
           {
                remove("printfFIle.txt");
                managerMenu();
           }
        }
        else
        {
                remove("printfFIle.txt");

                system("cls");
                compName();
                printf("\n\tYou are logged in to check account statement as a staff\n\n");

                printf("\n\tInvalid input tyr again\n");
                goto reenterChoice;


        }






    }

void deletedAccountList()
{
   system("cls");
   compName();
   FILE *ptr;
   //int choice = 0;

   printf("\n\tYou are viewing all deleted accounts list\n\n");

    printf("\n  Acc Num\t  ID num\t  Name\t\t  DOB\t\t   Address\t    Email\t   phone num\t Closing Balance\t    Acc Type\n\n");


    ptr = fopen("deletedAccountList.csv","r");

    while(fscanf(ptr,"%d %s %s %s %d/%d/%d %s %s %s  %f %s \n",&new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType)!=EOF)
    {
        printf("%d %s %s %s %d/%d/%d %s %s %s  %.2f %s \n",new.accNumber, new.idNumber, first.name, last.name, &new.dateOfBirth.day, &new.dateOfBirth.month, &new.dateOfBirth.year, new.address, new.emailID, new.telePhoneNum, &new.amount,new.accountType);
    }
    fclose(ptr);

    printf("\n\tMain menu ");

    system("pause");
    managerMenu();

}

int main()
{
   //compName();

   loginMenu();


}
