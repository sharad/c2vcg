/* @(#)gram.y -- grammar is approximatly equals to "The C Programming Language" K&R 's grammar.
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


/** @end 1 */

%{
#if HAVE_CONFIG_H
#  include <config.h>
#endif

# include <stdio.h>
# include <string.h>

# include "c2vcg.h"
# include "memmgm.h"
# include "output.h"


# define BEGINSUBGRPH(ntrml) if (pgmargs.forms & (01 << (ntrml - 1))) {\
                                nlindenting (subgrphdepth++, gdlout);\
                                fputs ("graph: {", gdlout);\
                                nlindenting (subgrphdepth, gdlout);\
                                fprintf (gdlout, "title: \"graph %d\"",\
                                         subgraph++);\
                             }

# define ENDSUBGRPH(ntrml)   if (pgmargs.forms & (01 << (ntrml - 1))) {\
                               nlindenting (subgrphdepth--, gdlout);\
                               fputs ("}", gdlout);\
                             }

# define FUNSFRM   1
# define STATSFRM  2
/* # define ALLSFRM     3 */
%}

%union { Stat *stat; }


%token <stat> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token <stat> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <stat> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <stat> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token <stat> XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token <stat> TYPEDEF EXTERN STATIC AUTO REGISTER

%token <stat> CHAR SHORT INT LONG SIGNED UNSIGNED
%token <stat> FLOAT DOUBLE CONST VOLATILE VOID

%token <stat> STRUCT UNION ENUM ELIPSIS RANGE

%token <stat> CASE DEFAULT IF ELSE SWITCH WHILE
%token <stat> DO FOR GOTO CONTINUE BREAK RETURN 

%token <stat> FILEEND
%token <stat> '%' '!' '-' '+' ',' ';' ':' '&' '*' '^' '['
%token <stat> ']' '{' '}' '(' ')' '=' '/' '?' '>' '<' '|' '.' '~'

%type <stat> translation_unit
%type <stat> external_declaration external_declaration0
%type <stat> function_definition function_body declaration
%type <stat> declaration_list declaration_specifiers
%type <stat> storage_class_specifier type_specifier type_qualifier
%type <stat> struct_or_union_specifier struct_or_union
%type <stat> struct_declaration_list init_declarator_list
%type <stat> init_declarator struct_declaration
%type <stat> specifier_qualifier_list struct_declarator_list
%type <stat> struct_declarator enum_specifier enumerator_list
%type <stat> enumerator declarator direct_declarator pointer
%type <stat> type_qualifier_list parameter_type_list parameter_list
%type <stat> parameter_declaration identifier_list initializer
%type <stat> initializer_list type_name abstract_declarator
%type <stat> direct_abstract_declarator typedef_name statement statement0
%type <stat> labeled_statement expression_statement compound_statement
%type <stat> statement_list selection_statement iteration_statement
%type <stat> jump_statement identifier expr assignment_expr
%type <stat> assignment_operator conditional_expr constant_expr
%type <stat> logical_or_expr logical_and_expr inclusive_or_expr
%type <stat> exclusive_or_expr and_expr equality_expr relational_expr
%type <stat> shift_expr additive_expr multiplicative_expr cast_expr
%type <stat> unary_expr unary_operator postfix_expr primary_expr
%type <stat> argument_expr_list constant string_litr


%start translation_unit

%%

/* translation_unit: */
/*         { graphstart (); } translation_unit0   { graphend (); } */
/*         ; */

translation_unit:
	external_declaration

	| translation_unit external_declaration
	;

external_declaration:
        { BEGINSUBGRPH(FUNSFRM) }

        external_declaration0   { $$ = $2; { ENDSUBGRPH(FUNSFRM) } }
        ;

external_declaration0:
        function_definition	{ $$ = $1; }

	| declaration  {
	                sketch_node (++ node, ($$ = $1)->copy, NULL, NULL);
	                $$->copy = NULL;  
	               }
	;


/* function_definition: */
/*         { BEGINSUBGRPH } function_definition0    { $$ = $2; { ENDSUBGRPH } } */
/*         ; */


function_definition:
	declarator function_body
	  	{
		  int ret = 0;

		  sketch_edge (EDGE, ++ node, $2->flows->entry, NULL, NULL);

		  ret = sketchout_edges (PASS, &($2->flows->outs), node + 1,
				     FORWARD);
		  sketch_node (node,
			   copyfmt ("Enter: %s", ret ?
				     strdup (($$ = $1)->copy) : $$->copy),
			   NULL, "34");

		  if (ret)
		    sketch_node (++node, copyfmt ( "End: %s", $$->copy),
			     NULL, "34"); // end node.

		  $$->copy = NULL;
		  $$->flows = get_flows (node - (ret&1), SIMPLE,
					ret ? $2->flows->entry : NULLNODE);
		  
		  freestat ($2); 
		}

	| declaration_specifiers declarator function_body
		{
		  int ret = 0;
		  ($$ = $1)->copy = copyfmt ("%s %s", $1->copy, freestat ($2));

		  sketch_edge (EDGE, ++node, $3->flows->entry, NULL, NULL);
		  ret = sketchout_edges (PASS, &($3->flows->outs), node + 1, FORWARD);

		  sketch_node (node, copyfmt ("Enter: %s", ret ? 
					  strdup ($$->copy) : $$->copy),
			   NULL, "34");

		  if (ret)
		    sketch_node (++node, copyfmt ( "End: %s", strdup ($$->copy)),
			     NULL, "34"); // end node.

		  $$->copy = NULL;
		  $$->flows = get_flows (node - (ret & 1), SIMPLE,
					ret ? $3->flows->entry : NULLNODE);
		  freestat ($3);
		}
	;

function_body:
	compound_statement	  	                {$$ = $1;}

	| declaration_list compound_statement		{$$ = $1;}
	;


declaration:
	  declaration_specifiers ';' {
	        ($$ = $1)->copy = copyfmt ( "%s;", $1->copy);
		}

	| declaration_specifiers init_declarator_list ';' {
	  ($$ = $1)->copy = copyfmt ( "%s %s;", $1->copy, freestat ($2));
	  if (!strncmp ($$->copy, "typedef", 7))
	    gettypedef ($$->copy);  // magic
		
	}
	;

