#include <bits/stdc++.h>
using namespace std;

  vector<pair<int,int> > v7094;

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            int x, y;
            x = i+1; y = j+1; 
            if(x!=y){ v7094.push_back({x,y}); }
            swap(arr[i], arr[j]); 
        } 
    } 

    int x, y;
    x = (i+1)+1; y = high+1; 
    if(x!=y){ v7094.push_back({x,y}); }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[300001];// = {10, 7, 8, 9, 1, 5}; 
    int n; // = sizeof(arr)/sizeof(arr[0]); 
    
    cin>>n;
    for(int i=0; i<n; i++){ cin>>arr[i];    }
    
    quickSort(arr, 0, n-1); 
    // printf("Sorted array: n"); 
    printArray(arr, n); 
    int m7094 = v7094.size();
    cout<<m7094<<"\n";
    for(int i=0; i<m7094; i++){
        cout<<v7094[i].first<<" "<<v7094[i].second<<"\n";
    }
    return 0; 
} 
