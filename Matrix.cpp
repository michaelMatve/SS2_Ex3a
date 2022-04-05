#include "Matrix.hpp"

zich::Matrix zich::Matrix::operator+()
{
    return *this;
}

zich::Matrix zich::Matrix::operator+(const Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //make new matrix and full the value
    zich::Matrix new_mat{this->number_rows,this->number_colums};
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            new_mat.My_mat[r][c] = this->My_mat[r][c]+other_mat.My_mat[r][c];
        }
    }
    return new_mat;
}

zich::Matrix& zich::Matrix::operator+=(const Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //add the values to the old matrix
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            this->My_mat[r][c] +=other_mat.My_mat[r][c];
        }
    }
    return *this;
}

zich::Matrix zich::Matrix::operator-()
{
    zich::Matrix new_mat{this->number_rows,this->number_colums};
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            new_mat.My_mat[r][c] = -this->My_mat[r][c];
        }
    }
    return new_mat;
}

zich::Matrix zich::Matrix::operator-(const Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //make new matrix and full the value
    zich::Matrix new_mat{this->number_rows,this->number_colums};
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            new_mat.My_mat[r][c] = this->My_mat[r][c]-other_mat.My_mat[r][c];
        }
    }
    return new_mat;
}

zich::Matrix& zich::Matrix::operator-=(const Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //sub the values to the old matrix
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            this->My_mat[r][c] -=other_mat.My_mat[r][c];
        }
    }
    return *this;
}

bool zich::Matrix::operator==(const zich::Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //run other all the matrix and if find somthing not equal return false otherwiss return true
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            if(this->My_mat[r][c] != other_mat.My_mat[r][c])
            {
                return false;
            }
        }
    }
    return true;
}

bool zich::Matrix::operator!=(const zich::Matrix& other_mat)
{
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //run other all the matrix and if find somthing not equal return true otherwiss return false
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            if(this->My_mat[r][c] != other_mat.My_mat[r][c])
            {
                return true;
            }
        }
    }
    return false;
}

bool zich::Matrix::operator>(const zich::Matrix& other_mat)
{
    bool flage = false;
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //calculate the sum that every time we add one matrix and sub the other
    double sum = 0.0;
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            sum+= this->My_mat[r][c];
            sum-=other_mat.My_mat[r][c];
        }
    }
    // if the sum is biger the 0 so this>other else this <= other
    if(sum>0)
    {
        flage = true;
    }
    return flage;
}

bool zich::Matrix::operator>=(const zich::Matrix& other_mat)
{
    bool flage = false;
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //calculate the sum that every time we add one matrix and sub the other
    double sum = 0.0;
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            sum+= this->My_mat[r][c];
            sum-=other_mat.My_mat[r][c];
        }
    }
    // if the sum is biger or equal to 0 so this>=other else this < other
    if(sum>=0)
    {
        flage = true;
    }
    return flage;
}

bool zich::Matrix::operator<(const zich::Matrix& other_mat)
{
    bool flage = false;
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //calculate the sum that every time we add one matrix and sub the other
    double sum = 0.0;
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            sum+= this->My_mat[r][c];
            sum-=other_mat.My_mat[r][c];
        }
    }
    // if the sum is smaller then 0 so this<other else this >= other
    if(sum<0)
    {
        flage = true;
    }
    return flage;
}

bool zich::Matrix::operator<=(const zich::Matrix& other_mat)
{
    bool flage = false;
    //check if the matrix are in the same size else throw
    if((this->number_colums!=other_mat.number_colums)||(this->number_rows!=other_mat.number_rows))
    {
        throw std::invalid_argument("the matrixs is not in the same size");
    }
    //calculate the sum that every time we add one matrix and sub the other
    double sum = 0.0;
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            sum+= this->My_mat[r][c];
            sum-=other_mat.My_mat[r][c];
        }
    }
    // if the sum is smaller or equal to 0 so this<other else this < other
    if(sum<=0)
    {
        flage = true;
    }
    return flage;
}

