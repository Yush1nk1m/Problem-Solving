package P1464;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static String line;
    static Deque<Character> deque = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        line = br.readLine();
        deque.addFirst(line.charAt(0));
        for (int i = 1; i < line.length(); i++) {
            if (deque.peekFirst() >= line.charAt(i))
                deque.addFirst(line.charAt(i));
            else
                deque.addLast(line.charAt(i));
        }
        for (Character c : deque)
            sb.append(c);
        System.out.println(sb);
    }

}
