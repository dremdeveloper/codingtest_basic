import java.util.*;

class AQuicksortIterative {
    static void sort(int[] a){
        Deque<int[]> st=new ArrayDeque<>(); st.push(new int[]{0,a.length-1});
        while(!st.isEmpty()){
            int[] seg=st.pop(); int l=seg[0], r=seg[1]; if(l>=r) continue;
            int p=a[(l+r)/2], i=l,j=r;
            while(i<=j){ while(a[i]<p)i++; while(a[j]>p)j--; if(i<=j){int t=a[i];a[i]=a[j];a[j]=t;i++;j--;}}
            if(l<j) st.push(new int[]{l,j}); if(i<r) st.push(new int[]{i,r});
        }
    }
    public static void main(String[] args){ int[] a={5,1,4,2,8}; sort(a); System.out.println(Arrays.toString(a)); }
}
