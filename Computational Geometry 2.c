#include<stdio.h>
#include<stdlib.h>

typedef struct vertex
{
    int x;
    int y;
} point;

int Sign(point a,point b, point c)
{
    int x;
    x=((a.x*b.y)+(b.x*c.y)+(c.x*a.y)-(a.x*c.y)-(c.x*b.y)-(b.x*a.y))/2;
    if(x>0){return 1;}
    else if(x<0){ return 0;}
    return 2;
}
int intersection(int m,int n)
{
    if(m==1 && n==0||m==0 && n==1){return 1;}
    else if(m==2 || n==2) {return 2;}
    return 0;
}
 int main()
 {
     printf("\nDetermination of a point which is inside or outside of a Polygon\n");
     printf("         (Exceptional cases are avoided.)   \n\n");
     int i,n,p,k,count=0;
     point arr[50],out,in;
     out.x=0;out.y=0;
     printf("Enter the amount of number of points of polygon:\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
        printf("Enter Point's number for x and y:\n");
        scanf("%d%d",&arr[i].x,&arr[i].y);
        if(arr[i].x>out.x){out.x=arr[i].x+100;}
        if(arr[i].y>out.y){out.y=arr[i].y+100;}
     }

     count=0;
     printf("\nEnter Inside or Outside Point:\n");
     printf("x=");scanf("%d",&in.x);
     printf("y=");scanf("%d",&in.y);

     //Making a outside point which is supposed to be in infity
     if(in.x>out.x){out.x=in.x+100;}
     if(in.y>out.y){out.y=in.y+100;}

     for(i=0;i<n-1;i++)
     {
         p=intersection(Sign(arr[i],out,arr[i+1]),Sign(arr[i],in,arr[i+1]));
         k=intersection(Sign(out,arr[i],in),Sign(out,arr[i+1],in));
         if(p==1 && k==1){count++;}
         else if(p==2 || k==2){printf("This is an Exceptional Case."); return 0;}
     }
     //For the line of end point to starting point of polygon
     p=intersection(Sign(arr[0],out,arr[n-1]),Sign(arr[0],in,arr[n-1]));
     k=intersection(Sign(out,arr[0],in),Sign(out,arr[n-1],in));
     if(p==1 && k==1){count++;}
     else if(p==2 || k==2){printf("This is an Exceptional Case."); return 0;}

     if(count%2==0 || count!= 1){printf("Outside");}
     else{printf("Inside");}
}

