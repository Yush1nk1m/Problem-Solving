class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String str : strs)
            sb.append(str.length()).append(' ').append(str);
        return sb.toString();
    }

    public List<String> decode(String str) {
        List<String> list = new ArrayList<>();
        int i = 0;
        while (i < str.length()) {
            int j = i;
            while (j < str.length() && '0' <= str.charAt(j) && str.charAt(j) <= '9')
                ++j;
            
            int length = Integer.parseInt(str.substring(i, j));
            list.add(str.substring(j + 1, j + 1 + length));
            i = j + 1 + length;
        }
        return list;
    }
}
