#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<math.h>
// int fact(int a);


using namespace std;

int main()
{
    int a;

    cout << "Please enter a number: ";
    cin >> a;

    int factorial = a;

    for(int i = 1; i<= a; i++){
      factorial = factorial*i;
    }

    cout << "The factorial of " << a  << "! is: " << factorial << endl;
    return 0;
}


/*
int main(){
  int a;
  int F=1;
  int i;
  std::cout<<"numero: "<< std::cin >> a;
  if(a<0) {F =0;}
  else if (a==0) {F=1;}
  else {
    for (i = 1;i<= a; i++){
      F = F*i;
    }
  }
  std::cout <<"Factorial de" << a << "es " << F << std::endl;
  return 0;
 
  }*/
/*
int fact(int a){
  
  int F=1;
  for(int i=1; i<= a; i++){
    F=F*i;
  }
  return F;
}
*/


