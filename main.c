/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:52:16 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/18 23:28:07 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define test_1 ""
# define test_2 "hey"
# define test_3 "mamie"
# define test_4 "j'ai perdu ma pelotte de laine"

# define STRLEN(x)			printf("Input = '%s' | ft_strlen = %d | strlen = %d\n", x, ft_strlen(x), (int)strlen(x));
# define WRITE(str, x)		printf("\n ft_write = \n"); \
							ft_write(0,str,x); \
							printf("\n write = \n"); \
							write(0,str,x); printf("\n");

int		ft_strlen(char const *str);
ssize_t	ft_read(int fd, void *buf, int nbyte);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

void	test_write(char *str, int x)
{
	printf("ft_write avec x = %d\n", x);
	ft_write(0 ,str ,x);
	printf("\n");
	printf("write avec x = %d\n", x);
	write(0, str, x);
	printf("\n");
}

void	test_read(char *buffer, int x)
{
	int fd;
	int ret;
	int ret_ft;

	ret_ft = ft_read((fd = open("test.txt", O_RDONLY)), buffer, x);
	buffer[ret_ft] = 0;
	printf ("buffer = '%s' | ft_ret = %d\n", buffer, ret_ft);
	close (fd);

	printf("\n--close fd and open fd again--\n\n");

	ret = read((fd = open("test.txt", O_RDONLY)), buffer, x);
	buffer[ret] = 0;
	printf ("buffer = '%s' | ret = %d\n", buffer, ret);
	close (fd);
}

int		main(void)
{
	int i;
	char	buffer[100];


	while (i < 100)
		buffer[i++] = 0;

	printf("\n================================\n");
	printf("========== FT_STRLEN =============\n");
	printf("================================\n\n");
	STRLEN(test_1);
	STRLEN(test_2);
	STRLEN(test_3);
	STRLEN(test_4);
	printf("\n\n");

	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");	
	test_read(buffer, 1);
	test_read(buffer, 5);
	test_read(buffer, 10);
	test_read(buffer, 50);

	printf("\n================================\n");
	printf("========== FT_WRITE =============\n");
	printf("================================\n\n");	

	test_write(test_1, ft_strlen(test_1));
	test_write(test_2, ft_strlen(test_2) -2);
	test_write(test_3, ft_strlen(test_3) );
	test_write(test_4, ft_strlen(test_4));
	printf("\n\n");


	
	return (0);
}
