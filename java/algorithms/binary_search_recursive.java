import java.util.*;

class ABinarySearchRecursive {
    static int search(int[] arr, int target, int l, int r) {
        if (l > r) return -1;
        int m = l + (r - l) / 2;
        if (arr[m] == target) return m;
        if (arr[m] < target) return search(arr, target, m + 1, r);
        return search(arr, target, l, m - 1);
    }
    public static void main(String[] args) {
        int[] a = {1,3,5,7,9,11};
        System.out.println(search(a, 7, 0, a.length-1));
    }
}
