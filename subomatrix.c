//%%writefile subomatrix.c

#include <stdio.h>
int main() 
{
    int m, n, i, j;
    printf("Enter the no. of rows : ");
    scanf("%d",&m);
    printf("Enter the no. columns : ");
    scanf("%d",&n);
    int a[m][n], b[m][n], difference[m][n];
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<m;i++) 
	{
        for(j=0;j<n;j++)
		 {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<m;i++) 
	{
        for(j=0;j<n;j++) 
		{
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<m;i++) 
	{
        for(j=0;j<n;j++) 
		{
            difference[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Difference of the matrices:\n");
    for(i=0;i<m;i++)
	 {
        for(j=0;j<n;j++) 
		{
            printf("%d\t",difference[i][j]);
        }
        printf("\n");
    }
    return 0;
}