declaration_list:
	declaration {
	        $$ = $1;
	  //$$->copy = copyfmt (NULL, $1->copy);
		}
	| declaration_list declaration {
	        ($$ = $1)->copy = copyfmt ( "%s\n%s", $1->copy, freestat ($2));
		}
	;

declaration_specifiers:
	  storage_class_specifier 
                                {$$ = $1;}
	  
	| storage_class_specifier declaration_specifiers
                  {
		    ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, 
						freestat ($2));
		  }

	| type_specifier        {$$ = $1;}

	| type_specifier declaration_specifiers
                  {
		    ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, 
						freestat ($2));
		  }

	| type_qualifier        {$$ = $1;}

	| type_qualifier declaration_specifiers
                  { 
		    ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy,
						freestat ($2));
		  }
	;


storage_class_specifier:
	  TYPEDEF	             {$$ = $1;}
	| EXTERN	             {$$ = $1;}
	| STATIC	             {$$ = $1;}
	| AUTO		             {$$ = $1;}
	| REGISTER	             {$$ = $1;}
	;

type_specifier:
	  VOID		             {$$ = $1;}
	| CHAR		             {$$ = $1;}
	| SHORT		             {$$ = $1;}
	| INT		             {$$ = $1;}
	| LONG		             {$$ = $1;}
	| FLOAT		             {$$ = $1;}
	| DOUBLE	             {$$ = $1;}
	| SIGNED	             {$$ = $1;}
	| UNSIGNED	             {$$ = $1;}
	| struct_or_union_specifier  {$$ = $1;}
	| enum_specifier             {$$ = $1;}
	| TYPE_NAME	             {$$ = $1;}
	;

type_qualifier:
	  CONST		 {$$ = $1;}
	| VOLATILE	 {$$ = $1;}
	;

