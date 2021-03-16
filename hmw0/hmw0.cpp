using namespace std;
#include <stdio.h>
#include <sys/time.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

int rand_num(int min, int max)
{
    return rand() % max + min;
}

int eight_bit(){
  struct timeval tstart, tend,tdiff;
  int iterations = 0;
  unsigned int r = 0;
  unsigned int m = 0;
  unsigned int n = 0;

  cout<<"8 bit :" << endl;
  for(int i = 0; i < 20; ++i){
    m = rand_num(0, 255);
    n = rand_num(0, 255);
    iterations = 1;
    if (m<n) {
        r = m;
        m = n;
        n = r;
    }
    r = 2;
    cout << "m =" << m << " n= " << n << endl;
    gettimeofday(&tstart,NULL);
    while (r != 0) {
        r = m % n;
    cout << "m =" << m << " n= " << n  << " r= " << r << endl;
        m = n;
        n = r;
        ++iterations;
    }
    gettimeofday(&tend,NULL);
    timersub(&tend, &tstart, &tdiff);
    cout<< "Time " << tdiff.tv_sec << "." << tdiff.tv_usec << " Iteration: " << iterations << endl;
  }
}

int main(){
  srand(time(0));
  eight_bit();
}


