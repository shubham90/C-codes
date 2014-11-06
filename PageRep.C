		/*Author: Shubham Bhawsinka
	    Date: 16 July, 2009*/


		#include<stdio.h>
		#include<conio.h>

		void FIFO(int pg[50],int no)
		{
		int i,j,k=0,l,out[5],flag=0,temp,fault=0,frame[30][10];
		int fsize;
			printf("\n\n Enter the frame size : ");
			scanf("%d",&fsize);
			for(j=0;j<fsize+1;j++)
			{
				out[j]=-1;
			}

			for(i=0;i<no;i++)
			{
				temp=pg[i];
				for(j=0;j<fsize;j++)
			{
			if(out[j]==temp)
			{
				flag=1;			//flag=1 specifies page already
				break;          	//present in the frame
			}
			}
			if(flag!=1)            		//to put the new pg no. in the frame
			{
				if(k==fsize) 		//if k exceeds frame size
				k=0;            	//store from top of frame
				out[k]=temp;
				k++;
				fault++;
			}
			else
				flag=0;
			for(j=0;j<fsize;j++)   		//frame array stores the final
				frame[i][j]=out[j]; 	//frame values
			}
			printf("\n The Pages Entered Are As Follows \n\n");
			for(i=0;i<no;i++)
			{
			printf(" %d ",pg[i]);
			}
			printf("\n\n");
			for(i=0;i<no;i++)
			{
			printf("\n Page %d : ",pg[i]);
			for(j=0;j<fsize;j++)
			{
			printf(" %d ",frame[i][j]);
			}
			printf("\n");
			}
			printf("\n\nTHE PAGE FAULTS ARE : %d ",fault);
			getch();
		}

		void LRU(int pg[50],int no)
		{
		int i,j,p,temp,tmp,max,k=0,l=0,m=0,flag=0,fault=0,out[5],count[10];
		int fsize;
			printf("\n\n Enter the frame size : ");
			scanf("%d",&fsize);
		printf("\n The Pages Entered Are As Follows \n\n");
			for(p=0;p<no;p++)
			{
				printf(" %d ",pg[p]);
			}
			printf("\n\n");
			for(j=0;j<fsize+1;j++)
			{
			out[j]=-1;
			}
			for(i=0;i<no;i++)
			{
			for(j=0;j<fsize+1;j++)  	//count[] is a array to store dist. of new
			count[j]=0;            		//page from the values in the previous frame
			flag=0;
			temp=pg[i];             	//temp is temporary var. to store the
			for(j=0;j<fsize;j++)   		//new page value
			{
				if(out[j]==temp)
				{
					flag=1;		//flag=1 specifies page value already
					break;  	//present in the frame
				}
			 }

			if(flag!=1)            		//to put the new pg no. in the frame
			{
				fault++;
				if(l!=fsize)    	//l specifies the frame no. where
				out[l++]=temp;  	//new value is to stored
				else            	//to find where new page is to be stored
				{               	//when l exceeds frame size
					for(j=0;j<fsize;j++)
				{
					tmp=out[j];
					for(k=i;k>=0;k--)
					{
					if(pg[k]!=tmp)
					count[j]++;    	//count[] array stores the value
					else    	//of the dist.
					break;
				}
				}
				max=count[0];   	//max var. stores the max. dist.
				m=0;
				for(j=0;j<fsize;j++)   	//loop to find the maximum dist.
				{
					if(count[j]>max)
					{
						max=count[j];   //the page have max. dist. is obtained
						m=j;
					}
				}               	//this page value is now replaced
				out[m]=temp;    	//by the new page value
				}
				}
				printf("\n Page %d : ",pg[i]);
				for(j=0;j<fsize;j++)
				{
				printf(" %d ",out[j]);
				}
				printf("\n");
			}
			printf("\n\nTHE PAGE FAULTS ARE : %d ",fault);
			getch();
		}


		void OPTIMAL(int pg[50],int no)
		{
		int p,i,j,k,m,tmp,min,max,temp,l=0,flag=0,fault=0,out[5],count[5];
		int fsize;
			printf("\n\n Enter the frame size : ");
			scanf("%d",&fsize);
			printf("\n The Pages Entered Are As Follows \n\n");
			for(p=0;p<no;p++)
			{
				printf(" %d ",pg[p]);
			}
			printf("\n\n");

			for(j=0;j<fsize+1;j++)  	//out[] is the temporay frame to
			{                       	//store the page values
				out[j]=-1;
			}
			for(i=0;i<(no-1);i++)   	//to perform rep. upto the 2nd last elelment
			{
			for(j=0;j<fsize+1;j++)  	//count[] is a array to store dist. of new
			count[j]=0;            		//page from the values in the previous frame
			flag=0;
			temp=pg[i];
			for(j=0;j<fsize;j++)
			{
				if(out[j]==temp)
				{
				flag=1;         	//flag=1 specifies page value already
				break;          	//present in the frame
				}
			}
			if(flag!=1)            		//to put the new pg no. in the frame
			{
				fault++;
				if(l!=fsize)
				out[l++]=temp;
			else                   		//to find where new page is to be stored
			{                      		//when l exceeds frame size
				for(j=0;j<fsize;j++)  	//loop to find the dist. of new pg.
				{	                //value from right
					tmp=out[j];     //the dist. is cal. from new pg. value
					for(k=i;k<=no;k++)  //to the values in the previous frame
					{
					if(pg[k]!=tmp)
					count[j]++;    	//count[] array stores the value
					else 		//of the dist.
					break;
				}
			}
			max=count[0];          		//max var. stores the max. dist.
			m=0;
			for(j=0;j<fsize;j++)   		//loop to find the maximum dist.
			{
				if(count[j]>max)
				{
					max=count[j];   //the page have max. dist. is obtained
					m=j;
				}
			}                      		//this page value is now replaced
			out[m]=temp;           		//by the new page value
			}
			}
			printf("\n Page %d : ",pg[i]);
			for(j=0;j<fsize;j++)
			{
				printf(" %d ",out[j]);
			}
			printf("\n");
		}
			temp=pg[no-1];  		//LAST REPLACEMENT BY LRU
			i=no-1;
			for(j=0;j<5;j++)
				count[j]=0;
			flag=0;
			temp=pg[i];
			for(j=0;j<fsize;j++)
			{
				if(out[j]==temp)	//flag=1 specifies page already
				{               	//present in the frame
				flag=1;
				break;
			}
			}
			if(flag!=1)            		//to put the new pg no. in the frame
			{
				fault++;
				if(l!=fsize)    	//l specifies the frame no. where
				out[l++]=temp;  	//new value is to stored
				else            	//to find where new page is to be stored
				{	        	//when l exceeds frame size
				for(j=0;j<fsize;j++)
				{
					tmp=out[j];
					for(k=i;k>=0;k--)
					{
					if(pg[k]!=tmp)
					count[j]++;    	//count[] array stores the value
					else    	//of the dist.
					break;
					}
				}
				max=count[0];   	//max var. stores the max. dist.
				m=0;
				for(j=0;j<fsize;j++)   	//loop to find the maximum dist.
				{
					if(count[j]>max)
					{
					max=count[j];   //the page have max. dist. is obtained
					m=j;
					}
				}               	//this page value is now replaced
				out[m]=temp;    	//by the new page value
				fault++;
				}
			}
			printf("\n Page %d : ",pg[no-1]);
			for(j=0;j<fsize;j++)
			printf(" %d ",out[j]);
			printf("\n\nTHE PAGE FAULTS ARE : %d ",fault-1);
			getch();
		}

		void main()
		{
			int choice,i,j,pg[50],no,fsize;
			char ch;
			clrscr();
			printf("\n\t\t\t ** PAGE REPLACEMENT ALGORITHM **");
			printf("\n\n Enter the number of pages : ");
			scanf("%d",&no);
			printf("\n Enter the Pages \n ");
			for(i=0,j=1;i<no;i++,j++)
			{
			printf("\n Enter Page %d) : ",j);
			scanf("%d",&pg[i]);
			}

			for(;;)
			{
				clrscr();
				printf ( "\n ** PAGE REPLACEMENT ALGORITHM **");
				printf ( "\n Enter your choice to draw the line  ");
				printf ( "\n 1 : FIRST IN FIRST OUT.");
				printf ( "\n 2 : LEAST RECENTLY USED.");
				printf ( "\n 3 : OPTIMAL METHOD.");
				printf ( "\n 4 : EXIT");
				printf ( "\nEnter Your Choice : ");
				scanf  ("%d",&choice);
				switch(choice)
				{
				case 1 :
					printf("\n\t\t Page Rep. by FIRST IN FIRST OUT ALGO \n");
					FIFO(pg,no);
					break;
				case 2 :
					printf("\n\t\t Page Rep. by LEAST RECENTLY USED ALGO \n");
					LRU(pg,no);
					break;
				case 3 :
					printf("\n\t\t Page Rep. by OPTIMAL ALGO \n");
					OPTIMAL(pg,no);
					break;
				case 4 : exit(0);
				}
			}
			getch();
		}
