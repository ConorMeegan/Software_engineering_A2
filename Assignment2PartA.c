#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define MAX 30

struct elves {
    char elves_array[MAX][MAX];
};
struct wizards {
    char wizards_array[MAX][MAX];
};
struct humans {
    char humans_array[MAX][MAX];
};
struct ogres {
    char ogres_array[MAX][MAX];
};
struct players {
    players_array[MAX][MAX];
};

void record_players(char player_name[30], char player_type[30], int numberof_players,int elfcounter,int humancounter, int ogrecounter, int wizardcounter);

int main()
{
    struct elves elves1;
    struct wizards wizards1;
    struct humans humans1;
    struct ogres ogres1;
    struct players players1;
    int counter = 0, counter_2 = 0, counter_3 = 0, numberof_slots = 0, numberof_players = 0, exit = 0, random_number = 0;
    int elfcounter = 0, wizardcounter = 0, humancounter = 0, ogrecounter = 0;
    int all_positions[MAX][MAX], adjacentslot_full = 0;
    int elf_position[MAX][MAX], wizard_position[MAX][MAX], human_position[MAX][MAX], ogre_position[MAX][MAX];
    char player_name[30], player_type[30];
    srand(time(NULL));

    record_players(player_name, player_type, numberof_players,elfcounter,humancounter, ogrecounter, wizardcounter);
    /*for (counter = 0; counter < elfcounter; counter++) {
        printf("%s", elves1.elves_array[counter]);
    }*/

    printf("\n\nPlease enter the number of required slots (Max is twenty): ");
        scanf("%d", &numberof_slots);
    char  slots_array[numberof_slots][20];

    for (counter = 0; counter < numberof_slots; counter++) {
        random_number = 1 + (rand()%3);

    if (random_number == 1) {
        strcpy(slots_array[counter], "Level Ground");
    }
    else if (random_number == 2) {
        strcpy(slots_array[counter], "Hill");
    }
    else if (random_number == 3) {
        strcpy(slots_array[counter], "City");
    }

    }

    /*for (counter = 0; counter < numberof_slots; counter++) {
        printf("%s\n", slots_array[counter]);
    }*/
    //assigning positions
    while (exit == 0) {
            for (counter = 0; counter < elfcounter; counter++) {
                elf_position[counter][1] = 1 + (rand()%numberof_slots);
                all_positions[counter_2][1] = elf_position[counter][1];
                counter_2++;
            }
            for (counter = 0; counter < wizardcounter; counter++) {
                wizard_position[counter][1] = 1 + (rand()%numberof_slots);
                all_positions[counter_2][1] = wizard_position[counter][1];
                counter_2++;
            }
            for (counter = 0; counter < humancounter; counter++) {
                human_position[counter][1] = 1 + (rand()%numberof_slots);
                all_positions[counter_2][1] = human_position[counter][1];
                counter_2++;
            }
            for (counter = 0; counter < ogrecounter; counter++) {
                ogre_position[counter][1] = 1 + (rand()%numberof_slots);
                all_positions[counter_2][1] = ogre_position[counter][1];
                counter_2++;
            }
            exit = 1;
            for (counter = 0; counter < numberof_players; counter++) {
                if (all_positions[counter][1] == all_positions[counter + 1][1]) {
                    exit = 0;
                }
            }
    }
    /*for (counter = 0; counter < numberof_players; counter++) {
        printf("%d\n", all_positions[counter][1]);
    }*/
    exit = 0;
    //asking each player if they want to move
    while (exit == 0) {
            for (counter = 0; counter < elfcounter; counter++) {
                printf("Elf: %s your position is %d.\n", elves1.elves_array[counter], elf_position[counter][1] );
                    if(elf_position[counter][1] == 1) {
                        for (counter_2 = 0; counter_2 < numberof_slots; counter_2) {
                            if (all_positions[counter_2][1] == 2) {
                                adjacentslot_full = 1;
                            }
                        }
                        if(adjacentslot_full == 0) {
                            printf("Would you like to move to the next slot or attack the closest player?");
                        }
                        if(adjacentslot_full == 1) {
                            printf("There is a player in the next slot, would you like to attack?");
                        }
                    }
                    else if(elf_position[counter][1] == numberof_slots) {
                        for (counter_2 = 0; counter_2 < numberof_slots; counter_2) {
                            if (all_positions[counter_2][1] == numberof_slots - 1) {
                                adjacentslot_full = 1;
                            }
                        }
                        if(adjacentslot_full == 0) {
                            printf("Would you like to move to the previous slot or attack the closest player?");
                        }
                        if(adjacentslot_full == 1) {
                            printf("There is a player in the previous slot, you are in the last slot, would you like to attack?");
                        }
                    }
                    else {
                        printf("Would you like to move to the next/previous slot or attack the closest player?");
                    }
            }
    }
    return 0;
}

void record_players(char player_name[30], char player_type[30], int numberof_players,int elfcounter,int humancounter, int ogrecounter, int wizardcounter) {

    struct elves elves1;
    struct wizards wizards1;
    struct humans humans1;
    struct ogres ogres1;
    struct players players1;
    int counter = 0;

    printf("Enter finished as player type when all players are entered\n");

    while (counter <= 6) {
        if (counter == 6) {
            printf("\nThe max number of players is 6.\nAll players recorded.\n");
        }
        else {
            printf("%d. Player type: ", counter + 1);
                fgets(player_type, 30, stdin);
                    if (strstr(player_type, "finished") != 0) {
                                printf("All players recorded.");
                                numberof_players = counter;
                                counter = 8;
                    }
                    else {
                        printf("Player name: ");
                            fgets(player_name, 30, stdin);
                                if (strstr(player_type, "Elf") != 0) {
                                    strcpy( elves1.elves_array[elfcounter], player_name );
                                    elfcounter++;
                                }
                                else if (strstr(player_type, "Wizard") != 0) {
                                    strcpy( wizards1.wizards_array[wizardcounter], player_name );
                                    wizardcounter++;
                                }
                                else if (strstr(player_type, "Human") != 0) {
                                    strcpy( humans1.humans_array[humancounter], player_name );
                                    humancounter++;
                                }
                                else if (strstr(player_type, "Ogre") != 0) {
                                    strcpy( ogres1.ogres_array[ogrecounter], player_name );
                                    ogrecounter++;
                                }
                            else {
                                printf("Incorrect player type entered please try again.\n");
                                counter--;
                            }
                    }

        }

        counter++;

    }
}
