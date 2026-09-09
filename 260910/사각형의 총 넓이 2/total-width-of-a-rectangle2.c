#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int cmp(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int uniq(int *a, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m == 0 || a[m - 1] != a[i]) a[m++] = a[i];
    }
    return m;
}

int find_idx(int *a, int n, int v) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == v) return mid;
        if (a[mid] < v) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    int n;
    int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
    int xs[MAXN * 2], ys[MAXN * 2];
    static char cover[MAXN * 2][MAXN * 2];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        xs[i * 2] = x1[i];
        xs[i * 2 + 1] = x2[i];
        ys[i * 2] = y1[i];
        ys[i * 2 + 1] = y2[i];
    }

    qsort(xs, n * 2, sizeof(int), cmp);
    qsort(ys, n * 2, sizeof(int), cmp);
    int nx = uniq(xs, n * 2);
    int ny = uniq(ys, n * 2);

    for (int k = 0; k < n; k++) {
        int lx = find_idx(xs, nx, x1[k]);
        int rx = find_idx(xs, nx, x2[k]);
        int ly = find_idx(ys, ny, y1[k]);
        int ry = find_idx(ys, ny, y2[k]);
        for (int i = lx; i < rx; i++)
            for (int j = ly; j < ry; j++)
                cover[i][j] = 1;
    }

    long long area = 0;
    for (int i = 0; i < nx - 1; i++)
        for (int j = 0; j < ny - 1; j++)
            if (cover[i][j])
                area += (long long)(xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);

    printf("%lld\n", area);
    return 0;
}