#include "push_swap"

void parse_argument(char *arg, t_stack **a);
void parse_number(char *str, t_stack **a);

t_stack *parse_args(int argc, char **argv)
{
    t_stack *a;
    int     i;

    a = NULL;
    i = 1;
    while (i < argc)
    {
        parse_argument(argv[i], &a);
        i++;
    }
    return (a);
}
void parse_argument(char *arg, t_stack **a)
{
    char    **words;
    int     j;

    words = ft_split(arg, ' ');
    if (!words || !words[0])
        error();
    j = 0;
    while (words[j])
    {
        parse_number(words[j], a);
        j++;
    }
    free_split(words);
}
void parse_number(char *str, t_stack **a)
{
    long n;

    if (!is_valid_number(str))
        error();
    n = ft_atol(str);
    if (n < INT_MIN || n > INT_MAX)
        error();
    stack_add_back(a, stack_new((int)n));
}
