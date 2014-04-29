/*
** my_putchar.c for libmy in /u/all/lang_m/rendu/piscine/Jour_07
** 
** Made by mathias lang
** Login   <lang_m@epitech.net>
** 
** Started on  Wed Oct 13 00:29:37 2010 mathias lang
** Last update Fri Jun  3 19:05:30 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	"rt.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
  return (1);
}

int	my_putstr(char *str)
{
  int	count;

  count = my_strlen(str);
  if (-1 == write(1, str, count))
    exit(EXIT_FAILURE);
  return (count);
}
