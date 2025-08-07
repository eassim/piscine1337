#ifndef FT_H

#define FT_h

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
char *ft_strpy(char *s1, char *s2);
char *ft_strcat(char *s1, char *s2);
char *ft_strdup(char *s1);
char *ft_strjoin(char **str, char *sep);

int ft_atoi(char *str);
int ft_atoibase(char *str, char *base);
void ft_putnbrbase(int nbr, char *base);
char *ft_retnbrbase(int nbr, char *base);
char *ft_convert_base(char *str, char *base_from, char *base_to);

#endif
