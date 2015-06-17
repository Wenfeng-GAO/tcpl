/* strcpy: copy t to s */
void str_cpy(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int str_cmp(char *s, char *t)
{
    for ( ; *s == *t; ++s, ++t)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

