#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
void cputurn( int *x, int *y, int *z, int *victory)
{
                if(*x>1 && *y==0 && *z==0)
                {
                    printf("\nmy turn\n");
                    printf("\nI turned %d" ,*x );
                    printf("to 1\n game over you lost!!\n");
                    *victory=1;

                }
                else if(*x>=1 && *y==1 && *z==0)
                {
                    printf("\nmy turn\n");
                   printf("\nI turned %d" ,*x);
                   printf("to 0\n game over you lost!!\n");
                    *victory=1;

                }
                else if(*x>1 && *y==1 && *z==1)
                {
                   printf("\nmy turn\n");
                   printf("\nI turned %d" ,*x);
                   printf("to 1\n game over you lost!!\n");
                    *victory=1;

                }
                else if(*x==1 && *y==1 && *z==1)
                {
                    printf("i never lose start again");
                    *victory=1;
                }
                else
                {
                    if(*x!=*y-*z)
                    {
                        printf("\nmy turn\n");
                        printf("\ni turned %d ",*x);
                        *x=*y-*z;
                        printf("to %d",*x );
                    }
                    else
                        {
                            printf("\nmy turn\n");
                            printf("\ni turned %d ",*x);
                            *x=(*y-*z)-1;
                            printf("to %d",*x);
                        }

                }
    return;
}

void userturn( int *x, int *y, int *z)
{

    int changewho=-1,changefor=-1;

            while((changewho!=*x) && (changewho!=*y) && (changewho!=*z))
                {
                     printf("\nyour turn please choose number from pack\n");
                     scanf("%d",&changewho);

                }
            while((changewho<=changefor) || (changefor<0))
                {
                    printf("\n choose a lower number to take?\n");
                    scanf("%d",&changefor);
                }
            if(*x==changewho) *x=changefor;
            else if(*y==changewho) *y=changefor;
            else if(*z==changewho) *z=changefor;
            return;
}

void gnim()
{
    int victory=0;
    int x=-1,y=-1,z=-1;
    while(x<0||y<0||z<0)
    {
     printf("welcome to my game choose 3 positive sizes of matches in each pack if you choose negative number choose again\n");
     scanf("%d %d %d",&x,&y,&z);
    }
    int turn=0;
    int hi;
    int lo;
    int mid;

    while(victory==0)
    {

        lo = min(min(x, y), z);
        hi = max(max(x,y), z);
        mid=x+y+z-lo-hi;
        z=lo;
        y=mid;
        x=hi;
        printf("\npacket sizes are now:%d %d %d" ,x,y,z );

        if((x==(y+z) && turn==0) || (turn%2==0 && turn>0))
        {
          userturn(&x,&y,&z);
          turn=2;
          turn++;
        }
        else
            {
                cputurn(&x,&y,&z,&victory);
                turn=1;
                turn++;
            }


    }
return;
}

int main()
{

    gnim();
    return 0;
}

