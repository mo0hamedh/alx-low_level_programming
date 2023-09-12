#include "main.h"

/*
 * e_ident[] - identification index
 *
 * Description: The initial bytes mark the file as an object file
 *              and provide machine independent data
 * The initial bytes of an ELF header
 *  correspond to the eident member
*/

/**
 * check_if_elf - checks if file is an ELF file by checking if it
 *                contains the magic numbers/file signature of an ELF file
 *
 * @e_ident: a pointer to an array of bytes specifies
 *           how to interpret the file
 *
 * Return: nothing
*/
void check_if_elf(unsigned char *e_ident)
{
	int index = 0;
	while (index < 4)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F') /0x7F is 127 in ASCII/
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}

		index++;
	}
}

/**
 * print_magic - print the m num of the ELF file
 *
 * @e_ident: a pointer to an array of bytes specifies
 *
 * Return: nothing
*/
void print_magic(unsigned char *e_ident)
{
	int ind = 0;

	printf("  Magic    ");

	while (ind < EI_NIDENT) /EI_NIDENT == sizeof(e_ident[]) = 16/
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" "); /space each number/

		ind++;
	}
}

/**
 * print_class - print the ELF file
 *
 * @e_ident: pointer to an array of bytes specifies
 *
 * Return: nothing
*/
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS]) /EI_CLASS - File class/
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - print the data code of the ELF file
 *
 * @e_ident: a pointer to an array of bytes specifies
 *
 * Return: nothing
*/
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA]) /EI_DATA - Data encoding/
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - to print the v of the ELF file
 *
 * @e_ident: a pointer to an array of bytes specifies
 *
 * Return: nothing
*/
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");/EI_VERSION - File version/

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", e_ident[EI_VERSION]);
	else
		printf("%i\n", e_ident[EI_VERSION]);
}		
