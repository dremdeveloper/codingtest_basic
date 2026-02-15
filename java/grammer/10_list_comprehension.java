import java.util.*;

class GN10ListComprehension {
    public static void main(String[] args) {
        List<Integer> squares = new ArrayList<>();
        for (int i = 0; i < 10; i++) if (i % 2 == 0) squares.add(i * i);
        System.out.println(squares);
    }
}
