package P34348;

import java.util.*;

public class Test {

    public static void main(String[] args) {
        List<Integer> list = new ArrayList(Arrays.asList(new Integer[]{0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}));
        System.out.println(Collections.binarySearch(list, 0));
        System.out.println(Collections.binarySearch(list, 1));
        System.out.println(Collections.binarySearch(list, 2));
        System.out.println(Collections.binarySearch(list, 3));
        System.out.println(Collections.binarySearch(list, 4));
    }
}
