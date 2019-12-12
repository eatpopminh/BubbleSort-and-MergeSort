#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


void swappy(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void display(int array[], int size) 
{
    for(int i = 0 ; i<size ; i++)
    {
        cout<<array[i] <<" ";
    }
    cout<<endl;
}

void BubbleSort(int arr[], int size)
{
    for(int j = 0 ; j<size-1 ; j++)
    {
        for(int i = 0 ; i<size-j-1 ; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swappy(&arr[i],&arr[i+1]);
            }
        }
    }
}




// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r, int b[]) 
{ 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2];       //Make temp arrays

	for (int i = 0; i < n1; i++)    //Copy the left side into the temp array
		L[i] = arr[l + i]; 
	for (int j = 0; j < n2; j++)    //Copy the right side into the temp array
		R[j] = arr[m + 1+ j]; 

    //swapping element into the Array.
	int i = 0; 
	int j = 0;  
	int k = l;  
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

    //Copying the rest of temp array into Array.
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	//Copying the rest of the temp array into the Array.
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
void mergeSort(int arr[], int l, int r, int b[]) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2;      //m = middle
        
		mergeSort(arr, l, m, b);   //Splitting left side
		mergeSort(arr, m+1, r, b); //Splitting right side
        
		merge(arr, l, m, r, b);    //Merge and order together
	} 
} 


int main() 
{ 
    
	int arr[] = {38,27,43,3,9,82,10}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
    int b[arr_size];
    
    cout<<"MergeSort"<<endl;
    display(arr,arr_size);
	mergeSort(arr, 0, arr_size - 1 , b); 
    display(arr, arr_size);
    
    
    cout<<endl;
    
    
    int arr2[] = {38,27,43,3,9,82,10}; 
	int arr_size2 = sizeof(arr2)/sizeof(arr2[0]);
	
    cout<<"BubbleSort"<<endl;
    display(arr2, arr_size2);
    BubbleSort(arr2, arr_size2);
    display(arr2, arr_size2);
    

	return 0; 
} 









