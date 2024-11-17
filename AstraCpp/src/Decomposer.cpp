#include "pch.h"

#include "Matrix.h"
#include "Exceptions.h"
#include "Decomposer.h"

using namespace astra;

Decomposer::PLUResult Decomposer::palu(Matrix A) {
    int m = A.num_row();

    // matrix is not square
    if (m != A.num_col()) {
        throw astra::internals::exceptions::non_sqauare_matrix();
    }

    Matrix P = Matrix::identity(m);
    Matrix L = Matrix::identity(m);
    Matrix U = A;
    int swaps = 0;

    for (int x = 0; x < m; x++) {
        int pivot_row = x; 
        
        // finding the largest value in the column and selecting it as the pivot
        for (int y = x; y < m; y++) {
            if (abs(U(y, x)) > abs(U(pivot_row, x))) {
                pivot_row = y;
            }
        }

        if (U(pivot_row, x) == 0) {
            // all values in the column are zero so we need to skip this column
            continue;
        }

        if (pivot_row != x) {
            // pivot is not in the diagonal so we need to
            // swap rows
            U.row_swap(x, pivot_row); // swaping U 
            P.row_swap(x, pivot_row); // swaping P
            L.partial_row_swap(x, pivot_row, x); // partial swapping L till diagonal
            swaps++;
        }

        // TODO: eliminate entries below the pivot
        for (int y = x + 1; y < m; y++) {
            double current_val = U(y, x);

            if (current_val == 0) {
                continue; // it is already eliminated
            }

            double pivot = U(x, x);
            double factor = current_val / pivot;



        }


    }




    Decomposer::PLUResult res(3);
    return res;
}
