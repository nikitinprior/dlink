# dlink
Restored  linker LINK.COM from the Hi-Tech C compiler v3.09

# Introduction

With the participation of Mark Ogden, the source code was restored linker LINK.COM from the Hi-Tech C compiler v3.09.
All functions and variables are assigned understandable names.

# Compiling the program

The source code can be compiled for CP/M using a Makefile. This requires the latest version of gnu make.
To compile using gcc on linux or macOS operating systems, run the command

  gcc -O2 -o link a.c b.c c.c ds.c e.c extra.c

as a result, the link executable file will be created.

# Additional Information

To create a backup copy of the source files, run the command

  make compress

and the link.huf archive file will be created.
To extract the files in the archive, run the command

  dehuff -x LINK.HUF

The source files for the dehuff and enhuff programs are available in the Tony Nicholson repository https://github.com/agn453/HI-TECH-Z80-C/tree/master/huff

For functions that cannot be optimized with the help of the OPTIM program.COM for CP/M, the optim program compiled from the restored source code is used https://github.com/nikitinprior/doptim.

The dos2unix program is temporarily used to delete the contents from the ^Z character to the end of the assembly language file created by the CGEN.COM program for CP/M.

When will the source code of the programs be restored P1.COM and ZAS.COM there will be no need for the dos2unix program.

The dos2unix source code is also included in the archive file. 

# Update 08.01.2022

Added support for searching for the library and startup file. To use the search one of two environment variables need to be set.
 
LIBDIR80              - path of the library and startup files
or
CPMDIR80           - path of the root of the CPM files as per zxcc. The actual library is in a subdirectory lib80 below the path specified by CPMDIR80
 
As per zxcc, the LIBDIR80 path takes precedence.
The search support is only provided for non CP/M builds and requires the additional extra.c file to be added to the build.

# Appreciation

Mark Ogden for active participation in the restoration of the compiler source code.

Tony Nicholson for maintaining  compiler information.

Andrey Nikitin 08.01.2022


