#include <iostream>
using namespace std;

struct nodo
{
	int numero;
	struct nodo *sigte;
};

typedef nodo*ptpila;

void apilar (ptpila &p, int valor)
{
	ptpila enlace;
	enlace = new (struct nodo);
	enlace -> numero = valor;
	
	enlace -> sigte = p;
	p = enlace;
}

int desapilar(ptpila &p)
{
	int num;
	ptpila enlace;
	
	enlace = p;
	num = enlace -> numero;
	
	p = enlace -> sigte;
	delete (enlace);
	
	return num;
	
}

void mostrar_pila(ptpila p)
{
	ptpila enlace;
	enlace = p;
	
	while(enlace != NULL)
	{
		cout <<"\t"<<enlace -> numero << endl;
		enlace = enlace -> sigte;	
	}
}

void eliminar_pila(ptpila &p)
{
	ptpila enlace;
	
	while(p != NULL)
	{
		enlace = p;
		p = enlace -> sigte;
		delete (enlace);
	}
}

int sumatoria_pila(ptpila enlace)
{
	int suma = 0;
	if (enlace == NULL)
		cout<< "\n\n La Pila esta Vacia... \n\n";
	else
	{
		while (enlace != NULL)
		{
			suma = suma + enlace -> numero;
			enlace = enlace -> sigte;
		}
	}
	return suma;
	
}

int elemento_mayor(ptpila enlace)
{
	int mayor = 0, numero;
	if(enlace == NULL)
		cout<<"\n\n La Pila esta Vacia... \n\n";
	else
	{
		while(enlace != NULL)
		{
			numero = enlace -> numero;
			if(numero > mayor)
				mayor = numero;
			enlace = enlace -> sigte;
		}
	}
	return mayor;
}

void menu()
{
    cout<<"\n\t ESTRUCTURA DE DATOS - PILAS\n\n";
    cout<<" 1. APILAR                                "<<endl;
    cout<<" 2. DESAPILAR                             "<<endl;
    cout<<" 3. MOSTRAR PILA                          "<<endl;
    cout<<" 4. ELIMINAR PILA                         "<<endl;
    cout<<" 5. SUMAR PILA                            "<<endl;
	cout<<" 6. ELEMENTO MAYOR                        "<<endl;
    cout<<" 7. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

int main()
{
	ptpila p = NULL;
	int dato;
	int opcion;
	int x;
	
	do
	{
		menu();
		cin >> opcion;
		
		switch(opcion)
		{
			case 1:
				cout<< "NUMERO A APILAR: " ;
				cin>> dato;
				apilar(p, dato);
				cout<<"\n\n\t\t Numero "<< dato <<" apilado... \n\n";
			break;
			
			case 2:
				x = desapilar(p);
				cout<<"\n\n\t\t Numero "<< x <<" desapilado... \n\n";
			break;
			
			case 3:
				cout << "\n\n MOSTRANDO PILA \n\n";
				if(p!=NULL)
					mostrar_pila( p );
				else
					cout<<"\n\n\t Pila vacia..! "<<endl;
			break;
			
			case 4:
				eliminar_pila( p );
				cout<<"\n\n\t\t Pila eliminada... \n\n";
			break;
			
			case 5:
				cout<<"\n\n\t\t La suma de la pila es: "<< sumatoria_pila( p ) ;
				
			break;
			
			case 6:
				cout<< "\n\n\t\t El elemento mayor de la pila es: "<< elemento_mayor(p);
			break;
		}
		
		cout<<endl<<endl;
		system("pause");
		system("cls");	
	}
	
	while(opcion != 7);
	return 0;
}
