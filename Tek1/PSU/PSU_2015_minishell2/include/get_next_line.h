/*
** get_next_line.h for get_next_line in /home/hubert_i/rendu/2015/CPE_2015/CPE_2015_getnextline
**
** Made by leo hubert
** Login   <hubert_i@epitech.net>
**
** Started on  Tue Jan  5 09:41:47 2016 leo hubert
** Last update Wed Apr  6 21:10:16 2016 Léo Hubert
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "my.h"

#ifndef READ_SIZE
# define READ_SIZE (2)

#endif /* !READ_SIZE */

typedef struct s_next
{
  char	*save;
  char	*result;
  int	rd;
  char	*buffer;
}	t_next;

char	*get_next_line(const int fd);
char	*get_fusion(char *str, char *str2);
int	get_search(char *str, char search);
void	my_show_next_line(t_next *next, char *save);
int	get_len(char *str);

#endif /* !GET_NEXT_LINE */
