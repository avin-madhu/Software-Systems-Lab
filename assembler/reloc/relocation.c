#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *fp;
    char line[200], name[100],stradd[10];
    int i, j, intadd, rel;

    fp = fopen ("obj.txt", "r");
    fscanf(fp, "%s", line);

    //displaying the name of the object file

    for( i=2, j=0;line[i]!='^';i++, j++)
    {
        name[j] = line[i];
    }
    name[j] = '\0';

    printf("The name of the object file is: %s\n\n", name);

    printf("Enter the relocation address: ");
    scanf("%d", &rel);
    
    while(!feof(fp))
    {
        fscanf(fp, "%s", line);

        while(line[0]=='T')
        {
            for(i=2,j=0;line[i]!='^';i++, j++)
            {
                stradd[j] = line[i];
            }
            stradd[j]='\0';
            intadd = atoi(stradd);
            intadd+=rel;
            
        
             i=12;

        while(line[i]!='$')
        {
           if(line[i]!='^')
           {
            printf("%05d\t%c%c\n", intadd, line[i], line[i+1]);
            i+=2;
            intadd+=rel;
           }
           else
           {
            i++;
           }
        }

         fscanf(fp, "%s", line);
        } 
    }
    if(line[0]=='E')
    {
        fclose(fp);
        printf("\nObject Code loaded successfully!");
    }
}
