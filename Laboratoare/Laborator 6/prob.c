#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int f;              // child process
    int pr[2], pw[2];   // read pipe, write pipe
    int a, b, s;        // first number, second number, and their sum

    if (pipe (pr) < 0)
    {
        perror ("Error creating read-pipe");
        exit (1);
    }

    if (pipe (pw) < 0)
    {
        perror ("Error creating write-pipe");
        exit (5);
    }

    f = fork();

    if (f < 0)
    {
        perror ("Error creating fork");
        exit (2);
    }
    else if (f == 0) // Inside the child proccess
    {
        close (pr[1]);

        if (read (pr[0], &a, sizeof (int)) < 0 ||
            read (pr[0], &b, sizeof (int)) < 0)
        {
            perror("Error pipe-reading");
            exit(4);
        }

        close (pr[0]);
            
        s = a + b;
        
        //printf ("The sum of %d and %d is %d ", a, b, s);
        //printf ("\n");
        //close (pr[0]);
        //exit (0);
        
        close (pw[0]);
        
        if (write (pw[1], &s, sizeof (int)) < sizeof (int))
        {
            perror ("Error pipe-writing");
			close (pw[1]);
			exit (6);
		}
    }
    else // Inside the parent process
    {
        close (pr[0]);

        printf ("First number = ");
        scanf ("%d", &a);
        
        printf ("Second number = ");
        scanf ("%d", &b);

        if (write (pr[1], &a, sizeof (int)) < 0 ||
            write (pr[1], &b, sizeof (int)) < 0)
        {
            perror ("Error pipe-writing");
            close (pr[1]);
            exit (3);
        }
        
        close (pw[1]);
        
		if (read (pw[0], &s, sizeof (int)) < sizeof (int))
		{	
			perror ("Error pipe-reading");
			close (pw[0]);
			exit (7);
		}
		else
		{
			printf ("Suma numerelor %d + %d este: %d\n", a, b, s);
			close (pw[0]);
			exit (0);
		}
    }
    
    return 0;
}

