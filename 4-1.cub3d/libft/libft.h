/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:05:14 by sumilee           #+#    #+#             */
/*   Updated: 2024/03/30 16:24:07 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}				t_lst;

typedef struct s_data
{
	char	*buff;
	char	*ret;
	size_t	len;
	size_t	alloc_len;
	int		n;
}				t_data;

char	*ft_pos(int n, int cnt);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
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
void	ft_lstadd_front(t_list **lst, t_list *newlst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *s, ...);
int		print_index(const char *s, va_list *ptr, int i, int *len);
int		pr_char(va_list *ptr, int *len);
int		pr_str(va_list *ptr, int *len);
int		pr_int(va_list *ptr, int *len);
int		pr_uns(va_list *ptr, int *len);
int		pr_ptr(va_list *ptr, int *len);
int		pr_uphex(va_list *ptr, int *len);
int		pr_lohex(va_list *ptr, int *len);
int		ft_putchar(char c, int *len);
int		ft_putstr(char *s, int *len);
char	*ft_unsigned_itoa(unsigned int n);

char	*get_next_line(int fd);
t_lst	*fd_scan(t_lst **fdlst, int fd);
int		first_str(t_lst *fdptr, t_data *data, int fd);
int		read_loop(t_lst *fdptr, t_data *data, int fd);
int		join(t_lst *fdptr, t_data *data, int i, int j);
char	*ft_strdup_gnl(const char *src, size_t index);
char	*ft_strcat(char *dest, char const *src);
void	clear(t_lst **head);
int		change_malloc(t_lst *fdptr, t_data *data, int read_size, int index);
void	fdnode_del(t_lst **fdlst, int indicator, int fd);

#endif
