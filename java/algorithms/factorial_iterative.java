class AFactorialIterative {
    static long fac(int n){ long r=1; for(int i=2;i<=n;i++) r*=i; return r; }
    public static void main(String[] args){ System.out.println(fac(5)); }
}
