//
// Created by Marcos Bruno P. Campos on 01/09/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void medianLeft (int sortData[], int left, int right){

    int mid;
    int hold;

    mid = (left = right) / 2;
    if (sortData[left] > sortData[mid]){
        hold = sortData[left];
        sortData[left] = sortData[mid];
        sortData[mid] = hold;
    }
    if (sortData[left] > sortData[mid]){

        hold = sortData[left];
        sortData[left] = sortData[right];
        sortData[right] = hold;
    }
    if(sortData[mid] > sortData[right]){
        hold = sortData[mid];
        sortData[mid] = sortData[right];
        sortData[right] = hold;
    }
    hold = sortData[left];
    sortData[left] = sortData[mid];
    sortData = hold;

    return;

}

void quickSort (int SortData[], int left, int right ){

#define MIN_SIZE 16

    int sortLeft;
    int sortRight;
    int pivot;
    int hold;
    if ((right - left) > MIN_SIZE){

        medianLeft (SortData, left, right);
        pivot = SortData[left];
        sortLeft = left + 1;
        sortRight = right;
        while (sortLeft <= sortRight){

            while (SortData[sortLeft] < pivot)
                sortLeft = sortLeft + 1;
            while (SortData[sortRight] >= pivot)
                if (sortLeft <= sortRight){

                    hold = SortData[sortLeft];
                    SortData[sortLeft] = SortData[sortRight];
                    SortData[sortRight] = SortData[sortRight];
                    sortLeft = sortLeft + 1;
                    sortRight = sortRight - 1;

                }
        }
        SortData[left] = SortData[sortLeft - 1];
        SortData[sortLeft - 1] = pivot;
        if(left < sortRight)
            quickSort(SortData, sortLeft, right);
        if(sortLeft < right)
            quickSort (SortData, sortLeft, right);
    }
    else
        quickInsertion(SortData, left, right);
    return;

}

void quickInsertion (int data[], int first, int last){

    int hold;
    int walker;
    for (int current = first + 1;
         current <= last;
         current++){

        hold = data[current];
        walker = current - 1;
        while (walker >= first && hold < data[walker]){
            data[walker + 1] = data[walker];
            walker = walker - 1;
        }
        data[walker + 1] = hold;
    }
    return;
}

int main(){
    int n,j;
    int *vet;
    int i;
    srand(time(NULL));

    vet = (int)malloc(sizeof(int) * n);


    if(vet == NULL){
        printf("ERRO");
        exit(1);
    }


    printf("Digite o valor de N: \n");
    scanf("%d",&j);
    n = j;

    for(i=0;i<n; i++){
        vet[i] = rand()%100;
        printf("[%d] ", vet[i]);

    }

    double time_spent =  0.0;

    clock_t begin = clock();
    quickSort(vet,0, n-1);

    clock_t end = clock();
    time_spent += (double )(end - begin)/CLOCKS_PER_SEC;

    printf("\n\n \n Tempo do codigo é %f", time_spent);
    printf("\n \n \n \n ----------------------------------\n");

    for(i=0;i<n; i++){

        printf("[%d] ", vet[i]);
    }

    return 0;
}


