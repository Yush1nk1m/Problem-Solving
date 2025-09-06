class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean[] dup = new boolean[256];
        int maxLength = 0, i = 0, j = 0;
        while (j < s.length()) {
            if (!dup[s.charAt(j)]) {
                dup[s.charAt(j++)] = true;
                maxLength = Math.max(maxLength, j - i);
            } else {
                dup[s.charAt(i++)] = false;
            }
        }
        return maxLength;
    }
}