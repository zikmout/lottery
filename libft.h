/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:32:48 by ssicard           #+#    #+#             */
/*   Updated: 2016/06/03 11:24:19 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# define INT_DIGITS 19
# define INT_UNS_DIGITS 21
# define BUFF_SIZE 1000

typedef struct s_list	t_list;

struct					s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
};

int						get_next_line(int const fd, char **line);
void					ft_putstr(char	*str);
void					ft_putchar(char	c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
void					ft_putnbr(long long int nbr);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isascii(int n);
int						ft_isalnum(int n);
int						ft_isprint(int n);
int						ft_atoi(const char *str);
int						ft_isalpha(int n);
int						ft_isdigit(int n);
int						ft_tolower(int n);
int						ft_toupper(int n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, void const *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
		size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strnstr(const char *str, const char *to_find,
		size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlcat(char	*dst, const char *src, size_t n);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					*ft_memalloc(size_t size);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
			char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
char					*ft_strjoin(char const *str1, char const *str2);
char					*ft_strtrim(char const *s);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						**ft_alloc_mem(int x, int y);
char					*ft_getchar_len2(char c);
char					*ft_getnbr(long long nb);
char					*ft_getwchar(wchar_t chr);
char					*ft_ibull(unsigned long long n, int base, int min);
void					ft_putnwstr(const wchar_t *str, size_t len);
void					ft_putwchar_fd(wchar_t chr, int fd);
char					*ft_strjoina(char *s1, char const c);
char					*ft_strjoinb(char const c, char *s1);
size_t					ft_wcslen(wchar_t *str);
size_t					ft_cslen(wchar_t wc);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstpush_back(t_list **alst, t_list *new);
void					ft_push_back(t_list **head, void const *content,
		size_t content_size);
t_list					*ft_list_end(t_list *lst);
t_list					*ft_merge(t_list *lg, t_list *ld);
t_list					*ft_split(t_list *list);
void					ft_make_sort(t_list **head);

#endif
