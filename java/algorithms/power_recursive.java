class APowerRecursive {
    static long pow(long a,long n){ if(n==0)return 1; long h=pow(a,n/2); return n%2==0?h*h:h*h*a; }
    public static void main(String[] args){ System.out.println(pow(2,10)); }
}
