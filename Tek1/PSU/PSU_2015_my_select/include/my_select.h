/*
** my_select.h for my_select in /home/hubert_i/rendu/PSU_2015_my_select
** 
** Made by leo hubert
** Login   <hubert_i@epitech.net>
** 
** Started on  Tue Dec  8 09:56:37 2015 leo hubert
** Last update Tue Dec  8 18:21:22 2015 leo hubert
*/

#ifndef MY_SELECT_
#define MY_SELECT_

typedef struct s_list
{
  int	first;
  int	is_selected;
  int	is_target;
  char	*str;
  struct s_list *prev;
  struct s_list *next;
}	t_list;

#endif
