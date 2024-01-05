#include </home/arch/Code/MyProjects/wlg/glassBox.c>

int main(int argc, char* argv[])
{
    /*------------------------------[CHECKS]-------------------------------*/
CHECKS:
    info("[CHECKS]");
    
    //checking if provided arguments number is valid
    if(argc<2)
    {
        warn("usage: wlg <path input> <path output> [OPTIONS] [OPTIO... <cr>");
        return EXIT_FAILURE;
    }

    //checking for -h || --help option
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        printf("\n--HELP MESSAGE--\n\n");
        return EXIT_SUCCESS;
    }

    /*------------------------------[VARS]---------------------------------*/
VARS:
    info("[VARS]");

    //vars for input:
    FILE* FILEIN;
    char** inStrs;
    char c;
    size_t nLines = 0;
    size_t nChars = 0;
    
    //vars for output:
    FILE* FILEOUT; 

    /*------------------------------[INPUT]--------------------------------*/
INPUT:
    info("[INPUT]");

    //open input file
    FILEIN = fopen(argv[1], "r");

    if(FILEIN = NULL)
    { 
        warn("failed to open %s", argv[1]);
        return EXIT_FAILURE;
    }

    //allocating starting size to inStrs
    inStrs = malloc(DEF_LINES*sizeof(char*));

    

    //reading and dinamically storing file
    do
    {  
        c = fgetc(FILEIN);

        if(ferror(FILEIN))
        {
            warn("error reading from the file");
            goto CLEANUP;
        }

        if(feof(FILEIN))
        {
            if(nChars!=0)
            {
                inStrs[nLines]= realloc(inStrs[nLines], (nChars+1)*sizeof(char));
                inStrs[nLines][nChars] = '\0';
                nLines++;
            }
            break;
        }

        if(nChars == 0)
        {
            inStrs[nLines] = malloc(DEF_CHARS*sizeof(char));
        }

        inStrs[nLines][nChars] = c;
        nChars++;

        if(c == '\n')
        {
            inStrs[nLines][nChars - 1] = '\0';
            inStrs[nLines]= realloc(inStrs[nLines], nChars*sizeof(char));
            nLines++;
            nChars=0;

            if(nLines % DEF_LINES == 0)
            {
                inStrs = realloc(inStrs, (nLines+DEF_LINES)*sizeof(char*));
            }
        }
        else if(nChars % DEF_CHARS == 0)
        {
            inStrs[nLines] = realloc(inStrs[nLines], (nChars+DEF_CHARS)*sizeof(char));
        }
        
    }while(1);

    fclose(FILEIN);

    inStrs = realloc(inStrs, nLines*sizeof(char*));
    

    /*------------------------------[OPTIONS]------------------------------*/
OPTIONS:
    info("[OPTIONS]");

    //-h || --help -->print help message to console

    

    //--cut-start <int> -->cut <int> characters from startpoint
    
    //--cut-end <int> -->cut <int> characters from startpoint
    
    //-birthday-front <int> <int> -->add in front of each line each number between <int> <int>

    //-birthday-end <int> <int> -->add at the end of each line each number between <int> <int>

    //-add-front <str>,<st... -->add in front of each line each line specified (separated with commas)

    //-add-end <str>,<st... -->add at the end of each line each line specified (separated with commas)

    //-rmd -->remove-duplicates from output file

    for(int i=3;i<argc;i++)
    {
OPTION_START:
        //-p -->add raw input to output file
        if(strcmp(argv[i], "-p") == 0)
        {
            okay("option -p selected");
            goto P;
        }

OPTION_END:
    }

    //freeing the allocated space before finishing the program
    goto CLEANUP;

    /*------------------------------[OUTPUT]-------------------------------*/
OUTPUT:
    info("[OUTPUT]");

P:
    //open file output 
    FILEOUT = fopen(argv[2], "a");

    if(FILEOUT = NULL)
    { 
        warn("failed to open %s", argv[2]);
        return EXIT_FAILURE;
    }

    //write to file
    
    for(int i=0;i<nLines;i++)
    {
        printf(inStrs[i]);
    }

    fclose(FILEOUT);

    //go back to options selection handling
    goto OPTION_END;
C:
    



    /*------------------------------[CLEANUP]------------------------------*/
CLEANUP:
    info("[CLEANUP]");

    for(int i=0;i<nLines;i++)
    {
        free(inStrs[i]);
    }
    free(inStrs);

    return EXIT_SUCCESS;
}
