/*
** my_getnbr_base.c for my_getnbr_base in /u/all/schmer_x/rendu/piscine/Jour_06
**
** Made by xavier schmerber
** Login   <schmer_x@epitech.net>
**
** Started on  Tue Oct 12 15:21:57 2010 xavier schmerber
** Last update Fri Mar 11 01:06:09 2011 xavier schmerber
*/

int	add_nbr(char *str, char *base, int power, int base_nbr)
{
  int	nbr;
  int	count;
  int	power_nb;
  int	chiffre;

  nbr = 0;
  count = 0;
  power_nb = 1;
  while (power > 0)
    {
      power_nb = power_nb * base_nbr;
      power = power - 1;
    }
  while (str[count] != '\0')
    {
      chiffre = 0;
      while (str[count] != base[chiffre])
	chiffre = chiffre + 1;
      nbr = nbr + chiffre * power_nb;
      power_nb = power_nb / base_nbr;
      count = count + 1;
    }
  return (nbr);
}

void	nbr_power(char *str, int *power)
{
  while (str[*power] != '\0')
    *power = *power + 1;
}

int	my_getnbr_base(char *str, char *base)
{
  int	nbr;
  int	power;
  int	base_nbr;
  int	test;

  nbr = 0;
  power = 0;
  base_nbr = 0;
  test = 0;
  if (str[0] == '-')
    {
      test = 1;
      str = str + 1;
    }
  nbr_power(str, &power);
  power = power - 1;
  while (base[base_nbr] != '\0')
    base_nbr = base_nbr + 1;
  nbr = add_nbr(str, base, power, base_nbr);
  if (test == 1)
    nbr = - nbr;
  return (nbr);
}
