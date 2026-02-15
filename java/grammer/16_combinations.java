import java.util.*;

class GN16Combinations {
    static void comb(int[] arr, int idx, int r, List<Integer> picked) {
        if (picked.size() == r) {
            System.out.println(picked);
            return;
        }
        for (int i = idx; i < arr.length; i++) {
            picked.add(arr[i]);
            comb(arr, i + 1, r, picked);
            picked.remove(picked.size() - 1);
        }
    }

    public static void main(String[] args) {
        comb(new int[]{1,2,3,4}, 0, 2, new ArrayList<>());
    }
}
