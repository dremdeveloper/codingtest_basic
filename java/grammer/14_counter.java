import java.util.*;

class GN14Counter {
    public static void main(String[] args) {
        String text = "banana";
        Map<Character, Integer> counter = new HashMap<>();
        for (char c : text.toCharArray()) counter.put(c, counter.getOrDefault(c, 0) + 1);
        System.out.println(counter);
    }
}
