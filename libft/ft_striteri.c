

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;

	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
	}
}
