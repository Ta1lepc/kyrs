// gallows.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include<string>
#include<cstring>
#include <vector>
#include <cctype>
#include <fstream>
#include <random>
#include <ctime>

#include "gallows.h"

using namespace std;

bool test1(int ch) {
    if (ch != 1 && ch != 2) return false;
    return true;
}

bool test2(ifstream &dict) {
    if (!dict) {
        return false;
    } else {
        return true;
    }

}


bool GamePlay(char star[10], char word[10], int letter) {
    cout << "You can use EN uppercase letters" << endl;
    cout << "Enter letter:";
    char let;
    cin >> let;
    int a = 0;
    for (int i = 0; i <= strlen(word); i++) {
        if (word[i] == let) {
            star[i] = let;
            a++;
        }
        cout << star[i];
    }
    cout << endl;

    if (a != 0) return true;
    return false;
}


void PartyGame() {
    char star[10] = {0};
    char word[10];
    cout << "Enter your word (uppercase letters):" << endl;
    cin.ignore();
    cin.getline(word, 10);
    int letter = 0;
    for (int i = 0; i <= strlen(word); i++) {
        if (isalpha(word[i])) {
            star[i] = '*';
            letter++;
        }
    }

    system("cls");
    cout << "A word for guessing:" << endl;
    for (int i = 0; i <= strlen(star); i++) cout << star[i];
    cout << endl;
    cout << "You have 3 point of hp, good luck" << endl;
    int hp = 3;
    while (hp > 0) {
        //GamePlay(star, word, letter);
        bool status = GamePlay(star, word, letter);
        if (!status) {
            hp--;
            cout << "Oops, you mistake, you have -1 heatpoint" << endl << "You have: " << hp << " of hp" << endl;
        } else {
            cout << "Well played, you guessed one letter" << endl;
        }
        int check = 0;
        for (int i = 0; i < letter; i++) {
            if (word[i] == star[i]) check++;
        }
        if (check == letter) {
            cout << "You are win!!!!!" << endl;
            system("PAUSE");
        }


        if (hp == 0) {
            cout << "You are lose" << endl;
            system("PAUSE");
        }
    }
}


void SoloGame() {
    char star[10] = {0};
    string worde;
    int n = 0;
    ifstream dict("dictionary.txt");
    if (!test2(dict)) {
        cout << "Not corrective number" << endl;
        system("PAUSE");
    } else {
        while (!dict.eof()) {
            dict >> worde;
            n++;
        }
        dict.seekg(0, ios::beg);
        int random = rand() % n + 1;
        for (int i = 0; i < random; i++) {
            getline(dict, worde);
        }
        //cout << worde << endl;
        //char *word=strdup(worde);
        char word[10];
        strcpy(word, worde.c_str());
        int letter = 0;
        for (int i = 0; i <= strlen(word); i++) {
            if (isalpha(word[i])) {
                star[i] = '*';
                letter++;
            }
        }
        cout << "A word for guessing:" << endl;
        for (int i = 0; i <= strlen(star); i++) cout << star[i];
        cout << endl;
        cout << "You have 3 point of hp, good luck" << endl;
        int hp = 3;
        while (hp > 0) {
            //GamePlay(star, word, letter);
            bool status = GamePlay(star, word, letter);
            if (!status) {
                hp--;
                cout << "Oops, you mistake, you have -1 heatpoint" << endl << "You have: " << hp << " of hp" << endl;
            } else {
                cout << "Well played, you guessed one letter" << endl;
            }
            int check = 0;
            for (int i = 0; i < letter; i++) {
                if (word[i] == star[i]) check++;
            }
            if (check == letter) {
                cout << "You are win!!!!!" << endl;
                system("PAUSE");
            }


            if (hp == 0) {
                cout << "You are lose" << endl;
                system("PAUSE");
            }
        }
    }
}


void Start() {
    srand(time(NULL));
    cout << "Welcome to game" << endl << "Choose:" << endl << "1. duo game" << endl << "2. solo game" << endl;
    int choose;
    cin >> choose;
    if (!test1(choose)) {
        cout << "Not corrective number" << endl;
        system("PAUSE");
    } else {
        if (choose == 1) PartyGame();
        if (choose == 2) SoloGame();
    }
}

// turned off due to automatic calling by Gtest and
//  preventing test' execution
/*
int main() {
    Start();
}*/
