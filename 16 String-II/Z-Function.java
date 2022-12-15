class Solution {
    private int[] calculateZ(char input[]) {
        int n = input.length;
        System.out.println(input);
        int z[] = new int[n];
        int l = 0;
        int r = 0;
        z[0] = 0;
        for (int k = 1; k < n; k++) { // l and r are the left and right boundaries for zbox

            if (k > r) { // check if k doesnot comes under zbox
                l = r = k;

                // extending zbox by right++ upto max possible
                while (r < n && input[r] == input[r - l])
                    r++;
                r--;
                z[k] = r - l + 1;

            } else { // the case in which our ele is inside the zbox
                int k1 = k - l;

                // directly copying the prev z's value bcz it doesn't touches the right boudary
                // of z box
                if (z[k1] < r - k + 1) {
                    z[k] = z[k1];
                } else {// z value of the ele touches the right boundary of curr zbox

                    // reducing the left boudary of the zbox to find the further z value for curr
                    // ele-k
                    l = k;

                    // l-r is already the valid zbox for curr ele k , so we will check for values >r
                    // and extend the zbox
                    r++;

                    // extending zbox by right++ upto max possible

                    while (r < n && input[r] == input[r - l])
                        r++;
                    r--;
                    z[k] = r - l + 1;

                }
            }
        }
        return z;

    }

    public int z_algo(char s[], char p[]) {
        int m = s.length;
        int n = p.length;

        // creating new string= p+'$'+text
        char newString[] = new char[m + n + 1];
        int i = 0;
        for (char x : p) {
            newString[i] = x;
            i++;
        }
        newString[i++] = '$';

        for (char x : s) {
            newString[i] = x;
            i++;
        }

        // calculating Z array
        int Z[] = calculateZ(newString);

        for (i = 0; i < Z.length; i++) {
            if (Z[i] == n) {
                return (i - n - 1);
            }
        }
        return -1;
    }

    public int strStr(String haystack, String needle) {
        return z_algo(haystack.toCharArray(), needle.toCharArray());
    }
}