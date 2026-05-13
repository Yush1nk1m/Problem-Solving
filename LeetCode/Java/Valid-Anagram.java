class Solution {

    int[] count = new int[26];

    public boolean isAnagram(String s, String t) {
        for (char c : s.toCharArray())
            ++count[(int) (c - 'a')];
        for (char c : t.toCharArray())
            --count[(int) (c - 'a')];
        for (int c : count)
            if (c != 0)
                return false;
        return true;
    }
}