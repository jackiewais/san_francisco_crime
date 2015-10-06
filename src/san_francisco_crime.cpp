//============================================================================
// Name        : SanFranciscoCrime.cpp
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>

#include "./randomforest/dataanalysis.h"

using namespace std;
using namespace alglib;

void randomforesttests(){
	 long int trainSize=10;
	 long int variablesSize=9;
	 long int arbolClasifador=2;
	 long int cantArboles=1;
	 double r=0.66;
	 long int codreturn=0;

	 	decisionforest df;
	 	real_2d_array data2;
	 	dfreport dfreporte;
	 	//data2 = data;
	 	cout << "antes";
	 	//alglib::dfbuildrandomdecisionforest(data2,trainSize,variablesSize,arbolClasifador,cantArboles,r,codreturn,df,dfreporte);
	 	cout << "despues";

		/*
			decisionforest decforest;
			real_1d_array x;
			real_1d_array y;
			dfprocess(decforest,x,y);
		*/
}

int main() {

	cout << "Starting" << endl;

	ifstream file("/home/jackie/workspace/san_francisco_crime/train.csv");
	string data[1000][9];

	 for(int row = 0; row < 1000; ++row)
	     {
	         string line;
	         getline(file, line);
	         if ( !file.good() )
	             break;

	         stringstream iss(line);

	         for (int col = 0; col < 100; ++col)
	         {
	             string val;
	             getline(iss, val, ',');

	             if ( !iss.good() ){
	            	 stringstream convertor(val);
	            	 convertor >> data[row][col];
	            	 break;
	             }

	             stringstream convertor(val);
	             convertor >> data[row][col];
	         }
	     }


		 for(int x=0;x<10;x++)
		    {
		        for(int y=0;y<10;y++)
		        {
		            cout<<data[x][y] << " ";
		        }
		    cout<<endl;
		    }

		 randomforesttests();
	return 0;
}
