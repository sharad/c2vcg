/* @(#)memmgm.c -- Briefly describe here 
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
# include "memmgm.h"
# include <common.h>

/** @start 1 */

/** @end 1 */


# ifdef USELOCALMEM
 Stat  StatArray [MAXNONTRM];
 Flows FlowArray [MAXNONTRM];
# endif

/****************************************************************/
/* Write Here For what it is used. */

/****************************************************************/

/****************************************************************/
/***********  Flow **********************************************/


static Flows *allocflow (void)
{
# ifdef USELOCALMEM
  int i;

  for (i = 0; i < MAXNONTRM; i++) {
    if (FlowArray [i].occupied == 0) {
      FlowArray [i].occupied == 1;
      return &FlowArray [i];
    }
  }
# ifdef DEBUG
  fprintf (stderr, "\nrequired more than %d "
	   "non-termianl\n\n\tAborted", MAXNONTRM);
  abort ();
# endif
# else
  return (Flows *) malloc (sizeof (Flows));
# endif
}



Flows *get_flows (int entry, Sttyp type, int node)
{
  
  Flows *retval = allocflow ();

  retval->entry = entry;
  retval->outs  = NULL;
  //  push_link (&(retval->outs), Outs);
  insert (type, node, &(retval->outs) );
  retval->brk   = NULL;
  retval->cnt   = NULL;
  retval->cas   = NULL;
  retval->sttyp = SIMPLE;
  return retval;
}    

static void freeflows (Flows *flows)
{
# ifdef USELOCALMEM
  flows->occupied = 0;
# else
  free (flows);
# endif
}

/****************************************************************/

/****************************************************************/


static Stat *allocstat (void)
{
# ifdef USELOCALMEM
  int i;

  for (i = 0; i < MAXNONTRM; i++) {
    if (StatArray [i].occupied == 0) {
      StatArray [i].occupied == 1;
      return &StatArray [i];
    }
  }
# ifdef DEBUG
  fprintf (stderr, "\nrequired more than %d "
	   "non-termianl\n\n\tAborted", MAXNONTRM);
  abort ();
# endif
# else
  return (Stat *) malloc (sizeof (Stat));
# endif
}


Stat *get_stat (char *copy, Flows *flows)
{

  Stat *retval = allocstat ();
  
  retval->copy = copy;
  retval->flows = flows;
  return retval;
}

char *freestat (Stat *tofree)
{
  char *retcopy = tofree->copy;
  //if (tofree->copy) {
  //  free (tofree->copy);
  //}

  //We will never try to free flows *
# ifdef USELOCALMEM
  tofree->occupied = 0;
# else
  free (tofree);
# endif

  return retcopy;
}

/******************************************************************************
*                            Btree *golabs                                    *
******************************************************************************/

/******************************************************************************
*                            Btree *golabs                                    *
******************************************************************************/

struct c2vlglab {
  char *label;
  int lablnode;			/* for now I am using -11 value for it. */
  Set go2node;
};

/*****************************************************************************/


# include <search.h>		/* for cmplglabs () */

static int cmplglabs (void *g1,  void *g2)
{
  if (g1 && g2) 
    return 0;
  else
    return strcmp (((struct c2vlglab *)g1)->label, ((struct c2vlglab *)g2) ->label);
}

static struct c2vlglab *addsearch_label (char *ident, int node)
{
  struct c2vlglab *tmp;
  struct c2vlglab *test = XMALLOC (struct c2vlglab, 1);
  test -> label = ident;
  /* test -> lablnode = node; */
  test -> go2node = (Set) 0;

  if ((tmp = tsearch (test, &golabs, cmplglabs))
      != test) {
    XFREE (test);
    XFREE (ident);
  }
  if (node >= 0)
    tmp -> lablnode = node;
  return tmp;
}

int put_out_node (char *ident, int node)
{
  struct c2vlglab *retval = addsearch_label (ident, -11);
  if (retval -> lablnode < 0)
    insert (JUMP, node, &(retval->go2node) );
  return retval->lablnode;
}

Set *put_lable_node (char *ident, int node)
{
  return &((addsearch_label (ident, node)) -> go2node);
}

/*****************************************************************************/
# include <list.h>

struct casnode {
  struct casnode *next;
  char *copy;
  int node;
};

//void push (unsigned int node, char *ptr, struct casnode **ptrcasroot)
void push (unsigned int node, char *ptr, void **ptrcasroot)
{
  struct casnode *tmp = (struct casnode *) XMALLOC (struct casnode, 1);
  tmp -> next = NULL;
  tmp -> copy = ptr;
  tmp -> node = node;

  *ptrcasroot = list_cons ((List *) tmp, (List *) *ptrcasroot);
}

//unsigned int pop (char **string, struct casnode **ptrcasroot)
unsigned int pop (char **string, void **ptrcasroot)
{
  struct casnode *retval =  *ptrcasroot;
  unsigned int tmp;
  if (retval == NULL) return -1; /* stack finish */
  *ptrcasroot = ((struct casnode *) (*ptrcasroot)) -> next;
  *string = retval -> copy;
  tmp = retval -> node;
  XFREE (retval);
  return tmp;			
/* note: it is valid to case node as return value, till we use non -ve
   for node's. */
}
