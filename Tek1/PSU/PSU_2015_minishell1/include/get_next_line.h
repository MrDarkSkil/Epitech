/*
** get_next_line.h for get_next_line in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_getnextline
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan  5 09:41:47 2016 leo hubert
** Last update Fri Jan 22 20:04:38 2016 Léo Hubert
*/

#ifndef GET_NEXT_LINE_
#define GET_NEXT_LINE_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE (2)

#endif /* !READ_SIZE */

typedef struct s_next
{
  char *save;
  char *result;
}	t_next;

char	*get_next_line(const int fd);
char	*my_fusionstr(char *str, char *str2);
int	my_strsearch(char *str, char search);
void	my_show_next_line(t_next *next, char *save);
int	my_strlen(char *str);

#endif /* !GET_NEXT_LINE */
