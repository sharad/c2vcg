/* @(#)id-emit.h -- Briefly describe here 
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
#ifndef _ID-EMIT_H
#define _ID-EMIT_H 1



/* bc-emit.h - declare entry points for producing object files of bytecodes. */

/* Internal format of symbol table for the object file. */
struct id_sym
{
  /* Private copy separately malloc'd. */
  char *name;

  /* Symbol has a defined value. */
  //unsigned int defined:1;

  /* Symbol has been globalized. */
  //unsigned int global:1;

  /* Symbol is common. */
  //unsigned int common:1;

  /* Value if defined. */
  //unsigned long int val;

  /* Used in internal symbol table structure. */
  struct id_sym *next;
};

struct id_sym* sym_lookup (char *name);

int sym_check (char *name);


/* List of symbols defined in a particular segment. */
/* struct bc_segsym */
/* { */
/*   struct bc_sym *sym; */
/*   struct bc_segsym *next; */
/* }; */


/* /\* List of relocations needed in a particular segment. *\/ */
/* struct bc_segreloc */
/* { */
/*   /\* Offset of datum to be relocated. *\/ */
/*   unsigned int offset; */

/*   /\* Symbol to be relocated by. *\/ */
/*   struct bc_sym *sym; */

/*   struct bc_segreloc *next; */
/* }; */


/* /\* Segment of an object file. *\/ */
/* struct bc_seg */
/* { */
/*   /\* Size allocated to contents. *\/ */
/*   unsigned int alloc; */

/*   /\* Pointer to base of contents. *\/ */
/*   char *data; */

/*   /\* Actual size of contents. *\/ */
/*   unsigned int size; */

/*   /\* List of symbols defined in this segment. *\/ */
/*   struct bc_segsym *syms; */

/*   /\* List of relocations for this segment. *\/ */
/*   struct bc_segreloc *relocs; */
/* }; */


/* /\* Anonymous bytecode label within a single function. *\/ */
/* struct bc_label */
/* { */
/*   /\* Offset of label from start of segment. *\/ */
/*   unsigned int offset; */

/*   /\* True when offset is valid. *\/ */
/*   unsigned int defined:1; */

/*   /\* Unique bytecode ID, used to determine innermost */
/*      block containment *\/ */
/*   int uid; */

/*   /\* Next node in list *\/ */
/*   struct bc_label *next; */
/* }; */


/* /\* Reference to a bc_label; a list of all such references is kept for */
/*    the function, then when it is finished they are backpatched to */
/*    contain the correct values. *\/ */

/* struct bc_labelref */
/* { */
/*   /\* Label referenced. *\/ */
/*   struct bc_label *label; */

/*   /\* Code offset of reference. *\/ */
/*   unsigned int offset; */

/*   /\* Next labelref in list *\/ */
/*   struct bc_labelref *next; */
/* }; */

/*  */

/* extern void bc_initialize(); */
/* extern int bc_begin_function(); */
/* extern char *bc_emit_trampoline(); */
/* extern void bc_emit_bytecode(); */
/* extern void bc_emit_bytecode_const(); */
/* extern struct bc_label *bc_get_bytecode_label(); */
/* extern int bc_emit_bytecode_labeldef(); */
/* extern void bc_emit_bytecode_labelref(); */
/* extern void bc_emit_code_labelref(); */
/* extern char *bc_end_function(); */
/* extern void bc_align_const(); */
/* extern void bc_emit_const(); */
/* extern void bc_emit_const_skip(); */
/* extern int bc_emit_const_labeldef(); */
/* extern void bc_emit_const_labelref(); */
/* extern void bc_align_data(); */
/* extern void bc_emit_data(); */
/* extern void bc_emit_data_skip(); */
/* extern int bc_emit_data_labeldef(); */
/* extern void bc_emit_data_labelref(); */
/* extern int bc_define_pointer (); */
/* extern int bc_emit_common(); */
/* extern void bc_globalize_label(); */
/* extern void bc_text(); */
/* extern void bc_data(); */
/* extern void bc_align(); */
/* extern void bc_emit(); */
/* extern void bc_emit_skip(); */
/* extern int bc_emit_labeldef(); */
/* extern void bc_emit_labelref(); */
/* extern void bc_write_file(); */



#endif /* _ID-EMIT_H */
/** @end 1 */

