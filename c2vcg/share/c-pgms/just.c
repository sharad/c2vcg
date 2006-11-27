


int main(int argc, char *argv[]) {
   char    c;            /* used for argument parsing */
   struct  termios pts;  /* termios settings on port */
   struct  termios sts;  /* termios settings on stdout/in */
   char   *portname;
   int    speed = 0;     /* used in argument parsing to set speed */
   struct sigaction sact;/* used to initialize the signal handler */

   int     raw = 0;      /* raw mode? */ 
   int     i = 0;        /* used in the multiplex loop */
   int     done = 0;
#  define BUFSIZE 1024
   char    buf[BUFSIZE];

   struct poptOption optionsTable[] = {
	    { "bps", 'b', POPT_ARG_INT, &speed, 0 },
	    { "crnl", 'c', 0, 0, 'c' },
	    { "help", 'H', 0, 0, 'H' },
	    { "hwflow", 'h', 0, 0, 'h' },
	    { "noflow", 'n', 0, 0, 0 },
	    { "raw", 'r', 0, &raw, 0 }, 
	    { "swflow", 's', 0, 0, 's' },
	    { NULL, 0, 0, NULL, 0 }
   };

#ifdef DSLEEP
   /* wait 10 minutes so we can attach a debugger */
   sleep(600);
#endif

   if (argc < 2) usage(1, "Not enough arguments", "");
}
