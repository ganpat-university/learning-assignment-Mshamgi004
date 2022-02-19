// ATM //

#include<stdio.h>

int login();
void CheckBalance(int);
void withdrawl(int);
void deposite(int); 

int id[6]={0,1,2,3,4,5};
int pin[6]={0,111,222,333,444,555};
int balance[6]={0,1000,2000,3000,4000,5000};

void main()
{
     int op;
     int u=login();
     if(u>0)
     {
        printf("user %d logged in succesfully\n", u);
        
        do 
        {
               printf("What you want to do ?\n Enter 1 for balance enquiry\n Enter 2 for cash withdrawl\n Enter 3 for cash      deposit\n Enter 4 for quit\n");
               scanf("%d", &op);
               switch(op)
                        { 
                        case 1:
                        CheckBalance(u);
                        break;
                 
                        case 2:
                        withdrawl(u);
                        break;
                 
                        case 3:
                        deposite(u);
                        break;
                 
                        case 4:
                        printf("Thank you for visiting our bank !!!\n");
                        break;
                 
                        default:
                        printf("Invalid input\n");
                        }
        }        
        while(op!=4); 
                        }
                        else
                           {
                             printf("Card Blocked");
                           }
}  

      int login()
      {
         int i,p,chance=3;
         printf("Enter your account id\n");
         scanf("%d",&i);
         do 
         {
                 printf("Enter pin no: \n");
                 scanf("%d" , &p);
                 if(p!=pin[i])
                 chance--;
         }  
         while(p!=pin[i] && chance>0);
         
         if(chance==0)
         {
                 return - 1;
         }
         else
         {
                 return i;
         } 
      }

void CheckBalance(int a)
{
      printf("Balance of user %d is %d\n",a,balance[a]);
}

void withdrawl(int a)
{
      int amount;
      printf("Enter the amount:\n");
      scanf("%d", &amount);
      if(balance[a]>=amount)
      {
          balance[a]=balance[a]-amount;
      }
      else
          printf("Insufficiant balance\n");
}

void deposite(int a)
{
      int amount;
      printf("Enter the amount:\n");
      scanf("%d", &amount);
      balance[a]=balance[a]+amount;

}                    
                  
                                            
                 
