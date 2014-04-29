/*
** parse_conf.c for RT in /partage/code/c/RT/working_dir/part_parse
** 
** Made by mathias lang
** Login   <lang_m@epitech.net>
** 
** Started on  Mon Apr  4 16:07:10 2011 mathias lang
** Last update Sun Jun  5 16:59:25 2011 Mathias Lang
*/
#include	<stdlib.h>
#include	<limits.h>
#include	<strings.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"rt.h"

/*
** Parser XML: On avance dans la chaine en lisant des balises 1 a 1.
** wanted ne sert a rien.
** On prend une balise, on nous retourne son type, et on agit en
** consequence.
**
** Si on ne commence pas par <?xml version ="XXX" ?> puis <RT>, on
** affiche une erreur.
**
** A chaque balise <object>, on cree un nouveau maillon.
** Si a l'appel de </object>, certains champs ne sont pas remplis,
** on affiche une erreur.
**
*/

/*
** Pre-checks: xml version, RT in/out, delete des comments.
** On aurait pu faire une fonction pour les "<?", ca aurait
** ete plus propre et plus generique, mais bon...
**
** Algo:
** Recupere la balise
**  | Si args apres, on les met dans un tableau.
**  | On stocke dans la liste chainee.
**    |=> On parse d'abord l'intra balise.
**    |=> Ensuite on parse les balise suivante.
**  | Si on rencontre EOF / </object>, on check
**    si les bons champs sont remplis.
*/

/*
** Apres reflexion, on ne gere les attributs que pour
** color et RT. Sinon on se retrouve avec des balises vides
** ne contenant que des attributs, ou dissemines.
** C'est stupide.
*/

/*
** Ce que le parseur fait actuellement:
** - Detection / suppression des commentaires, "nettoyage" du .xml
**   (On peut s'amuser a mettre tout pleins d'espaces / tab / "\n")
** - Verification que le programme commence bien par la version XML.
**   Si ce n'est pas le cas, exit. Si la version est differente de "1.0",
**   le programme affiche un warning.
** - Detection de toutes les balises. Affiche un warning si la balise
**   contient un parametre alors qu'elle ne le devrait pas. Detection
**   des parametres de RT et de color. Verification que le premier
**   parametre de color est bien "base" ou "BASE". Sinon, erreur.
**
*/

static void	speed_exit(char *file, int fd)
{
  free(file);
  xclose(fd);
  xexit(FILE_OVERSIZE);
}

static int	swap_balise(char *file)
{
  int		i;

  i = 1;
  while (file[i] && (file[i] != '>'))
    i++;
  return (i + 1);
}

# define CHECK_BAL_END	((!balises[count[1]])				\
			 || (file[count[0] + BLEN] != ' '		\
			     && file[count[0] + BLEN] != '>'))
# define FIND_BALISE	(balises[count[1]] &&				\
			 strncmp(balises[count[1]], file + count[0], BLEN))

void	clean_all(int *, char **, func_handler *, t_glob *);

static void	construct_chain(char *file, t_glob *glob)
{
  int		*count;
  char		**balises;
  func_handler	*fptr;

  balises = init_balises();
  fptr = init_fptr();
  count = cx_malloc(sizeof(int) * 6);
  count[0] = check_xml_begining(file, count, glob);
  while (file[count[0]] && !(count[1] = 0))
    {
      while (file[count[0]] == ' ' && (count[0]++ || 1));
      while (FIND_BALISE && (count[1]++ || 1));
      if (CHECK_BAL_END)
	invalid_tag(count, file, glob);
      else if (file[count[0] + BLEN] == ' ')
	gere_args(glob, count, file);
      if (count[1] != B_END(BAL_RT))
	count[0] += swap_balise(file + count[0]);
      if (!fptr[count[1]](glob, file, count))
	ID_FLAG += count[1];
      else if (count[1] == B_END(BAL_RT))
	count[0] += swap_balise(file + count[0]);
    }
  clean_all(count, balises, fptr, glob);
}

void	parse_conf(char *conf, t_glob *mom)
{
  char	*file;
  int	i;
  int	fd;

  i = 0;
  if (-1 == (fd = open(conf, O_RDONLY)))
    xexit("Error: Not able to open the file\n");
  file = cx_malloc(READ_VAL * sizeof(char));
  while (READ_VAL == xread(fd, file + (i * READ_VAL), READ_VAL))
    {
      i++;
      if (i < S_LIMIT)
	{
	  file = my_realloc(file, READ_VAL + (i * READ_VAL));
	  bzero(file + (i * READ_VAL), READ_VAL);
	}
      else
	speed_exit(file, fd);
    }
  xclose(fd);
  file = clean_str(file);
  construct_chain(file, mom);
  free(file);
}
