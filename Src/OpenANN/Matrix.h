#pragma once
#include <vector>

using namespace std;

class Matrix
{
public:
	/// <summary>
	/// Initializes a new instance of the <c cref="Matrix" /> class.
	/// </summary>
	/// <param name="numRows">The number of rows in matrix.</param>
	/// <param name="numCols">The number of columns in matrix.</param>
	/// <param name="isRandom">if set to <c>true</c> initializes the matrix with random numbers. Else all cells will be zero.</param>
	Matrix(int numRows, int numCols, bool isRandom);

	/// <summary>
	/// Transposes current matrix.
	/// </summary>
	/// <returns>A new Matrix which is transpose of current matrix.</returns>
	Matrix* transpose() const;

	/// <summary>
	/// Prints to console values of matrix.
	/// </summary>
	void printToConsole();

	/// <summary>
	/// Sets the value for given row and column with given value.
	/// </summary>
	/// <param name="rowIndex">Index of the row.</param>
	/// <param name="columnIndex">Index of the column.</param>
	/// <param name="value">The value to set.</param>
	void setValue(int rowIndex, int columnIndex, double value) { values.at(rowIndex).at(columnIndex) = value; }

	/// <summary>
	/// Gets the value of cell with given row and column index.
	/// </summary>
	/// <param name="rowIndex">Index of the row.</param>
	/// <param name="columnIndex">Index of the column.</param>
	/// <returns>Teh value of specified cell.</returns>
	double getValue(int rowIndex, int columnIndex) const { return values.at(rowIndex).at(columnIndex); }

	/// <summary>
	/// Gets the number of rows.
	/// </summary>
	/// <returns></returns>
	int getNumberOfRows() const	{return numRows;}

	/// <summary>
	/// Gets the number of columns.
	/// </summary>
	/// <returns></returns>
	int getNumberOfColumns() const	{return numCols;}

private:
	int numRows;
	int numCols;

	double generateRandomNumber() noexcept;

	vector<vector<double>> values;

};

