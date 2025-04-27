#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * (n + 2));
    for (int i = 1; i <= n; i++) scanf("%d", arr + i);
    arr[0] = arr[n];
    arr[n + 1] = arr[1];

    int p, q, d;
    p = 1;
    q = n;

    for (int i = 1; i <= n; i++) {
        d = abs(arr[i - 1] - arr[i]);
        if (d == 1 || d == n - 1) continue;

        if ((n + arr[i] - arr[i + 1]) % n == 1) p = i;   //1~n
        if ((n + arr[i + 1] - arr[i]) % n == 1) q = i - 1; //0~n-1
    }

    // printf("p:%d q:%d\n",p,q);
    printf("%d\n%d %d\n%d", arr[p] % n, n - (n + q - p) % n, n, (n - q) % n);

    return 0;
}