#include <stdio.h>
#include <stdlib.h>

void makeheap (int[], int);
void heapsort (int[], int);

void main()
{
    int arr[10] = {15, 5, 9, 13, 57, 25, 17, 1, 90, 3}, i;
    printf("Original Array\n");
    for(i=0; i<10; i++)
        printf("%4d", arr[i]);
    printf("\n");
    makeheap(arr, 10);
    printf ("\n\nHeap Tree Before Sorting:\n");
    for (i=0; i<10; i++){
        if(i==0){
            printf("%21d\n", arr[i]);
        }
        if(i<=2 && i!=0){
            printf("%11d%s", arr[i], i == 2 ? "\n" : "         ");
        }
        if(i<=6 && i>=3){
            printf("%6d%s", arr[i], i == 6 ? "\n" : "    ");
        }
        if(i<=14 && i>=7){
            printf("%3d%s", arr[i], i == 14 ? "\n" : "  ");
        }
    }
    heapsort(arr, 10);
    printf("\n\nAfter Sorting:\n");
    for (i=0; i<10; i++)
        printf("%4d", arr[i]);
    printf("\n");
}

void makeheap(int x[], int n)
{
    int i, val, s, f;
    for(i=1; i<n; i++)
    {
        val = x[i];
        s = i;
        f = (s-1)/2;
        while(s>0 && x[f]<val)
        {
            x[s] = x[f];
            s = f;
            f =(s-1)/2;
        }
        x[s] = val;
    }
}

void heapsort(int x[], int n)
{
    int i, s, f, ivalue;
    for(i=n-1; i>0; i--)
    {
        ivalue = x[i];
        x[i] = x[0];
        f = 0;
        if(i == 1)
            s = -1;
        else
            s = 1;
        if (i > 2 && x[2] > x[1])
            s = 2;
        while(s>=0 && ivalue<x[s])
        {
            x[f] = x[s];
            f = s;
            s = (2 * f) + 1;
            if(s+1 <= i-1 && x[s] < x[s+1])
                s++;
            if(s > i-1)
                s = -1;
        }
        x[f] = ivalue;
    }
}
