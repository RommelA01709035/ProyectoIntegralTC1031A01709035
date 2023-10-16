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
            std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
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
            std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;     
            encontrado = true;
        }            
    }
    if(encontrado == false){
        std::cout << "No se encontro un jugador con ese nombre" << std::endl;
    }
}

Player marcarJugador(std::vector<Player>& jugadores, StackList<Player>& marcados,std::string nombre){
    bool encontrado = false;
    Player notFound;
    for (const auto& jugador : jugadores) {
        if (jugador.getNombre() == nombre) {
            std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;     
            encontrado = true;
            marcados.push(jugador);
            return jugador;
        }            
    }
    return notFound;
}


//===========================Funciones del Menu==========================================
void menuGeneral(){
    
    std::cout << "\n\tMenu";
    std::cout << "\n\t 1.- Jugadores de LaLiga";
    std::cout << "\n\t 2.- Jugadores de la Bundesliga"; 
    std::cout << "\n\t 3.- Busque a un jugador"; 
    std::cout<<"\n\t 4. Ordenar de forma Ascendente ";
    std::cout << "\n\t 5.- mostrar jugadores marcados";     
    std::cout << "\n\t 6.- Salir\n";     
}

void descripcion(){
    std::cout << "\n\tBienvenido al Recluta jugadores\n";
    std::cout << "\n\t Este software esta hecho con el fin de ordenarlas mejores stats de un grupo de jugadores";
    std::cout << "\n\t y escojas tu a quienes seguir\n"; 
    
}
void menuAcciones(){
    std::cout << "\n\t 1.-Ordenar de forma descendente\n";
    std::cout << "\n\t2.- Ordenar de forma ascendente\n";
    std::cout << "\n\t3.- Seguir jugador\n"; 
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
    std::vector<Player> jugadores;
    std::vector<Player> players = jugadores;
        players.push_back( Player ("Neymar Jr.", "Extremo Izquierdo","LaLiga",20,156,40));
        players.push_back( Player("Lionel Messi", "Extremo Derecho", "LaLiga",35,235,70));
        players.push_back( Player("Cristiano Ronaldo","Extremo Izquierdo","LaLiga", 30,126,20));
        players.push_back( Player("Timo Werner","Delantero","Bundesliga", 19,79,45));
        players.push_back( Player ("Lois Openda", "Delantero","Bundesliga",15,200,25));
        players.push_back( Player("Donyell Malen", "Delantero", "Bundesliga",20,300,30));
        players.push_back( Player("Leroy Sane","Extremo Izquierdo","Bundesliga", 21,403,45));
        players.push_back( Player("Niklas Fullkrug","Delantero","Bundesliga", 16,168,30));
        players.push_back( Player ("Serge Gnabry", "Extremo Derecho","Bundesliga",13,264,40));
        players.push_back( Player("Anthony Modeste", "Delantero", "Bundesliga",7,147,15));
        players.push_back( Player("Harry Kane","Delantero","Bundesliga", 25,308,90));
        players.push_back( Player("Benjamin Sesko","Delantero","Bundesliga", 11,146,22));
        players.push_back( Player ("Sadio Mane", "Extremo Izquierdo","Bundesliga",14,563,56));
        players.push_back( Player("Christopher Nkunku", "Segundo Delantero", "Bundesliga",25,687,80));
        players.push_back( Player("Robert Lewandoski","Delantero","LaLiga", 27,240,52));
        players.push_back( Player("Antoine Griezmann","Delantero","Laliga", 17,324,60));
        players.push_back( Player ("Karim Benzema", "Segundo Delantero","LaLiga",22,598,30));
        players.push_back( Player("Rodrigo Goes", "Extremo Derecho", "LaLiga",13,421,60));
        players.push_back( Player("Vinicus Jr","Extremo Izquierdo","LaLiga", 20,368,80));
        players.push_back( Player("Iago Aspas","Delantero","Delantero", 18,274,30));
        players.push_back( Player("Marcos Acuña","Medio izquierdo","LaLiga", 9,906,38));
        players.push_back( Player ("Moussa Diaby", "Medio Derecho","Bundesliga",16,469,70));
        players.push_back( Player("Yanick Carrasco", "Medio Izquierdo", "LaLiga",11,835,25));
        players.push_back( Player("Marcos Llorente","Medio Derecho","LaLiga", 9,874,35));
        players.push_back( Player("Ousmane Dembele","Extremo Derecho","LaLiga", 15,971,45));
        players.push_back( Player ("Raphael Guerreiro", "Medio Izquierdo","Bundesliga",7,756,40));
        players.push_back( Player("Patric Schick", "Delantero", "Bundesliga",25,320,45));
        players.push_back( Player("Sebastian Haller","Delantero","Bundesliga", 12,258,20));
        players.push_back( Player("Raphinha","Extremo Derecho","LaLiga", 13,785,56));
        players.push_back( Player("Vicenzo Grifo", "Medio Izquierdo","Bundesliga",16,587,30));
        players.push_back( Player("Marco Asensio", "Extremo Derecho", "LaLiga",10,160,43));
        players.push_back( Player("Iker Munian","Medio Izquierdo","LaLiga", 12,452,35));
        players.push_back( Player("Mikel Oyazarbal","Extremo Izquierdo","Laliga", 19,79,45));
        players.push_back( Player ("Alejandro Gomez", "Extremo Izquierdo","LaLiga",15,478,15));
        players.push_back( Player("Mario Gotze", "Segundo Delantero", "Bundesliga",8,741,20));
        players.push_back( Player("Kolo Muani","Delantero","Bundesliga", 26,487,75));
        players.push_back( Player("Ferran Torres","Extremo Izquierdo","LaLiga", 10,236,15));
        players.push_back( Player ("Daniel Szoboszlai", "Medio Izquierdo","Bundesliga",7,1200,60));
        players.push_back( Player("Joselu", "Delantero", "LaLiga",16,95,12));
        players.push_back( Player("Marcus Thuram","Delantero","Bundesliga", 7,205,8));
        players.push_back( Player("Alex Berenguer","Medio Derecho","LaLiga", 10,452,14));
        players.push_back( Player("Michael Gregoritsch","Delantero","Bundesliga", 7,103,7));
    //===========================Casos de prueba=================================================    
    
    
    
    std::vector<Player> prueba1 = players;
    std::vector<Player> prueba2 = players;
    std::string respuestas[] ={"Nombre: Lionel Messi Goles: 35\n","Nombre: Cristiano Ronaldo Goles: 30\n","Nombre: Robert Lewandoski Goles: 27\n",
    "Nombre: Kolo Muani Goles: 26\n", "Nombre: Patric Schick Goles: 25\n","Nombre: Christopher Nkunku Goles: 25\n","Nombre: Harry Kane Goles: 25\n",
    "Nombre: Karim Benzema Goles: 22\n", "Nombre: Leroy Sane Goles: 21\n","Nombre: Vinicus Jr Goles: 20\n",
    "Nombre: Donyell Malen Goles: 20\n","Nombre: Neymar Jr. Goles: 20\n","Nombre: Mikel Oyazarbal Goles: 19\n",
    "Nombre: Timo Werner Goles: 19\n", "Nombre: Iago Aspas Goles: 18\n","Nombre: Antoine Griezmann Goles: 17\n","Nombre: Joselu Goles: 16\n",
    "Nombre: Vicenzo Grifo Goles: 16\n", "Nombre: Moussa Diaby Goles: 16\n","Nombre: Niklas Fullkrug Goles: 16\n",
    "Nombre: Alejandro Gomez Goles: 15\n","Nombre: Ousmane Dembele Goles: 15\n","Nombre: Lois Openda Goles: 15\n",
    "Nombre: Sadio Mane Goles: 14\n", "Nombre: Raphinha Goles: 13\n","Nombre: Rodrigo Goes Goles: 13\n","Nombre: Serge Gnabry Goles: 13\n",
    "Nombre: Iker Munian Goles: 12\n","Nombre: Sebastian Haller Goles: 12\n","Nombre: Yanick Carrasco Goles: 11\n",
    "Nombre: Benjamin Sesko Goles: 11\n", "Nombre: Alex Berenguer Goles: 10\n","Nombre: Ferran Torres Goles: 10\n","Nombre: Marco Asensio Goles: 10\n",
    "Nombre: Marcos Llorente Goles: 9\n",
    "Nombre: Marcos Acuña Goles: 9\n", "Nombre: Mario Gotze Goles: 8\n","Nombre: Michael Gregoritsch Goles: 7\n","Nombre: Marcus Thuram Goles: 7\n",
    "Nombre: Daniel Szoboszlai Goles: 7\n","Nombre: Raphael Guerreiro Goles: 7\n","Nombre: Anthony Modeste Goles: 7\n"
    };

int i = 0;
prueba1 = ordenaMergeAscendente(players);
std::cout << "Prueba 1 - ordenaMergeAscendente:\n";
std::cout << "  Resultado:\n";

for (const Player &player : prueba1) {
    std::cout << "Numero: "<< i << std::endl;
    std::cout << "\nesperada " << respuestas[i] << "\n programa " << player.toString() << "\n";
    std::cout << (strcasecmp(respuestas[i].c_str(), player.toString().c_str()) == 0 ? "success\n" : "fail\n");
    i++;
}
      
prueba2 = ordenaMergeDescendente(players);
std::cout << "Prueba 2 - ordenaMergeDescendente:\n";
std::cout << "  Resultado:\n";
std::string respuestasInvertidas[] = {
    "Nombre: Michael Gregoritsch Goles: 7 \n",
    "Nombre: Marcus Thuram Goles: 7\n",
    "Nombre: Daniel Szoboszlai Goles: 7\n",
    "Nombre: Raphael Guerreiro Goles: 7\n",
    "Nombre: Anthony Modeste Goles: 7\n"   ,
    "Nombre: Mario Gotze Goles: 8\n",
    "Nombre: Marcos Llorente Goles: 9\n",
    "Nombre: Marcos Acuña Goles: 9\n",
    "Nombre: Alex Berenguer Goles: 10\n",
    "Nombre: Ferran Torres Goles: 10\n",
    "Nombre: Marco Asensio Goles: 10\n",
    "Nombre: Yanick Carrasco Goles: 11\n",
    "Nombre: Benjamin Sesko Goles: 11\n",
    "Nombre: Iker Munian Goles: 12\n",
    "Nombre: Sebastian Haller Goles: 12\n",
    "Nombre: Raphinha Goles: 13\n",
    "Nombre: Rodrigo Goes Goles: 13\n",
    "Nombre: Serge Gnabry Goles: 13\n",
    "Nombre: Sadio Mane Goles: 14\n",
    "Nombre: Alejandro Gomez Goles: 15\n",
    "Nombre: Ousmane Dembele Goles: 15\n",
    "Nombre: Lois Openda Goles: 15\n",
    "Nombre: Joselu Goles: 16\n",
    "Nombre: Vicenzo Grifo Goles: 16\n",
    "Nombre: Moussa Diaby Goles: 16\n",
    "Nombre: Niklas Fullkrug Goles: 16\n",
    "Nombre: Antoine Griezmann Goles: 17\n",
    "Nombre: Iago Aspas Goles: 18\n",
    "Nombre: Mikel Oyazarbal Goles: 19\n",
    "Nombre: Timo Werner Goles: 19\n",
    "Nombre: Vinicus Jr Goles: 20\n",
    "Nombre: Donyell Malen Goles: 20\n",
    "Nombre: Neymar Jr. Goles: 20\n",
    "Nombre: Leroy Sane Goles: 21\n",
    "Nombre: Karim Benzema Goles: 22\n",
    "Nombre: Patric Schick Goles: 25\n",
    "Nombre: Christopher Nkunku Goles: 25\n",
    "Nombre: Harry Kane Goles: 25\n"    ,
    "Nombre: Kolo Muani Goles: 26\n",
    "Nombre: Robert Lewandoski Goles: 27\n",
    "Nombre: Cristiano Ronaldo Goles: 30\n",
    "Nombre: Lionel Messi Goles: 35\n"
}; 


i = 0;
for (const Player &player : prueba2) {
    std::cout << "Numero: "<< i << std::endl;
    std::cout << "\nesperada " << respuestasInvertidas[i] << "\n programa " << player.toString() << "\n";
    std::cout << (strcasecmp(respuestasInvertidas[i].c_str(), player.toString().c_str()) == 0 ? "success\n" : "fail\n");
    i++;
}      
//Output: "No se encontro un jugador con ese nombre"
std::cout << "Prueba 3" << std::endl;
filtrarJugadores(players,"Goku"); 

        
//Output: "Nombre: Lionel Messi Valor: 70 Goles: 35"
std::cout << "Prueba 4" << std::endl;
filtrarJugadores(players,"Lionel Messi");

std::vector <Player>prueba5 = mostrarJugadoresDeLiga(players,"LaLiga");
std::cout << "Prueba 5 - mostrarJugadoresDeLiga:\n";
std::cout << "  Resultado:\n";
std::string respuestas5[] = {
    "Nombre: Neymar Jr. Goles: 20\n",
    "Nombre: Lionel Messi Goles: 35\n",
    "Nombre: Cristiano Ronaldo Goles: 30\n",
    "Nombre: Robert Lewandoski Goles: 27\n",
    "Nombre: Karim Benzema Goles: 22\n",
    "Nombre: Rodrigo Goes Goles: 13\n",
    "Nombre: Vinicus Jr Goles: 20\n",
    "Nombre: Marcos Acuña Goles: 9\n",
    "Nombre: Yanick Carrasco Goles: 11\n",
    "Nombre: Marcos Llorente Goles: 9\n",
    "Nombre: Ousmane Dembele Goles: 15\n",
    "Nombre: Raphinha Goles: 13\n",
    "Nombre: Marco Asensio Goles: 10\n",
    "Nombre: Iker Munian Goles: 12\n",
    "Nombre: Alejandro Gomez Goles: 15\n",
    "Nombre: Ferran Torres Goles: 10\n",
    "Nombre: Joselu Goles: 16\n",
    "Nombre: Alex Berenguer Goles: 10\n"
}; 
i = 0;
for (const Player &player : prueba5) {
    std::cout << "Numero: "<< i << std::endl;
    std::cout << "\nesperada " << respuestas5[i] << "\n programa " << player.toString() << "\n";
    std::cout << (strcasecmp(respuestas5[i].c_str(), player.toString().c_str()) == 0 ? "success\n" : "fail\n");
    i++;
} 

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
                std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 2){
                jugadoresClasificados = ordenaMergeAscendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
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
                std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
                }
            }
            else if(opcion == 2){
                jugadoresClasificados = ordenaMergeAscendente(jugadoresClasificados);
                for (const auto& jugador : jugadoresClasificados) {
                std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
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
                std::cout << "Jugador encontrado: " << jugador.getNombre() << "\n Su valor es: " << jugador.getValor() << "\n Sus goles es: " << jugador.getGoles() << std::endl;
            }
        }
         
        else if (opcion == 5){ 
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
