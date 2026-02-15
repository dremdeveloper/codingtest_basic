import java.util.*;

class PRangeSumQuery {
    static long brute(int[] a, int[][] qs){ long s=0; for(int[] q:qs) for(int i=q[0];i<=q[1];i++) s+=a[i]; return s; }
    static long prefix(int[] a, int[][] qs){ long[] p=new long[a.length+1]; for(int i=0;i<a.length;i++) p[i+1]=p[i]+a[i]; long s=0; for(int[] q:qs)s+=p[q[1]+1]-p[q[0]]; return s; }
    public static void main(String[] args){
        int n=200000,k=200000; Random rnd=new Random(42);
        int[] a=new int[n]; for(int i=0;i<n;i++) a[i]=rnd.nextInt(100);
        int[][] qs=new int[k][2];
        for(int i=0;i<k;i++){ int l=rnd.nextInt(n); int r=l+rnd.nextInt(n-l); qs[i][0]=l; qs[i][1]=r; }
        long s1=System.nanoTime(); long r1=brute(a,qs); long e1=System.nanoTime();
        long s2=System.nanoTime(); long r2=prefix(a,qs); long e2=System.nanoTime();
        System.out.println("brute 결과="+r1+", 시간="+((e1-s1)/1e9)+"s");
        System.out.println("prefix 결과="+r2+", 시간="+((e2-s2)/1e9)+"s");
    }
}
