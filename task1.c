#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int getSum(int arr[], int l, int r) {
    int s = 0, i;
    for (i = l; i <= r; i++) s += arr[i];
    return s;
}


int solve(int arr[], int l, int r, int c, int *bestL, int *bestR) {
    if (l > r) return 0;

    int mid = (l + r) / 2;

    int leftBestL = -1, leftBestR = -1;
    int rightBestL = -1, rightBestR = -1;

    int left = solve(arr, l, mid - 1, c, &leftBestL, &leftBestR);
    int right = solve(arr, mid + 1, r, c, &rightBestL, &rightBestR);

    
    int sum = 0, i, j;
    int leftSum = 0, rightSum = 0;

    int tempSum = 0;
    for (i = mid; i >= l; i--) {
        tempSum += arr[i];
        if (tempSum <= c && tempSum > leftSum) leftSum = tempSum;
    }

    tempSum = 0;
    for (j = mid + 1; j <= r; j++) {
        tempSum += arr[j];
        if (tempSum + leftSum <= c && tempSum > rightSum) rightSum = tempSum;
    }

    int cross = leftSum + rightSum;

    int best = 0;
    if (left > best) {
        best = left;
        *bestL = leftBestL;
        *bestR = leftBestR;
    }
    if (right > best) {
        best = right;
        *bestL = rightBestL;
        *bestR = rightBestR;
    }
    if (cross > best) {
        best = cross;
        *bestL = l;
        *bestR = r;
    }

    return best;
}

void maxSub(int arr[], int n, int c) {
    if (n == 0 || c <= 0) {
        printf("No subarray\n");
        return;
    }
    int l = -1, r = -1;
    int res = solve(arr, 0, n - 1, c, &l, &r);

    if (res == 0) {
        printf("No subarray\n");
        return;
    }

    printf("Best sum: %d\n", res);
}

int main() {
    int a1[] = {2,1,3,4};
    maxSub(a1, 4, 5);

    int a2[] = {2,2,2,2};
    maxSub(a2, 4, 4);

    int a3[] = {1,5,2,3};
    maxSub(a3, 4, 5);

    int a4[] = {6,7,8};
    maxSub(a4, 3, 5);

    int a5[] = {1,2,3,2,1};
    maxSub(a5, 5, 5);

    int a6[] = {1,1,1,1,1};
    maxSub(a6, 5, 4);

    int a7[] = {4,2,3,1};
    maxSub(a7, 4, 5);

    int a8[] = {};
    maxSub(a8, 0, 10);

    int a9[] = {1,2,3};
    maxSub(a9, 3, 0);

    return 0;
}
