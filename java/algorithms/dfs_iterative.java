import java.util.*;

class ADfsIterative {
    public static void main(String[] args) {
        List<List<Integer>> g = List.of(List.of(1,2), List.of(3), List.of(3), List.of());
        boolean[] vis = new boolean[g.size()];
        Deque<Integer> st = new ArrayDeque<>();
        st.push(0);
        while (!st.isEmpty()) {
            int u = st.pop();
            if (vis[u]) continue;
            vis[u] = true;
            System.out.print(u + " ");
            List<Integer> adj = g.get(u);
            for (int i = adj.size()-1; i>=0; i--) if (!vis[adj.get(i)]) st.push(adj.get(i));
        }
    }
}
