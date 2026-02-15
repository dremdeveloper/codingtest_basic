class AFactorialRecursive {
    static long fac(int n){ return n<=1?1:n*fac(n-1); }
    public static void main(String[] args){ System.out.println(fac(5)); }
}
