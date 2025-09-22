#include <iostream>
using namespace std;

void print(string msg){
    cout << msg;
}

void printLine(string msg){
    cout << msg << endl;
}


string readLine(){
    string input = "";
    getline(cin, input);
    return input;
}

string player1 = "Jugador 1";
string player2 = "Jugador 2";

char player1Char = 'X';
char player2Char = 'O';

string tablero[3][3] = {
    {" ", " ", " "},
    {" ", " ", " "},
    {" ", " ", " "}
};
int fichasJugadas = 0;

bool gameOver = false;

void MostrarTablero(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            print(tablero[i][j]);
            if(j<2)
                print(" | ");
        }
        if(i<2)
        printLine("\n---------");
    }
}

bool JugadaValida(int fila, int columna){
    if(fila < 1 || fila > 3) return false;
    if(columna < 1 || columna > 3) return false;

    return  (tablero[fila - 1][columna - 1] == " ");
}

bool ComprobarFin(string jugador, char ficha){

    bool juegoTerminado = false;
    bool empate = fichasJugadas >= 9;

    for(int i = 0; i < 3; i++){
        if(tablero[i][i] == " ")
            continue;
        //vertical
        if(tablero[i][0] == tablero[i][1] && tablero[i][1]  == tablero[i][2])
        {
            juegoTerminado = true;
            break;
        }
        //horizontal
        if(tablero[0][i] == tablero[1][i] && tablero[1][i]  == tablero[2][i])
        {
            juegoTerminado = true;
            break;
        }
    }
    //diagonal izquierda arriba derecha abajo
    if(tablero[0][0] != " " && tablero[0][0] == tablero[1][1] && tablero[1][1]  == tablero[2][2])
    {
        juegoTerminado = true;
    }
    //diagonal izquierda abajo derecha arriba
    if(tablero[0][2] != " " && tablero[0][2] == tablero[1][1] && tablero[1][1]  == tablero[2][0])
    {
        juegoTerminado = true;
    }

    if(juegoTerminado){
        printLine("Ha ganado " + jugador + " (" + ficha + ")");
    }
    else if(empate){
        printLine("Juego empatado, ninguno gana");
    }
    return juegoTerminado || empate;
}

int main(){
    printLine("Bienvenido al Tic Tac Toe");

    string jugadorActual = player1;
    char fichaActual = player1Char;

    int fila = 0, columna = 0;

    while (!gameOver)
    {
        MostrarTablero();
        
        while(true){
            printLine("Elige la casilla en la que vas a jugar (fila columna)");
            print(jugadorActual + " (" + fichaActual + "): ");
            
            cin >> fila >> columna;

            if(JugadaValida(fila, columna))
                break;
            
            printLine("jugada invalida, Intenta jugar en otra casilla");
        }
        
        tablero[fila - 1][columna - 1] = fichaActual;

        fichasJugadas++;

        gameOver = ComprobarFin(jugadorActual, fichaActual);


        if(jugadorActual == player1){
            jugadorActual = player2;
            fichaActual = player2Char;
        }else{
             jugadorActual = player1;
            fichaActual = player1Char;
        }
    }

    printLine("Fin del juego");
    return 0;
}
