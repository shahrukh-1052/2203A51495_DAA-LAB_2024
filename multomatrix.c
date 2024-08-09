//%%writefile subomatrix.c

#include<stdio.h>
int main() 
{
    int m, n, p, i, j, k;
    printf("Enter the no. of rows : ");
    scanf("%d",&m);
    printf("Enter the no. of columns : ");
    scanf("%d",&n);
    printf("Enter the no. of columns of the second matrix: ");
    scanf("%d",&p);
    int a[m][n], b[n][p], product[m][p];
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<m;i++) 
	{
        for(j=0;j<n;j++) 
		{
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<n;i++) 
	{
        for(j=0;j<p;j++) 
		{
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<m;i++) 
	{
        for(j=0;j<p;j++) 
		{
            product[i][j] = 0;
        }
    }
    for(i=0;i<m;i++) 
	{
        for(j=0;j<p;j++) 
		{
            for(k=0;k<n;k++) 
			{
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Product of the matrices:\n");
    for(i=0;i<m;i++) 
	{
        for(j=0;j<p;j++) 
		{
            printf("%d\t",product[i][j]);
        }
        printf("\n");
    }
    return 0;
}

