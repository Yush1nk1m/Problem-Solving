class Solution {

    List<List<String>> anagrams = new ArrayList<>();
    Map<Integer, List<String>> map = new HashMap<>();

    public List<List<String>> groupAnagrams(String[] strs) {
        for (String str : strs) {
            int hashCode = Arrays.hashCode(countCharacters(str));
            map.putIfAbsent(hashCode, new ArrayList<>());
            map.get(hashCode).add(str);
        }
        
        for (List<String> list : map.values())
            anagrams.add(list);

        return anagrams;
    }

    private int[] countCharacters(String line) {
        int[] count = new int[26];
        for (char c : line.toCharArray())
            ++count[(int) (c - 'a')];
        return count;
    }
}
