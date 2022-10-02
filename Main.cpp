#include <iostream>
#include <string>
#include "Nodo.h"
#include "Archivo.h"
#include <fstream>

using namespace std;

int main(){
    ofstream archivo;
    ifstream lectura;
    archivo.open("usuarios.txt",ios::out);
    lectura.open("usuarios.txt",ios::in);
    Nodo *head = NULL;
    Nodo *lista;
    string usuario, contraseña; 
//menú
    while(true){
        int num;
        cout<<"Ingrese 0 para finalizar la ejecucion del programa."<<"\n";
        cout<<"Ingrese 1 para crear un nuevo usuario."<<"\n";
        cout<<"Ingrese 2 para buscar usuario existente."<<"\n";
        cout<<"Ingrese 3 para eliminar un usuario existente."<<"\n";
        cout<<"Ingrese 4 para mostrar la lista de usuarios."<<"\n";
        cin>>num;
        if(num == 0){
                break;
        }
        switch(num){
            case 1: {
                cout<<"Ingrese el nuevo usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la nueva contraseña:\n";
                cin>>contraseña;
                Nodo *nuevoN = new Nodo(usuario,contraseña);
                cout<<"\n";
                archivo<<nuevoN->toString()<<endl;
                if(head == NULL){
                    head = nuevoN;
                    lista = head;
                }else{
                    lista->setNext(nuevoN);
                    lista = nuevoN;
                }
                break;
            }
            case 2:{
                cout<<"Ingrese el usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la contraseña:\n";
                cin>>contraseña;
                Nodo *temp = head;
                while(temp != NULL){
                    if((temp->getUsername() == usuario) && (temp->getPassword() == contraseña)){
                        cout<<"Bienvenido\n";
                        break;
                    }
                    temp = temp->getNext();
                }
                break;
            }
            case 3:{
                cout<<"Ingrese el usuario:\n";
                cin>>usuario;
                cout<<"Ingrese la contraseña:\n";
                cin>>contraseña;
                Nodo *temp = head;
                if((temp->getUsername() == usuario) && (temp->getPassword() == contraseña)){
                    
                }
                //se elimina el nodo
                break;
            }
            case 4:{
                cout<<"lista:\n";
                Nodo *temp = head;
                while(temp != NULL){
                    cout<<temp->getUsername()<<endl;
                    temp = temp->getNext();
                }
                break;
                }
        }
    }
    delete head;
}
