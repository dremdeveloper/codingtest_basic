class GNTuple {
    static class Pair<A, B> {
        A first;
        B second;
        Pair(A first, B second) { this.first = first; this.second = second; }
    }

    public static void main(String[] args) {
        Pair<String, Integer> user = new Pair<>("alice", 20);
        System.out.println(user.first + " " + user.second);
    }
}
