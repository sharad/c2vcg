  
     void delete()
     {
       int temp,i;
     
     /* if list is empty then reveal the fact */
     
     if(n<1)
        {
         printf("\n\t WANT TO DELETE AN ELEMENT FROM EMPTY LIST ?");
	  printf("\n\t IMPOSSIBLE ");
	  printf("\n\t :-((");
	  printf("\n\t To make me smile again goto menu ");
	  printf("\n\t :-))");
	  goto endofdel;
	}
     
     /* number to be deleted is 1'st element of list */
    /* interchange it with last element of list */
       temp=list[1];
       list[1]=list[n];
       list[n]=temp;

       printf("\n Deleted element is:%d\t",list[n]);
       /* but element is not actually deleted */
       
       n--;
            /* n decreased by 1 number hence last number is deleted */
	    /* now heap is disturbed so recreate heap */
	    
	    for(i=((n/2)+1);i>=1;i--)
	      {
	        adjust(list,i,n);
              }
       endofdel:
       }
           /* end of delete */
           /* even if you call display we will get heap */

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
