/* Blaise Cannon & Guadalupe Delgado
 * Conway's Game of Life
 * 29 November 2015
 *
 * The Game of Life is an autonomous game that does not require any human interaction except for the initial
 * grid sequence. The game can continue forever or it may end in one turn depending on the initial conditions.
 *
 * =========
 * Resources
 * =========
 *
 * 1. http://www.dreamincode.net/forums/topic/382784-global-array-becoming-null-after-appending-elements/
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>

using namespace std;

static const int MAX_HEIGHT = 80; // height of the grid
static const int MAX_WIDTH = 40; // width of the grid
char INIT_GRID[MAX_HEIGHT][MAX_WIDTH];
char NEW_GRID[MAX_HEIGHT][MAX_WIDTH]; // store the updates in a new grid so that no overwrite can occur before all cells change state

void fillGrid(void) {

    FILE *data = fopen("initial_config.txt", "r"); // opens data file

    if (data == NULL) {
        fprintf(stderr, "File cannot be read.");
        exit(EXIT_FAILURE);
    }

    else {
        char line[64];
        int count = 0;
        int i;

        while (fgets(line, sizeof line, data) != NULL) {
            for (i = 0; i < MAX_WIDTH; i++) {
                INIT_GRID[count][i] = line[i];
                printf("%c", INIT_GRID[count][i]);
                count++;
            }
            printf("\n");
        }

        if (count < MAX_HEIGHT) // not enough lines were passed
        {
            exit(EXIT_FAILURE);
        }
    }
    fclose(data); // close file
}

int main(void) {

    char height;
    char width;
    int round = 0;

    fillGrid();


    return 0;
}
