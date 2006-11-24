/* @(#)scan.l -- Briefly describe here 
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
# include "c2vcg.h"
# include "gram.h"
# include <stdio.h>
# include <string.h>

# define SKIPYYTEXT    { count (); }

int column = 0;
int line = 1;
static char fmtbuff [1000];

char *fmtvcg (char *trg);   // only needed by scan.l
void setyylval ();
void count();

%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
WS			[ \t\n]+
STRQ		        [^\\\"]|\\.
STRING		        \"({STRQ}*)\"
COMM		        \/\*[^\*]*\*+([^\*\/][^\*]*\*+)*\/
COMME		        \/\/[^\n]*


%%

"auto"			{  setyylval (); return(AUTO); }
"break"			{  setyylval (); return(BREAK); }
"case"			{  setyylval (); return(CASE); }
"char"			{  setyylval (); return(CHAR); }
"const"			{  setyylval (); return(CONST); }
"continue"		{  setyylval (); return(CONTINUE); }
"default"		{  setyylval (); return(DEFAULT); }
"do"			{  setyylval (); return(DO); }
"double"		{  setyylval (); return(DOUBLE); }
"else"			{  setyylval (); return(ELSE); }
"enum"			{  setyylval (); return(ENUM); }
"extern"		{  setyylval (); return(EXTERN); }
"float"			{  setyylval (); return(FLOAT); }
"for"			{  setyylval (); return(FOR); }
"goto"			{  setyylval (); return(GOTO); }
"if"			{  setyylval (); return(IF); }
"int"			{  setyylval (); return(INT); }
"long"			{  setyylval (); return(LONG); }
"register"		{  setyylval (); return(REGISTER); }
"return"		{  setyylval (); return(RETURN); }
"short"			{  setyylval (); return(SHORT); }
"signed"		{  setyylval (); return(SIGNED); }
"sizeof"		{  setyylval (); return(SIZEOF); }
"static"		{  setyylval (); return(STATIC); }
"struct"		{  setyylval (); return(STRUCT); }
"switch"		{  setyylval (); return(SWITCH); }
"typedef"		{  setyylval (); return(TYPEDEF); }
"union"			{  setyylval (); return(UNION); }
"unsigned"		{  setyylval (); return(UNSIGNED); }
"void"			{  setyylval (); return(VOID); }
"volatile"		{  setyylval (); return(VOLATILE); }
"while"			{  setyylval (); return(WHILE); }

{L}({L}|{D})*		{  setyylval (); return(check_type()); }

0[xX]{H}+{IS}?		{  setyylval (); return(CONSTANT); }
0{D}+{IS}?		{  setyylval (); return(CONSTANT); }
{D}+{IS}?		{  setyylval (); return(CONSTANT); }
'(\\.|[^\\'])+'		{  yylval.stat = (Stat *) malloc (sizeof (Stat));
                           yylval.stat->copy = strdup (fmtvcg (yytext));
                           yylval.stat->flows = NULL;
                           count (); return(CONSTANT); }

{D}+{E}{FS}?		{  setyylval (); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{  setyylval (); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{  setyylval (); return(CONSTANT); }

{STRING}           	{  yylval.stat = (Stat *) malloc (sizeof (Stat));
                           yylval.stat->copy = strdup (fmtvcg (yytext));
                           yylval.stat->flows = NULL;
                           count (); return(STRING_LITERAL); }

{COMM}			{ SKIPYYTEXT; }
{COMME}			{ SKIPYYTEXT; }


">>="			{  setyylval (); return(RIGHT_ASSIGN); }
"<<="			{  setyylval (); return(LEFT_ASSIGN); }
"+="			{  setyylval (); return(ADD_ASSIGN); }
"-="			{  setyylval (); return(SUB_ASSIGN); }
"*="			{  setyylval (); return(MUL_ASSIGN); }
"/="			{  setyylval (); return(DIV_ASSIGN); }
"%="			{  setyylval (); return(MOD_ASSIGN); }
"&="			{  setyylval (); return(AND_ASSIGN); }
"^="			{  setyylval (); return(XOR_ASSIGN); }
"|="			{  setyylval (); return(OR_ASSIGN); }
">>"			{  setyylval (); return(RIGHT_OP); }
"<<"			{  setyylval (); return(LEFT_OP); }
"++"			{  setyylval (); return(INC_OP); }
"--"			{  setyylval (); return(DEC_OP); }
"->"			{  setyylval (); return(PTR_OP); }
"&&"			{  setyylval (); return(AND_OP); }
"||"			{  setyylval (); return(OR_OP); }
"<="			{  setyylval (); return(LE_OP); }
">="			{  setyylval (); return(GE_OP); }
"=="			{  setyylval (); return(EQ_OP); }
"!="			{  setyylval (); return(NE_OP); }
";"			{  yylval.stat = NULL; count (); return(';'); }
"{"			{  yylval.stat = NULL; count (); return('{'); }
"}"			{  yylval.stat = NULL; count (); return('}'); }
","			{  yylval.stat = NULL; count (); return(','); }
":"			{  yylval.stat = NULL; count (); return(':'); }
"="			{  yylval.stat = NULL; count (); return('='); }
"("			{  yylval.stat = NULL; count (); return('('); }
")"			{  yylval.stat = NULL; count (); return(')'); }
"["			{  yylval.stat = NULL; count (); return('['); }
"]"			{  yylval.stat = NULL; count (); return(']'); }
"."			{  yylval.stat = NULL; count (); return('.'); }
"&"			{  yylval.stat = NULL; count (); return('&'); }
"!"			{  yylval.stat = NULL; count (); return('!'); }
"~"			{  yylval.stat = NULL; count (); return('~'); }
"-"			{  yylval.stat = NULL; count (); return('-'); }
"+"			{  yylval.stat = NULL; count (); return('+'); }
"*"			{  yylval.stat = NULL; count (); return('*'); }
"/"			{  yylval.stat = NULL; count (); return('/'); }
"%"			{  yylval.stat = NULL; count (); return('%'); }
"<"			{  yylval.stat = NULL; count (); return('<'); }
">"			{  yylval.stat = NULL; count (); return('>'); }
"^"			{  yylval.stat = NULL; count (); return('^'); }
"|"			{  yylval.stat = NULL; count (); return('|'); }
"?"			{  yylval.stat = NULL; count (); return('?'); }

[ \t\v\n\f]		{ SKIPYYTEXT }
.			{ SKIPYYTEXT /* ignore bad characters */ }
#.*			{ SKIPYYTEXT } 
<<EOF>>                 { return (systpdf ? FILEEND : 0); }
%%



