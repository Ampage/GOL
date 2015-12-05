/* (Bitwise)~(~(Guadalupe Delgado) & Blaise Cannon
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
static const int MAX_HEIGHT = 80; // height of the grid
static const int MAX_WIDTH = 40; // width of the grid
static const int GRID_BOTTOM = (MAX_HEIGHT - 1);
static const int GRID_WALL = (MAX_WIDTH - 1);
char INIT_GRID[MAX_HEIGHT][MAX_WIDTH];
char NEW_GRID[MAX_HEIGHT][MAX_WIDTH];

using namespace std;

void fillGrid(void) {

    FILE *data = fopen("initial_config.txt", "r"); // opens data file

    if (data == NULL) {
        fprintf(stderr, "File cannot be read.");
        exit(EXIT_FAILURE);
    }

    else {
        char line[64];
        int count = 0;

        while (fgets(line, sizeof line, data) != NULL) {
            for (int i = 0; i < MAX_WIDTH; i++) {
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
                    // left wall needs to wrap right
                    if (k == 0) {

                    }

                        // right wall needs to wrap left
                    else if (k == GRID_WALL) {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[GRID_BOTTOM][k - 1];
                        celltm = INIT_GRID[GRID_BOTTOM][k];
                        celltr = INIT_GRID[GRID_BOTTOM][0];

                        // neighbors on same row
                        cellml = INIT_GRID[j][k - 1];
                        cellmr = INIT_GRID[j][0];

                        // neighbors below
                        cellbl = INIT_GRID[j + 1][k - 1];
                        cellbm = INIT_GRID[j + 1][k];
                        cellbr = INIT_GRID[j + 1][0];
                    }

                    else {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[GRID_BOTTOM][k - 1];
                        celltm = INIT_GRID[GRID_BOTTOM][k];
                        celltr = INIT_GRID[GRID_BOTTOM][k + 1];

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

                // bottom of grid: needs to wrap around to top of grid
            else if (j == GRID_BOTTOM) {
                for (int k = 0; k < MAX_WIDTH; ++k) {
                    // left wall needs to wrap right
                    if (k == 0) {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[0][GRID_WALL];
                        celltm = INIT_GRID[0][k];
                        celltr = INIT_GRID[0][k + 1];

                        // neighbors on same row
                        cellml = INIT_GRID[j][GRID_WALL];
                        cellmr = INIT_GRID[j][k + 1];

                        // neighbors below
                        cellbl = INIT_GRID[j + 1][GRID_WALL];
                        cellbm = INIT_GRID[j + 1][k];
                        cellbr = INIT_GRID[j + 1][k + 1];
                    }

                        // right wall needs to wrap left
                    else if (k == GRID_WALL) {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[0][0];
                        celltm = INIT_GRID[0][k];
                        celltr = INIT_GRID[0][k + 1];

                        // neighbors on same row
                        cellml = INIT_GRID[j][0];
                        cellmr = INIT_GRID[j][k + 1];

                        // neighbors below
                        cellbl = INIT_GRID[j + 1][k - 1];
                        cellbm = INIT_GRID[j + 1][k];
                        cellbr = INIT_GRID[j + 1][k + 1];
                    }

                    else {
                        // cell being changed
                        cell = INIT_GRID[0][k];

                        // neighbors above
                        celltl = INIT_GRID[0][k - 1];
                        celltm = INIT_GRID[0][k];
                        celltr = INIT_GRID[0][k + 1];

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

            else {
                for (int k = 0; k < MAX_WIDTH; ++k) {

                    // left wall needs to wrap right
                    if (k == 0) {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[j - 1][GRID_WALL];
                        celltm = INIT_GRID[j - 1][k];
                        celltr = INIT_GRID[j - 1][k + 1];

                        // neighbors on same row
                        cellml = INIT_GRID[j][GRID_WALL];
                        cellmr = INIT_GRID[j][k + 1];

                        // neighbors below
                        cellbl = INIT_GRID[j + 1][GRID_WALL];
                        cellbm = INIT_GRID[j + 1][k];
                        cellbr = INIT_GRID[j + 1][k + 1];
                    }

                        // right wall needs to wrap left
                    else if (k == GRID_WALL) {
                        // cell being changed
                        cell = INIT_GRID[j][k];

                        // neighbors above
                        celltl = INIT_GRID[j - 1][0];
                        celltm = INIT_GRID[j - 1][k];
                        celltr = INIT_GRID[j - 1][k + 1];

                        // neighbors on same row
                        cellml = INIT_GRID[j][0];
                        cellmr = INIT_GRID[j][k + 1];

                        // neighbors below
                        cellbl = INIT_GRID[j + 1][0];
                        cellbm = INIT_GRID[j + 1][k];
                        cellbr = INIT_GRID[j + 1][k + 1];
                    }

                    else {
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
            }
        }
        round++;
    }

    return 0;
}
