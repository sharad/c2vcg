/* @(#)set.h -- Briefly describe here 
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
# ifndef _SETLL_H
# define _SETLL_H 1



# define SETSPACE unsigned int  	/* Tailor Space values */
# define SETP  unsigned int	/* according to you.   */

//extern int bowlsize;

struct llset;
typedef struct llset *PtrToNode;
typedef PtrToNode PosSet;
typedef PtrToNode Set;
typedef PtrToNode *ptrSet;

typedef unsigned int ttyp;

typedef	int (*setaction) (int, ttyp, unsigned int,
		       unsigned int, unsigned int);


int insert       (ttyp eletype, SETP ele, Set *dest);
int delete       (SETP ele, Set *dest);
Set *setunion    (Set *dest, Set *src);
int printset     (Set src);

SETP setwalk     (int freemem, ptrSet src,
		  unsigned int trgedge,
		  unsigned int trg,
		  unsigned int reverse,
		  int (*action) (int, ttyp, unsigned int,
			      unsigned int, unsigned int));

SETP setwalkfree (ptrSet src,
		  unsigned int trgedge,
		  unsigned int trg,
		  unsigned int reverse,
		  setaction action);

#endif /* _SET_H */
/** @end 1 */
