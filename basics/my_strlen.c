/*
** my_strlen.c for my_ls in /home/schmer_x//unix/my_ls
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Tue Dec 14 17:24:17 2010 xavier schmerber
** Last update Wed Mar  9 17:39:41 2011 xavier schmerber
*/

int	my_strlen(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    c = c + 1;
  return (c);
}
