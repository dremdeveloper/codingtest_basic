import java.util.*;

class PMembershipLookup {
    static int containsWithList(List<Integer> data, List<Integer> queries){
        int c=0; for(int q:queries) if(data.contains(q)) c++; return c;
    }
    static int containsWithSet(List<Integer> data, List<Integer> queries){
        Set<Integer> s=new HashSet<>(data); int c=0; for(int q:queries) if(s.contains(q)) c++; return c;
    }
    public static void main(String[] args){
        int n=400000, qn=200000;
        List<Integer> data=new ArrayList<>(); for(int i=0;i<n;i++) data.add(i);
        Random rnd=new Random(42);
        List<Integer> queries=new ArrayList<>(); for(int i=0;i<qn;i++) queries.add(rnd.nextInt(n*2));
        long s1=System.nanoTime(); int c1=containsWithList(data,queries); long e1=System.nanoTime();
        long s2=System.nanoTime(); int c2=containsWithSet(data,queries); long e2=System.nanoTime();
        System.out.println("list 결과="+c1+", 시간="+((e1-s1)/1e9)+"s");
        System.out.println("set  결과="+c2+", 시간="+((e2-s2)/1e9)+"s");
    }
}
