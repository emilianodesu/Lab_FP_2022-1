/*
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Jorge A. Solano
 *
 */

#include <stdio.h>

int main(int argc, char **argv){
    FILE *ap;
    unsigned char buffer[2048]; // Buffer de 2 Kbytes
    int bytesLeidos;
    // Si no se ejecuta el programa correctamente
    if (argc < 2){
    printf("Ejecutar el programa de la siguiente manera:\n\tnombre_\tprograma nombre_archivo\n");
    return 1;
    }
    // Se abre el archivo de entrada en modo lectura y binario
    ap = fopen(argv[1], "rb");
    if (!ap){
        printf("El archivo %s no existe o no se puede abrir", argv[1]);
        return 1;
    }
    while (bytesLeidos = fread(buffer, 1, 2048, ap)){
        printf("%s", buffer);
    }
    fclose(ap);

    return 0;
}