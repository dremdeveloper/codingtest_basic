import java.util.*;

class ATopologicalSortKahn {
    public static void main(String[] args){
        int n=6;
        int[][] edges={{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
        List<List<Integer>> g=new ArrayList<>(); for(int i=0;i<n;i++) g.add(new ArrayList<>());
        int[] indeg=new int[n];
        for(int[] e:edges){g.get(e[0]).add(e[1]); indeg[e[1]]++;}
        Queue<Integer> q=new ArrayDeque<>();
        for(int i=0;i<n;i++) if(indeg[i]==0) q.offer(i);
        List<Integer> order=new ArrayList<>();
        while(!q.isEmpty()){
            int u=q.poll(); order.add(u);
            for(int v:g.get(u)) if(--indeg[v]==0) q.offer(v);
        }
        System.out.println(order);
    }
}
