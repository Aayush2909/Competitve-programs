#include<bits/stdc++.h>

#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}

struct triplet{
    int val, apos, vpos;
    triplet(int v, int ap, int vp)
    {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct compare{
    bool operator()(triplet t1, triplet t2)
    {
        return t1.val > t2.val;
    }
};

int *mergeKArrays(int arr[][N], int k)
{
    //code here
    static int a[10000];
    
    priority_queue < triplet, vector <triplet>, compare> pq;
    
    for(int i=0; i<k; i++)
    {
        pq.push(triplet(arr[i][0], i, 0));
    }
    
    int index=0;
    while(!pq.empty())
    {
        triplet T = pq.top();
        pq.pop();
        a[index++] = T.val;
        
        if(T.vpos < k-1)
        {
            pq.push(triplet(arr[T.apos][T.vpos+1], T.apos, T.vpos+1));
        }
    }
    
    return a;
}
