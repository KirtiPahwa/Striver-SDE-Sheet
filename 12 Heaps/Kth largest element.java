
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pr = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            pr.add(nums[i]);
            if (pr.size() > k) {
                int a = pr.remove();
            }

        }
        return pr.remove();
    }
}