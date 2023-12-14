#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Universe{
public:

    int rows,cols;
bool grid [30][30];


    Universe(int r,int c){
        rows=r;
        cols=c;

    }

    void initialize(){


    for(int i=0;i<rows;i++){
     for(int j=0;j<cols;j++){
        grid[i][j]=false;


     }
    }
    int x,y,z;
    cout<< "enter number of live grid\n";
    cin >>x;
    for(int i=0;i<x;i++){
        cout<< "enter number of row and col";

        cin>>y>>z;

        grid[y][z]=true;
    }
      //grid[1][1]=true;
      //grid[2][2]=true;
      //grid[3][1]=true;
      //grid[3][2]=true;
      //grid[3][3]=true;


    }

void reset(){
//set all grid as dead

  for(int i=0;i<rows;i++){
     for(int j=0;j<cols;j++){
        grid[i][j]=false;


     }
    }

}

int count_neighbors(int r,int c){
int counter=0;
 for(int i=-1;i<=1;i++){
     for(int j=-1;j<=1;j++){
            if(i==0 && j==0) continue;
            int nr=r+i;
            int nc=c+j;

        if(nr<rows&&nr>=0&&nc<cols&&nc>=0&&grid[nr][nc]== true) {
            counter++;
        }


     }
    }
return counter;
}
 void next_generation(){
 bool new_grid  [rows][cols];
 for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        new_grid[i][j]=grid[i][j];
    }
 }
 for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        int num_of_neighbors=count_neighbors(i,j);
        if(grid[i][j]==true){
                if(num_of_neighbors<2||num_of_neighbors>3){             //underpopelution &overpopulotion
                    new_grid[i][j]=false;
                }
            else{
                if(num_of_neighbors == 3){
                    new_grid[i][j]=true;
                }
            }

        }
    }


 }
 for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        grid[i][j]=new_grid[i][j];
    }
 }


 }

 void display(){
 for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        if (grid[i][j]==true){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
 cout<<endl;
 }

 }



};



int main()
{
    Universe univers(30,30);
    univers.initialize();
for (int i = 0; i < 50; i++) {
        univers.display();
        univers.next_generation();
        this_thread::sleep_for(std::chrono::milliseconds(1000));

         system("cls");
    }




}
