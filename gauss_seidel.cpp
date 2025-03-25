#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to implement Gauss-Seidel Iteration
void gaussSeidel(vector<vector<double>> &A, vector<double> &b, vector<double> &x, int maxIterations, double tolerance) {
    int n = A.size();
    
    for (int iter = 0; iter < maxIterations; iter++) {
        double error = 0.0;
        
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];  // Use updated values when available
                }
            }
            
            double new_x = (b[i] - sum) / A[i][i];
            error = max(error, fabs(new_x - x[i]));  // Compute error
            x[i] = new_x;  // Update x value
        }

        // Print intermediate results
        cout << "Iteration " << iter + 1 << ": ";
        cout << fixed << setprecision(6);
        for (double val : x) {
            cout << val << " ";
        }
        cout << endl;

        // Stop if the solution has converged
        if (error < tolerance) {
            cout << "Converged in " << iter + 1 << " iterations." << endl;
            return;
        }
    }

    cout << "Did not converge within " << maxIterations << " iterations." << endl;
}

int main() {
    int n = 3;  // Number of variables
    vector<vector<double>> A = {
        {10, -1, 2},
        {-1, 10, -2},
        {2, -2, 10}
    };
    vector<double> b = {6, 2, 3};  // Right-hand side
    vector<double> x(n, 0.0);  // Initial guess (all zeros)

    int maxIterations = 100;
    double tolerance = 1e-6;

    cout << "Solving system using Gauss-Seidel Iteration..." << endl;
    gaussSeidel(A, b, x, maxIterations, tolerance);

    cout << "Final Solution: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