struct_or_union_specifier:
        struct_or_union identifier '{' struct_declaration_list '}' {
	        ($$ = $1)->copy = copyfmt ( "%s %s {%s}", $1->copy,
					    freestat ($2), freestat ($4));
		}
	| struct_or_union '{' struct_declaration_list '}' {
	        ($$ = $1)->copy = copyfmt ( "%s {%s}", $1->copy, freestat($3));
		}
	| struct_or_union identifier {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	;

struct_or_union:
	  STRUCT	{$$ = $1;}
	| UNION		{$$ = $1;}
	;

struct_declaration_list:
	struct_declaration	{$$ = $1;}

	| struct_declaration_list struct_declaration {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	;

init_declarator_list:
	init_declarator	{$$ = $1;}

	| init_declarator_list ',' init_declarator {
	        ($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

init_declarator:
	declarator	{$$ = $1;}

	| declarator '=' initializer {
	        ($$ = $1)->copy = copyfmt ( "%s=%s", $1->copy, freestat ($3));
		}
	;

struct_declaration:
	  specifier_qualifier_list struct_declarator_list ';' {
	        ($$ = $1)->copy = copyfmt ( "%s %s;", $1->copy, freestat ($2));
		}
	;

specifier_qualifier_list:
	type_specifier	{$$ = $1;}

	| type_specifier specifier_qualifier_list {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}

	| type_qualifier	{$$ = $1;}

	| type_qualifier specifier_qualifier_list {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	;

struct_declarator_list:
	struct_declarator	{$$ = $1;}

	| struct_declarator_list ',' struct_declarator {
	        ($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

struct_declarator:
        declarator	{$$ = $1;}

	| ':' constant_expr {
	        ($$ = $2)->copy = copyfmt ( ": %s", $2->copy);
		}
	| declarator ':' constant_expr {
	        ($$ = $1)->copy = copyfmt ( "%s: %s", $1->copy, freestat ($3));
		}
	;

enum_specifier:
	ENUM '{' enumerator_list '}' {
	        ($$ = $3)->copy = copyfmt ( "%s {%s}",
					    freestat ($1), $3->copy);
		}
	| ENUM identifier '{' enumerator_list '}' {
	        ($$ = $2)->copy = copyfmt ( "%s %s {%s}", freestat ($1),
				     $2->copy, freestat ($4));
		}
	| ENUM identifier {
	        ($$ = $2)->copy = copyfmt ( "%s %s", freestat ($1), $2->copy);
		}
	;

enumerator_list:
	enumerator	{$$ = $1;}

	| enumerator_list ',' enumerator {
	        ($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

enumerator:
	identifier	{$$ = $1;}

	| identifier '=' constant_expr {
	        ($$ = $1)->copy = copyfmt ( "%s=%s", $1->copy, freestat($3));
		}
	;

declarator:
	direct_declarator	{$$ = $1;}

	| pointer direct_declarator {
	        ($$ = $2)->copy = copyfmt ( "%s%s", freestat($1), $2->copy);
		}
	;

direct_declarator:
	identifier	{$$ = $1;}

	| '(' declarator ')' {
	        ($$ =$2)->copy = copyfmt ( "(%s)", $2->copy);
		}
	| direct_declarator '[' ']' {
	        ($$ = $1)->copy = copyfmt ( "%s[]", $1->copy);
		}
	| direct_declarator '[' constant_expr ']' {
	        ($$ = $1)->copy = copyfmt ( "%s [%s]", $1->copy, freestat($3));
		}
	| direct_declarator '(' ')' {
	        ($$ = $1)->copy = copyfmt ( "%s ()", $1->copy);
		}
	| direct_declarator '(' parameter_type_list ')' {
	        ($$ = $1)->copy = copyfmt ( "%s (%s)", $1->copy, freestat($3));
		}
	| direct_declarator '(' identifier_list ')' {
	        ($$ = $1)->copy = copyfmt ( "%s (%s)", $1->copy, freestat($3));
		}

	;

pointer:
	'*'	 { $$ = get_stat (strdup ("*"), NULL); }

	| '*' type_qualifier_list {
	        ($$ = $2)->copy = copyfmt ( "*%s", $2->copy);
		}
	| '*' pointer {
	        ($$ =$2)->copy = copyfmt ( "*%s", $2->copy);
		}
	| '*' type_qualifier_list pointer {
	        ($$ = $2)->copy = copyfmt ( "*%s %s", $2->copy, freestat ($3));
		}
	;

type_qualifier_list:
	type_qualifier	{$$ = $1;}

	| type_qualifier_list type_qualifier {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	;

parameter_type_list:
	parameter_list	{$$ = $1;}

	| parameter_list ',' ELIPSIS {
		($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

parameter_list:
	parameter_declaration	{$$ = $1;}

	| parameter_list ',' parameter_declaration {
		($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

parameter_declaration:
	  declaration_specifiers declarator {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	| declaration_specifiers abstract_declarator {
	        ($$ = $1)->copy = copyfmt ( "%s %s", $1->copy, freestat ($2));
		}
	| declaration_specifiers   {
	                ($$ = $1)->copy = copyfmt(NULL, $1->copy);
			}
	;

identifier_list:
	identifier	{$$ = $1;}

	| identifier_list ',' identifier {
		($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy, freestat ($3));
		}
	;

initializer:
	  assignment_expr	{$$ = $1;}

	| '{' initializer_list '}' {
		($$ = $2)->copy = copyfmt ( "{%s}", $2->copy);
		}
	| '{' initializer_list ',' '}' {
		($$ = $2)->copy = copyfmt ( "{%s,} ", $2->copy);
		}
	;

initializer_list:
	  initializer	    {$$ = $1;}

	| initializer_list ',' initializer 
                    { 
		    ($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy,
						freestat ($3));
		    }
	;

type_name:
	  specifier_qualifier_list	{$$ = $1;}

	| specifier_qualifier_list abstract_declarator
                    { 
		    ($$ = $1)->copy = copyfmt ( "%s%s", $1->copy,
						freestat ($2));
		    //$$ = $1;
		    //$$->copy = copyfmt ( "%s %s", $1->copy, $2->copy);
		    //freestat ($2);
		    }
	;

abstract_declarator:
	  pointer	                {$$ = $1;}

	| direct_abstract_declarator	{$$ = $1;}

	| pointer direct_abstract_declarator
                  { 
		    ($$ = $1)->copy = copyfmt ( "%s%s", $1->copy,
						freestat ($2));
		  }
	;

direct_abstract_declarator:
	  '(' abstract_declarator ')' {
		($$ = $2)->copy = copyfmt ( "(%s)", $2->copy);
		}

	| '[' ']'	   { $$ = get_stat (strdup ("[]"), NULL); }

	| '[' constant_expr ']' {
		($$ = $2)->copy = copyfmt ( "[%s]", $2->copy);
		}

	| direct_abstract_declarator '[' ']' {
	        ($$ = $1)->copy = copyfmt ( "%s[]", $1->copy);
		}

	| direct_abstract_declarator '[' constant_expr ']' {
	  ($$ = $1)->copy = copyfmt ( "%s[%s]", $1->copy, freestat ($3));
	        }

	| '(' ')'	{ $$ = get_stat (strdup ("()"), NULL); }

	| '(' parameter_type_list ')' {
	        ($$ = $2)->copy = copyfmt ( "(%s)", $2->copy);
		}

	| direct_abstract_declarator '(' ')' {
	        ($$ = $1)->copy = copyfmt ( "%s()", $1->copy);
		}

	| direct_abstract_declarator '(' parameter_type_list ')' {
	        ($$ = $1)->copy = copyfmt ( "%s(%s)", $1->copy,
					    freestat ($3));
		}
	;

typedef_name:
	identifier	{$$ = $1;}
	;

/* new added */
statement:
        { BEGINSUBGRPH(STATSFRM) }
        statement0            { $$ = $2; { ENDSUBGRPH(STATSFRM) } }
        ;
/* above new added */

statement0:
	labeled_statement	      { $$ = $1; }
        | expression_statement	      { $$ = $1; }
	| compound_statement	      { $$ = $1; }
        | selection_statement	      { $$ = $1; }
        | iteration_statement	      { $$ = $1; }
        | jump_statement	      { $$ = $1; }
	;

labeled_statement:
	identifier ':'		/* can say required, my new added.  */
                {
		  char *ident = strdup ($1->copy);
		  int edgecount;

		  sketch_node (++node, copyfmt ("%s:", ($$ = $1)->copy),
			   NULL, NULL);
		  //sketch_edge (NEAR, node, $3->flows->entry, NULL, NULL);
		  //$$ = $3;
		  $$->flows = get_flows (node,  LABL, node);
				/* must be set to this node, */
				/* check some else solution. */
		  $$->copy = NULL;
		  //if ( (idlabel = 
		  //addsearch_label (ident, node);
		  
			  //)
			  //		      -> lablnode < 0) {
			  //idlabel->lablnode = node;
		  edgecount = sketchout_edges (EDGE,
					       put_lable_node (ident, node),
					       node, FORWARD);
			//}
		  //free (ident);
		}
	| CASE constant_expr ':' statement
		{
		  ($$ = $4)->copy = copyfmt ("%s %s:", freestat ($1),
					     freestat ($2));

		  /* if (pgmargs.caseq == 0)  */
/* 		    sketch_node (++node, $$->copy, NULL, NULL);		   */
/* 		  else */
		  if ($4->flows->sttyp == CAS && pgmargs.casejoin) {
		    char *cas_copy;
		    unsigned int tmp = pop (&cas_copy, &caseroot);
		    push (tmp, copyfmt (pgmargs.casejoin > 0 ?
					"%s\n%s" : "%s %s",
					$$->copy, cas_copy),
			  &caseroot);
		  } else /* no joining */
		    push (++node, $$->copy, &caseroot);



		  if (!($4->flows->sttyp == CAS && pgmargs.casejoin)) {
		    insert (CAS, node, &($$->flows->cas));
		    sketch_edge (pgmargs.caseq ? EDGE : NEAR, node,
				 $4->flows->entry, NULL, NULL);
		  }
		  //if ($$->flows->sttyp == LOOP) forincase = 1;

		  //$$->copy = NULL; // so never try to statement->copy

		  $$->flows->sttyp = CAS; // must belowest.
		}
	| DEFAULT ':' statement	
		{
		  ($$ = $3)->copy = copyfmt ("%s:", freestat ($1));

/* 		  if (pgmargs.caseq == 0)  */
/* 		    sketch_node (++node, $$->copy /\*"default:"*\/, NULL, NULL); */
/* 		  else */
		  if ($3->flows->sttyp == CAS && pgmargs.casejoin) {
		    char *cas_copy;
		    unsigned int tmp = pop (&cas_copy, &caseroot);
		    push (tmp, copyfmt (pgmargs.casejoin > 0 ?
					"%s\n%s" : "%s %s",
					$$->copy, cas_copy),
			  &caseroot);

		  } else
		    push (++node, $$->copy, &caseroot);


		  
		  
		  if (!($3->flows->sttyp == CAS && pgmargs.casejoin)) {
		    insert (CAS, node, &($$->flows->cas));
		    sketch_edge (pgmargs.caseq ? EDGE : NEAR, node, $3->flows->entry, NULL, NULL);
		  }
		  //if ($$->flows->sttyp == LOOP) forincase = 1;

		  $$->copy = NULL; // so never try to statement->copy
		  $$->flows->sttyp = CAS; // must belowest.
		}
	;

expression_statement:
	  ';'
	  	{
			sketch_node (++node, strdup (";"), NULL, NULL);
			$$ = get_stat (NULL, get_flows (node, SIMPLE, node));
		}
	| expr ';'
		{
		  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s",
					   $1->copy), NULL, NULL);
		  $$->copy = NULL;
		  ($$ = $1)->flows = get_flows (node, SIMPLE, node);
		}
	;

compound_statement:
	'{' '}'
                {
		  // if (showemptybody) {
		    $$ = get_stat (strdup ("{  }"), NULL);
		    sketch_node (++node, $$->copy, NULL, NULL);
		    $$->copy = NULL;
		    $$->flows = get_flows (node, SIMPLE, node);
		    // } else
		    // $$ = NULL;
                }
	| '{' statement_list '}'	{$$ = $2;}

	| '{' declaration_list '}'
		{
		  sketch_node (++node, ($$ = $2)->copy, NULL, NULL);
		  $$->copy = NULL;
		  $$->flows = get_flows (node, SIMPLE, node);
		  /* new added */
#ifdef DEBUG
		if ($$->flows) {
		    fprintf (logfile, "\n$$->flow exist in declaration_list"
			     "You may see here Segment fault.");
		    fflush (logfile);
		  }
#endif
		//	$$->flows = get_flows (node, crtnodtyp (node, SIMPLE));
		//have done above
			//$$->flows->entry = node;
			//$$->flows->outs = crtnodtyp (2, node, -1);
		}

	| '{' declaration_list statement_list '}'
		{
		  sketch_node (++node, freestat ($2), NULL, NULL);     //search
		  sketch_edge (EDGE, node, $3->flows->entry, NULL, NULL);
		  //$$->flows->entry = node;
		  ($$ = $3)->copy = NULL;

		  $$->flows->entry = node;
				/* carefully see what had happened. */
				/* find same happening around in it */
		}
	;


statement_list:
	  statement	              { $$ = $1; }
			/* Here */
	| statement_list statement	{ /* check it. crucial point deleteme*/

	  /*int i = */sketchout_edges (PASS, &($1->flows->outs),
			       $2->flows->entry, FORWARD);

	  ($$ = $1)->flows->outs = $2->flows->outs;
	  setunion (&($$->flows->brk), &($2->flows->brk));
	  setunion (&($$->flows->cnt), &($2->flows->cnt));
	  setunion (&($$->flows->cas), &($2->flows->cas));

	  $2->flows->outs = $2->flows->brk =
	    $2->flows->cnt = $2->flows->cas = NULL; /* not necessary */

	  free ($2->flows);
	  //showflows ($$->flows->outs, "statlist stat: Joining:");
	  freestat ($2);
	  /* here make sure to free one non-terminal. -- sharad */
	  	//$$->flows->entry = $1->flows->entry; /* search flows */
	}
	;


selection_statement:
        IF '(' expr ')' statement
	  /* will creat 1 node, 3 edges: 1 internal, 2 outgoing. */
	{
	  //printf ("\n COPY %s", $5->copy); fflush (stdout);
	  //showflows ($5->flows->outs, "if ex stat:");
	  //sketch_node (++node, copyfmt ( "if\\n%s", freestat ($3)),
	  sketch_node (++node, copyfmt ( "if\\n%s", freestat ($3)),
		       "rhomb", "33");
	  sketch_edge (BENTNEAR, node, $5->flows->entry, "true", NULL);
	  
	  ($$ = $5)->flows->entry = node;
	  $$->flows->sttyp = SEL; // see if it is SEL.
	  //free ($$->copy);
	  $$->copy = NULL;

	  insert (SEL, node, &($$->flows->outs));



	  //freestat ($3);
#ifdef DEBUG
	  if ($$->copy)
	    {
	      fprintf (logfile, "\n$$->copy exist %s"
		       "You may see here Segment fault."
		       "\n\t\tGood Bye", $$->copy);
	      fflush (logfile);
	      free ($$->copy);
	      $$->copy = NULL;
	    }
#endif
	}
	| IF '(' expr ')' statement ELSE statement
	  /* will creat 1 node, 4 edges: 2 internal, 2 outgoing. */
		{
		  sketch_node (++node, copyfmt ("if\\n%s", freestat ($3)),
			   "rhomb", "33");
		  //$$->flows->entry = node;

		  sketch_edge (BENTNEAR, node, $5->flows->entry, "true", NULL);
		  sketch_edge (BENTNEAR, node, $7->flows->entry, "false",NULL);
		  
		  ($$ = $5)->flows->entry = node;
		  $$->flows->sttyp = SIMPLE; // see if it is SEL.
		  //free ($$->copy);
		  $$->copy = NULL;

		  setunion (&($$->flows->outs), &($7->flows->outs));
		  setunion (&($$->flows->brk), &($7->flows->brk));
		  setunion (&($$->flows->cnt), &($7->flows->cnt));
		  setunion (&($$->flows->cas), &($7->flows->cas));
		  
		  free ($7->flows);
		  freestat ($7);
		}

	| { push (-11, NULL, &caseroot); } SWITCH '(' expr ')' statement
	  /* creat 1 node, 2 edges - 1 internal, 1 outgoing. */
	{
		int cascount = 0;
		int prev_casnode = 0;	/* add Sat May 20 */
		int casnode;
		char *cas_copy;

	  	sketch_node (/*$$->flows->entry = */++node,
			 copyfmt ( "switch\\n%s", freestat ($4)),
			 "triangle", "42");

		if ($6->flows->sttyp != CAS)
		  sketch_edge (EDGE, node, $6->flows->entry, NULL, NULL);


		if (pgmargs.caseq) /* non 0 caseq means parallel */
		  cascount =  sketchout_edges (BENTNEAR, &($6->flows->cas), node,
					 REVERSE);


		while (/*cascount-- &&  what to do. */
		       ( (casnode
			  = pop (&cas_copy, &caseroot) ) >= 0)) {

		  if (prev_casnode && pgmargs.caseq >= 0)
		    if (pgmargs.caseq == 0)
		      sketch_edge (EDGE, casnode, prev_casnode,
				   NULL, NULL);
		    else 
		      sketch_edge (NEAR, casnode, prev_casnode,
				   NULL, "invisible");


		  /* added Sat May 20, see effect by setting
		     pgmargs.caseq 0 or > 0 Do not worry about
		     it, it will not sketch edge between 0 and
		     casnode, because of above if expression.*/
		  
		  sketch_node (prev_casnode = casnode, cas_copy, NULL, NULL);
		}

		if (pgmargs.caseq == 0)
		  sketch_edge (NEAR, node, prev_casnode, NULL, NULL);


		($$ = $6)->flows->entry = node;
		$$->flows->sttyp = SIMPLE;
		$$->copy = NULL;

		setunion (&($$->flows->outs), &($6->flows->brk));

		$$->flows->brk = NULL; //must done.
		

             /* must be done. otherwise in recursive switch case:
	      * switch previous switch consider it as CAS
	      * statement. and creating problems by expecting or
	      * seeing for *($$->flows->cas->node)
	      */


	     /* Yes we are doing for condition pgmargs.casejoin
	      * is non zero the reason is that
	      */
	}
	;

iteration_statement:
	  WHILE '(' expr ')' statement
	  /*will creat 1 node and 3 edges: 2 intern, 1 outgoing. */
	  {
	  	sketch_node (++node, copyfmt ( "while\\n%s", freestat ($3)),
			 "rhomb", "33");
		sketch_edge (BENTNEAR, node, $5->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &($5->flows->outs), node, FORWARD);
		sketchout_edges (BACK, &($5->flows->cnt), node, FORWARD);

		($$ = $5)->flows->entry = node;
		$$->flows->sttyp = LOOP;
		$$->copy = NULL;

		insert (LOOP, node, &($$->flows->outs) );
		setunion (&($$->flows->outs), &($5->flows->brk));
		$$->flows->brk = NULL;
		// for continue statement.

	  }
	| DO statement WHILE '(' expr ')' ';'
	  {
	    sketch_node (++node, strdup ("do"), NULL, NULL);   //search 
	    sketch_edge (EDGE, node, $2->flows->entry, NULL, NULL);
	    sketch_node (++node, copyfmt ( "while\\n%s", $5->copy),
		     "rhomb", "33");
	    sketchout_edges (EDGE, &($2->flows->outs), node, FORWARD);
	    sketchout_edges (EDGE, &($2->flows->cnt), node, FORWARD);
	    sketch_edge (BENTNEAR, node, node - 1, NULL, NULL);
	    /* check BACK is better than BENTNEAR */

	    ($$ = $2)->flows->entry = node - 1;
	    $$->flows->sttyp = LOOP;
	    //free ($$->copy);
	    $$->copy = NULL;

	    insert (LOOP, node, &($$->flows->outs));
	    setunion (&($$->flows->outs), &($2->flows->brk));
	    $$->flows->brk = NULL;



#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "\nWell: do {..} while () l"
			   "oops 's cnt flows is NULL");
		else
		  fprintf (logfile, "\nWell: do {..} while () l"
			   "oops 's cnt flows is NOT - NULL");
#endif
	    // make sure $2->flows->cnt is null and check it.

	}
	| FOR '(' ';' ';' ')' statement
		{
		sketch_node (++node, strdup ("for (;;)"), "rhomb", NULL);
		sketch_edge (EDGE, node, $6->flows->entry, NULL, NULL);
		sketchout_edges (BENTNEAR/*EDGE*/, &($6->flows->outs), node, FORWARD);	 // should work well
		//if ($6->flows->cnt)
		//sketchout_edges (EDGE, &($6->flows->cnt), node, 0); R
 		sketchout_edges (BACK, &($6->flows->cnt), node, FORWARD); 
		 
		$$ = $6;
		$$->flows->entry = node;
		$$->flows->sttyp = LOOP;
		insert (LOOP, node, &($$->flows->outs));
		setunion (&($$->flows->outs), &($6->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "\nWell: for (;;) loops 's cnt"
			   "flows is NULL");
		else
		  fprintf (logfile, "\nWell: for (;;) loops 's cnt flows"
			   "is NOT - NULL");
#endif
	}
	| FOR '(' ';' ';' expr ')' statement
		{
		sketch_node (++node, strdup ("for ; ;"), "rhomb", NULL);

		//sketch_edge (EDGE, node, $7->flows->entry, NULL, NULL); R
		sketch_edge (BENTNEAR, node, $7->flows->entry, NULL, NULL);
		sketch_node (++node, $5->copy, NULL, NULL);
		//		$5->flows->entry = node;
		//sketchout_edges (EDGE, &($7->flows->outs), node, 0);
		sketchout_edges (/*BENTNEAR*/EDGE, &($7->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); //working well
		//if ($7->flows->cnt)
		//  sketchout_edges (EDGE, &($7->flows->cnt), node - 1, 0); R
		sketchout_edges (/*BENTNEAR*/EDGE, &($7->flows->cnt), node, FORWARD);
		// for continue statement.
		($$ = $7)->flows->entry = node - 1;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node - 1, &($$->flows->outs));
		setunion (&($$->flows->outs), &($7->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "\nWell: for (;;s) loops 's cnt"
			   " flows is NULL");
		else
		  fprintf (logfile, "\nWell: for (;;s) loops 's cnt flows"
			   "is NOT - NULL");
#endif

		}
	| FOR '(' ';' expr ';' ')' statement
		{
		sketch_node (++node, $4->copy, /*fmtvcg ($4->copy),*/
			   "rhomb", "33");
		//$$->flows->entry = node;

		sketch_edge (BENTNEAR, node, $7->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &($7->flows->outs), node, FORWARD); // should work well
		//if ($7->flows->cnt)
		sketchout_edges (BACK, &($7->flows->cnt), node, FORWARD);
		// check n - 1 or n
		// for continue statement.
		($$ = $7)->flows->entry = node;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node, &($$->flows->outs));
		setunion (&($$->flows->outs), &($7->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for ( ;ex; ) loops 's "
			   "cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for ( ;ex; ) loops 's cnt flows"
			   "is NOT - NULL");
#endif
	   }
	| FOR '(' ';' expr ';' expr ')' statement
		{
		sketch_node (++node, $4->copy, "rhomb", "33");

		sketch_edge (BENTNEAR, node, $8->flows->entry, "true", NULL);
		sketch_node (++node, $6->copy, NULL, NULL);
		//$6->flows->entry = node;
		sketchout_edges (/*BENTNEAR*/EDGE, &($8->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); // working well
		//if ($8->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &($8->flows->cnt), node, FORWARD);
		// for continue statement.
		($$ = $8)->flows->entry = node - 1;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node - 1, &($$->flows->outs));
		setunion (&($$->flows->outs), &($8->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for ( ;ex;ex) loops "
			   "'s cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for ( ;ex;ex) loops "
			   "'s cnt flows is NOT - NULL");
#endif
	  }
	| FOR '(' expr ';' ';' ')' statement
		{
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, $3->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, strdup ("for\n;;"), "rhomb", "33");

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, $7->flows->entry, NULL, NULL);
		sketchout_edges (BACK/*EDGE*/, &($7->flows->outs), node, FORWARD); //should work well
		//if ($7->flows->cnt)
		sketchout_edges (BACK, &($7->flows->cnt), node, FORWARD);
		// for continue statement.
		$$ = $7;
		$$->flows->entry = node - 1;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node, &($$->flows->outs));
		setunion (&($$->flows->outs), &($7->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for (ex;;) loops 's cnt"
			   "flows is NULL");
		else
		  fprintf (logfile, "Well: for (ex;;) loops 's cnt"
			   " flows is NOT - NULL");
#endif
	 }
	| FOR '(' expr ';' ';' expr ')' statement
		{
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, $3->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, strdup("for\n;;"), "rhomb", "33");

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (EDGE, node, $8->flows->entry, NULL, NULL);
		sketch_node (++node, $6->copy, NULL, NULL);
		//$6->flows->entry = node;   //donot delete.
		sketchout_edges (/*BENTNEAR*/EDGE, &($8->flows->outs), node, FORWARD);
		sketch_edge (BACK/*EDGE*/, node, node - 1, NULL, NULL); // should work well
		//if ($8->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &($8->flows->cnt), node, FORWARD);
		// for continue statement.
		($$ = $8)->flows->entry = node - 1;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node, &($$->flows->outs));
		setunion (&($$->flows->outs), &($8->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for (ex; ;ex) loops 's "
			   "cnt flows is NULL");//, $3->copy, $6->copy);
	        else
		  fprintf (logfile, "Well: for (ex; ;ex) loops 's "
			   "cnt flows is NOT - NULL");//, $3->copy, $6->copy);
#endif
	 }
	| FOR '(' expr ';' expr ';' ')' statement
		{
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, $3->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, $5->copy, "rhomb", "33");
		//$5->flows->entry = node;

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, $8->flows->entry, "true", NULL);
		sketchout_edges (BACK/*EDGE*/, &($8->flows->outs), node, FORWARD); //should work well
		//if ($8->flows->cnt)
		  sketchout_edges (BACK, &($8->flows->cnt), node, FORWARD);
		// for continue statement.
		$$ = $8;
		$$->flows->entry = node - 1;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		insert (LOOP, node, &($$->flows->outs));
		setunion (&($$->flows->outs), &($8->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for (ex;ex; ) loops '"
			   "s cnt flows is NULL");//, $3->copy, $5->copy);
		else
		  fprintf (logfile, "Well: for (ex;ex; ) loops 's"
			   " cnt flows is NOT - NULL");//, $3->copy, $5->copy);
#endif
	}
	| FOR '(' expr ';' expr ';' expr ')' statement
		{
		  //$$->flows->sttyp = LOOP;
		sketch_node (++node, $3->copy, NULL, NULL);
		//$$->flows->entry = node;
		sketch_node (++node, $5->copy, "rhomb", "33");
		//$5->flows->entry = node;

		sketch_edge (EDGE, node - 1, node, NULL, NULL);
		sketch_edge (BENTNEAR, node, $9->flows->entry, "true", NULL);
		sketch_node (++node, $7->copy, NULL, NULL);
		//$7->flows->entry = node; // donot delete.
		sketchout_edges (/*BENTNEAR*/EDGE, &($9->flows->outs), node, FORWARD); //should work well
		sketch_edge (BACK, node, node - 1, NULL, NULL);
		//if ($9->flows->cnt)
		sketchout_edges (/*BENTNEAR*/EDGE, &($9->flows->cnt), node, FORWARD);
		// for continue statement.


		($$ = $9)->flows->entry = node - 2;
		$$->flows->sttyp = LOOP;
		//free ($$->copy);
		$$->copy = NULL;

		//we are reusing flows struct and $$->flows->outs is NULL here.

		insert (LOOP, node - 1, &($$->flows->outs));
		setunion (&($$->flows->outs), &($9->flows->brk));
		$$->flows->brk = NULL;


#ifdef DEBUG
		if (!($$->flows->cnt))
		  fprintf (logfile, "Well: for (ex;ex;ex) loops "
			   "'s cnt flows is NULL");
		else
		  fprintf (logfile, "Well: for (ex;ex;ex) loops "
			   "'s cnt flows is NOT - NULL");
#endif
		freestat ($1); freestat ($3); freestat ($5); freestat ($7);
	}
	;

jump_statement:
	  GOTO identifier ';'
			{
			  int label;
			  char *ident = strdup ($2->copy); /* used to send */
			  /* handle function. */
			  sketch_node (++node,
				   copyfmt ( pgmargs.semicolon ? "goto %s;":
					     "goto %s", $2->copy),
				   NULL, NULL);
			  $$ = $2;
			  $$->copy = NULL;
			  $$->flows = get_flows (node, NONODE, NULLNODE); /* entry is */
			  /* here, but no outs, except to (int label) */
			  if ((label = put_out_node (ident, node)) >= 0)
			    sketch_edge (BACK, node, label, NULL, NULL);
			  freestat ($1); // free it $1->copy also.
			}
	| CONTINUE ';'
			{
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", $1->copy),
				   NULL, NULL);
			  $$ = $1;
			  $$->copy = NULL;
			  $$->flows = get_flows (node, NONODE, NULLNODE);
			  insert (JUMP, node, &($$->flows->cnt));
			}
	| BREAK ';'
			{
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", $1->copy),
				   NULL, NULL);
			  $$ = $1;
			  $$->copy = NULL;
			  $$->flows = get_flows (node, NONODE, NULLNODE);
			  insert (JUMP, node, &($$->flows->brk));
			}
	| RETURN ';'
			{
			  sketch_node (++node, copyfmt(pgmargs.semicolon ? "%s;" : "%s", $1->copy),
				   NULL, NULL);
			  $$ = $1;
			  $$->copy = NULL;
			  $$->flows = get_flows (node, NONODE, NULLNODE);
			}
	| RETURN expr ';'
                        {
			  sketch_node (++node,
				   copyfmt ( pgmargs.semicolon ? "return %s;" : "return %s", $2->copy),
				   NULL, NULL);
			  $$ = $2;
			  $$->copy = NULL;
			  $$->flows = get_flows (node, NONODE, NULLNODE);
			  freestat ($1);
			}
	;

identifier:
    	    IDENTIFIER	           { $$ = $1; }

          | TYPE_NAME              { $$ = $1; }
	  ;

expr:
	assignment_expr         {$$ = $1;}

	| expr ',' assignment_expr
		 { $$ = $1;
		   $$->copy = copyfmt ( "%s, %s", $1->copy, $3->copy);
		   freestat ($3); }
	;

assignment_expr:
	conditional_expr	{$$ = $1;}
	  
	| unary_expr assignment_operator assignment_expr
	           { 
		     ($$ = $1)->copy = copyfmt ( "%s%s%s", $1->copy,
					  freestat ($2), freestat ($3));
		   }
	;

assignment_operator:
	'='		    { $$ = get_stat (strdup ("="), NULL); }
	  /* printf ("\ngoing to bh sizeof Stat %d", sizeof (Stat)); */
/* 	  fflush (stdout); */
	  /* I think there is problem in malloc implementation.
	   * only
	   * no problem were with double free()ing  of some address.
	   */

	| MUL_ASSIGN	        {$$ = $1;}
	| DIV_ASSIGN	        {$$ = $1;}
	| MOD_ASSIGN	        {$$ = $1;}
	| ADD_ASSIGN	        {$$ = $1;}
	| SUB_ASSIGN	        {$$ = $1;}
	| LEFT_ASSIGN	        {$$ = $1;}
	| RIGHT_ASSIGN	        {$$ = $1;}
	| AND_ASSIGN	        {$$ = $1;}
	| XOR_ASSIGN	        {$$ = $1;}
	| OR_ASSIGN	        {$$ = $1;}
	;

conditional_expr:
	logical_or_expr         {$$ = $1;}

	| logical_or_expr '?' expr ':' conditional_expr
	          {
		    ($$ = $1)->copy = copyfmt ( "%s ? %s:%s", $1->copy,
						freestat ($3), freestat ($5));
		  }
	;

constant_expr:
	conditional_expr	 {$$ = $1;}
	;

logical_or_expr:
	logical_and_expr	{$$ = $1;}

	| logical_or_expr OR_OP logical_and_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s||%s",
					       $1->copy, freestat ($3));
		   free(freestat ($2));
		 }
	;

logical_and_expr:
	inclusive_or_expr	{$$ = $1;}

	| logical_and_expr AND_OP inclusive_or_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s&&%s",
					       $1->copy, freestat ($3));
		   free(freestat ($2));
		 }
	;

inclusive_or_expr:
	exclusive_or_expr	{$$ = $1;}

	| inclusive_or_expr '|' exclusive_or_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s|%s",
						$1->copy, freestat ($3));
		  }
	;

exclusive_or_expr:
	and_expr	        {$$ = $1;}

	| exclusive_or_expr '^' and_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s^%s",
						$1->copy, freestat ($3));
		    //free(freestat ($2));
		  }
	;

and_expr:
	equality_expr	        {$$ = $1;}

	| and_expr '&' equality_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s&%s",
						$1->copy, freestat ($3));
		  }
	;

