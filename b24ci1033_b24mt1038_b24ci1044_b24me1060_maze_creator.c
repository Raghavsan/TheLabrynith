#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_RESET "\033[0m"
#define COLOR_START "\033[35m"
#define COLOR_BORDER "\033[36m"

void showmaze(char *maze, int rows, int colmns);

void init_maze(char *maze, int rows, int columns);

void save_maze(char *maze, int rows, int columns, char* algoname, double time_taken, int index);

void put_squarepatch(char *maze, int rows, int columns);

#include "b24ci1033_b24mt1038_b24ci1044_b24me1060<dfs>.h"

    //Function to initilize the Maze with all Walls
void init_maze(char *maze, int rows, int columns){
    int i,j;
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            *(maze + i*columns + j)='H';
        }
    }
}


    //Function to show the maze
void showmaze(char *maze, int rows, int columns){
   printf("%s*", COLOR_BORDER); // Set border color
    for(int i = 0; i < columns; i++) {
        printf("-");
    }
    printf("*%s\n", COLOR_RESET); // Reset color after border

    for(int i = 0; i < rows; i++) {
        printf("%s|", COLOR_BORDER); // Set border color
        for(int j = 0; j < columns; j++) {
            if (*(maze + i * columns + j) == 'S') {
                printf("%s%c%s", COLOR_START, *(maze + i * columns + j), COLOR_RESET); // Change color of 'S'
            } else {
                printf("%s%c", COLOR_BORDER,*(maze + i * columns + j));
            }
        }
        printf("|%s\n", COLOR_RESET); // Reset color after row
    }

    printf("%s*", COLOR_BORDER); // Set border color
    for(int i = 0; i < columns; i++) {
        printf("-");
    }
    printf("*%s", COLOR_RESET); // Reset color after border
}

    //Function to save the maze
void save_maze(char *maze, int rows, int columns, char* algoname, double time_taken, int index){
    FILE *fp = fopen("b24ci1033_b24mt1038_b24ci1044_b24me1060<maze_text>.txt", "a");
    fprintf(fp, "\n\n---Index %d---\n\n", index);
    
    fputc('*', fp);
    for(int i=0; i<columns; i++){
        fputc('-', fp);
    }
    fputs("*\n", fp);
    
    for(int i=0; i<rows; i++){
        fputc('|', fp);
        for(int j=0; j<columns; j++){
            fputc(*(maze + i*columns + j), fp);
        }
        fputs("|\n", fp);
    }
    fputc('*', fp);
    for(int i=0; i<columns; i++){
        fputc('-', fp);
    }
    fputs("*\n", fp);

    fprintf(fp, "\nThe time taken by the %s algorithm is %f seconds\n", algoname, time_taken / CLOCKS_PER_SEC);

    fclose(fp);
}

void put_squarepatch(char *maze, int rows, int columns){
    int i, j;
    for(i = (rows-1)/2 -10; i<=(rows-1)/2 +10; i++){
        for(j = (columns-1)/2 -20; j<=(columns-1)/2 +20; j++){
            *(maze + i*columns +j) = ' ';
        }
    }

    for(i = (rows-1)/2 -10; i<=(rows-1)/2 +10; i++){
        for(j = (columns-1)/2 -20; j<=(columns-1)/2 +20; j++){
            
            if(j==(columns-1)/2 -20||j==(columns-1)/2 +20 || i==(rows-1)/2 -10 || i==(rows-1)/2 +10)
                if(i!=(rows-1)/2 -10 || j!=(columns-1)/2)
                *(maze + i*columns +j) = 'W';
        }
    }



}