yywrap ()
{
	return(1);
}

/* comment () */
/* { */
/* 	char c, c1; */

/* coloop: */
/* 	while ((c = input()) != '*' && c != 0) */
/* 		//putchar(c); */
/* 		; */

/* 	if ((c1 = input()) != '/' && c != 0) */
/* 	{ */
/* 		unput(c1); */
/* 		goto coloop; */
/* 	} */

/* 	if (c != 0) */
/* 		//putchar(c1); */
/* 		; */
/* } */


void swap (FILE **f1, FILE **f2)
{
  FILE *hold = *f1;
  *f2 = *f1;
  *f1 = hold;
}

void count ()
{
	register int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n') {
		  column = 0;
		  if (src_file_enter) line++;
		} else if (yytext[i] == '\t')
		  column += 8 - (column % 8);
		else
		  column++;

	if (echo) fputs (yytext, echoout);
}


int check_type()
{

  //pseudo code --- this is what it should check

	if ( sym_check(yytext) != 0)
		return(TYPE_NAME);

	return(IDENTIFIER);
}


int gettypedef (char *buff)
{
//  enum yytokentype token = CHAR;
  int token = CHAR;
  int matchbrace = 0;
  //char *typdfname;
  YY_BUFFER_STATE in = YY_CURRENT_BUFFER;
  yy_scan_string (buff);

  while (token != IDENTIFIER /*&& token != EOF*/
	 && token != TYPE_NAME) { /* it is possible for some pgmr to 
				   * retypedef type_name.
				   */
    /* this EOF is source of problems, should never be here */
    token = yylex ();

    if ((token == STRUCT || token == UNION || token == ENUM) 
	&& (token = yylex ()) ) {
      if (token == IDENTIFIER)
	if ((token = yylex ()) == IDENTIFIER)
	  break;

      if (token == '{') {
	matchbrace = 1;
	while (matchbrace)
	  if ((token = yylex ()) == '{') ++matchbrace;
	  else if (token == '}') --matchbrace;
      }
    }
  }

  if (token == IDENTIFIER) {
    //typdfname = strdup (yytext);
    //typdfname = yytext;
    sym_lookup (yytext);
/*     if (!addbst_node (tpdf, yytext/\*typdfname*\/, yyleng + 1)) */
/*    /\* control never come here, bcoz token == TYPENAME, != IDENTIFIER *\/ */
/*       fprintf (logfile, "gettypedef: Duplicate typedef" */
/* 	       "definition `%s'\n", yytext/\*typdfname*\/); */

#ifdef DEBUG
/*     fprintf (debuglog, "\ngettypedef: Typedefs in Store."); */
/*     btreeprint (debuglog, tpdf); */
/*     fprintf (debuglog, "\ngettypedef: Typedefs End"); */
    id_sym_write (debuglog);
#endif
  }

  yy_switch_to_buffer(in);
}

