#include<iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class bitset
{
private:
    unsigned char v[10];
    unsigned int n=0;

public:
    bitset();                           //constructor, initializeaza cu 0
    void set();                         //seteaza toti bitii la 1
    void set(unsigned int pos);         //seteaza bitul de la pozitia pos
    void clear();                       //stergere toti bitii
    void clear(unsigned int pos);        //sterge bitul de la pozitia pos
    bool contains(unsigned int pos);    //verifica daca un elem apartine multimii
    void toString();                    //afisare a multimii
};

bitset::bitset()
{
    int b;  //numarul de biti
    n=1;   //numarul de caractere

    for (int i=0; i<10; i++)
    {
        v[i] = 0b00000000;
    }
}

void bitset::set()
{
    for (int i=0; i<n; i++)
    {
        v[i] = 0b11111111;
    }
}

void bitset::set(unsigned int pos)
{
    int carMax;
    do
    {
        if (pos>=0 && pos<80)
        {
            //in al catelea caracter pica?

            carMax=(pos/8) + 1;

            // n<caracater? => update;
            if (n<carMax)
            {
                n=carMax;
            }

            v[carMax-1] |= ( 0b00000001 << (pos%8) );
        }
    }
    while (pos<0 || pos>79);

}

void bitset::clear()
{
    for(int i=0; i<n; i++)
    {
        v[i] = 0b00000000;
    }
}

void bitset::clear(unsigned int pos)
{
    int carMax;
    do
    {
        if (pos>=0 && pos<80)
        {
            //in al catelea caracter pica?

            carMax=(pos/8) + 1;

            // n<caracater? => update;
            if (n<carMax)
            {
                n=carMax;
            }

            v[carMax-1] &= ~( 0b00000001 << (pos%8) );
        }
    }
    while (pos<0 || pos>79);
}

bool bitset::contains(unsigned int pos)
{
    char dummy;
    dummy=v[pos/8];

    dummy >>= (pos%8);
    dummy &= 0b00000001;

    return dummy;
}

void bitset::toString()
{
    int maxCharNo;
    unsigned short bit;
    char sir[9];
    char sirMare[91] = "";

    maxCharNo = n - 1;

    for (int charNo = maxCharNo; charNo >= 0; charNo--)
    {
        for (int bitNo = 7; bitNo >= 0; bitNo--)
        {
            bit = v[charNo] >> bitNo;
            bit = bit & 0b00000001;

            itoa(bit, sir, 2);
            strcat(sirMare, sir);
        }
        strcat(sirMare, " ");
    }

    cout<< sirMare;
}

int main (void)
{
    bitset x;
    int m;
    char c;

    do
    {
        cout<<endl<<"Doriti sa setati un bit (s - set), sa stergeti un bit (c - clear) sau sa parasiti programul (e - exit)?"<<endl;
        cin>>c;

        if(c=='s')
        {
            cout<<"Introduceti numarul bitului pe care doriti sa il setati sau numarul 99 daca doriti sa setati toti bitii"<<endl;
            cin>>m;

            if(m>=0 && m<80)
            {
                if(x.contains(m))
                {
                    cout<<"Acest bit este deja setat"<<endl;
                }
                else
                {
                    x.set(m);
                    x.toString();
                    cout<<endl;
                }
            }
            else if (m==99)
            {
                x.set();
                x.toString();
                cout<<endl;
            }
            else
                cout<<"Trebuie sa introduceti un numar intre 0 si 79!!!"<<endl;
        }

        else if (c=='c')
        {
            cout<<"Introduceti numarul bitului pe care doriti sa il stergeti sau numarul 99 daca doriti sa stergeti toti bitii"<<endl;
            cin>>m;

            if(m>=0 && m<80)
            {
                if(x.contains(m)==0)
                {
                    cout<<"Acest bit este deja sters"<<endl;
                }
                else
                {
                    x.clear(m);
                    x.toString();
                    cout<<endl;
                }
            }
            else if (m==99)
            {
                x.clear();
                x.toString();
                cout<<endl;
            }
            else
                cout<<"Trebuie sa introduceti un numar intre 0 si 79!!!"<<endl;
        }


    }
    while (c !='e');

}




