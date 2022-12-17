
public class Solution {
    public static int fixJ(String str, int i, int j) {
        while (str.charAt(i) != str.charAt(j)) {
            j--;
        }
        return j;
    }

    public static boolean checkPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }

        }
        return true;
    }

    public static int minCharsforPalindrome(String str) {
        if (str.length() == 0 || str.length() == 1) {
            return 0;
        }
        int i = 0, j = str.length() - 1;
        j = fixJ(str, i, j);
        while (j != i) {
            if (checkPalindrome(str, i, j)) {
                return str.length() - j - 1;
            }
            j = fixJ(str, i, --j);
        }
        return str.length() - j - 1;

    }

}

// better approach using lps

public class Solution {
    public static String updatedString(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append('@');
        for (int i = 0; i < s.length(); i++) {
            sb.append('#');
            sb.append(s.charAt(i));
        }
        sb.append('#');
        sb.append('$');
        return sb.toString();
    }

    public static int manacherAlgo(String originalString) {

        String s = updatedString(originalString);
        int ans = 0;
        int n = s.length();
        int[] LPS = new int[n];
        int c = 0;
        int r = 0; // r of zbox
        for (int i = 1; i < n - 1; i++) {
            int mirror = c - (i - c);
            if (i < r) {
                LPS[i] = Math.min(LPS[mirror], r - i);
            }
            while (s.charAt(i + 1 + LPS[i]) == s.charAt(i - 1 - LPS[i])) {
                LPS[i]++;
            }

            if (i + LPS[i] > r) {
                c = i;
                r = i + LPS[i];
            }
            if (r == n - 2) {
                ans = LPS[i];
                break;
            }
        }
        int maxLen = 1;
        int maxIdx = 0;
        for (int i = 0; i < LPS.length; i++) {
            int firstIdx = i - LPS[i] + 1;
            int actIdx = (firstIdx - 2) / 2;
            if (actIdx == 0 && LPS[i] > (maxLen)) {
                maxLen = LPS[i];
                maxIdx = i;
            }
        }
        return originalString.length() - maxLen;

    }

    public static int minCharsforPalindrome(String str) {
        return manacherAlgo(str);
    }

}
