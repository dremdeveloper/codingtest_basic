import java.util.*;

class GN11SortKeyLambda {
    public static void main(String[] args) {
        List<String> words = new ArrayList<>(Arrays.asList("apple", "kiwi", "banana", "fig"));
        words.sort(Comparator.comparingInt(String::length));
        System.out.println(words);
    }
}
