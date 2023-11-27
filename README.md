# ProyectoIntegralTC1031A01709035
Este es mi proyecto de la materia "Programación de estructura de datos y algoritmos fundamentales".

Ya hay casos de prueba programados solo debe correr el programa y desplazar hacia arriba y verá los casos.

 Buscador de jugadores a partir de sus estadisticas básicas.
Este proyecto se hizo a para simular la necesidad que tienen los reclutadores para encontrar jugadores para sus equipos.
Se utiliza memoria estatica para ejemplificar las funciones del menú y se usan pocos parámetros en esta versión.
>Ejemplo 1: Marca a seguir un jugador, (Joselu)
> 
>Paso 1: Introducir el número de opcion en el menu. Por ejemplo: 1.
>
>Paso 2: Introducir la opción deseada. Por ejemplo : 3.
>
>Paso 3: Escribe el nombre del jugador. Por ejemplo: Joselu
>
>Paso 4: Introducir el número de opcion en el menu. Por ejemplo: 2.
>Paso 2: Introducir la opción deseada. Por ejemplo : 3.
>Paso 3: Escribe el nombre del jugador. Por ejemplo: Harry Kane
>Paso 1: Introducir el número de opcion en el menu. Por ejemplo: 1.
>Paso 2: Introducir la opción deseada. Por ejemplo : 3.
>Paso 3: Escribe el nombre del jugador. Por ejemplo: Lionel Messi
> 
>Con estos datos se manda a llamar a la función marcarJugador que devuelve un objeto de tipo player. Donde si el jugador es encontrado va imprimir algunos atributos y lo guardará en un archivo de texto local y también lo guardará en el SplayTree llamado marcados (la opción 5 del menú despliega en pantalla todos los jugadores que haz marcado hasta el momento), sino retornará el objeto "notFound".
>
Adicionalmente incluyo las funciones para filtrar un grupo de jugadores a partir de su liga y ver sus atributos, también dentro de las funciones del menu se añaden opciones para ordenar estos jugadores ya sea de forma ascendete o descendente, una función de buscar un jugador en especifico y finalmente otra opción para ver que jugadores estan marcados 

### Nota importante

Para poner los archivos de texto debes descargar los archivos de texto y poner su ruta completa.


## SICT0301: Evalúa los componentes 
### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

#### ordenaMergeAscendente y ordenaMergeDescendente

función de ordenaMergeAscendente y ordenaMergeDescendente: O(n*log(n)) por que para llegar al ordenamiento divido los arrays, por lo que cada paso que doy es más grande, mientras que se multiplica por esas enes ya que una n simboliza a la función mergeArrayAscendente o mergeArrayDescendente donde va combinanado dos vectores los cuales tienen una n longitud y la otra n es la representación de la función copyArrayAscendentes o copyArrayDescendente la cual solo copia n elementos de un vector.

#### filtrarJugadores
la funcion de filtrarJugadores: O(n) porque recorre el vector proporcionalmente a su tamaño o sea hace el número de jugadores que estan en el vector, por lo que su cantidad de tiempo es lineal.

#### mostrarJugadoresDeLiga
la funcion de mostrarJugadoresDeLiga: O(n) porque recorre el vector proporcionalmente a su tamaño o sea hace el número de jugadores que estan en el vector, por lo que su cantidad de tiempo es lineal.

### marcarJugador
la funcion de marcarJugadores: O(n) porque recorre el vector proporcionalmente a su tamaño o sea hace el número de jugadores que estan en el vector, por lo que su cantidad de tiempo es lineal.

### cargarJugadoresDesdeArchivo y cargarRespuestasDesdeArchivo
la funcion de marcarJugadores: O(n) porque recorre el archivo de acuerdo a las líneas que hay y los va guardando en el vector en caso de la función "cargarJugadoresDesdeArchivo" y la función "cargarRespuestasDesdeArchivo" es lo mismo.

### Opción 5 del menu
la funcion de marcarJugadores: Como usamos el comportamiento de StackLIst tendríamos que los métodos valen O(1), pero al usar un ciclo que va desde el incio hasta que terminar de vaciar el StackList entonces debemos tener en cuenta la cantidad de objetos en el StackList por lo tanto su notación es de O(n) porque dependerá su recorrido de la cantidad de objetos dentro.

### opción 1,2 y 4 del menu
Las opciones 1, 2 y 4 del menú utilizan un ciclo for para recorrer los vectores que se usan para almacenar los jugadores que se filtran gracias a sus funciones, por lo que va a tener una notación O(0) lineal ya que va a recorrer todos los jugadores que filtra uno por uno y esto dependerá de que tantos jugadores necesite filtrar.

### For de prueba
Los ciclos que uso para despliegar las pruebas: O(n) porque recorre el vector proporcionalmente a su tamaño o sea hace el número de jugadores que estan en el vector, por lo que su cantidad de tiempo es lineal

## SICT0302: Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Uso el algoritmo Merge Sort ya que su funcionamiento hace que sea más rápido y esto ayuda ya que estamos usando memoria estatica, por lo que al tener un número predefinido del tamaño de un vector va a ser agilmente acceder a los datos, además que no nos tenemos que preocupar por organizar la memoria (ya sea en liberar espacio o asignarlo). También use Merge Sort porque su tiempo de ejecución es el mismo (nlog(n)) en todos sus casos.
Las funciones donde se puede ver es en ordenaMergeDescendente (de la línea 27 a la 83) y ordenaMergeAscendente (Linea 84 a la 136) en el archivo main.cpp .

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Use el SplayTree porque quiero mantener los nodos que el usuario elija de mla forma más rápida posible por lo que el SPlayTree tiene la logica adecuada para eso además que no debo usar exceptions como lo tenía que hacer con el StackList al usar el Stack. En cuanto a la logica de la opción 5 del menu es guarddar jugadores en esa estrcutra de datos porque son los jugadores que entre todos te van a interesar asi que primero seleccionas esos y haces un grupo más pequeño y después si implementará dentro de esa opción la opción de buscar a un jugador especifico pues en una perspectiva de programación tendría a los jugadores que estas siguiendo  más cerca y los ecnontraría más rápido


## SICT0303: Implementa acciones científicas


### Implementa mecanismos para consultar información de las estructras correctos.
Use el StackList dado que la froma de ordenar de forma ascendente y descendente es más fácil utilizando un solo Stack porque solamente sacas los obbjetos de una forma y después lo metes de otra, en esta versión no esta implementada la función de esto, sin embargo se añade la clase. Se combino con un StackList dado que si ponía solamente el stack o usaba un STackVector iba a ocupar mucha memoria y minimo debería haber más de 100 jugadores por lo que si uso un vector tendría acceso más rápido a los objetos, pero ocuparía bastante memoria por lo que decidí priorizar el menor uso de memoria, pero  que el acceso sea más lento

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Se implementa la lectura de archivos para ingresar la información guardada en los objetos de los jugadores y para las respuestas en los casos de prueba ahorrando memoria en no crear otros vectores.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.
Se implementa la escritura de archivos en los jugadores marcados ya que sería el reporte de los jugadores que te interesaron.


