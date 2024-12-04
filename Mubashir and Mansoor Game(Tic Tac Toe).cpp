#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char board[3][3];
char player;
char playerName[20];
void Board();
int Winner(char Player);
int Draw();
void switchPlayer();
void computerMove();

void Board() 
{
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            board[i][j]=' ';
        }
    }
    player='X';
}

void printBoard() 
{
    printf("\n");
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            printf(" %c ",board[i][j]);
            if (j<2) 
			printf("|");
        }
        printf("\n");
        if(i < 2) 
		printf("---|---|---\n");
    }
    printf("\n");
}

int Winner(char Player) 
{
    for(int i=0;i<3;i++) 
   {
        if(board[i][0]==Player&&board[i][1]==Player&&board[i][2]==Player)
        {
        	return 1;
		}
        if(board[0][i]==Player&&board[1][i]==Player&&board[2][i]==Player)
        {
        	return 1;
		}
    }
    if(board[0][0]==Player&&board[1][1]==Player&&board[2][2]==Player) 
	{
		return 1;
	}
    if(board[0][2]==Player&&board[1][1]==Player&&board[2][0]==Player) 
	{
		return 1;
	}
    return 0;
}

int Draw() 
{
    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			return 0;
        }
    }
    return 1;
}

void switchPlayer() 
{
    if(player=='X')
    player='O';
    else 
    player='X';
}

void computerMove() 
{
    
    char opponent='X';
    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			{
                board[i][j]=opponent;
                if(Winner(opponent)==1)
				{
                    board[i][j]=player;
                    printf("Computer (Player O) chose: %d %d\n",i+1,j+1);
                    return;
                }
                board[i][j]=' ';
            }
        }
    }

    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			{
                board[i][j]=player;
                if(Winner(player)==1) 
				{
                    printf("Computer (Player O) chose: %d %d\n",i+1,j+1);
                    return;
                }
                board[i][j]=' ';
            }
        }
    }

    if(board[1][1]==' ') 
	{
        board[1][1]=player;
        printf("Computer (Player O) chose: 2 2\n");
        return;
    }

    int side[4][2] = {{0, 1},{1, 0},{1, 2},{2, 1}};
    for(int i=0;i<4;i++) 
	{
        int row = side[i][0];
        int col = side[i][1];
        if (board[row][col] == ' ') 
		{
            board[row][col]=player;
            printf("Computer (Player O) chose: %d %d\n",row+1,col+1);
            return;
        }
    }
    
    int cor[4][2]={{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i=0;i<4;i++) 
	{
        int row=cor[i][0];
        int col=cor[i][1];
        if(board[row][col]==' ') 
		{
            board[row][col]=player;
            printf("Computer (Player O) chose: %d %d\n",row + 1,col + 1);
            return;
        }
    }
}

int main() 
{
    int row, col;
    printf("Enter your First name (Player X): ");
    scanf("%s", playerName);
    Board();
    int u;
    printf("1.If you want computer to play first \n2.If you want to play first\n");
    scanf("%d",&u);
    switch(u)
    {
    case 1:
    {
    switchPlayer();
    computerMove();
    switchPlayer();
    int p=1;
    while(p==1) 
    {
    	printBoard();
        if(player=='X') 
		{
            printf("%s (Player %c), enter your move (row): ",playerName,player);
            scanf("%d",&row);
            printf("%s (Player %c), enter your move (column): ",playerName,player);
            scanf("%d",&col);
            if (row<1||row>3||col<1||col>3||board[row-1][col-1]!=' ') 
            {
                printf("Invalid move\n");
                continue;
            }
            system("cls");
			board[row-1][col-1]=player;
        } else 
		{
            system("cls");
			computerMove();
        }
        if(Winner(player)==1) 
        {
            printBoard();
            if(player == 'X') 
			{
                printf("%s (Player %c) wins\n\n\n",playerName,player);
            } 
			else 
			{
                printf("Computer (Player %c) wins\n\n\n",player);
            }
            break;
        }
        if (Draw()==1) 
        {
            printBoard();
            printf("Draw\n");
            break;
        }
        switchPlayer();
    }
    break;
	}
    
    case 2:
    {
	int p=1;
    while(p==1) 
    {
    	printBoard();
        if(player=='X') 
		{
            printf("%s (Player %c), enter your move (row): ",playerName,player);
            scanf("%d",&row);
            printf("%s (Player %c), enter your move (column): ",playerName,player);
            scanf("%d",&col);
            if (row<1||row>3||col<1||col>3||board[row-1][col-1]!=' ') 
            {
                printf("Invalid move\n");
                continue;
            }
            system("cls");
            board[row-1][col-1]=player;
        } 
		else 
		{
            system("cls");
            computerMove();
        }
        if(Winner(player)==1) 
        {
            printBoard();
            if(player == 'X') 
			{
                printf("%s (Player %c) wins \n\n\n",playerName,player);
            } 
			else 
			{
                printf("Computer (Player %c) wins \n\n\n",player);
            }
            break;
        }
        if(Draw()==1) 
        {
            printBoard();
            printf("Draw\n");
            break;
        }
        switchPlayer();
    }
    break;
	}
	default:
	{
		printf("Invalid Answer \n");
		printf("Restart The Game \n");
		break;
	}
}
    return 0;
}

