#include <errno.h>
#include <libgen.h> 
#include <string.h>

int	ft_strlen(char *str);

void	print_error(char *prog_name, char *file_name)
{
	write(2, basename(prog_name), ft_strlen(basename(prog_name)));
	write(2, ": ", 2);
	write(2, file_name, strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}