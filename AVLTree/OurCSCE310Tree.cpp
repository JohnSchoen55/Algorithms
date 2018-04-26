#include "OurCSCE310Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCSCE310Tree{
 public:
  OurCSCE310Tree(void);
  OurCSCE310Tree(OurCSCE310Tree&);
  ~OurCSCE310Tree(void);
  void operator=(OurCSCE310Tree&);
  OurCSCE310Tree* getParent(void);
  OurCSCE310Tree* getLeft(void);
  OurCSCE310Tree* getRight(void);
  int getValue(void);
  void setParent(OurCSCE310Tree*);
  void setLeft(OurCSCE310Tree*);
  void setRight(OurCSCE310Tree*);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
  int getHeight();
  
 private:
  int value;
  OurCSCE310Tree* parent;
  OurCSCE310Tree* left;
  OurCSCE310Tree* right;
};
 */

OurCSCE310Tree::OurCSCE310Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCSCE310Tree::OurCSCE310Tree( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

void OurCSCE310Tree::operator=( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

OurCSCE310Tree::~OurCSCE310Tree(){
  delete left;
  left = NULL;
  delete right;
  right = NULL;
  value = 0;
}

OurCSCE310Tree* OurCSCE310Tree::getParent(){
  return parent;
}

OurCSCE310Tree* OurCSCE310Tree::getLeft(){
  return left;
}

OurCSCE310Tree* OurCSCE310Tree::getRight(){
  return right;
}

int OurCSCE310Tree::getValue(){
  return value;
}

void OurCSCE310Tree::setParent( OurCSCE310Tree* par ){
  parent = par;
}

void OurCSCE310Tree::setLeft( OurCSCE310Tree* lft ){
  left = lft;
}

void OurCSCE310Tree::setRight( OurCSCE310Tree* rght ){
  right = rght;
}

void OurCSCE310Tree::setValue( int val ){
  value = val;
}

void OurCSCE310Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( ( val < getValue() && !getLeft() ) || ( val < getValue() && !getLeft()->getValue() ) ){
    left = new OurCSCE310Tree();
    left->setParent( this );
    left->setValue( val );
  }
  else if( ( val > getValue() && !getRight() ) || ( val > getValue() && !getRight()->getValue() ) ){
    right = new OurCSCE310Tree();
    right->setParent( this );
    right->setValue( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  if( getLeft() && getLeft()->getRight() && !getRight() || getLeft() && getLeft()->getRight() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() + 1 ){
    rotateLeftRight();
  }
  else if( getRight() && getRight()->getLeft() && !getLeft() || getRight() && getRight()->getLeft() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() + 1 ){
    rotateRightLeft();
  }
  else if( getLeft() && !getRight() && getLeft()->getHeight() > 1 || getLeft() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 ){
    rotateRight();
  }
  else if( getRight() && !getLeft() && getRight()->getHeight() > 1 || getRight() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 ){
    rotateLeft();
  }

}

void OurCSCE310Tree::printPreorder(){
  if( getValue() ){
    cout << getValue();
  }
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }
}

void OurCSCE310Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }
}

void OurCSCE310Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
}

int OurCSCE310Tree::getHeight(){
  if( getLeft() && getLeft()->getValue() && ( !getRight() || !getRight()->getValue() ) ){
    return getLeft()->getHeight() + 1;
  }
  else if( getRight() && getRight()->getValue() && ( !getLeft() || !getLeft()->getValue() ) ){
    return getRight()->getHeight() + 1;
  }
  else if( getRight() && getLeft() && getRight()->getValue() && getLeft()->getValue() ){
    return fmax( getRight()->getHeight() , getLeft()->getHeight() ) + 1;
  }
  else if( getValue() && ( !getLeft() || !getLeft()->getValue() ) && ( !getRight() || !getRight()->getValue() ) ){
    return 1;
  }
  return 0;
}

void OurCSCE310Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
}

void OurCSCE310Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
}

void OurCSCE310Tree::rotateLeft(){
OurCSCE310Tree* left = new OurCSCE310Tree;
OurCSCE310Tree* right = new OurCSCE310Tree;
  if(this->getLeft() == NULL){
  setLeft(left);
  getLeft()->setValue(getValue());
  setValue(getRight()->getValue());
  setRight(getRight()->getRight());
}
else{
  getLeft()->setLeft(left);
  getLeft()->setRight(right);
  getLeft()->getLeft()->setValue(getLeft()->getValue());
  getLeft()->setValue(getValue());
  getLeft()->getRight()->setValue(getRight()->getLeft()->getValue());
  setValue(getRight()->getValue());
  setRight(getRight()->getRight());
  }
 }

