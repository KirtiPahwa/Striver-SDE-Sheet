class Solution {
    public int singleNonDuplicate(int[] arr) {
        int n = arr.length;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0 || arr[mid] != arr[mid - 1]) {
                if (mid % 2 == 0) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (mid % 2 == 1) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return arr[r];
    }
}