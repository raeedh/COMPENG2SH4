public class UpperTriangularMatrix {
    private int matrixSize;
    private int[] effMatrixData;

    public UpperTriangularMatrix(int n) {
        if (n <= 0) {
            matrixSize = 1;
        }
        else {
            matrixSize = n;
        }
        effMatrixData = new int[(matrixSize*(matrixSize+1))/2];
    }

    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{
        int k = 0; // index of array counting efficient representation of upper triangular matrix
        if (upTriM.isUpperTr()) { //
            matrixSize = upTriM.getRowsNum();
            effMatrixData = new int[(matrixSize*(matrixSize+1))/2];
            for (int i = 0; i < matrixSize; i++) {
                for (int j = i; j < matrixSize; j++) {
                    effMatrixData[k] = upTriM.getElement(i, j);
                    k++;
                }
            }
        }
        else {
            throw new IllegalArgumentException("The matrix is not upper triangular.");
        }
    }

    public int getDim() {
        return matrixSize;
    }

    public int getElement(int i, int j) throws IndexOutOfBoundsException {
        if (i < matrixSize && j < matrixSize) {
            if (j < i) {
                return 0; // if below diagonal, return 0
            }
            else {
                return effMatrixData[(2*matrixSize+1-i)*i/2+j-i];
            }
        }
        else {
            throw new IndexOutOfBoundsException("Invalid index");
        }
    }

    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException {
        if (i < matrixSize && j < matrixSize && j >= i) { // checks if in or above diagonal
            effMatrixData[(2*matrixSize+1-i)*i/2+j-i] = x;
        }
        else if (i < matrixSize && j < matrixSize && x != 0) { // checks if trying to change element under diagonal to non-zero value
            throw new IllegalArgumentException("Incorrect Argument");
        }
        else {
            throw new IndexOutOfBoundsException("Invalid indexes");
        }
    }

    public Matrix fullMatrix() {
        Matrix fullUpTriM = new Matrix(matrixSize, matrixSize);
        int k = 0; // index of array of efficient representation of triangular matrix
        for (int i = 0; i < matrixSize; i++) {
            for (int j = i; j < matrixSize; j++) {
                fullUpTriM.setElement(effMatrixData[k], i, j); // sets element of matrix using method from class
                k++;
            }
        }
        return fullUpTriM;
    }

    public void print1DArray() {
        for (int element : effMatrixData) { // for loop for elements in array
            System.out.print(element + "  ");
        }
    }

    public String toString() {
        return this.fullMatrix().toString();
    } // creates a full matrix then using toString method from matrix class

    public int getDet() {
        int det = 1;
        for (int i = 0; i < matrixSize; i++) {
            det *= effMatrixData[(2*matrixSize+1-i)*i/2];
        }
        return det;
    }

    /*
    The efficient solve works by doing backward substitution.
    Begins at the last row of full matrix and iterates through each row
    b assigns value of x
    For each row, subtracts value of corresponding x multipled by coefficient in A from b, until you reach diagonal
    At the diagonal, divide b by coefficient of A
    */

    public double[] effSolve(double [] b) throws IllegalArgumentException {
        if (b.length != matrixSize) { // checks if matrix A and b have the number of rows
            throw new IllegalArgumentException("The dimensions of the matrices do not match.");
        }
        if (getDet() != 0) {
            double[] effSolution = new double[matrixSize];
            for (int i = (matrixSize-1); i >= 0; i--) { // iterates through full matrix from bottom
                effSolution[i] = b[i]; // stores value from b to solution of same row
                for (int j = (matrixSize-1); j >= i; j--) {
                    if (j == i) {
                        effSolution[i] = effSolution[i] / effMatrixData[(2*matrixSize+1-i)*i/2+j-i]; // if on diagonal, divides x at index by value of A
                    }
                    else {
                        effSolution[i] = effSolution[i] - effSolution[j]*effMatrixData[(2*matrixSize+1-i)*i/2+j-i]; // if not in diagonal, subtract coefficient in A * solved value of x to current value of x
                    }
                }
            }
            return effSolution;
        }
        else {
            throw new IllegalArgumentException("Matrix is non-invertible.");
        }
    }
}
