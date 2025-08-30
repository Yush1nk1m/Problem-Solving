package P1302;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N;
    static Map<String, Integer> wordCounts = new HashMap<>();
    static String maxCountedWord;
    static int maxCount;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            String word = br.readLine();
            wordCounts.put(word, wordCounts.getOrDefault(word, 0) + 1);
        }

        List<String> keyList = new ArrayList<>(wordCounts.keySet());
        Collections.sort(keyList);

        for (String key : keyList) {
            if (maxCount < wordCounts.get(key)) {
                maxCountedWord = key;
                maxCount = wordCounts.get(key);
            }
        }

        bw.write(maxCountedWord);
        bw.flush();

        br.close();
        bw.close();
    }
}
