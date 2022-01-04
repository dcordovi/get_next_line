#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char *read_to_staticstr(int fd, char * staticstr)
{
    char* buff;
    int size;
    buff = (char *)malloc(sizeof(char) * (BUFF_SIZE+1));
    if (!buff)
        return (NULL);
    size = 1;
    while (!(ft_strchr(staticstr, '\n')) && size > 0 )
    {
        size = read(fd, buff, BUFF_SIZE);
        if (size == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[size] = '\0';
        staticstr = ft_strjoin(staticstr, buff);
    }
    free(buff);
    return (staticstr);
}

int line_len(char *staticstr)
{
    int i;

    i=0;
    while (staticstr[i] && staticstr[i] != '\n')
        i++;
    return (i);
}

char *get_line(char* staticstr)
{
    int i;
    char *line;

    i=0;
    if (!staticstr)
        return (NULL);
    line = (char *)malloc((line_len(staticstr) + 2) * sizeof(char));
    if (!line)
        return (NULL);
    while (staticstr[i] && staticstr[i] != '\n')
    {
        line[i]=staticstr[i];
        i++;
    }
    if (staticstr[i] == '\n')
    {
        line[i]='\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *get_next_line(int fd)
{

    static char *staticstr = "";
    char *line;

    if (fd < 0 || fd > 1024 || BUFF_SIZE <= 0)
        return (NULL);
    staticstr = read_to_staticstr(fd, staticstr);
    if (!staticstr)
        return (NULL);
    line = get_line(staticstr);
    if (!line)
        return (NULL);
    staticstr = newstaticstr(staticstr);
    if (!strcmp(line, ""))
        return NULL;
    return (line);
}

// int    main(void)
// {
//     int        fd;
//     char    *s;

//     s = malloc(100);
//     fd = open("file.txt", O_RDONLY);
//     printf("|%s|\n", get_next_line(fd));
//     s = NULL;
//     printf("|%s|\n", s);
//     while (strcmp(s = get_next_line(fd), ""))
//         printf("gnl: |%s|\n", s);
// }