#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry( unsigned long int  e_entry, unsigned char *e_ident);
void close_elf (int elf);
/**
 * check_elf - checks the file
 * @e_ident: arrary conyaning the elf magic number
 *
 * Description: if a dile s not the elf file exit
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for(index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		e_ident[index] != 'E' &&
		e_ident[index] != 'L' &&
		e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}