zich::Matrix& zich::Matrix::operator++()
{
    //add 1 to all the matrix values
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            ++this->My_mat[r][c];
            
        }
    }
    return *this;
}

zich::Matrix zich::Matrix::operator++(int)
{
    //make new matrix and then make for it dip copy
    zich::Matrix new_mat{};
    new_mat=*this;

    //add 1 to all the matrix values
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            ++this->My_mat[r][c];
            
        }
    }
    return new_mat;
}

zich::Matrix& zich::Matrix::operator--()
{
    //sub 1 to all the matrix values
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            --this->My_mat[r][c];
            
        }
    }
    return *this;
}

zich::Matrix zich::Matrix::operator--(int)
{
    //make new matrix and then make for it dip copy
    zich::Matrix new_mat{};
    new_mat=*this;

    //sub 1 to all the matrix values
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            --this->My_mat[r][c];
            
        }
    }
    return new_mat;
}

zich::Matrix zich::Matrix::operator*(const Matrix& other_mat)
{
    //check that we can make * by check the mat1 colums == mat2 rows
    if(this->number_colums!=other_mat.number_rows)
    {
        throw std::invalid_argument("the numbers of colum is not like the other row number can make *");
    }

    //make new matrix in the size of the anser this.row , other.colums
    zich::Matrix new_mat{this->number_rows,other_mat.number_colums};

    // full the new matrix values
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            for(ulong curr = 0 ; curr < other_mat.number_rows; curr++)
            {
                new_mat.My_mat[r][c]+=this->My_mat[r][curr]*other_mat.My_mat[curr][c];
            }
        }
    }
    return new_mat;

}

zich::Matrix& zich::Matrix::operator*=(const Matrix& other_mat)
{
    //check that we can make * by check the mat1 colums == mat2 rows
    if(this->number_colums!=other_mat.number_rows)
    {
        throw std::invalid_argument("the numbers of colum is not like the other row number can make *");
    }

    //make new matrix in the size of the anser this.row , other.colums
    zich::Matrix new_mat{this->number_rows,other_mat.number_colums};

    // full the new matrix values
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            for(ulong curr = 0 ; curr < other_mat.number_rows; curr++)
            {
                new_mat.My_mat[r][c]+=this->My_mat[r][curr]*other_mat.My_mat[curr][c];
            }
        }
    }
    //copy the new matrix in to this
    *this = new_mat;

    return *this;
    
}

zich::Matrix zich::Matrix::operator*(const double scalar)
{
    //make new matrix in the same size
    zich::Matrix new_mat{this->number_rows,this->number_colums};

    // full the new matrix values for value*scalar
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            new_mat.My_mat[r][c]=this->My_mat[r][c]*scalar;
        }
    }
    return new_mat;
}

zich::Matrix& zich::Matrix::operator*=(const double scalar)
{
    // value*scalar 
    for(ulong r = 0; r < this->number_rows; r++)
    {
        for(ulong c = 0; c < this->number_colums; c++)
        {
            this->My_mat[r][c]*=scalar;
        }
    }
    return *this;
}

zich::Matrix zich::operator*(const double scalar,const Matrix& mat)
{
    //make new matrix in the same size
    zich::Matrix new_mat{mat.number_rows,mat.number_colums};

    // full the new matrix values for value*scalar
    for(ulong r = 0; r < new_mat.number_rows; r++)
    {
        for(ulong c = 0; c < new_mat.number_colums; c++)
        {
            new_mat.My_mat[r][c]=mat.My_mat[r][c]*scalar;
        }
    }
    return new_mat;
}

std::ostream& zich::operator<<(std::ostream& My_output,const Matrix& mat)
{
    for(ulong r = 0; r < mat.number_rows; r++)
    {
        My_output<<"[";
        for(ulong c = 0; c < mat.number_colums; c++)
        {
            My_output<<mat.My_mat[r][c]<<" ";
        }
        My_output<<"]"<<std::endl;
    }
    return My_output;
}


std::istream& zich::operator>>(std::istream& My_input,const Matrix& mat)
{
    return My_input;
}