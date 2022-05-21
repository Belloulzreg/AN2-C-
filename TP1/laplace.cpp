//This code solves laplace equation for an electrical potential in 2 Dimensions with constant boundary conditions using the centered finite differences method, the result of the calculation is then saved into 
//A DAT file afterwards we plot the results using gnuplot software.
#include<iostream>
#include<fstream>
int main(){
  const int size = 40;//This will be the size of the grid for the numerical method
  const int num_iter = 500; //The number of iterations that will be preformed 
  double potl[size][size]; //Electrical potential 
  std::ofstream outfile("laplace.dat"); //creates an output file 
  //Setting up the boundary conditions 
  for (int i=0;i<size;i++){//Top edge is at 100 V
  ptl[i][0] = 100.0;
  }
  for (int j=1;i<size;i++){//The rest is zero V
  ptl[i][j] = 0.0;
  }
  for(int iter=0;iter<num_iter;iter++){//iterations 
    for(int i=1;i<(size-1);i++){//x-direction
      for(int j=1;j<(size-1);j++){//y-direction
        potl[i][j] = 0.25* (potl[i-1][j] +potl[i+1][j]+potl[i][j+1] +potl[i][j-1]):        
      }    
    }  
  }
  
  //Write data in a gnuplot 3D format 
  for(int i=0; i<size;i++){
    for(int j=0;j<size;j++){
    outfile <<potl[i][j] <<std::endl; //gnuplot grid format 
    }
    outfile << std::endl; //empty line for gnuplot 
  }
  std::cout << std::endl<< "Data stored in laplace.dat" <<std::endl;
  outfile.close();
return(0);
}
