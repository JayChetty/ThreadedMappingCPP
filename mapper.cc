#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

class Mapper{
private:
  static const int length = 10000000;
 
  double my_array[length];

  double ex_op(double in, int num_times){
    double out = in;
    int i = 0;
    while(i<num_times){
      out = sqrt(out)* 2.123;
      i++;
    }
    return out;
  };

public:

  void set_up_array(){
    for(int i = 0; i < Mapper::length; i++){
      my_array[i] = i;
    }
  }

  void map_array(){
    time_t start = time(0);
    for(int i = 0; i < Mapper::length; i++){
      my_array[i] = ex_op(my_array[i], 50);
    }
    time_t end = time(0);
    double time = difftime(end, start);
    cout << "Time taken " << time << " seconds \n";
  }

  double sum_array(){
    double sum = 0;
    for(int i = 0; i < Mapper::length; i++){
      sum = sum + my_array[i];
    }
    return sum;   
  }
};

int main(){
  Mapper* p = new Mapper();
  p->set_up_array();
  p->map_array();
  cout << "Sum is " << p->sum_array() << "\n";
}