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
    int dexterity;  //player attributes
    int smartness;
    int luck;
    int strength;
    int magic_skills;
    int life_points;
    int position;

};

struct slot
{
    char terrain[20];  // Level Ground, City, Hill

};

void ability_modification(int counter);
void successful_attack(int counter_2);
void failed_attack(int counter, int counter_2);

struct player players_array[100];  //global variables for convenience
struct slot slots_array[100];

int main(void)
{
    srand(time(NULL));  //generating random every time

    //different variables used
    int number_of_players;
    int number_of_slots = 0;
    int i;
    int counter;
    int random_number;

    printf("Welcome to the game Crossfire!\n");
    printf("Please enter the number of players you would like to have (there is a max of 6 players): ");
    scanf("%d", &number_of_players);  //gets the number of players in the game from the user

    if(number_of_players > 6)  //implemented if there's an invalid number of players
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
        scanf("%s", players_array[i].name);  //gets the players to type in their name and then stores it in an array

        while(strcmp(players_array[i].type, "human")!=0 && strcmp(players_array[i].type, "ogre")!=0 && strcmp(players_array[i].type, "elf")!=0 && strcmp(players_array[i].type, "wizard")!=0)
        {
            printf("%s enter in your player type by typing in either: human, ogre, elf, wizard - ", players_array[i].name);
            scanf("%s", players_array[i].type);  //gets user to enter in their desired player type
        }
    }

    for(i=0; i<number_of_players; i++)
    {
        //assigning the attributes to each player
        if(strcmp(players_array[i].type,"human") ==0)  //implements if the player is a human
        {
            players_array[i].dexterity = ((rand() % (100)) + 1);  //using ranged formula r = ((rand() % (max + 1 - min)) + min)
            players_array[i].smartness = ((rand() % (100)) + 1);
            players_array[i].luck = ((rand() % (100)) + 1);
            players_array[i].strength = ((rand() % (100)) + 1);
            players_array[i].magic_skills = ((rand() % (100)) + 1);
            players_array[i].life_points = 100;

            //repeats if sum of all attributes is greater than or equal to 300 until valid attributes are generated
            while(players_array[i].dexterity + players_array[i].smartness + players_array[i].luck + players_array[i].strength + players_array[i].magic_skills >= 300)
            {
                players_array[i].dexterity = ((rand() % (100)) + 1);
                players_array[i].smartness = ((rand() % (100)) + 1);
                players_array[i].luck = ((rand() % (100)) + 1);
                players_array[i].strength = ((rand() % (100)) + 1);
                players_array[i].magic_skills = ((rand() % (100)) + 1);
            }

            //printing out the user's attributes for them to see
            printf("\n%s -- Player Type: %s", players_array[i].name, players_array[i].type);
            printf("\n%s stats are as follows\n", players_array[i].name);
            printf("\nLife Points: %d \n", players_array[i].life_points);
            printf("\nDexterity: %d", players_array[i].dexterity);
            printf("\nSmartness: %d", players_array[i].smartness);
            printf("\nLuck: %d",  players_array[i].luck);
            printf("\nStrength: %d", players_array[i].strength);
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"ogre") ==0)  //implements if the player is an ogre
        {
            players_array[i].magic_skills = 0;
            players_array[i].smartness = ((rand() % (20)) + 1);
            players_array[i].strength = ((rand() % (100+1-80)) + 80);
            players_array[i].dexterity = ((rand() % (100+1-80)) + 80);
            players_array[i].luck = ((rand() % (50)) + 1);
            players_array[i].life_points = 100;

            //repeats if sum of smartness and luck attributes are greater than 50 until valid attributes are generated
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
            printf("\nMagic Skills: %d \n", players_array[i].magic_skills);
        }
        if(strcmp(players_array[i].type,"elf") ==0)  //implements if the player is an elf
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
        if(strcmp(players_array[i].type,"wizard") ==0)  //implements if the player is a wizard
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
        printf("\nPlease enter in the number of slots you would like to have (max.20):");
        scanf("%d", &number_of_slots);
    }

    //this loop randomly assigns a type of slot to each slot depending on the random number generated
    for (counter = 0; counter < number_of_slots; counter++) {
        random_number = 1 + (rand()%3);
        //if random = 1 slot is level ground
        if (random_number == 1) {
            strcpy(slots_array[counter].terrain, "Level Ground");
        }
        //if random = 2 slot is hill
        else if (random_number == 2) {
            strcpy(slots_array[counter].terrain, "Hill");
        }
        //if random = 3 slot is city
        else if (random_number == 3) {
            strcpy(slots_array[counter].terrain, "City");
        }


    }

    for (counter = 0; counter < number_of_slots; counter++)
    {
        printf("Slot %d: %s \n", counter+1, slots_array[counter].terrain);
    }

    int exit = 0;
    int all_positions[20][20];
    int counter_2;

    //this loop randomly assigns each player to a slot
    while (exit == 0) {
        for (counter = 0; counter < number_of_players; counter++) {
            players_array[counter].position = 1+(rand()%number_of_slots);
            //the array all_positions holds the positions of all players and is just used
            //to analyse every players position later on when implementing movement and attacks
            //not necessarily needed but used to avoid any confusion
            all_positions[counter][1] = players_array[counter].position;
        }
        exit = 1;
        //this loop ensures no two players are in the same slot
        for (counter_2 = 0; counter_2 <= number_of_players; counter_2++) {
            for (counter = counter_2+1; counter <= number_of_players; counter++) {
                if (all_positions[counter][1] == all_positions[counter + 1][1]) {
                    exit = 0;
                }
            }
        }
    }

    for (counter = 0; counter < number_of_players; counter++) {
        printf("\n%s is in slot position %d\n", players_array[counter].name,  all_positions[counter][1]);
    }


    int adjacentslot_full = 0;
    int adjacentslot_full_2 = 0;
    char player_option[20];



    //this loop asks user if they want to attack or move and sends them to the corresponding function
    for (counter = 0; counter < number_of_players; counter++) {
        int lowest = number_of_slots+1;

        printf("\n%s your position is %d.\n", players_array[counter].name, players_array[counter].position);
        //must change users options if they are in the first slot
        if(players_array[counter].position == 1) {
            //this loop checks if there is a player in the second slot
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == 2) {
                    adjacentslot_full = 1;
                }
            }
            //if there is no player in the second slot player can move or attack
            if(adjacentslot_full == 0) {
                printf("Would you like to move to the next slot (next) or attack the closest player (attack)?");
                scanf("%s", player_option);
                if (strcmp(player_option, "next") == 0) {
                    players_array[counter].position++;
                    ability_modification(counter);
                }
                else if(strcmp(player_option, "attack") == 0) {
                    //this loop finds the closest player
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if (all_positions[counter_2][1] - players_array[counter].position < lowest) {
                            lowest = all_positions[counter_2][1];
                        }
                    }
                    //player with position lowest is closest player
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        //locates closest player so closest player can be analysed
                        if(players_array[counter_2].position == lowest) {
                            //attack will be successful if attacked player has strength <= 70
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");
                                successful_attack(counter_2);
                            }
                                //attack will be unsuccessful if attacked player has strength > 70
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");
                                failed_attack(counter, counter_2);
                            }
                        }
                    }
                }
                //if user enters an incorrect value
                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            }
            //if there is someone in the next slot user can only attack
            if(adjacentslot_full == 1) {
                //scans in attack from user even though it is their only option
                printf("There is a player in the next slot, enter attack to attack.");
                scanf("%s", player_option);

                if(strcmp(player_option, "attack") == 0) {
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        //locate player in the next slot
                        if(players_array[counter_2].position == players_array[counter].position + 1) {
                            //checks if an attack will be successful or not and calls corresponding function
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");
                                printf("%d\n", counter);
                                printf("%d\n", counter_2);
                                successful_attack(counter_2);
                            }
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");
                                printf("%d", counter);
                                printf("%d", counter_2);
                                failed_attack(counter, counter_2);
                            }
                        }
                    }


                }

                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            }
        }
        //this if statement deals with if the player is in the last slot
        else if(players_array[counter].position == number_of_slots) {
            //checks if there is a player in previous slot
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == number_of_slots - 1) {
                    adjacentslot_full = 1;
                }
            }
            //no one in previous slot
            if(adjacentslot_full == 0) {
                //give user option
                printf("Would you like to move to the previous slot (previous) or attack the closest player (attack)?");
                scanf("%s", player_option);
                //moves player back a space
                if (strcmp(player_option, "previous")==0) {
                    players_array[counter].position--;
                    ability_modification(counter);
                }
                //if player wants to attack
                else if(strcmp(player_option, "attack") == 0) {
                    //find closest player
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if (players_array[counter].position - all_positions[counter_2][1] < lowest) {
                            lowest = all_positions[counter_2][1];
                        }
                    }
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if(players_array[counter_2].position == lowest) {
                            //check if attack will be successful or not
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");

                                successful_attack(counter_2);
                            }
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");

                                failed_attack(counter, counter_2);
                            }
                        }
                    }

                }

                else {
                    printf("Please enter a valid option.");
                    counter--;
                }


            }
            //if someone is in previous slot
            if(adjacentslot_full == 1) {
                printf("There is a player in the previous slot, you are in the last slot, would you like to attack (attack)?");
                scanf("%s", player_option);
                //player wants to attack
                if(strcmp(player_option, "attack") == 0) {
                    //must find player in previous slot then view their strengths
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if(players_array[counter_2].position == players_array[counter].position - 1) {
                            //send program to correct function
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");

                                successful_attack(counter_2);
                            }
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");

                                failed_attack(counter, counter_2);
                            }
                        }
                    }
                }

                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            }
        }
        //if player is not in first or last slot
        else {
            //this for loop checks if there is someone in the slot behind
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == players_array[counter].position - 1) {
                    //represents previous slot
                    adjacentslot_full = 1;
                }
            }
            //this loop checks if there is someone in the next slot
            for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                if (all_positions[counter_2][1] == players_array[counter].position + 1) {
                    //represents next slot
                    adjacentslot_full_2 = 1;
                }
            }
            //if there is a player in previous slot but not next slot
            
            if (adjacentslot_full == 1 && adjacentslot_full_2 == 0) {
                printf("There is a player in the previous slot would you like to attack (attack) or move to the next slot (next)?");
                scanf("%s", player_option);
                //move player forward one slot
                if (strcmp(player_option, "next")==0) {
                    players_array[counter].position++;
                    ability_modification(counter);
                }
                //attack player behind


                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            } else if(strcmp(player_option, "attack") == 0) {
                //locate player in previous slot
                for (counter_2 = 0; counter_2 < number_of_players; counter_2++) {
                    if(players_array[counter_2].position == players_array[counter].position - 1) {
                        //view their stats and call necessary functions
                        if (players_array[counter_2].strength <= 70) {
                            printf("\nYou attacked\n");

                            successful_attack(counter_2);
                        }
                        else if (players_array[counter_2].strength > 70) {
                            printf("\nYou attacked\n");

                            failed_attack(counter, counter_2);
                        }
                    }
                }

            }
            //if there is a player in the next slot but not the previous slot
            else if (adjacentslot_full_2 == 1 && adjacentslot_full == 0) {
                printf("There is a player in the next slot would you like to attack (attack) or move to the previous slot (previous)?");
                scanf("%s", player_option);
                //move player back one slot
                if (strcmp(player_option, "previous") ==0) {
                    players_array[counter].position--;
                    ability_modification(counter);
                }
                //player wants to attack
                else if(strcmp(player_option, "attack") == 0) {
                    //find player in the next slot and view their stats
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if(players_array[counter_2].position == (players_array[counter].position) + 1) {
                            //call necessary functions
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");

                                successful_attack(counter_2);
                            }
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");

                                failed_attack(counter, counter_2);
                            }
                        }
                    }
                }

                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            }
            //if there is a player in the next and previous slot
            else if (adjacentslot_full == 1 && adjacentslot_full_2 == 1) {
                printf("There is a player in the next and previous slot enter attack to attack");
                scanf("%s", player_option);
                if(strcmp(player_option, "attack") == 0) {
                    printf("Would you like to attack the person in the next or previous slot? (next/previous)");
                    scanf("%s", player_option);
                    //attack player in next slot
                    if (strcmp(player_option, "next") == 0) {
                        //find player in next slot
                        for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                            if(players_array[counter_2].position == players_array[counter].position + 1) {
                                //call necessary functions depending on strength of attacked player
                                if (players_array[counter_2].strength <= 70) {
                                    printf("\nYou attacked\n");

                                    successful_attack(counter_2);
                                }
                                else if (players_array[counter_2].strength > 70) {
                                    printf("\nYou attacked\n");

                                    failed_attack(counter, counter_2);
                                }
                            }
                        }
                    }
                    //attack previous player
                    if (strcmp(player_option, "previous") == 0) {
                        //find previous player and view their stats
                        for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                            if(players_array[counter_2].position == players_array[counter].position - 1) {
                                //call necessary functions depending on strength of attacked player
                                if (players_array[counter_2].strength <= 70) {
                                    printf("\nYou attacked\n");
                                    successful_attack(counter_2);
                                }
                                else if (players_array[counter_2].strength > 70) {
                                    printf("\nYou attacked\n");
                                    failed_attack(counter, counter_2);
                                }
                            }
                        }
                    }
                }
            }
            //if there is no one in next or previous slot
            else {
                printf("Would you like to move to the next (next) or previous (previous) slot or attack the closest player (attack)?");
                scanf("%s", player_option);
                //move player forward one slot
                if (strcmp(player_option, "next") == 0) {
                    players_array[counter].position++;
                    ability_modification(counter);
                }
                //move player back one slot
                else if (strcmp(player_option, "previous") == 0) {
                    players_array[counter].position--;
                    ability_modification(counter);
                }
                //attack closest player
                else if(strcmp(player_option, "attack") == 0) {
                    //find closest player
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        //find closest player after player
                        if (players_array[counter].position < all_positions[counter_2][1]) {
                            if (all_positions[counter_2][1] - players_array[counter].position < lowest) {
                                lowest = all_positions[counter_2][1];
                            }
                        }
                        //find closest player before player
                        else if (players_array[counter].position > all_positions[counter_2][1]) {
                            if (players_array[counter].position - all_positions[counter_2][1] < lowest) {
                                lowest = all_positions[counter_2][1];
                            }
                        }
                    }
                    //attack closest player after they are found
                    for (counter_2 = 0; counter_2 < number_of_slots; counter_2++) {
                        if(players_array[counter_2].position == lowest) {
                            //call necessary functions
                            if (players_array[counter_2].strength <= 70) {
                                printf("\nYou attacked\n");
                                successful_attack(counter_2);
                            }
                            else if (players_array[counter_2].strength > 70) {
                                printf("\nYou attacked\n");
                                failed_attack(counter, counter_2);
                            }
                        }
                    }
                }

                else {
                    printf("Please enter a valid option.");
                    counter--;
                }
            }

        }
        adjacentslot_full = 0;
        adjacentslot_full_2 = 0;
        printf("\n%s stats are as follows\n", players_array[counter].name);
        printf("\nLife Points: %d \n", players_array[counter].life_points);
        printf("\nDexterity: %d", players_array[counter].dexterity);
        printf("\nSmartness: %d", players_array[counter].smartness);
        printf("\nLuck: %d",  players_array[counter].luck);
        printf("\nStrength: %d", players_array[counter].strength);
        printf("\nMagic Skills: %d \n", players_array[counter].magic_skills);
    }




    return 0;
}

