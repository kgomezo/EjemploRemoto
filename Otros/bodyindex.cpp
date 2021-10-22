#include<iostream>

int main()
{
  float bmi, w, h;
  std::cout<<"Please enter your weight in kilograms: ";
  std::cin>>w;
  std::cout<<"Please enter your height in meters: ";
  std::cin>>h;
  bmi= (w/(h*h));
  std::cout<<"Your BMI is: " <<bmi<<std::endl;

  if(bmi>25)
    std::cout<<"Overweight";
  else if (bmi<25 && bmi>18.5)
    std::cout<<"Optimal";
  else
    std::cout<<"Underweight";
  return 0;
}
