
#include "../inc/minishell.h"

int	main(int argc, char *argv[])
{
	t_lexer *lexer;

	lexer = NULL;
	(void)argv;
	if (argc > 1)
	{
		printf("Error\n");
	}
	receive_signal(1);
	while (1)
	{
		if (ft_operation(&lexer))
			break ;
		// line = readline("minishell$ ");
		// if (line == NULL)
		// {
		// 	printf("exit\n");
		// 	return (1);
		// }
		// if (ft_lexer(line, lexer) == 0)
		// {
		
		// 	printf("no error?");
		// 	// printf("%s", (*lexer)->value);
		// 	// if (ft_parse())
		// 	// {
		// 	//     her_doc();
		// 	//     if (!expandor())
		// 	//         executor();
		// 	// }
		// }
		// if (!ft_strncmp(line, "exit", 4))
		// {
		//     write(1, "exit\n", 5);
		//     free(line);
		//     exit(0);
		// }
		// ft_lexer(line);
	}
	// free(line);
	return (g_error);
}