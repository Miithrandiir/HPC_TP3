#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

  ifstream in(argv[1]);

  if(!in.is_open()){
    cerr << "erreur d'ouverture de " << argv[1] << endl;
    return -1;
  }

  string s;
  vector <float> coord;
  
  in >> s;
  while(!in.eof()){
    if(s=="v"){
      float x, y, z;
      in >> x >> y >> z;
      coord.push_back(x); coord.push_back(y+0.5); coord.push_back(z-2);
      in >> s;
      continue;
    }
    if(s=="f"){
      int a, b, c, d;
      string s;
      in >> a >> b >> c >> s;
      cout << "tri ";
      cout << coord[(a-1)*3] << " " << coord[(a-1)*3 +1] << " " << coord[(a-1)*3 +2] << " ";
      cout << coord[(b-1)*3] << " " << coord[(b-1)*3 +1] << " " << coord[(b-1)*3 +2] << " ";
      cout << coord[(c-1)*3] << " " << coord[(c-1)*3 +1] << " " << coord[(c-1)*3 +2] << endl;
      if(s!="f"){// c'est un quad
	d = stoi(s);
	cout << "tri ";
	cout << coord[(a-1)*3] << " " << coord[(a-1)*3 +1] << " " << coord[(a-1)*3 +2] << " ";      
	cout << coord[(c-1)*3] << " " << coord[(c-1)*3 +1] << " " << coord[(c-1)*3 +2] << " ";
	cout << coord[(d-1)*3] << " " << coord[(d-1)*3 +1] << " " << coord[(d-1)*3 +2] << endl;
	in >> s;
	continue;
      }
    }
  }// while

  in.close();
      
  return 0;
}
