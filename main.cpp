/* Blaise Cannon & Guadalupe Delgado
 * Conway's Game of Life
 * 29 November 2015
 *
 * The Game of Life is an autonomous game that does not require any human interaction except for the initial
 * grid sequence. The game can continue forever or it may end in one turn depending on the initial conditions.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>
//#include "mpi.h"

using namespace std;

static const int MAX_HEIGHT = 80; // height of the grid
static const int MAX_WIDTH = 40; // width of the grid
static const int GRID_BOTTOM = (MAX_HEIGHT - 1);

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
            }
            count++;
            printf("\n");
        }

        if (count < MAX_HEIGHT) // not enough lines were passed from the file
        {
            exit(EXIT_FAILURE);
        }
    }
    fclose(data); // close file
}

int main(void) {
    int round = 1;
    char celltl, celltm, celltr;
    char cellml, cell, cellmr;
    char cellbl, cellbm, cellbr;

    fillGrid();
    while (round <= 5) {
        printf("The game is now on round: %d\n", round);
        for (int j = 0; j < MAX_HEIGHT; ++j) {

            // top of grid: needs to wrap around to bottom of grid
            if (j == 0) {
                for (int k = 0; k < MAX_WIDTH; ++k) {

                }
            }

                // bottom of grid: needs to wrap around to top of grid
            else if (j == GRID_BOTTOM) {
                for (int k = 0; k < MAX_WIDTH; ++k) {

                }
            }

            else {
                for (int k = 0; k < MAX_WIDTH; ++k) {
                    // cell being changed
                    cell = INIT_GRID[j][k];

                    // neighbors above
                    celltl = INIT_GRID[j - 1][k - 1];
                    celltm = INIT_GRID[j - 1][k];
                    celltr = INIT_GRID[j - 1][k + 1];

                    // neighbors on same row
                    cellml = INIT_GRID[j][k - 1];
                    cellmr = INIT_GRID[j][k + 1];

                    // neighbors below
                    cellbl = INIT_GRID[j + 1][k - 1];
                    cellbm = INIT_GRID[j + 1][k];
                    cellbr = INIT_GRID[j + 1][k + 1];
                }
            }

            for (int k = 0; k < MAX_WIDTH; ++k) {

                if (j > 0 && k < MAX_HEIGHT) {

                }

                if (j == 0) {
                    cell = INIT_GRID[j][k];

                    // neighbors above
                    celltl = INIT_GRID[j - 1][k - 1];
                    celltm = INIT_GRID[j - 1][k];
                    celltr = INIT_GRID[j - 1][k + 1];

                    // neighbors on same row
                    cellml = INIT_GRID[j][k - 1];
                    cellmr = INIT_GRID[j][k + 1];

                    // neighbors below
                    cellbl = INIT_GRID[j + 1][k - 1];
                    cellbm = INIT_GRID[j + 1][k];
                    cellbr = INIT_GRID[j + 1][k + 1];
                }
            }
        }
        round++;
    }

    return 0;
}
