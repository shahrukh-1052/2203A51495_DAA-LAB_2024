#include<stdio.h>
#include<string.h>

struct Product {
    int Product_Code;
    char Name[100];
    int Price;
};

void SelectionSort(struct Product A[], int N) {
    int largeQ, largeC, index;
    char LargeN[100];
    int i, j;

    for (i = N - 1; i >= 1; i--) {
        largeQ = A[0].Price;
        index = 0;
        largeC = A[0].Product_Code;
        strcpy(LargeN, A[0].Name);

        for (j = 1; j <= i; j++) {
            if (largeQ < A[j].Price) {
                largeQ = A[j].Price;
                largeC = A[j].Product_Code;
                strcpy(LargeN, A[j].Name);
                index = j;
            }
        }

        A[index].Price = A[i].Price;
        A[index].Product_Code = A[i].Product_Code;
        strcpy(A[index].Name, A[i].Name);

        A[i].Price = largeQ;
        A[i].Product_Code = largeC;
        strcpy(A[i].Name, LargeN);
    }
}

void Display(struct Product A[], int N, int Choice) {
    int i = 0;
    if (Choice == 1) {
        printf("\nSorted By Price Low to High: \n");
        while (i < N) {
            printf("%d\t\t%s\t\t%d\n", A[i].Product_Code, A[i].Name, A[i].Price);
            i++;
        }
    } else {
        printf("\nSorted By Price High to Low: \n");
        i = N - 1;
        while (i >= 0) {
            printf("%d\t\t%s\t\t%d\n", A[i].Product_Code, A[i].Name, A[i].Price);
            i--;
        }
    }
}

int main() {
    int N, Choice, i = 0;

    printf("Enter Number of Products Information Needed to Sort: ");
    scanf("%d", &N);
    getchar(); 

    struct Product A[N];

    while (i < N) {
        printf("\nEnter Product Code for Product %d: ", i + 1);
        scanf("%d", &A[i].Product_Code);
        getchar();
        printf("Enter Name for Product %d: ", i + 1);
        fgets(A[i].Name, sizeof(A[i].Name), stdin);
        A[i].Name[strcspn(A[i].Name, "\n")] = '\0'; 
        printf("Enter Price for Product %d: ", i + 1);
        scanf("%d", &A[i].Price);
        getchar(); 
        i++;
    }

    do {
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
    InputChoice:
        scanf("%d", &Choice);

        if (Choice == 1 || Choice == 2) {
            SelectionSort(A, N);
            Display(A, N, Choice);
        } else if (Choice == 3) {
            printf("Exited Program, Thank You");
        } else {
            printf("\nInvalid Input, Please Input Again !\n");
            goto InputChoice;
        }
    } while (Choice != 3);

    return 0;
}

