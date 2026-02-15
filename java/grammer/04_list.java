import java.util.*;

class GN04List {
    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>(Arrays.asList(1, 2, 3));
        nums.add(4);
        nums.remove(Integer.valueOf(2));
        System.out.println(nums);
    }
}
