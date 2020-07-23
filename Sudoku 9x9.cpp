#include <bits/stdc++.h>
using namespace std;

#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}

bool isSafe(int grid[N][N], int mark, int i, int j)
{
    for(int k=0; k<N; k++)
    {
        if(grid[i][k] == mark || grid[k][j] == mark) return false;
        
    }
    
    int x = (i/3)*3;
    int y = (j/3)*3;
    
    for(int m= x; m<x+3; m++)
    {
        for(int n=y; n<y+3; n++)
        {
            if(grid[m][n] == mark) return false;
        }
    }
    
    return true;
}

bool solver(int grid[N][N], int i, int j)
{
    if(i==N) return true;
    if(grid[i][j] == 0)
    {
        for(int k=1; k<=9; k++)
        {
            if(isSafe(grid, k, i, j))
            {
                grid[i][j] = k;
                
                if(j==N-1)
                {
                    if(solver(grid, i+1, 0))
                       return true;
                }
                else
                {
                    if(solver(grid, i, j+1)) return true;
                    
                }
            }
       
        }
        grid[i][j] = 0;
        return false;
    }
    else
    {
        if(j==N-1)
        {
            if(solver(grid, i+1, 0)) return true;
        }
        else 
        {
            if(solver(grid, i, j+1)) return true;
        }
        
        return false;
    }
    
}

bool SolveSudoku(int grid[N][N])  
{ 
    
    return solver(grid, 0, 0);
    
}

void printGrid (int grid[N][N]) 
{
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
