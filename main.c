/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:43:49 by kkamashi          #+#    #+#             */
/*   Updated: 2021/03/06 18:52:31 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libasm.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf_red("\n-------------- EXAMPLE --------------\n\n");
		printf_cyan("            [./main strlen]          \n");
		printf_cyan("            [./main strcpy]          \n");
		printf_cyan("            [./main strcmp]          \n");
		printf_cyan("            [./main write]          \n");
		printf_cyan("            [./main read]          \n");
		printf_cyan("            [./main strdup]          \n");
		printf_red("\n---------------  END  ---------------\n\n");
		return (0);
	}
	if (argc == 2 && strcmp(argv[1], "strlen") == 0)
	{
		printf_yellow("\n------------ FT_STRLEN ------------\n\n");
		test_ft_strlen(1, "hello world", "hello world");
		test_ft_strlen(2, "0123456789", "0123456789");
		test_ft_strlen(3, "EMPTY", "");
		test_ft_strlen(4, "\\0", "\0");
		test_ft_strlen(5, "\\n", "\n");
		test_ft_strlen(6, "SPACES", "                ");
		test_ft_strlen(7, "TABS", "										");
		test_ft_strlen(8, "LONG STRING", LONG_STRING);
		test_ft_strlen(9, "REALLY LONG STRING", REALLY_LONG_STRING);
		test_ft_strlen(9, "null", NULL);
	}
	else if (argc == 2 && strcmp(argv[1], "strcpy") == 0)
	{
		printf_yellow("\n------------ FT_STRCPY ------------\n\n");
		test_ft_strcpy(1, "Hello World", "Hello World");
		test_ft_strcpy(2, "EMPTY", "");
		test_ft_strcpy(3, "\\n", "\n");
		test_ft_strcpy(4, "\\0", "\0");
		test_ft_strcpy(5, "SPACES", "        ");
		test_ft_strcpy(6, "TABS", "						");
		test_ft_strcpy(7, "abc\\0def", "abc\0def");
		test_ft_strcpy(8, "LONG STRING", LONG_STRING);
		test_ft_strcpy(9, "REALLY LONG STRING", REALLY_LONG_STRING);
	}
	else if (argc == 2 && strcmp(argv[1], "strcmp") == 0)
	{
		printf_yellow("\n------------ FT_STRCMP ------------\n\n");
		test_ft_strcmp(1, "0123456789", "0123456789");
		test_ft_strcmp(2, "", "");
		test_ft_strcmp(3, "\0", "\0");
		test_ft_strcmp(4, "\n", "\n");
		test_ft_strcmp(5, "        ", "        ");
		test_ft_strcmp(6, "				", "			");
		test_ft_strcmp(7, "abc", "abce");
		test_ft_strcmp(8, "xyz", "xy");
		test_ft_strcmp(9, "xyz", "xy");
		test_ft_strcmp(10, "ABC", "B");
		test_ft_strcmp(11, "B", "ABCD");
		test_ft_strcmp(12, "AAAA", "ABC");
		test_ft_strcmp(13, "abc", "");
		test_ft_strcmp(14, "", "abc");
	}
	else if (argc == 2 && strcmp(argv[1], "write") == 0)
	{
		printf_yellow("\n------------ FT_WRITE ------------\n\n");
		int		fd_write;
		int		fd_ft_write;
		char	*buffer;

		if (!(buffer = ft_strdup("HELLO WORLD!")))
		{
			return (1);
		}
		fd_write = open("write.txt", O_WRONLY);
		fd_ft_write = open("ft_write.txt", O_WRONLY);
		test_ft_write(1, fd_write, fd_ft_write, buffer);
		close(fd_write);
		close(fd_ft_write);
		free(buffer);

		if (!(buffer = ft_strdup(LONG_STRING)))
		{
			return (1);
		}
		fd_write = open("write_long.txt", O_WRONLY);
		fd_ft_write = open("ft_write_long.txt", O_WRONLY);
		test_ft_write(2, fd_write, fd_ft_write, buffer);
		close(fd_write);
		close(fd_ft_write);
		free(buffer);

		if (!(buffer = ft_strdup("HELLO WORLD!")))
		{
			return (1);
		}
		fd_write = open("write.txt", O_RDONLY);
		fd_ft_write = open("ft_write.txt", O_RDONLY);
		test_ft_write(3, fd_write, fd_ft_write, buffer);
		close(fd_write);
		close(fd_ft_write);
		free(buffer);

		if (!(buffer = ft_strdup("HELLO WORLD!")))
		{
			return (1);
		}
		fd_write = 42;
		fd_ft_write = 42;
		test_ft_write(4, fd_write, fd_ft_write, buffer);
		close(fd_write);
		close(fd_ft_write);
		free(buffer);

		// STDOUT
		if (!(buffer = ft_strdup("HELLO WORLD!\n")))
		{
			return (1);
		}
		fd_write = 1;
		fd_ft_write = 1;
		test_ft_write(5, fd_write, fd_ft_write, buffer);
		close(fd_write);
		close(fd_ft_write);
		free(buffer);

		buffer = NULL;
	}
	else if (argc == 2 && strcmp(argv[1], "read") == 0)
	{
		printf_yellow("\n------------ FT_READ ------------\n\n");
		int fd_read;
		int fd_ft_read;

		fd_read = open("read.txt", O_RDONLY);
		fd_ft_read = open("ft_read.txt", O_RDONLY);
		test_ft_read(1, fd_read, fd_ft_read);
		close(fd_read);
		close(fd_ft_read);

		fd_read = open("read_long.txt", O_RDONLY);
		fd_ft_read = open("ft_read_long.txt", O_RDONLY);
		test_ft_read(2, fd_read, fd_ft_read);
		close(fd_read);
		close(fd_ft_read);

		fd_read = open("read.txt", O_WRONLY);
		fd_ft_read = open("ft_read.txt", O_WRONLY);
		test_ft_read(3, fd_read, fd_ft_read);
		close(fd_read);
		close(fd_ft_read);

		fd_read = 42;
		fd_ft_read = 42;
		test_ft_read(4, fd_read, fd_ft_read);
		close(fd_read);
		close(fd_ft_read);

		fd_read = 0;
		fd_ft_read = 0;
		test_ft_read(5, fd_read, fd_ft_read);
		close(fd_read);
		close(fd_ft_read);
	}
	else if (argc == 2 && strcmp(argv[1], "strdup") == 0)
	{
		printf_yellow("\n------------ FT_STRDUP ------------\n\n");
		test_ft_strdup(1, "Hello World", "Hello World");
		test_ft_strdup(2, "EMPTY", "");
		test_ft_strdup(3, "\\0", "\0");
		test_ft_strdup(4, "\\n", "\n");
		test_ft_strdup(5, "SPACES", "       ");
		test_ft_strdup(6, "TABS", "				");
		test_ft_strdup(7, "LONG STRING", LONG_STRING);
		test_ft_strdup(8, "REALLY LONG STRING", REALLY_LONG_STRING);
	}
	printf_yellow("\n------------    END    ------------\n\n");
	return (0);
}

/*
** FT_STRLEN.S
*/

