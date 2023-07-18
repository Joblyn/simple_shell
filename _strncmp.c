#include "main.h"

/**
 * strncmp - compare two strings by number of numbers
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Result: integer
 */
int _strncmp( const char * s1, const char * s2, size_t n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}
