2D ARRAYS 

QUE 1 - (Row and column sums)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        return 1;
    }

    if (r == 0 || c == 0) {
        printf("\n\n");
        return 0;
    }

    // Use calloc to zero-initialize column sums; long long prevents overflow
    long long *col_sums = calloc((size_t)c, sizeof(long long));
    if (col_sums == NULL) {
        return 1;
    }

    // Stream the matrix: compute and print row sums on the fly, accumulate column sums
    for (int i = 0; i < r; i++) {
        long long row_sum = 0;
        for (int j = 0; j < c; j++) {
            long long val;
            if (scanf("%lld", &val) != 1) {
                free(col_sums);
                return 1;
            }
            row_sum += val;
            col_sums[j] += val;
        }
        printf("%lld%c", row_sum, (i == r - 1) ? '\n' : ' ');
    }

    // Print column sums on the second line
    for (int j = 0; j < c; j++) {
        printf("%lld%c", col_sums[j], (j == c - 1) ? '\n' : ' ');
    }

    free(col_sums);
    return 0;
}

QUE 2 - (Check matrix symmetry)

#include<stdio.h>
int main(){
    int n,i,j,flag=1;
    scanf("%d",&n);
    int a[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=a[j][i]){
                flag=0;
                break;
            }
        }
    }

    if(flag==1)
        printf("YES");
    else
        printf("NO");

    return 0;
}


QUE 3 - (Find a saddle point)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("None\n");
        return 0;
    }

    long long *a = malloc((size_t)r * c * sizeof(long long));
    if (!a) return 1;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lld", &a[i * c + j]);

    for (int i = 0; i < r; i++) {
        long long rowMin = a[i * c];
        for (int j = 1; j < c; j++)
            if (a[i * c + j] < rowMin) rowMin = a[i * c + j];

        for (int j = 0; j < c; j++) {
            if (a[i * c + j] != rowMin) continue;

            int isMax = 1;
            for (int k = 0; k < r; k++) {
                if (a[k * c + j] > rowMin) { isMax = 0; break; }
            }

            if (isMax) {
                printf("%d %d %lld\n", i, j, rowMin);
                free(a);
                return 0;
            }
        }
    }

    printf("None\n");
    free(a);
    return 0;
}

QUE 4 - (Count local peaks)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("0\n");
        return 0;
    }

    long long *a = malloc((size_t)r * c * sizeof(long long));
    if (!a) return 1;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lld", &a[i * c + j]);

    int count = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int isPeak = 1;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;  // ignore missing neighbours
                if (a[i * c + j] <= a[ni * c + nj]) {
                    isPeak = 0;
                    break;
                }
            }
            if (isPeak) count++;
        }
    }

    printf("%d\n", count);
    free(a);
    return 0;
}