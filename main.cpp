//
//  main.cpp
//  MasterMind
//
//  Created by Luca Savant on 23/03/15.
//  Copyright (c) 2015 LucaNet. All rights reserved.
//
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#define NUM 4

/*
 for(int i=0; i < NUM; i++)
 {
 array_computer[i] = rand() % 9 +1;
 }
 */

int Compara(int array_umano[], int array_computer[], float count){
    //controlla
    for(int a=0; a < NUM; a++)
    {
        if (array_computer[a]!=array_umano[a]) {
            for(int i=0; i < NUM; i++)
            {
                for(int j=0; j < NUM; j++)
                {
                    if ((array_computer[i]==array_umano[j])&(i==j)) {
                        cout << "    Indizio: c'è un numero giusto al posto giusto."<<endl;
                    }
                    else if ((array_computer[i]==array_umano[j])&(i!=j)){
                        cout << "    Indizio: c'è un numero gisto al posto sbalgiato."<<endl;
                    }
                }
            }
            break;
        }
        if (a==3) {
            cout<<  "Hai vinto dopo "<<count<<" giri!"<<endl;
            
            exit(0);
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    //counter giri
    float count=0;
    //numeri inseribili max e min
    int min=0;
    int max=0;
    for (int i=0; i<NUM; i++){
        min=min+1*(pow(10, i));
        max=max+9*(pow(10, i));
    }
    /* initialize random seed: */
    srand (time(NULL));
    //impagino
    cout <<  "/$$                 /$$                 /$$      /$$ /$$                 /$$"<<endl<<
            "| $$                | $$                | $$$    /$$$|__/                | $$"<<endl<<
            "| $$       /$$   /$$| $$   /$$ /$$   /$$| $$$$  /$$$$ /$$ /$$$$$$$   /$$$$$$$"<<endl<<
            "| $$      | $$  | $$| $$  /$$/| $$  | $$| $$ $$/$$ $$| $$| $$__  $$ /$$__  $$"<<endl<<
            "| $$      | $$  | $$| $$$$$$/ | $$  | $$| $$  $$$| $$| $$| $$  \\ $$| $$  | $$"<<endl<<
            "| $$      | $$  | $$| $$_  $$ | $$  | $$| $$\\  $ | $$| $$| $$  | $$| $$  | $$"<<endl<<
            "| $$$$$$$$|  $$$$$$/| $$ \\  $$|  $$$$$$$| $$ \\/  | $$| $$| $$  | $$|  $$$$$$$"<<endl<<
            "|________/ \\______/ |__/  \\__/ \\____  $$|__/     |__/|__/|__/  |__/ \\_______/"<<endl<<
            "                               /$$  | $$"<<endl<<
            "                              |  $$$$$$/"<<endl<<
            "                               \\______/"<<endl;
    cout <<endl<< "Nuova Partita. Sei pronto?"<<endl;
    cout << "Ho pensato a "<<NUM<<" numeri da 1 a 9. Prova ad indovinarli."<<endl;
    //dichiaro array
    int array_computer[NUM];
    int array_umano[NUM];
    //assegno valore casuali all'array del computer
    for(int i=0; i < NUM; i++)
    {
        array_computer[i] = rand() % 9 +1;
    }
start:
    //chiedi mosse all'umano
    long int prova;
    //controlla l'input
    int error;
    do
    {
        error = 0;
        count=count+1;
        cout << count<<"° giro. Inserisci i "<<NUM<<" numeri: ";
        cin >> prova;
        if (prova==-1){
            //baro-----------------------------baro
            cout<<endl;
            for(int i=0; i < NUM; i++)
            {
                cout << array_computer[i];
            }
            cout<<endl;
            //baro-----------------------------baro ;)
            goto start;
        }
        if (cin.fail()|(prova<min)|(prova>max))
        {
            cout << "Numero non valido!" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
    }while(error == 1);

    for(int i=NUM-1; i>=0; i--)
    {
        int digit = prova%10;
        prova /= 10;
        array_umano[i]=digit;
    }
    Compara(array_umano,array_computer,count);
    cout << endl <<"Basandoti sugli indizi ricevuti, riprova ad indovinare la sequenza."<<endl;
    
    goto start;
}
