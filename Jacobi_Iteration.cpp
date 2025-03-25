#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to implement Jacobi Iteration
void jacobiIteration(vector<vector<double>> &A, vector<double> &b, vector<double> &x, int maxIterations, double tolerance) {
    int n = A.size();
    vector<double> x_new(n, 0.0);  // Store new values of x

    for (int iter = 0; iter < maxIterations; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];  // Jacobi formula
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error = max(error, fabs(x_new[i] - x[i]));
        }

        // Update x values
        x = x_new;

        // Print intermediate results
        cout << "Iteration " << iter + 1 << ": ";
        cout << fixed << setprecision(6);
        for (double val : x) {
            cout << val << " ";
        }
        cout << endl;

        // If the solution has converged, stop iterating
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

    cout << "Solving system using Jacobi Iteration..." << endl;
    jacobiIteration(A, b, x, maxIterations, tolerance);

    cout << "Final Solution: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
