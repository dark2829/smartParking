#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void gotoxy(int x, int y);
void imprimir();
void lugares(int caso);
void Color(int Background, int Text);

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

void main(){
char estacionamiento[10][19];// Declaramos la matriz que vamos a ocupar
int op,i,j,contador=0,contadordos=0;
// Se delimita la matriz dependiendo de los tipos de cajones
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
        estacionamiento[i][j]=NULL;//Pasillos
    }
}
for (i=0;i<1;i++){
    for (j=1;j<17;j++){
        estacionamiento[i][j]=("%c",65);//Veiculo compacto
    }
}
for (i=1;i<4;i++){
    for (j=0;j<1;j++){
        estacionamiento[i][j]=("%c",86);//Vicicleta
    }
}
for (i=4;i<5;i++){
    for (j=1;j<7;j++){
        estacionamiento[i][j]=("%c",83);//Sedan
    }
}
for (i=5;i<9;i++){
    for (j=6;j<7;j++){
        estacionamiento[i][j]=("%c",77);//Motocicleta
    }
}
for (i=1;i<9;i++){
    for (j=17;j<18;j++){
        estacionamiento[i][j]=("%c",67);//Veiculo de carga
    }
}
for (i=6;i<9;i++){
    for (j=11;j<13;j++){
        estacionamiento[i][j]=("%c",68);//Discapacitados
    }
}
for (i=5;i<9;i++){
    for (j=0;j<6;j++){
        estacionamiento[i][j]=NULL;//Pared
    }
}
for (i=9;i<10;i++){
    for (j=0;j<18;j++){
        estacionamiento[i][j]=NULL;//Pared
    }
}
estacionamiento[4][0]=NULL;//Pared
estacionamiento[0][0]=NULL;//Pared
estacionamiento[0][17]=NULL;//Pared

printf("//////////////////////////////////////\n");
printf("Tlahuicole Systems te da la Bienvenida\n");
printf("//////////////////////////////////////\n");
// hacemos la llamada de la funcion principal
principal(estacionamiento,contador,contadordos);

}

//Iniciamos con la funcion de llenado
void principal(char estacionamiento[10][19], int contador, int contadordos){//recibimos todos los parametros
int i,j,op;
printf("Que deseas hacer?\n");
printf("\n1.Ingresar carro\n2.Retirar carro\n");// Menu para dar a escoger lo que quiere el usuario
scanf("%d",&op);
switch(op){
case 1:
    if(contadordos<43){//if para saber si la matriz ya esta llena
    contadordos++;//contador para saber si la matriz esta llena
    contador++;//contador para saber si la triz esta vacia
    ingresar (estacionamiento,contador,contadordos);//LLamada a la funcion de ingresar
    }else{
    printf("\nLO SENTIMOS EL ESTACIONAMIENTO ESTA LLENO\n");
    }
break;
case 2:
    if (contador==0){//If para saber si la matriz esta vacia
    printf("\nLO SENTIMOS EL ESTACIONAMIENTO ESTA VACIO\n");
    }else{
    contadordos--;//contador para saber si la matriz esta llena
    contador--;//contador para saber si la triz esta vacia
    retirar (estacionamiento,contador,contadordos);// LLamada a la funcion de retirar
    }
break;
default :
    printf("LO sentimos opcion invalida");
break;
}
 principal(estacionamiento,contador,contadordos);//Se vuelve a llamar a la funcion principal
}


// Funcion para ingresar autos
void ingresar (char estacionamiento[10][19], int contador, int contadordos){

int op,i,j,fila,columna,caso;
printf("Que tipo de carro tienes\n");// Menu para escoger el tipo de auto
printf("1. Discapacitados\n 2. Carga\n 3. Sedan\n 4. Compacto\n 5. Moto\n 6. Vicicleta\n");
scanf("%d",&op);
switch(op){
///////////
case 1:
    system("cls");
    lugar(op);
break;

case 2:
    system("cls");
    lugar(op);
    gotoxy(1,11); printf("\n");
    break;
case 3://Caso 3 y se repite los ajustes de los casos anteriores
system("cls");
suv();
gotoxy(1,11); printf("\n");
estacionamiento[fila][columna]=("%c",244);

for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
//////////
case 4://Caso 4 y se repite los ajustes de los casos anteriores
printf("\n LOS LUGARES DISPONIBLES SE MUESTRAN CON EL CARACTER: A \n");
system("cls");
autoa();
gotoxy(1,11); printf("\n");
estacionamiento[fila][columna]=("%c",244);
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
////////
case 5://Caso 5 y se repite los ajustes de los casos anteriores
    system("cls");
moto();
gotoxy(1,11); printf("\n");
estacionamiento[fila][columna]=("%c",244);

for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
//////////
case 6: //Caso 6 y se repite los ajustes de los casos anteriores
system("cls");
vici();
gotoxy(1,11); printf("\n");
estacionamiento[fila][columna]=("%c",244);

break;
default :
    printf("LO sentimos obcion invalida");
break;
}
principal(estacionamiento,contador,contadordos);// se llama a la funcion principal
}