void test_ft_strlen(int num, const char *title, const char *target)
{
	size_t ret_value_lib = strlen(target);
	size_t ret_value_asm = ft_strlen(target);

	printf("TEST[%d]: TARGET = [%s]\n", num, title);
	printf("[LIB]: [%zu]\n", ret_value_lib);
	printf("[ASM]: [%zu]\n", ret_value_asm);

	if (ret_value_lib == ret_value_asm)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}
	printf("\n");
}

/*
** FT_STRCPY.S
*/

void test_ft_strcpy(int num, const char *title, const char *src)
{
	char *dest_lib = calloc(sizeof(char), (strlen(src) + 10));
	char *dest_asm = calloc(sizeof(char), (strlen(src) + 10));
	char *ret_lib = strcpy(dest_lib, src);
	char *ret_asm = ft_strcpy(dest_asm, src);

	printf("TEST[%d]: DEST = [ft_strlen(src) + 10], SRC = [%s]\n", num, title);
	printf("[LIB]: [%s]\n", ret_lib);
	printf("[ASM]: [%s]\n", ret_asm);

	if (strcmp(ret_lib, ret_asm) == 0)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}
	free(dest_lib);
	dest_lib = NULL;
	free(dest_asm);
	dest_asm = NULL;

	printf("\n");
}

/*
** FT_STRCMP.S
*/

