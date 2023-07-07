#include <iostream>
#include <tuple>
#include "rdb-join.cpp"

int main()
{
  int a = 1;
  vector<Relation *> R;
  DNFformula *f;
  
  cout<<endl;
  cout << "0  -- Exit from Interface"<<endl;
  cout << "1  -- Creation of Relation"<<endl;
  cout << "2  -- Union of two Relations"<<endl;
  cout << "3  -- Difference of two Relations"<<endl;
  cout << "4  -- Catersianproduct of two Relations"<<endl;
  cout << "5  -- Projection of Relation"<<endl;
  cout << "6  -- Rename of Relation"<<endl;
  cout << "7  -- Selection of Relation"<<endl;
  cout << "8  -- Intersection of two Relations"<<endl;
  cout << "9  -- Natural Join of two Relations"<<endl;
  cout << "10 -- Deletion of Relation"<<endl;
  cout << "11 -- Addition of records to the Relation"<<endl;
  cout << "12 -- Printing the Relation"<<endl;
  cout << endl;
  
  while (a)
  { 
    cout << "Enter the value of a :";
    cin >> a;
    
    if (a == 1)
    {
      Relation *r = new Relation();
      int b = 1, x, y, pre = 1;
      cout << "Enter the number of attrnames:" << endl;
      cin >> x;
      string f[x];
      cout << "Enter the attrnames:" << endl;
      for (int i = 0; i < x; i++)
      {
        cin >> f[i];
        r->addAttrnames(f[i]);
      }
      cout << "Enter the number of records:" << endl;
      cin >> y;
      cout << "Enter the records:" << endl;
      cout << "if ind=1 then String Attribute" << endl;
      cout << "if ind=2 then Integer Attribute" << endl;
      cout << "if ind=3 then Float Attribute" << endl;
      while (y != 0)
      {
        Record *r1 = new Record();
        cout << "Attribute-" << pre << ":" << endl;

        for (int i = 0; i < x; i++)
        {
          cout << "ind=";
          int ind;
          cin >> ind;
          if (ind == 1)
          {
            string g;
            cout << "String Attribute=";
            cin >> g;
            StrAttr *p = new StrAttr(g);
            r1->addAttr(p);
          }
          else if (ind == 2)
          {
            int g;
            cout << "Integer Attribute=";
            cin >> g;
            IntAttr *p = new IntAttr(g);
            r1->addAttr(p);
          }
          else if (ind == 3)
          {
            float g;
            cout << "Float Attribute=";
            cin >> g;
            FloatAttr *p = new FloatAttr(g);
            r1->addAttr(p);
          }
        }
        r->addrecord(r1);
        y--;
        pre++;
      }
      cout << endl;
      cout << "Relation" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 2)
    {
      int p, q;
      Relation *r;
      cout << "Enter the index of relation-1=";
      cin >> p;
      cout << "Enter the index of relation-2=";
      cin >> q;
      cout << endl;
      r = Union(R[p], R[q]);
      cout << "Union" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 3)
    {
      int p, q;
      Relation *r;
      cout << "Enter the index of relation-1=";
      cin >> p;
      cout << "Enter the index of relation-2=";
      cin >> q;
      cout << endl;
      r = Difference(R[p], R[q]);
      cout << "Difference" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 4)
    {
      int p, q;
      Relation *r;
      cout << "Enter the index of relation-1=";
      cin >> p;
      cout << "Enter the index of relation-2=";
      cin >> q;
      cout << endl;
      r = Catersianproduct(R[p], R[q]);
      cout << "Catersianproduct" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 5)
    {
      int p, q;
      Relation *r;
      list<string> projectattrs;
      cout << "Enter the index of relation=";
      cin >> p;
      cout << "Enter number of projectattrs=";
      cin >> q;
      cout << "Enter the projectattrs:" << endl;
      for (int i = 0; i < q; i++)
      {
        string a;
        cin >> a;
        projectattrs.push_back(a);
      }
      cout << endl;
      r = Projection(R[p], projectattrs);
      cout << "Projection" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 6)
    {
      int p;
      Relation *r;
      string s1, s2;
      cout << "Enter the index of relation=";
      cin >> p;
      cout << "Enter the string s1=";
      cin >> s1;
      cout << "Enter the string s2=";
      cin >> s2;
      cout << endl;
      r = Difference(R[p], s1, s2);
      cout << "After changed" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
    }

    if (a == 7)
    {
      Relation *r;
      struct DNFformula *f= new struct DNFformula();
      cout << "enter index of relation=";
      int index;
      cin >> index;
       int y=1;
      while(y){
      list<tuple<string, char, Attr *>>l;
     
      int z=1;
      while(z){
      tuple<string, char, Attr *> t;
      cout << "enter string=";
      string s;
      cin >> s;
      cout<<"'1' : =="<<endl;
      cout<<"'2' : !="<<endl;
      cout<<"'3' : <"<<endl;
      cout<<"'4' : <="<<endl;
      cout<<"'5' : >"<<endl;
      cout<<"'6' : >="<<endl;
      cout << "enter char=";
      char a;
      cin >> a ;
      cout<<"Index =1 - String Attribute"<<endl;
      cout<<"Index =2 - Integer Attribute"<<endl;
      cout<<"Index =3 - Float Attribute"<<endl;
      cout << "enter index=";
      int ind;
      cin >> ind;
      if (ind == 1)
      {
        string g;
        cout << "String Attribute=";
        cin >> g;
        StrAttr *p = new StrAttr(g);
        t=make_tuple(s,a,p);
      }
      else if (ind == 2)
      {
        int g;
        cout << "Integer Attribute=";
        cin >> g;
        IntAttr *p = new IntAttr(g);
        t=make_tuple(s,a,p);
      }
      else if (ind == 3)
      {
        float g;
        cout << "Float Attribute=";
        cin >> g;
        FloatAttr *p = new FloatAttr(g);
        t=make_tuple(s,a,p);
      }
      l.push_back(t);
     
      (f->ops).push_back(l);
      }
      r = Union(R[index], f);
      cout<<endl;
      cout<<"Selection"<<endl;
      r->print();
      cout<<endl;
      R.push_back(r);
  }
   
    if (a == 8){
    int p, q;
      Relation *r;
      cout << "Enter the index of relation-1=";
      cin >> p;
      cout << "Enter the index of relation-2=";
      cin >> q;
      r = Intersection(R[p], R[q]);
      cout<<endl;
      cout << "Intersection" << endl;
      r->print();
      cout << endl;
      R.push_back(r);
   }
   
    if (a == 9){
    int p, q;
    list<string>l;
    Relation *r;
    cout << "Enter the index of relation-1=";
    cin >> p;
    cout << "Enter the index of relation-2=";
    cin >> q;
    int s;
    cout<<"Enter size of the string list=";
    cin>>s;
    int i=0;
    while(i!=s){
      string g;
      cout<<"string["<<i<<"]=";
      cin>>g;
      l.push_back(g);
      i++;
    }
    r = naturaljoin(R[p], R[q],l);
    cout<<endl;
    cout<<"Natural Join"<<endl;
    r->print();
    cout<<endl;
    R.push_back(r);
   }
  
    if (a == 10){
      cout<<"Enter the index of relation that should be deleted = ";
      int p;
      cin>>p;
      auto i=R.begin();
      advance(i,p);
      R.erase(i);
    }

    if (a == 11){
       cout<<"Enter the index of relation for which records should be added = ";
       int p;
       cin>>p;
       cout<<"Enter number of records to be added = ";
       int q;
       cin>>q;
       auto i=R.begin();
       advance(i,p);
       int k;
       for(k=0;k<q;k++){
        Record *r1=new Record();
        cout << "Enter the record["<<k<<"] = "<<endl;
        cout << "if l=1 then String Attribute" << endl;
        cout << "if l=2 then Integer Attribute" << endl;
        cout << "if l=3 then Float Attribute" << endl;
        for(int j=0;j<(*i)->getNattr();j++){
         int l;
         cout<<"i = ";
         cin>>l;
         if (l == 1)
          {
            string g;
            cout << "String Attribute=";
            cin >> g;
            StrAttr *p = new StrAttr(g);
            r1->addAttr(p);
          }
          else if (l == 2)
          {
            int g;
            cout << "Integer Attribute=";
            cin >> g;
            IntAttr *p = new IntAttr(g);
            r1->addAttr(p);
          }
          else if (l == 3)
          {
            float g;
            cout << "Float Attribute=";
            cin >> g;
            FloatAttr *p = new FloatAttr(g);
            r1->addAttr(p);
          }
       }
       (*i)->addrecord(r1);
      }
      cout<<endl;
      cout<<"Relation after added"<<endl;
      (*i)->print();
      cout<<endl;
    }
  
    if (a == 12){
      cout<<"Enter the index of relation that should be printed = ";
      int p;
      cin>>p;
      auto i=R.begin();
      advance(i,p);
      cout<<endl;
      cout<<"Relation"<<endl;
      (*i)->print();
      cout<<endl;
    }
  }
  cout<<"Operations completed"<<endl;
  return 0;
}
