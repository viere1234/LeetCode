class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        const int size = nums1.size() + nums2.size(), partition = (size + 1) * 0.5;
        int left = 0, right = nums1.size(), cut1, cut2, l1, l2, r1, r2;
        while(left <= right) {
            cut1 = (left + right) * 0.5;
            cut2 = partition - cut1;
            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1) 
                return (size % 2) ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) * 0.5;
            if (l1 > r2) right = cut1 - 1;
            else left = cut1 + 1;
        }
        return 0.0;
    }
};
