#include <unistd.h>
// void	ft_std_in_out(int f)
// {
// 	char	buffer[29000];
// 	ssize_t	bytes_read;

// 	bytes_read = read(f, buffer, 29000);
// 	while (bytes_read > 0)
// 	{
// 		write(1, buffer, bytes_read);
// 		bytes_read = read(f, buffer, 29000);
// 	}
// }

void	ft_std_in()
{
	char	buffer[29000];
	ssize_t	bytes_read;

	bytes_read = read(0, buffer, 29000);
	while (bytes_read > 0)
	{
		bytes_read = read(0, buffer, 29000);
	}
}