#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

int counter = 0;

struct nodo {
    char *name;
    char *username;
    char *password;
    int count;
    struct nodo *sig;
};

struct nodo *head = NULL;
struct nodo *tail = NULL;

// Funcion 'empty'
bool empty() {
    if (head == NULL)
        return true;
    else
        return false;
}

// Funcion insert
void insert(char name_[], char username_[], char password_[]) {
    if (counter < MAX_SIZE) {
        struct nodo *nuevo;
        nuevo=malloc(sizeof(struct nodo) * MAX_SIZE);

        nuevo->name = name_;
        nuevo->username = username_;
        nuevo->password = password_;
        nuevo->count = counter;

        counter++;

        nuevo->sig = NULL;
        if (empty()) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->sig = nuevo;
            tail = nuevo;
        }

    } else {
        printf("\nLa cola esta llena...\n");
    }
}

// Funcion extract
int extract() {
    if (!empty()) {
        int informacion = head->count;

        struct nodo *bor = head;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->sig;
        }

        free(bor);

        counter --;

        return informacion;
    } else {
        printf("\nLa lista esta empty...\n");
        return -1;
    }
}

// Funcion 'status'
void status() {
    struct nodo *reco = head;

    printf("Listado de todos los elementos de la cola.\n");

    while (reco != NULL) {
        printf("%s, %s, %s\n", reco->name,  reco->username, reco->password);
        reco = reco->sig;
    }
    printf("\n");
}

// Funcion 'perc'
int perc () {
    int perc = ((counter / MAX_SIZE) * 100);

    return perc;
}

// Funcion 'liberar' - Libera el programa de la memoria
void liberar() {
    struct nodo *reco = head;
    struct nodo *bor;

    while (reco != NULL) {
        bor = reco;
        reco = reco->sig;

        free(bor);
    }
}

void main() {
    insert("David", "davidFH", "125A49B");
    insert("Pablo", "Pablo12", "A45B36");
    insert("Carla", "CarlaV", "B98Z46");
    insert("Carlos", "CarlosB", "1269AB");
    insert("Lucia", "Lucia12", "968523");
    status();
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    insert("Pedro", "PedritoSaltamontes", "PRCLS23");
    insert("Sergio", "Sergi11", "BTC100K");
    insert("Alvaro", "Alvaro3", "910BNB");
    status();
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    printf("Extraemos el elemento %d de la cola\n", extract());
    liberar();
}