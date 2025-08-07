#include <stdio.h>

int trap(int height[], int n) {
    if (n <= 2) {
        return 0;
    }

    int left_max[n];
    int right_max[n];

    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = (left_max[i - 1] > height[i]) ? left_max[i - 1] : height[i];
    }

    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = (right_max[i + 1] > height[i]) ? right_max[i + 1] : height[i];
    }

    int trapped_water = 0;
    for (int i = 0; i < n; i++) {
        trapped_water += (left_max[i] < right_max[i] ? left_max[i] : right_max[i]) - height[i];
    }

    return trapped_water;
}

int main() {
    int n;
    scanf("%d", &n);
    int height[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = trap(height, n);
    printf("%d\n", result);
    return 0;
}