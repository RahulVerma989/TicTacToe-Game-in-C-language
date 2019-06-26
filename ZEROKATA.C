#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
void game(int);

void intro(void)
{
 gotoxy(30,13);
 printf("Welcome to Zero Katta");
 gotoxy(57,24);
 printf("Developed by Rahul Verma");
 delay(1500);
 cleardevice();
}

void grid(void)
{
     line(300,150,300,300);   //vertical 1
     line(350,150,350,300);    //vertical 2
     line(250,200,400,200);    //horizontal 1
     line(250,250,400,250);    //horizontal 2
}


int choice(void)
{ int c;
 again:
 cleardevice();
  gotoxy(30,13);
  printf("Choose\n");
  printf("1. X\t 2. 0\t 3.Exit");
  scanf("%d",&c);
  if(c!=1&&c!=2&&c!=3)
   {  gotoxy(35,24);
      printf("Invalid Input");
      delay(50);
      goto again;
   }
  return c;
}



void zero(int b)
{  if(b>=0&&b<=2)
    circle(275+(b)*50,175,20);
   else
    if(b>=3&&b<=5)
     circle(275+(b-3)*50,225,20);
   else
    if(b>=6&&b<=8)
     circle(275+(b-6)*50,275,20);
}

void cross(int b)
{
  if(b>=0&&b<=2)
    {line(260+ b*50,160,290+ b*50,190);
     line(260+ b*50,190,290+ b*50,160);
     }
   else
    if(b>=3&&b<=5)
    {line(260+(b-3)*50,210,290+(b-3)*50,240);
     line(260+(b-3)*50,240,290+(b-3)*50,210);
     }
   else
    if(b>=6&&b<=8)
    {line(260+(b-6)*50,260,290+(b-6)*50,290);
     line(260+(b-6)*50,290,290+(b-6)*50,260);
    }
}

void numbers(void)
{  int i,j,k=0;
 for(j=0;j<=2;j++)
 for(i=0;i<=2;i++)
   { gotoxy(37+i*6,12+j*3);
     printf("%d",k++);
   }
}
void compwin(void)
{
      gotoxy(35,24);
      printf("COMPUTER WINS");
      delay(1500);
      cleardevice();
      gotoxy(35,13);
      printf("Thankyou For Playing");
}
void userwin(void)
{
      gotoxy(35,24);
      printf("YOU WIN");
      delay(1500);
      cleardevice();
      gotoxy(35,13);
      printf("Thankyou For Playing");
}

void draw(void)
{     gotoxy(35,24);
      printf("DRAW");
      delay(1500);
      cleardevice();
      gotoxy(35,13);
      printf("Thankyou For Playing");
}

int decide(int a,int check[3][3])
{ int r,c,w,u;
   for(r=0;r<=2;r++)          //row wise checking
   {   w=0; u=0;
    for(c=0;c<=2;c++)
      { if(check[r][c]==a)         //checking for computer
	 { w++;
	   if(w==3)
	   { line(275,175+r*50,375,175+r*50);
	     compwin();
	     goto end;
	   }
	 }
	else
	if(check[r][c]==(1-a))     //checking same condition for user
	  { u++;
	   if(u==3)
	    { line(275,175+r*50,375,175+r*50);
	      userwin();
	      goto end;
	    }
	  }
      }
   }

       for(c=0;c<=2;c++)     //if comp & user fails in row wise checking
	{   w=0;u=0;          //column wise checking
	  for(r=0;r<=2;r++)
	   { if(check[r][c]==a)        //checking for computer
		{ w++;
		  if(w==3)
		   { line(275+c*50,175,275+c*50,275);
		     compwin();
		     goto end;
		   }
		}
	     else
	     if(check[r][c]==(1-a))         //checking for user
		{ u++;
		  if(u==3)
		  { line(275+c*50,175,275+c*50,275);
		    userwin();
		    goto end;
		  }
		}
	   }
	}

	 {    w=0;u=0;         //if comp & user fails in column wise checking
	   for(c=0;c<=2;c++)  //checking 1st diagonal(from (0,0) to (2,2))
	   { if(check[c][c]==a)
	     {  w++;
		if(w==3)
	       { line(275,175,375,275);
		 compwin();
		 goto end;
	       }
	     }
	      else
	      if(check[c][c]==(1-a))              //checking for user
	     {  u++;
		if(u==3)
	       { line(275,175,375,275);
		 userwin();
		 goto end;
	       }
	     }

	   }
	 }

	{ w=0;u=0;            //if comp & User fails in 1st diagonal
	  for(r=0;r<=2;r++)  //checking 2nd diagonaly from (0,2) to (2,0)
	  {
	    { if(check[r][2-r]==a)
	       { w++;
		if(w==3)
		 { line(375,175,275,275);
		   compwin();
		   goto end;
		 }
	       }
	       else
	       if(check[r][2-r]==(1-a))
	       { u++;
		 if(u==3)
		 { line(375,175,275,275);
		   userwin();
		   goto end;
		 }
	       }
	     }
	  }
       }
	  if(w<3&&u<3)
	   for(r=0;r<=2;r++)
	    for(c=0;c<=2;c++)
	    if(check[r][c]!=1&&check[r][c]!=0)
		return 5;

	      draw();

 end:
 return 0;
}