void OurCSCE310Tree::rotateRight(){
OurCSCE310Tree* left = new OurCSCE310Tree;
OurCSCE310Tree* right = new OurCSCE310Tree;
  if(this->getRight() == NULL){
  setRight(right);
  getRight()->setValue(getValue());
  setValue(getLeft()->getValue());
  setLeft(getLeft()->getLeft());
}
else{
  getRight()->setRight(right);
  getRight()->setLeft(left);
  getRight()->getRight()->setValue(getRight()->getValue());
  getRight()->setValue(getValue());
  getRight()->getLeft()->setValue(getLeft()->getRight()->getValue());
  setValue(getLeft()->getValue());
  setLeft(getLeft()->getLeft());
  }
}

void OurCSCE310Tree::deleteNode( int key ){
// 4 node cases
if(getLeft() != NULL && getRight() != NULL){
  if(getLeft()->getRight() != NULL){  // works left right right left
    if(key == getValue()){
      setValue(getLeft()->getRight()->getValue());
      getLeft()->getRight()->setValue(NULL);
    }
    if(key == getLeft()->getValue()){ // works
      getLeft()->setValue(getLeft()->getRight()->getValue());
      getLeft()->getRight()->setValue(NULL);
    }
    if(key == getRight()->getValue()){
      getRight()->setValue(getValue());
      setValue(getLeft()->getRight()->getValue());
      getLeft()->getRight()->setValue(NULL);
    }
    if(key == getLeft()->getRight()->getValue()){
      getLeft()->getRight()->setValue(NULL);
    }
  }
  if(getRight()->getLeft() != NULL){  // works
    if(key == getValue()){
      setValue(getRight()->getLeft()->getValue());
      getRight()->getLeft()->setValue(NULL);
    }
    if(key == getRight()->getValue()){ // works
      getRight()->setValue(getRight()->getLeft()->getValue());
      getRight()->getLeft()->setValue(NULL);
    }
    if(key == getLeft()->getValue()){
      getLeft()->setValue(getValue());
      setValue(getRight()->getLeft()->getValue());
      getRight()->getLeft()->setValue(NULL);
    }
    if(key == getRight()->getLeft()->getValue()){
      getRight()->getLeft()->setValue(NULL);
    }
  } // end left righ right left
   
   // left left right right
  if(getLeft()->getLeft() != NULL){
    if(key == getValue()){
      setValue(getLeft()->getValue());
      getLeft()->setValue(getLeft()->getLeft()->getValue());
      getLeft()->getLeft()->setValue(NULL);
    }
    if(key == getLeft()->getValue()){
      getLeft()->setValue(getLeft()->getLeft()->getValue());
      getLeft()->getLeft()->setValue(NULL);
    }
    if(key == getLeft()->getLeft()->getValue()){
      getLeft()->getLeft()->setValue(NULL);
    }
  }

  if(getRight()->getRight() != NULL){
    if(key == getValue()){
      setValue(getRight()->getValue());
      getRight()->setValue(getRight()->getRight()->getValue());
      getRight()->getRight()->setValue(NULL);
    }
    if(key == getRight()->getValue()){
      getRight()->setValue(getRight()->getRight()->getValue());
      getRight()->getRight()->setValue(NULL);
    }
    if(key == getRight()->getRight()->getValue()){
      getRight()->getRight()->setValue(NULL);
    }
  }   // end of 4 nodes
  
  // 3 node cases
  if(getLeft() != NULL && getRight() != NULL){ 
    if(key == getValue()){
      setValue(getLeft()->getValue());
      getLeft()->setValue(NULL);
    }
    if(key == getLeft()->getValue()){
      getLeft()->setValue(NULL);
    }
    if(key == getRight()->getValue()){
     getRight()->setValue(NULL);
    }
   }
  } // end if
  
 // 2 node
 if(getLeft() != NULL){
   if(key == getValue()){
     setValue(getLeft()->getValue());
     getLeft()->setValue(NULL);
   }
   if(key == getLeft()->getValue()){
     getLeft()->setValue(NULL);
   }
 }

 if(getRight() != NULL){
   if(key == getValue()){
     setValue(getRight()->getValue());
     getRight()->setValue(NULL);
   }
   if(key == getRight()->getValue()){
     getRight()->setValue(NULL);
   }
 }
 // 1 node
 if(getLeft() == NULL && getRight() == NULL){
   if(key == getValue()){
     setValue(NULL);
  }
 }
 
}
  

