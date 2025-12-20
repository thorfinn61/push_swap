int is_sep(char c, char sep)
{
    if (c == sep)
        return (1);
    if (c == '\0')
        return (1);
    return (0);
}

int count_words(const char *str, char sep)
{
    int i;
    int words;

    i = 0;
    words = 0;
    while (str[i])
    {
        if (is_sep(str[i], sep) == 0 && is_sep(str[i + 1], sep) == 1)
            words++;
        i++;
    }
    return (words);
}

void    write_word(char *dest, const char *src, char sep)
{
    int i;

    i = 0;
    while (is_sep(src[i], sep) == 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void    write_split(char **split, const char *str, char sep)
{
    int i;
    int j;
    int word;

    i = 0;
    word = 0;
    while (str[i])
    {
        if (is_sep(str[i], sep) == 1)
            i++;
        else
        {
            j = 0;
            while (is_sep(str[i + j], sep) == 0)
                j++;
         split[word] = malloc(sizeof(char) * (j + 1));
            if (!split[word])
                return ;
            write_word(split[word], str + i, sep);
            i = i + j;
            word++;
        }
    }
}

char    **ft_split(char const *s, char c)
{
    int     words;
    char    **res;

    words = count_words(s, c);
    res = malloc(sizeof(char *) * (words + 1));
    if (!res)
        return (NULL);
    res[words] = NULL;
    write_split(res, s, c);
    return (res);
}
                                                                                                              6,1           12%

