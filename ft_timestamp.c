#include "philosophers.h"

long long	ft_timestamp(void)
{
	struct timeval	te;
	long long	milliseconds;

    gettimeofday(&te, NULL); 
    milliseconds = ((te.tv_sec * 1000) + te.tv_usec / 1000);
    return (milliseconds);
}