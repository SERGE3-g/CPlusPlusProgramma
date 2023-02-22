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

using namespace std;

void funzioneDue()
{

    ifstream fileInput("maggio.txt"); // apertura file in lettura
    // ofstream fileOutput("output.txt"); // apertura file in scrittura

    // variabili
    string paragrafo = "";
    string riga;
    string parola = "polvere";
    int numeroRiga = 0;
    int trovato;

    while (getline(fileInput, riga))
    {
        numeroRiga++;
        if (riga != "")
        {
            paragrafo += to_string(numeroRiga) + " - " + riga + "\n";
        }
        else
        {
            paragrafo = "";
        }

        bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
        for (int i = 0; i < riga.length(); i++) // for tutta riga
        {

            for (int j = 0; j < parola.length(); j++) // for tutta parola
            {

                if (riga[i] == parola[j]) // se le lettere sono uguali
                {
                    if (j == parola.length() - 1 && ((riga[i + 1] == ' ') || (riga[i + 1] == '.') || (riga[i + 1] == ',') || (riga[i + 1] == '\n'))) // se le lettere sono uguali E sono all'ultima lettera della parola
                    {
                        flag = true; // PAROLA TROVATA

                        trovato = numeroRiga;
                        cout << paragrafo;
                        while (getline(fileInput, riga))
                        {
                            numeroRiga++;
                            if (riga == "")
                            {
                                break;
                            }
                            else
                            {
                                cout << numeroRiga << " - " << riga << endl;
                            }

                            cout << endl;
                        }
                    }
                    i++;
                }
                else
                {
                    break;
                }
            }
        }

        if (flag == true)
        {
            cout << "PAROLA TROVATA IN RIGA: " << trovato << endl;
        }
    }
    fileInput.close();
}

int main()
{

    cout << "quest'app puo' fare questo: " << endl;
    cout << "1) trovare le righe contenenti la parola data" << endl;
    cout << "2) trovare le righe contenenti la parola data e stampare il paragrafo" << endl;
    cout << "3) fare un'analisi del paragrafo in cui la parola e' stata trovata (quanti spazi, quante parole, quanti simboli, quanti caratteri per ogni riga)" << endl;
    cout << "4) stampa solo le righe pari" << endl;
    cout << "0) EXIT" << endl;

    int telecomando;

    do
    {
        cin >> telecomando;

        switch (telecomando)
        {
            case 1:
                cout << "trova le righe contenenti la parola data" << endl;
                break;
            case 2:
                cout << "trova le righe contenenti la parola data e stampa il paragrafo" << endl;
                funzioneDue();
                break;
            case 3:
                cout << "fai un'analisi del paragrafo in cui la parola è stata trovata" << endl;
                break;
            case 4:
                cout << "stampa solo le righe pari" << endl;
                break;
            case 0:
                cout << "EXIT" << endl;
                break;
        }
    } while (telecomando != 0);

    return 0;
}
