class Solution {

    int lb, rb;
    boolean[] visited = new boolean[60];
    int[] count = new int[60];

    public String minWindow(String s, String t) {
        lb = 0;
        rb = s.length() + 1;
        for (char c : t.toCharArray()) {
            visited[c - 'A'] = true;
            ++count[c - 'A'];
        }

        int l = 0;
        while (l < s.length() && !visited[s.charAt(l) - 'A'])
            ++l;
        int r = l;
        while (r < s.length() && !check())
            --count[s.charAt(r++) - 'A'];
        
        while (check()) {
            if (rb - lb > r - l) {
                rb = r;
                lb = l;
            }

            ++count[s.charAt(l++) - 'A'];
            while (l < s.length() && !visited[s.charAt(l) - 'A'])
                ++count[s.charAt(l++) - 'A'];
            while (r < s.length() && !check())
                --count[s.charAt(r++) - 'A'];
        }

        if (rb == s.length() + 1)
            return new String("");
        else
            return s.substring(lb, rb + 1);
    }

    private boolean check() {
        for (int i = 0; i < 60; ++i)
            if (visited[i] && count[i] > 0)
                return false;
        return true;
    }
}
