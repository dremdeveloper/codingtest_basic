import java.util.*;

class AMergeSortRecursive {
    static void sort(int[] a,int l,int r){
        if(l>=r) return;
        int m=(l+r)/2;
        sort(a,l,m); sort(a,m+1,r);
        int[] tmp=new int[r-l+1]; int i=l,j=m+1,k=0;
        while(i<=m&&j<=r) tmp[k++]=a[i]<=a[j]?a[i++]:a[j++];
        while(i<=m) tmp[k++]=a[i++]; while(j<=r) tmp[k++]=a[j++];
        System.arraycopy(tmp,0,a,l,tmp.length);
    }
    public static void main(String[] args){ int[] a={5,1,4,2,8}; sort(a,0,a.length-1); System.out.println(Arrays.toString(a)); }
}
