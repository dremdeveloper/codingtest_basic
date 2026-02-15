import java.util.*;

class GN15BisectLeft {
    static int bisectLeft(List<Integer> arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (arr.get(m) < target) l = m + 1;
            else r = m;
        }
        return l;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(1, 3, 3, 5, 8);
        System.out.println(bisectLeft(arr, 3));
    }
}
