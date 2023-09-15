#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

int     ft_atoi(char *str);
int     ft_strlen(const char *str);
int     ft_isalpha(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
char    *ft_strrchr(const char *s, int c);
char *ft_strchr(char *str, int c);
void    ft_bzero(void *ptr, size_t n);
unsigned int    ft_strlcpy(char *dest, char *src, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int  ft_isalnum(int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memset(void *ptr, int value, size_t num);
void *ft_memchr(const void *s, int c, size_t n);
//void    *ft_memmove(void *dest, const void *src, size_t n);
char *strnstr(const char *haystack, const char *needle, size_t len);
int     ft_toupper(int c);
int     ft_tolower(int c);
size_t     ft_strlcat(char *dst, const char *src, size_t size);
char *ft_strdup(const char *s1);

#endif
