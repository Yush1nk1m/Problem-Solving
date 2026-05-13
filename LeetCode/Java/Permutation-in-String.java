class Solution {

    boolean[] visited = new boolean[26];
    int[] count = new int[26];

    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        
        for (char c : s1.toCharArray()) {
            visited[c - 'a'] = true;
            ++count[c - 'a'];
        }

        int l = 0, r = s1.length();
        for (int i = l; i < r; ++i)
            --count[s2.charAt(i) - 'a'];
        
        while (!check() && r < s2.length()) {
            ++count[s2.charAt(l++) - 'a'];
            --count[s2.charAt(r++) - 'a'];
        }

        return check();
    }

    private boolean check() {
        for (int i = 0; i < 26; ++i)
            if (visited[i] && count[i] > 0)
                return false;
        return true;
    }
}
