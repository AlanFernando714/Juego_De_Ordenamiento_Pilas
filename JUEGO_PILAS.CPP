//ALAN FERNANDO CARLOS FLORES
// OBJETIVO:
// Ordenar las pilas para que:
// Pila 1 = cuatro números 1
// Pila 2 = cuatro números 2
// Pila 3 = cuatro números 3
//
// INSTRUCCIONES:
// - Solo puedes mover el tope de cada pila.
// - Usa la pila 4 como pila auxiliar.
// - Cada pila admite máximo 4 números.
// - No se puede mover directamente entre pilas 1, 2 y 3.
// - Usa la opción "Comprobar victoria" para saber si ganaste.

#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;


struct nodo { //DEFINIR NODO, QUE ES EL LUGAR PARA GUARDAR LAS PILAS CON UN NUMERO Y DIRECCION DE EL MISMO.

    int numero;
    nodo * siguiente;
};

typedef nodo *P;//DEFINIMOS EL TIPO DE DATO NODO PARA UTILIZARLO EN LAS PILAS

//APILAR NUMEROS DENTRO DE LAS PILAS
void apilar(int num, P &pila)
{
    P aux;
    aux = new nodo;
    aux->numero = num;
    aux->siguiente = pila;
    pila = aux;
}

//MOSTRAR LAS PILAS
void mostrar(P pila)
{
    P aux;
    aux = pila;

    if(aux == NULL)
    {
        cout<<endl<<"La pila esta vacia"<<endl;
    }

    while(aux != NULL)
    {
        cout<<endl<<aux->numero<<endl;
        aux = aux->siguiente;
    }
}

//DESAPILAR LAS PILAS
int desapilar(P &pila)
{
	int temp;
	P aux;
	aux = pila;
	temp = aux->numero;
	pila = aux->siguiente;
	delete aux;
	return temp;
}

//RELLENAR LAS PILAS ALEATORIAMENTE
void rellenarpilas(P &pila, int &numeros1, int &numeros2, int &numeros3)
{
    bool encontrado = false;
    int num;

    for (int i = 0; i < 4; i++) //For para rellenar las pilas hasta 4 numeros.
    {
        encontrado = false;
        while (encontrado == false) 
        {
			num = rand()%(4-1) + 1; //Se genera el numero aleatorio
            if (num == 1 && numeros1 < 4)//mientras el contador de los 1 no sean mas de 4
            {
                numeros1++;
                apilar(num, pila);
                encontrado = true;
            }
            else if (num == 2 && numeros2 < 4)//mientras el contador de los 2 no sean mas de 4
            {
                numeros2++;
                apilar(num, pila);
                encontrado = true;
            }
            else if (num == 3 && numeros3 < 4)//mientras el contador de los 3 no sean mas de 4
            {
                numeros3++;
                apilar(num, pila);
                encontrado = true;
            }
        }
    }
}

void modificarPila(P& pila, P&pila4) {
    int op,num,contador;
    P auxpila4 = NULL;
    auxpila4 =pila4;
    contador=0;

    cout<<endl<<"Pila actual: "<< endl;
    mostrar(pila);

    
    while(auxpila4!=NULL)
    {
     contador++;
     auxpila4=auxpila4->siguiente;
    }

    do {


        if(contador<4)
        {
        if(pila != NULL)
        {
        num=0;
        num=pila->numero;
        
        desapilar(pila);
        apilar(num, pila4);
        contador++;

        cout<<endl<<"Se movio el tope de la pila 1 al tope de la pila 4 "<<endl;

        cout<<endl<<"Pila actualizada: "<< endl;
        mostrar(pila);

        cout<<endl<<"Quieres mover el siguiente numero tope de la pila 1 a la pila 4?        1. Si       0. No "<<endl;
        cin >> op;
        }
        else
        {
            cout<<endl<<"La pila ya esta vacia"<<endl;
            op=0;
        }
        }

        else
        {
            cout<<endl<<"La pila 4 esta llena, no puede meter mas numeros"<<endl;
            op=0;
        }

    } while (op == 1);
}

void movernumeros(P&pila4, P &pila)
{
    int op,num,contador;
    P auxpila = NULL;
    auxpila= pila;
    contador=0;


    cout<<endl<<"Pila 4 actual: "<< endl;
    mostrar(pila4);

            while(auxpila!=NULL)
        {
            contador++;
            auxpila = auxpila->siguiente;

        }

    do {


    if(contador<4)
    {
        if(pila4 != NULL )
        {
        num=0;
        num=pila4->numero;
        
        desapilar(pila4);
        apilar(num, pila);
        contador++;

        cout<<endl<<"Se movio el tope de la pila 4 al tope de la pila seleccionada"<<endl;

        cout<<endl<<"Pila actualizada: "<< endl;
        mostrar(pila4);

        cout<<endl<<"Quieres mover el siguiente numero tope de la pila 1 a la pila 4?        1. Si       0. No "<<endl;
        cin >> op;
        }
        else
        {
            cout<<endl<<"La pila ya esta vacia"<<endl;
            op=0;
        }
    }
    else
    {
        cout<<endl<<"La pila esta llena, no puede meter mas numeros"<<endl;
            op=0;
    }
    } while (op == 1);


}

