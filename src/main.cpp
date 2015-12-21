#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;
#include "RandomForest.h"

int main(int argc, char* args[])
{
    
    argc = 3;
    args[1] = "C";
    args[2] = "1000";
    args[3] = "200";
    
    if(argc < 3)
    {
        cout << "Debe ingresar E para entrenar, C para clasificar, la cantidad de registros y la cantidad de arboles como parametros!" << endl;
    }
    else
    {
        
        cout << "Starting" << endl;
        //Entrenar
        if(strcmp(args[1], "E") == 0)
        {
            RandomForest* rndForest;
            
            ostringstream ostr;
            
            for(int i = 0; i < atoi(args[3]); i++)
            {
                rndForest = new RandomForest(atoi(args[2]),atoi(args[3]));
                ostr.str("");
                ostr << i;
                rndForest->ArmarArbol("/Users/jmwaisgold/workspace_other/san_francisco_crime/trains/archivo_2k_" + ostr.str() + ".csv", "/Users/jmwaisgold/workspace_other/san_francisco_crime/trains/outs/arbol_B_" + ostr.str() + ".txt");
            }
        }
        //Clasificar
        if(strcmp(args[1], "C") == 0)
        {
            
            RandomForest* rndForest;
            rndForest = new RandomForest(atoi(args[2]),atoi(args[3]));
            rndForest->Clasificar("/Users/jmwaisgold/workspace_other/san_francisco_crime/trains/outs/", "/Users/jmwaisgold/workspace_other/san_francisco_crime/classification/outs/salida.csv", "/Users/jmwaisgold/workspace_other/san_francisco_crime/classification/test_pre.csv");
        }
        cout << "Finish" << endl;
    }
    cin.get();
    return 0;
}
