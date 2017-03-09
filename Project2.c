//
// Created by Conor Meegan 25/02/2017
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct player
{
    char name[100];  //player's name
    char type[7];  //human, ogre, elf, wizard
    int dexterity;
    int smartness;
    int luck;
    int strength;
    int magic_skills;
    int life_points;

}player;

struct slot
{
    char terrain[6];  // ground, city, hill
    int slot_number;

}slot;

struct player players_array[100];
struct slot array[100];

int main(void)
{
    srand(time(NULL));  //generating random every time

    int number_of_players;
    int number_of_slots = 0;
    int r, i;

    printf("Welcome to the game Crossfire!\n");
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

    for(i=0; i<number_of_players; i++)
    {
        printf("\nPlease enter player %d name", i+1);
        scanf("%s", players_array[i].name);

        while(strcmp(players_array[i].type, "human")!=0 && strcmp(players_array[i].type, "ogre")!=0 && strcmp(players_array[i].type, "elf")!=0 && strcmp(players_array[i].type, "wizard")!=0)
        {
            printf("%s enter in your player type by typing in either: human, ogre, elf, wizard - ", players_array[i].name);
            scanf("%s", players_array[i].type);
        }
    }

    while(number_of_slots < number_of_players || number_of_slots > 20)
    {
        printf("\nPlease enter in the number of slots you would like to have");
        scanf("%d", &number_of_slots);
    }

    for(i=0; i<number_of_players; i++)
    {
        if(strcmp(players_array[i].type,"human") ==0)
        {
            players_array[i].dexterity = ((rand() % (100)) + 1);  //using ranged formula r = ((rand() % (max + 1 - min)) + min);
            players_array[i].smartness = ((rand() % (100)) + 1);
            players_array[i].luck = ((rand() % (100)) + 1);
            players_array[i].strength = ((rand() % (100)) + 1);
            players_array[i].magic_skills = ((rand() % (100)) + 1);
            players_array[i].life_points = 100;

            while(players_array[i].dexterity + players_array[i].smartness + players_array[i].luck + players_array[i].strength + players_array[i].magic_skills >= 300)
            {
                players_array[i].dexterity = ((rand() % (100)) + 1);  //using ranged formula r = ((rand() % (max + 1 - min)) + min);
                players_array[i].smartness = ((rand() % (100)) + 1);
                players_array[i].luck = ((rand() % (100)) + 1);
                players_array[i].strength = ((rand() % (100)) + 1);
                players_array[i].magic_skills = ((rand() % (100)) + 1);

            }

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"ogre") ==0)
        {
            players_array[i].magic_skills = 0;
            players_array[i].smartness = ((rand() % (20)) + 1);
            players_array[i].strength = ((rand() % (100+1-80)) + 80);
            players_array[i].dexterity = ((rand() % (100+1-80)) + 80);
            players_array[i].luck = ((rand() % (50)) + 1);
            while(players_array[i].smartness + players_array[i].luck > 50)
            {
                players_array[i].smartness = ((rand() % (20)) + 1);
                players_array[i].luck = ((rand() % (50)) + 1);
            }

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"elf") ==0)
        {
            players_array[i].luck = ((rand() % (100+1-60)) + 60);
            players_array[i].smartness = ((rand() % (100+1-70)) + 70);
            players_array[i].strength = ((rand() % (50)) + 1);
            players_array[i].magic_skills = ((rand() % (79+1-51)) + 51);
            players_array[i].dexterity = ((rand() % (100)) + 1);

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"wizard") ==0)
        {
            players_array[i].luck = ((rand() % (100+1-50)) + 50);
            players_array[i].smartness = ((rand() % (100+1-90)) + 90);
            players_array[i].strength = ((rand() % (20)) + 1);
            players_array[i].magic_skills = ((rand() % (100+1-80)) + 80);
            players_array[i].dexterity = ((rand() % (100)) + 1);

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
    }

    return 0;
}