int main(){
    int key = 1;
    int rows, columns;
    int starting_r_i = 0, starting_c_i = 0; 
    int finishing_r_i, finishing_c_i;
    int character_iterations;
    int choice;
    int index=0;
    int database_deletion;
    clock_t start;
    clock_t end;

       
        printf("\n\nDo you want to empty out the maze Database?\n");
        printf("1.YES\n");
        printf("2.NO\n");

        printf("\nEnter option number: ");
        scanf("%d", &database_deletion);

        if(database_deletion ==1){
            FILE *fptr_del = fopen("b24ci1033_b24mt1038_b24ci1044_b24me1060<maze_text>.txt", "w");
            fprintf(fptr_del, "\n");
            fclose(fptr_del);
        }
         //Starting File Storage:
        FILE *fstart = fopen("b24ci1033_b24mt1038_b24ci1044_b24me1060<maze_text>.txt", "a");
        fprintf(fstart, "\n\n*--------------------The Mazes for this Run of the code are printed below--------------------*\n\n");
        fclose(fstart);

    while(key){
        
        printf("Enter the dimensions of the maze:\n");
        scanf("%d", &columns);
        scanf("%d", &rows);
        // char mazegrid[rows][columns];   //This step is to remove the warnings generated while running the code for
        // char *maze = &mazegrid[0][0];   //passing a 2D array in function which takes argument of a (char *) pointer. 

        char *maze = (char *)malloc(rows*columns*sizeof(char));
        
        printf("\nEnter the Coordinates of the Starting Point:\n");
        scanf("%d", &starting_c_i);
        scanf("%d", &starting_r_i);
        starting_c_i--;
        starting_r_i--;
        if(index<2){
            printf("\nSelect the Number of the choice for Maze generation Algorithm:\n");
            printf("1. Depth First Search (DFS)\n");

            printf("\nEnter your choice (Enter \"0\" in case, not wanting to select any algorithm): \n");
            scanf("%d", &choice);
        }
        else if(index>=2){
            printf("\nSelect the Number of the choice for Maze generation Algorithm:\n");
            printf("1. Depth First Search (DFS)\n");

            printf("*--You may enter the number of planets in the Solar System to see something interesting--*");
            printf("\nEnter your choice (Enter \"0\" in case, not wanting to select any algorithm): \n");
            scanf("%d", &choice);
        }


        

        if(choice == 0){
            printf("\nAlgorithm not Selected\n");
        }

        else if(choice==1){
            index++;
            clock_t start = clock();
            init_maze(maze, rows, columns);
            carvemaze_dfs(maze, starting_r_i, starting_c_i, rows, columns);
            clock_t end = clock();
            *(maze + starting_r_i*columns + starting_c_i) = 'S';
            showmaze(maze, rows, columns);
            printf("\nThe time taken by the DFS algorithm is %f seconds.\n\n",(double)(end-start) / CLOCKS_PER_SEC );

            printf("\n*---------Maze Generation Successfull----------*\n");
            save_maze(maze, rows, columns, "DFS" , (end-start), index);
        }

        else if(choice==9){
            index++;
            clock_t start = clock();
            init_maze(maze, rows, columns);
            carvemaze_dfs(maze, starting_r_i, starting_c_i, rows, columns);
            put_squarepatch(maze, rows, columns);
            //Writing 'Maze Runner' in the middle of the square patch
            *(maze + ((rows-1)/2)*columns + (columns-1)/2-5) = 'M';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2-4) = 'A';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2-3) = 'Z';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2-2) = 'E';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2-1) = ' ';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2  ) = 'R';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2+1) = 'U';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2+2) = 'N';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2+3) = 'N';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2+4) = 'E';
            *(maze + ((rows-1)/2)*columns + (columns-1)/2+5) = 'R';
            clock_t end = clock();
            
            showmaze(maze, rows, columns);
            printf("\nThe time taken by the DFS algorithm is %f seconds.\n\n",(double)(end-start) / CLOCKS_PER_SEC );

            printf("\n*---------Maze Generation Successfull----------*\n");
            save_maze(maze, rows, columns, "DFS" , (end-start), index);



        }

        
        
            
       
        free(maze);
        choice = 0;

        printf("\nEnter \"0\" if you want to exit, or Enter \"1\"to create another maze.\n");
        scanf("%d", &key);

        if(key==0){
            printf("*---------Maze Generation exited----------*");
        }
       
        printf("\n\nDo you want to empty out the maze Database?\n");
        printf("1.YES\n");
        printf("2.NO\n");

        printf("\nEnter option number: ");
        scanf("%d", &database_deletion);

        if(database_deletion ==1){
            FILE *fptr_del = fopen("b24ci1033_b24mt1038_b24ci1044_b24me1060<maze_text>.txt", "w");
            fprintf(fptr_del, "\n");
            fclose(fptr_del);
        }    
    }
 
}




