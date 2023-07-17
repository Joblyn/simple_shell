#include "main.h"

/**
 * _strdup - duplicates a string
 * @org: string to be duplicated
 * Return: duplicate of string
 */
char *_strdup(char *org)
{
    int org_size;
    static char *dup;
    char *dup_offset;

    /* Allocate memory for duplicate */
    org_size = _strlen(org);
    dup = (char *)malloc(sizeof(char)*org_size+1);
    if( dup == NULL)
        return( (char *)NULL);

    /* Copy string */
    dup_offset = dup;
    while(*org)
    {
        *dup_offset = *org;
        dup_offset++;
        org++;
    }
    *dup_offset = '\0';

    return(dup);
}
