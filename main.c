#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PrintMatrix(int **arr,int k){
	for(int i = 0;i<k;i++){
		printf("| ");
		for(int j = 0;j<k;j++){
			printf("%d ", arr[i][j]);
		}
		printf("|\n");
	}

}


void SortMatrix(int **arr,int k){
	int tempArr[k*3];
	int index = 0;
	for(int i = 0; i < k; i++){
		tempArr[index++] = arr[0][i];
	}
	for(int i = 1; i < k; i++){
		tempArr[index++] = arr[i][0];
	}
	for(int i = 0; i < k; i++){
		tempArr[index++] = arr[i][k-1];

	}
	for(int i = 0; i < 27; i++){
		for(int j = 0;j < 27 - i;j++){
			if(tempArr[j] > tempArr[j+1]){
				int tempTemp = tempArr[j];
				tempArr[j] = tempArr[j+1];
				tempArr[j+1] = tempTemp;
			}
		}
	}
	for(int i = 0; i < k; i++){
		arr[i][0] = tempArr[k-i];
	}
		// for(int i = 0; i < 27; i++){
		// 	printf("%d ", tempArr[i]);
		// }
	for(int i = 0; i < k + 9; i++){
		arr[0][i] = tempArr[9+i]; 
	}
	
	for(int i = 0; i < k; i++){
		arr[i][k-1] = tempArr[18+i];
	}
	printf("\n");

	PrintMatrix(arr,k);
}


void FillRandomMatrix(int **arr, int k){
	srand(time(NULL));
	for(int i = 0; i < k;i++){
		for(int j = 0; j < k;j++){
			arr[i][j] = rand() % 100;
		}
	}
}

void FillManualMatrix(int **arr,int k){
	printf("Input matrix elements:\n");
		for(int i = 0; i<k;i++){
			for(int j = 0;j<k;j++){
				printf("Element [%d] [%d]: ",i,j);
				scanf("%d", &arr[i][j]);
			}
			
		}
}

void FindMaxMinAndDiagonalCheck(int **arr, int k){
	int minNoSorted = 100;
	int maxNoSorted = 0;
	for(int i = 1; i < k-1; i++){
		for(int j = 1; j < k; j++){
			if(arr[i][j] > maxNoSorted){
				maxNoSorted = arr[i][j];
			}else if(arr[i][j] < minNoSorted){
				minNoSorted = arr[i][j];
			}
		}
	}


	printf("MAX: %d \n", maxNoSorted);
	printf("MIN: %d \n", minNoSorted);

	printf("Check Main Diag \n");
	for(int i = 0; i < k; i++){
		if(arr[i][i] == minNoSorted || arr[i][i] == maxNoSorted){
			printf("Main Diag Element & Cords: (%d, %d) %d \n ",i,i,arr[i][i]);
		}
	}
}


int main()
{
    srand(time(NULL));
    int variant = 5;
    int k = variant + 5;
    int **arr = (int**)malloc(k * sizeof(int *));
	for (int i = 0; i < k;i++){
		arr[i] = (int *)malloc(k * sizeof(int));
	}
	int inputmode;
	printf("Select input mode: 1 - hands , 2 - auto: ");
	scanf("%d", &inputmode);
	if (inputmode == 2){
		FillRandomMatrix(arr,k);
	}else{
		FillManualMatrix(arr,k);
	}
	PrintMatrix(arr,k);
	printf(" \n");
	SortMatrix(arr,k);
	FindMaxMinAndDiagonalCheck(arr,k);
	return 0;
}
