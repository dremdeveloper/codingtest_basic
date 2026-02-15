import java.util.*;

class GN12Deque {
    public static void main(String[] args) {
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(1);
        dq.addLast(2);
        dq.addFirst(0);
        System.out.println(dq.pollFirst());
        System.out.println(dq.pollLast());
    }
}
