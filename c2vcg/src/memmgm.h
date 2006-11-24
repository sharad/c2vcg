/* @(#)memmgm.h -- Briefly describe here 
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
#ifndef _MEMMGM_H
#define _MEMMGM_H 1

# include <stdarg.h>
# include "c2vcg.h"

/* struct casnode; */
/* struct casnode *casnode_new (int node, char *copy); */
/* void push (unsigned int node, char *ptr, struct casnode **ptrcasroot); */
/* unsigned int pop (char **string, struct casnode **ptrcasroot); */

void push (unsigned int node, char *ptr, void **ptrcasroot);
unsigned int pop (char **string, void **ptrcasroot);


/**************************************/
/************** Flow ******************/

Flows *get_flows (int entry, Sttyp type, int node);

/***************************************/

/****************************************/

Stat *get_stat (char *copy, Flows *flows);

char *freestat (Stat *tofree);	/* Describe here about who char* returning */
				/* and taking (Stat *) */

/*****************************************
           Btree *golabs 
******************************************/
struct c2vlglab;

int put_out_node (char *ident, int node);

struct c2vlglab *addsearch_label (char *ident, int node);

Set *put_lable_node (char *ident, int node);

/******************************************/




#endif /* _MEMMGM_H */
/** @end 1 */