void test_ft_strcmp(int num, const char *str1, const char *str2)
{
	int ret_value_lib = strcmp(str1, str2);
	int ret_value_asm = ft_strcmp(str1, str2);

	printf("TEST[%d]: STR1 = [%s], STR2 = [%s]\n", num, str1, str2);
	printf("[LIB]: [%d]\n", ret_value_lib);
	printf("[ASM]: [%d]\n", ret_value_asm);

	if (ret_value_lib == ret_value_asm)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}

	printf("\n");
}

/*
** FT_WRITE.S
*/

static void	print_error_state(void)
{
	printf_red("[ERRNO]");
	printf(" = [%d: %s]\n", errno, strerror(errno));
	errno = 0;
	return ;
}

void	test_ft_write(int num, int fd_write, int fd_ft_write, char *buffer)
{
	int		ret_value_lib;
	int		ret_value_asm;

	printf("TEST[%d]: buffer = [%s]\n", num, buffer);

	ret_value_lib = write(fd_write, buffer, strlen(buffer));
	if (ret_value_lib == -1)
	{
		printf("[LIB]: ");
		print_error_state();
	}
	ret_value_asm = ft_write(fd_ft_write, buffer, strlen(buffer));
	if (ret_value_asm == -1)
	{
		printf("[ASM]: ");
		print_error_state();
	}

	printf("[LIB]: [%d]\n", ret_value_lib);
	printf("[ASM]: [%d]\n", ret_value_asm);

	if (ret_value_lib == ret_value_asm)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}
	printf("\n");
}

/*
** FT_READ.S
*/

void	test_ft_read(int num, int fd_read, int fd_ft_read)
{
	int		ret_value_lib;
	int		ret_value_asm;
	char	*buffer_read;
	char	*buffer_ft_read;

	if (!(buffer_read = (char *)malloc(sizeof(char) * 1000)))
	{
		return ;
	}
	if (!(buffer_ft_read = (char *)malloc(sizeof(char) * 1000)))
	{
		return ;
	}
	printf("TEST[%d]: fd_read = [%d], fd_ft_read= [%d]\n", num, fd_read, fd_ft_read);
	ret_value_lib = read(fd_read, buffer_read, 1000);
	printf("[LIB]: ");
	printf("ret_vale = %d, buffer = [%s]\n", ret_value_lib, buffer_read);
	if (ret_value_lib == -1)
	{
		print_error_state();
	}
	ret_value_asm = ft_read(fd_ft_read, buffer_ft_read, 1000);
	printf("[ASM]: ");
	printf("ret_vale = %d, buffer = [%s]\n", ret_value_asm, buffer_ft_read);
	if (ret_value_asm == -1)
	{
		print_error_state();
	}

	if (ret_value_lib == ret_value_asm)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}
	printf("\n");
	free(buffer_read);
	buffer_read = NULL;
	free(buffer_ft_read);
	buffer_ft_read = NULL;
}

/*
** FT_STRDUP.S
*/

void	test_ft_strdup(int num, char *title, char *str)
{
	char *ret_lib = strdup(str);
	char *ret_asm = ft_strdup(str);

	printf("TEST[%d]: STR = [%s]\n", num, title);
	printf("[LIB]: [%s]\n", ret_lib);
	printf("[ASM]: [%s]\n", ret_asm);

	if (strcmp(ret_lib, ret_asm) == 0)
	{
		printf_blue("[PASS]\n");
	}
	else
	{
		printf_red("[FAIL]\n");
	}
	free(ret_lib);
	ret_lib = NULL;
	free(ret_asm);
	ret_asm = NULL;

	printf("\n");
}

/*
** PINRTF WITH COLOR
*/

void	printf_red(const char *str)
{
	printf("%s", RED);
	printf("%s", str);
	printf("%s", RESET);
}

void	printf_blue(const char *str)
{
	printf("%s", BLUE);
	printf("%s", str);
	printf("%s", RESET);
}

void	printf_yellow(const char *str)
{
	printf("%s", YELLOW);
	printf("%s", str);
	printf("%s", RESET);
}

void	printf_cyan(const char *str)
{
	printf("%s", CYAN);
	printf("%s", str);
	printf("%s", RESET);
}

void	printf_green(const char *str)
{
	printf("%s", GREEN);
	printf("%s", str);
	printf("%s", RESET);
}
