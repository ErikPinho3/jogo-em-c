#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PLAYER '&'
#define MONSTER 'X'
#define MONSTER2 'V'
#define WALL '*'
#define KEY '@'
#define DOOR_CLOSED 'D'
#define DOOR_OPEN '='
#define SPIKE '#'
#define BUTTON 'B'
#define TPLEFT '<'
#define TPRIGHT '>'
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define MAP_WIDTH2 20
#define MAP_HEIGHT2 20
#define MAP_WIDTH3 40
#define MAP_HEIGHT3 40

void printMap1(char map[][MAP_WIDTH], int height, int width, int playerX, int playerY)
{
    system("cls");
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == playerY && j == playerX)
            {
                printf("%c ", PLAYER);
            }
            else
            {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void initializeMap1(char map[][MAP_WIDTH], int height, int width)
{
    int i, j;
    
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            map[i][j] = '.';
        }
    }
    
    map[1][1] = PLAYER;
    
    for(i=0;i<10;i++)
    {
        map[0][0] = map[0][width - i] = map[height - i][0] = map[height - 1][width - i] = map[height - i][width -1] = WALL;
    }
    
    map[3][3] = KEY;
    map[7][7] = DOOR_CLOSED;
}

void moveMonster(char map2[][MAP_WIDTH2], int height, int width, int *monsterX, int *monsterY) 
{
    int direction = rand() % 4;

    int newX = *monsterX, newY = *monsterY;
    switch (direction) 
    {
        case 0:
            newY = *monsterY - 1;
            break;
        case 1:
            newY = *monsterY + 1;
            break;
        case 2:
            newX = *monsterX - 1;
            break;
        case 3:
            newX = *monsterX + 1;
            break;
    }

    if (newX >= 0 && newX < width && newY >= 0 && newY < height && map2[newY][newX] != WALL && map2[newY][newX] != SPIKE) 
    {
        *monsterX = newX;
        *monsterY = newY;
    }
}

void moveMonster2(char map2[][MAP_WIDTH2], int height, int width, int *monsterX2, int *monsterY2, int playerX, int playerY) 
{
    int dx = playerX - *monsterX2;
    int dy = playerY - *monsterY2;

    if (abs(dx) > abs(dy)) 
	{
        int newMonsterX2 = *monsterX2 + (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
        
        if (newMonsterX2 >= 0 && newMonsterX2 < width && map2[*monsterY2][newMonsterX2] != WALL && map2[*monsterY2][newMonsterX2] != SPIKE) 
		{
            *monsterX2 = newMonsterX2;
        }
    } 
	else 
	{
        int newMonsterY2 = *monsterY2 + (dy > 0 ? 1 : (dy < 0 ? -1 : 0));
        if (newMonsterY2 >= 0 && newMonsterY2 < height && map2[newMonsterY2][*monsterX2] != WALL && map2[newMonsterY2][*monsterX2] != SPIKE) {
            *monsterY2 = newMonsterY2;
        }
    }
}

void initializeMap2(char map2[][MAP_WIDTH2], int height, int width, int *monsterX, int *monsterY, int *monsterX2, int *monsterY2)
{
    int i, j;
    height = 20;
    width = 20;
    
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            map2[i][j] = '.';
        }
    }
    
    map2[1][1] = PLAYER;
    
    for(i=0;i<20;i++)
    {
        map2[0][0] = map2[0][width - i] = map2[height - i][0] = map2[height - 1][width - i] = map2[height - i][width -1] = WALL;
    }
    
    map2[2][1] = KEY;
    map2[7][7] = DOOR_CLOSED;
    map2[8][7] = SPIKE;
    map2[7][6] = SPIKE;
    map2[7][8] = SPIKE;
    map2[6][7] = SPIKE;
    map2[5][5] = BUTTON;

    *monsterX = 10;
    *monsterY = 10;
    *monsterX2 = 18;
    *monsterY2 = 18;
}

void printMap2(char map2[][MAP_WIDTH2], int height, int width, int playerX, int playerY, int monsterX, int monsterY, int monsterX2, int monsterY2) 
{
    system("cls");
    int i, j;
    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            if (i == playerY && j == playerX) 
            {
                printf("%c ", PLAYER);
            } 
            else if (i == monsterY && j == monsterX) 
            {
                printf("%c ", MONSTER);
            } 
            else if(i == monsterY2 && j == monsterX2)
            {
                printf("%c", MONSTER2);
            }
            else 
            {
                printf("%c ", map2[i][j]);
            }
        }
        printf("\n");
    }
}

