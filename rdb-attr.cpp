#include <iostream>
#include "rdb.h"

using namespace std;

class Attr
{ // Base class for attributes
  // Add operators for different attribute type in derived classes
public:
   
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
    virtual int getType()=0;
   
};

class IntAttr : public Attr
{
private:
    int value;

public:

    IntAttr(int a) : value(a) {}
    IntAttr(){}
    ~IntAttr(){}

    int getValue()
    {
        return value;
    }

  bool operator==(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value==p->value)return true;
    else return false;
  }
  bool operator!=(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value!=p->value)return true;
    else return false;
  }
  bool operator<(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value<p->value)return true;
    else return false;
  }
  bool operator<=(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value<=p->value)return true;
    else return false;
  }
  bool operator>(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value>p->value)return true;
    else return false;
  }
  bool operator>=(const Attr &right){
    const IntAttr* p=dynamic_cast<const IntAttr*>(&right); 
    if(value>=p->value)return true;
    else return false;
  }
  int getType(){
    return 1;
  }
};

class FloatAttr : public Attr
{
private:
    float value;

public:
    FloatAttr(float a) : value(a) {}
    FloatAttr(){}
    ~FloatAttr(){}

    float getValue()
    {
        return value;
    }
  bool operator==(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value==p->value)return true;
    else return false;
  }
  bool operator!=(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value!=p->value)return true;
    else return false;
  }
  bool operator<(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value<p->value)return true;
    else return false;
  }
  bool operator<=(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value<=p->value)return true;
    else return false;
  }
  bool operator>(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value>p->value)return true;
    else return false;
  }
  bool operator>=(const Attr &right){
    const FloatAttr* p=dynamic_cast<const FloatAttr*>(&right); 
    if(value>=p->value)return true;
    else return false;
  }
  int getType(){
    return 2;
  }
};

class StrAttr : public Attr
{
private:
    string value;

public:
    StrAttr(string a) : value(a) {}
    StrAttr(){}
    ~StrAttr(){}

    string getValue()
    {
        return value;
    }
     bool operator==(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value==p->value)return true;
    else return false;
  }
  bool operator!=(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value!=p->value)return true;
    else return false;
  }
  bool operator<(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value<p->value)return true;
    else return false;
  }
  bool operator<=(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value<=p->value)return true;
    else return false;
  }
  bool operator>(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value>p->value)return true;
    else return false;
  }
  bool operator>=(const Attr &right){
    const StrAttr* p=dynamic_cast<const StrAttr*>(&right); 
    if(value>=p->value)return true;
    else return false;
  }
  int getType(){
    return 3;
  }
};

class Record
{
private:
    vector<Attr *> attrptr;
public:
    Record(){}
    ~Record(){}
    void addAttr(Attr *attr)
    {
        attrptr.push_back(attr);
    }
    vector<Attr *> getRecord()
    {
        return attrptr;
    }

    bool IsSame(Record *r){
        int p=0;
        vector<Attr*>c=r->getRecord();
      for(int i=0;i<r->getSize();i++){     
        if(*((this->attrptr)[i])== *c[i]){
            p++;
        }
      }
      if(p==r->getSize())return true;
      else return false;
    }

    int getSize(){
      int j=0;
      for(auto i=attrptr.begin();i<attrptr.end();i++){
        j++;
      }
      return j;
    }

    void print(){
        for(auto j=attrptr.begin();j!=attrptr.end();j++){
              
                if(dynamic_cast<IntAttr*>(*j)){
                cout << static_cast<IntAttr*>(*j)->getValue()<< "\t"<<"\t";
              }
              if(dynamic_cast<FloatAttr*>(*j)){
                cout << static_cast<FloatAttr*>(*j)->getValue()<< "\t"<<"\t";
              }
              if(dynamic_cast<StrAttr*>(*j)){
                cout << static_cast<StrAttr*>(*j)->getValue()<< "\t"<<"\t";
              }
            }

    }
};

class Relation
{
private:
    int nattr = 0, nrecs = 0; // number of attributes and records
    vector<string> attrnames; // schema
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records

public:
    Relation(){}
    ~Relation(){}
    void addAttrnames(string a)
    {
        attrnames.push_back(a);       
        nattr++;
        attrinds.push_back(nattr);
    }
    void addrecord(Record *a)
    {
        recs.push_back(a);
        nrecs++;
    }

    int getNattr(void)
    {
        return nattr;
    }

    int getNrecs(void)
    {
        return nrecs;
    }

    vector<int> getAttrinds()
    {
        return attrinds;
    }

    list<Record *> getRelation()
    {
        return recs;
    }

    vector<string> getAttrNames(){
        return attrnames;
    }
    
    void print(){
        int lm=0,qs=0;
        for (int i = 0; i < nattr; i++)
        {
            cout<< attrnames[i] << "\t"<<"\t";
        }
        cout << endl;
        for (auto i=recs.begin();i!=recs.end();i++)
        {  
            (*i)->print(); 
            cout<<endl;
        }
    }
};