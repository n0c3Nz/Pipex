# Pipex
El programa Pipex está diseñado para emular el funcionamiento de los pipes de bash utilizando C.
Proporciona una forma de redirigir la salida de un comando a la entrada de otro, imitando así la funcionalidad de los pipes en la línea de comandos de Unix.

*·* Este programa admite tanto rutas absolutas como rutas relativas.
## Uso
Para compilar el programa descárguelo y ejecute el siguiente comando:

```bash
make
```
## Ejecución

```bash
./pipex infile "command1" "command2" outfile

```
`infile` : Nombre del archivo de entrada.

`"command1"` : Primer comando que se ejecutará.

`"command2"` : Segundo comando que se ejecutará.

`outfile` : Nombre del archivo de salida donde se almacenará el resultado.
### Ejemplo de uso

```bash
./pipex infile "grep hello" "wc -l" outfile
```

### Extra
Este programa admite comillas simples en sus comandos, como por ejemplo:
```bash
./pipex infile "ls -l" "awk '{print $a}'" outfile

```

#### Contribuciones

Las contribuciones son bienvenidas. Siéntase libre de crear un fork de este repositorio, hacer mejoras y enviar un pull request.
