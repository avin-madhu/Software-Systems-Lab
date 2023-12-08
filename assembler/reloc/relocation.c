#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char bit[30];
char bitmask[20];

void bitmask_convert(char mask[])
{
	int len;
	len=strlen(mask);
	strcpy(bit,"");

	int i;

	for(i=0;i<len;++i)
	{
		switch(mask[i])
		{
		
			case '0': strcat(bit,"0000");
				  break;
			case '1': strcat(bit,"0001");
				  break;
			case '2': strcat(bit,"0010");
                                  break;
			case '3': strcat(bit,"0011");
                                  break;
			case '4': strcat(bit,"0100");
                                  break;
			case '5': strcat(bit,"0101");
                                  break;
			case '6': strcat(bit,"0110");
                                  break;
			case '7': strcat(bit,"0111");
                                  break;
			case '8': strcat(bit,"1000");
                                  break;
			case '9': strcat(bit,"1001");
                                  break;
			case 'A': strcat(bit,"1010");
                                  break;
			case 'B': strcat(bit,"1011");
                                  break;
			case 'C': strcat(bit,"1100");
                                  break;
	
			case 'D': strcat(bit,"1101");
                                  break;
			case 'E': strcat(bit,"1110");
                                  break;

			case 'F': strcat(bit,"1111");
                                  break;

			default : break;
		}

	}
	
}





void main()
{

	FILE *objptr;
	int start,addr;
	char rec[20];
	char name[20];
	int modif_obj_code;

	char first[3];
	char second[5];
	
	int bitmask_index=0;

	int i;
	////char bitmask[20];
	//char bit[20];

	int  add,len;

	printf("ENTER THE STARTING ADDRESS OF THE PROGRAM\n");
	scanf("%X",&start);
	addr=start;
	
	objptr=fopen("program.txt","r");

       fscanf(objptr,"%s",rec);

       if(strcmp(rec,"H")==0)
       {
	      // printf("HEADER RECORD");
	       fscanf(objptr,"%s",name);
	       fscanf(objptr,"%X",&add);
	       fscanf(objptr,"%X",&len);
	      printf("\nPROGRAM NAME=%s\n\n",name);

	      printf(" ADDRESS   OBJECT CODE \n");
	      printf("____________________________\n");
       }
       else
	{
		printf("INAVLID OBJECT CODE FORMAT\n");
		fclose(objptr);
		exit(1);
	}
      
       strcpy(rec,"");
       
	
       fscanf(objptr,"%s",rec);

       while(strcmp(rec,"E")!=0)
       {
	       //fscanf(objptr,"%s",rec);
	       if(strcmp(rec,"T")==0)
	       {
		       fscanf(objptr,"%X",&add);
		       fscanf(objptr,"%X",&len);
		       fscanf(objptr,"%s",bitmask);
		       add+=start;
		       bitmask_index=0;
		       bitmask_convert(bitmask);
		       fscanf(objptr,"%s",rec);
	       }

		if(bit[bitmask_index]=='1')
	 	{
			//printf("NEED RELOCATION\n");
			
		//	modif_obj_code=atoi(rec);
		//	modif_obj_code+=start;
		//	printf("%X\t%X\n",add,modif_obj_code);
		//	strcpy(first,"");
		//	strcpy(second,"");
			for(i=0;i<6;++i)
			{
				if(i<2)
				{
					
					first[i]=rec[i];
					
				}
				else
				{
					second[i-2]=rec[i];

				}
			}
			first[2]='\0';
			second[4]='\0';
			modif_obj_code=strtol(second,NULL,16);
			modif_obj_code+=start;

			printf("%X\t%s%X\n",add,first,modif_obj_code);
				
		}
		else
		{
			printf("%X\t%s\n",add,rec);

		}		
	       //printf("%s\n",rec);
		add+=3;
		bitmask_index++;
		
	       fscanf(objptr,"%s",rec);
       }
       

       fclose(objptr);
}
