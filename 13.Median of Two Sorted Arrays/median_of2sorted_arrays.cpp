#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m); // Ensure nums1 is the smaller array
    }

    int low = 0, high = m;
    int mid = (m + n + 1) / 2;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = mid - cut1;

        int left1 = (cut1 == 0) ? -1000000 : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? -1000000 : nums2[cut2 - 1];

        int right1 = (cut1 == m) ? 1000000 : nums1[cut1];
        int right2 = (cut2 == n) ? 1000000 : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 0) {
                return (double)((max(left1, left2) + min(right1, right2)) / 2.0);
            } else {
                return (double)max(left1, left2);
            }
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, m, nums2, n);
    cout << fixed << setprecision(2) << median << endl;

    return 0;
}
