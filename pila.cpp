#include <iostream>
using namespace std;

struct nodo{
    string nombren;
    struct nodo *sgte;
};

typedef nodo *punteropila;

void push(punteropila &p,string nombre){
    punteropila aux;
    aux = new(struct nodo);
    aux->nombren = nombre;
    aux->sgte = p;
    p = aux;
}
string pop(punteropila &p){
    string nombre;
    punteropila aux;
    aux = p;
    nombre = aux->nombren;
    p = aux->sgte;
    delete(aux);
    return nombre;
}
void mostraPila(punteropila p){
    punteropila aux;
    aux = p;
    while(aux!=NULL){
        cout<<aux->nombren<<endl;
        aux = aux->sgte;
    }
}
void destruirpila(punteropila &p){
    punteropila aux;
    while(p!=NULL){
        aux = p;
        p = aux->sgte;
        delete(aux);
    }
}
void menu(){
    cout<<"IMPLEMENTACION DE PILA\n";
    cout<<"1. APILAR\n";
    cout<<"2. DESAPILAR\n";
    cout<<"3. MOSTRAR PILA\n";
    cout<<"4. DESTRUIR PILA\n";
    cout<<"5. SALIR\n";
    cout<<"ELIJA!\n";
}
int main(){
    punteropila p = NULL;
    string nombre;
    int op;
    string x;
    do{
        menu();cin>>op;
        switch(op){
            case 1:cout<<"\nDato para apilar\n";
                cin>>nombre;
                push(p,nombre);
                cout<<"\nDato: "<<nombre<<" apilado!\n";
                break;
            case 2:x=pop(p);
                cout<<"\nDato: "<<x<<" Desapilado!\n";
                break;
            case 3:cout<<"\nMostrando la pila!\n";
                if(p!=NULL){
                    mostraPila(p);
                }else{
                    cout<<"\nPila vacia!\n";
                }
                break;
            case 4:destruirpila(p);
                cout<<"\nPila eliminada!\n";
                break;
        }
        cout<<endl;
    }while(op!=5);
    return 0;
}