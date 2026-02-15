import java.util.*;

class ALisDpBinarySearch {
    public static void main(String[] args){
        int[] a={10,20,10,30,20,50};
        List<Integer> tails=new ArrayList<>();
        for(int x:a){
            int i=Collections.binarySearch(tails,x);
            if(i<0) i=-(i+1);
            if(i==tails.size()) tails.add(x); else tails.set(i,x);
        }
        System.out.println(tails.size());
    }
}
