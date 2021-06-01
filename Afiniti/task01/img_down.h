#include <iostream>
#include <unistd.h>
#include <cstring>  
#include <pthread.h>
using namespace std;

typedef struct {
    string url;
} threadArgs;

pthread_mutex_t lock;
pthread_t img01, img02, img03;
threadArgs* args;

string img01URL = "https://images.unsplash.com/photo-1588196749597-9ff075ee6b5b?ixid=MnwxMjA3fDB8MHxzZWFyY2h8MXx8b25saW5lfGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=500&q=60";
string img02URL = "https://images.unsplash.com/photo-1515378791036-0648a3ef77b2?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Mnx8b25saW5lfGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=500&q=60";
string img03URL = "https://images.unsplash.com/photo-1517245386807-bb43f82c33c4?ixid=MnwxMjA3fDB8MHxzZWFyY2h8NXx8b25saW5lfGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=500&q=60";

void *img_down(void *vargp);
