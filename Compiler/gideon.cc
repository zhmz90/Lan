#include <iostream>


using namespace std;

int main(int argc ,char* argv[]){
  cout<<endl;
  cout<<"\033[1;32m       Hello, I am Gideon, an interactive artificial consciousness.\033[0m"<<endl;
  cout<<"You can communicate with me via text now."<<endl;
  cout<<endl;
  cout<<"\033[1;32mGideon>\033[0m";
  string c;
  while (true){
    cin>>c;
    cout<<"\033[1;32mGideon>\033[0m"<<c<<endl;
    cout<<"\033[1;32mGideon>\033[0m";
  }
  

  return 0;
}
