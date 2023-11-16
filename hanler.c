#include "shell.h"
size_t custom_strlen(const char *str);

/**
 * custom_signal_handler - Handles signals for Ctrl+C
 * @sig: Signal number
 * Returns: None
 */
void custom_signal_handler(int sig)
{
	char *custom_prompt = "\n$";

	(void)sig;
	write(1, custom_prompt, custom_strlen(custom_prompt));
	fflush(stdout);
}
