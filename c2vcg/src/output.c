/* @(#)output.c -- Briefly describe here 
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
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

# include "c2vcg.h"
# include "output.h"

/** @start 1 */


/** @end 1 */

void nlindenting (int indent, FILE *out)
{
  fputc ('\n', out);
  while (indent--) fputs (indentsp, out);
}

static void putnchar (int i, FILE *out)
{
  while (--i)
    fputc ( ' ', gdlout);
}

/* int graphstart () */
/* { */
/*   //  nlindenting (subgrphdepth++, gdlout); */
/*   fputs ("graph: {", gdlout); */
/*   c2vnl; fprintf (gdlout, "title: \"CFG_GRAPH\""); */
  
/*   c2vnl; fprintf (gdlout, "colorentry 19: 255 255 180"); */
/*   c2vnl; fprintf (gdlout, "colorentry 33: 198 232 255"); */
/*   c2vnl; fprintf (gdlout, "colorentry 34: 255 228 198"); */
/*   c2vnl; fprintf (gdlout, "colorentry 35: 204 119  22"); */
/*   c2vnl; fprintf (gdlout, "colorentry 36:  10 147 113"); */
/*   c2vnl; fprintf (gdlout, "colorentry 42: 198 255 234"); */
/*   c2vnl; fprintf (gdlout, "colorentry 43:  47 183 122"); */
/*   c2vnl; fprintf (gdlout, "x: 60"); */
/*   c2vnl; fprintf (gdlout, "y: 60"); */
/*   c2vnl; fprintf (gdlout, "width: %d", pgmargs.width); */
/*   c2vnl; fprintf (gdlout, "height: %d", pgmargs.hight); */
/*   c2vnl; fprintf (gdlout, "layout_nearfactor: 0"); */
/*   c2vnl; fprintf (gdlout, "manhatten_edges: yes"); */
/*   c2vnl; fprintf (gdlout, "// layoutalgorithm: minbackward"); */
/*   c2vnl; fprintf (gdlout, "xspace: %d", pgmargs.xspace); */
/*   c2vnl; fprintf (gdlout, "yspace: %d", pgmargs.yspace); */
/*   c2vnl; fprintf (gdlout, "xlspace: 25"); */
/*   c2vnl; fprintf (gdlout, "stretch: 40"); */
/*   c2vnl; fprintf (gdlout, "shrink: 100"); */
/*   c2vnl; fprintf (gdlout, "display_edge_labels: yes"); */
/*   c2vnl; fprintf (gdlout, "finetuning: no"); */
/*   c2vnl; fprintf (gdlout, "node.borderwidth: 3"); */
/*   c2vnl; fprintf (gdlout, "node.color: 19");// lightcyan"); */
/*   c2vnl; fprintf (gdlout, "node.textcolor: 8"); //darkred"); */
/*   c2vnl; fprintf (gdlout, "node.bordercolor: 7"); //red"); */
/*   c2vnl; fprintf (gdlout, "edge.color: 8"); //darkgreen\n\n"); */

/* } */

/* int graphend () */
/* { */
/*   nlindenting (subgrphdepth--, gdlout); */
/*   fputs ("}", gdlout); */

/* } */

int sketch_node (int title, char *label, char *shape, char *color)
{				/*, memop fopt)*/

  fputc ('\n', gdlout);
  nlindenting (subgrphdepth, gdlout);
  fputs ("node: {", gdlout);

  nlindenting (subgrphdepth, gdlout);
  putnchar (5 + 4, gdlout);
  fprintf (gdlout, "title: \"%d\" ", title);

  if (label) {
    nlindenting (subgrphdepth, gdlout);
    putnchar (5 + 4, gdlout);
    if (pgmargs.print_node)
      fprintf (gdlout, "label: \"[%d] %s\" ", title, label);
    else
      fprintf (gdlout, "label: \"%s\" ", label);
  
  free (label);  // free memory asociated with label....
  }


  if (shape) {
    nlindenting (subgrphdepth, gdlout);
    putnchar (5 + 4, gdlout);
    fprintf (gdlout, "shape: %s ", shape);
  }
  if (color) {
    nlindenting (subgrphdepth, gdlout);
    putnchar (5 + 4, gdlout);
    fprintf (gdlout, "color: %s ", color);
  }

  nlindenting (subgrphdepth, gdlout);
  putnchar (5 + 4, gdlout);
  fprintf (gdlout, "textmode: %s ", "center");

  nlindenting (subgrphdepth, gdlout);
  putnchar (3 + 4, gdlout);
  fprintf (gdlout, "}\n");
}

int sketch_edge (int edge, int src, int trg, char *label, char *linestyle)
{
  int i;
  static char *edgename [] = {"edge", "edge", "bentnearedge", "backedge", "nearedge"};

  fputc ('\n', gdlout);
  nlindenting (subgrphdepth, gdlout);
  fprintf (gdlout, "%s: {", edgename [edge]);
  nlindenting (subgrphdepth, gdlout);
  putnchar (5 + strlen (edgename [edge]), gdlout);
  fprintf (gdlout, "sourcename: \"%d\" ", src);
  nlindenting (subgrphdepth, gdlout);
  putnchar (5 + strlen (edgename [edge]), gdlout);
  fprintf (gdlout, "targetname: \"%d\" ", trg);


  if (label) {
    nlindenting (subgrphdepth, gdlout);
    putnchar (5 + strlen (edgename [edge]), gdlout);
    fprintf (gdlout, "label: \"%s\"", label);
  }

  if (linestyle) {
    nlindenting (subgrphdepth, gdlout);
    putnchar (5 + strlen (edgename [edge]), gdlout);
    fprintf (gdlout, "linestyle: %s", linestyle);
  }

  nlindenting (subgrphdepth, gdlout);

  putnchar (3 + strlen (edgename [edge]), gdlout);

  fprintf (gdlout, "}\n");
}


