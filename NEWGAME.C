#include<stdio.h>
#include<conio.h>
  struct move
{  int row;
  int col;
}Hmove[5],cmove;
char winer(void);
int check(void);
struct move make_move(struct move a[]);
char a[3][3]={{'\0'},{'\0'},{'\0'}};
int row=0,col=0;
int main()
{  char chp='X',chw='\0',cht,chb=1;
   int i,j,x,y,move=1;
   struct move Hmove[5],cmove;
   clrscr();
   gotoxy(25,1);
   printf("PRESS 'a' TO MOVE RIGHT ");
   gotoxy(25,2);
   printf("PRESS 'd' TO MOVE LEFT");
   gotoxy(25,3);
   printf("PRESS 'w' TO MOVE UP ");
   gotoxy(25,4);
   printf("PRESS 's' TO MOVE DOWN ");
   gotoxy(25,5);
   printf("PRESS ENTER KEY TO INSERT 'X' OR 'O' ");
   gotoxy(1,2);
//print pattern of game
   x=1;
   y=2;
   for(i=0;i<3;i++)
   {for(j=0;j<3;j++)
     {   gotoxy(x,y);
      printf("___");
	  x=x+4;
     }
     x=1;
     y=y+2;
   }
   //END
  x=2;
  y=1;
  //loop start
  start:
  while(chb==1)
  {    gotoxy(25,7);
  printf("%c's MOVE........",chp);
  gotoxy(x,y);
   cht=getch();
  //switch case start
       switch(cht)
       { case 'a':
	 if(x>2)
	 {  x=x-4;
	    col--;
	    gotoxy(x,y);

	 }goto start;

	 case 'd':
	 if(x<10)
	 {  x=x+4;
	    col++;
	    gotoxy(x,y);

	 }goto start;

	 case 'w':
	 if(y>1)
	 {  y=y-2;
	    row--;
	    gotoxy(x,y);
	 } goto start;

	 case 's':
	 if(y<5)
	 {  y=y+2;
	    row++;
	    gotoxy(x,y);
	 } goto start;

	 case (char)13 :
	 if(a[row][col]=='\0')
	 {a[row][col]=chp;
	 Hmove[move].row=row;
	 Hmove[move].col=col;
	  printf("%c",chp);
	 gotoxy(x,y);
	 if('X'==chp)
	 chp='O';
	 else
	 chp='X';
	 }  break;
	 default:
	 goto start;
       }
       //switch case end
       chw=winer();
       if(chw!='\0')
       break;
   chb=check();
   if(chb==0)
   break;
   cmove=make_move(Hmove);
   if(cmove.row<3&&cmove.col<3)
   { a[cmove.row][cmove.col]=chp;
     chp='X';

   }
  }
  //loop end
  gotoxy(1,9);
  if(chw=='\0')
  printf("........Game is tie.........");
  else
  printf(".......%c is winer........ ",chw);


 getch();
 return 0;
}
//winer cheking funtion
char winer(void)
{  int i;
  for(i=0;i<3;i++)
  {  if('X'==a[i][0]||'O'==a[i][0])
      {    if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
	    return a[i][0];
      }
      if('X'==a[0][i]||'O'==a[0][i])
      {    if(a[0][i]==a[1][i]&&a[1][i]==a[2][i])
	    return a[0][i];
      }
  }
  if('X'==a[0][0]||'O'==a[0][0])
      {    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
	    return a[0][0];
      }
      if('X'==a[0][2]||'O'==a[0][2])
      {    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
	    return a[0][2];
      }
      return '\0';
}
//check matrix empty or not
int check(void)
{  int i,j;
      for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
       { if(a[i][j]=='\0')
	 {  return 1;
	 }
       }
    }
    return 0;
}


struct move make_move(struct move a[])
{  int i;
FILE *fp;
struct move b[5],c;
fp=fopen("game.dat","rb");
     start:
    while((i=getw(fp))!=EOF)
    { b[0].row=i;
      b[0].col=getw(fp);
      for(i=1;i<5;i++)
       { b[i].row=getw(fp);
	b[i].col=getw(fp);
       }
       for(i=0;i<5;i++)
       {   if(a[i].row==b[i].row&&a[i].col==b[i].col)
	    continue;
	     else
	    { getw(fp);
	      getw(fp);
	      goto start;
	    }
       }
       c.row=getw(fp);
       c.col=getw(fp);
       return c;
    }
    c.row=5;
    c.col=5;
    return c;
}