#include<stdio.h>
#include<string.h>

struct Courier {
    char Destination[100];
    int TrackingNum;
};

void BubbleSort(struct Courier A[], int N) {
    int Temp;
    char TempN[100];
    int i = 0, j = 0;
    
    while(i < N - 1) {
        j = 0;
        while(j < N - i - 1) {
            if(A[j].TrackingNum > A[j+1].TrackingNum) {
                Temp = A[j].TrackingNum;
                A[j].TrackingNum = A[j+1].TrackingNum;
                A[j+1].TrackingNum = Temp;
                strcpy(TempN, A[j].Destination);
                strcpy(A[j].Destination, A[j+1].Destination);
                strcpy(A[j+1].Destination, TempN);
            }
            j++;
        }
        i++;
    }
}

void Display(struct Courier A[], int N, int Choice) {
    int i = 0;
    if(Choice == 1) {
        printf("\nSorted By Tracking Number Low to High: \n");
        while(i < N) {
            printf("%s\t\t%d\n", A[i].Destination, A[i].TrackingNum);
            i++;
        }
    } else {
        printf("\nSorted By Tracking Number High to Low: \n");
        i = N - 1;
        while(i >= 0) {
            printf("%s\t\t%d\n", A[i].Destination, A[i].TrackingNum);
            i--;
        }
    }
}

int main() {
    int N = 0;
    int Choice = 0;
    int i = 0;

    printf("Enter Number of Courier Information Needed to Sort: ");
    scanf("%d", &N);
    getchar(); // to consume the newline character left by scanf

    struct Courier A[N];
    
    while(i < N) {
        printf("\nEnter Destination for Courier Information %d: ", i + 1);
        fgets(A[i].Destination, sizeof(A[i].Destination), stdin);
        A[i].Destination[strcspn(A[i].Destination, "\n")] = '\0'; 
        printf("Enter Tracking Number for Courier Information %d: ", i + 1);
        scanf("%d", &A[i].TrackingNum);
        getchar(); 
        i++;
    }

    do {
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
    InputChoice:
        scanf("%d", &Choice);

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

