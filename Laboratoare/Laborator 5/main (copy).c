#include <stdio.h>
#include <stdlib.h>
#include <error.h>

void print_proc()
{
    printf ("I am process '%d', and I am son of '%d'!\n", getpid(), getppid());
}

int main()
{
    int p1, p2, p3;

    p1 = fork();

    if (p1 > 0)
        printf ("I am process '%d'!\n", getpid());
    else if (p1 == 0)
    {
        print_proc ();

        p2 = fork ();
        if (p2 == 0)
        {
            print_proc ();
        }
        else
        {
            perror ("Error creating sub-process2");
            exit (1);
        }
    }
    else
    {
        perror ("Error creating process");
        exit (1);
    }

    return 0;
}

