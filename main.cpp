/*
Author: Rommel Pacheco Hernandez
Fecha:14/09/2023
Descripcion:Este programa filtra y ordena jugadores a partir de memoria estatica y dinamica
version:1.2
*/
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <cstring>
#include <fstream>


#include "Player.h"
#include "StackList.h"

//==========================Funciones Algoritmos===================================================
    
    std::vector<Player> ordenaMergeDescendente(std::vector<Player>);
    std::vector<Player> ordenaMergeAscendente(std::vector<Player>);
    void copyArrayDescendente(std::vector<Player>&, std::vector<Player>&, int, int);
    void copyArrayAscendente(std::vector<Player>&, std::vector<Player>&, int, int);
    void mergeArrayDescendente(std::vector<Player>&, std::vector<Player>&, int, int, int);
    void mergeArrayAscendente(std::vector<Player>&, std::vector<Player>&, int, int, int);
    void mergeSplitDescendente(std::vector<Player>&, std::vector<Player>&, int, int);
    void mergeSplitAscendente(std::vector<Player>&, std::vector<Player>&, int, int);
    
//==========================Algoritmo Merge Sort descendente========================================
    //Inicia el algoritmo merge sort de manera recursiva y de orden descendente como unico parametro un vector estatico de objetos  
    std::vector<Player> ordenaMergeDescendente(std::vector<Player> vec) {
        std::vector<Player> temporal(vec.size());
        mergeSplitDescendente(vec, temporal, 0, vec.size() - 1);
        return vec;
    }
    //Divide el vector en dos partes hasta dar con el caso base, usa un vector originial y una copia, de tercer y cuarto parametro
    //usa un valor int como inicio y otro int como final
    void mergeSplitDescendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int alto) {
        int mitad;
        if ((alto - inicio < 1)) {
        return;
        }
        mitad = (alto + inicio) / 2;
        mergeSplitDescendente(A, B, inicio, mitad);
        mergeSplitDescendente(A, B, mitad + 1, alto);
        mergeArrayDescendente(A, B, inicio, mitad, alto);
        copyArrayDescendente(A, B, inicio, alto);
    }
    //Junta de forma ordenada los arrays generados, usa los anteriores vectores de la funcion merge e 
    //incluye la mitad de los mismos
    void mergeArrayDescendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int mitad, int alto) {
        int i, j, k;
        i = inicio;
        j = mitad + 1;
        k = inicio;
        while (i <= mitad && j <= alto) {
            if (A[i].getGoles() < A[j].getGoles()) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mitad) {
            for (; j <= alto; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mitad; i++) {
                B[k++] = A[i];
            }
        }
    }
    //Copia el array temporal en el original copia el vector temporal en el orginal usando como
    //parametros adicionales el inicio y final
    //del vector
    void copyArrayDescendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int alto) {
        for (int i = inicio; i <= alto; ++i) {
            A[i] = B[i];
        }
    }

//==========================Algoritmo Merge Sort Ascendente========================================
    
    //Inicia el algoritmo merge sort de manera recursiva y de orden ascendente como unico parametro un vector estatico de objetos  
    std::vector<Player> ordenaMergeAscendente(std::vector<Player> vec) {
        std::vector<Player> temporal(vec.size());
        mergeSplitAscendente(vec, temporal, 0, vec.size() - 1);
        return vec;
    }
    //Divide el vector en dos partes hasta dar con el caso base, usa un vector originial y una copia, de tercer y cuarto parametro
    //usa un valor int como inicio y otro int como final
    void mergeSplitAscendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int alto) {
        int mitad;
        if ((alto - inicio < 1)) {
        return;
        }
        mitad = (alto + inicio) / 2;
        mergeSplitAscendente(A, B, inicio, mitad);
        mergeSplitAscendente(A, B, mitad + 1, alto);
        mergeArrayAscendente(A, B, inicio, mitad, alto);
        copyArrayAscendente(A, B, inicio, alto);
    }
    //Junta de forma ordenada los arrays generados, usa los anteriores vectores de la funcion merge e incluye la mitad de los mismos
    void mergeArrayAscendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int mitad, int alto) {
        int i, j, k;
        i = inicio;
        j = mitad + 1;
        k = inicio;
        while (i <= mitad && j <= alto) {
            if (A[i].getGoles() > A[j].getGoles()) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mitad) {
            for (; j <= alto; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mitad; i++) {
                B[k++] = A[i];
            }
        }
    }
    //Copia el array temporal en el original copia el vector temporal en el orginal usando como parametros adicionales el inicio y final
    //del vector
    void copyArrayAscendente(std::vector<Player> &A, std::vector<Player> &B, int inicio, int alto) {
    for (int i = inicio; i <= alto; ++i) {
        A[i] = B[i];
    }
    }

