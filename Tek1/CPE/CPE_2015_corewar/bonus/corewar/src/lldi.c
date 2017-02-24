/*
** lldi.c for lldi.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 16:22:45 2016 Antoine Roig
** Last update Sun Mar 27 00:20:01 2016 Eric DESCHODT
*/

#include "corewar.h"

int		lldi2(t_args *arg,
		      t_champ *champ,
		      unsigned char board[2][MEM_SIZE],
		      t_byte uni)
{
  int		i;

  i = -1;
  while (++i < 4)
    {
      champ->reg[arg[2].val - 1][i] = *champ->instru;
      moving_PC(champ, board[0], 1);
    }
  i = -1;
  while (++i < 4)
    moving_PC(champ, board[0], -1);
  if (uni.full < 0)
    while (++i < uni.full)
      moving_PC(champ, board[0], 1);
  else
    while (++i < uni.full)
      moving_PC(champ, board[0], -1);
  return (0);
}

int		lldi(t_args *arg,
		     void *_champ,
		     unsigned char board[2][MEM_SIZE])
{
  t_byte        uni;
  t_byte        uni1;
  int           i;
  t_champ       *champ;

  champ = _champ;
  swap_carry(champ);
  if (arg[2].val <= 0 || arg[2].val > REG_NUMBER)
    return (0);
  i = -1;
  uni.full = arg[0].val;
  uni1.full = arg[1].val;
  uni.full = uni.full;
  uni.full += uni1.full;
  if (uni.full < 0)
    while (++i < uni.full)
      moving_PC(champ, board[0], -1);
  else
    while (++i < uni.full)
      moving_PC(champ, board[0], 1);
  return (lldi2(arg, champ, board, uni));
}
