class PStringBuilding {
    static String plusLoop(int n){ String s=""; for(int i=0;i<n;i++) s += "a"; return s; }
    static String builderLoop(int n){ StringBuilder sb=new StringBuilder(); for(int i=0;i<n;i++) sb.append('a'); return sb.toString(); }
    public static void main(String[] args){
        int n=200000;
        long s1=System.nanoTime(); plusLoop(n); long e1=System.nanoTime();
        long s2=System.nanoTime(); builderLoop(n); long e2=System.nanoTime();
        System.out.println("+= 시간="+((e1-s1)/1e9)+"s");
        System.out.println("StringBuilder 시간="+((e2-s2)/1e9)+"s");
    }
}
