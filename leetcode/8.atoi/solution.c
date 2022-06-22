#include "limits.h"
#include "stdio.h"

int isSpace(char c)
{   
    if (c && c <= 32)
        return (1);
    return (0);
}

int isSign(char c)
{
    if (c == '+' || c == '-')
        return (1);
    return (0);
}

int check_boundaries(long res, int sign)
{
    res = res * sign;
    if (res > INT_MAX)
        return (INT_MAX);
    else if (res < INT_MIN)
        return (INT_MIN);
    return (0);
}

int myAtoi(char * s){
    char * t_s;
    long res;
    int sign;
    int len_sign;
    
    t_s = s;
    res = 0;
    sign = 1;
    len_sign = 0;
    
    if (!t_s || !*t_s)
        return (0);
    while (isSpace(*t_s))
        t_s++;
    while (isSign(*t_s))
    {
        len_sign += 1;
        if (len_sign > 1)
            return (0);
        if (*t_s == '-')
            sign = -1;
        t_s++;
    }
    while (*t_s >= '0' && *t_s <= '9')
    {               
        res += (*t_s++ - '0');
        // printf("res: %d\n", res);
        if (check_boundaries(res, sign))
            return (check_boundaries(res, sign));
        res *= 10;
    }
    return (res / 10) * sign;
}
