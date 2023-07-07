#include <iostream>
#include "rdb-attr.cpp"
#include <tuple>

using namespace std;

struct DNFformula { 
    list <list <tuple <string, char, Attr *> > > ops;
    };

Relation *Union(Relation *R1, Relation *R2)
{
    list<Record *> recs1 = R1->getRelation();
    list<Record *> recs2 = R2->getRelation();
    vector<string> name = R2->getAttrNames();
    list<Record *> s1;
    int n = 0;
    Relation *r = new Relation();

    for (auto i = recs1.begin(); i!= recs1.end(); i++)
    {
        s1.push_back(*i);
        n++;
    }

    for (auto i = recs2.begin(); i!= recs2.end(); i++)
    {
       Record *p= new Record();
       p=*i;
       int ix=0,x=0;
       for (auto j = recs1.begin(); j!= recs1.end(); j++,x++)
        {
            Record *q= new Record();
            q=*j;
            if (!p->IsSame(q))
            {
                ix++;
            }
        }  
        if(ix==x){
                s1.push_back(p);
             }  
    }
    for(auto i=name.begin();i!=name.end();i++){
     r->addAttrnames(*i);
    }

    for(auto i=s1.begin();i!=s1.end();i++){
     r->addrecord(*i);
    }
    return r;
}

Relation *Difference (Relation * R1, Relation * R2){
    list<Record *> recs1 = R1->getRelation();
    list<Record *> recs2 = R2->getRelation();
    vector<string> name = R2->getAttrNames();
    list<Record *> s1;
    
    Relation *r = new Relation();
    
    for (auto i = recs1.begin(); i!= recs1.end(); i++)
    { 
        int n = 0;
        Record *p= new Record();
        p=*i;
       for (auto j = recs2.begin(); j!= recs2.end(); j++)
        {
            Record *q= new Record();
            q=*j;
            if (p->IsSame(q))
            {
                n++;
            }
        }   
        if(n==0){
            s1.push_back(p);
        } 
    }

    for(auto i=name.begin();i!=name.end();i++){
     r->addAttrnames(*i);
    }

    for(auto i=s1.begin();i!=s1.end();i++){
     r->addrecord(*i);
    }
    return r;
}

Relation *Catersianproduct(Relation * R1, Relation * R2){
    list<Record *> recs1 = R1->getRelation();
    list<Record *> recs2 = R2->getRelation();
    vector<string> name1 = R1->getAttrNames();
    vector<string> name2 = R2->getAttrNames();
    vector<string> name ;int n=0;
    int n1=R1->getNrecs();
    int n2=R2->getNrecs();
    list<Record *>s1;
    Relation *r= new Relation();
    
    for(auto i=name1.begin();i!=name1.end();i++){
        name.push_back(*i);
    }
    for(auto i=name1.begin();i!=name1.end();i++){
        name.push_back(*i);
    }
    
    for (auto i = recs1.begin(); i!= recs1.end(); i++)
    {   
       for (auto j = recs2.begin(); j!= recs2.end(); j++){
        Record *s= new Record();
        Record *p= new Record();
        p=*i;
        Record *q= new Record();
        q=*j;
        vector<Attr *> a=p->getRecord();
        vector<Attr *> b=q->getRecord();
        for(auto k=a.begin();k!=a.end();k++){
        s->addAttr(*k);
        }
        for(auto k=b.begin();k!=b.end();k++){
        s->addAttr(*k);
        }
        s1.push_back(s);
        n++;
       }    
    }

    for(auto i=name.begin();i!=name.end();i++){
     r->addAttrnames(*i);
    }

    for(auto i=s1.begin();i!=s1.end();i++){
     r->addrecord(*i);
    }
    return r;
}

Relation *Projection(Relation * R1, list<string> projectattrs){
    list<Record *> recs1 = R1->getRelation();
    list<Record *>s1;
    vector<string>a=R1->getAttrNames();
    vector<int>b;int y=0;
    Relation *r= new Relation();
    
    for(auto i=projectattrs.begin();i!=projectattrs.end();i++){
        int x=0;
      for(auto j=a.begin();j!=a.end();x++,j++){
         if(*i==*j){
            b.push_back(x);
         }
        }
    }
    for(auto i=recs1.begin();i!=recs1.end();i++){
      Record *p= new Record();
        p=*i;
      vector<Attr*>c=p->getRecord();
      Record *s=new Record();
      for(auto j=b.begin();j!=b.end();j++){
        s->addAttr(c[*j]);
        }
        y++;
        if(y==1){
            s1.push_back(s);
        }
        else {
            for(auto j=s1.begin();j!=s1.end();j++){
             if(!s->IsSame(*j)){
                s1.push_back(s);
             }
            }
        }
      }
    for(auto i=projectattrs.begin();i!=projectattrs.end();i++){
     r->addAttrnames(*i);
    }

    for(auto i=s1.begin();i!=s1.end();i++){
     r->addrecord(*i);
    }
    return r;
}

Relation *Difference (Relation * R1, string s1, string s2){
    list<Record *> recs1 = R1->getRelation();
     list<Record *> recs2;
    vector<string> name = R1->getAttrNames();
    Relation *r = new Relation();

    for(auto i=recs1.begin();i!=recs1.end();i++){
        Record*p = new Record();
        Record*q = new Record();
        p=*i;
        vector<Attr*>c=p->getRecord();
        for(auto j=c.begin();j!=c.end();j++){
         StrAttr *p=dynamic_cast<StrAttr*>(*j);
         if(p->getValue()==s1){
            *p=s2;
         }
         q->addAttr((*j));
         }
         recs2.push_back(q);
        }    
    
    for(auto i=name.begin();i!=name.end();i++){
     r->addAttrnames(*i);
    }
    
    for(auto i=recs2.begin();i!=recs2.end();i++){
     r->addrecord(*i);
    }
    return r;  
}

Relation *Intersection(Relation *R1, Relation *R2){
    list<Record *> recs1 = R1->getRelation();
    list<Record *> recs2 = R2->getRelation();
    vector<string> name = R2->getAttrNames();
    list<Record *> s1;
    int n = 0;
    Relation *r = new Relation();
    for(auto i=recs1.begin();i!=recs1.end();i++){
        for(auto j=recs2.begin();j!=recs2.end();j++){
            if((*i)->IsSame(*j)){
                s1.push_back(*i);
                break;
            }
        }
    }
    for(auto i=name.begin();i!=name.end();i++){
     r->addAttrnames(*i);
    }

    for(auto i=s1.begin();i!=s1.end();i++){
     r->addrecord(*i);
    }
    return r;

}


