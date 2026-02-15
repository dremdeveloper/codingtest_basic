import java.util.*;

class AMergeSortIterative {
    static void merge(int[] a,int l,int m,int r){
        int[] t=new int[r-l+1]; int i=l,j=m+1,k=0;
        while(i<=m&&j<=r) t[k++]=a[i]<=a[j]?a[i++]:a[j++];
        while(i<=m) t[k++]=a[i++]; while(j<=r) t[k++]=a[j++];
        System.arraycopy(t,0,a,l,t.length);
    }
    static void sort(int[] a){
        for(int sz=1;sz<a.length;sz*=2)
            for(int l=0;l+sz<a.length;l+=2*sz){
                int m=l+sz-1, r=Math.min(l+2*sz-1,a.length-1);
                merge(a,l,m,r);
            }
    }
    public static void main(String[] args){ int[] a={5,1,4,2,8}; sort(a); System.out.println(Arrays.toString(a)); }
}
