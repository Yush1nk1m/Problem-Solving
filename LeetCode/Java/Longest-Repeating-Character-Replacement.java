class Solution {
    
    int[] count = new int[26];

    public int characterReplacement(String s, int k) {
        int l = 0, r = 0, length = 0;    
        while (r < s.length()) {
            boolean valid = false;
            ++count[(int) (s.charAt(r++) - 'A')];
            for (int i = 0; i < 26; ++i)
                if (count[i] + k >= r - l) {
                    valid = true;
                    break;
                }

            if (valid) {
                length = Math.max(length, r - l);
            } else {
                --count[(int) (s.charAt(l++) - 'A')];
            }
        }

        return length;
    }
}