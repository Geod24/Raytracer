/*
** get_args.c for TraceMyRay in /home/lang_m/code/c/RT
**
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
**
** Started on  Fri May 27 12:36:38 2011 Mathias Lang
** Last update Fri Jun  3 19:46:51 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"rt.h"

void	get_args(t_glob *glob, int ac, char **av)
{
  const char	*res[] = AV_FLAGS;
  int		cnt[2];

  cnt[0] = 2;
  if (!glob || !glob->option)
    put_error("Fatal error.\n", 1);
  while (cnt[0] < ac)
    {
      cnt[1] = 0;
      while (res[cnt[1]] &&
	     strncmp(av[cnt[0]], res[cnt[1]], strlen(res[cnt[1]])))
	cnt[1]++;
      if (res[cnt[1]])
	glob->option->options |= (1 << cnt[1]);
      else
	{
	  fprintf(stderr, "%s: Invalid argument '%s'.\n", av[0], av[cnt[0]]);
	  exit(EXIT_FAILURE);
	}
      cnt[0]++;
    }
}