equality_expr:
	relational_expr	        {$$ = $1;}

	| equality_expr EQ_OP relational_expr
		 {
		   ($$ = $1)->copy = copyfmt ("%s==%s",
					       $1->copy, freestat ($3));
		   free(freestat ($2));		 
		 }

	| equality_expr NE_OP relational_expr
		 {
		   ($$ = $1)->copy = copyfmt ("%s!=%s",
					       $1->copy, freestat ($3));
		   free(freestat ($2));
		 }
	;

relational_expr:
	shift_expr	        {$$ = $1;}

	| relational_expr '<' shift_expr
		  {
		    ($$ = $1)->copy = copyfmt ("%s<%s",$1->copy,
					       freestat ($3)); }

	| relational_expr '>' shift_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s>%s", $1->copy,
						freestat ($3)); }

	| relational_expr LE_OP shift_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s<=%s", $1->copy,
					       freestat ($3));
		   free(freestat ($2));
		 }

	| relational_expr GE_OP shift_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s>=%s", $1->copy,
					       freestat ($3));
		   free(freestat ($2));
		 }
	;

shift_expr:
	additive_expr	        {$$ = $1;}

	| shift_expr LEFT_OP additive_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s<<%s", $1->copy,
					       freestat ($3));
		   free (freestat ($2));
		 }

	| shift_expr RIGHT_OP additive_expr
		 {
		   ($$ = $1)->copy = copyfmt ( "%s>>%s", $1->copy,
					       freestat ($3));
		   free (freestat ($2));
		 }
	;

