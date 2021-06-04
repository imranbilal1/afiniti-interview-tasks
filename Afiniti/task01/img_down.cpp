#include "img_down.h"
   
int main()
{   
    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 

    memset(&img01, 0, sizeof(img01));
    memset(&img02, 0, sizeof(img02));
    memset(&img03, 0, sizeof(img03));
    
    args = (threadArgs *) malloc(sizeof(threadArgs));

    args->url = img01URL;
    pthread_create(&img01, NULL, img_down, args);
    sleep(2);

    args->url = img02URL;
    pthread_create(&img02, NULL, img_down, args);
    sleep(2);

    args->url = img03URL;
    pthread_create(&img03, NULL, img_down, args);
    sleep(2);

    pthread_join(img01, NULL);
    pthread_join(img02, NULL);
    pthread_join(img03, NULL);
    
    free(args);
    args = NULL;
    
    return 0;
}

void *img_down(void *vargp)
{
    threadArgs* args = (threadArgs*)vargp;
    string getImgCMD = "wget " + args->url;
    system((const char*) getImgCMD.c_str());
    sleep(1);
    return NULL;
}
