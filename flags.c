#include <stdlib.h>
#include "main.h"


/**
 * init_flags - initializes the flags data structure
 *
 * Return: the flags object
 */
Flags *init_flags()
{
	Flags *flags;

	flags = malloc(sizeof(Flags));
	if (flags)
		flags->plus = flags->space = flags->hash = 0;
	return (flags);
}


/**
 * set_flags - sets the flags and infer change of any flag
 *
 * @flags: the flags object
 * @flag: the format character specifying a flag to set
 *
 * Return: 1 if set any of the flags, 0 otherwise
 */
int set_flags(Flags *flags, const char flag)
{
	int ret;

	ret = 0;
	switch (flag)
	{
		case '+':
			flags->plus = 1, ret = 1;
			break;
		case '#':
			flags->hash = 1, ret = 1;
			break;
		case '0':
			flags->zero = 1, ret = 1;
			break;
		default:
			break;
	}
	return (ret);
}
