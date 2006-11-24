/* @(#)output.h -- Briefly describe here 
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
#ifndef _OUTPUT_H
#define _OUTPUT_H 1


extern char yytext[];
extern int column, line;



//nodtyp *crtnodtyp (int node, Sttyp type);
void nlindenting (int indent, FILE *out);

int graphstart (void);

int graphend (void);

int sketch_node (int title, char *label, char *shape, char *color);

int sketch_edge (int edge, int src, int trg, char *label, char *linestyle);


int sketchout_edges (edge trgedge, Set *outsptr, int trg, dir reverse);

int joinary (int **trg, int **src1, int **src2);

int *creatary (int size, ...);

char *copyfmt (char *fmt, ...);


/** Debug **/

int showflows (Set root, char *s);




#endif /* _OUTPUT_H */
/** @end 1 */

