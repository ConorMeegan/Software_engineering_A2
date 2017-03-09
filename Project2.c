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
    int player_position[20][20];
    int all_positions[20][20];

}player;

struct slot
{
    char terrain[20];  // level ground, city, hill
    int slot_number;

}slot;

struct player players_array[100];
struct slot slots_array[100];

int main(void)
{
    srand(time(NULL));  //generating random every time

    int number_of_players;
    int number_of_slots = 0;
    int r, i;
    int counter;
    int random_number;

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
        printf("\nPlease enter player %d name:", i+1);
        scanf("%s", players_array[i].name);

        while(strcmp(players_array[i].type, "human")!=0 && strcmp(players_array[i].type, "ogre")!=0 && strcmp(players_array[i].type, "elf")!=0 && strcmp(players_array[i].type, "wizard")!=0)
        {
            printf("%s enter in your player type by typing in either: human, ogre, elf, wizard - ", players_array[i].name);
            scanf("%s", players_array[i].type);
        }
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
            printf("\n%s stats are as follows\n", players_array[i].name);
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
            players_array[i].life_points = 100;

            while(players_array[i].smartness + players_array[i].luck > 50)
            {
                players_array[i].smartness = ((rand() % (20)) + 1);
                players_array[i].luck = ((rand() % (50)) + 1);
            }

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
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
            players_array[i].life_points = 100;

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
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
            players_array[i].life_points = 100;

            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
    }

    while(number_of_slots < number_of_players || number_of_slots > 20)
    {
        printf("\nPlease enter in the number of slots you would like to have");
        scanf("%d", &number_of_slots);
    }

    for (counter = 0; counter < number_of_slots; counter++) {

        random_number = 1 + (rand()%3);



        if (random_number == 1) {

            strcpy(slots_array[counter].terrain, "Level Ground");

        }

        else if (random_number == 2) {

            strcpy(slots_array[counter].terrain, "Hill");

        }

        else if (random_number == 3) {

            strcpy(slots_array[counter].terrain, "City");

        }

    }

    for (counter = 0; counter < number_of_slots; counter++)
    {
        printf("%s \n", slots_array[counter].terrain);
    }

    int exit = 0;
    int player_position[20][20];
    int all_positions[20][20];

    while (exit == 0) {
        for (counter = 0; counter < number_of_players; counter++) {
            player_position[counter][1] = 1+(rand()%number_of_slots);
            all_positions[counter][1] = player_position[counter][1];
        }
        exit = 1;
        for (counter = 0; counter < number_of_players; counter++) {
            if (all_positions[counter][1] == all_positions[counter + 1][1]) {
                exit = 0;
            }
        }
    }
    for (counter = 0; counter < number_of_players; counter++) {
        printf("%s is in slot position %d\n", players_array[counter].name,  all_positions[counter][1]);
    }

    int counter_2;
    int adjacentslot_full, adjacentslot_full_2;


    for (counter = 0; counter < number_of_players; counter++) {
        printf("%s your position is %d.\n", players_array[counter].name, player_position[counter][1] );
        if(player_position[counter][1] == 1) {
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == 2) {
                    adjacentslot_full = 1;
                }
            }
            if(adjacentslot_full == 0) {
                printf("Would you like to move to the next slot or attack the closest player?\n");
            }
            if(adjacentslot_full == 1) {
                printf("There is a player in the next slot, would you like to attack?\n");
            }
        }
        else if(player_position[counter][1] == number_of_slots) {
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == number_of_slots - 1) {
                    adjacentslot_full = 1;
                }
            }
            if(adjacentslot_full == 0) {
                printf("Would you like to move to the previous slot or attack the closest player?\n");
            }
            if(adjacentslot_full == 1) {
                printf("There is a player in the previous slot, you are in the last slot, would you like to attack?\n");
            }
        }
        else {
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == player_position[counter][1] - 1) {
                    adjacentslot_full = 1;
                }
            }
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == player_position[counter][1] + 1) {
                    adjacentslot_full_2 = 1;
                }
            }
            if (adjacentslot_full == 1 && adjacentslot_full_2 == 0) {
                printf("There is a player in the previous slot would you like to attack or move to the next slot?\n");
            }
            else if (adjacentslot_full_2 == 1 && adjacentslot_full == 0) {
                printf("There is a player in the next slot would you like to attack or move to the previous slot?\n");
            }
            else if (adjacentslot_full == 1 && adjacentslot_full_2 == 1) {
                printf("There is a player in the next and previous slot would you like to attack?\n");
            }
            else {
                printf("Would you like to move to the next or previous slot or attack?\n");
            }

        }
        adjacentslot_full = 0;
        adjacentslot_full_2 = 0;
    }




    return 0;
}

void ability_modification()
{
    int i, counter;

    if(strcmp(slots_array[counter].terrain, "Level Ground")==0)
    {
        //return to game function
    }

    if(strcmp(slots_array[counter].terrain, "Hill")==0)
    {
        if(players_array[i].dexterity < 50)
        {
            players_array[i].strength = players_array[i].strength - 10;
            //return to game function
        }
        else if(players_array[i].dexterity >= 60)
        {
            players_array[i].strength = players_array[i].strength + 10;
            //return to game function
        }
        else if(players_array[i].dexterity <= 50 && players_array[i].dexterity < 60)
        {
            //return to game function
        }
    }

    if(strcmp(slots_array[counter].terrain, "City")==0)
    {
        if(players_array[i].smartness > 60)
        {
            players_array[i].magic_skills = players_array[i].magic_skills + 10;
            //returns to game function
        }
        else if(players_array[i].smartness <= 50)
        {
            players_array[i].dexterity = players_array[i].dexterity - 10;
            //returns to game function
        }
        else if(players_array[i].smartness > 50 && players_array[i].smartness <= 60)
        {
            //return to game function
        }
    }
}
