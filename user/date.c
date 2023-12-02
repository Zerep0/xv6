#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char * argv[]){
    struct rtcdate r;

    if(date(&r))
    {
        printf(2, "date failed\n");
        exit(EXIT_SUCCESS);
    }

    printf(1,"%d/%d/%d %d:%d:%d\n",r.day,r.month,r.year,r.hour,r.minute,r.second);
    int a = 0;
    int b = 0;
    printf(1,"%d",a/b);
    exit(EXIT_SUCCESS);
    
}