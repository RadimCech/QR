#include "Math.hpp"


unsigned int Math::SwapEndianness(unsigned int x)
{
    unsigned char *ptr = (unsigned char *) &x;
    return (unsigned int)(ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
}


std::vector<DataMatrix*> Math::HouseHolderBidiagonalization(DataMatrix* matrix) 
{
    DataMatrix* G;
    DataMatrix* H;
    //A = UBV^T
    DataMatrix* U = LeftHouseholder(matrix,0);// = new DataMatrix(matrix->getRows(), matrix->getColumns());
    DataMatrix* B = new DataMatrix(matrix);
    DataMatrix* V = RightHouseholder(matrix,0);
    //first iteration
 
    G = Math::MultiplyByLeftHouseholder(U,B);

    delete B;
    B = G;

    B->print();

    G = Math::MultiplyByRightHouseholder(B,V);
    delete B;
    B = G;  
    //B = U*B



    for(int k = 1; k < matrix->getColumns()-1; k++)
    {
        G = Math::LeftHouseholder(B,k);

        //B := G*B
        H = Math::MultiplyByLeftHouseholder(G, B, 'd');
        delete B;
        B = H;

        //U := U*G
        H = Math::MultiplyByRightHouseholder(U, G);
        delete U;
        U = H;

        if(k<matrix->getColumns()-2)
        {
        G = Math::RightHouseholder(B, k);

        //B := B*G
        H = Math::MultiplyByRightHouseholder(B, G, 'd');
        delete B;
        B = H;

        //V := G*V
        H = Math::MultiplyByLeftHouseholder(G,V);
        delete V;
        V = H;
        }
    }
    std::vector<DataMatrix*> output(3,0);

    output.at(0) = U;
    output.at(1) = B;
    output.at(2) = V;

    return output;
}

//return the k-th Q matrix without the identity submatrix
DataMatrix* Math::LeftHouseholder(DataMatrix* A, int k) 
{
    DataMatrix* Q = new DataMatrix(A->getRows()-k, A->getColumns()-k);
    DataVector* u = new DataVector(A->getRows()-k);

    double euclidNorm = 0;


    for(int i = 0; i < A->getRows()-k; i++) //u := kth column of A without the first k rows
    {
        u->getElement(i) = A->getElement(k+i, k);
        euclidNorm = euclidNorm + A->getElement(k+i,k) * A->getElement(k+i, k);
    }

    if(u->getElement(0)<0)
    u->getElement(0) += sqrt(euclidNorm); //subtract the norm of u from the first coordinate
    else 
    u->getElement(0) -= sqrt(euclidNorm);

    //Math::Normalize(u);
    
    //assemble Q
    Q = Math::OuterProduct(u);
    Q->scalarMultiply(-2 / Math::GetNorm2(u));

    for(int i = 0; i< u->getDimension(); i++)
    {
        Q->getElement(i,i) += 1;
    }

    return Q;
}

//return the k-th P matrix without the identity submatrix
DataMatrix* Math::RightHouseholder(DataMatrix* A, int k) 
{
    DataMatrix* P = new DataMatrix(A->getRows()-k, A->getColumns()-k);
    DataVector* u = new DataVector(A->getRows()-k);

    float euclidNorm = 0;


    for(int i = 0; i < A->getColumns()-k; i++) //u := kth column of A without the first k rows
    {
        u->getElement(i) = A->getElement(k, k+i+1);
        euclidNorm += A->getElement(k,k+i+1);
    }

    u->getElement(0) -= sqrt(euclidNorm); //subtract the norm of u from the first coordinate
    Math::Normalize(u);

    //assemble p
    P = Math::OuterProduct(u);
    P->scalarMultiply(-2);

     
    for(int i = 0; i< u->getDimension(); i++)
    {
        P->getElement(i,i) += 1;
    }

    return P;
}


DataMatrix* Math::MultiplyByLeftHouseholder(DataMatrix* A, DataMatrix* B, char c ) //B := A*B
{

    int k = B->getRows() - A->getColumns(); 

    //d for diagonal
    int m = 0;
    if(c == 'd') m = k;

    DataMatrix* C = new DataMatrix(A->getRows(), B->getColumns());
  
    for(int i = k; i < B->getRows(); i++)   //lze preskocit k radku
    {
        
        for(int j = m; j< B->getColumns(); j++) //pokud je cast B v diagonalnim tvaru lze preskocit k sloupcu
        {

            float a = 0;
            //tady se dejou hrozne veci
            for(int l = k; l<B->getRows(); l++) //mozna bug
            {

                a += A->getElement(i, l)+B->getElement(l, j); 
            }

            (C->getElement(i,j)) = a;
        }
    }

    return C;
}

DataMatrix* Math::MultiplyByRightHouseholder(DataMatrix* A, DataMatrix* B, char c) //B := A*B
{

    int k = A->getRows(); 

    //d for diagonal 
    int m = 0;
    if(c == 'd') m = k;

    DataMatrix* C = new DataMatrix(A->getRows(), B->getColumns());
  
    for(int i = m; i < B->getRows(); i++)
    {
        
        for(int j = k; j< B->getColumns(); j++) //nasobi se ty submatice jenom jakoby zacne se od k vsude
        {

            float a = 0;
            //tady se dejou hrozne veci
            for(int l = k; l<B->getRows(); l++) //mozna bug
            {

                a += A->getElement(i, l)+B->getElement(l, j); 
            }

            (C->getElement(i,j)) = a;
        }
    }

    return C;
}


DataMatrix* Math::NaiveMatrixMultiply(DataMatrix* A, DataMatrix* B) //return C := A*B
{
    if(A->getColumns()!=B->getRows())
    {
        printf("je to v pici");
        return NULL;
    }

    DataMatrix* C = new DataMatrix(A->getRows(), B->getColumns());
    //check if sizes are alright
  
    for(int i = 0; i < B->getRows(); i++)
    {

        for(int j = 0; j< B->getColumns(); j++)
        {

            char b = 0;
            //tady se dejou hrozne veci
            for(int k = 0; k<B->getRows(); k++)
            {

                b += A->getElement(i, k)+B->getElement(k, j);
            }

            (C->getElement(i,j)) = b;
        }
    }

    return C;
}

DataMatrix* Math::OuterProduct(DataVector* u)
{
    unsigned int dimension = u->getDimension();

    DataMatrix* matrix = new DataMatrix(dimension, dimension);
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j<dimension; j++)
        {
            matrix->getElement(i,j) = u->getElement(i)*u->getElement(j);
        }
    }
    return matrix;
}

