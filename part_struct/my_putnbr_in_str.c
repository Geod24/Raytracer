/*
** my_putnbr_in_str.c for rt in /home/klein_e//Project/tek1/igraph/RT_final/TraceMyRay/part_struct
**
** Made by eric klein
** Login   <klein_e@epitech.net>
**
** Started on  Thu Apr 28 20:31:50 2011 eric klein
** Last update Fri Jun  3 20:14:44 2011 xavier schmerber
*/
#include	"rt.h"

char	*my_putnbr_in_str(int nb)
{
  int	puissance;
  char	*str;
  int	i;

  str = cx_malloc(sizeof(char) * 12);
  i = 0;
  if (nb < 0)
    {
      str[i++] = '-';
      nb = nb * -1;
    }
  puissance = 1;
  while ((nb / puissance) > 9)
    puissance = puissance * 10;
  while (puissance > 1)
    {
      str[i++] = (nb / puissance + '0');
      nb = nb % puissance;
      puissance = puissance / 10;
    }
  str[i++] = (nb / puissance + '0');
  return (str);
}