additive_expr:
	multiplicative_expr	{$$ = $1;}

	| additive_expr '+' multiplicative_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s+%s", $1->copy,
						freestat ($3));
		  }

	| additive_expr '-' multiplicative_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s-%s", $1->copy,
						freestat ($3));
		  }

	;

multiplicative_expr:
	cast_expr	        {$$ = $1;}

	| multiplicative_expr '*' cast_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s*%s", $1->copy,
						freestat ($3));
		  }

	| multiplicative_expr '/' cast_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s/%s", $1->copy,
						freestat ($3));
		  }

	| multiplicative_expr '%' cast_expr
		  {
		    ($$ = $1)->copy = copyfmt ( "%s%%%s", $1->copy,
						freestat ($3));
		  }
	;

cast_expr:
	unary_expr	        {$$ = $1;}

	| '(' type_name ')' cast_expr
                       {
			 ($$ = $2)->copy = copyfmt ("(%s)%s", $2->copy,
						     freestat ($4));
		       }
	;

unary_expr:
	postfix_expr	        {$$ = $1;}

	| INC_OP unary_expr
                        {
			  ($$ = $2)->copy = copyfmt ("++%s", $2->copy);
			  free (freestat ($1));
			}

	| DEC_OP unary_expr
                        {
			  ($$ = $2)->copy = copyfmt ("--%s", $2->copy);
			  free (freestat ($1));
			}

	| unary_operator cast_expr
                      {
			($$ = $2)->copy = copyfmt ("%s%s", freestat ($1),
						    $2->copy);
		      }

	| SIZEOF unary_expr
                      {
			($$ = $2)->copy = copyfmt ( "sizeof %s", $2->copy);
		        free (freestat ($1));
		      }

	| SIZEOF '(' type_name ')'
		      {
			($$ = $3)->copy = copyfmt ("sizeof (%s)", $3->copy);
		        free (freestat ($1));
		      }
	;

