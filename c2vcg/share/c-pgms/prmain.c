
main()
  {
        int choice;
        menu:
        
	printf("\n\n\t  MENU ");
	printf("\n\t1: add an element to que");
	printf("\n\t2: delete an element ");
	printf("\n\t3: display queue");
	printf("\n\t4: exit ");
	printf("\n\tAny other choice will lead you to exit ");
	printf("\n\t enter the choice   :");
	scanf("%d",&choice);
	
	
	switch (choice)
	{
	  case 1:
	  {
	          n++;
		  hadd();
		  break;
          }
	  case 2:
	  {
		  delete();
	          break;
          }
	  case 3:
	 {
		  display();
	          break;
          }
	  case 4:
	  {
		  exit(0);
	  }
	  default :exit(0);
        }	/* end of switch */

	goto menu;
   }
    /* end of main */
