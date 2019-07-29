#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ticketno = 1, i, surgeeco = 1000, surgebusi = 2500, seatcnt = 1;

struct boeing
{
    char passname[50], from[50], dest[50], class[20], meal[20];
    float ticketot, surge;
    int age, seatno, tickno;
    char date[8];
    char time[8];
} fl101[100], fl102[100];

int main()
{
    printf("\n---------------------AIRLINE RESERVATION SYSTEM---------------------\n");
    int choice, flightno, tickch, temptno1, temptno2, itr, ctr, mealch, tickcnt;
    char tempname1[50],tempname2[50];
    while(1)
    {
    printf("\n1.Boeing101 2.Boeing102\nEnter flight's number (or enter 3 to exit): ");
    scanf("%d",&flightno);
    if(flightno==1)
    {
flight1:printf("\n1.Reserve Ticket\n2.Display Flight Summary\n3.Cancel Ticket\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("---------RESERVE TICKETS---------\nEnter number of tickets: ");
          scanf("%d",&tickcnt);
          for(itr=0;itr<tickcnt;itr++)
          {
              printf("Enter passenger's name: ");
              scanf("%s",&fl101[itr].passname);
              printf("Enter passenger's age: ");
              scanf("%d",&fl101[itr].age);
              printf("Flight from: ");
              scanf("%s",&fl101[itr].from);
              printf("To: ");
              scanf("%s",&fl101[itr].dest);
              printf("Enter date: ");
              scanf("%s",&fl101[itr].date);
              printf("Enter time: ");
              scanf("%s",&fl101[itr].time);
ticketchoice: printf("Enter ticket class: 1.Business (Rs.8000) 2.Economy (Rs.4500): ");
              scanf("%d",&tickch);
              if(tickch==1)
              {
                 fl101[itr].ticketot=9500;
                 fl101[itr].surge=1500;
                 strcpy(fl101[itr].class,"Business");
              }
              else if(tickch==2)
              {
                 fl101[itr].ticketot=5500;
                 fl101[itr].surge=1000;
                 strcpy(fl101[itr].class,"Economy");
              }
              else
              {
                   printf("\nEnter a vaild option.\n");      
                   goto ticketchoice;
              }
mealchoice:   printf("\nDo you want a meal? 1.Veg Meal (Rs.500) 2.Non-Veg Meal(Rs.650) 3.Kids meal(Rs.250) 4.No meal\n");
              scanf("%d",&mealch);
              if(mealch==1)
              {
                 fl101[itr].ticketot+=500;
                 strcpy(fl101[itr].meal,"Veg meal");
              }
              else if(mealch==2)
              {
                 fl101[itr].ticketot+=650;
                 strcpy(fl101[itr].meal,"Non-Veg meal");
              }
              else if(mealch==3)
              {
                 fl101[itr].ticketot+=250;
                 strcpy(fl101[itr].meal,"Kids meal");
              }
              else if(mealch==4)
                 strcpy(fl101[itr].meal,"No meal");
              else
              {
                   printf("\nEnter a vaild option.\n");      
                   goto mealchoice;
              }
              fl101[itr].seatno = seatcnt;
              fl101[itr].tickno = ticketno;
              seatcnt++;
              ticketno++;
              printf("\nTicket %d booked successfully\n");
          } 
          printf("\nSurge pricing will be charged automatically based on your ticket's class\n");
          goto flight1;
          break;
   case 2:printf("\n----------------FLIGHT SUMMARY----------------\nEnter ticket number: ");
          scanf("%d",&temptno1);
          for(ctr=0;(temptno1!=fl101[ctr].tickno)&&(ctr<ticketno);ctr++);
          printf("\n-------------TICKET DETAILS--------------\nFLIGHT: BOEING101\nPASSENGER NAME: %s\t\tTICKET NUMBER:%d\t\tTICKET CLASS:%s\t\t\n",fl101[ctr].passname,fl101[ctr].tickno,fl101[ctr].class);
          printf("FLIGHT FROM: %s\t\t\tDESTINATION: %s\t\tON %s\t\tAT %s\t\n",fl101[ctr].from,fl101[ctr].dest,fl101[ctr].date,fl101[ctr].time);
          printf("MEAL SELECTED: %s\t\tSurge Charges: %.2f\n",fl101[ctr].meal,fl101[ctr].surge);
          printf("TOTAL TICKET COST: %.2f\nHave an amazing journey\n",fl101[ctr].ticketot);
          goto flight1;
          break;
   case 3:printf("\n----------------TICKET CANCELLATION-----------------\nEnter ticket number: ");
          scanf("%d",&temptno1);           
          for(ctr=0;(temptno1!=fl101[ctr].tickno)&&(ctr<ticketno);ctr++);
          printf("\nTicket cancelled successfully. Rs.%.2f refunded.\n", fl101[ctr].ticketot);
          for(i=ctr;i<(ticketno-1);i++)
              fl101[ctr]=fl101[ctr+1];
          ticketno--;
          goto flight1;    
          break;
   case 4:break;       
   default:printf("\nEnter a valid option"); 
           goto flight1;            
       }
    }
    else if(flightno==2)
    {
flight2:printf("1.Reserve Ticket\n2.Display Flight Summary\n3.Cancel Ticket\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("---------RESERVE TICKETS---------\nEnter number of tickets: ");
          scanf("%d",&tickcnt);
          for(itr=0;itr<tickcnt;itr++)
          {
              printf("Enter passenger's name: ");
              scanf("%s",&fl102[itr].passname);
              printf("Enter passenger's age: ");
              scanf("%d",&fl102[itr].age);
              printf("Flight from: ");
              scanf("%s",&fl102[itr].from);
              printf("To: ");
              scanf("%s",&fl102[itr].dest);
              printf("Enter date: ");
              scanf("%s",&fl102[itr].date);
              printf("Enter time: ");
              scanf("%s",&fl102[itr].time);
ticketchoice1: printf("Enter ticket class: 1.Business (Rs.8000) 2.Economy (Rs.4500): ");
              scanf("%d",&tickch);
              if(tickch==1)
              {
                 fl102[itr].ticketot=9500;
                 fl102[itr].surge=1500;
                 strcpy(fl102[itr].class,"Business");
              }
              else if(tickch==2)
              {
                 fl102[itr].ticketot=5500;
                 fl102[itr].surge=1000;
                 strcpy(fl102[itr].class,"Economy");
              }
              else
              {
                   printf("\nEnter a vaild option.\n");      
                   goto ticketchoice1;
              }
mealchoice1:   printf("\nDo you want a meal? 1.Veg Meal (Rs.500) 2.Non-Veg Meal(Rs.650) 3.Kids meal(Rs.250) 4.No meal\n");
              scanf("%d",&mealch);
              if(mealch==1)
              {
                 fl102[itr].ticketot+=500;
                 strcpy(fl102[itr].meal,"Veg meal");
              }
              else if(mealch==2)
              {
                 fl102[itr].ticketot+=650;
                 strcpy(fl102[itr].meal,"Non-Veg meal");
              }
              else if(mealch==3)
              {
                 fl102[itr].ticketot+=250;
                 strcpy(fl102[itr].meal,"Kids meal");
              }
              else if(mealch==4)
                 strcpy(fl102[itr].meal,"No meal");
              else
              {
                   printf("\nEnter a vaild option.\n");      
                   goto mealchoice1;
              }
              fl102[itr].seatno = seatcnt;
              fl102[itr].tickno = ticketno;
              seatcnt++;
              ticketno++;
              printf("\nTicket %d booked successfully\n");
          } 
          printf("\nSurge pricing will be charged automatically based on your ticket's class\n");
          goto flight2;
          break;
   case 2:printf("\n----------------FLIGHT SUMMARY----------------\nEnter ticket number: ");
          scanf("%d",&temptno1);
          for(ctr=0;(temptno1!=fl102[ctr].tickno)&&(ctr<ticketno);ctr++);
          printf("\n-------------TICKET DETAILS--------------\nFLIGHT: BOEING102\nPASSENGER NAME: %s\t\tTICKET NUMBER:%d\t\tTICKET CLASS:%s\t\t\n",fl102[ctr].passname,fl102[ctr].tickno,fl102[ctr].class);
          printf("FLIGHT FROM: %s\t\t\tDESTINATION: %s\t\tON %s\t\tAT %s\t\n",fl102[ctr].from,fl102[ctr].dest,fl102[ctr].date,fl102[ctr].time);
          printf("MEAL SELECTED: %s\t\tSurge Charges: %.2f\n",fl102[ctr].meal,fl102[ctr].surge);
          printf("TOTAL TICKET COST: %.2f\nHave an amazing journey\n",fl102[ctr].ticketot);
          goto flight2;
          break;
   case 3:printf("\n----------------TICKET CANCELLATION-----------------\nEnter ticket number: ");
          scanf("%d",&temptno1);           
          for(ctr=0;(temptno1!=fl102[ctr].tickno)&&(ctr<ticketno);ctr++);
          printf("\nTicket cancelled successfully. Rs.%.2f refunded.\n", fl102[ctr].ticketot);
          for(i=ctr;i<(ticketno-1);i++)
              fl102[ctr]=fl102[ctr+1];
          ticketno--;
          goto flight2;    
          break;
   case 4:break;       
   default:printf("\nEnter a valid option"); 
           goto flight2;            
       }
    }
    else if(flightno==3)
         return 0;
    else
         printf("\nEnter a valid option\n");     
    }
}






