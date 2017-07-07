#include <iostream>


using namespace std;

class Color{
  
};

class Console{
 public:
  Console()=default;
  Console(Color c){
  }
  

 private:
  Color color;
  std::string welcome;
};


int main(int argc ,char* argv[]){
  cout<<"\033[1;32m";
  cout<<endl<<endl;
  cout<<"       Hello, I am Gideon, an interactive artificial consciousness."<<endl;
  cout<<"You can communicate with me via text now."<<endl;
  cout<<endl;
  cout<<"\033[0m";
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
