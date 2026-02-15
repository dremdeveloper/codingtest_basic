import java.util.*;

class AQuicksortRecursive {
    static void sort(int[] a,int l,int r){
        if(l>=r)return;
        int p=a[(l+r)/2], i=l,j=r;
        while(i<=j){
            while(a[i]<p)i++; while(a[j]>p)j--;
            if(i<=j){int t=a[i];a[i]=a[j];a[j]=t;i++;j--;}
        }
        sort(a,l,j); sort(a,i,r);
    }
    public static void main(String[] args){ int[] a={5,1,4,2,8}; sort(a,0,a.length-1); System.out.println(Arrays.toString(a)); }
}
