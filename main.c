#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char T[9][9],mat[9]={'1','2','3','4','5','6','7','8','9'};
int cpt=0,tab[9][9];
int solve_sudoku(char board[9][9],int tab[9][9]);
void interface()
{ system("cls");
  printf("************************************************************************************************************************************************************************************************************************************************");
  printf("\n\n\n\n\n\n\t\t\t\t");
  printf("  ______                 __          __  \n");
  printf("\t\t\t\t");
  printf(" /      \x5c               |  \x5c        |  \x5c \n");
  printf("\t\t\t\t");
  printf("|  \xB2\xB2\xB2\xB2\xB2\xB2\x5c__    __  ____| \xB2\xB2 ______ | \xB2\xB2   __ __    __\n");
  printf("\t\t\t\t");
  printf("| \xB2\xB2___\x5c\xB2\xB2  \x5c  |  \x5c/      \xB2\xB2/      \x5c| \xB2\xB2  /  \x5c  \x5c  |  \x5c\n");
  printf("\t\t\t\t");
  printf(" \x5c\xB2\xB2    \x5c| \xB2\xB2  | \xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\x5c \xB2\xB2_/  \xB2\xB2 \xB2\xB2  | \xB2\xB2\n");
  printf("\t\t\t\t");
  printf(" _\x5c\xB2\xB2\xB2\xB2\xB2\xB2\x5c \xB2\xB2  | \xB2\xB2 \xB2\xB2  | \xB2\xB2 \xB2\xB2  | \xB2\xB2 \xB2\xB2   \xB2\xB2| \xB2\xB2  | \xB2\xB2\n");
  printf("\t\t\t\t");
  printf("|  \x5c__| \xB2\xB2 \xB2\xB2__/ \xB2\xB2 \xB2\xB2__| \xB2\xB2 \xB2\xB2__/ \xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\x5c| \xB2\xB2__/ \xB2\xB2\n");
  printf("\t\t\t\t");
  printf(" \x5c\xB2\xB2    \xB2\xB2\x5c\xB2\xB2    \xB2\xB2\x5c\xB2\xB2    \xB2\xB2\x5c\xB2\xB2    \xB2\xB2 \xB2\xB2  \x5c\xB2\xB2\x5c\x5c\xB2\xB2    \xB2\xB2\n");
  printf("\t\t\t\t");
  printf("  \x5c\xB2\xB2\xB2\xB2\xB2\xB2  \x5c\xB2\xB2\xB2\xB2\xB2\xB2  \x5c\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \x5c\xB2\xB2\xB2\xB2\xB2\xB2 \x5c\xB2\xB2   \x5c\xB2\xB2 \x5c\xB2\xB2\xB2\xB2\xB2\xB2\n");
  printf("\n\n\n\n\t\t\t\t\t\t    ");
  printf("* PRESS TO PLAY ! *");
  printf("\n\t\t\t\t\t\t\t    ");
  getchar();
  system("cls");



}
int verify_num(char board[9][9],int row, int col,char nu)
{    int l,c,L,C,intial1,intial2;
    //verify row
     for(l=0;l<9;l++)
     { if(board[l][col]==nu && l!=row)
          return 0;
     }
    //verify column
    for(c=0;c<9;c++)
     { if(board[row][c]==nu && c!=col)
          return 0;
     }
    //verify nonet
    if(row>=0 && row<=2 )
      {L=3;
      intial1=0;
      }
    else if(row>=3 && row<=5)
          {L=6;
           intial1=3;
          }
         else
          {L=9;
           intial1=6;
          }
    if(col>=0 &&col<=2)
      {C=3;
       intial2=0;
      }
    else if(col>=3 &&col<=5)
           {C=6;
            intial2=3;
           }
         else
           {C=9;
            intial2=6;
          }
  for(int l=intial1 ;l<L;l++)
   { for(int c=intial2;c<C;c++)
     { if(nu==board[l][c] && (l!=row || c!=col) )
         {
          return 0;
         }
     }
   }
  return 1;
}


void create_table(char board[9][9], char Mat[9]) {
  int i, j, num, r, c;
  srand(time(NULL));


  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      board[i][j] = '.';
    }
  }


  for (i = 0; i < 9; i += 3) {
    for (j = 0; j < 9; j += 3) {
      num = rand() % 9 + 1;
      for (r = i; r < i + 3; r++) {
        for (c = j; c < j + 3; c++) {
          while (!verify_num(board, r, c, num + '0') && solve_sudoku(board,tab)==1) {
            num = (num + 1) % 9 + 1;
          }
          board[r][c] = num  +'0';
        }
      }
    }
  }


  solve_sudoku(board, tab);


  for (i = 0; i < 40; i++) {
    r = rand() % 9;
    c = rand() % 9;
    board[r][c] = '.';
  }



}

int check_empty_case(char board[9][9])
{
  for(int i=0;i<9;i++)
  { for(int j=0;j<9;j++)
    { if(board[i][j]=='.')
        return 1;
    }
  }
  return 0;
}
int verify_table(char board[9][9])
{   int l,c;

   if(!check_empty_case)
     {

        for(int m=0;m<9;m++)
            {for(int n=0;n<9;n++)
              { for(int k=n+1;k<9;k++)
                 { if(board[m][n]==board[m][k] || board[n][m]==board[k][m] )
                    { cpt++;
                      return 0;
                      Sleep(2000);
                    }
                 }
                 if(m>=0 && m<=2 )
                   l=2;
                 else if(m>=3 && m<=5)
                          l=5;
                      else
                          l=8;
                 if(n>=0 &&n<=2)
                     c=2;
                   else if(n>=3 &&n<=5)
                          c=5;
                        else
                          c=8;
                for(int i=0 ;i<l;i++)
                { for(int j=0;j<c;j++)
                  { if(board[m][n]==board[i][j] && i!=m &&j!=n )
                      { cpt++;
                       return 0;
                       Sleep(2000);

                      }
                  }
                }

               }
            }
   }
 return 1;
}