void victoria(P pila1, P pila2, P pila3, bool &ganar)
{
    int ganadorpila1, ganadorpila2,ganadorpila3;
    ganadorpila1 = 0; ganadorpila2 = 0; ganadorpila3 = 0;
    P aux = NULL;
    P aux2 = NULL;
    P aux3 = NULL;

    aux = pila1;
    aux2 = pila2;
    aux3 = pila3;

     for(int i=0; i<4; i++)
    {
        if(aux->numero == 1){
        aux = aux->siguiente;
        ganadorpila1++;
        }
        if(aux2->numero == 2){
        aux2 = aux2->siguiente;
        ganadorpila2++;
        }

        if(aux3->numero == 3){
        aux3 = aux3->siguiente;
        ganadorpila3++;
        }
    }
    cout<<ganadorpila1<<endl;//comprobar cuantos numeros estan bien
     cout<<ganadorpila2<<endl;//comprobar cuantos numeros estan bien
      cout<<ganadorpila3<<endl;//comprobar cuantos numeros estan bien

    if((ganadorpila1 == 4) && (ganadorpila2 == 4) && (ganadorpila3 == 4)){
        ganar=true;
         cout<<"Felicidades, has ganado!";
    }

    else
    {
        cout<<"aun no has ganado"<<endl;
    }

}


int main()
{

    system("cls");
    srand(time(NULL));
    P pila1 = NULL;
    P pila2 = NULL;
    P pila3 = NULL;
    P pila4 = NULL;
    // P pila4 = NULL; 

    int numeros1 = 0, numeros2 = 0, numeros3 = 0;
    int opcion,opcionmover;
    bool ganar=false;

    //RELLENAR LAS PILAS
    rellenarpilas(pila1, numeros1, numeros2, numeros3);
    rellenarpilas(pila2, numeros1, numeros2, numeros3);
    rellenarpilas(pila3, numeros1, numeros2, numeros3);

    //MOSTRAR LAS PILAS
    cout<<"Pila 1:"<<endl;
    mostrar(pila1);
    cout<<"Pila 2:"<<endl; 
    mostrar(pila2); 
    cout<<"Pila 3:"<<endl;
    mostrar(pila3);
    cout<<"Pila 4:"<<endl;
    mostrar(pila4);

do{
    cout << "Seleccione la pila que desea modificar: 1. Pila #1,  2. Pila #2, 3. Pila #3 , 4.Mostrar todas las pilas , 5.Comprobar victoria. , 0 salir. ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        cout<<"Ingresaras numeros de la pila 1 a la pila 4, o quitaras numeros de la pila 4 para mover a la 1?  1. Ingresar.  2. Quitar: ";
        cin>>opcionmover;
        if(opcionmover == 1)
        {
        modificarPila(pila1,pila4);
        }
        else
        {
            movernumeros(pila4,pila1);
        }
        break;

    case 2:
  cout<<"Ingresaras numeros de la pila 2 a la pila 4, o quitaras numeros de la pila 4 para mover a la 2?  1. Ingresar.  2. Quitar: ";
        cin>>opcionmover;
        if(opcionmover == 1)
        {
        modificarPila(pila2,pila4);
        }
        else
        {
            movernumeros(pila4,pila2);
        }
        break;

    case 3:
  cout<<"Ingresaras numeros de la pila 3 a la pila 4, o quitaras numeros de la pila 4 para mover a la 3?  1. Ingresar.  2. Quitar: ";
        cin>>opcionmover;
        if(opcionmover == 1)
        {
        modificarPila(pila3,pila4);
        }
        else
        {
            movernumeros(pila4,pila3);
        }
        break;

    case 4:

    cout<<"Pila 1:"<<endl;
    mostrar(pila1);
    cout<<"Pila 2:"<<endl; 
    mostrar(pila2); 
    cout<<"Pila 3:"<<endl;
    mostrar(pila3);
    cout<<"Pila 4:"<<endl;
    mostrar(pila4);


    break;

    case 5:
    victoria(pila1,pila2,pila3,ganar);
    break;

    case 0:
        ganar=true;
        break;

    default:
        cout << endl << "Opción inválida " << endl;
        break;
    }


}while(ganar==false);
    return 0;
}