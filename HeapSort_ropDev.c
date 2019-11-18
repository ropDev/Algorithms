/**
 * Heap Sort
 * author: Ronald Perez (ropDev)
 * date: 17-11-2019
 */

#include<stdio.h>
void display(int A[], int n);
void maxHeapify(int A[], int i, int n);
void buildMaxHeap(int A[], int n);
void heapSort(int A[], int n);

int main(){
    int A[] = {-1, 40,60,10,20,50,30};
    int n = sizeof(A)/sizeof(A[0]);
    display(A, n);
    heapSort(A, n);
    display(A, n);
}

void maxHeapify(int A[], int i, int n){
    int l=0, r=0, iActual=0, aux=0;
    iActual = i;
    l = (2 * i);
    r = (2 * i) + 1;
    if(l <= n && A[l] > A[i]) {
        iActual = l;
    }
    if(r <= n && A[r] > A[iActual]) {
        iActual = r;
    }
    if(iActual != i) {
        aux = A[i];
        A[i] = A[iActual];
        A[iActual] = aux;
        maxHeapify(A, iActual, n);
    }
}

void buildMaxHeap(int A[], int n){
    for(int i = (n / 2); i >= 1; i--){
        maxHeapify(A, i, n);
    }
}

void heapSort(int A[], int n){
    buildMaxHeap(A,n);
    int aux=0, tam=n-1;
    for (int i=tam;i>=2;i--){
        aux = A[i];
        A[i] = A[1];
        A[1] = aux;
        tam = tam-1;
        maxHeapify(A, 1, tam);
    }
}

void display(int A[], int n){
    for(int i = 1; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
