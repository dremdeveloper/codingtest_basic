import java.util.*;

class GN06Dict {
    public static void main(String[] args) {
        Map<String, Integer> scores = new HashMap<>();
        scores.put("kim", 90);
        scores.put("lee", 85);
        System.out.println(scores.getOrDefault("kim", 0));
        System.out.println(scores.getOrDefault("park", 0));
    }
}
