# Software_engineering_A2
Assignment2 work


//
// Created by Conor Meegan 25/02/2017
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct player
{
    char name[100];  //player's name
    char type[7];  //human, ogre, elf, wizard
    int dexterity[100];
    int smartness[100];
    int luck[100];
    int strength[100];
    int magic_skills[100];
    int life_points[100];

}player;

typedef struct slot
{
    char terrain[6];  // ground, city, hill
    int number;
    int following;  //following slot
}slot;

void player_selection();
void ability_modification();
void human(player a[]);
void ogre(player a[]);
void elf(player a[]);
void wizard(player a[]);

int main(void)
{
    srand(time(NULL));  //generating random every time
    printf("Welcome to the game Crossfire!\n");
    player_selection();

    return 0;
}

void player_selection()
{
    int number_of_players;
    int r, i, j;
    int sum;
    int counter[5];

    printf("Please enter the number of players you would like to have (there is a max of 6 players): ");
    scanf("%d", &number_of_players);

   if(number_of_players > 6)
   {
       while(number_of_players > 6)
       {
           printf("Enter a valid number of players you would like to have (max 6): ");
           scanf("%d \n", &number_of_players);
       }
   }


    player.life_points[i] = 100;

    for(i=0; i<number_of_players; i++)
    {
        if(player.type == human)
        {
            human(players);
        }
        if(player.type == ogre)
        {
            ogre(players);
        }
        if(player.type == elf)
        {
            elf(players);
        }
        if(player.type == wizard)
        {
            wizard(players);
        }
    }

    ability_modification();
}


void human(player a[])
{
    int r, i, j;
    int result;
    int sum = 0;
    int counter[5];
    r = ((rand() % (100)) + 1);

    while(1)
    {
        for(i=0; i<5; i++)
        {
            r = ((rand() % (100)) + 1);  //using ranged formula r = ((rand() % (max + 1 - min)) + min)
            counter[i] = r;
        }
        player.dexterity[i] = counter[0];
        player.smartness[i] = counter[1];
        player.luck[i] = counter[2];
        player.strength[i] = counter[3];
        player.magic_skills[i] = counter[4];
        sum = player.dexterity[i]+player.smartness[i]+player.luck[i]+player.strength[i]+player.magic_skills[i];
        if(sum >= 300)
        {
            result = human(players);
        }
        else
        {
            break;
        }
    }
}

void ogre(player a[])
{
    int i,j,r;
    int sum = 0;
    int result;

    while(1)
    {
        player.magic_skills[i] = 0;
        player.smartness[i] = ((rand() % (20)) + 1);
        player.strength[i] = ((rand() % (100+1-80)) + 80);
        player.dexterity[i] = ((rand() % (100+1-80)) + 80);
        player.luck[i] = ((rand() % (50)) + 1);
        sum = player.smartness[i] + player.luck[i];
        if(sum >50)
        {
            result = ogre(players);
        }
        else
        {
            break;
        }
    }
}

void elf(player a[])
{
    int i;

    player.luck[i] = ((rand() % (100+1-60)) + 60);
    player.smartness[i] = ((rand() % (100+1-70)) + 70);
    player.strength[i] = ((rand() % (50)) + 1);
    player.magic_skills[i] = ((rand() % (79+1-51)) + 51);
    player.dexterity[i] = ((rand() % (100)) + 1);
}

void wizard(player a[])
{
    int i;

    player.luck[i] = ((rand() % (100+1-50)) + 50);
    player.smartness[i] = ((rand() % (100+1-90)) + 90);
    player.strength[i] = ((rand() % (20)) + 1);
    player.magic_skills[i] = ((rand() % (100+1-80)) + 80);
    player.dexterity[i] = ((rand() % (100)) + 1);
}


void ability_modification()
{
    int i;

    if(slot.terrain == ground)
    {
        //return to game function
    }
    
    if(slot.terrain == hill)
    {
        if(player.dexterity[i] < 50)
        {
            player.strength[i] = player.strength[i-10];
            //return to game function
        }
        else if(player.dexterity[i] >= 60)
        {
            player.strength[i] = player.strength[i+10];
            //return to game function
        }
        else if(player.dexterity[i] <= 50 && player.dexterity[i] < 60)
        {
            //return to game function
        }
    }

    if(slot.terrain == city)
    {
        if(player.smartness[i] > 60)
        {
            player.magic_skills[i] = player.magic_skills[i+10];
            //returns to game function
        }
        else if(player.smartness[i] <= 50)
        {
            player.dexterity[i] = player.dexterity[i-10];
            //returns to game function
        }
        else if(player.smartness[i] > 50 && player.smartness[i] <= 60)
        {
            //return to game function
        }
    }
}