unary_operator:
	'&'		{ $$ = get_stat (strdup ("&"), NULL); }

	| '*'		{ $$ = get_stat (strdup ("*"), NULL); }

	| '+'		{ $$ = get_stat (strdup ("+"), NULL); }

	| '-'		{ $$ = get_stat (strdup ("-"), NULL); }

	| '~'		{ $$ = get_stat (strdup ("~"), NULL); }

	| '!'		{ $$ = get_stat (strdup ("!"), NULL); }

	;

postfix_expr:
 	  primary_expr	        {$$ = $1;}

	| postfix_expr '[' expr ']'
                    {
		      ($$ = $1)->copy = copyfmt ("%s [%s]", $1->copy,
						 freestat ($3));
		    }

	| postfix_expr '(' ')'
                    { ($$ =$1)->copy = copyfmt ("%s ()", $1->copy); }

	| postfix_expr '(' argument_expr_list ')'
                    {
		      ($$ = $1)->copy = copyfmt ("%s (%s)", $1->copy,
						 freestat ($3));
		    }

	| postfix_expr '.' identifier
                    {
		      ($$ = $1)->copy = copyfmt ("%s.%s", $1->copy,
						 freestat ($3)); }

	| postfix_expr PTR_OP identifier
		    {
		      ($$ = $1)->copy = copyfmt ("%s->%s", $1->copy,
						 freestat ($3));
		      free (freestat ($2));
		    }

	| postfix_expr INC_OP
	                 {
			   ($$ =$1)->copy = copyfmt ( "%s++", $1->copy);
			   free (freestat ($2));
			 }

	| postfix_expr DEC_OP
	                 {
			   ($$ =$1)->copy = copyfmt ( "%s--", $1->copy);
			   free (freestat ($2));
			 }
	;

primary_expr:
	  identifier		{$$ = $1;}

	| CONSTANT		{$$ = $1;}

/*      | STRING_LITERAL	{$$ = $1;} */
        | string_litr	        {$$ = $1;}
                                /*  fmtvcg needed here also. */
	| '(' expr ')'	    { ($$ = $2)->copy = copyfmt ("(%s)", $2->copy); }
	;

string_litr:
	 STRING_LITERAL             {$$ = $1;}

       | string_litr STRING_LITERAL { /* changed to be compitable with multi */
	                             char *ptr;	/* ".." strings. */
	                             $1->copy [strlen ($1->copy) - 2]
				       = '\0';
				     ptr = strdup (($2->copy) + 2);

				     free (freestat ($2));

	                             ($$ = $1)->copy =
				       copyfmt ( "%s%s", $1->copy, ptr);
                                     }
       ;

argument_expr_list:
	assignment_expr       {$$ = $1;}

	| argument_expr_list ',' assignment_expr 
                 {
		   ($$ = $1)->copy = copyfmt ( "%s, %s", $1->copy,
					       freestat ($3));
		 } 
	;

constant:
	CONSTANT	       {$$ = $1;}

	;

%%
/* 	//extern char yytext[]; */
/* 	//extern int column; */