//norm squared
double Math::GetNorm2(DataVector* v)
{
    

    double sum = 0;
    for(int i = 0; i < v->getDimension(); i++)
    {
        sum += v->getElement(i)*v->getElement(i);
    }
    return sum;
}


double Math::GetNorm(DataVector* v)
{
    

    double sum = 0;
    for(int i = 0; i < v->getDimension(); i++)
    {
        sum += v->getElement(i)*v->getElement(i);
    }
    return sqrt(sum);
}

void Math::Normalize(DataVector* v) //overrides original vector
{
    double norm = GetNorm(v);

    norm = 1/norm;
    v->scalarMultiply(norm);
}


int main()
{

    DataMatrix* A = new DataMatrix(3,3);
    float pole[9] = {12, -51, 4, 6, 167, -68, -4, 24, -41};

    for(int i = 0; i<A->getRows(); i++)
    {
        for(int j = 0; j<A->getColumns(); j++)
        {
            A->getElement(i,j) = pole[i*3+j];
        }
    }
    A->print();
    printf("\n");
    
    std::vector<DataMatrix*> UBV = Math::HouseHolderBidiagonalization(A);
    // printf("\n\n\n\n");
    // printf("A\n");
    // A->print();
    // printf("V\n");
    // UBV.at(0)->print();
    // printf("B\n");
    // UBV.at(1)->print();
    // printf("V transposed\n");
    // UBV.at(2)->print();



}