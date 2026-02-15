import java.util.*;

class ADijkstraHeap {
    static class Node { int v, d; Node(int v,int d){this.v=v;this.d=d;} }
    public static void main(String[] args) {
        int n = 5;
        List<List<int[]>> g = new ArrayList<>();
        for(int i=0;i<n;i++) g.add(new ArrayList<>());
        g.get(0).add(new int[]{1,2}); g.get(0).add(new int[]{2,5});
        g.get(1).add(new int[]{2,1}); g.get(1).add(new int[]{3,2});
        g.get(2).add(new int[]{3,3}); g.get(3).add(new int[]{4,1});
        int[] dist = new int[n]; Arrays.fill(dist, Integer.MAX_VALUE); dist[0]=0;
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a->a.d));
        pq.offer(new Node(0,0));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(cur.d != dist[cur.v]) continue;
            for(int[] e: g.get(cur.v)){
                int nv=e[0], nd=cur.d+e[1];
                if(nd<dist[nv]){dist[nv]=nd; pq.offer(new Node(nv,nd));}
            }
        }
        System.out.println(Arrays.toString(dist));
    }
}
