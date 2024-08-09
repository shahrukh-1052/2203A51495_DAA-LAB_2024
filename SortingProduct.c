#include<stdio.h>
#include<string.h>

struct Product {
    int Price;
    char Name[100];
    int ProductCode;
};

void SelectionSort(struct Product A[], int N) {
    int largeQ, largeC, index, i, j;
    char LargeN[100];
    for (i = N - 1; i >= 1; i--) {
        largeQ = A[0].ProductCode;
        index = 0;
        largeC = A[0].Price;
        strcpy(LargeN, A[0].Name);
        for (j = 1; j <= i; j++) {
            if (largeQ < A[j].ProductCode) {
                largeQ = A[j].ProductCode;
                largeC = A[j].Price;
                strcpy(LargeN, A[j].Name);
                index = j;
            }
        }
        A[index].ProductCode = A[i].ProductCode;
        A[index].Price = A[i].Price;
        strcpy(A[index].Name, A[i].Name);
        A[i].ProductCode = largeQ;
        A[i].Price = largeC;
        strcpy(A[i].Name, LargeN);
    }
}

void Display(struct Product A[], int N, int Choice) {
    int i;
    if (Choice == 1) {
        printf("\nSorted By ProductCode Low to High: \n");
        for (i = 0; i < N; i++)
            printf("%d\t\t%s\t\t%d\n", A[i].Price, A[i].Name, A[i].ProductCode);
    } else {
        printf("\nSorted By ProductCode High to Low: \n");
        for (i = N - 1; i >= 0; i--)
            printf("%d\t\t%s\t\t%d\n", A[i].Price, A[i].Name, A[i].ProductCode);
    }
}

int main() {
    int N, Choice, i;
    printf("Enter Number of Products Information Needed to Sort: ");
    scanf("%d", &N);
    struct Product A[N];
    getchar(); 
    for (i = 0; i < N; i++) {
        printf("\nEnter product Information %d: \n", i + 1);
        printf("Product Id: ");
        scanf("%d", &A[i].ProductCode);
        getchar();  
        printf("Name: ");
        fgets(A[i].Name, 100, stdin);
        A[i].Name[strcspn(A[i].Name, "\n")] = '\0';  
        printf("Price: ");
        scanf("%d", &A[i].Price);
        getchar();  
    }

    do {
        printf("\nEnter Sorting Order:\nEnter 1 to Sort Low to High\nEnter 2 to Sort High To Low\nEnter 3 to Exit\n");
        printf("\nInput Your Choice: ");
    InputChoice:
        scanf("%d", &Choice);

        if (Choice == 1 || Choice == 2) {
            SelectionSort(A, N);
            Display(A, N, Choice);
        } else if (Choice == 3)
            printf("Exited Program, Thank You");
        else {
            printf("\nInvalid Input, Please Input Again!\n");
            goto InputChoice;
        }
    } while (Choice != 3);
    return 0;
}

