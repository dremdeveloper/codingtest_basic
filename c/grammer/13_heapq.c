#include <stdio.h>
void push(int h[],int*n,int x){int i=++(*n);while(i>1&&h[i/2]>x){h[i]=h[i/2];i/=2;}h[i]=x;}
int pop(int h[],int*n){int r=h[1],last=h[(*n)--],i=1,c;while((c=i*2)<=*n){if(c+1<=*n&&h[c+1]<h[c])c++;if(last<=h[c])break;h[i]=h[c];i=c;}h[i]=last;return r;}
int main(void){
    int h[100],n=0; push(h,&n,5); push(h,&n,2); push(h,&n,7);
    while(n) printf("%d ",pop(h,&n));
    printf("\n");
    return 0;
}