// Se inicia con la funcion de retirar auto
void retirar (char estacionamiento[10][19], int contador, int contadordos){//iniciamos la funcion con sus parametros
system("COLOR 12");//cambiamos el color para distinguir entre retirar y meter auto
int op,i,j,fila,columna;
printf("Que tipo de carro deseas retirar\n");// contamos con el menu para el tipo de carro
printf("1. Discapacitados\n 2. Carga\n 3. Sedan\n 4. Compacto\n 5. Moto\n 6. Vicicleta\n");
scanf("%d",&op);
switch(op){
///////////
case 1:
for (i=0;i<9;i++){// se imprimer la matriz
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}//Se le pide al usuario teclear la cordenada
printf("\n\n Los numero de los extremos son las cordenadas:");
printf("\n Teclea la fila en la que esta tu cajon\n");
scanf("%d",&fila);
printf("\n Teclea la columna en la que esta tu cajon\n");
scanf("%d",&columna);
estacionamiento[fila][columna]=("%c",68);// se vuelbe a dovlover el caracter original de la matriz
printf("\nEsta es la actualizacion del estacionamiento\n");
for (i=0;i<9;i++){// se imprime la matriz actualizada
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
///////////
case 2://Caso 2 y se repite los ajustes de los casos anteriores

for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
printf("\n\n Los numero de los extremos son las cordenadas:");
printf("\n Teclea la fila en la que esta tu cajon\n");
scanf("%d",&fila);
printf("\n Teclea la columna en la que esta tu cajon\n");
scanf("%d",&columna);
estacionamiento[fila][columna]=("%c",67);
printf("\nEsta es la actualizacion del estacionamiento\n");
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
///////////
case 3://Caso 3 y se repite los ajustes de los casos anteriores
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
//Llenado aleatorio

for (i=0;i<9;i++){ // <- imprecion
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
//////////
case 4://Caso 4 y se repite los ajustes de los casos anteriores
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
printf("\n\n Los numero de los extremos son las cordenadas:");
printf("\n Teclea la fila en la que esta tu cajon\n");
scanf("%d",&fila);
printf("\n Teclea la columna en la que esta tu cajon\n");
scanf("%d",&columna);
estacionamiento[fila][columna]=("%c",65);
printf("\nEsta es la actualizacion del estacionamiento\n");
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
////////
case 5://Caso 5 y se repite los ajustes de los casos anteriores
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
printf("\n\n Los numero de los extremos son las cordenadas:");
printf("\n Teclea la fila en la que esta tu cajon\n");
scanf("%d",&fila);
printf("\n Teclea la columna en la que esta tu cajon\n");
scanf("%d",&columna);
estacionamiento[fila][columna]=("%c",77);
printf("\nEsta es la actualizacion del estacionamiento\n");
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
//////////
case 6://Caso 6 y se repite los ajustes de los casos anteriores
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
printf("\n\n Los numero de los extremos son las cordenadas:");
printf("\n Teclea la fila en la que esta tu cajon\n");
scanf("%d",&fila);
printf("\n Teclea la columna en la que esta tu cajon\n");
scanf("%d",&columna);
estacionamiento[fila][columna]=("%c",86);
printf("\nEsta es la actualizacion del estacionamiento\n");
for (i=0;i<9;i++){
    for (j=0;j<18;j++){
    printf("[ %c ]",estacionamiento[i][j]);
    }
    printf("\n");
}
break;
default :
    printf("LO sentimos obcion invalida");
break;
}
principal(estacionamiento,contador,contadordos);// se llama a la funcion para continuar como un ciclo
}

void carga(){
    imprimir();
    int caso1;
    printf("munu carga");
    scanf("%d",&caso1);
    switch(caso1)
    {
    case 1:
    for(int i=9;i>=8;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i<=88;i++){
            Sleep(200); gotoxy(i,8); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,8); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 2:
    for(int i=9;i>=7;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,7); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,7); printf("%c",157);Color(BLACK,WHITE);

        break;
    case 3:
    for(int i=9;i>=6;i--){
            Sleep(200); gotoxy(75,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,6); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,6); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 4:
    for(int i=9;i>=5;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,5); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 5:
    for(int i=9;i>=4;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,4); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 6:
        for(int i=9;i>=4;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,4); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,4); printf("%c",157);Color(BLACK,WHITE);
        break;

    case 7:
        for(int i=9;i>=3;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=88;i++){
            Sleep(200); gotoxy(i,3); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,3); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 8:
        for(int i=9;i>=2;i--){
            Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=75;i<=87;i++){
            Sleep(200); gotoxy(i,2); printf("%c",157);
        }

        for(int i=2;i>=1;i--){
            Sleep(200); gotoxy(87,i); printf("%c",157);
        }
        for(int i=87;i<=88;i++){
            Sleep(200); gotoxy(i,1); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(88,1); printf("%c",157);Color(BLACK,WHITE);
        break;

        gotoxy(1,11); printf("\n");
    }
}

void discapacitado(){
    imprimir();
printf("\nmenu discapacitados\n");
    int dis;
    scanf("%d",&dis);
    switch(dis)
    {
    case 1:
        for(int i=9;i>=8;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=62;i--){
            Sleep(200); gotoxy(i,8); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(62,8); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 2:
        for(int i=9;i>=7;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=62;i--){
            Sleep(200); gotoxy(i,7); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(62,7); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 3:
        for(int i=9;i>=6;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=62;i--){
            Sleep(200); gotoxy(i,6); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(62,6); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 4:
        for(int i=9;i>=5;i--){ //arriba
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=57;i--){ //Izquiera
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        Sleep(200); gotoxy(57,6); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(57,6); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 5:
        for(int i=9;i>=5;i--){ //arriba
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=56;i--){ //Izquiera
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        for(int i=5;i<=7;i++){ //bajar
        Sleep(200); gotoxy(56,i); printf("%c",157);
        }
        Sleep(200); gotoxy(57,7); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(57,7); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 6:
        for(int i=9;i>=5;i--){ //arriba
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=56;i--){ //Izquiera
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        for(int i=5;i<=8;i++){ //bajar
        Sleep(200); gotoxy(56,i); printf("%c",157);
        }
        Sleep(200); gotoxy(57,8); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(57,8); printf("%c",157);Color(BLACK,WHITE);
        break;
    }
    gotoxy(1,11); printf("\n");
}

void autoa(){
    imprimir();
    int caso1,i;
    printf("Compacto");
    scanf("%d",&caso1);
    switch(caso1)
    {
case 1:
for( i=9;i>=3;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
for(i=74;i<=81;i++){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(81,i); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(81,1); printf("%c",157);Color(BLACK,WHITE);
    break;
case 2:

for( i=9;i>=3;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
for(i=74;i<=76;i++){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(76,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(76,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 3:
for( i=9;i>=3;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
for(i=74;i>=71;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(71,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(71,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 4:
    for( i=9;i>=3;i--){
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
for(i=74;i>=66;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(66,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(66,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 5:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=61;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(61,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(61,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 6:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=56;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(56,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(56,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 7:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=51;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(51,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(51,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 8:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=46;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(46,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(46,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 9:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=41;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(41,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(41,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 10:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=36;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(36,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(36,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 11:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=31;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(31,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(31,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 12:
    for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=26;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(26,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(26,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 13:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=21;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(21,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(21,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 14:
    for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=16;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(16,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(16,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 15:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=11;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(11,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(11,1); printf("%c",157);Color(BLACK,WHITE);
    break;

case 16:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=6;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i>=1;i--){
        Sleep(200); gotoxy(6,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(6,1); printf("%c",157);Color(BLACK,WHITE);
    break;
    }
    gotoxy(1,11); printf("\n");
}

void moto(){
    imprimir();
    int cmot;
    printf("munu moto");
    scanf("%d",&cmot);
    switch(cmot)
    {
    case 1:
        for(int i=9;i>=5;i--){//sube
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=33;i--){ //izquierda
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        Color(BLACK,RED);Sleep(200); gotoxy(33,5); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 2:
        for(int i=9;i>=5;i--){ //sube
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=35;i--){//izquierda
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        for(int i=5;i<=6;i++){//baja
            Sleep(200); gotoxy(35,i); printf("%c",157);
        }
        Sleep(200); gotoxy(34,6); printf("%c",157); //pocicion
        Sleep(200); gotoxy(33,6); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(33,6); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 3:
        for(int i=9;i>=5;i--){//sube
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=35;i--){//izquierda
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        for(int i=5;i<=7;i++){//baja
            Sleep(200); gotoxy(35,i); printf("%c",157);
        }
        Sleep(200); gotoxy(34,7); printf("%c",157);
        Sleep(200); gotoxy(33,7); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(33,7); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 4:
        for(int i=9;i>=5;i--){//sube
        Sleep(200); gotoxy(74,i); printf("%c",157);
        }
        for(int i=74;i>=35;i--){//izquierda
            Sleep(200); gotoxy(i,5); printf("%c",157);
        }
        for(int i=5;i<=8;i++){//baja
            Sleep(200); gotoxy(35,i); printf("%c",157);
        }
        Sleep(200); gotoxy(34,8); printf("%c",157);
        Sleep(200); gotoxy(33,8); printf("%c",157);
        Color(BLACK,RED);Sleep(200); gotoxy(33,8); printf("%c",157);Color(BLACK,WHITE);
        break;

    }
    gotoxy(1,11); printf("\n");
}

void suv(){
    imprimir();
    int ops,i;
    scanf("%d",&ops);
    switch(ops)
    {
    case 1:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=31;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(31,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(31,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 2:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=26;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(26,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(26,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 3:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=21;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(21,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(21,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 4:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=16;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(16,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(16,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 5:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=11;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(11,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(11,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 6:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=6;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for( i=3;i<=4;i++){
    Sleep(200); gotoxy(6,i); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(6,4); printf("%c",157);Color(BLACK,WHITE);
        break;
    }
gotoxy(1,11); printf("\n");
}

void vici(){
    imprimir();
    int i,pov;
    scanf("%d",&pov);
    switch(pov)
    {
    case 1:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=1;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(1,3); printf("%c",157);Color(BLACK,WHITE);
        break;
    case 2:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=3;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for(i=3;i>=1;i--){
 Sleep(200); gotoxy(i,4); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(1,4); printf("%c",157);Color(BLACK,WHITE);

        break;
    case 3:
for( i=9;i>=3;i--){
    Sleep(200); gotoxy(74,i); printf("%c",157);
    }
for(i=74;i>=3;i--){
    Sleep(200); gotoxy(i,3); printf("%c",157);
}
for(i=3;i>=1;i--){
 Sleep(200); gotoxy(i,2); printf("%c",157);
}
Color(BLACK,RED);Sleep(200); gotoxy(1,2); printf("%c",157);Color(BLACK,WHITE);
        break;
    }

   gotoxy(1,11); printf("\n");
}

void lugar(int op){
    int caso;
    //El caso es el numero random
    printf("Menu -lugar-");
    caso=op;
    switch(caso)
    {

case 1:
    discapacitado();
    break;
case 2:
    carga();
    break;
case 3:
    suv();
    break;
case 4:
    autoa();
    break;
case 5:
    moto();
    break;

case 6:
    vici();
    break;
    }
}

void imprimir(){
    int i,c=6,c1=6;

    for (i=0;i<90;i++){
        if(i>=6 && c<=85){
            gotoxy(c,1); printf("%c",65); //A
            c+=5;
        }

     gotoxy(i,0); printf("%c",220);
    }

    for(i=0;i<10;i++){ //Derecha
            if(i>=1 && i <=10){
               gotoxy(88,i); printf("%c",67);//C
            }
        if(i==0){
            gotoxy(90,i); printf("%c",220);
        }else{
            gotoxy(90,i); printf("%c",219);
            }
        }
    for(i=0;i<5;i++){ //izquierda
            if(i>=2 && i<=4){
               gotoxy(1,i); printf("%c",86);//V
            }
         if(i==0){
            gotoxy(0,i); printf("%c",220);
         }else{
            gotoxy(0,i); printf("%c",219);
         }
    }

    for(i=0;i<31;i++){ //izquierda acostada
            if(i>=6 && c1<= 35){
                gotoxy(c1,4); printf("%c",83);//S
                c1+=5;
            }

         if(i==0){
             gotoxy(i,5); printf("%c",219);
         }else{
              gotoxy(i,5); printf("%c",220);
         }
     }

    for(i=6;i<10;i++){ //izquierda levantada
            gotoxy(33,5); printf("%c",77); //M
            if(i>=5 && i<=10){
                 gotoxy(33,i); printf("%c",77); //M
            }

        if(i==6){
             gotoxy(30,i); printf("%c",219);
        }else{
             gotoxy(30,i); printf("%c",219);
        }
    }
         gotoxy(57,6); printf("%c",68);//D
         gotoxy(62,6); printf("%c",68);//D
         gotoxy(57,7); printf("%c",68);//D
         gotoxy(62,7); printf("%c",68);//D
         gotoxy(57,8); printf("%c",68);//D
         gotoxy(62,8); printf("%c",68);// D

    for(i=31;i<90;i++){ //abajo


        if(i>=41 && i <=48){
            gotoxy(i,9); printf(" ");
        }else{
            gotoxy(i,9); printf("%c",220);
        }
        if(i>=70 && i <=78){
            gotoxy(i,9); printf(" ");
        }
    }
}

void gotoxy(int x, int y){
   HANDLE manipulador;
   COORD   cordenada;
   manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
   cordenada.X = x;
   cordenada.Y = y;
   SetConsoleCursorPosition(manipulador,cordenada);
}

void Color(int Background, int Text){

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
 int    New_Color= Text + (Background * 16);
 SetConsoleTextAttribute(Console, New_Color);
}
