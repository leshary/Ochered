#include <iostream>
#include <string>
using namespace std;

struct person
{
    string name;
    float time;
    person* next;
    person* last;
    person ( string name, float time ) {
    this->name = name;
    this->time = time;
    next = NULL;
    last = NULL;
    }
};
class que
{
private:
    person* head;
    person* find1 ( string n , person* x)
    {
       if ( x == NULL )
            return NULL;
       if ( x->name == n )
            return x;
       return (find1( n, x->next));

    }
    void dell ( person* n)
    {
        if ( n->last == NULL ){
            n->next->last=NULL;
            head = n->next;
            delete n;
        }
        if ( n-> next == NULL){
            n->last->next = 0;
            delete n;
        }
       n->last->next = n->next;
       n->next->last = n->last;
       delete n;
    }

    person* last ( person* x )
    {
       if ( x == NULL )
            return NULL;
       if ( x->next )
            return (x->next);
       return ( x );
    }
public:

    void push( string name, float time )
    {
    person* n = last (head);
    if (n)
        n->next = new person ( name, time );
        n->next->last = n;
    }
    void exit ( string name )
    {
        dell ( find1( name , head ));
    }
    person* get()
    {
       person* n = head;
       head->next->last = NULL;
       head=head->next;
       return n;
    }
    ~que()
    {
        while (head)
            dell( head );
    }
};

int main()
{
    que hospital;
    hospital.push( "Vasia Ivanov", 10.10);
    hospital.push( "Mariy Gerasimovna",11.30);
    hospital.push("Anonimus",13.44);
    hospital.push( "Anatoliy Borisovich", 14.15 );
    hospital.exit("Mariy Gerasimovna");
    for (;;){
     person* x = hospital.get();
     if (x)
            break;
     cout<<x->name<<' '<<x->time<<endl;
    }
}
