#include "h.h"

#define MESSAGES 1

char *	messages[MESSAGES] = {\
	"usage function called",\
	"fillit.exe requires exactly one filename as input.\n\
			the file must describe a list of tetraminos.",\
	"could not open specified file",\
	"tetramino file contents invalid"\
}

void	usage(int i)
{
	if (i > MESSAGES)
		i = 0;
	ft_putstr(messages[i]);
}
