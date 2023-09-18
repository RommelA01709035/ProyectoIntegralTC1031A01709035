# ProyectoIntegralTC1031A01709035
Este es mi proyecto de la materia "Programación de estructura de datos y algoritmos fundamentales".

 Buscador de jugadores a partir de sus estadisticas básicas.
Este proyecto se hizo a para simular la necesidad que tienen los reclutadores para encontrar jugadores para sus equipos.
Se utiliza memoria estatica para ejemplificar las funciones del menú y se usan pocos parámetros en esta versión.
>Ejemplo 1: Marca a seguir un jugador, (Joselu)
> 
>Paso 1: Introducir el peso el número de opcion en el menu. Por ejemplo: 1.
>Paso 2: Introducir la opción deseada. Por ejemplo : 3.
>Paso 3: Escribe el nombre del jugador. Por ejemplo: Joselu
> 
>Con estos datos se manda a llamar a la función marcarJugador que devuelve un objeto de tipo player. Donde si el jugador es encontrado va imprimir algunos atributos y lo guardará en un vector local en main, sino retornará el objeto "notFound".
>
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

## SICT0302: Toma decisiones 
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Uso el algoritmo Merge Sort ya que su funcionamiento hace que sea más rápido y esto ayuda ya que estamos usando memoria estatica, por lo que al tener un número predefinido del tamaño de un vector va a ser agilmente acceder a los datos, además que no nos tenemos que preocupar por organizar la memoria (ya sea en liberar espacio o asignarlo). También use Merge Sort porque su tiempo de ejecución es el mismo (nlog(n)) en todos sus casos.
Las funciones donde se puede ver es en ordenaMergeDescendente (de la línea 27 a la 83) y ordenaMergeAscendente (Linea 84 a la 136) en el archivo main.cpp .




