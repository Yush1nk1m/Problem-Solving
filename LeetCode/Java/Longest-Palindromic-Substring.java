class Solution {
    public String longestPalindrome(String s) {
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        int maxLength = 1;
        String maxSubstring = s.substring(0, 1);
        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
            if (i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)) {
                isPalindrome[i][i + 1] = true;
                maxLength = 2;
                maxSubstring = s.substring(i, i + 2);
            }
        }

        for (int k = 2; k < s.length(); k++)
            for (int i = 0; i + k < s.length(); i++)
                if (s.charAt(i) == s.charAt(i + k) && isPalindrome[i + 1][i + k - 1]) {
                    isPalindrome[i][i + k] = true;
                    if (maxLength < k + 1) {
                        maxLength = k + 1;
                        maxSubstring = s.substring(i, i + k + 1);
                    }
                }
        return maxSubstring;
    }
}