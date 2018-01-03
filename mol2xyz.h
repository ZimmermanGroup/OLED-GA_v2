#ifndef MOL2XYZ_H
#define MOL2XYZ_H

#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/builder.h>
#include <openbabel/obiter.h>
#include <memory>
#include <iostream>
#include "stringtools.h"
#include "pTable.h"
#include <openbabel/forcefield.h>

/*   
 *  Convert MOL format generated by ChemDraw to xyz format with label 
 *  Optimization of the fragment is also implenmented 
 *  to do: convert all files in the certain folder to 1.xyz ... etc.
 *         two folders : regular and cap
 */

class MOL2XYZ {

  int natoms;
  vector<string> anames;
  vector<double> coords;
  vector<int> index;
  vector<string>  label;
 
  vector<OpenBabel::OBAtom*> handles;
  
  public:

  string title;

//read MOL file and add H atoms to it (except atom with label)
  unique_ptr<OpenBabel::OBMol> readXYZ(string filename);

//write the modifed xyz file into target directory
  void writeXYZ(unique_ptr<OpenBabel::OBMol> & mol, string dir);
 
  int minimize(unique_ptr<OpenBabel::OBMol> & mol);
 
};

#endif