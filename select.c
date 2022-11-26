#include "my_shell.h"

void select_cmd(char **args, int token_parts, char *home_dir, char **contents, char **path_contents)
{
    if (!strcmp(args[1], "\n"))
    {
        return;
    }

    else if(!strcmp(args[1], "cd"))
    {
        f_cd(args, home_dir);
    }
    else if(!strcmp(args[1], "echo"))
    {
        f_echo(args, token_parts);
    }
    else if(!strcmp(args[1], "pwd"))
    {
        f_pwd();
    }
    else if(!strcmp(args[1], "ls"))
    {
        f_ls(args, contents, path_contents, token_parts);
    }
    else if(!strcmp(args[1], "pinfo"))
    {
        if(token_parts == 2)
            f_pinfo(atoi(args[2]), 1);
        else
            f_pinfo(-1, 1);
    }
    else if(!strcmp(args[1], "setenv"))
    {
        f_setenv(args);
    }
    else if(!strcmp(args[1], "unsetenv"))
    {
        f_unsetenv(args);
    }
    else if(!strcmp(args[1], "quit"))
    {
        return 0;
    }
    else
    {
        int j = strlen(args[0]);
        if(args[0][j-1] == '&')
        {
            args[0][j-1] = '\0';
            f_bground(args);
        }
        else
        {
            f_fground(args, token_parts);
        }
    }

}