char *fmtvcg (char *trg)
{
  //char *buffptr = fmtbuff;
  char *buffptr = fmtbuff;	/* keep in mind that ever buff never come in */
  //char *tofree = trg;    	/* mask of trg */
#ifdef DEBUG
//  fprintf (logfile, "\nfmtvcg: Yes coming with %s", trg);
#endif

  while (*trg)
    {
      if (*trg == ',' || *trg == '"'
	  || *trg == '%' || *trg == '\\')
	*buffptr++ = '\\';
      *buffptr++ = *trg++;
    }
  *buffptr = *trg;

#ifdef DEBUG
//  fprintf (logfile, "\nfmtvcg: End going with %s", fmtbuff);
#endif
  
  //	if (fopt == free) free (tofree);
  
  return fmtbuff;
}


void setyylval ()
{
  yylval.stat = (Stat *) malloc (sizeof (Stat));
  yylval.stat->copy = strdup (yytext);
  yylval.stat->flows = NULL;
  count ();
}


int sysTpdfParse (FILE *infile)
{
//  enum yytokentype token = CHAR;
  int token = CHAR;
  int matchbrace = 0;
  //char *typdfname;
  //YY_BUFFER_STATE in = YY_CURRENT_BUFFER;
  //yy_scan_string (buff);

  //yyin = infile;
  yyrestart (infile);

  while ((token = yylex ()) != FILEEND) {
    //printf ("\n Passing"); fflush (stdout);
    if (token == TYPEDEF) {
      while (token != IDENTIFIER /*&& token != EOF*/) { 
    /* this EOF is source of problems, should never be here */
	token = yylex ();

	if ((token == STRUCT || token == UNION || token == ENUM) 
	    && (token = yylex ()) ) {
	  if (token == IDENTIFIER)
	    if ((token = yylex ()) == IDENTIFIER)
	      break;
	  
	  if (token == '{') {
	    matchbrace = 1;
	    while (matchbrace)
	      if ((token = yylex ()) == '{') ++matchbrace;
	      else if (token == '}') --matchbrace;
	  }
	}
      }
      
      if (token == IDENTIFIER) {
	sym_lookup (yytext);
	//typdfname = strdup (yytext);
/* 	if (!addbst_node (tpdf, yytext, yyleng + 1)) */
/* 	  fprintf (logfile, "sysTpdfParse: Duplicate typedef " */
/* 		   "definition `%s'\n", yytext); // control never come here. */
	
# ifdef DEBUG
/* 	fprintf (debuglog, "\nsysTpdfParse: Typedefs in Store."); */
/* 	btreeprint (debuglog, tpdf); */
/* 	fprintf (debuglog, "\nsysTpdfParse: Typedefs End"); */
/* 	fflush (debuglog); */
	id_sym_write (debuglog);
# endif
      }
    }
  }
  //yy_switch_to_buffer(in);

}


/* void startgph (char *s) */
/* { */

/*   fprintf (gdlout, "\ngraph: {\n"); */
/*   fprintf (gdlout, "\n//  %s\n", s); */

/* } */
