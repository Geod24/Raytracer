/*
** my_put_nbr.c for my_put_nbr in /u/all/schmer_x/rendu/piscine/Jour_10/do-op
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Mon Oct 18 22:01:05 2010 xavier schmerber
** Last update Thu May 12 12:35:39 2011 xavier schmerber
*/
#include "../headers/rt.h"

void	my_put_nbr(int nb)
{
  int	puissance;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  puissance = 1;
  while ((nb / puissance) > 9)
    puissance = puissance * 10;
  while (puissance > 1)
    {
      my_putchar(nb / puissance + '0');
      nb = nb % puissance;
      puissance = puissance / 10;
    }
  my_putchar(nb % 10 + '0');
}
