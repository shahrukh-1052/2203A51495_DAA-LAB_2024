#include<stdio.h>
#include<string.h>

struct Package {
    char Destination[100];
    int EstTime;
};

void BubbleSort(struct Package A[], int N) {
    int Temp, i, j;
    char TempN[100];
    i = 0;
    while(i < N - 1) {
        j = 0;
        while(j < N - i - 1) {
            if(A[j].EstTime > A[j+1].EstTime) {
                Temp = A[j].EstTime;
                A[j].EstTime = A[j+1].EstTime;
                A[j+1].EstTime = Temp;
                strcpy(TempN, A[j].Destination);
                strcpy(A[j].Destination, A[j+1].Destination);
                strcpy(A[j+1].Destination, TempN);
            }
            j++;
        }
        i++;
    }
}

void Display(struct Package A[], int N, int Choice) {
    int i = 0;
    if(Choice == 1) {
        printf("\nSorted By Estimated Time Low to High: \n");
        while(i < N) {
            printf("%s\t\t%d\n", A[i].Destination, A[i].EstTime);
            i++;
        }
    } else {
        printf("\nSorted By Estimated Time High to Low: \n");
        i = N - 1;
        while(i >= 0) {
            printf("%s\t\t%d\n", A[i].Destination, A[i].EstTime);
            i--;
        }
    }
}

int main() {
    int N, Choice, i = 0;
    printf("Enter Number of Package Information Needed to Sort: ");
    scanf("%d", &N);
    struct Package A[N];
    getchar(); 

    while(i < N) {
        printf("\nEnter Destination for Package %d: ", i + 1);
        fgets(A[i].Destination, sizeof(A[i].Destination), stdin);
        A[i].Destination[strcspn(A[i].Destination, "\n")] = '\0'; 

        printf("Enter Estimated Time for Package %d: ", i + 1);
        scanf("%d", &A[i].EstTime);
        getchar(); 
        i++;
    }

    do {
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
        InputChoice: scanf("%d", &Choice);

        if(Choice == 1 || Choice == 2) {
            BubbleSort(A, N);
            Display(A, N, Choice);
        } else if(Choice == 3)
            printf("Exited Program, Thank You");
        else {
            printf("\nInvalid Input, Please Input Again !\n");
            goto InputChoice;
        }
    } while(Choice != 3);

    return 0;
}

