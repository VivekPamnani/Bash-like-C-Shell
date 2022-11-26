#include "my_shell.h"

void f_echo(char **echo, int num_tokens)
{
    // printf("tok: %d\n", num_tokens);
    // int j = 0;
    // while(j < num_tokens)
    // {
    //     j = get_pipe(echo, num_tokens, j+1);
    //     printf("%d\n", j);
    // }
    for(int i = 2; strcmp(echo[i], "") && i <= num_tokens; i++)
        fprintf(print_dest, "%s ", echo[i]);
    fprintf(print_dest, "\n");

}
