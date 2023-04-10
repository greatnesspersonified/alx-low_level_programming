#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * A function that appends a text at the end of a file
 * @filename: path to file
 * @text_content: content
 * Return: 1 on success or -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fn;
	ssize_t w;
	int size;

	if (!filename)
		return (-1);

	fn = open(filename, O_WRONLY | O_APPEND);

	if (fn == -1)
		return (-1);

	if (!text_content)
	{
		close(fn);
		return (1);
	}

	size = strlen(text_content);
	w = write(fn, text_content, size);

	if (w == -1)
	{
		close(fn);
		return (-1);
	}
	close(fn);
	return (1);
}

/**
 * _strlen - len
 *
 * @s: A pointer to a char
 *
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
