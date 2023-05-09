#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

void check_elf(const char* filename);
void print_magic(const unsigned char* magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_abi(unsigned char abi);
void print_osabi(unsigned char osabi);
void print_type(unsigned short type);
void print_entry(Elf64_Addr entry);
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
