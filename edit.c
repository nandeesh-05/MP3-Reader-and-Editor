

#include "heah.h"
// function defnition
 void editdetails(char *ctag,char *edittext,char *filename)
 {
    FILE *fptr=fopen(filename,"rb");
    if(fptr==NULL)
    {
        printf("Failed to open the file\n");
        return ;
    }
    FILE *tptr=fopen("temp.mp3","wb");
    char arr[10];
    fread(arr,1,10,fptr);
    fwrite(arr,1,10,tptr);
    while(1)
    {
        char tag[4];
        fread(tag,1,4,fptr); 
        char oldsize[4];
        char flag[3];

        fread(oldsize,1,4,fptr);
        // conversion of hexadecimal to integer
        unsigned int size=oldsize[0]<<24|oldsize[1]<<16|oldsize[2]<<8|oldsize[3];
        fread(flag,1,3,fptr);
        char buffer[size-1];
        fread(buffer,1,size-1,fptr);
        if(!strcmp(tag,ctag))
        {
            int newsize=strlen(edittext)+1;
            char BE[4];
            // conversion of integer to hexadecimal
            // edit the details 
            BE[0]=(newsize>>24)&0xFF;
            BE[1]=(newsize>>16)&0xFF;
            BE[2]=(newsize>>8)&0xFF;
            BE[3]=(newsize)&0xFF;
            fwrite(tag,1,4,tptr);
            fwrite(BE,1,4,tptr);
            fwrite(flag,1,3,tptr);
            fwrite(edittext,1,newsize-1,tptr);
            break;
        }
        else
        {
            fwrite(tag,1,4,tptr);
            fwrite(oldsize,1,4,tptr);
            fwrite(flag,1,3,tptr);
            fwrite(buffer,1,size-1,tptr);

        }

    }
    char ch[1];
    while(fread(ch,1,1,fptr))
    {
        fwrite(ch,1,1,tptr);
    }
    fclose(fptr);
    fclose(tptr);
    remove(filename);
    rename("temp.mp3",filename);
 }

