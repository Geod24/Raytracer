/*
** error_handling.c for raytracer in /home/lang_m/code/c/RT/part_parse
** 
** Made by Mathias Lang
** Login   <lang_m@epitech.net>
** 
** Started on  Sun May  1 00:31:27 2011 Mathias Lang
** Last update Fri Jun  3 21:04:43 2011 Mathias Lang
*/
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"rt.h"

int	check_xml_begining(char *file, int *count, t_glob *glob)
{
  char	*wanted;

  if (strncmp(XML_BEGINING, file, strlen(XML_BEGINING)))
    {
      my_free(file, count, glob->universe, glob->graph, glob, NULL);
      xexit(NO_XML_VERSION);
    }
  if ((wanted = get_attr_value(file + 14)) == NULL)
    {
      my_free(file, count, glob->universe, glob->graph, glob, NULL);
      xexit("Error: Parse error when getting xml version\n");
    }
  if (strncmp(wanted, "\"1.0\"", 5))
    printf(WARN_VERSION, wanted);
  free(wanted);
  return (25);
}

void	invalid_tag(int *count, char *file, t_glob *glob)
{
  while (file[count[0] + count[2]] && file[count[0] + count[2]] != '>')
    count[2]++;
  xwrite(2, "Error: unexpected tag: ");
  write(2, (file + count[0]), count[2] + 1);
  my_putchar('\n');
  free_and_quit(glob, file, count);
}

static void	base_expected(t_glob *glob, char *file, int *count, char **bal)
{
  while (NO_NXT(file[count[0] + count[2]]))
    count[2]++;
  xwrite(2, "Error: Invalid tag \"");
  write(2, (file + count[0]), count[2]);
  xwrite(2, "\", expected base attribute instead.\n");
  free(bal);
  free_and_quit(glob, file, count);
}

/* This if handle the error case of tag with attributes
   when they don't need them. We're just skipping the attribute(s),
   printing a warning including the tag name. */

# define NO_BASE_TAG	(strncmp("base", file + count[0], 4)		\
			 && strncmp("BASE", file + count[0], 4))

void	gere_args(t_glob *glob, int *count, char *file)
{
  char **balises;

  balises = init_balises();
  if (count[1] != 0 && count[1] != 10)
    {
      while (file[count[0]] == ' ' && (count[0]++ || 1));
      if (file[count[0]] && file[count[0]] != '>' && count[0]++)
	printf(WARN_ATTR, balises[count[1]]);
      else
	while (file[count[0]] && file[count[0]] != '>' && count[0]++);
    }
  else
    {
      count[0] += my_strlen(balises[count[1]]);
      while (file[count[0]] == ' ' && (count[0]++ || 1));
      if (count[1] == 10)
	{
	  if (NO_BASE_TAG || (NO_BASE_TAG && NO_NXT(file[count[0] + 1])))
	    base_expected(glob, file, count, balises);
	}
    }
  free(balises);
}
