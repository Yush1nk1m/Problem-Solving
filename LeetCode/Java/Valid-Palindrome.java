class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
                sb.append(c);
            else if ('a' <= c && c <= 'z')
                sb.append((char) (c - 32));
        }

        for (int i = 0; i < sb.length() >> 1; ++i)
            if (sb.charAt(i) != sb.charAt(sb.length() - i - 1))
                return false;
        return true;
    }
}
