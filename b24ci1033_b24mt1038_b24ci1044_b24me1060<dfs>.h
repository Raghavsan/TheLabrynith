#ifndef _dfs_
#define _dfs_


int isValid(char *maze, int r_i, int c_i, int rows, int columns);

void carvemaze_dfs(char *maze, int r_i, int c_i, int rows, int columns);


int isValid(char *maze, int r_i, int c_i, int rows, int columns){
    return (r_i<rows && r_i>=0 && c_i>=0 && c_i<columns && *(maze + r_i*columns + c_i)=='H');

}

void carvemaze_dfs(char *maze, int r_i, int c_i, int rows, int columns){
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    
    int i, j;
    for(i=0; i<4; i++){
        // srand((unsigned)time(NULL))
        j=rand()%4;
        int temp_r = dir[j][0];     //Shuffling the Directions 
        int temp_c = dir[j][1]; 
        dir[j][0] = dir[i][0];
        dir[j][1] = dir[i][1];
        dir[i][0] = temp_r;
        dir[i][1] = temp_c;
    }
    for(i=0; i<4; i++){                     
        int nr_i = r_i + dir[i][0]*2;
        int nc_i = c_i + dir[i][1]*2;

        if(isValid(maze, nr_i, nc_i, rows, columns)){
            *(maze + nr_i*columns + nc_i)=' ';
            *(maze + (r_i + dir[i][0])*columns + c_i + dir[i][1]) = ' ';
            showmaze(maze, rows, columns);
            carvemaze_dfs(maze, nr_i, nc_i, rows, columns);
        }

    }


}

#endif