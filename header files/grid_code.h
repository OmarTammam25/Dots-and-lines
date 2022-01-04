//#include <stdio.h>
//#include <Windows.h>
//#include "colors.h"

#define dot 254
#define ver 124
#define hor 196

void flatten(int n ,int m,int arr[n][m],int flat_data[]){
    /*
    function to get the data structure as 2d array of intergers and
    turn it to 1d array of the characters (| , __ ,' ')
    each caracter mathced with the grid to display
    
    the parameters:
        n-> the number of rows of the data structure array
        m -> the number of colomns of the data structure array
        arr -> the data structure array
        flat_data -> the new formed flat data array
    */
    // note the size of the flaten array can be obtained from (2*m*n-m-n + (n-1)*(m-1))--> number of dots
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) flat_data[counter++]=' ';//check if the element is zero turn it to space

            // check if the element is 1 and the row number is even turn it to horizontal line
            else if(arr[i][j]==1&&i%2==0) flat_data[counter++] =  hor ;
            else if(arr[i][j]==-1&&i%2==0) flat_data[counter++]= -hor ;   
            // check if the element is 1 and the row number is odd turn it to vertical line
            else if(arr[i][j]==1&&i%2==1) flat_data[counter++] =  ver ;
            else if(arr[i][j]==-1&&i%2==1) flat_data[counter++]= -ver ;
            else if(i%2 == 1 && arr[i][j] == 3) flat_data[counter++] = 3;
            else if(i%2 == 1 && arr[i][j] == -3) flat_data[counter++] = -3;
            else if(i%2 == 1 && arr[i][j] == 2) flat_data[counter++] = 2;
        }
    }
}


// n and m here are number of dots (num_row & num_col)
void change_grid(int n,int m ,int data[],WORD cr1,WORD cr2,WORD cr1_bg, WORD cr2_bg){
    /* fuction to apply the move of the user 
        and display the new grid 
    */
    int c=0; // counter for the data structure
    int c_count=1;
    int r_count=1;
    setColor(7);
    for(int i=0;i<n;i++){
        if(i==0){
                for(int z=0;z<m;z++){
                    z==0?printf("\t\t\t\t\t\t\t  %d    ",c_count++):printf("%d    ",c_count++);
                }
                printf("\n");
            }
        for(int j=0;j<m;j++){
            j==0?printf("\t\t\t\t\t\t\t%d %c",r_count++,dot):printf("%c",dot);
            if(j!=m-1){
                if(data[c]<0){
                    setColorL(cr1);
                    printf("%c%c%c%c",data[c++]*-1,data[c]*-1,data[c]*-1,data[c]*-1); //print horizontal line if exist in the data structure with color -1
                    setColor(7);
                }
                else{ 
                    setColorL(cr2);
                    printf("%c%c%c%c",data[c++],data[c],data[c],data[c]); //print horizontal line if exist in the data structure with color 1
                    setColor(7);
                }
            }
        }
        printf("\n");
        if(i!=n-1){ // for not printing vertical lines after the last row of dots
            for(int j=0;j<m;j++){
                if(j==0)printf("\t\t\t\t\t\t\t  ");
                if(data[c]<0){
                    setColorL(cr1);

                    printf("%c",data[c++]*-1); // printing vertical line if exist in the data structure with color -1
                    setColor(7);
                }
                else {
                    setColorL(cr2);
                    printf("%c",data[c++]*1); // printing vertical line if exist in the data structure with color 1
                    setColor(7);
                }
                // for printing space between vert lines
                //TODO  if a square then it prints a colored space :)
                if(data[c] == 3 && j!=m-1){
                    setColorL(cr2_bg);
                    printf("    ");
                    setColor(7);
                    c++;
                }else if(data[c] == -3 && j!=m-1){
                    setColorL(cr1_bg);
                    printf("    ");
                    setColor(7);
                    c++;                    
                } else if(data[c] == 2 && j!=m-1){
                    printf("    ");
                    c++;
                }    
            }
        }
        printf("\n");
    }
}


/* 
 int main(){
// the data must be in one dimension form of size (2*m*n - m - n)
//and having one value of the 3 (' ' , hor , ver)

//example:

    
int data[5][5] ={{2,0,2,0,2},
                 {0,2,0,2,0},
                 {2,0,2,0,2},
                 {0,2,0,2,0},
                 {2,0,2,0,2}};
    int flat_data[16];//number of lines

    flatten(5,5,data,flat_data); //size of data structure

    for (int i = 0; i < 40 ; i++)
    {
        printf("%c,",flat_data[i]);
    } 
 
    printf("\n");
    
    //int data[49]={' ',hor,hor,hor,hor,ver,ver,ver,ver,ver,ver,
    //               hor,-hor,hor,hor,hor,-ver,' ',ver,-ver,ver,ver,
    //               hor,hor,hor,hor,hor,ver,ver,ver,-ver,ver,ver,
    //               hor,' ',hor,hor,-hor,' ',ver,ver,ver,ver,ver,
    //               hor,hor,hor,hor,hor};
    //int is_square = 1;                
    //change_grid(5,5,flat_data,FOREGROUND_RED,FOREGROUND_BLUE,BACKGROUND_RED,BACKGROUND_BLUE, is_square);//number of dots
    //system("pause");
    return 0;
    
} */