package P1701;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        Integer maxLength = 0;
        String input = br.readLine();

        for (int i = 0; i < input.length() - 1; i++) {
            maxLength = Math.max(maxLength, getFailureMax(input.substring(i)));
        }

        bw.write(maxLength.toString());
        bw.flush();
        bw.close();
    }

    public static Integer getFailureMax(String pattern) {
        int[] failure = new int[pattern.length()];
        failure[0] = -1;

        int i, j;
        for (i = 1; i < pattern.length(); i++) {
            j = failure[i - 1];

            while ((pattern.charAt(i) != pattern.charAt(j + 1)) && (j >= 0)) {
                j = failure[j];
            }

            if (pattern.charAt(i) == pattern.charAt(j + 1)) {
                failure[i] = j + 1;
            } else {
                failure[i] = -1;
            }
        }

        int maxValue = -1;
        for (int value : failure) {
            maxValue = Math.max(maxValue, value);
        }

        return maxValue + 1;
    }
}