void moveMonster3(char map3[][MAP_WIDTH3], int height, int width, int *monsterX, int *monsterY) 
{
    int direction = rand() % 4;

    int newX = *monsterX, newY = *monsterY;
    switch (direction) 
    {
        case 0:
            newY = *monsterY - 1;
            break;
        case 1:
            newY = *monsterY + 1;
            break;
        case 2:
            newX = *monsterX - 1;
            break;
        case 3:
            newX = *monsterX + 1;
            break;
    }

    if (newX >= 0 && newX < width && newY >= 0 && newY < height && map3[newY][newX] != WALL && map3[newY][newX] != SPIKE) 
    {
        *monsterX = newX;
        *monsterY = newY;
    }
}

void moveMonster4(char map3[][MAP_WIDTH3], int height, int width, int *monsterX2, int *monsterY2, int playerX, int playerY) 
{
    int dx = playerX - *monsterX2;
    int dy = playerY - *monsterY2;

    if (abs(dx) > abs(dy)) 
	{
        int newMonsterX2 = *monsterX2 + (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
        
        if (newMonsterX2 >= 0 && newMonsterX2 < width && map3[*monsterY2][newMonsterX2] != WALL && map3[*monsterY2][newMonsterX2] != SPIKE) 
		{
            *monsterX2 = newMonsterX2;
        }
    } 
	else 
	{
        int newMonsterY2 = *monsterY2 + (dy > 0 ? 1 : (dy < 0 ? -1 : 0));
        if (newMonsterY2 >= 0 && newMonsterY2 < height && map3[newMonsterY2][*monsterX2] != WALL && map3[newMonsterY2][*monsterX2] != SPIKE) {
            *monsterY2 = newMonsterY2;
        }
    }
}

void initializeMap3(char map3[][MAP_WIDTH3], int height, int width, int *monsterX, int *monsterY, int *monsterX2, int *monsterY2)
{
    int i, j;
    height = 40;
    width = 40;
    
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            map3[i][j] = '.';
        }
    }
    
    map3[1][1] = PLAYER;
    
    for(i=0;i<40;i++)
    {
        map3[0][0] = map3[0][width - i] = map3[height - i][0] = map3[height - 1][width - i] = map3[height - i][width -1] = WALL;
    }
    
    map3[30][30] = DOOR_CLOSED;
    map3[31][30] = SPIKE;
    map3[30][29] = SPIKE;
    map3[30][31] = SPIKE;
    map3[29][30] = SPIKE;
    map3[2][1] = SPIKE;
    map3[2][2] = SPIKE;
    map3[2][3] = SPIKE;
    map3[2][4] = SPIKE;
    map3[2][5] = SPIKE;
    map3[3][5] = SPIKE;
    map3[4][5] = SPIKE;
    map3[5][5] = SPIKE;
    map3[3][1] = SPIKE;
    map3[4][1] = SPIKE;
    map3[5][1] = SPIKE;
    map3[6][1] = SPIKE;
    map3[6][2] = SPIKE;
    map3[6][3] = SPIKE;
    map3[6][4] = SPIKE;
    map3[6][5] = SPIKE;
    map3[20][20] = KEY;
    map3[25][25] = BUTTON;
    map3[19][20] = TPLEFT;
    map3[5][4] = TPRIGHT;

    *monsterX = 10;
    *monsterY = 10;
    *monsterX2 = 18;
    *monsterY2 = 18;
}

void printMap3(char map3[][MAP_WIDTH3], int height, int width, int playerX, int playerY, int monsterX, int monsterY, int monsterX2, int monsterY2) 
{
    system("cls");
    int i, j;
    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            if (i == playerY && j == playerX) 
            {
                printf("%c ", PLAYER);
            } 
            else if (i == monsterY && j == monsterX) 
            {
                printf("%c ", MONSTER);
            } 
            else if(i == monsterY2 && j == monsterX2)
            {
                printf("%c", MONSTER2);
            }
            else 
            {
                printf("%c ", map3[i][j]);
            }
        }
        printf("\n");
    }
}

int checkCollision(char map[][MAP_WIDTH], int height, int width, int x, int y)
{
    if (map[y][x] == WALL || map[y][x] == DOOR_CLOSED)
    {
        return 1;
    }
    return 0;
}

int checkCollision2(char map2[][MAP_WIDTH2], int height, int width, int x, int y)
{

    if (map2[y][x] == WALL || map2[y][x] == DOOR_CLOSED)
    {
        return 1;
    }
    return 0;
}

