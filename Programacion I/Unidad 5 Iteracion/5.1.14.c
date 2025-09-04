#include <stdio.h>
#define MAX_NUM 9000
int main()
{
    int i,j,suma=0;


    for (i=1;i<=MAX_NUM;i++)
    {
        suma=0;
        for (j=1;j<i;j++)
        {
            if (i%j==0)
            {
                suma+=j;
            }

        }
      if (suma==i)
      {
          printf ("%d es perfecto\n",i);
      }
    }
    return 0;
}
