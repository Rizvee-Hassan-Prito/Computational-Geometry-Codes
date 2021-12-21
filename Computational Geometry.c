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
    else{return 2;}
}

 int main()
 {
     printf("\nDETECTION OF A CAR WHICH WILL GO LEFT or,RIGHT or,STRAIGHT\n\n");
     point a,b,c;
     printf("Enter First Point:\n");
     printf("x=");scanf("%d",&a.x);
     printf("y=");scanf("%d",&a.y);
     printf("Enter Second Point:\n");
     printf("x=");scanf("%d",&b.x);
     printf("y=");scanf("%d",&b.y);
     printf("Enter Third Point:\n");
     printf("x=");scanf("%d",&c.x);
     printf("y=");scanf("%d",&c.y);
     int k=Sign(a,b,c);
     if(k==1){printf("\nLeft");}
     else if(k==0){printf("\nRight");}
     else{printf("\nStraight");}
 }
