import java.util.*;

class GN13Heapq {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(5); pq.offer(1); pq.offer(3);
        while (!pq.isEmpty()) System.out.print(pq.poll() + " ");
    }
}
