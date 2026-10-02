#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void print_Matrix(const vector<vector<int>>& matrix) {
    	for (size_t i = 0; i < matrix.size(); i++) {
        	for (size_t j = 0; j < matrix[i].size(); j++) {
            		cout << matrix[i][j] << " ";
        	}
        	cout << "\n";
    	}
	cout << "\n";
}

vector<vector<int>> matrix_Addition(
    	const vector<vector<int>>& matrixA, 
    	const vector<vector<int>>& matrixB) 
{
    	int size = matrixA.size();

    	vector<vector<int>> output(size, vector<int>(size, 0));

    	for (int i = 0; i < size; ++i) {
        	for (int j = 0; j < size; ++j) {
            		output[i][j] = matrixA[i][j] + matrixB[i][j];
        	}
    	}

    	return output;
}

vector<vector<int>> matrix_Multiplication(
    	const vector<vector<int>>& matrixA, 
    	const vector<vector<int>>& matrixB) 
{
    	int size = matrixA.size();

    	vector<vector<int>> output(size, vector<int>(size, 0));

    	for (int i = 0; i < size; ++i) {
        	for (int j = 0; j < size; ++j) {
	            	for (int k = 0; k < size; ++k) {
        	        	output[i][j] += matrixA[i][k] * matrixB[k][j];
            		}
        	}
    	}

    	return output;
}

int matrix_Main_Diagonal(const vector<vector<int>>& matrix) {
	int size = matrix.size();

	int sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += matrix[i][i];
	}
	return sum;
}

int matrix_Secondary_Diagonal(const vector<vector<int>>& matrix) {
	int sum = 0;
    	int n = matrix.size();

    	for (int i = 0; i < n; ++i) {
        	sum += matrix[i][n - 1 - i];
    	}

    	return sum;
}

vector<vector<int>> swap_Rows(vector<vector<int>> matrix, int row1, int row2) {
    	if (row1 >= 0 && row1 < matrix.size() && row2 >= 0 && row2 < matrix.size()) {
        	swap(matrix[row1], matrix[row2]);
    	}
    
    	return matrix;
}

vector<vector<int>> swap_Columns(vector<vector<int>> matrix, int col1, int col2) {
    	int size = matrix.size();

    	if (size > 0 && col1 >= 0 && col1 < size && col2 >= 0 && col2 < size) {
        	for (int i = 0; i < size; ++i) {
            		swap(matrix[i][col1], matrix[i][col2]);
        	}
    	}
    
    return matrix;
}

void update_Element(vector<vector<int>>& matrix, int row, int col, int newValue) {
    	if (row >= 0 && row < matrix.size()) {
        	if (col >= 0 && col < matrix[row].size()) {
            		matrix[row][col] = newValue;
        	}
    	}
}

int main() {
	string filename;
	cout << "Enter the filename: ";
	cin >> filename;
	fstream file(filename, ios::in);
    
	// Check if file opened successfully
	if (!file.is_open()) {
		cerr << "Error: Could not open input.txt" << endl;
		return 1;
    	}

    	string sizeString;
    	if (!getline(file, sizeString)) {
        	cerr << "Error: Could not read size." << endl;
        	return 1;
    	}
    
    	int size = stoi(sizeString);

    	vector<vector<int>> matrixA(size, vector<int>(size, 0));
	vector<vector<int>> matrixB(size, vector<int>(size, 0));

	string line;

	// MatrixA input
	for (int i = 0; i < size; i++) {
    		if (getline(file, line)) {
        		std::string lineContent = line;
        		std::istringstream iss(lineContent);
        		int count = 0;
        		int num;
        		while (iss >> num && count < size) {
            			matrixA[i][count++] = num;
        		}
    		}
	}

	// MatrixB input
	for (int i = 0; i < size; i++) {
    		if (getline(file, line)) {
        		std::string lineContent = line;
        		std::istringstream iss(lineContent);
        		int count = 0;
        		int num;
        		while (iss >> num && count < size) {
            			matrixB[i][count++] = num;
        		}
    		}
	}

	file.close();

	cout << "Matrix A:\n";
        print_Matrix(matrixA);
	cout << "Matrix B:\n";
	print_Matrix(matrixB);
	
	vector<vector<int>> output(size, vector<int>(size, 0));

    	// Matrix Addition
	output = matrix_Addition(matrixA, matrixB);

	//addition output
	cout << "A + B:\n";
	print_Matrix(output);

	output = matrix_Multiplication(matrixA, matrixB);
	cout << "A x B:\n";
	print_Matrix(output);

	cout << "Diagonal sums for Matrix A:\n";
	cout << "Main diagonal sum: ";
	cout << matrix_Main_Diagonal(matrixA) << "\n";
	cout << "Secondary diagonal sum: ";
	cout << matrix_Secondary_Diagonal(matrixA) << "\n";
	cout << "\n";

	int row1;
	int row2;
	cout << "Enter first row you want swapped: ";
	cin >> row1;
	cout << "Enter second row you want swapped: ";
	cin >> row2;

	output = swap_Rows(matrixA, row1, row2);
	print_Matrix(output);

        cout << "Enter first column you want swapped: ";
        cin >> row1;
        cout << "Enter second column you want swapped: ";
        cin >> row2;

	output = swap_Columns(matrixA, row1, row2);
	print_Matrix(output);

	int value;

	cout << "Enter first index you want swapped: ";
        cin >> row1;
        cout << "Enter second index you want swapped: ";
	cin >> row2;
	cout << "Enter value you want: ";
	cin >> value;


	update_Element(matrixA, row1, row2, value);
	print_Matrix(matrixA);

    	return 0;
}
