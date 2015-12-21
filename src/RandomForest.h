#ifndef RandomForest_H_
#define RandomForest_H_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Registro
{
    string anio;
    string mes;
    string horario;
    string semana;
    string dia;
    string distrito;
    string resolucion;
    string CATEGORIA;
    Registro(string _anio, string _mes, string _horario, string _semana, string _dia, string _distrito, string _resolucion, string _categoria)
    :anio(_anio), mes(_mes), horario(_horario), semana(_semana), dia(_dia), distrito(_distrito), resolucion(_resolucion), CATEGORIA(_categoria){};
};

struct RegistroArbol
{
    string abuelo;
    string padre;
    string campo;
    string clase;
    string probabilidad;
    RegistroArbol(string _abuelo, string _padre, string _campo, string _clase, string _probabilidad)
    :abuelo(_abuelo), padre(_padre), campo(_campo), clase(_clase), probabilidad(_probabilidad){};
};

struct Elegible
{
    int campo;
    string valor;
    Elegible(int _campo, string _valor):campo(_campo), valor(_valor){};
};

struct CategoriaProbabilidad
{
    string categoria;
    float probabilidad;
    int cant_datos;
    CategoriaProbabilidad(string _categoria, float _probabilidad, int _cant_datos):categoria(_categoria), probabilidad(_probabilidad), cant_datos(_cant_datos){};
};

struct TodosArboles
{
    int campo1;
    int campo2;
    int campo3;
    vector<RegistroArbol> vcArbol;
    TodosArboles(int _campo1, int _campo2, int _campo3, vector<RegistroArbol> _vcArbol):campo1(_campo1), campo2(_campo2), campo3(_campo3), vcArbol(_vcArbol){};
};

struct RegistroTest
{
    string id;
    string anio;
    string mes;
    string horario;
    string semana;
    string dia;
    string distrito;
    RegistroTest(string _id, string _anio, string _mes, string _horario, string _semana, string _dia, string _distrito)
    :id(_id), anio(_anio), mes(_mes), horario(_horario), semana(_semana), dia(_dia), distrito(_distrito){};
};

struct RegistroCSV
{
    vector<string> vcCsvColumn;
    RegistroCSV(vector<string> _vcCsvColumn):vcCsvColumn(_vcCsvColumn){};
};

class RandomForest
{
private:
    //Entrenar
    FILE* f_registros;
    ofstream f_arbol;
    ifstream f_regs;
    float log2(float n);
    string prediccion;
    string accion;
    vector<Registro> vcRegistros;
    vector<Registro> vcRegistros_2;
    vector<string> vcCategorias;
    vector<string> ObtenerValoresPosibles(int _campo, vector<Registro> _registros);
    int cantidad_categorias;
    float CalcularEntropia(vector<Registro> _registros);
    void DecidirSplit(vector<Elegible> _camposElegibles, vector<Registro> _registros, string _padre, string _abuelo);
    int cant_registros;
    int cant_arboles;
    
    //Clasificar
    ifstream f_arboles_entrada;
    ifstream f_test_set;
    ofstream f_salida;
    vector<CategoriaProbabilidad> CargarCategorias();
    
public:
    RandomForest(int _cantRegistros, int _cantArboles);
    ~RandomForest();
    void ArmarArbol(string _ruta, string _rutaArbol);
    void Clasificar(string _rutaArboles, string _rutaSalida, string _rutaTestSet);
};

#endif /*RandomForest_H_*/
