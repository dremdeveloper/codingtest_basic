import java.util.*;

class ADfsRecursive {
    static void dfs(int u, List<List<Integer>> g, boolean[] vis) {
        vis[u] = true;
        System.out.print(u + " ");
        for (int v : g.get(u)) if (!vis[v]) dfs(v, g, vis);
    }
    public static void main(String[] args) {
        List<List<Integer>> g = List.of(List.of(1,2), List.of(3), List.of(3), List.of());
        dfs(0, g, new boolean[g.size()]);
    }
}
