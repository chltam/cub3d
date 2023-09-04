/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:41:46 by cbadura           #+#    #+#             */
/*   Updated: 2023/06/22 16:47:29 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	void			*var_name;
	void			*var_str;
	void			*cmd;
	struct s_list	*next;
}					t_list;

int		ft_isalnum(char c);
int		ft_isalpha(int c);
int		ft_isascii(char c);
int		ft_isdigit(char c);
int		ft_isprint(char c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *s, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dest, char *src);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strcpy(char	*dest, char	*src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtok(char *str, char *delim);
char	*ft_strjoin_free_s1(char *s1, char *s2);
char	*ft_strjoin_free_s2(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);

int		ft_printf(const char *format, ...);
int		print_int(int arg);
int		print_unsigned(unsigned int arg);
int		print_string(char *arg);
int		print_char(char arg);
int		print_hex(unsigned int hex, char mode);
int		print_ptr(void *arg);
int		print_percent(void);

#endif
