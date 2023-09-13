int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || \
		(c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*int	main()
{
	int c = 65;

	printf("%d",ft_isalpha(c));
}*/