//============================Algoritmos busqueda=======================================
//filtra los jugadores a partir de su liga de tipo string y de un vector
std::vector<Player>mostrarJugadoresDeLiga(std::vector<Player> jugadores, std::string ligaBuscada) {
    std::vector<Player> filtrado;
    for (const auto& jugador : jugadores) {
        if (jugador.getLiga() == ligaBuscada) {
            filtrado.push_back(jugador);
            std::cout<< "================================================"<< std::endl;
            std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
            std::cout<< "================================================"<< std::endl;
        }
    }    
    return filtrado;
}



//filtra los jugadores a partir de su nombre de tipo string y de un vector
void filtrarJugadores(std::vector<Player> jugadores, std::string nombre){
    bool encontrado = false;
    for (const auto& jugador : jugadores) {
        if (jugador.getNombre() == nombre) {
            std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;     
            encontrado = true;
        }            
    }
    if(encontrado == false){
        std::cout << "No se encontro un jugador con ese nombre" << std::endl;
    }
}

//===========================================Escritura de datos===========================================================
void guardaMarcados(Player j) {
    std::ofstream escribe ("C:/Users/herna/Desktop/Algoritmos/Proyecto Integra oficial/Marcados.txt", std::ofstream::app);
    if (escribe.is_open()) {
        escribe << "Nombre: " << j.getNombre() << ", Liga: " << j.getLiga()
                << ", Valor: " << j.getValor() << ", Goles: " << j.getGoles() << std::endl;
    }
    escribe.close();
}

Player marcarJugador(std::vector<Player>& jugadores, StackList<Player>& marcados,std::string nombre){
    bool encontrado = false;
    Player notFound;
    for (const auto& jugador : jugadores) {
        if (jugador.getNombre() == nombre) {
            std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;     
            encontrado = true;
            marcados.push(jugador);
            guardaMarcados(jugador);
            return jugador;
        } 
           
    }
    return notFound;
}




//===========================Funciones del Menu==========================================


void menuGeneral(){
    
    std::cout << "Menu" << std::endl;
    std::cout << "1.- Jugadores de LaLiga" << std::endl;
    std::cout << "2.- Jugadores de la Bundesliga" << std::endl;
    std::cout << "3. Buscar a un jugador" << std::endl;
    std::cout << "4. Ordenar de forma Ascendente" << std::endl;
    std::cout << "5.- Mostrar jugadores marcados" << std::endl;
    std::cout << "6.- Salir" << std::endl;
}

void descripcion(){
    std::cout << "Bienvenido al Recluta jugadores" << std::endl;
    std::cout << "Este software está hecho con el fin de ordenar las mejores stats de un grupo de jugadores" << std::endl;
    std::cout << "y escojas a quiénes seguir" << std::endl;
}
void menuAcciones(){
    std::cout << "1.-Ordenar de forma descendente" << std::endl;
    std::cout << "2.- Ordenar de forma ascendente" << std::endl;
    std::cout << "3.- Seguir jugador" << std::endl;
}

//Carga los jugadores desde un archivo usando objetos de tipo Player
std::vector<Player> cargarJugadoresDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<Player> jugadores;  // Vector para almacenar los jugadores

    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return jugadores;  // Retorna un vector vacío en caso de error
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string nombre, liga, posicion;
        int goles, promedioPases, valor;
        
        std::getline(ss, nombre, ',');
        std::getline(ss, liga, ',');
        std::getline(ss, posicion, ',');
        ss >> goles;
        ss.ignore();  
        ss >> promedioPases;
        ss.ignore();  
        ss >> valor;


        Player jugador(nombre, liga, posicion, goles, promedioPases, valor);
        jugadores.push_back(jugador);
    }

    return jugadores;
}


//Carga los jugadores desde un archivo usando cadenas de texto
std::vector<std::string> cargarRespuestasDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return std::vector<std::string>();
    }

    std::vector<std::string> respuestas;

    std::string linea;
    while (std::getline(archivo, linea)) {
        respuestas.push_back(linea); // Agregar cada línea como una respuesta
    }

    archivo.close();

    return respuestas;
}

