/************************************************************
 *							    *
 *	DOS2UNIX.C					    *
 *							    *
 * This utility can be compiled for either DOS or UNIX.	    *
 * It reads a DOS source file, converts tabs to spaces,	    *
 * and converts CR/LF pairs to LF only. It also eliminates  *
 * the CONTROL Z character at the end of a DOS text file.   *
 * Tab conversion assumes tab stops are at 3 space inter-   *
 * vals (this can be changed by redefining TAB_SIZE and	    *
 * recompiling).					    *
 *							    *
 *		V 1.0	- 08/10/96			    *
 *							    *
 * This program and its source code are placed in the	    *
 * public domain with no restrictions whatsoever.	    *
 *				Jeffery L. Post		    *
 *							    *
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define	BFR_SIZE	512	/* I/O buffer size	    */
#define	TAB_SIZE	3	/* tab spacing		    */
#define	CR		0x0d	/* ascii carriage return    */
#define	LF		0x0a	/* ascii line feed	    */
#define	CTRLZ		0x1a	/* ascii control z	    */

FILE	*fpi;
FILE	*fpo;
char	bfr_in[BFR_SIZE];
char	bfr_out[2 * BFR_SIZE]; /* bigger in case lots of tabs */

int main(int argc, char *argv[]) {
    int i, j, k, l;

    if(argc < 3) {
	printf("\nUsage: dos2unix file.in file.out\n");
	exit(1);
    }
    fpi = fopen(argv[1], "rb");
    if(fpi == NULL) {
	printf("Can't open '%s'\n", argv[1]);
	exit(1);
    }
    fpo = fopen(argv[2], "wb");
    if(fpi == NULL) {
	printf("Can't open '%s'\n", argv[2]);
	exit(1);
    }
    i = 1;
    while (i) {
	i = fread(bfr_in, 1, BFR_SIZE, fpi);
	for (j=0, k=0, l=0; j<i; j++) {
	    if (bfr_in[j] == CTRLZ) {	/* done if end of DOS file */
	    i = 0;
	    break;
	}
	if(bfr_in[j] == '\t') {	/* if tab, expand it */
	    do
	        bfr_out[k++] = ' ';
	    while(++l % TAB_SIZE);
	} else {			/* if not a tab... */
	    if(bfr_in[j] != CR) {	/* anything not a CR goes out */
		bfr_out[k++] = bfr_in[j];
		if(bfr_in[j] == LF)	/* if line feed, line count = 0 */
		    l = 0;
		else			/* else count characters in line */
		    l++;
	    }
	}
    }
    if(k)
	fwrite(bfr_out, 1, k, fpo);
    }
    fclose(fpi);
    fflush(fpo);
    fclose(fpo);
}

/* end of dos2unix.c */


