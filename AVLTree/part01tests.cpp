#include "OurCSCE310Tree.h"
#include <iterator>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main( int argc , char* argv[] ){
  ifstream addsFile( "part01test01.adds.input" );
   
  istream_iterator<int> aStart(addsFile),aEnd;
  
  vector<int> adds(aStart,aEnd);
  //cout<< << endl;
  
  OurCSCE310Tree tree;

  for( int a = 0; a < adds.size(); a++ ){
    try{
      tree.insert( adds[a] );
    }
    catch(...){
      cerr << "An error occurred in rotation" << endl;
    }
  }

  try{
   tree.deleteNode(6);
    cout<<"Preorder"<<endl;
    tree.printPreorder();
    cout << endl<< endl;
    cout<<"Inorder"<<endl;
    tree.printInorder();
    cout << endl<< endl;
    cout<<"Postorder"<<endl;
    tree.printPostorder();
    cout << endl<< endl;
  }
  catch(...){
    cerr << "An error occurred in printing" << endl;
  }
  return 0;
}
