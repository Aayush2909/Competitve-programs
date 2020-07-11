#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}


void helper(vector<int> A[], int N, int M, vector<bool> visited[], int i, int j)
{
    for(int a=i-1; a<=i+1; a++)
    {
        for(int b=j-1; b<=j+1; b++)
        {
            if(a<0 || b<0 || a>=N || b>=M || (a==i && b==j))
                continue;
            
            if(A[a][b] == 1 and visited[a][b] == false)
            {
                visited[a][b] = true;
                helper(A, N, M, visited, a, b);
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    vector<bool> visited[N];
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            visited[i].push_back(false);
            
    int count = 0;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(A[i][j] == 1 and visited[i][j] == false)
            {
                visited[i][j] = true;
                helper(A, N, M, visited, i, j);
                
                count++;
            }
        }
    }
    
    return count;
}
