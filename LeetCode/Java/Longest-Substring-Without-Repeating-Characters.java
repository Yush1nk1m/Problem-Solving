class Solution {

    int[] count = new int[256];

    public int lengthOfLongestSubstring(String s) {
        int l = 0, r = 0, length = 0;
        while (r < s.length()) {
            if (count[(int) s.charAt(r)] == 0) {
                ++count[(int) s.charAt(r++)];
                length = Math.max(length, r - l);
            } else {
                --count[(int) s.charAt(l++)];
            }
        }    
        return length;
    }
}
