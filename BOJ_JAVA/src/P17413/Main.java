package P17413;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int i = 0;
    static char[] line;
    static Stack<Character> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        line = br.readLine().toCharArray();
        while (i < line.length) {
            while (i < line.length && line[i] != '<' && line[i] != ' ')
                stack.push(line[i++]);

            while (!stack.isEmpty())
                sb.append(stack.pop());

            if (i >= line.length)
                break;

            if (line[i] == '<') {
                while (line[i] != '>')
                    sb.append(line[i++]);
            }
            sb.append(line[i++]);
        }
        System.out.print(sb);
    }
}
