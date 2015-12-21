#include "RandomForest.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

RandomForest::RandomForest(int _cantRegistros, int _cantArboles)
{
    cant_registros = _cantRegistros;
    cant_arboles = _cantArboles;
}

RandomForest::~RandomForest()
{
    
}

float RandomForest::log2(float n)
{
    return (float)((float)log(n) / (float)log((float)2));
}

void RandomForest::DecidirSplit(vector<Elegible> _camposElegibles, vector<Registro> _registros, string _padre, string _abuelo)
{
    vector<string> vcValoresPosibles;
    vector<Elegible> vcNuevosElegibles = _camposElegibles;
    vector<Registro> _registrosCondicionados = _registros;
    int cant_registros_nodo = 0;
    int cant_registros_valor = 0;
    float probabilidad_nodo = 1;
    int campo_menor_entropia = 0;
    float entropia_campo = 100;
    float entropia_min = 100;
    
    for (vector<Elegible>::iterator k = _camposElegibles.begin(); k != _camposElegibles.end(); k++)
    {
        switch (k->campo)
        {
            case 0:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->anio != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 0;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 1:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->mes != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 1;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 2:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->horario != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 2;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 3:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->semana != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 3;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 4:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->dia != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 4;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 5:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->distrito != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 5;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            case 6:
                if (k->valor != "nulo")
                {
                    vector<Registro>::iterator i = _registrosCondicionados.begin();
                    while (i != _registrosCondicionados.end())
                    {
                        cant_registros_nodo++;
                        if (i->resolucion != k->valor)
                        {
                            cant_registros_valor++;
                            i = _registrosCondicionados.erase(i);
                        }
                        else
                            i++;
                    }
                }
                else
                {
                    if (cant_registros_nodo != 0)
                        probabilidad_nodo = (float)cant_registros_valor / (float)cant_registros_nodo;
                    entropia_campo = probabilidad_nodo * CalcularEntropia(_registrosCondicionados);
                    if (entropia_campo < entropia_min)
                    {
                        campo_menor_entropia = 6;
                        entropia_min = entropia_campo;
                    }
                }
                break;
            default:
                break;
        }
    }
    
    
    int cant_elegibles = 0;
    int cant_nulos = 0;
    float proba_clase = 0;
    int cant_registros_condicionados = 0;
    int cant_registros_clasificar = 0;
    string campo_clasificado;
    string valor_clasificado;
    string categoria_clase;
    vector<RegistroArbol> regArbolTemp;
    
    for (vector<Elegible>::iterator k = _camposElegibles.begin(); k != _camposElegibles.end(); k++)
    {
        cant_elegibles++;
        if(k->valor == "nulo")
            cant_nulos++;
    }
    
    vcValoresPosibles = ObtenerValoresPosibles(campo_menor_entropia, _registrosCondicionados);
    for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
    {
        cant_registros_condicionados = 0;
        cant_registros_clasificar = 0;
        regArbolTemp.clear();
        for (vector<Elegible>::iterator k = _camposElegibles.begin(); k != _camposElegibles.end(); k++)
        {
            if(cant_nulos != 1)
            {
                if (k->campo == campo_menor_entropia)
                {
                    k->valor = (*i).c_str();
                    DecidirSplit(_camposElegibles, _registrosCondicionados, k->valor, _padre);
                }
            }
            else
            {
                if(k->valor == "nulo")
                {
                    for (vector<string>::iterator ic = vcCategorias.begin(); ic != vcCategorias.end(); ic++)
                    {
                        cant_registros_condicionados = 0;
                        for (vector<Registro>::iterator ip = _registrosCondicionados.begin(); ip != _registrosCondicionados.end(); ip++)
                        {
                            //cant_registros_condicionados++;
                            categoria_clase = (*ic).c_str();
                            switch (k->campo)
                            {
                                case 0:
                                    if((ip->anio == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "anio";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 1:
                                    if((ip->mes == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "mes";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 2:
                                    if((ip->horario == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "horario";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 3:
                                    if((ip->semana == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "semana";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 4:
                                    if((ip->dia == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "dia";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 5:
                                    if((ip->distrito == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "distrito";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                case 6:
                                    if((ip->resolucion == (*i).c_str()) && (ip->CATEGORIA == (*ic).c_str()))
                                    {
                                        campo_clasificado = "resolucion";
                                        cant_registros_clasificar++;
                                        regArbolTemp.push_back(RegistroArbol(_abuelo.c_str(), _padre.c_str(), (*i).c_str(), categoria_clase.c_str(), ""));
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
        }
        
        //Calcula la probabilid de la clase
        if(cant_registros_clasificar > 0)
        {
            for (vector<RegistroArbol>::iterator ia = regArbolTemp.begin(); ia != regArbolTemp.end(); ia++)
            {
                //proba_clase = (float) cant_registros_clasificar / (float)cant_registros_condicionados;
                //f_arbol << campo_clasificado << "," << (*i).c_str() << "," << cant_elegibles - 1 << "," << _padre << "," << categoria_clase << "," << proba_clase << endl;
                proba_clase = (float)1 / (float)cant_registros_clasificar;
                f_arbol << ia->abuelo << "," << ia->padre << "," << ia->campo <<  "," << ia->clase << "," << proba_clase << endl;
            }
        }
    }
}

float RandomForest::CalcularEntropia(vector<Registro> _registros)
{
    float entropia = 0;
    int registros_categoria = 0;
    
    for (vector<string>::iterator j = vcCategorias.begin(); j != vcCategorias.end(); j++)
    {
        registros_categoria = 0;
        for (vector<Registro>::iterator i = _registros.begin(); i != _registros.end(); i++)
        {
            if (i->CATEGORIA == (*j).c_str())
            {
                registros_categoria++;
            }
        }
        if ((registros_categoria != 0) && (cant_registros != 0))
            entropia += ((float)registros_categoria / (float)cant_registros) * log2((float)registros_categoria / (float)cant_registros);
    }
    entropia *= -1;
    
    return entropia;
}

void RandomForest::ArmarArbol(string _ruta, string _rutaArbol)
{
    f_arbol.open(_rutaArbol.c_str(), ofstream::out);
    f_regs.open(_ruta.c_str(), ifstream::in);
    
    int rnd_attrib_1 = -1;
    int rnd_attrib_2 = -1;
    int rnd_attrib_3 = -1;
    
    string anio;
    string mes;
    string horario;
    string semana;
    string dia;
    string distrito;
    string resolucion;
    string categoria;
    
    bool existe_categoria = false;
    
    string csvLine;
    
    //Leo los datos desde el archivo
    while( std::getline(f_regs, csvLine) )
    {
        istringstream csvStream(csvLine);
        vector<std::string> csvColumn;
        string csvElement;
        while( std::getline(csvStream, csvElement, ',') )
        {
            csvColumn.push_back(csvElement);
        }
        anio = csvColumn[0];
        mes = csvColumn[1];
        horario = csvColumn[2];
        semana = csvColumn[3];
        dia = csvColumn[4];
        distrito = csvColumn[5];
        resolucion = csvColumn[6];
        categoria = csvColumn[7];
        
        existe_categoria = false;
        
        //Veo si la categor\EDa ya existe dentro de los registros, sino, sumo uno a la cantidad
        for (vector<Registro>::iterator i = vcRegistros.begin(); i != vcRegistros.end(); i++)
        {
            if (i->CATEGORIA == categoria.c_str())
                existe_categoria = true;
        }
        
        if (!existe_categoria)
        {
            cantidad_categorias++;
            vcCategorias.push_back(categoria.c_str());
        }
        
        //Agrego el dato al vector
        vcRegistros.push_back(Registro(anio.c_str(), mes.c_str(), horario.c_str(), semana.c_str(), dia.c_str(), distrito.c_str(), resolucion.c_str(), categoria.c_str()));
    }
    
    //Tomo solo 3 atributos random de los 6 totales - Correccion, saco resolucion
    rnd_attrib_1 = rand() % 6;
    rnd_attrib_2 = rand() % 6;
    rnd_attrib_3 = rand() % 6;
    
    while(rnd_attrib_2 == rnd_attrib_1)
    {
        rnd_attrib_2 = rand() % 6;
    }
    
    while((rnd_attrib_3 == rnd_attrib_1) || (rnd_attrib_3 == rnd_attrib_2))
    {
        rnd_attrib_3 = rand() % 6;
    }
    
    //En la primera l\EDnea, guardo los atributos del arbol
    f_arbol << rnd_attrib_1 << "," << rnd_attrib_2 << "," << rnd_attrib_3 << endl;
    
    vector<Elegible> elegibles_inciales;
    elegibles_inciales.push_back(Elegible(rnd_attrib_1, "nulo"));
    elegibles_inciales.push_back(Elegible(rnd_attrib_2, "nulo"));
    elegibles_inciales.push_back(Elegible(rnd_attrib_3, "nulo"));
    
    //Primer split
    DecidirSplit(elegibles_inciales, vcRegistros, "nulo", "nulo");
    
    f_arbol.close();
    f_regs.close();
}

vector<string> RandomForest::ObtenerValoresPosibles(int _campo, vector<Registro> _registros)
{
    vector<string> vcValoresPosibles;
    bool existe_valor = false;
    
    switch (_campo)
    {
        case 0:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->anio == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->anio);
            }
            break;
        case 1:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->mes == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->mes);
            }
            break;
        case 2:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->horario == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->horario);
            }
            break;
        case 3:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->semana == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->semana);
            }
            break;
        case 4:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->dia == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->dia);
            }
            break;
        case 5:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->distrito == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->distrito);
            }
            break;
        case 6:
            for (vector<Registro>::iterator j = _registros.begin(); j != _registros.end(); j++)
            {
                existe_valor = false;
                for (vector<string>::iterator i = vcValoresPosibles.begin(); i != vcValoresPosibles.end(); i++)
                {
                    if (j->resolucion == (*i).c_str())
                    {
                        existe_valor = true;
                    }
                }
                if (!existe_valor)
                    vcValoresPosibles.push_back(j->resolucion);
            }
            break;
        default:
            break;
    }
    
    return vcValoresPosibles;
}

vector<CategoriaProbabilidad> RandomForest::CargarCategorias()
{
    vector<CategoriaProbabilidad> vcRegistroSalida;
    
    vcRegistroSalida.push_back(CategoriaProbabilidad("ARSON", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("ASSAULT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("BAD-CHECKS", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("BRIBERY", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("BURGLARY", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("DISORDERLY-CONDUCT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("DRIVING-UNDER-THE-INFLUENCE", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("DRUG/NARCOTIC", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("DRUNKENNESS", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("EMBEZZLEMENT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("EXTORTION", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("FAMILY-OFFENSES", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("FORGERY/COUNTERFEITING", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("FRAUD", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("GAMBLING", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("KIDNAPPING", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("LARCENY/THEFT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("LIQUOR-LAWS", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("LOITERING", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("MISSING-PERSON", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("NON-CRIMINAL", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("OTHER-OFFENSES", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("PORNOGRAPHY/OBSCENE-MAT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("PROSTITUTION", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("RECOVERED-VEHICLE", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("ROBBERY", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("RUNAWAY", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("SECONDARY-CODES", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("SEX-OFFENSES-FORCIBLE", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("SEX-OFFENSES-NON-FORCIBLE", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("STOLEN-PROPERTY", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("SUICIDE", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("SUSPICIOUS-OCC", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("TREA", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("TRESPASS", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("VANDALISM", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("VEHICLE-THEFT", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("WARRANTS", 0, 0));
    vcRegistroSalida.push_back(CategoriaProbabilidad("WEAPON-LAWS", 0, 0));
    
    return vcRegistroSalida;
}



void RandomForest::Clasificar(string _rutaArboles, string _rutaSalida, string _rutaTestSet)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    
    vector<RegistroCSV> vcCSV;
    vector<CategoriaProbabilidad> vcRegistroSalida;
    vector<RegistroTest> vcRegistrosTest;
    f_salida.open(_rutaSalida.c_str(), ofstream::out);
    f_test_set.open(_rutaTestSet.c_str(), ifstream::in);
    string ruta_entrada;
    ostringstream ostr;
    int totaliza = 0;
    
    string csvLine;
    string csvCampos;
    
    string id;
    string anio;
    string mes;
    string horario;
    string semana;
    string dia;
    string distrito;
    
    string abuelo;
    string padre;
    string campo;
    string clase;
    string probabilidad;
    
    vector<RegistroArbol> vcRegArboles;
    vector<TodosArboles> todosArboles;
    
    string campo1;
    string campo2;
    string campo3;
    
    ostringstream salida;
    ostringstream inicio;
    vcRegistroSalida = CargarCategorias();
    string categorias_replace;
    
    //Encabezado de la salida
    for (vector<CategoriaProbabilidad>::iterator cp = vcRegistroSalida.begin(); cp != vcRegistroSalida.end(); cp++)
    {
        inicio << "," <<  cp->categoria;
    }
    f_salida << "Id" << inicio.str() << endl;
    
    //Carga de arboles
    for(int i = 0; i < cant_arboles; i++)
    {
        cout << "Carga arbol " << i << " finalizada." << endl;
        
        ostr.str("");
        ostr << i;
        ruta_entrada = _rutaArboles + "arbol_B_" + ostr.str() + ".txt";
        f_arboles_entrada.open(ruta_entrada.c_str(), ifstream::in);
        
        //Primer linea, tomo los campos que voy a evaluar
        getline(f_arboles_entrada, csvCampos);
        istringstream csvStreamCampos(csvCampos);
        vector<std::string> csvColumnCampos;
        string csvElementCampos;
        while( std::getline(csvStreamCampos, csvElementCampos, ',') )
        {
            csvColumnCampos.push_back(csvElementCampos);
        }
        campo1 = csvColumnCampos[0]; //Abuelo
        campo2 = csvColumnCampos[1]; //Padre
        campo3 = csvColumnCampos[2]; //Campo
        
        while(getline(f_arboles_entrada, csvCampos))
        {
            istringstream csvStreamCampos(csvCampos);
            vector<std::string> csvColumnCampos;
            string csvElementCampos;
            while(getline(csvStreamCampos, csvElementCampos, ',') )
            {
                csvColumnCampos.push_back(csvElementCampos);
            }
            abuelo = csvColumnCampos[0];
            padre = csvColumnCampos[1];
            campo = csvColumnCampos[2];
            clase = csvColumnCampos[3];
            probabilidad = csvColumnCampos[4];
            
            vcRegArboles.push_back(RegistroArbol(abuelo.c_str(), padre.c_str(), campo.c_str(), clase.c_str(), probabilidad.c_str()));
        }
        
        todosArboles.push_back(TodosArboles(atoi(campo1.c_str()), atoi(campo2.c_str()), atoi(campo3.c_str()), vcRegArboles));
        f_arboles_entrada.close();
    }
    //Fin carga de arboles
    
    int cuenta_registros = 0;
    //Carga de registroa a clasificar
    while(getline(f_test_set, csvLine))
    {
        cuenta_registros++;
        istringstream csvStream(csvLine);
        vector<string> csvColumn;
        string csvElement;
        
        while(getline(csvStream, csvElement, ','))
        {
            csvColumn.push_back(csvElement);
        }
        id = csvColumn[0];
        anio = csvColumn[1];
        mes = csvColumn[2];
        horario = csvColumn[3];
        semana = csvColumn[4];
        dia = csvColumn[5];
        distrito = csvColumn[6];
        
        //vcRegistrosTest.push_back(RegistroTest(id.c_str(), anio.c_str(), mes.c_str(), horario.c_str(), semana.c_str(), dia.c_str(), distrito.c_str()));
        vcCSV.push_back(csvColumn);
        if(cuenta_registros % 10000 == 0)
            cout << "Carga registro " << cuenta_registros << " finalizada." << endl;
    }
    //Fin carga de registroa a clasificar
    
    //Clasificacion
    for(vector<RegistroCSV>::iterator rt = vcCSV.begin(); rt != vcCSV.end(); rt++)
    {
        for (vector<CategoriaProbabilidad>::iterator cp = vcRegistroSalida.begin(); cp != vcRegistroSalida.end(); cp++)
        {
            cp->probabilidad = (float)0;
            cp->cant_datos = 0;
        }
        salida.str("");
        totaliza = 0;
        for(vector<TodosArboles>::iterator ta = todosArboles.begin(); ta != todosArboles.end(); ta++)
        {
            for(vector<RegistroArbol>::iterator ua = ta->vcArbol.begin(); ua != ta->vcArbol.end(); ua++)
            {
                if(rt->vcCsvColumn[ta->campo1 + 1] == ua->abuelo)
                {
                    if(rt->vcCsvColumn[ta->campo2 + 1] == ua->padre)
                    {
                        if(rt->vcCsvColumn[ta->campo3 + 1] == ua->campo)
                        {
                            totaliza++;
                            for (vector<CategoriaProbabilidad>::iterator cp = vcRegistroSalida.begin(); cp != vcRegistroSalida.end(); cp++)
                            {
                                if(ua->clase == cp->categoria)
                                {
                                    cp->probabilidad += atof(ua->probabilidad.c_str());
                                    cp->cant_datos++;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //Calculo el promedio de la probabilidad y guardo el registro clase-probabliidad
        for (vector<CategoriaProbabilidad>::iterator cp = vcRegistroSalida.begin(); cp != vcRegistroSalida.end(); cp++)
        {
            if(cp->cant_datos > 0)
                cp->probabilidad = (float)cp->cant_datos / (float)totaliza; //(float)cp->probabilidad/(float)cp->cant_datos;
            
            salida << "," << cp->probabilidad;
        }
        f_salida << rt->vcCsvColumn[0] << salida.str() << endl;
        
        now = time(0);
        dt = ctime(&now);
        cout << "Registro: " << rt->vcCsvColumn[0] << " - " << dt;
    }
    //Fin clasificacion
    
    
    f_salida.close();
}
