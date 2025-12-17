/*
Name :Nandeesh
Date :
Topic:
*/

#include "heah.h"
// function defnition  to view details
void viewdetails(char * filename)
{
    // open the file pointer to read the content
    FILE *fptr=fopen(filename,"rb");
    if(fptr==NULL)
    {
        printf("Failed to open the file\n");
        return ;
    }
    
      char  id[3];
    fread(id,1,3,fptr);
    if(!strcmp(id,"ID3"))
    {
        fseek(fptr,3,SEEK_CUR);
          char size[4];
        fread(size,1,4,fptr);
        swap_endian(size,4);
        // conversion of hexadecimal to integer
        unsigned int number = (size[0]&0x7f)<<21|(size[1]&0x7f)<<14|(size[2]&0x7f)<<7|(size[3]&0x7f);
        unsigned int  end=number+10;
        // 
        int i=0;
        while(i<6)
        {
            char tag[5];
            fread(tag,1,4,fptr);
            tag[4]='\0';
            char size1[4];
            fread(size1,1,4,fptr);
            // conversion of big endian to little endian
            swap_endian(size1,4);
            // conversion of hexadecimal to integer
             int number1 = size1[3]<<24|size1[2]<<16|size1[1]<<8|size1[0];
            fseek(fptr,3,SEEK_CUR);
              char name[number1];
            fread(name,1,number1-1,fptr);
            name[number1-1]='\0';
 
            // display the tags present in song
            if(!strcmp(tag,"TIT2"))
            {
                printf("🎼 Title   : %s\n", name);
            }
            else if (!strcmp(tag,"TPE1"))
            {
                printf("🎤 Artist  : %s\n", name);
            }
            else if(!strcmp(tag,"TALB"))
            {
                printf("💿 Album   : %s\n", name);
            }
            else if(!strcmp(tag,"TYER"))
            {
                printf("📅 Year    : %s\n", name);
            }
            else if(!strcmp(tag,"TCON"))
            {
                printf("📖 Content : %s\n", name);
            }
            else if(!strcmp(tag,"TCOM"))
            {
                printf("🎹 Composer : %s\n", name);

            }
            else
            {
                return ;
            }


        }
        i++;

    }
    else
    {
        printf("\n====================================\n");
        printf("❌ ERROR: Invalid file type!\n");
        printf("👉 The file should be of MP3 format (.mp3)\n");
        printf("====================================\n\n");

        return;

    }

}
void swap_endian(unsigned char *arr, int size) {
    unsigned char temp;
    int i, j;

    for (i = 0, j = size - 1; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

