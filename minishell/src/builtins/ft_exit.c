/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:11:46 by alounici          #+#    #+#             */
/*   Updated: 2024/05/30 20:13:53 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La fonction ft_exit gère plusieurs scénarios pour la commande exit dans un shell minimaliste :

// exit -- termine avec succès.
// exit "" ou un argument vide imprime une erreur et termine avec 255.
// exit N où N est un nombre termine avec le code de retour N.
// exit N1 N2 avec trop d'arguments imprime une erreur et ne termine pas immédiatement le programme, mais signale une erreur via exit_status(1).
// Cette gestion robuste permet de traiter différentes entrées utilisateur tout en fournissant des messages d'erreur clairs et appropriés.


// La fonction limit_number vérifie si une chaîne de caractères représentant un nombre dépasse les 
// limites des entiers de 64 bits signés (long en C). Elle prend en compte le signe du nombre, 
// ignore les zéros initiaux et utilise des comparaisons de chaîne pour détecter les dépassements.
//  Si le nombre dépasse les limites, un message d'erreur est affiché et le programme se termine avec
//   un code de sortie 255, assurant ainsi que seules les valeurs valides sont acceptées.

#include "../../inc/minishell.h"

void    check_exit(char *str)
{
    int i = 0;

        if ((str[i] == '-' || str[i] == '+') && str[i + 1])
            i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
        {
            print_notdigit_exit(str);
            exit(255);
        }
        i++;
    }
}

void   print_notdigit_exit(char *str)
{
    int i;

    i = 0;
    (void)str;
    write(2, "exit: ", 6);
    while(str[i])
            write(2, &str[i++], 1);
    write(2, ": numeric argument required", 28);
}

void print_limit_exit(char *str)
{
    int i;

    i = 0;
    (void)str;
    write(2, "exit: ", 6);
    while(str[i])
            write(2, &str[i++], 1);
    write(2, ": numeric argument required", 27);
}

void check_limit(char *str)
{
    int neg;
    int i;

    i = 0;
    neg = 0;
    if (*str == '-')
    {
        str++;
        neg = 1;
    }
    if (ft_strlen(str) > 19)
    {
        print_limit_exit(str);
    }
    else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0 && !neg)
	{
        print_limit_exit(str);
    }
	else if (ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775808") > 0 && neg)
    {
        print_limit_exit(str);
    }
    else
        return;
    exit (255);
}

void ft_exit(char **args)
{
    
    if (args[1] == NULL || ft_strcmp(args[1], "--") == 0)
    {
        // write(2, "exit\n", 5);
        exit(0);
    }
    else if (!args[1][0])
    {
        write(2, "exit: : numeric argument required", 33);
        exit (255);
    }
    else if (args[1] && args[2])
    {
        write(2, "exit: too many arguments", 24);
        exit (1);
    }
    else if (args[1])
    {
        check_exit(args[1]);
        check_limit(args[1]);
    }
        // write(1, "ici", 3);
    // write(2, "exit\n", 5);
    exit (ft_atoi(args[1]));
}