#include "../include/ft_printf.h"

int	main(void)
{
	// CHAR
	if(test_char || test_all)
	{
	printf("\n\nCHAR\n"); 
	char t_char = 'a';
	printf("%c\n", t_char);
	ft_printf("%c", t_char);
	}

	// STRING 
	if(test_string || test_all)
	{
	printf("\n\nSTRING\n"); 
	char *t_string = "abc";
	printf("%s\n", t_string);
	ft_printf("%s", t_string);
	printf("\n\nSTRING - null\n"); 
	char *t_string_n = NULL;
	printf("%s\n", t_string_n);
	ft_printf("%s", t_string_n);
	// printf("\n\nSTRING - null 2\n"); 
	// printf(" NULL %s NULL \n", NULL);
	// ft_printf(" NULL %s NULL ", NULL);
	}
	
	// INT 
	if(test_int || test_all)
	{
	printf("\n\nINT\n");
	int t_int = 930;
	printf("%d\n", t_int);
	ft_printf("%d", t_int);
	printf("\n\nINT - min\n");
	int t_int_mx = -2147483648;
	printf("%d\n", t_int_mx);
	ft_printf("%d", t_int_mx);
	}

	// PERCENTAGE 
	if(test_percentage || test_all)
	{
	printf("\n\nPERCENTAGE\n");
	printf("100%%\n");
	ft_printf("100%%");
	}
	
	// INVALID CONVERSION 
	if(test_invalid || test_all)
	{
	int return_value;
	printf("\n\nINVALID CONVERSION\n");
	// printf("%k\n"); // INVALID
	return_value = ft_printf("%k");
	ft_printf("return value (%d)\n", return_value);
	}
	
	// UNSIGNED INT 
	if(test_unsigned || test_all)
	{
	printf("\n\nUNSIGNED INT\n"); 
	unsigned int bigger_than_signed_int = 4000000000;
	printf("%u\n", bigger_than_signed_int);
	ft_printf("%u", bigger_than_signed_int);
	printf("\n\nUNSIGNED INT - max\n"); 
	unsigned int max = 4294967295;
	printf("%u\n", max);
	ft_printf("%u", max);
	}

	// HEXA 
	if(test_hexa || test_all)
	{
	printf("\n\nHEXA\n");
	int t_hexa = 66558;
	printf("%x\n", t_hexa);
	ft_printf("%x", t_hexa);
	printf("\n\nHEXA - negative, uppercase\n");
	int t_hexa_u = -34543839;
	printf("%X\n", t_hexa_u);
	ft_printf("%X", t_hexa_u);
	}
	
	// ADDRESS 
	if(test_address || test_all)
	{
	printf("\n\nADDRESS\n");
	int t_address = 40;
	printf("%p\n", &t_address);
	ft_printf("%p", &t_address);
	printf("\n\nADDRESS - null\n");
	printf(" %p %p \n", NULL, NULL);
	ft_printf(" %p %p ", NULL, NULL);
	}
	
	return (0);
}
