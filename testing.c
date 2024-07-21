#include "testing.h"
#include "get_next_line.h"

void	title_of_test(char *title)
{
	int	length = strlen(title);
	int	i;

	printf("\n\n");
	i = 0;
	while (i < length)
	{
		printf("=");
		i++;
	}
	printf("\n%s\n", title);
}

int	get_lines_till_NULL(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	printf("%s", line);
	return (0);
}

void	test_read_from_stdin(void) // TODO
{
	title_of_test("READ FROM STDIN");
	printf("\n");
	char	*line;
	int	fd = 1;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	printf("%s", line);
}

void	test_gnl(char *file, char *testname)
{
	int	fd = open(file, O_RDONLY);
	
	title_of_test(testname);
	printf("\n");
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

int	main(void)
{
	test_gnl("testfiles/big.txt", "BIG FILE");
	test_gnl("testfiles/long.txt", "LONG FILE");
	test_gnl("testfiles/nope", "WRONG FILE DESCRIPTOR");
	test_gnl("testfiles/medium.txt", "MEDIUM FILE");
	test_gnl("testfiles/empty.txt", "EMPTY FILE");
	test_gnl("testfiles/small.txt", "SMALL FILE");
	test_gnl("testfiles/char.txt", "ONE CHAR");
	// test_read_from_stdin();
	return (0);
}
