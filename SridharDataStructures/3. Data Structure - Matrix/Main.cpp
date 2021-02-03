#include "MatrixClass.h"

MatrixClass<double> operator* (MatrixClass<double>& matA, MatrixClass<double>& matB)
{
	if (matA.columns() != matB.rows()) throw MatrixIncompatibleException();
	MatrixClass<double> matC(matA.rows(), matB.columns(), 0.0);

	for (int i = 0; i < matC.rows(); i++) 
	{
		for (int j = 0; j < matC.columns(); j++)
		{
			for (int k = 0; k < matA.columns(); k++)
			{
				matC[i][j] = matC[i][j] + matA[i][k] * matB[k][j];
			}
		}
	}
	return matC;
}


int main()
{
	MatrixClass<double> m2x3(2, 3, 0.0);
	MatrixClass<double> m3x2(3, 2, 0.0);
	MatrixClass<double> m2x2;
	MatrixClass<double> m3x3;
	m2x3[0][0] = 1; m2x3[0][1] = 2; m2x3[0][2] = 1;
	std::cout << m2x3[0][0] << " " << m2x3[0][1] << " " << m2x3[0][2] << std::endl;
	m2x3[1][0] = 0; m2x3[1][1] = 1; m2x3[1][2] = 3;
	std::cout << m2x3[1][0] << " " << m2x3[1][1] << " " << m2x3[1][2] << std::endl;

	m3x2[0][0] = 1; m3x2[0][1] = 1;
	std::cout << m3x2[0][0] << " " << m3x2[0][1] << std::endl;
	m3x2[1][0] = 0; m3x2[1][1] = 1;
	std::cout << m3x2[1][0] << " " << m3x2[1][1] << std::endl;
	m3x2[2][0] = 1; m3x2[2][1] = 1;
	std::cout << m3x2[2][0] << " " << m3x2[2][1] << std::endl;


	m2x2 = (m2x3 * m3x2);
	std::cout << m2x3 << " * " << m3x2 << " = " << m2x2;
	m3x3 = m3x2 * m2x3;
	std::cout << m3x2 << " * " << m2x3 << " = " << m3x3;
}