void game(int cho)
{  int i,r,c,m=0,d,check[3][3]={3,3,3,3,3,3,3,3,3};
 while(1)
 {     if(m>=3)
      {  delay(1000);
	 d=decide(cho-1,check);
	 if(d==5)
	  goto inputagain;
	 else
	 break;
      }

    inputagain:
   gotoxy(14,10);
   printf("Input:");
   fflush(stdin);
   scanf("%d",&i);        //user gives input
   if(cho==1)
   {
    if(i>=0&&i<=2)
     { if(check[0][i]==3)
       { check[0][i]=cho; cross(i);}
       else
       { gotoxy(35,24);
	 printf("Invalid input");
	 goto inputagain;
       }
     }
    else
    if(i>=3&&i<=5)
     { if(check[1][i-3]==3)
       {check[1][i-3]=cho; cross(i);}
       else
       { gotoxy(35,24);
	 printf("Invalid input");
	 goto inputagain;
       }
     }
    else
    if(i>=6&&i<=8)
     { if(check[2][i-6]==3)
       { check[2][i-6]=cho; cross(i);}
       else
       { gotoxy(35,24);
	 printf("Invalid input");
	 goto inputagain;
       }
     }
    else
      { gotoxy(35,24);
	printf("Invalid input");
	goto inputagain;
      }
   }
   else
   if(cho==2)
   {
     if(i>=0&&i<=2)
     { if(check[0][i]==3)
	{ check[0][i]=0; zero(i);}
       else
	{ gotoxy(35,24);
	  printf("Invalid input");
	  goto inputagain;
	}
     }
     else
     if(i>=3&&i<=5)
      {	if(check[1][i-3]==3)
	 { check[1][i-3]=0; zero(i);}
	else
	 { gotoxy(35,24);
	   printf("Invalid input");
	   goto inputagain;
	 }
      }
     else
     if(i>=6&&i<=8)
     { if(check[2][i-6]==3)
       { check[2][i-6]=0; zero(i);}
       else
	{ gotoxy(35,24);
	  printf("Invalid input");
	  goto inputagain;
	}
     }
    else
      { gotoxy(35,24);
	printf("Invalid input");
	goto inputagain;
      }
   }
    m++;
    if(m>=3)                   //checking after every input >3
      {  delay(1000);
	 d=decide(cho-1,check);
	 if(d==5)
	  goto output;
	 else
	 break;
      }
	output:
      chec:
	randomize();
	randomize();
       r=rand()%3;
       c=rand()%3;
    { if(check[r][c]!=0&&check[r][c]!=1)      //computer gives input
	 if(1-cho)
	 { if(r==0)
	   { cross(c); check[0][c]=1;}
	   else
	    if(r==1)
	     { cross(3+c); check[1][c]=1;}
	    else
	     if(r==2)
	      { cross(6+c); check[2][c]=1;}
	 }
	 else
	 { if(r==0)
	    { zero(c);    check[0][c]=0;}
	   else
	    if(r==1)
	    { zero(3+c);  check[1][c]=0;}
	    else
	     if(r==2)
	      { zero(6+c);  check[2][c]=0;}
	 }
      else                //if random block is filled then we check full
			  //full array for any empty block if empty then
	  {  for(r=0;r<=2;r++) //a random number is generated else we decide.
	     for(c=0;c<=2;c++)
	     if(check[r][c]!=0&&check[r][c]!=1)
	       goto chec;

	       delay(1000);
	       decide(cho-1,check); //deciding after computer make its move
	       break;
	  }

    }

  }

}
void main()
{ int c,gm,gd=DETECT;
clrscr();
initgraph(&gd,&gm," ");
 intro();
 c=choice();
 if(c==3)
 exit(0);
 cleardevice();
 gotoxy(35,5);
 printf("Provide Input");
 grid();
numbers();
game(c);
fflush(stdin);
 getch();
 closegraph();
  }
