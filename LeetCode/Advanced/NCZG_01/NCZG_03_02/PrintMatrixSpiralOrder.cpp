#include <iostream>
#include <vector>
using namespace std;

class PrintMaxtrixSpiralOrder
{
public:
	void spiralOrderPrint(const vector<vector<int>>& matrix);
	

private:
	void printEdge(const vector<vector<int>>& matrix, int topRow, int topColumn, int downRow, int downColumn);

	int m_topRow;
	int m_topColumn;
	int m_downRow;
	int m_downColumn;
};

void PrintMaxtrixSpiralOrder::spiralOrderPrint(const vector<vector<int>>& matrix)
{
	m_topRow = 0;
	m_topColumn = 0;
	m_downRow = matrix.size() - 1;
	m_downColumn = matrix[0].size() - 1;

	while (m_topRow <= m_downRow && m_topColumn <= m_downColumn)
		printEdge(matrix, m_topRow++, m_topColumn++, m_downRow--, m_downColumn--);
	

	return;
}

void PrintMaxtrixSpiralOrder::printEdge(const vector<vector<int>>& matrix, int topRow, int topColumn, int downRow, int downColumn)
{
	if (topRow == downRow)
		for (int i = topColumn; i <= downColumn; i++)
			cout << matrix[topRow][i] << " ";
	else if (topColumn == downColumn)
		for (int i = topRow; i < downRow; i++)
			cout << matrix[topColumn][i] << " ";

	int curRow = topRow;
	int curColumn = topColumn;
	while (curColumn < downColumn)
		cout << matrix[curRow][curColumn++] << " ";
	while (curRow < downRow)
		cout << matrix[curRow++][curColumn] << " ";
	while (curColumn > topColumn)
		cout << matrix[curRow][curColumn--] << " ";
	while (curRow > topRow)
		cout << matrix[curRow--][curColumn] << " ";
	

	return;
}

//int main()
//{
//	vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, 
//	{ 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
//
//	PrintMaxtrixSpiralOrder pmsOrder;
//	pmsOrder.spiralOrderPrint(matrix);
//
//	return -1;
//}