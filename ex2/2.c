/* C implementation QuickSort */
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{    int tmp;
    int pivot = median(arr,low,high);
      tmp=arr[high];
      arr[high]=arr[pivot];
      arr[pivot]=tmp;
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
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

/* Function to print ani array */

// Driver program to test above functions
void main()
{
        int a[100],n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        quickSort(a,0,n-1);
        for(i=0;i<n;i++)
        printf("%d",a[i]);
}
int median(int a[],int l,int u)
{      int m;
       int n=l-u+1;
        m=l+((n+1)/2)-1;
        int t=partition1(a,l,u);
        if(t<m)
            return median(a,t+1,u);
        else if(t>m)
            return median(a,l,t-1);
         else
              return m;
}

int partition1(int a[],int l,int u)
{
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

/* Function to print ani array */

// Driver program to test above functions
void main()
{
        int a[100],n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        quickSort(a,0,n-1);
        for(i=0;i<n;i++)
        printf("%d",a[i]);
}
int median(int a[],int l,int u)
{      int m;
       int n=l-u+1;
        m=l+((n+1)/2)-1;
        int t=partition1(a,l,u);
        if(t<m)
            return median(a,t+1,u);
        else if(t>m)
            return median(a,l,t-1);
         else
              return m;
}

int partition1(int a[],int l,int u)
{
 int pivot=a[u],i,tmp,j;
        for(i=l-1,j=l;j<u-1;j++)
        {
                if(a[j]<=pivot)
                {
                        i++;
                        tmp=a[i];
                        a[i]=a[j];
                        a[j]=tmp;
                }
        }
        tmp=a[i+1];
        a[i+1]=a[u];
        a[u]=tmp;
        return i+1;
}

