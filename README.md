# ProyectoIntegralTC1031A01709035
Este es mi proyecto de la materia "Programación de estructura de datos y algoritmos fundamentales".

Ya hay casos de prueba programados solo debe correr el programa y desplazar hacia arriba y verá los casos.

 Buscador de jugadores a partir de sus estadisticas básicas.
Este proyecto se hizo a para simular la necesidad que tienen los reclutadores para encontrar jugadores para sus equipos.
Se utiliza memoria estatica para ejemplificar las funciones del menú y se usan pocos parámetros en esta versión.
>Ejemplo 1: Marca a seguir un jugador, (Joselu)
 
Paso 1: Introducir el número de opcion en el menu. Por ejemplo: 1.

Paso 2: Introducir la opción deseada. Por ejemplo : 3.

Paso 3: Escribe el nombre del jugador. Por ejemplo: Joselu

Paso 4: Introducir el número de opcion en el menu. Por ejemplo: 2.

Paso 2: Introducir la opción deseada. Por ejemplo : 3.

Paso 3: Escribe el nombre del jugador. Por ejemplo: Harry Kane

Paso 1: Introducir el número de opcion en el menu. Por ejemplo: 1.

Paso 2: Introducir la opción deseada. Por ejemplo : 3.

Paso 3: Escribe el nombre del jugador. Por ejemplo: Lionel Messi

 
>Con estos datos se manda a llamar a la función marcarJugador que devuelve un objeto de tipo player. Donde si el jugador es encontrado va imprimir algunos atributos y lo guardará en un archivo de texto local y también lo guardará en el SplayTree llamado marcados (la opción 5 del menú despliega en pantalla todos los jugadores que haz marcado hasta el momento), sino retornará el objeto "notFound".

Adicionalmente incluyo las funciones para filtrar un grupo de jugadores a partir de su liga y ver sus atributos, también dentro de las funciones del menu se añaden opciones para ordenar estos jugadores ya sea de forma ascendete o descendente, una función de buscar un jugador en especifico y finalmente otra opción para ver que jugadores estan marcados 

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
la funcion de marcarJugadores: Como usamos la funciòn toString de la clase LInear (que representa un Hash) tendríamos que el método vale O(n) porque va a depender de que tan llena este la tabla.

### Analisis asintotico total

Ejemplificando el caso promedio de consulta
opcion 1 despliega los jugadores de "LaLiga" O(n) 
1.1 ordena con merge (n log n)
regresa al menu y el resultado final es:
O(n)+nlogn = nlogn (porque esogemos el caso más complejo)

## SICT0302: Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Uso el algoritmo Merge Sort ya que su funcionamiento hace que sea más rápido y esto ayuda ya que estamos usando memoria estatica, por lo que al tener un número predefinido del tamaño de un vector va a ser agilmente acceder a los datos, además que no nos tenemos que preocupar por organizar la memoria (ya sea en liberar espacio o asignarlo). También use Merge Sort porque su tiempo de ejecución es el mismo (nlog(n)) en todos sus casos.
Las funciones donde se puede ver es en ordenaMergeDescendente (de la línea 27 a la 83) y ordenaMergeAscendente (Linea 84 a la 136) en el archivo main.cpp .

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Use el Hash dado que al inicializarlo puedo contemplar a todos los jugadores y además tienen una clave unica lo cual hace que en el mejor de los casos la notación sea de O(1) sin embargo en el peor de los casos puede llegar a ser de O(n) (colisiones) que también es algo bueno considerando que otras estructuras son peores en esta situación, como vas a meter pocos jugadores que son los que te interesan lo que va a pasar es que como un jugador esta registrado por su nombre completo no se repetiría la posición y además es poco probable que llenes la tabla completa porque no te van a interesar todos los jugadores en una aplicación real de este software.

## SICT0303: Implementa acciones científicas
En este caso al ser un hash utiliza el resultado del hash (donde un hash%size de la tabla) y devuelve el valor de acuerdo a la clave que se proporcionó.

### Implementa mecanismos para consultar información de las estructras correctos.
EN este caso utilice un Hash y el método donde hace una busqueda y esto se puede ver así:

 Paso 1: seleccione la opcion 1 del menu
 Paso 1.1 Seleccione la opcion 3 del menu "Marcar jugador" y escriba literalmente Joselu o cualquier nombre de algún jugador cargado.
 Paso 2 ponga la opción 6 del menu
 Paso 3 Escriba el nombre que puso de algún jugador marcado en este caso Joselu
 Paso 4 aparecerá en pantalla

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Se implementa la lectura de archivos para ingresar la información guardada en los objetos de los jugadores y para las respuestas en los casos de prueba ahorrando memoria en no crear otros vectores.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.
Se implementa la escritura de archivos en los jugadores marcados ya que sería el reporte de los jugadores que te interesaron.


