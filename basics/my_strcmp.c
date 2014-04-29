/*
** my_strcmp.c for my_strcmp in /u/all/schmer_x/rendu/piscine/Jour_06
** 
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
** 
** Started on  Mon Oct 11 14:55:42 2010 xavier schmerber
** Last update Fri Mar 11 01:14:31 2011 xavier schmerber
*/

int	my_strcmp(char *s1, char *s2)
{
  int	compt;

  compt = 0;
  while ((s1[compt] != '\0') || (s2[compt] != '\0'))
    {
      if (s1[compt] < s2[compt])
	return (-1);
      else if (s1[compt] > s2[compt])
	return (1);
      else
	compt = compt + 1;
    }
  return (0);
}
