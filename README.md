# C estructurado: ejercicios y prácticas

Repositorio de ejercicios y trabajos prácticos desarrollados en **C estructurado** durante la cursada de **Elementos de Programación**.

El conjunto reúne prácticas de entrada y salida, control de flujo, arreglos, estructuras, funciones, punteros, recursividad, ordenamiento, búsqueda y persistencia en archivos binarios. Incluye ejercicios integradores y parciales resueltos.

## Contenido

- **Más de 200 archivos fuente `.c`**
- Ejercicios independientes sobre matemáticas, cadenas, fechas y estructuras de datos básicas
- Ejemplos de sistemas administrativos y empresariales
- Funciones de carga, validación, ordenamiento, búsqueda y generación de informes
- Ejercicios con archivos binarios y datos de prueba en formato `.dat`
- Archivos compilados `.exe`, objetos `.o` y datos históricos incluidos en el repositorio
- Dos carpetas con entregas de parciales:
  - `1erparcialverano/`
  - `2doparcialverano/`

## Stack tecnológico

| Componente | Uso |
|---|---|
| Lenguaje C | Implementación de todos los ejercicios |
| Funciones de biblioteca estándar | `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<ctype.h>` |
| Consola MS-DOS/Windows | `<conio.h>` y funciones como `getch()` |
| API de Windows | `<windows.h>` y `Sleep()` en algunos ejercicios |
| Archivos binarios | `fopen()`, `fread()` y `fwrite()` con registros estructurados |
| IDE/compilador Windows | Artefactos PE32 y objetos COFF de Intel 80386 |
| Datos de prueba | Archivos `.dat` y `.txt` utilizados por los ejercicios |

## Conceptos y funcionalidades practicadas

### Fundamentos

- Variables, constantes y operadores
- Conversión de unidades y cálculos matemáticos
- Entrada y salida por consola
- Validación de rangos y datos ingresados
- Uso de sentencias `if`, `switch` y estructuras iterativas

### Funciones y punteros

- Diseño de funciones con parámetros y valores de retorno
- Paso de parámetros por valor y por referencia
- Funciones auxiliares para cargar, validar, inicializar y mostrar datos
- Ejercicios de ternas y operaciones con punteros
- Recursividad con factorial y otros ejemplos

### Arreglos y matrices

- Vectores de contadores y acumuladores
- Carga y recorrido de arreglos
- Compactación de caracteres
- Clasificación de datos y cálculo de máximos, mínimos y promedios
- Matrices utilizadas para informes multidimensionales
- Comparación y procesamiento de dos vectores

### Algoritmos de ordenamiento y búsqueda

- Ordenamiento por burbujeo
- Ordenamiento por selección
- Ordenamiento conservando el orden de ingreso
- Ordenamiento de estructuras
- Búsqueda secuencial
- Búsqueda de registros por claves como DNI o número de legajo

### Estructuras

- Definición de `struct`
- Estructuras anidadas
- Registros con nombre, apellido, fechas, alturas y otros campos
- Procesamiento de alumnos, automóviles, inmuebles, artículos y empleados
- Construcción de informes y resúmenes a partir de arreglos de estructuras

### Archivos

- Escritura y lectura de archivos binarios
- Archivos maestros y archivos de movimientos
- Actualización de registros
- Generación de archivos derivados y listados
- Trabajo con datos persistentes como `DATOSPERSONAS.dat`, `artículos.dat`, `empleados.dat` y archivos de ventas

### Ejemplos integradores

Los programas más completos combinan varias prácticas en un caso de uso:

- Administración de bancos y movimientos de saldos
- Control de ventas y facturación
- Gestión de empleados y sueldos
- Registro de productos, artículos y pedidos
- Manejo de depósitos, vehículos y viajes
- Teatro, cine y clubes deportivos
- Fábricas, comercios, distribuidores y empresas de servicios
- Procesamiento de temperaturas, edades y registros académicos

Algunos ejemplos representativos son:

- `manejo de estructuras 1.c`
- `datos personales_grabar archivo.c`
- `datos personales_leer y ordenar archivo c fn.c`
- `ordenamiento con burbujeo acarreando el orden.c`
- `ordenamiento con seleccion acarreando el orden.c`
- `ternas función con punteros.c`
- `matriz a archivo y viceversa.c`
- `fn factorial recursiva.c`
- `2doparcialverano/parcial diagrama.c`

## Organización del repositorio

El repositorio utiliza una estructura mayormente plana: cada ejercicio guarda su fuente `.c`, su objeto `.o` y, cuando fue compilado, su ejecutable `.exe` con nombres similares.

```text
.
├── *.c                       Código fuente de los ejercicios
├── *.o                       Objetos compilados para Windows
├── *.exe                     Ejecutables de consola de 32 bits
├── *.dat / *.txt             Archivos de datos utilizados por los programas
├── 1erparcialverano/         Primera entrega de parcial
└── 2doparcialverano/         Segunda entrega de parcial
```

Algunos programas crean o modifican archivos `.dat` en el directorio desde el que se ejecutan. Conviene ejecutar las versiones relacionadas desde la raíz del repositorio y conservar una copia de los datos originales.

## Requisitos

Para trabajar con el código fuente se recomienda:

- Un compilador C compatible, como MinGW-w64
- Windows o Wine para ejecutar directamente los binarios `.exe` incluidos
- GCC/Clang para compilar ejercicios compatibles con Linux o macOS
- Una terminal o IDE capaz de mostrar salida de consola

Debido al uso de `conio.h`, `windows.h`, `void main()` y otras extensiones propias de compiladores de Windows, no todos los programas son portables sin cambios.

## Compilación

Ejemplo con GCC o MinGW:

```sh
gcc "ej1 secuencial.c" -o "ej1 secuencial.exe"
./"ej1 secuencial.exe"
```

En Windows, el ejecutable puede ejecutarse desde la terminal:

```powershell
.\ej1 secuencial.exe
```

Ejemplo con GCC sobre un ejercicio sin dependencias específicas de Windows:

```sh
gcc "número perfecto.c" -o numero-perfecto
./numero-perfecto
```

La ejecución puede depender de archivos `.dat` ubicados junto al programa. Por ejemplo, los ejercicios de personas pueden leer o escribir `DATOSPERSONAS.dat`.

## Consideraciones del contenido

Este es un repositorio educativo y conserva su evolución histórica:

- Varias fuentes utilizan caracteres acentuados codificados como ISO-8859-1 o Windows-1252.
- Algunos nombres contienen tildes, eñes y signos de puntuación.
- Hay ejemplos con entradas, funciones o declaraciones propias de compiladores antiguos.
- Algunos ejercicios incluyen artefactos binarios generados en distintas etapas del aprendizaje.
- Parte del código conserva propuestas de parciales o trabajos prácticos originales.
- Los programas pueden requerir ajustes para compilar con estándares modernos o portabilidad POSIX.

La estructura fue preservada para facilitar la consulta de cada práctica por nombre y tema.

## Autor

Fabián Norberto Escobar.

La carpeta `2doparcialverano/` y los archivos históricos mantienen la información de identificación correspondiente a la entrega original.
