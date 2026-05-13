class Solution {

    StringBuilder[] sb;
    int[] dr;

    public String convert(String s, int numRows) {
        sb = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++)
            sb[i] = new StringBuilder();
        if (numRows == 1)
            dr = new int[1];
        else
            dr = new int[(numRows - 1) * 2];
        for (int i = 1; i < numRows; i++)
            dr[i] = dr[dr.length - i] = i;
        for (int i = 0; i < s.length(); i++)
            sb[dr[i % dr.length]].append(s.charAt(i));
        for (int i = 1; i < numRows; i++)
            sb[0].append(sb[i]);
        return sb[0].toString();
    }
}