int checkCollision3(char map3[][MAP_WIDTH3], int height, int width, int x, int y)
{

    if (map3[y][x] == WALL || map3[y][x] == DOOR_CLOSED)
    {
        return 1;
    }
    return 0;
}

void collectKey()
{
    printf("Voce coletou a chave!\n");
}

int main()
{
    char map1[MAP_HEIGHT][MAP_WIDTH];
    char map2[MAP_HEIGHT2][MAP_WIDTH2];
    char map3[MAP_HEIGHT3][MAP_WIDTH3];
    int playerX = 1, playerY = 1, nivel = 1, monsterX2 = 15, monsterY2 = 15;
    int hasKey = 0;
    int lives = 3;

    int choice;

    printf("Bem-vindo ao Jogo!\n");

    do
    {
         
        printf("\nMenu:\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Tutorial\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
         

        switch (choice)
        {
            case 1:
                 
                initializeMap1(map1, MAP_HEIGHT, MAP_WIDTH);
                 
                while (lives > 0)
                {
                    printMap1(map1, MAP_HEIGHT, MAP_WIDTH, playerX, playerY);

                    char move;
                 
                    printf("Movimente o jogador (W, A, S, D), Interaja com o jogo (I): ");
                 
                    scanf(" %c", &move);
                 
                    int newX = playerX, newY = playerY;
                 
                    switch (move)
                    {
                        case 'w':
                        case 'W':
                            newY = playerY - 1;
                            break;
                         
                        case 'a':
                        case 'A':
                            newX = playerX - 1;
                            break;
                         
                        case 's':
                        case 'S':
                         
                            newY = playerY + 1;
                            break;
                         
                        case 'd':
                        case 'D':
                         
                            newX = playerX + 1;
                            break;
                         
                        case 'i':
                        case 'I':

                            if (playerY == 3 && playerX == 3)
                            {
                                hasKey = 1;
                                collectKey();
                            }
                            else if (((playerY == 5 || playerY == 7) && (playerX == 6 || playerX == 8)) || ((playerY == 6 || playerY == 8) && (playerX == 5 || playerX == 7)) && hasKey == 1)
                            {
                                map1[7][7] = DOOR_OPEN;
                                printf("voce abriu a porta");
                                usleep(300000);
                            }
                            else if (playerY == 7 && playerX == 7)
                            {
                                printf("Voce passou de nivel!\n");
                                usleep(300000);
                                int monsterX, monsterY;
                                initializeMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY, &monsterX2, &monsterY2);
                                
                            	inicio:
                                playerY = 1;
                                playerX = 1;
                                newY = 1;
                                newX = 1;
                                
                                while (1)
                                {
                                    moveMonster(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY);
                                    
                                    moveMonster2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX2, &monsterY2, playerX, playerY);
                                    
                                    printMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, playerX, playerY, monsterX, monsterY, monsterX2, monsterY2);
                                    char move;
                                    printf("Movimente o jogador (W, A, S, D), Interaja com o jogo (I): ");
                                    scanf(" %c", &move);
                                    int newX = playerX, newY = playerY;
                                    switch (move)
                                    {
                                        case 'w':
                                        case 'W':
                                            newY = playerY - 1;
                                            break;
                             
                                        case 'a':
                                        case 'A':
                                            newX = playerX - 1;
                                            break;
                             
                                        case 's':
                                        case 'S':
                                            newY = playerY + 1;
                                            break;
                             
                                        case 'd':
                                        case 'D':
                                            newX = playerX + 1;
                                            break;
                                        case 'i':
                                        case 'I':
                        
                                            if (playerY == 20 && playerX == 20)
                                            {
                                                hasKey = 1;
                                                collectKey();
                                            }
                                            else if(playerY == 5 && playerX == 5)
                                            {
                                            	printf("voce apertou o butao, os espinhos sumiram");
                                            	usleep(500000);
                                                map2[8][7] = '.';
                                                map2[7][6] = '.';
                                                map2[7][8] = '.';
                                                map2[6][7] = '.';
                                            }
                                            else if (((playerY == 5 || playerY == 7) && (playerX == 6 || playerX == 8)) || ((playerY == 6 || playerY == 8) && (playerX == 5 || playerX == 7)) && hasKey == 1)
                                            {
                                                map2[7][7] = DOOR_OPEN;
                                                printf("voce abriu a porta");
                                                usleep(500000);
                                            }
                                            else if (playerY == 7 && playerX == 7)
				                            {
				                                printf("Voce passou de nivel!\n");
				                                usleep(300000);
				                                int monsterX, monsterY;
				                                initializeMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY, &monsterX2, &monsterY2);
				                                
				                            	inicio2:
				                                playerY = 3;
				                                playerX = 3;
				                                newY = 3;
				                                newX = 3;
				                                
				                                while (1)
				                                {
				                                    moveMonster3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY);
				                                    
				                                    moveMonster4(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX2, &monsterY2, playerX, playerY);
				                                    
				                                    printMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, playerX, playerY, monsterX, monsterY, monsterX2, monsterY2);
				                                    char move;
				                                    printf("Movimente o jogador (W, A, S, D), Interaja com o jogo (I): ");
				                                    scanf(" %c", &move);
				                                    int newX = playerX, newY = playerY;
				                                    switch (move)
				                                    {
				                                        case 'w':
				                                        case 'W':
				                                            newY = playerY - 1;
				                                            break;
				                             
				                                        case 'a':
				                                        case 'A':
				                                            newX = playerX - 1;
				                                            break;
				                             
				                                        case 's':
				                                        case 'S':
				                                            newY = playerY + 1;
				                                            break;
				                             
				                                        case 'd':
				                                        case 'D':
				                                            newX = playerX + 1;
				                                            break;
				                                        case 'i':
				                                        case 'I':
				                        
				                                            if (playerY == 20 && playerX == 20)
				                                            {
				                                                hasKey = 1;
				                                                collectKey();
				                                            }
				                                            else if (playerY == 5 && playerX == 4)
				                                            {
				                                            	printf("voce se teleportou");
				                                            	usleep(500000);
				                                            	playerY = 19;
				                                            	playerX = 20;
				                                            	newY = 19;
				                                            	newX = 20;
				                                            	
															}
				                                            else if(playerY == 25 && playerX == 25)
				                                            {
				                                            	printf("voce apertou o butao, os espinhos sumiram");
				                                            	usleep(500000);
				                                                map3[31][30] = '.';
				                                                map3[30][29] = '.';
				                                                map3[30][31] = '.';
				                                                map3[29][30] = '.';
				                                            }
				                                            else if (((playerY == 28 || playerY == 30) && (playerX == 29 || playerX == 31)) || ((playerY == 29 || playerY == 31) && (playerX == 28 || playerX == 30)) && hasKey == 1)
				                                            {
				                                                map3[30][30] = DOOR_OPEN;
				                                                printf("voce abriu a porta");
				                                                usleep(500000);
				                                            }
				                                            else if (playerY == 30 && playerX == 30)
				                                            {
				                                            	printf("voce ganhou!!!!");
				                                            	exit(0);
															}
				                                    }
				                                    if (!checkCollision3(map3, MAP_HEIGHT3, MAP_WIDTH3, newX, newY))
				                                    {
				                                        if (map3[newY][newX] == SPIKE)
				                                        {
				                                            printf("\nvoce pisou no espinho");
				                                            usleep(200000);
				                                            playerX = 1;
				                                            playerY = 1;
				                                            lives--;
				                                            if (lives == 0)
				                                            {
				                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
				                                                exit(0);
				                                            }
				                                            else
				                                            {
				                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
				                                                usleep(500000);
				                                                playerX = 1;
				                                                playerY = 1;
				                                                initializeMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY, &monsterX2, &monsterY2);
				                                                goto inicio2;
				                                            }
				                                            initializeMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY, &monsterX2, &monsterY2);
				                                            goto inicio2;
				                                        }
				                                        else if (newX == monsterX && newY == monsterY || playerX == monsterX && playerY == monsterY)
				                                        {
				                                            printf("\nvoce foi pego pelo monstro");
				                                            usleep(300000);
				                                            lives--;
				                                            if (lives == 0)
				                                            {
				                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
				                                                exit(0);
				                                            }
				                                            else
				                                            {
				                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
				                                                usleep(500000);
				                                                playerX = 1;
				                                                playerY = 1;
				                                                initializeMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY, &monsterX2, & monsterY2);
				                                                goto inicio2;
				                                            }
				                                        }
				                                        else if (newX == monsterX2 && newY == monsterY2 || playerX == monsterX2 && playerY == monsterY2)
				                                        {
				                                            printf("\nvoce foi pego pelo monstro");
				                                            usleep(300000);
				                                            lives--;
				                                            if (lives == 0)
				                                            {
				                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
				                                                exit(0);
				                                            }
				                                            else
				                                            {
				                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
				                                                usleep(500000);
				                                                playerX = 1;
				                                                playerY = 1;
				                                                initializeMap3(map3, MAP_HEIGHT3, MAP_WIDTH3, &monsterX, &monsterY, &monsterX2, &monsterY2);
				                                                goto inicio2;
				                                            }
				                                        }
				                                        map3[playerY][playerX] = '.';
				                                        playerX = newX;
				                                        playerY = newY;
				                                        map3[playerY][playerX] = PLAYER;
				                                    }
				                                    
				                                    usleep(100000);
				                                }
				                            }
                                            
                                    }
                                    if (!checkCollision2(map2, MAP_HEIGHT2, MAP_WIDTH2, newX, newY))
                                    {
                                        if (map2[newY][newX] == SPIKE)
                                        {
                                            printf("\nvoce pisou no espinho");
                                            usleep(200000);
                                            playerX = 1;
                                            playerY = 1;
                                            lives--;
                                            if (lives == 0)
                                            {
                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
                                                exit(0);
                                            }
                                            else
                                            {
                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
                                                usleep(500000);
                                                playerX = 1;
                                                playerY = 1;
                                                initializeMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY, &monsterX2, &monsterY2);
                                                goto inicio;
                                            }
                                            initializeMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY, &monsterX2, &monsterY2);
                                            goto inicio;
                                        }
                                        else if (newX == monsterX && newY == monsterY || playerX == monsterX && playerY == monsterY)
                                        {
                                            printf("\nvoce foi pego pelo monstro");
                                            usleep(300000);
                                            lives--;
                                            if (lives == 0)
                                            {
                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
                                                exit(0);
                                            }
                                            else
                                            {
                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
                                                usleep(500000);
                                                playerX = 1;
                                                playerY = 1;
                                                initializeMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY, &monsterX2, & monsterY2);
                                                goto inicio;
                                            }
                                        }
                                        else if (newX == monsterX2 && newY == monsterY2 || playerX == monsterX2 && playerY == monsterY2)
                                        {
                                            printf("\nvoce foi pego pelo monstro");
                                            usleep(300000);
                                            lives--;
                                            if (lives == 0)
                                            {
                                                printf("\nvoce perdeu todas as vidas. Fim de jogo.");
                                                exit(0);
                                            }
                                            else
                                            {
                                                printf("\nvoce perdeu uma vida. Restam %d vidas.", lives);
                                                usleep(500000);
                                                playerX = 1;
                                                playerY = 1;
                                                initializeMap2(map2, MAP_HEIGHT2, MAP_WIDTH2, &monsterX, &monsterY, &monsterX2, &monsterY2);
                                                goto inicio;
                                            }
                                        }
                                        map2[playerY][playerX] = '.';
                                        playerX = newX;
                                        playerY = newY;
                                        map2[playerY][playerX] = PLAYER;
                                    }
                                    
                                    usleep(100000);
                                }
                            }
                
                        else
                        {
                            printf("voce nao esta em um interagivel");
                        }
                        usleep(500000);
                        break;
                        
                    }
                    
                    if (!checkCollision(map1, MAP_HEIGHT, MAP_WIDTH, newX, newY))
                    {
                        map1[playerY][playerX] = '.';
                        playerX = newX;
                        playerY = newY;
                        map1[playerY][playerX] = PLAYER;
                    }
                 
                    usleep(100000);
                 
                }
                 
                break;
                 
            case 2:
                system("cls");
                printf("Tutorial:\n\n");
                printf("voce tem tres vidas\n");
                printf("Use as teclas W, A, S, D para mover o jogador.\n");
                printf("* : parede\n");
                printf("@ : chave:\n");
                printf("D : porta fechada\n");
                printf("= : porta aberta\n");
                printf("# : espinho caso tocado o nivel reiniciara e perca uma vida\n");
                printf("> <: lados do teleportador\n");
                printf("x : inimigo nivel 1 caso tocado o nivel reiniciara e perdera uma vida\n");
                printf("v : inimigo nivel 2 caso tocado o nivel reiniciara e perdera uma vida\n");
                printf("Pressione 'I' para interagir com objetos.\n");
                printf("Objetivo: Pegar a chave e abrir a porta.\n");
                break;
             
            case 3:
                system("cls");
                printf("Obrigado por jogar!\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (choice != 3);

    return 0;    
}




