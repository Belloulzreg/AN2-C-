#include <iostream>
#include <fstream>
int main()
{
const double length = 150.;     // length in cm
const int size = 151;     // grid size
const int num_steps = 30000;     // number of timesteps
const double conductivity = 0.12;    // units: (cal/s cm degree C)
const double specific_heat = 0.113;  // units: (cal/ g degree C)
const double rho = 7.8;     // density in (g/cm^3)
double T[size][2];     // temperature at x and two times
std::ofstream outfile("eqheat.dat"); // open an output file stream
double delta_x = length/double(size-1); // mesh spacing in x
for (int i = 0; i < size; i++)
{
T[i][0] = 100.; // at t=0, all points are at 100 C
}
for (int j = 0; j < 2; j++) // except the endpoints, which are 0 C
{
T[0][j] = T[size-1][j] = 0.;
}
double constant = conductivity / (specific_heat*rho) / (delta_x*delta_x);
for (int i = 1; i <= num_steps; i++) // loop over num_steps timesteps
{
for (int j = 1; j < (size - 1); j++) // loop over space
{
T[j][1] = T[j][0]
+ constant * (T[j+1][0] + T[j-1][0] - 2.0 * T[j][0]);
}
if ((i % 1000 == 0) || (i == 1)) // save every 1000 time steps
{
for (int j = 0; j < size; j++)
{
outfile << T[j][1] << std::endl; // gnuplot 3D grid format
}
outfile << std::endl; // empty line for gnuplot
}
for (int j = 0; j < size; j++)
{
T[j][0] = T[j][1]; // shift new values to old
}
}
std::cout << std::endl << "data stored in eqheat.dat" << std::endl;
outfile.close ();
return (0);
