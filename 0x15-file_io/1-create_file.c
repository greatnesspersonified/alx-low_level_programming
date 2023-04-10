#include "main.h"
#include <stdlib.h>

/**
  * create_file - create a function that creates a file
  * @filename: u to create
  * @text_content: content to read into the u
  *
  * Return: 1 on success, -1 on any failure
  */
int create_file(const char *filename, char *text_content)
{
	int u, w, len = 0;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);
	u = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (u == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		write(u, text_content, len);
	}
	w = close(u);
	if (w == -1)
		return (-1);
	return (1);
}
