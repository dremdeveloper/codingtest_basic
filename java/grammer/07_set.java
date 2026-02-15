import java.util.*;

class GN07Set {
    public static void main(String[] args) {
        Set<Integer> s = new HashSet<>(Arrays.asList(1, 2, 2, 3));
        s.add(4);
        System.out.println(s.contains(2));
        System.out.println(s);
    }
}
