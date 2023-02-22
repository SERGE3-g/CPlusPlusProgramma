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

// provo un altro metodo che mi stampa tutto il testo
int main()
{
    ifstream fileInput("testi/maggio.txt");  // apertura file in lettura
    if (fileInput.is_open()) {
        string line;
        while (getline(fileInput, line)) {
            cout << line << endl;
        }
        fileInput.close();
    }
    string riga;
    string parola ="immobile";
    string paragrafo="1";

    int numeroRigaParolaTrovata = 0;

    // ho provato questo metodo che mi stampa il paragrafo della parola cercata

    /*while (getline(fileInput, riga)) {
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
    return 0;*/

    while(paragrafo!= "16")

        paragrafo += riga + "\n";
    cout << "Riga: " << numeroRigaParolaTrovata << " " << riga << endl;;

    while (getline(fileInput, riga)) {
        {
            paragrafo += riga + "\n";
            cout << "Riga: " << numeroRigaParolaTrovata << " " << riga << endl;
            bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {

                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {

                    if  (riga[i] == parola[j])// se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                        {
                            flag = true;
                        }
                        i++;
                    }
                    {
                        break;
                    }
                }
                if (flag)
                    break;
            }

            if (flag)

            {
                cout << "PAROLA TROVATA IN RIGA: " << numeroRigaParolaTrovata << " - " << riga << endl;
            }
        }
        fileInput.close();
    }
}
