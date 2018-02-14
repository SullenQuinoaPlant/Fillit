#include "fillit.h"

#define MESSAGES 4

char *	messages[MESSAGES] = {
	"usage function called\n",
	"fillit.exe requires exactly one filename as input.\n\
			the file must describe a list of tetraminos.\n",
	"could not open specified file or file was too long\n",
	"tetramino file contents invalid\n"
};

void	my_usage(int i)
{
	if (i >= MESSAGES)
		i = 0;
	ft_putstr(messages[i]);
}
