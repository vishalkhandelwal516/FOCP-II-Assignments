#include<stdio.h>
#include<stdlib.h>

int cmp_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

const char* solve(int n, int* arr) {
    qsort(arr, n, sizeof(int), cmp_desc);

    long long alexTotal = 0, bobTotal = 0;
    int turn = 0;
    int lastAlex = -1, lastBob = -1;

    for (int i = 0; i < n; i++) {
        int val = arr[i];
        if (turn == 0) {
            if (val == lastAlex) continue;
            alexTotal += val;
            lastAlex = val;
            turn = 1;
        } else {
            if (val == lastBob) continue;
            bobTotal += val;
            lastBob = val;
            turn = 0;
        }
    }

    if (alexTotal > bobTotal) return "Alex";
    else if (bobTotal > alexTotal) return "Bob";
    else return "Draw";
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++) {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        const char* out_ = solve(n, arr);
        printf("%s\n", out_);

        free(arr);
    }
    return 0;
}
