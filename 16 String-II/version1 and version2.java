class Solution {
    public int compareVersion(String version1, String version2) {
        int m = version1.length();
        int n = version2.length();
        int i = 0, j = 0;
        while (i < m || j < n) {
            int temp1 = 0;
            while (i < m && version1.charAt(i) != '.') {
                temp1 = temp1 * 10 + version1.charAt(i) - '0';
                i++;
            }
            int temp2 = 0;
            while (j < n && version2.charAt(j) != '.') {
                temp2 = temp2 * 10 + version2.charAt(j) - '0';
                j++;
            }
            if (temp1 > temp2)
                return 1;
            else if (temp1 < temp2)
                return -1;
            i++;
            j++;

        }
        return 0;
    }
}