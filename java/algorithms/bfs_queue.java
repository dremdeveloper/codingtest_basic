import java.util.*;

class ABfsQueue {
    public static void main(String[] args) {
        List<List<Integer>> g = List.of(List.of(1,2), List.of(3), List.of(3), List.of());
        boolean[] vis = new boolean[g.size()];
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(0); vis[0] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            System.out.print(cur + " ");
            for (int nxt : g.get(cur)) if (!vis[nxt]) { vis[nxt] = true; q.offer(nxt); }
        }
    }
}
