#include <iostream>
#include <map>

using namespace std;

multimap<int,int> canicas;
multimap<int,int>::iterator it;
int numCanicas, numConsulta;

int etiqueta,consulta;

void positionsCorrect(){
    int count = 1;
    for (auto &item : canicas) {
        item.second = count;
        ++count;
    }
}

int main(){
    int cases = 1;
    while(cin>>numCanicas>>numConsulta, numCanicas){
        for (int i = 1; i <= numCanicas; ++i) {
            cin>>etiqueta;
            canicas.emplace(etiqueta,0);
        }

        positionsCorrect();
        cout<<"CASE# "<<cases<<":"<<endl;

        for (int j = 1; j <= numConsulta; ++j) {
            cin>>consulta;
            it = canicas.find(consulta);

            if(it == canicas.end()) cout<<consulta<<" not found"<<endl;
            else cout<<consulta<<" found at "<<it->second<<endl;
        }
        canicas.clear();
        ++cases;
    }


}
