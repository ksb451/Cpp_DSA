//integer Heap using array
#include<iostream>
using namespace std;
void swap(int &a, int &b);
void heapsort(int arr[], int n);
void printarray(const int arr[],const int n);
bool compare(const int &,const int &);//change this to switch b/w max and mean
void heapify(int arr[], int n,int i);
void heap(int arr[],int n);

int main()
{
    int n;
    cin>>n;
    cin.get();
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin.get();
    heap(arr,n);
    printarray(arr,n);
    heapsort(arr,n);
    printarray(arr,n);
}

//A simle function to swap the elements
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

//change this function to switch between max and mean heap
inline bool compare(const int &a, const int &b) 
{
    if(a<=b)//<= for mean hep and >= for max heap
    {
        return true;
    }
    return false;
}

//this function checks the properties of the heap from the gien node
void heapify(int arr[],int n,int i)
{
    int node=i;//node
    int l=i*2+1;//left child
    int r=i*2+2;//right child
    if(l<n && compare(arr[l],arr[node]))//if the left child is bigger or smaller based on the compare function
    {
        node=l;
    }
    if(r<n && compare(arr[r],arr[node]))//the biggest or smallest among the three based on compare function
    {
        node=r;
    }
    if(node!=i)//swapping the elementss and checking the porperties in the changed node
    {
        swap(arr[node],arr[i]);
        //recursively run the heapify operation on the swapped elements 
        heapify(arr,n,node);
    }
}
//to turn the array into a heap (max/min) based on the compare function
void heap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)//iterate through the leaves taht is the last haves element
    {
        heapify(arr,n,i);
    }
}

//to sort the given heap
void heapsort(int arr[],int n)
{
    for(int i=n-1; i>=0;i--)
    {
        swap(arr[0],arr[i]);//remove the top node by swapping it to the end and decresing the size of heap
        heapify(arr,i,0);//call heap properties from the new node
    }
}
//function to print the array
void printarray(const int arr[],const int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}