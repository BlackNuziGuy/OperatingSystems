#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int buffer = 0;

int asleep_babushka = 0, asleep_vnuk = 0;



void *producer(void *ptr){


    
    while (1){
        
        if ( !asleep_babushka ){

            

            if ( buffer == 100){
                printf("Babushka_Ustala: Babushka Spatb\n");
                asleep_babushka = 1;
                continue;
            }

            
            buffer++;
            printf("Babushka Prigotovila %d pechenek\n",buffer);
            
        
            if ( buffer == 1){
                printf("VNUK_Prosnulsya: Babushka zovet kushat!\n");
                asleep_vnuk = 0;
            }
            

            
        }
    
        
    }
    
    pthread_exit(0);
}

void *consumer(void *ptr){
    

    while (1){
        
        if ( !asleep_vnuk ){
            
            
            if ( buffer == 0){
                printf("VNUK_SPIT: EDA KONCHILAS :{; Pora Spatb \n");
                asleep_vnuk = 1;
                continue;
            }
            
            
            buffer--;
            printf("VNUK SKUSHAL ODNU PECHENKU (OSTALOS %d PECHENEK) \n",buffer);
            
            
            if ( buffer == 99){
                printf("BABUSHKA_Prosnulasb: POrA GOTOVITb\n");
;               asleep_babushka = 0;
                
            }
            
            
            
        }
        
        
    
    }
    
    pthread_exit(0);
}

int main(int argc, char **argv){
    pthread_t babushka, vnuk;
        

    pthread_create(&babushka, 0, consumer, 0);
    pthread_create(&vnuk, 0, producer, 0);
    sleep(5);
    
    
    pthread_cancel(babushka);    
    pthread_cancel(vnuk);
    
    printf("\nThe Deadlock has already happened, I guess..");
    
    
}
