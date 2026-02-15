class AUnionFind {
    static int find(int[] p,int x){ return p[x]==x?x:(p[x]=find(p,p[x])); }
    static void union(int[] p,int a,int b){ a=find(p,a); b=find(p,b); if(a!=b)p[b]=a; }
    public static void main(String[] args){
        int[] p=new int[6]; for(int i=0;i<p.length;i++) p[i]=i;
        union(p,1,2); union(p,2,3); union(p,4,5);
        System.out.println(find(p,1)==find(p,3));
        System.out.println(find(p,1)==find(p,5));
    }
}
