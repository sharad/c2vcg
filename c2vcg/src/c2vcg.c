/* @(#)c2vcg.c -- Briefly describe here 
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

#if HAVE_CONFIG_H
#  include <config.h>
#endif
#include "c2vcg.h"

/** @start 1 */


/** @end 1 */



# include <stdio.h>
# include <stdlib.h>

# include <string.h>
# define _GNU_SOURCE
extern const char *const sys_siglist [];

# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# ifdef SHOWRESOUS
# include <time.h>
# endif

//# include <error.h>

unsigned int node = ~0;		/* node number */
unsigned int subgraph = 0;	/* subgraph number */
unsigned int subgrphdepth = 1;	/* subgraph number */
//fpos_t position;
char *indentsp = "  ";



//Bstree *tpdf   = NULL;		/* all typedef names */
//Bstree *golabs = NULL;		/* all goto label names */
void *golabs = NULL;		/* all goto label names */

/* struct casnode *caseroot = NULL; */
void *caseroot = NULL;




char buff [BUFFCFGSIZE];	/* general purpose buffer */

char *progname = NULL;		//"c2vcg";
char *inputf   = NULL;		/* input file name */









int echo = 0;
int src_file_enter = 0;



FILE *cin      = NULL;		/*  */
FILE *gdlout   = NULL;		/* GDL output */
FILE *systpdf  = NULL;		/* used as pipe by cpp cmd */

FILE *logfile  = NULL;		/* All log of error and else */
FILE *debuglog = NULL;		/* All log of debugging */
FILE *errfile = NULL;		/* error reporting */
FILE *echoout  = NULL;		/* echo C soucre */

/* used in yyparse () > gram.y */

/****************************************************************************/
//const char *c2vcg_version = "c2vcg v11";
//const char *c2vcg_bug_address = "sh4r4d@gmail.com";
int parseclg (int ac, char **av);  
int check_ofile (const char *filename);
int setfile (const char *filename, const FILE *dfile,  FILE **file);
/****************************************************************************/

int main (int ac, char **av)
{
# ifdef SHOWRESOUS
  clock_t start, end;
  double cpu_time_used;
# endif

  int init ();
  int preprocess (const char *inputf);
  void cleanup (int signum);
  int print_gdl ();
  int rcode;			/* return code value. */
  
# ifdef SHOWRESOUS
  start = clock ();
# endif

  progname = *av;		/* setting program name. */

  //atexit (cleanup);
  signal (SIGINT, cleanup);

  parseclg (ac, av);		/* parse command line argument. */

  //  queueprint (stderr, pgmargs.clg, printarg); /*fulfilled their purpose*/
  //  stackprint (stderr, pgmargs.clg, printarg);

  /* initailization */
  init ();

  preprocess (inputf);

  yyrestart (cin);

  rcode = print_gdl ();

  /* Clean up >> */
  //  cleanup (0);

  fprintf (stderr, "\n\n");
  fprintf (stderr, "Good Bye Crual World\n");

  /* New Added */
/*   fsetpos (cin, &position); */
/*   while (fread (buff, 2, 10, cin)) */
/*     fwrite (buff, 2, 10, stderr); */

  /* New Added */

# ifdef SHOWRESOUS
  end = clock ();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  fprintf (stderr, "Total %f CPU clock, %f sec used\n", cpu_time_used,
	   end - start);
  fflush (stderr);
# endif

  cleanup (0);

  return rcode;
}
     
int init ()
{
  char *fn;
  char *dequeue (void **ptrclg);
  /* Initialization >> */


  inputf = ((fn = dequeue (&(pgmargs.clg))) == NULL ||
	    !strcmp (fn , "-")) ? "-" : fn;

  /* input file */
  if (strcmp (inputf, "-")) {
    struct stat fbuff;
    { /* check input file. */
      if (stat (inputf, &fbuff)) {
	sprintf (buff, "%s: %s", progname, inputf);
	perror (buff);
	exit (-1);
      }
      
      if (S_ISDIR(fbuff.st_mode)) {
	fprintf (stderr, "%s: input file `%s' is a directory.\n",
		 progname, inputf);
	exit (-2);
      }
    }
    
    if (S_ISREG(fbuff.st_mode) && !(cin = fopen (inputf, "r"))) {
      sprintf (buff, "Unable to open %s", inputf);
      perror (buff);
      exit (0);
    }

  } else
    cin = stdin;

  /* output file */
  gdlout = fopen ("/dev/null", "w");

  errfile = stderr;


  //if (pgmargs.output_file) {
  if (!getenv ("DISPLAY") || pgmargs.gdl2file)
    setfile (pgmargs.output_file, stdout, &gdlout);
  else if (!(gdlout = popen ("xvcg -", "w"))) {
      perror ("unable to open pipe");
      exit (-1);
    }

  if (pgmargs.echo)
    setfile (pgmargs.echo_file, stderr, &echoout);

  /********************************************/


  sprintf (buff, "%s/log.c2vcg", getenv ("HOME"));
  logfile = fopen (buff, "w+");
  
# ifdef DEBUG

  if (pgmargs.debug_ofile)
    setfile (pgmargs.debug_ofile, stderr, &debuglog);
  else
    debuglog = logfile;

# endif

}

