#include "testing.h"
#include "get_next_line.h"

void	title_of_test(char *title)
{
	int	length = strlen(title);
	int	i;

	printf("\n");
	i = 0;
	while (i < length)
	{
		printf("=");
		i++;
	}
	printf("\n%s\n", title);
	printf("test result:\t");
}

int	get_lines_till_NULL(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	printf("[%s]", line);
	return (0);
}

void	test_wrong_fd(void)
{
	int	fd = open("../source_files/wrong", O_RDONLY);
	char	*line;

	title_of_test("WRONG FILE DESCRIPTOR");
	line = get_next_line(fd);
	if (line == NULL)
		printf("ok\n");
	else
	{
		printf("nope\n");
	}
	/* DETAILS
	printf("input get_next_line ==> %d\n", fd);
	printf("output get_next_line ==> %s\n", line);
	*/
	close(fd);
}

void	test_read_from_stdin(void) // TODO
{
	title_of_test("READ FROM STDIN");
	printf("\n");
}

void	print_gnl(int fd, int lines)
{
	while (0 < lines)
	{
		printf("%s", get_next_line(fd));
		lines--;
	}
}

void	test_gnl(char *file, char *testname)
{
	int	fd = open(file, O_RDONLY);
	
	title_of_test(testname);
	printf("\n");
	/* DETAILS
	*/
	// print_gnl(fd, 6);
	get_lines_till_NULL(fd);
	close(fd);
}

void	display_list(t_list *list)
{
	t_list	*current;

	current = list;
	printf("---start of list\n");
	while (current)
	{
		printf("%s\n", current->str);
		current = current->next;
	}
	printf("---end of list\n");
}

void	test_read_file_medium(void)
{
	int	fd = open("testfiles/medium.txt", O_RDONLY);

	title_of_test("MEDIUM FILE");
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("[%s]", get_next_line(fd));
	if (get_next_line(fd) == NULL)
		printf("\n\nok"); 
	else
		printf("\n\nnope"); 
	close(fd);
}
void	test_read_file_empty(void)
{
	int	fd = open("testfiles/empty.txt", O_RDONLY);

	title_of_test("EMPTY FILE");
	printf("\n");
	printf("%s\n", get_next_line(fd));
	close(fd);
}
void	test_read_file_small(void)
{
	int	fd = open("testfiles/small.txt", O_RDONLY);

	title_of_test("SMALL FILE");
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
void	test_read_file_big(void)
{
	int	fd = open("testfiles/big.txt", O_RDONLY);
	char	*line;

	title_of_test("BIG FILE");
	printf("\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	close(fd);
}

int	main(void)
{
	/*
	*/
	// test_read_file_big();
	// test_read_file_medium();
	// test_read_file_small();
	// test_read_file_empty();
	test_gnl("testfiles/big.txt", "BIG FILE");
	test_wrong_fd();
	// test_read_from_stdin();
	test_gnl("testfiles/medium.txt", "MEDIUM FILE");
	test_gnl("testfiles/empty.txt", "EMPTY FILE");
	test_gnl("testfiles/small.txt", "SMALL FILE");
	test_gnl("testfiles/char.txt", "ONE CHAR");
	test_gnl("testfiles/long.txt", "LONG FILE");
	return (0);
}
