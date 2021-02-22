#include <sys/mman.h>
#include <sys/stat.h> /* Pour les constantes « mode » */
#include <fcntl.h> /* Pour les constantes O_* */ 
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int shm_open(const char *nom, int oflag, mode_t mode); 

int main(){
    int val24 ;
    int ival24;
    int * addr;
    val24 = shm_open("eXchange",O_CREAT | O_RDWR ,666);
    if(val24 ==-1){
        return -1;
    } 
    ival24 = ftruncate(val24,0x400);
    if ( ival24 == -1){
        return -2;
    }
    //memset(ival24,0,0x400);

    addr =(int*) mmap((void*) 0x00, 0x400, PROT_READ|PROT_WRITE, MAP_SHARED,val24, 0);   
    printf("%p\n",addr);
    printf("%d\n",addr[1]);
    printf("%d\n",val24);
     for(int j =0 ; j< 1024 ; j ++){
        printf("%d",addr[j]);
    }
    printf("\n");
    addr [ 0 ] = '3' ;
    for(int i =0 ; i < 1024 ; i ++){
        addr [ i ] = i ;
    }
    for(int j =1 ; j< 1024 ; j ++){
        printf("%d",addr[j]);
    }
     printf("\n");
    printf("%p\n",addr);
    me
    shm_unlink("eXchange");
    while (1)
    {
        /* code */
    }
    
    return 0;
}
