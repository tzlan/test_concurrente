#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 





typedef struct _product_data {
char name[LEN]; //Nom du produit
unsigned int total; //contient la somme des ventes réalisées sur le produit 
pthread_mutex_t lock_pd; // la variable d’exclusion mutuelle
} product_data;


typedef struct _thread_data {
pthread_t thID; //désigne l’identifiant de thread
unsigned int id; //un identifiant ad hoc
unsigned int nbPd; //nombre de produits uniques dans le fichier d’inventaire (différent de celui des ventes)
FILE *fv; // le descripteur du fichier (partagé) des ventes
product_data *products; //est la référence vers le tableau (partagé) des produits en mémoire
} thread_data;

/*Chaque emplacement du tableau contient une référence vers
un produit de l’inventaire (définit par le type product_data). Il y a donc autant d’emplacements
que de produits uniques.
*/

//Creation du thread
pthread_t create_thread(void * (*start_routine)(void *), void * arg)
    {
        pthread_t thread;

       if (pthread_create(&thread,NULL,start_routine,arg)!=0)
       {
           printf("le thread n'as pas été créé avec succès");
           exit(-1);
       } 
       
       return thread;
    }






int main(int argc, char**argv){
    nbPd = atoi(argv[1]);
    int nbLecteur= atoi(argv[2]);
    int pathFileProduct = atoi(argv[3]);
    int nbCourse = atoi(argv[4]);
    fv = fopen("ventes.txt",r);
    return 0;
}










//Creer un semaphore sem_t sem1;

//* pthread_join(th1,NULL);  Equivalent du wait
 //pthread_exit   Fin de tache   
//int pthread_mutex_lock  
//int pthread_mutex_unlock         
//int pthread_T 

//int VAL;
// pthread_mutex_t value = PTHREAD_MUTEX_INITIALIZER; //initialisation du mutex

//void *Inc(){
 //   pthread_mutex_lock(&value);
   // VAL++;
  //  pthread_mutex_unlock(&value);
   // printf("val incr %d \n",VAL);
///*