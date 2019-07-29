#include <stdio.h>
#include <stdlib.h>
#include <error.h>

void print_proc()
{
    printf ("I am process '%d', and I am son of process '%d'!\n", getpid(), getppid());
}

int main()
{
    int i;
    
//    for (i = 1; i <= 3; i++)
    {
        int f = fork();
        
        if (f < 0)
        {
            perror ("Eroare la fork");
            exit (1);
        }
        else
        {
            printf("%d ",i);
            print_proc ();
            wait (0);
            printf("m-am oprit\n");
        }
    }
    
    return 0;
}