//===========================================Main===========================================================
int main() {

    
    int opcion;
    bool continua = true;
    std::string nombre;
    Player vacio;
    StackList <Player> marcados;
    StackList<Player>  marcadosCopy = marcados;
    //===============================Data==============================
    std::vector<Player> players = cargarJugadoresDesdeArchivo("C:/Users/herna/Desktop/Algoritmos/Proyecto Integra oficial/data.txt");
    for (const Player& jugador : players) {
        std::cout << jugador.toString() << std::endl;
    }
    //===========================Casos de prueba=================================================    
    
    std::vector<Player> prueba1 = players;
    std::vector<Player> prueba2 = players;
    
int i = 0;
prueba1 = ordenaMergeAscendente(players);
std::cout << "Prueba 1 - ordenaMergeAscendente:";
std::cout << "  Resultado:" << std::endl;
std::vector <std::string> respuestas = cargarRespuestasDesdeArchivo("C:/Users/herna/Desktop/Algoritmos/Proyecto Integra oficial/respuestas.txt");

for (const Player &player : prueba1) {
    std::cout<<"\n" << "Numero: "<< i  <<std::endl;
    std::cout << "esperada " << respuestas[i]  << std::endl;
    std::cout << " programa " << player.toString() << std::endl;
    std::cout << (strcasecmp(respuestas[i].c_str(), player.toString().c_str()) == 0 ? "success" : "fail") << std::endl;
    i++;
}
      
prueba2 = ordenaMergeDescendente(players);
std::cout << "Prueba 2 - ordenaMergeDescendente:";
std::cout << "  Resultado:";
std::vector <std::string> respuestasInvertidas = cargarRespuestasDesdeArchivo("C:/Users/herna/Desktop/Algoritmos/Proyecto Integra oficial/respuestasInvertidas.txt");
    

i = 0;
for (const Player &player : prueba2) {
    std::cout<<"\n" << "Numero: "<< i  <<std::endl;
    std::cout << "esperada " << respuestasInvertidas[i]  << std::endl;
    std::cout << " programa " << player.toString() << std::endl;
    std::cout << (strcasecmp(respuestasInvertidas[i].c_str(), player.toString().c_str()) == 0 ? "success" : "fail") << std::endl;
    i++;
}      
//Output: "No se encontro un jugador con ese nombre"
std::cout << "Prueba 3" << std::endl;
filtrarJugadores(players,"Goku"); 

        
//Output: "Nombre: Lionel Messi Valor: 70 Goles: 35"
std::cout << "Prueba 4" << std::endl;
filtrarJugadores(players,"Lionel Messi");

std::vector <Player>prueba5 = mostrarJugadoresDeLiga(players,"LaLiga");
  
//===================================================Desarrollo del main=======================================================
    descripcion();
    while(continua == true){
        menuGeneral();
        std::cout << "Escoge una opcion:  " << std::endl;
        std::cin >> opcion;
        if (opcion == 1)
        {
            std::cout<<"Estos son los jugadores de la Laliga"<<std::endl;
            std::vector <Player> jugadoresClasificados;
            jugadoresClasificados = mostrarJugadoresDeLiga(players, "LaLiga");
            menuAcciones();
            std::cin >> opcion;
            if(opcion == 1){
                jugadoresClasificados = ordenaMergeDescendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 2){
                jugadoresClasificados = ordenaMergeAscendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 3){

                std::cout << "Escribe el nombre del jugador a seguir: "<< std::endl;
                std::cin.ignore();
                getline(std::cin, nombre);
                vacio = marcarJugador(players, marcadosCopy, nombre);
                
            }
            else{
                std::cout << "Opcion incorrecta"<<std::endl;
            }
            
        }
        else if (opcion == 2)
        {   std::cout<<"Estos son los jugadores de la Bundesliga"<<std::endl;
            std::vector <Player> jugadoresClasificados;
            jugadoresClasificados = mostrarJugadoresDeLiga(players, "Bundesliga");
            menuAcciones();
            std::cin >> opcion;
            if(opcion == 1){
                jugadoresClasificados = ordenaMergeDescendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 2){
                jugadoresClasificados = ordenaMergeAscendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 3){
                
                std::cout << "Escribe el nombre del jugador a seguir: "<< std::endl;
                std::cin.ignore();
                getline(std::cin, nombre);
                vacio = marcarJugador(players, marcadosCopy, nombre);


            }
            
            else{
                std::cout << "Opcion incorrecta"<<std::endl;
            }   
        } 
        else if (opcion == 3)
        {
            std::cout << "Dame el nombre del jugador: "<< std::endl;
            std::cin.ignore();
            getline(std::cin, nombre);
            filtrarJugadores(players, nombre);
        }
        else if(opcion == 4){
            std::vector <Player> jugadoresOrdenados;
            std::cout<<"Ordenados: "<<std::endl;
            jugadoresOrdenados = ordenaMergeAscendente(players);
            for (const auto& jugador : jugadoresOrdenados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << " Su valor es: " << jugador.getValor() << " Sus goles es: " << jugador.getGoles() << std::endl;
            }
        }
         
        else if (opcion == 5){ 
            std::cout << "Sigues a estos jugadores" << std::endl;
            while (!marcadosCopy.empty()) {
                Player jugador = marcadosCopy.top();
                std::cout << "Nombre: " << jugador.getNombre() << ", Liga: " << jugador.getLiga() << ", Valor: " << jugador.getValor()<< ", Goles: " << jugador.getGoles() << std::endl;
                marcadosCopy.pop();   
            }



        }
        else if(opcion == 6){
            continua = false;
        }
        else{
            std::cout << "Opcion incorrecta"<<std::endl;
        }
    }
    return 0;
}
