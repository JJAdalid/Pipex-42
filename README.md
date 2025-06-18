# Pipex

> Proyecto de la escuela 42: Reproducir la funcionalidad de los pipes de UNIX en C

## Descripción

**Pipex** es un proyecto cuyo objetivo es entender y replicar cómo funciona el encadenamiento de comandos usando pipes en sistemas UNIX, tal como lo hace la shell. El ejercicio consiste en ejecutar dos comandos conectados por un pipe, donde la salida del primero sirve como entrada del segundo, utilizando llamadas al sistema como `fork()`, `pipe()`, `dup2()`, y `execve()`.

## Uso

Compila el proyecto con:

```bash
make
```

Esto generará el ejecutable `pipex`.

### Ejecución

El programa se usa de la siguiente forma:

```bash
./pipex archivo_entrada "comando1" "comando2" archivo_salida
```

- `archivo_entrada`: archivo desde el que se leerá la entrada para el primer comando.
- `comando1`: primer comando a ejecutar (puede incluir argumentos).
- `comando2`: segundo comando a ejecutar (puede incluir argumentos).
- `archivo_salida`: archivo donde se guardará la salida del segundo comando.

#### Ejemplo

```bash
./pipex infile "grep hola" "wc -l" outfile
```

Esto ejecuta `grep hola < infile`, y pasa su salida a `wc -l`, guardando el resultado en `outfile`.

## Cómo funciona

1. **Creación del pipe:** Se crea un pipe que conecta la salida del primer comando con la entrada del segundo.
2. **Fork y ejecución:** El programa crea dos procesos hijos con `fork()`.  
   - El primer hijo redirige su entrada al archivo de entrada y su salida al pipe, luego ejecuta el primer comando.
   - El segundo hijo lee la entrada del pipe y redirige la salida al archivo de salida, luego ejecuta el segundo comando.
3. **Gestión de errores:** Si ocurre un error (por ejemplo, archivo no encontrado, comando inválido), se muestra un mensaje y el programa termina con el código adecuado.

## Estructura

- `pipex.c` — Lógica principal del programa, gestión de procesos y pipes.
- `pipex_utils.c` — Funciones auxiliares: gestión de archivos, búsqueda de rutas, manejo de errores.
- `pipex.h` — Cabecera con prototipos de funciones.
- `libft/` — Librería auxiliar propia (debes tenerla en la carpeta).

## Compilación y limpieza

- `make` — Compila el ejecutable.
- `make clean` — Elimina los archivos objeto.
- `make fclean` — Elimina el ejecutable y los archivos objeto.
- `make re` — Limpia y recompila todo.

## Notas

- Este código es educativo y cumple con las normas de la escuela 42, evitando cualquier tipo de plagio.
- No incluye funcionalidades extra como soporte para múltiples pipes o here-document (bonus no obligatorio).

---

## ¡Logro destacado!

¡Este proyecto ha obtenido la máxima puntuación!  
![100 conseguido](imgs/suces100.png)

---

**Autor:** [jadalid-](https://github.com/JJAdalid)  
**Proyecto académico, uso didáctico.**
