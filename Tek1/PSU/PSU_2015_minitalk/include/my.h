/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Fri Feb  5 12:01:08 2016 Léo Hubert
*/

#ifndef MY_
#define MY_

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#define _XOPEN_SOURCE
#define _POSIX_SOURCE
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#define COLOR_CLIGNO  "\033[5;1;35m"

void	init_serveur();
void	show_message(int sig);
int	my_getnbr(char *str);
int	send_binary(char caract, int uid);
int	error(int mode);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_put_nbr(int nbr);
int	color(char c, int *check);

#endif