static int faction (int src, Sttyp srctyp, edge trgedge, int trg, dir reverse)
{
  char *setfalse = NULL;
  edge tmpedge = EDGE;

    switch (srctyp) 
      {
      case LOOP:
	tmpedge = BENTNEAR;
	setfalse = "false";	/* enable toggle, by option */
	break;
      case LABL:
	tmpedge = pgmargs.gotonear ? NEAR : EDGE;
	break;
      default:
	tmpedge = EDGE;
	setfalse = NULL;
      }
  
  if (reverse == REVERSE)
    sketch_edge (trgedge == PASS ? tmpedge:trgedge, trg, src, setfalse, NULL);
  else
    sketch_edge (trgedge == PASS ? tmpedge:trgedge, src, trg, setfalse, NULL);
}


# include <set.h>


int sketchout_edges (edge trgedge, Set *outsptr, int trg, dir reverse)
{
  if (outsptr && !*outsptr) {
# ifdef DEBUG
    fprintf (logfile, "\nerror: outs = NULL");
     fprintf (stderr, "\nerror: outs = NULL");
# endif
     return 0;			/*-1;     source of problem */
  }
  setwalkfree (outsptr, trgedge, trg, reverse, (setaction) faction);
}

/*********************************************************************
* It is returning a stiring of format fmt with arguments ...         *
* and also freeing the memory associated with arguments ...          * 
*********************************************************************/
char *copyfmt (char *fmt, ...)
{
  va_list ap;
  char *tmp1, *tmp2;
  int count = 0;
  //  char buff [1000];

  if (!fmt) {			/* early getout */
    va_start (ap, fmt); 

    //    tmp2 = strdup (tmp1 = (char *) va_arg (ap, char *));

    //free ((char *) tmp1);
   
    tmp2 = (char *) va_arg (ap, char *);  //added.

    va_end (ap);

    return tmp2;
  }

  va_start (ap, fmt);
  vsprintf (buff, fmt, ap);
  va_end (ap);

  //  fprintf (stderr, "22222"); fflush (stderr);
  tmp1 = fmt;
  while (*tmp1)
	  if (*tmp1++ == '%') 
	      if (*tmp1 != '%') count++;   //crusial point.
	      // it is necessary to avoid the case of %%.

  //  fprintf  (stderr, "\nCOUNT : %d, format string:|: %s\n", count, fmt); 
  
  va_start (ap, fmt);
  while (count--)
    free ((char *) va_arg (ap, char *));
  va_end (ap);

  fflush (stderr);
  return strdup (buff);

}



yyerror(char *s)
//char *s;
{
  if (echo) {
    fflush(echoout);
    fprintf(echoout, "\n%*s\n%*s\n", column, "^", column, s);
    //exit (11);
  }
  fflush(errfile);
  fprintf(errfile, "\n%s:%d:c%d: %s"
# ifdef DEBUG
	  " yytext: %s"
# endif
	  "\n", 
	  inputf, line, column, s
# ifdef DEBUG
	  , yytext
# endif
	  );
  //  cleanup (0);
  exit (11);
}



/*
 *   functions for debugging help. 
 *
 *
 */


int showflows (Set root, char *s)
{
  if (!root) {
    fprintf (logfile, "\n<%s> : there is no node", s);
    return;
  }
  fprintf (logfile, "\nNodes of <%s> : ", s);
  printset (root);
  fprintf (logfile, "$end");
}






/* int joinary (int **trg, int **src1, int **src2) { */
/* 		int alen = 0; */
/* 		int *tmp = NULL; */
/* 		if (!(*src1 && *src2)) { */
			
/* 			tmp = ( *src1 ? *src1 : *src2 ); */
			
/* 			if (!(tmp && !(*tmp  < 0))) {   */
/* 				//\*trg = (int *) malloc (sizeof (int)); */
/* 				//\**trg = -1; */
/* 				*trg = NULL; */
/* 				return; // think it enough */
/* 			} */
/* 		} */

/* 		if (tmp) */
/* 			*trg = tmp; */
/* 		else { */
/* 			int *tmpsrc1 = *src1;	// trg and src1 or src2 */
/* 			int *tmpsrc2 = *src2;	// can be same. */
/* 			*trg = (int *) calloc (alen = (arlen (*src1) */
/* 					+ arlen (*src2) + 1), */
/* 					sizeof (int)); */
/* 			arcpy (*trg, tmpsrc1);	// carefull abt trg and src1 same */
/* 			arcpy (*trg + arlen (tmpsrc1), tmpsrc2); */
/* 			//qsort (*trg, alen, sizeof (int), numcmp); */

/* 			free (*src1);		//don't do that urself */
/* 			free (*src2);		// be careful. */
/* 		} */
/* } */


/* int *creatary (int size, ...) */
/* { */
/*   int *retmp = (int *) calloc (size, sizeof (int)); */
/*   int *tmp = retmp; */
/*   va_list ap; */
/*   va_start (ap, size); */
/*   while (size--) */
/*     *tmp++ = (int) va_arg (ap, int); */
/*   va_end (ap); */

/*   //  *tmp = -1; */

/*   return retmp; */
/* } */

