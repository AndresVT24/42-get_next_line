*Este proyecto ha sido creado como parte del currículo de 42 por ervillca.*

# get_next_line

## Descripción

`get_next_line` es un proyecto de la escuela 42 cuyo objetivo es implementar una función en C capaz de leer y devolver una línea completa desde un descriptor de archivo.

La función principal del proyecto es:

```c
char *get_next_line(int fd);
```

Cada llamada a `get_next_line` devuelve la siguiente línea disponible del descriptor de archivo recibido como parámetro. Esto permite leer archivos, la entrada estándar u otros descriptores línea por línea hasta llegar al final del contenido.

El proyecto trabaja conceptos fundamentales de C como la gestión manual de memoria, el uso de descriptores de archivo, la función `read`, las variables estáticas y la manipulación de strings.

## Instrucciones

### Compilación

El proyecto se compila indicando un tamaño de buffer mediante la macro `BUFFER_SIZE`.

Ejemplo:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

También debería poder compilar sin definir explícitamente `BUFFER_SIZE`, siempre que el header tenga un valor por defecto.

Ejemplo:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

### Ejemplo de uso

Un ejemplo básico de `main.c` para probar la función:

```c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Compilación:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Ejecución:

```bash
./a.out
```

## Comportamiento esperado

La función debe devolver una línea cada vez que se llama.

Una línea incluye el carácter `\n` si existe en el archivo. Si se llega al final del archivo y la última línea no termina con `\n`, se devuelve igualmente esa última línea.

La función devuelve `NULL` cuando:

- No queda nada más por leer.
- Ocurre un error de lectura.
- El descriptor de archivo no es válido.
- Hay un fallo de memoria.

Ejemplo de archivo:

```txt
Hola
42 Barcelona
get_next_line
```

Llamadas sucesivas a `get_next_line(fd)` devolverían:

```txt
"Hola\n"
"42 Barcelona\n"
"get_next_line\n"
NULL
```

## Bonus

La parte bonus añade soporte para múltiples descriptores de archivo al mismo tiempo.

Esto significa que `get_next_line` debe poder leer de varios `fd` de forma alterna sin mezclar el contenido de unos con otros.

Ejemplo conceptual:

```c
get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);
get_next_line(fd3);
```

Cada descriptor debe conservar su propio estado de lectura.

Para conseguirlo, normalmente se usa una estructura estática capaz de guardar un buffer independiente por descriptor de archivo.

## Recursos

Referencias útiles para entender los conceptos usados en este proyecto:

```bash
man 2 read
man malloc
man free
man 2 open
```

También son útiles:

- Documentación sobre variables estáticas en C.
- Documentación sobre file descriptors en sistemas Unix.
- Apuntes personales y pruebas realizadas durante el desarrollo.

## Uso de IA

Durante este proyecto, la IA se ha utilizado únicamente como apoyo para la redacción y organización de este README.

No se ha utilizado para copiar una solución completa del código. El objetivo del proyecto es comprender el funcionamiento de `read`, la memoria dinámica, las variables estáticas y la gestión de strings en C.

Cualquier ayuda externa debe usarse de forma responsable, asegurando que el código final pueda ser explicado, defendido y modificado durante una evaluación.

## Autor

Proyecto realizado por:

`<ervillca>`

42 Barcelona.