int solve_sudoku(char board[9][9],int tab[9][9])
{
  int i,j,k=0,o=0,p;
  char num;

  if(check_empty_case(board)==0)
    return 1;

  for(i=0;i<9;i++){
    for(j=0;j<9;j++)
    {
      if(tab[i][j]==0)
      {
        for(num='1';num<='9';num++)
        {
          if(verify_num(board,i,j,num)==1)
          {
            board[i][j]=num;
            tab[i][j]=1;
            if(solve_sudoku(board,tab)==1)
              return 1;
            board[i][j]='.';
            tab[i][j]=0;
          }
        }
        return 0 ;
      }
    }
  }
  return 0;
}

void table(char board[9][9])
{
  printf("\n\t\t\t\t   ********************** SUDOKU **********************\n");
  printf("\t\t\t\t                  *************************          ");
  printf("\n\n\n\n\t\t\t\t\t      ");
  for(int k=0;k<9;k++)
        printf("%d   ",k);
  printf("\n\t\t\t\t\t  ");
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<20;j++)
     if(i==0 || i==3 || i==6 || i==9)
       printf("==");
    else
       printf("--");
   printf("\n\t\t\t\t\t ");
   for(int k=0;k<9;k++)
    { if(k==0 || k==3 || k==6 || k==9)
       if(k==0)
        printf("%d|| %c ",i,board[i][k]);
       else
        printf("|| %c ",board[i][k]);
      else
        printf("| %c ",board[i][k]);
    }
   printf("||\n\t\t\t\t\t  ");

  }
  for(int j=0;j<20;j++)
     printf("==");
   printf("\n\t\t\t\t\t");
}
int pause(char board[9][9])
{  int ch;
   char c;
  printf("\n\t\t\t\t   ********************** SUDOKU **********************\n");
  printf("\t\t\t\t                  *************************          ");
  printf("\n\n\n\n\n\n\t\t\t\t\t\t   ");
  printf("=========pause=========");
  printf("\n\t\t\t\t\t\t   |\t\t\t |");
  printf("\n\t\t\t\t\t\t   ");
  printf("|      1.continue     |");
  printf("\n\t\t\t\t\t\t   ");
  printf("|      2.solve it!    |");
  printf("\n\t\t\t\t\t\t   ");
  printf("|      3.Menu         |");
  printf("\n\t\t\t\t\t\t   ");
  printf("|      4.Quit         |");
   printf("\n\t\t\t\t\t\t   ");
  printf("=======================");
  printf("\n\t\t\t\t\t\t\t      ");
  scanf("%d",&ch);
  switch(ch)
  { case 1 : return 1;
             break;
    case 2 : {
               return 2;
              }
              break;
    case 3 : {return 3;
            }
             break;
    case 4 : return 4;
             break;
  }

}

int main()
{
    int i,j,m,n,nb,k;
    char nbr,p;
    start:
    system("color B");
    interface();


    create_table(T,mat);


    for( m=0;m<9;m++)
      {for( n=0;n<9;n++)
       { if(T[m][n]!='.')
          tab[m][n]=1;
         else
           tab[m][n]=0;

       }

      }
     table(T);
     keep:
     do{
       cpt=0;
       table(T);

         printf("\n\n\t\t\t\t\t\t         *-1 : pause* \n\n\t\t\t\t\t\t\t  coordinate\n\n\t\t\t\trow = ");
         scanf("%d",&i);
         if(i==-1)
         {system("cls");
          switch(pause(T))
          { case 1 : goto keep;
                     break;
            case 2 : { system("cls");
                       cpt=solve_sudoku(T,tab);
                       table(T);
                       p=getchar();
                       p=getchar();
				       goto start;
			          }
                     break;
            case 3 : {getchar();
                     goto start;
                     }
                      break;
            case 4 : goto quit;
                     break;
          }
         }
         printf("\n\n\t\t\t\tcolumn = ");
         scanf("%d",&j);
          if(j==-1)
         {system("cls");
          switch(pause(T))
          { case 1 : goto keep;
                     break;
            case 3 : { getchar();
                     goto start;
                     }
                      break;
            case 4 : goto quit;
                     break;
          }
         }
         printf("\n\n\t\t\t\t\t\t\t    digit\n\t\t\t\t\t\t\t      ");
         scanf("%d",&nb);
          if(nb==-1)
         {system("cls");
          switch(pause(T))
          { case 1 : goto keep;
                     break;
            case 3 : { getchar();
                     goto start;
                     }
                      break;
            case 4 : goto quit;
                     break;
          }
         }
         nbr=nb+48;
       if(tab[i][j]==0 && i>=0 && i<9 && j>=0 && j<9 && nb>0 && nb<=9 )
         T[i][j]=nbr;
       verify_table(T);

        system("cls");
    }while(cpt!=0 || check_empty_case(T) );
     printf("\n\n\t\t\t\t\t\t      you win the game\n");
     quit:
        system("cls");
    return 0;
}
