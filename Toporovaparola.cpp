//
// Created by gueas on 22/02/2023.
//


/*
 *
 * Scrivere un programma che rimane aperto finchÃ© l'utente non digita EXIT.
 *Il programma chiede all'utente una parola da cercare nel 5 Maggio
 *Restituisce a schermo:
 *i versetti con i numeri di riga in cui appare la parola cercata
 *Chiede la successiva parola a meno che non si inserisce EXIT
 *
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileInput("testi/maggio.txt");  // apertura file in lettura

    string riga;
    string parola ="immobile";
    string paragrafo="1";

    int numeroRigaParolaTrovata = 0;

    while (getline(fileInput, riga)) {
        numeroRigaParolaTrovata++;
        paragrafo += riga + "\n";
        cout << "Riga: " << numeroRigaParolaTrovata << " " << riga << endl;
        if (numeroRigaParolaTrovata == 5) {
            paragrafo += riga + "\n";
            cout << "Riga: " << numeroRigaParolaTrovata << " " << riga << endl;
            break;
        }
        else {
            paragrafo += riga + "\n";
            cout << "Riga: " << numeroRigaParolaTrovata << " " << riga << endl;
        }
        riga = paragrafo;
    }
    fileInput.close();
    return 0;
}