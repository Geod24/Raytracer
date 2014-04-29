/*
** x_foncs2.c for 42sh in /home/lang_m/code/c/42sh
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon May 16 14:54:16 2011 Mathias Lang
** Last update Wed May 18 21:05:36 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<stdarg.h>

void	my_free(void *ptr1, ...)
{
  va_list	ap;
  void		*r_ptr;

  va_start(ap, ptr1);
  free(ptr1);
  while ((r_ptr = va_arg(ap, void *)) != NULL)
    free(r_ptr);
  va_end(ap);
}
