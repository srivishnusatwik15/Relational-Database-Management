#include <iostream>
#include "rdb-basics.cpp"

Relation * naturaljoin(Relation * R1, Relation * R2, list<string>joinattr)
{
  list<Record *> recs1 = R1->getRelation();
  list<Record *> recs2 = R2->getRelation();
  list<Record *> recs;
  vector<string> name1 = R1->getAttrNames();
  vector<string> name2 = R2->getAttrNames();
  vector<string> name;
  list<string> namecheck;
  vector<string> sname;
  Relation *result=new Relation();
  Relation *rr;

  for(auto i=name1.begin();i!=name1.end();i++){
    name.push_back(*i);
  }
  for(auto i=name2.begin();i!=name2.end();i++){
    int n=0;
    for(auto j=name1.begin();j!=name1.end();j++){
    if((*i)==(*j)){
      n++;
    }
    }
    if(n==0){
      name.push_back(*i);
    }
  }

   for(auto i=name2.begin();i!=name2.end();i++){
    int n=0;
    for(auto j=name1.begin();j!=name1.end();j++){
     if((*i)==(*j)){
      sname.push_back(*i);
      break;
     }
    }
    }
   
  for(int i=0;i<sname.size();i++){
     int idx1=0,idx2=0;
     for(int j=0;j<name1.size();j++){
      if(sname[i]==name1[j]){
         idx1=j;
         break;
      }
     }

     for(int j=0;j<name2.size();j++){
      if(sname[i]==name2[j]){
         idx2=j;
         break;
      }
     }

    for(auto j=recs1.begin();j!=recs1.end();j++){
      vector<Attr*>c=(*j)->getRecord();
      int m=c.size();
     for(auto k=recs2.begin();k!=recs2.end();k++){
      vector<Attr*>d=(*k)->getRecord();
      if(c[idx1]->operator==(*d[idx2])){
        for(int l=0;l<d.size();l++){
          if(l!=idx2){
          c.push_back(d[l]);
          }
        }
        break;
      }
    } 
    if(c.size()>m){
     Record *r=new Record();
     for(auto k=c.begin();k!=c.end();k++){
      r->addAttr(*k);
     }
     recs.push_back(r);
    }
    }
  }

  for(auto i=recs.begin();i!=recs.end();i++){
    result->addrecord(*i);
  }
  for(auto i=name.begin();i!=name.end();i++){
    result->addAttrnames(*i);
  }
  rr=Projection(result,joinattr);
return rr;
}