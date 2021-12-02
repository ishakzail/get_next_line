#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	else
	{
		while (*(char *)s1 != '\0')
		{
			str[i] = *(char *)s1++;
			i++;
		}
		while (*(char *)s2 != '\0')
		{
			str[i] = *(char *)s2++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}


static size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    unsigned int    i;

    i = 0;
    if (dstsize > 0)
    {
        while (--dstsize && src[i])
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (i);
}

static char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t    s_len;

    if (!s)
        return (0);
    s_len = strlen((char *)s);
    if (start > s_len)
        return ("");
    if (s_len - start >= len)
        str = (char *)malloc((len + 1) * sizeof(char));
    else
        str = (char *)malloc((s_len - start + 1) * sizeof(char));
    if (!str)
        return (0);
    ft_strlcpy(str, (s + start), (len + 1));
    return (str);
}
static char    *ft_get_line(char *s)
{
    char    *temp;
    int        i;

    i = 0;
    if (!s && !*s)
        return (NULL);
    while (s[i] && s[i] != '\n')
        i++;
    temp = (char *)malloc(sizeof(char) * (i + 2));
    if (!temp)
        return (NULL);
    temp = ft_substr(s,0,i+1);
    return (temp);
}
int main() {
  
  char  *line;
  static char   *rec;
  char  buff[100]="It is a long hfghfghfghfghfgdhfgdhfghgfh \n content layout.";
  line = ft_get_line(buff);
  rec = ft_strjoin(rec,line);
  printf("record : %s",rec);
  printf("line : %s", line);
  
  return 0;
}