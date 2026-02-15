class APowerIterative {
    static long pow(long a,long n){ long r=1; while(n>0){ if((n&1)==1) r*=a; a*=a; n>>=1;} return r; }
    public static void main(String[] args){ System.out.println(pow(2,10)); }
}
