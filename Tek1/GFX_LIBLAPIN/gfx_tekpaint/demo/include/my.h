/*
** my.h for my.h in /home/hubert_1/rendu/Piscine_C_J09/ex_02
**
** Made by leo hubert
** Login   <hubert_1@epitech.net>
**
** Started on  Thu Oct  8 14:25:19 2015 leo hubert
** Last update Tue Jan 26 19:07:53 2016 Léo Hubert
*/

#ifndef MY_
#define MY_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lapin.h"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#define	LINE		((line.dx > line.dy) ? (line.dx) : (line.dy))
#define	ULINE		((line.dx > line.dy) ? (line.dy) : (line.dx))
#define	SINC		((line.dx > line.dy) ? (line.yinc) : (line.xinc))
#define	USINC		((line.dx > line.dy) ? (line.xinc) : (line.yinc))
#define XY		((line.dx > line.dy) ? (pos[0].x += line.xinc) : (pos[0].y += line.yinc))
#define YX		((line.dx > line.dy) ? (pos[0].y += line.yinc) : (pos[0].x += line.xinc))
#define ABS(value)      ((value < 0) ? (-value) : (value))

typedef struct s_image
{
  short int			magic_number;
  unsigned int			size;
  unsigned int			inutile;
  unsigned int			pos_pix;
  unsigned int			size_header;
  unsigned int			width;
  unsigned int			height;
  short int			plan_bit;
  short int			plan_bitbis;
  unsigned int			compression;
  unsigned int			size_octe;
  unsigned int			width_metre;
  unsigned int			height_metre;
  unsigned int			number_colorpal;
  unsigned int			number_color;
} __attribute__ ((packed))	t_image;

typedef	struct	s_line
{
  int	dx;
  int	dy;
  int	xinc;
  int	yinc;
  int	cumul;
  int	x;
  int	y;
}	t_line;

typedef struct s_list
{
  int			x;
  int			y;
  int			d;
  t_bunny_position	pos2;
}	t_list;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*menu_1;
  t_bunny_pixelarray	*menu_2;
  t_bunny_position	pos;
  t_bunny_position	pos_old;
  int			height;
  int			width;
  int			click;
  t_color		color;
  int			in_tab;
  char			type;
  char			pencil;
  int			size;
}	t_data;

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color);
void	tekline(t_bunny_pixelarray	*pix,
		t_bunny_position	*pos,
		t_color			*color);
void	tekpaint(t_bunny_pixelarray	*pix,
		 t_color		*color);
void	left(t_data *data);
void	right(t_data *data);
void	up(t_data *data);
void	down(t_data *data);
t_bunny_response	mouse(t_bunny_position	*relativ,
			      void		*my_data);
t_bunny_pixelarray	*load_bitmap(const char	*file);
void	       	tekcircle(t_bunny_pixelarray	*pix,
			  t_bunny_position	*pos,
			  t_color		*color,
			  int			r);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int     my_putnbr_unsigned(unsigned int nb);
int	my_put_nbr_base(int nb, char *str);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
void	set_my_heap_size(size_t);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	sum_stdarg(int i, int nb, ...);
int	disp_stdarg(char *s, ...);
int	my_putnbr_bin(int nb);
int	my_putnbr_base(int nbr, char *base);
int	my_is_printable_char(char *str);
int     my_printf(char *arg, ...);
int     my_putnbr_base_size(size_t nbr, char *base);
int	chek_flags(va_list ap, char arg);
int     my_printf_p(size_t pointer);
int     my_printf_x(int arg, int type);
int     my_printf_S(char *str);
void	my_printchar(va_list ap);
void	my_printstr(va_list ap);
void	my_printnbr(va_list ap);
void	my_printnbr_unsigned(va_list ap);
void	my_print_S(va_list ap);
void	my_print_p(va_list ap);
void	my_print_base(va_list ap);
void	my_print_x(va_list ap);
void	my_print_pourcent(va_list ap);
void	my_print_b(va_list ap);
void	teksquare(t_bunny_pixelarray	*pix,
		  t_bunny_position	*pos,
		  t_color		*color,
		  int			r);
void	tekcircle_bis(t_bunny_pixelarray	*pix,
		      t_bunny_position		*pos,
		      t_color			*color,
		      t_list			list);

#endif
