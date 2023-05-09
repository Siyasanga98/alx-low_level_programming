#include "main.h"
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
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
/**
 * check_elf - checks if the file is an ELF file
 * @e_ident: array containing the ELF magic number
 *
 * Description: If a file is not an ELF file, it exits with an error message.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints the ELF magic number
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the magic number in hexadecimal format.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		unsigned char byte = e_ident[i];

		printf("%02x ", byte);
	}
	printf("\n");
}

/**
 * print_class - prints the ELF class
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the ELF class based on the value in e_ident[EI_CLASS].
 */
void print_class(unsigned char *e_ident)
{
	printf("Class:   ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
		printf("ELF32\n");
		break;
		case ELFCLASS64:
		printf("ELF64\n");
		break;
		default:
		printf("Invalid class\n");
		exit(98);
	}
}

/**
 * print_data - prints the ELF data encoding
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the ELF data encoding based on the value
 */
void print_data(unsigned char *e_ident)
{
	printf("Data:    ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data encoding\n");
			exit(98);
	}
}

/**
 * print_version - prints the ELF version
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the ELF version based on the value
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_abi - prints the OS/ABI
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the OS/ABI based on the value in e_ident[EI_OSABI].
 */
void print_abi(unsigned char *e_ident)
{
	printf("OS/ABI:  ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		default:
			printf("Unknown OS/ABI\n");
			exit(98);
	}
}

/**
 * print_osabi - prints the ABI Version
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the ABI Version based on the value
 */
void print_osabi(unsigned char *e_ident)
{
	printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the ELF file type
 * @e_type: ELF file type
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the ELF file type based on the value in e_type.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	printf("Type:    ");
	(void)e_ident;
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown type\n");
			exit(98);
	}
}

/**
 * print_entry - prints the entry point address
 * @e_entry: entry point address
 * @e_ident: array containing the ELF magic number
 *
 * Description: Prints the entry point address in hexadecimal format.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("Entry point address: 0x%08lx\n", e_entry);
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("Entry point address: 0x%016lx\n", e_entry);
	else
	{
		printf("Invalid ELF class\n");
		exit(98);
	}
}

/**
 * close_elf - closes the ELF file
 * @elf: file descriptor of the ELF file
 *
 * Description: Closes the ELF file.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("Error closing ELF file");
		exit(98);
	}
}

/**
 * print_elf_header - prints the information contained in the ELF header
 * @filename: name of the ELF file
 *
 * Description: Opens the ELF file, reads and prints information.
 */
void print_elf_header(const char *filename)
{
	Elf64_Ehdr header;

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		perror("Error reading file");
	exit(98);
}

check_elf(header.e_ident);

printf("ELF Header:\n");

print_magic(header.e_ident);
print_class(header.e_ident);
print_data(header.e_ident);
print_version(header.e_ident);
print_abi(header.e_ident);
print_osabi(header.e_ident);
print_type(header.e_type, header.e_ident);
print_entry(header.e_entry, header.e_ident);

close_elf(fd);

}
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage : ./elf_header filename\n");
		exit(98);
	}
	print_elf_header(argv[1]);
	return (0);
}
