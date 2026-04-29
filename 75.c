#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;
    int hash[MAX];
    
    for (int i = 0; i < MAX; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            max_len = i + 1;
        }

        int key = sum + MAX / 2;

        if (hash[key] != -1) {
            int length = i - hash[key];
            if (length > max_len)
                max_len = length;
        } else {
            hash[key] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d", maxLen(arr, n));

    return 0;
}