class ABinarySearchIterative {
    static int search(int[] arr, int target) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == target) return m;
            if (arr[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] a = {1,3,5,7,9,11};
        System.out.println(search(a, 7));
    }
}
