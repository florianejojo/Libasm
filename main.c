/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:52:16 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/23 11:09:12 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


#define errno (*__error())
#define O_RDONLY 0x0000

# define test_1 ""
# define test_2 "hey"
# define test_3 "mamie"
# define test_4 "j'ai perdu ma pelotte de laine"

# define STRLEN(x)			printf("Input = '%s' | ft_strlen = %d | strlen = %d\n", x, ft_strlen(x), (int)strlen(x));
# define STRCPY(buffer,str) printf("Input = '%s' | ft_dest = '%s' | dest = '%s'\n", str, ft_strcpy(buffer, str), strcpy(buffer, str));


int		ft_strlen(char const *str);
ssize_t	ft_read(int fd, void *buf, int nbyte);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, char const *src);


void	test_write(char *str, int x, int fd)
{
	int ret;
	int ft_ret;

	printf("nb de char a ecrire = %d\n", x);
	errno = 0;
	ft_ret = ft_write(fd ,str ,x);
	printf("\n");
	printf ("ft_ret = %d | errno : %d \n", ft_ret, errno);

	
	ret = 0;
	errno = 0;
	
	ret = write(fd, str, x);
	printf("\n");
	printf ("ret = %d | errno : %d \n", ret, errno);
	printf ("----------------------------\n");
}

void	test_read(char *buffer, int x, char *file)
{
	int fd;
	int ret;
	int ret_ft;

	errno = 0;
	ret_ft = ft_read((fd = open(file, O_RDONLY)), buffer, x);
	buffer[ret_ft] = 0;
	printf ("buffer = '%s' | ft_ret = %d | errno = %d\n", buffer, ret_ft, errno);
	close (fd);

	printf("\n--close fd and open fd again--\n\n");
	errno = 0;
	ret = read((fd = open(file, O_RDONLY)), buffer, x);
	buffer[ret] = 0;
	printf ("buffer = '%s' | ret = %d | errno = %d \n", buffer, ret, errno);
	close (fd);

	printf ("----------------------------\n");
}

void	test_strdup(char *src)
{
	char *ft_dst;
	char *dst;

	printf("src = '%s'\n", src);
	
	dst = strdup(src);

	ft_dst = ft_strdup(src);
	printf ("ft_dst = '%s'| dst = '%s'\n", ft_dst, dst);
	printf ("----------------------------\n");
}

int		main(void)
{
	int i = 0;
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
	printf("========== FT_READ ===============\n");
	printf("================================\n\n");	
	test_read(buffer, -1, "");
	test_read(buffer, 5, "test.txt");
	test_read(buffer, 10, "test.txt");
	test_read(buffer, 50, "test.txt");

	printf("\n================================\n");
	printf("========== FT_WRITE ==============\n");
	printf("================================\n\n");	

	test_write(test_1, ft_strlen(test_1), 50);
	test_write(test_2, -ft_strlen(test_2), 1);
	test_write(test_3, ft_strlen(test_3), 1);
	test_write(test_4, ft_strlen(test_4), 1);

	printf("\n================================\n");
	printf("========== FT_STRCPY =============\n");
	printf("================================\n\n");	

	STRCPY(buffer, test_1);
	STRCPY(buffer, test_2);
	STRCPY(buffer, test_3);
	STRCPY(buffer, test_4);

	printf("\n================================\n");
	printf("========== FT_STRDUP =============\n");
	printf("================================\n\n");	

	test_strdup(test_1);
	test_strdup(test_2);
	test_strdup(test_3);
	test_strdup(test_4);



	return (0);
}
