#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            double maxLeft1 = (partition1 == 0) ? std::numeric_limits<double>::lowest() : nums1[partition1 - 1];
            double minRight1 = (partition1 == m) ? std::numeric_limits<double>::max() : nums1[partition1];

            double maxLeft2 = (partition2 == 0) ? std::numeric_limits<double>::lowest() : nums2[partition2 - 1];
            double minRight2 = (partition2 == n) ? std::numeric_limits<double>::max() : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                } else {
                    return std::max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }
        // Control should not reach here for valid inputs.
        return -1.0;
    }
};