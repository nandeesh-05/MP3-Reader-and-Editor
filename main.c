/*
 NAME :Nandeesh
 DATE :16/12/2025
 DIS  :Mp3 project can perform view song and edit song operations
*/
#include "heah.h"
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		errorfun();
		return 1;

	}
	if(!strcmp(argv[1],"--help"))
	{
		help();
	}
	// 
	if(!strcmp(argv[1],"-v"))
	{
		if(argc==3)
		{
			// view details function call view function
			viewdetails(argv[2]);
			return 1;
		}
		else
		{
			errorfun();
			help();
		}
	}
	if(!strcmp(argv[1],"-e"))
	{
		char * tag[6]={"-t","-a","-A","-y","-m","-c"};
		char *tagid[6]={"TIT2","TPE1","TALB","TYER","TCON","TCOM"};
		if(argc==5)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(!strcmp(tag[i],argv[2]))
				{
					// function call to edit the song
		                editdetails(tagid[i],argv[3],argv[4]);
						printf("✅ MP3 tag edited successfully!\n");
						break;
				}
				
			}
			if(i==6)
			{
				printf("🎶 Sorry! The requested MP3 tag was not found.\n");
				return 0;
			}
		}
		else if(argc!=5)
		{
			errorfun();
			help();
		}
	}
    
}
// function defnition for help function
void help()
{
	printf("\n========================= 🎶 HELP MENU 🎶 =========================\n");
    printf("\n1️⃣  -v   👉  View MP3 file contents\n");
    printf("\n2️⃣  -e   ✍️  Edit MP3 file contents\n");
    printf("\n       📌 2.1  -t   🎼  Edit Song Title\n");
    printf("       📌 2.2  -a   🎤  Edit Artist Name\n");
    printf("       📌 2.3  -A   💿  Edit Album Name\n");
    printf("       📌 2.4  -y   📅  Edit Year\n");
    printf("       📌 2.5  -m   📖  Edit Content\n");
    printf("       📌 2.6  -c   💬  Edit Comment\n");
    printf("\n=================================================================\n");

}
// function defnition of errorfun
void errorfun()
{
	printf("\n======================================================================\n");
        printf("⚠️  ERROR: ./a.out : INVALID ARGUMENTS\n");
        printf("----------------------------------------------------------------------\n");

        printf("\n USAGE:\n");
        printf("   🔍 To view    👉  ./a.out -v mp3filename\n");
        printf("   ✍️  To edit    👉  ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
        printf("   ❓ For help   👉  ./a.out --help\n");

        printf("\n======================================================================\n");

}

