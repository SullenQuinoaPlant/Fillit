#include "fillit.h"

#define MESSAGES 4

char *	messages[MESSAGES] = {
	"usage function called",
	"fillit.exe requires exactly one filename as input.\n\
			the file must describe a list of tetraminos.",
	"could not open specified file or file was too long",
	"tetramino file contents invalid"
};

void	my_usage(int i)
{
	if (i > MESSAGES)
		i = 0;
	ft_putstr(messages[i]);
}
