/*
** str_utils.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:20:56 2011 Mathias Lang
** Last update Fri Jun  3 19:58:14 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	<stdio.h>
#include	"rt.h"

# define IS_SPACE(chr)	(chr == ' ' || chr == '\t' || chr == '\n')
# define COMMENT_SIZE	strlen("<?comment")

char	*clean_str(char *str)
{
  int	len;
  int	i[2];
  char	*ret;

  bzero(i, sizeof(int) * 2);
  ret = cx_malloc((len = strlen(str)) * sizeof(char));
  while (i[0] < len)
    {
      if (!strncmp(str + i[0], "<?comment", COMMENT_SIZE)
	  && IS_SPACE(str[i[0] + 9]))
	{
	  i[0] += COMMENT_SIZE + 1;
	  while (str[i[0]] && (str[i[0]] != '?' || str[i[0] + 1] != '>'))
	    i[0] += 1;
	  if ((!str[i[0]]) || (!str[i[0] + 1]))
	    xexit(COMMENT_ERR);
	  i[0] += 2;
	}
      while (PCHAR(str[i[0]]) && PCHAR(str[i[0] + 1]))
	i[0] += 1;
      ret[i[1]++] = (PCHAR(str[i[0]])) ? (' ') : (str[i[0]]);
      i[0]++;
    }
  free(str);
  return (ret);
}
