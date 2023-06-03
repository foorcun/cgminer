#include <stdio.h>
#include <string.h>

// compile # gcc param.c -o param
// run # param -p "Hello, world!"

int main(int argc, char *argv[])
{
    char *parameter = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-p") == 0)
        {
            if (i + 1 < argc)
            {
                parameter = argv[i + 1];
                break;
            }
        }
    }

    if (parameter == NULL)
    {
        printf("No parameter provided.\n");
    }
    else
    {
        printf("Parameter: %s\n", parameter);
    }

    return 0;
}
