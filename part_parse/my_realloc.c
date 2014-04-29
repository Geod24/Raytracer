/*
** my_realloc.c for RT in /partage/code/c/RT/working_dir/part_parse
** 
** Made by mathias lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon Apr  4 16:39:47 2011 mathias lang
** Last update Fri Jun  3 19:47:49 2011 Mathias Lang
*/
#include	<strings.h>
#include	<stddef.h>
#include	"rt.h"

void	*my_realloc(char *ptr, int size)
{
  char	*new;
  int	i;

  i = 0;
  new = cx_malloc(size);
  bzero(new, size);
  if (ptr != NULL)
    while (i < size)
      {
	new[i] = ptr[i];
	i++;
      }
  return (new);
}
