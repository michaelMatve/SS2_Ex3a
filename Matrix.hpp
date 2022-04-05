#include <iostream>
#include <stdexcept>
#include <vector>

namespace zich
{
    class Matrix{
        private:
            std::vector<std::vector<double>> My_mat;
            ulong number_rows;
            ulong number_colums;
        public:
            //defult constarctor
            Matrix(){};
            // set the matrix to 0
            Matrix(ulong row, ulong colum){
                this->number_colums = colum;
                this->number_rows = row;
                this->My_mat.assign(this->number_rows, std::vector<double>(this->number_colums));
                for(ulong r = 0; r < this->number_rows; r++)
                {
                    for(ulong c = 0; c < this->number_colums; c++)
                    {
                        this->My_mat[r][c] = 0;
                    }
                }
            };

            Matrix(std::vector<double> temp_vector,ulong row, ulong colum){
                this->number_colums = colum;
                this->number_rows = row;
                this->My_mat.assign(this->number_rows, std::vector<double>(this->number_colums));
                for(ulong r = 0; r < this->number_rows; r++)
                {
                    for(ulong c = 0; c < this->number_colums; c++)
                    {
                        this->My_mat[r][c] = temp_vector[(r*this->number_colums)+c];
                    }
                }

            };
            // make deep copy of the matrix
            Matrix& operator=(const Matrix& other_mat)
            {
                
                this->number_colums = other_mat.number_colums;
                this->number_rows = other_mat.number_rows;
                this->My_mat.assign(this->number_rows, std::vector<double>(this->number_colums));
                for(ulong r = 0; r < this->number_rows; r++)
                {
                    for(ulong c = 0; c < this->number_colums; c++)
                    {
                        this->My_mat[r][c] = other_mat.My_mat[r][c];
                    }
                }
                return *this;
            }
            Matrix operator+();
            Matrix operator+(const Matrix& other_mat);
            Matrix& operator+=(const Matrix& other_mat);
            
            Matrix operator-();
            Matrix operator-(const Matrix& other_mat);
            Matrix& operator-=(const Matrix& other_mat);
    
            bool operator==(const Matrix& other_mat);
            bool operator!=(const Matrix& other_mat);
            bool operator>(const Matrix& other_mat);
            bool operator>=(const Matrix& other_mat);
            bool operator<(const Matrix& other_mat);
            bool operator<=(const Matrix& other_mat);
    
            Matrix& operator++();
            Matrix operator++(int);
            
            Matrix& operator--();
            Matrix operator--(int);
    
            Matrix operator*(const Matrix& other_mat);
            Matrix& operator*=(const Matrix& other_mat);
            Matrix operator*(double scalar);
            Matrix& operator*=(double scalar);
            friend Matrix operator*(double scalar,const Matrix& mat);
    
            friend std::ostream& operator<<(std::ostream& My_output,const Matrix& mat);
            friend std::istream& operator>>(std::istream& My_input,const Matrix& mat);
        
    };
} // namespace zich
