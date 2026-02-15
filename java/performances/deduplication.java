import java.util.*;

class PDeduplication {
    static List<Integer> dedupList(List<Integer> a){
        List<Integer> out=new ArrayList<>();
        for(int x:a) if(!out.contains(x)) out.add(x);
        return out;
    }
    static List<Integer> dedupSet(List<Integer> a){
        Set<Integer> seen=new HashSet<>(); List<Integer> out=new ArrayList<>();
        for(int x:a) if(seen.add(x)) out.add(x);
        return out;
    }
    public static void main(String[] args){
        int n=300000; Random rnd=new Random(42);
        List<Integer> a=new ArrayList<>(); for(int i=0;i<n;i++) a.add(rnd.nextInt(100000));
        long s1=System.nanoTime(); int l1=dedupList(a).size(); long e1=System.nanoTime();
        long s2=System.nanoTime(); int l2=dedupSet(a).size(); long e2=System.nanoTime();
        System.out.println("list 기반 결과="+l1+", 시간="+((e1-s1)/1e9)+"s");
        System.out.println("set 보조 결과="+l2+", 시간="+((e2-s2)/1e9)+"s");
    }
}
