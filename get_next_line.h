#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 32
#endif // BUFF_SIZE

char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *left_str, char *buff);
char* newstaticstr(char *str);
char *read_to_staticstr(int fd, char * staticstr);
size_t  ft_strlen(const char *str);
int line_len(char *staticstr);
char *get_line(char* staticstr);

#endif //GET_NEXT_LINE_H
