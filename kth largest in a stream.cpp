void kthLargest(int arr[], int n, int k)
{
	// your code here
	
	priority_queue <int, vector<int>, greater<int> > pq;
	
	int index = 0;
	for(int i=0; i<k-1; i++)
	{
	    cout<<"-1 ";
	    pq.push(arr[i]);
	}
	
	for(int i=k-1; i<n; i++)
	{
	    if(index!=0 and arr[index-1] > arr[i])
	    {
	        cout<<arr[index-1]<<" ";
	        arr[index] = arr[index-1];
	        arr[index-1] = arr[i];
	    }
	    else
	    {
	        pq.push(arr[i]);
	        arr[index] = pq.top();
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
      
      index++;
	}
	
}