void cleanup (int signum)
{
  /* Clean up >>*/

  /* close input file */
  fclose (cin);
  /* close output file */
  if (getenv ("DISPLAY") && !pgmargs.gdl2file)
    pclose (gdlout);
  gdlout = NULL;
  
  fflush (logfile);
  fclose (logfile);

# ifdef DEBUG
  fprintf (debuglog, "\nsignal received %s\n", strsignal (signum));
  fflush (debuglog);
  fclose (debuglog);
#endif

  fclose (errfile);
  //  if (pgmargs.echo && !strcmp (pgmargs.echo_file, "-"))
  if (echoout)
    fclose (echoout);


  signal (SIGINT, SIG_DFL);
  kill (0, signum);
/*   while (tmp = pluckbst_node (tpdf, NULL, ascending)) { */
/*     fprintf (stderr, "\n  %s", tmp); */
/*     free (tmp); */
/*   } */
}



int print_gdl ()
{
  int rcode;
  int yyparse();

  node = pgmargs.node;		/* starting node number */
  echo = pgmargs.echo;
  //  src_file_enter = 1;

  nlindenting (subgrphdepth++, gdlout);
  fputs ("graph: {", gdlout);
  c2vnl; fprintf (gdlout, "title: \"%s CFG_GRAPH\"", ! strcmp (inputf, "-") ? stdin : inputf);
  
  c2vnl; fprintf (gdlout, "colorentry 19: 255 255 180");
  c2vnl; fprintf (gdlout, "colorentry 33: 198 232 255");
  c2vnl; fprintf (gdlout, "colorentry 34: 255 228 198");
  c2vnl; fprintf (gdlout, "colorentry 35: 204 119  22");
  c2vnl; fprintf (gdlout, "colorentry 36:  10 147 113");
  c2vnl; fprintf (gdlout, "colorentry 42: 198 255 234");
  c2vnl; fprintf (gdlout, "colorentry 43:  47 183 122");
  c2vnl; fprintf (gdlout, "x: 60");
  c2vnl; fprintf (gdlout, "y: 60");
  c2vnl; fprintf (gdlout, "width: %d", pgmargs.width);
  c2vnl; fprintf (gdlout, "height: %d", pgmargs.hight);
  c2vnl; fprintf (gdlout, "layout_nearfactor: 0");
  c2vnl; fprintf (gdlout, "manhatten_edges: yes");
  c2vnl; fprintf (gdlout, "// layoutalgorithm: minbackward");
  c2vnl; fprintf (gdlout, "xspace: %d", pgmargs.xspace);
  c2vnl; fprintf (gdlout, "yspace: %d", pgmargs.yspace);
  c2vnl; fprintf (gdlout, "xlspace: 25");
  c2vnl; fprintf (gdlout, "stretch: 40");
  c2vnl; fprintf (gdlout, "shrink: 100");
  c2vnl; fprintf (gdlout, "display_edge_labels: yes");
  c2vnl; fprintf (gdlout, "finetuning: no");
  c2vnl; fprintf (gdlout, "node.borderwidth: 3");
  c2vnl; fprintf (gdlout, "node.color: 19");// lightcyan");
  c2vnl; fprintf (gdlout, "node.textcolor: 8"); //darkred");
  c2vnl; fprintf (gdlout, "node.bordercolor: 7"); //red");
  c2vnl; fprintf (gdlout, "edge.color: 8"); //darkgreen\n\n");
  fputs ("\n", gdlout);

  src_file_enter = 1;

  /* main parser */
  rcode = yyparse ();

  src_file_enter = 0;

  nlindenting (subgrphdepth--, gdlout);
  fputs ("}\n\n", gdlout);


  return rcode;
}


int preprocess (const char *infile)
{ /* block for parsing in cpp output. */
    /************************************/
  void prepcleanup (int signum);

  sprintf (buff, "%s %s  %s",
	   "cpp",
	   pgmargs.ppinclude ?
	   pgmargs.ppinclude : "" 
	   , infile);
  
  signal (SIGINT, prepcleanup);
  
  if (!(systpdf = popen (buff, "r"))) {
    perror ("unable to open pipe");
    exit (0);
  }


  sysTpdfParse (systpdf);

  
  pclose (systpdf);
  systpdf = NULL;

  //  signal (SIGINT, cleanup);
  /********************************************/
}

void prepcleanup (int signum)
{
  pclose (systpdf);
  signal (SIGINT, cleanup);

  cleanup (signum);
}

int setfile (const char *filename, const FILE *dfile, FILE **file)
{
    if (strcmp (filename, "-")) {
      if (check_ofile (filename)) {
	if (!(*file = fopen (filename, "w+"))) {
	  sprintf (buff, "Unable to open %s",
		   filename);
	  perror (buff);
	  exit (0);
	}
      } else
	exit (0);
    } else
      *file = dfile;

    return 0;
}


int check_ofile (const char *filename)
{
  char response;
  struct stat fbuff;

  if (stat (filename, &fbuff))
    return 1;
    //    sprintf (buff, "Unable to stat about %s", filename);
    //    perror (buff);
    //    exit (-1);

  if (S_ISDIR(fbuff.st_mode)) {
    fprintf (stderr, "%s: output file `%s' is a directory.\n",
	     progname, filename);
    exit (-2);
  }

  if (S_ISREG(fbuff.st_mode)) {
    fprintf (stderr, "\n%s: file `%s' already exist.", progname, filename);
    fprintf (stderr, "\nDo you want to overwrite existing file `%s'? [n]",
	     filename);

    response = fgetc (stdin);
    
    if (response == 'Y' || response == 'y')
      return 1;			/* success -- overwrite */
    else
      return 0;			/* fail -- exit donot overwrite */
  }
}
