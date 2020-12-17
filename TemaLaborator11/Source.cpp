#include<iostream>
#include<vector>
#include<iterator>
#include<math.h>
using namespace std;


class Punct {
    int x;
    int y;

public:
    Punct():x(),y(){}
    Punct(int a, int b) :x(a), y(b) {}

    int getX() { return x; }
    void setX(int value) { x = value; }

    int getY() { return y; }
    void setY(int value) { y = value; }

    void afisare()
    {
        cout << "(" << x << "," << y << ")  ";
    }
};



class Figura {
public:
    vector<Punct> puncte;
    virtual float perimetru() = 0;

    float muchie(Punct p1, Punct p2) {
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }

    void adaugaPunct(int x, int y) {
        Punct p(x,y);
        puncte.push_back(p);
        
    }

    template<typename T>
    T pantaDreptei()
    {
       
        return (puncte[1].getY() - puncte[0].getY()) / (puncte[1].getX() - puncte[0].getY());

    }

   vector<Punct> getPuncte() {
        return puncte;
    }

   void afisare_Puncte() {
       cout << endl;
       for (int i = 0; i < puncte.size(); i++)
       {
           puncte[i].afisare();
          
       }
   }

};
class Dreptunghi : public Figura {

public:
    float a;
    float b;
    float perimetru_val = 0;
    Dreptunghi() :a(0), b(0) {}

    float perimetru() {
        a = muchie(puncte[0], puncte[1]);
        b = muchie(puncte[1], puncte[2]);
        perimetru_val = 2 * (a + b);
        return perimetru_val;
    }
};


class Triunghi : public Figura {
public:
    float a;
    float b;
    float c;
    float perimetru_val = 0;
    Triunghi() :a(0), b(0), c(0) {};
    float perimetru() {
   
        a = muchie(puncte[0], puncte[1]);
        b = muchie(puncte[1], puncte[2]);
        c = muchie(puncte[2], puncte[3]);
        perimetru_val = a + b + c;
        return perimetru_val;
    }
    
};

class Pentagon : public Figura {
public:
    float a;
    float b;
    float c;
    float d;
    float e;
    float perimetru_val = 0;
    Pentagon() :a(0), b(0), c(0),d(0),e(0) {};
    float perimetru() {
      
        a = muchie(puncte[0], puncte[1]);
        b = muchie(puncte[1], puncte[2]);
        c = muchie(puncte[2], puncte[3]);
        d = muchie(puncte[3], puncte[4]);
        e = muchie(puncte[4], puncte[5]);
        perimetru_val = a + b + c + d + e;
        return perimetru_val;
    }
};


class Cerc {
    Punct centru;
    int raza;
    static Cerc* instance;
    Cerc():centru(),raza() { }
    Cerc(Punct elem, int raza):centru(elem),raza(raza) {
    }
public:
    static Cerc* getInstance(Punct elem, int raza) {
        try {
            if (instance == NULL)
                instance = new Cerc(elem, raza);
            else {
                throw "Cercul este deja creat";
            }
            return instance;
        }

        catch (const char* elem) {
            cout << elem ;
        }
    }
    static void destroy() {
        if (instance != NULL)
            delete(instance);
        instance = NULL;
    }

    template<typename T>
    void verificaCerc(T elem) {
        int aux = 0;
        bool check = true;
        vector<Punct> puncte = elem.getPuncte();
        for (int i = 0; i < puncte.size(); i++)
        {
            aux = pow(puncte[i].getX() - centru.getX(), 2) + pow(puncte[i].getY() - centru.getY(), 2);
            if (aux != pow(raza, 2))
            {
                check = false;
            }
        }
      
        if (check == false)
        {
            cout << "\nFigura nu apartine cercului";
        }
        else {

            cout<<"\nFigura apartine cercului";
        }

    }

};

Cerc* Cerc::instance = NULL;

int main()
{
    Triunghi t;
    Dreptunghi d;
    Pentagon p;
    Cerc* c;
    int alegere,ok=0;
    int x;
    int y;
    bool loop = true;
    float perimetru = 0;

    while (loop)
    {
        cout << "\nAlegeti forma:" ;
        cout << "\n1.Adaugati triunghi";
        cout << "\n2.Adaugati Dreptunghi";
        cout << "\n3.Adaugati Pentagon";
        cout << "\n4.Cerc si verifica daca e una din forme pe el" ;
        cout << "\n5.Afisati triunghi";
        cout << "\n6.Afisati Dreptunghi";
        cout << "\n7.Afisati Pentagon";
        cout << "\n8.Afisati panta triunghi";
        cout << "\n9.Afisati panta Dreptunghi";
        cout << "\n10.Afisati panta Pentagon";
        cout << "\n0.Exit" <<endl;
        cin >> alegere;
        switch (alegere) 
        {
        case 1:
            if (t.puncte.size() == 0)
            {
                cout << "\nDati coordonatele celor 3 puncte\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << "x=";
                    cin >> x;
                    cout << "y=";
                    cin >> y;
                    t.adaugaPunct(x, y);
                }
            }
            else cout << "\nUn triunghi a fost deja adaugat.";
            break;
      
        case 2:
            if (d.puncte.size() == 0)
            {
                cout << "\nDati coordonatele celor 3 puncte\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << "x=";
                    cin >> x;
                    cout << "y=";
                    cin >> y;
                    d.adaugaPunct(x, y);
                }
            }else cout << "\nUn dreptunghi a fost deja adaugat.";

          break;
        
        case 3:
            if (p.puncte.size() == 0)
            {
                cout << "\nDati coordonatele celor 5 puncte\n";
                for (int i = 0; i < 5; i++)
                {
                    cout << "x=";
                    cin >> x;
                    cout << "y=";
                    cin >> y;
                    p.adaugaPunct(x, y);
                }
            }else cout << "\nUn pentagon a fost deja adaugat;";

            break;
        
        case 5:
            t.afisare_Puncte();
            perimetru=t.perimetru();
            cout << "Perimetrul este: " << perimetru;
            break;
        case 6:
            d.afisare_Puncte();
            perimetru = d.perimetru();
            cout << "Perimetrul este: " << perimetru;
            break;
        case 7:
            p.afisare_Puncte();
            perimetru = p.perimetru();
            cout << "Perimetrul este: " << perimetru;
            break;
        case 8:
            cout << "Panta dreptei este: " << t.pantaDreptei<float>();
    
            break;
        case 9:
            cout << "Panta dreptei este: " << d.pantaDreptei<float>();
            break;
        case 10:
            cout << "Panta dreptei este: " << p.pantaDreptei<float>();
            break;
      
        case 4:
            int r;
            cout << "\nCoordonatele centrului cercului:\n";
            cout << "x=";
            cin >> x;
            cout << "y=";
            cin >> y;
            cout << "\n cercului: \n";
            cin >> r;
            Punct* cerc = new Punct(x, y);
            c = Cerc::getInstance(*cerc, r);
            
            cout << "\nTriunghi: ";
            c->verificaCerc<Triunghi>(t);
            cout << "\nDreptunghi: ";
            c->verificaCerc<Dreptunghi>(d);
            cout << "\nPentagon: ";
            c->verificaCerc<Pentagon>(p);
            break;


        }


    }

    return 0;
}
