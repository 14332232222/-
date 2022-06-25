#include<iostream>
using namespace std;
//ϡ�����
class SparseMatrix;

//����Ԫ������
class MatrixTerm
{
	friend class SparseMatrix;
private:
	int row, col, value;
};

class SparseMatrix
{
private:
	//������������������
	int rows, cols, terms;
	MatrixTerm* smArray;

public:
	//���캯��1
	SparseMatrix(int r, int c, int t, int rs[], int cs[], int vs[]);

	//���캯��2
	SparseMatrix(int r, int c, int t);

	//Ĭ�Ϲ��캯��
	SparseMatrix();

	//ת�þ���
	SparseMatrix Transpose();


	//����=�ţ���������
	const SparseMatrix& operator=(const SparseMatrix& temp);

	//�����ӡ
	void S_Show();
};

SparseMatrix::SparseMatrix(int r, int c, int t, int rs[], int cs[], int vs[])
{
	rows = r;
	cols = c;
	terms = t;
	smArray = new MatrixTerm[terms];

	for (int i = 0; i < terms; i++)
	{
		smArray[i].row = rs[i];
		smArray[i].col = cs[i];
		smArray[i].value = vs[i];
	}
}

SparseMatrix::SparseMatrix(int r, int c, int t)
{
	rows = r;
	cols = c;
	terms = t;
	if (terms > 0)
		smArray = new MatrixTerm[terms];
	else smArray = NULL;
}

SparseMatrix::SparseMatrix()
{
	rows = 0;
	cols = 0;
	terms = 0;
	smArray = NULL;
}

SparseMatrix SparseMatrix::Transpose()
{
	cout << "ת�þ���" << endl;

	if (terms > 0)
	{
		SparseMatrix result(cols, rows, terms);
		int bPos = 0;

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < terms; j++)
			{
				//�ҵ�smArray��col����i
				if (smArray[j].col == i)
				{
					result.smArray[bPos].row = i;
					result.smArray[bPos].col = smArray[j].row;
					result.smArray[bPos++].value = smArray[j].value;
				}
			}
		}

		return result;
	}
	else return *this;
}


const SparseMatrix& SparseMatrix::operator=(const SparseMatrix& temp)
{
	cols = temp.cols;
	rows = temp.rows;
	terms = temp.terms;

	if (smArray != NULL)
		delete[]smArray;

	if (terms > 0)
	{
		smArray = new MatrixTerm[terms];
		copy(temp.smArray, temp.smArray + terms, smArray);
	}
	else smArray = NULL;

	return *this;
}

void SparseMatrix::S_Show()
{
	if (rows > 0 && cols > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << "[";
			for (int j = 0; j < cols; j++)
			{
				int out = 0;
				for (int t = 0; t < terms; t++)
				{
					if (smArray[t].row == i && smArray[t].col == j)
					{
						out = smArray[t].value;
					}
				}
				cout << out << "\t";
			}
			cout << "]\n";
		}
	}
	else cout << "[ ]\n";
	cout << "ϡ�������Ϣ��\n������" << rows << "\t������" << cols << "\t����������" << terms << endl << endl;
}

int main()
{
	int rs1[7] = { 0,0,1,1,3,5,7 }, rs2[10] = { 0,0,0,1,3,4,6,6,6,7 };
	int cs1[7] = { 1,2,4,7,5,3,4 }, cs2[10] = { 0,3,8,4,2,5,2,4,7,6 };
	int vs1[7] = { 20,11,23,45,13,6,16 }, vs2[10] = { 23,12,55,13,56,13,15,46,24,66 };

	SparseMatrix a(8, 9, 7, rs1, cs1, vs1), b(8, 9, 10, rs2, cs2, vs2), c;
	a.S_Show();
	b.S_Show();

	c = a.Transpose();
	c.S_Show();

	return 0;
}
