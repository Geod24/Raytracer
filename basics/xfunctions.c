/*
** xexit.c for xlib in /home/lang_m/code/lib/xlib
** 
** Made by mathias lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon Jan 31 23:34:06 2011 mathias lang
** Last update Fri Jun  3 19:11:25 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	"rt.h"

void	xexit(char *mess)
{
  write(2, mess, my_strlen(mess));
  exit(EXIT_FAILURE);
}

int	xwrite(int fd, char *buf)
{
  int	ret;

  if ((ret = write(fd, buf, my_strlen(buf))) == -1)
    exit(EXIT_FAILURE);
  return (ret);
}

int	xread(int fd, char *buf, int count)
{
  int	ret;

  if ((ret = read(fd, buf, count)) == -1)
    {
      my_putstr("Error when reading\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	xclose(int fd)
{
  if (close(fd) == -1)
    xexit("Error when closing a file descriptor.\n");
}
