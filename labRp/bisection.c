#include <stdio.h>
#include <math.h>

// Function to evaluate the equation
double func(double x) {
    return x * x - 4; // Replace this with your actual equation
}

// Function to calculate the derivative of the equation
double derivative(double x) {
    return 2 * x; // Replace this with the derivative of your equation
}

int main() {
    double x0, x1, f, fprime, epsilon, numIterations;

    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    // printf("Enter the allowed error: ");
    // scanf("%lf", &epsilon);

    printf("Enter the maximum number of iterations: ");
    scanf("%lf", &numIterations);

    for (int i = 0; i < numIterations; ++i) {
        // Check for division by zero
        if (fabs(derivative(x0)) < epsilon) {
            printf("Error: Derivative is zero at x = %lf\n", x0);
            return 1;
        }

        f = func(x0);
        fprime = derivative(x0);

        // Update x using the Newton-Raphson formula
        x1 = x0 - f / fprime;

        printf("Iteration %d: x = %lf\n", i + 1, x1);

        // Check for convergence
        if (fabs(x1 - x0) < epsilon) {
            printf("Root found at x = %lf\n", x1);
            return 0;
        }

        x0 = x1;
    }

    printf("Failed to converge after %d iterations\n", (int)numIterations);
    return 1;
}
