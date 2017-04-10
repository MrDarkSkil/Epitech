/*
** my_strncmp.c for my_strncmp in /home/hubert_1/rendu/Piscine_C_J06/ex_07
** 
** Made by leo hubert
** Login   <hubert_1@epitech.net>
** 
** Started on  Tue Oct  6 15:19:59 2015 leo hubert
** Last update Tue Oct  6 19:46:48 2015 leo hubert
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	counter;

  counter = 0;
  while ((s1[counter] || s2[counter]) && counter < nb)
    {
      if (s1[counter] < s2[counter])
	{
	  return (0);
	}
      if (s1[counter] > s2[counter])
	{
	  return (1);
	}
	counter = counter + 1;
    }
  if ((s1[counter] < s2[counter]) && counter  < nb)
    {
      return (0);
    }
  else if ((s1[counter] > s2[counter]) && counter < nb)
    {
      return (1);
    }
  return (0);
}
