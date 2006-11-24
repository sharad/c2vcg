/* @(#)c2vcg.h -- Briefly describe here 
   Copyright (C) 2006 Sharad Pratap
  
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
  
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
*/

/** @start 1 */
#ifndef _C2VCG_H
#define _C2VCG_H 1

# include <stdio.h>
# include <set.h>


/*****************************/

# define c2vnl  nlindenting (subgrphdepth, gdlout)


/*****************************/

# define BUFFCFGSIZE 1000
# define MAXNONTRM   3 /* I think more than 3 is not needed. See later */
# define NULLNODE    -1 	/* negative value */


extern unsigned int node;	/* node number */
extern unsigned int subgraph; /* subgraph number */
extern unsigned int subgrphdepth; /* subgraph number */
//extern fpos_t position;
extern char *indentsp;
extern char buff [BUFFCFGSIZE];	/* general purpose buffer */
extern char *progname;
extern char *inputf;		/* input file name */

extern int echo;
extern int src_file_enter;

/*** For Now ***/
//typedef int hook;



/***************/

/****************************************************************************/
//extern int casejoin;		/*  */
//extern int jump;		/* ??? */

/* struct casenode; */
/* extern struct casnode *caseroot; */

extern void *caseroot;
extern void *golabs;		/* all goto label names */
/* options */ 
extern int casejoin;	        //7; can have -ve 0 +ve values.
extern int semicolon;		/* binary */
extern int caseq;		/* binary: used for leveling the case */
extern int gotonear;		/* binary */
//int showemptybody = 0;   // if programmer intended to do stupidity
                           // why I need to bother.


/****************************************************************************/

extern FILE *cin;		/*  */
extern FILE *gdlout; 		/* GDL output */		
extern FILE *logfile;		/* All log of error and else */	
extern FILE *systpdf;		/* used as pipe by cpp cmd */

extern FILE *debuglog;		/* All log of debugging */
extern FILE *errfile;		/* error reporting */
extern FILE *echoout;		/* echo C soucre */

//extern Bstree *tpdf;		/* all typedef names */
//extern Bstree *golabs;		/* all goto label names */


/****************************************************************************/
/****************************************************************************/

enum dir { FORWARD, REVERSE };

enum Sttyp {NONODE = 0, SIMPLE, LOOP,
	    SEL, JUMP, SWIT, CAS, LABL};
enum edge { PASS = 0, EDGE, BENTNEAR, BACK, NEAR }; /*  */

typedef enum Sttyp Sttyp;

typedef enum edge edge;

typedef enum dir dir;

typedef struct Flows Flows;

typedef struct Stat Stat;

# define STATYPE 8

struct Flows {

# ifndef USELOCALMEM
  short unsigned int occupied;
# endif

  int entry;
  Sttyp sttyp;
  Set outs;
  Set brk, cnt, cas;
};


struct Stat {

# ifndef USELOCALMEM
  short unsigned int occupied;
# endif

  char *copy;
  Flows *flows;
  int h, w;
};

typedef struct {
  int node;
  Sttyp type;
} nodtyp;


int gettypedef (char *buff);	/* used for typedef */
int sysTpdfParse (FILE *);




/* Used by `main' to communicate with `parse_opt'. */
struct arguments
{
  void *clg;                   /* ARG1 */ // use hook.
  unsigned int node;
  //  char **strings;               /* [STRING...] */
  int silent, verbose, abort;   /* `-s', `-v', `--abort' */
  int semicolon, gotonear, hight, width;
  int casejoin, caseq, forms;
  int print_node;
  int echo;
  char *echo_file;
  int xspace, yspace;		/*  */
  int gdl2file;
  char *output_file;            /* FILE arg to `--output' */
  char *debug_ofile;
  char *ppinclude;
  int repeat_count;             /* COUNT arg to `--repeat' */
};

struct arguments pgmargs;


#endif /* _C2VCG_H */
/** @end 1 */

