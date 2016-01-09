#define program_name "Distributed Dictionary"
#define program_version "v0.1"

const int ERROR_ENUM = 1;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GEN_STRING(string) #string,
#define GEN_VAL(val) val,

#define FOREACH_PROGRAM_TYPE(PROGRAM_TYPE) \
        PROGRAM_TYPE(UNKNOWN) \
        PROGRAM_TYPE(UI) \
        PROGRAM_TYPE(MASTER) \
        PROGRAM_TYPE(SLAVE)
enum program_type_enum{
    FOREACH_PROGRAM_TYPE(GEN_VAL)
};
static const char * PROGRAM_TYPE_STRINGS[] = {
    FOREACH_PROGRAM_TYPE(GEN_STRING)
};

int main_ui()
{
    return -1;
}

int main_master()
{
    return -1;
}

int main_slave()
{
    return -1;
}

bool master_exist()
{
    //TODO detect if master exist
    return false;
}

int detect_program_type(){
    return master_exist() ? MASTER : SLAVE;
}

int convert_program_type(char * param)
{
    if(strcmp(param,"-ui")==0)
        return UI;
    else if(strcmp(param,"-master")==0)
        return MASTER;
    else if(strcmp(param,"-slave")==0)
        return SLAVE;
    else return UNKNOWN;
}

int main(int argc, char * argv[])
{
    printf("%s %s\n",program_name,program_version);

    int program_type;

    if(argc>1){
        program_type=convert_program_type(argv[1]);
        if(program_type==UNKNOWN){
            fprintf(stderr, "Invalid program type !\n");
            fprintf(stderr, "correct param is [-ui, -master, -slave]\n");
            fprintf(stderr, "or no argument for auto detect\n");
            exit(ERROR_ENUM);
        }
    }else{
        printf("auto mode\n");
        program_type=detect_program_type();
    }
    printf("program type is : %s\n",PROGRAM_TYPE_STRINGS[program_type]);

    return 0;
}
