import java.util.*;

class AKnapsackN01Dp {
    public static void main(String[] args){
        int[] w={2,1,3,2}; int[] v={12,10,20,15}; int cap=5;
        int[] dp=new int[cap+1];
        for(int i=0;i<w.length;i++){
            for(int c=cap;c>=w[i];c--) dp[c]=Math.max(dp[c],dp[c-w[i]]+v[i]);
        }
        System.out.println(dp[cap]);
    }
}
