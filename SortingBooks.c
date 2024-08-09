#include <stdio.h>
#include <string.h>

#define MAX_DESTINATION_LENGTH 100

struct Package {
    char destination[MAX_DESTINATION_LENGTH];
    int time;
};

void swap(struct Package *a, struct Package *b) {
    struct Package temp = *a;
    *a = *b;
    *b = temp;
}

void sortByTime(struct Package arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].time > arr[j].time) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void display(struct Package arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Destination: %s, Time: %d minutes\n\n", arr[i].destination, arr[i].time);
    }
}

int main() {
    int N;
    int i;
    printf("Enter the number of packages: ");
    scanf("%d", &N);
    
    struct Package packages[N];
    
    for (i = 0; i < N; i++) {
        printf("Enter destination for package %d: ", i + 1);
        scanf("%s", packages[i].destination);
        printf("Enter delivery time for package %d (in minutes): ", i + 1);
        scanf("%d", &packages[i].time);
    }
    
    sortByTime(packages, N);
    display(packages, N);
    
    return 0;
}