void ability_modification(int counter)
{


    //checks what terrain the slot is and modifies the player's attributes based on what this and also the player's current attributes
    if(strcmp(slots_array[counter].terrain, "Level Ground")==0)  //strcmp evaluates to 0 if the terrain is Level Ground
    {
        //prints out the new stats if any of them hav changed based on the slot terrain
        printf("\n%s is now in a Level Ground slot\n", players_array[counter].name);


    }

    if(strcmp(slots_array[counter].terrain, "Hill")==0)
    {
        if(players_array[counter].dexterity < 50)
        {
            players_array[counter].strength = players_array[counter].strength - 10;

            printf("\n%s is now in a Hill slot\n", players_array[counter].name);


        }
        else if(players_array[counter].dexterity >= 60)
        {
            players_array[counter].strength = players_array[counter].strength + 10;

            printf("\n%s is now in a Hill slot\n", players_array[counter].name);

        }
        else if(players_array[counter].dexterity <= 50 && players_array[counter].dexterity < 60)
        {
            printf("\n%s is now in a Hill slot\n", players_array[counter].name);

        }
    }

    if(strcmp(slots_array[counter].terrain, "City")==0)
    {
        if(players_array[counter].smartness > 60)
        {
            players_array[counter].magic_skills = players_array[counter].magic_skills + 10;

            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
        else if(players_array[counter].smartness <= 50)
        {
            players_array[counter].dexterity = players_array[counter].dexterity - 10;

            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
        else if(players_array[counter].smartness > 50 && players_array[counter].smartness <= 60)
        {
            printf("\n%s is now in a City slot\n", players_array[counter].name);

        }
    }
}

void successful_attack(int counter_2)
{

    printf("%d", counter_2);
    players_array[counter_2].life_points = players_array[counter_2].life_points - (players_array[counter_2].strength / 2);

    printf("\n%s life points are now %d\n", players_array[counter_2].name, players_array[counter_2].life_points);

}

void failed_attack(int counter, int counter_2)
{

    printf("%d\n", counter);
    printf("%d\n", counter_2);
    players_array[counter].life_points = players_array[counter].life_points - (players_array[counter_2].strength * 0.3);

    printf("\n%s life points are now %d\n", players_array[counter_2].name, players_array[counter_2].life_points);

}


