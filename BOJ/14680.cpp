#include <iostream>
using namespace std;
typedef long long ll;

class Matrix
{
    private:
        ll row;
        ll col;
        ll** matrix;
    public:
        void test() const;
        Matrix();
        Matrix(ll row, ll col);
        Matrix(const Matrix& M);
        ~Matrix();
        ll getRow() const;
        ll getCol() const;
        ll** getMatrix() const;
        void load();
        void load(ll** M);
        void printSum() const;
        void operator=(const Matrix& M);
        friend Matrix operator*(const Matrix& left, const Matrix& right);
};

void Matrix::test() const
{
    for (ll r = 0; r < row; r++)
    {
        for (ll c = 0; c < col; c++)
        {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix::Matrix()
: row(0), col(0), matrix(0)
{
}

Matrix::Matrix(ll row, ll col)
: row(row), col(col)
{
    matrix = new ll*[row];
    for (ll i = 0; i < row; i++)
    {
        matrix[i] = new ll[col];
    }
}

Matrix::Matrix(const Matrix& M)
: row(M.getRow()), col(M.getCol())
{
    (this->matrix) = new ll*[row];
    for (ll i = 0; i < row; i++)
    {
        matrix[i] = new ll[col];
    }

    for (ll r = 0; r < row; r++)
    {
        for (ll c = 0; c < col; c++)
        {
            matrix[r][c] = (M.getMatrix())[r][c];
        }
    }
}

Matrix::~Matrix()
{
    for (ll i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

ll Matrix::getRow() const
{
    return row;
}

ll Matrix::getCol() const
{
    return col;
}

ll** Matrix::getMatrix() const
{
    return matrix;
}

void Matrix::load()
{
    for (ll r = 0; r < row; r++)
    {
        for (ll c = 0; c < col; c++)
        {
            cin >> matrix[r][c];
        }
    }
}

void Matrix::load(ll** M)
{
    for (ll r = 0; r < row; r++)
    {
        for (ll c = 0; c < col; c++)
        {
            (this->matrix)[r][c] = M[r][c];
        }
    }
}

void Matrix::printSum() const
{
    ll tempSum = 0;
    for (ll r = 0; r < row; r++)
    {
        for (ll c = 0; c < col; c++)
        {
            tempSum += matrix[r][c];
            tempSum %= static_cast<ll>(1000000007);
        }
    }
    cout << tempSum;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
    ll tempRow = left.getRow(), tempCol = right.getCol();
    ll** tempMatrix = new ll*[tempRow];
    for (ll i = 0; i < tempRow; i++) tempMatrix[i] = new ll[tempCol];

    for (ll r = 0; r < tempRow; r++)
    {
        for (ll c = 0; c < tempCol; c++)
        {
            ll tempSum = 0;
            for (ll k = 0; k < left.col; k++)
            {
                tempSum += (left.matrix[r][k] * right.matrix[k][c]);
            }
            tempSum %= 1000000007;
            tempMatrix[r][c] = tempSum;
        }
    }

    Matrix temp(tempRow, tempCol);
    temp.load(tempMatrix);
    for (ll i = 0; i < tempRow; i++) delete[] tempMatrix[i];
    delete[] tempMatrix;

    return temp;
}

void Matrix::operator=(const Matrix& M)
{
    this->row = M.getRow();
    this->col = M.getCol();
    this->matrix = new ll*[this->row];
    for (ll i = 0; i < this->row; i++) (this->matrix)[i] = new ll[this->col];
    
    for (ll r = 0; r < this->row; r++)
    {
        for (ll c = 0; c < this->col; c++)
        {
            (this->matrix)[r][c] = (M.getMatrix())[r][c];
        }
    }
}

int main()
{
    ll N;
    cin >> N;

    Matrix* matrices = new Matrix[N];

    for (ll i = 0; i < N; i++)
    {
        ll tempRow, tempCol;
        cin >> tempRow; cin >> tempCol;

        Matrix temp(tempRow, tempCol);
        temp.load();

        matrices[i] = temp;
    }

    Matrix result(matrices[0]);

    for (ll i = 1; i < N; i++)
    {
        if (result.getCol() != matrices[i].getRow())
        {
            cout << -1;
            return 0;
        }
        else
        {
            //cout << i << "th iteration test" << endl;
            //result.test();
            //matrices[i].test();
            result = result * matrices[i];
        }
    }

    result.printSum();

    delete[] matrices;
    return 0;
}