## Task #PC3: Simulacro Practica Calificada 3  
**course:** Programación III  
**unit:** 6  
**cmake project:** prog3_pc3_TEO4_v2024_1
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `check_hidden_heap.h`
    - `lazy_hash_table.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.

### Question #1 - check_hidden_heap (7 points)

#### **Objetivo:**  
Implementa una función que determine si un arreglo contiene un heap oculto, donde los elementos del heap están separados por una distancia constante `s`, y si es así, determinar si es un min-heap o un max-heap.  
#### **Descripción:**  
Se te proporciona un arreglo de enteros y un valor `s` que representa la separación entre los elementos del supuesto heap. Tu tarea es implementar una función que verifique si los elementos del arreglo, tomados cada `s` posiciones, forman un heap válido. Además, debes determinar si es un `min-heap` o un `max-heap`.  
#### **Requisitos:**  
- No puedes usar `std::is_heap` o funciones similares de la biblioteca estándar.
- Debes implementar tu propia lógica para revisar la propiedad de heap.
- La función debe devolver un resultado que indique si es un heap válido y, en caso afirmativo, si es un `min-heap` o `max-heap`. 
- Considera que el primer elemento del heap está en el índice `0` del arreglo.

#### **Resultados posibles**:
- `return HeapType::MinHeap`: Has descubierto un min-heap oculto.
- `return HeapType::MaxHeap`: Has encontrado un max-heap escondido.
- `return HeapType::NotHeap`: No hay heap escondido en este arreglo.

**Nota:** La complejidad temporal de tu solución debe ser `O(n)`, donde `n` es el número de elementos en el heap oculto (no en el arreglo completo).

Declaración de la función:
```cpp
  enum class HeapType { MinHeap, MaxHeap, NotHeap };
  template <typename Container>
  HeapType check_hidden_heap(const Container& arr, int s);
```

**Use Case #1:**
```cpp
  std::vector<int> arr = {1, 2, 4, 1, 2, 5, 12, 11, 5};
  auto result = check_hidden_heap(arr, 2);
  
  // Debería imprimir 0 (HeapType::MinHeap)
  std::cout << static_cast<int>(result) << std::endl; 
```

**Otros Casos de prueba:**
```cpp
  {1, 2, 4, 1, 2, 5, 12, 11, 5}, s = 2                        // (HeapType::MinHeap)
  {20, 1, 15, 2, 3, 10, 8, 4, 5}, s = 3                       // (HeapType::MaxHeap)
  {5, 1, 4, 2, 3, 6, 7, 8, 9}, s = 1                          // (HeapType::NotHeap)
  {100, 2.3, 3, 50, 4.5, 5, 60, 6, 7.5}, s = 4                // (HeapType::MaxHeap)
  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, s = 5  // (HeapType::MinHeap)
  {"zebra", "apple", "banana", "cat", "dog", "elephant", "fox", "giraffe", "horse"}, s = 3; // (HeapType::MaxHeap) 
```

### Question #2 - LazyHashTable Implementation (7 points)

#### **Objetivo:**
Implementa una clase de tabla hash perezosa (`LazyHashTable`) que permita insertar, buscar y reestructurar elementos de manera eficiente.

#### **Descripción:**
Se te pide implementar una tabla hash perezosa (`LazyHashTable`) que almacene elementos y permita las siguientes operaciones:

1. **Añadir un elemento (`add`)**: Inserta un elemento en la tabla hash si no está ya presente.
2. **Buscar un elemento (`find`)**: Verifica si un elemento está presente en la tabla hash.
3. **Reestructurar la tabla (`reshape`)**: Cambia el tamaño de la tabla hash y reubica los elementos. Si se produce una colisión durante la reestructuración, la operación falla.
4. **Iteradores (`begin` y `end`)**: Devuelve iteradores para recorrer la tabla hash.

#### **Requisitos:**
- La tabla hash debe utilizar un vector de pares de booleanos y elementos (`std::vector<std::pair<bool, T>>`) para almacenar los elementos.
- La función hash debe ser un functor pasado como plantilla, con un valor por defecto de `std::hash<T>`.
- La tabla hash debe manejar las colisiones de manera sencilla mediante la verificación de disponibilidad en la posición hash calculada usando el método de división: `h(k) % m`.
- La operación `reshape` debe redimensionar la tabla hash, reubicando todos los elementos. Si se produce una colisión durante esta reubicación, la operación debe fallar y la tabla debe permanecer sin cambios.

Declaración de la clase:
```cpp
template <typename T, typename Hash = std::hash<T>>
class LazyHashTable;
```

**Use Case #1:**
```cpp
    LazyHashTable<int> table(10);
    
    // Añadir elementos
    table.add(5);  // true
    table.add(15); // true (colisión si no se maneja correctamente)
    table.add(5);  // false (ya está presente)

    // Buscar elementos
    std::cout << table.find(5) << std::endl;  // true
    std::cout << table.find(10) << std::endl; // false

    // Reestructurar la tabla
    std::cout << table.reshape(20) << std::endl; // true dependiendo de si la reestructuración fue exitosa
```

**Use Case #2:**
```cpp
    LazyHashTable<std::string> table(5);
    
    // Añadir elementos
    table.add("apple");  // true
    table.add("banana"); // true
    table.add("cherry"); // true
    table.add("date");   // true
    table.add("fig");    // true
    table.add("grape");  // false (colisión)

    // Buscar elementos
    std::cout << table.find("banana") << std::endl; // true
    std::cout << table.find("kiwi") << std::endl;   // false

    // Reestructurar la tabla
    std::cout << table.reshape(10) << std::endl; // true o false dependiendo de si la reestructuración fue exitosa
```
