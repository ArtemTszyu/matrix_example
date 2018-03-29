#include "matrix.hpp"
template <typename T>
matrix_t::matrix_t()
    : elements_{ nullptr }
    , rows_{ 0 }
    , collumns_{ 0 }
{
}

matrix_t<T>::matrix_t(matrix_t<T> const& other)
{
    this->rows_ = other.rows_;
    this->collumns_ = other.collumns_;
    this->elements_ = new T*[rows_];
    for (std::size_t i = 0; i < this->rows_; i++)
    {
        elements_[i] = new float[this->collumns_];
        for (std::size_t j = 0; j < this->collumns_; j++)
        {
            this->elements_[i][j] = other.elements_[i][j];
        }
    }
}

matrix_t& matrix_t::operator=(matrix_t const& other)
{
    for (unsigned int i = 0; i < this->rows_; i++)
    {
        delete[] this->elements_[i];
    }
    delete[] this->elements_;
    this->rows_ = other.rows_;
    this->collumns_ = other.collumns_;
    this->elements_ = new float*[rows_];
    for (unsigned int i = 0; i < this->rows_; i++)
    {
        this->elements_[i] = new float[this->collumns_];
        for (unsigned int j = 0; j < this->collumns_; j++)
        {
            this->elements_[i][j] = other.elements_[i][j];
        }
    }
    return *this;
}

matrix_t::~matrix_t()
{
    for (unsigned int i = 0; i < this->rows_; i++)
    {
        delete[] this->elements_[i];
    }
}

std::size_t matrix_t::rows() const
{
    return rows_;
}

std::size_t matrix_t::collumns() const
{
    return collumns_;
}

matrix_t matrix_t::operator+(matrix_t const& other) const
{
    matrix_t result;
    if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_)
    {
        result.elements_ = new float*[this->rows_];
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            result.elements_[i] = new float[this->collumns_];
        }
        result.rows_ = this->rows_;
        result.collumns_ = this->collumns_;

        for (std::size_t i = 0; i < result.rows_; i++)
        {
            for (std::size_t j = 0; j < result.collumns_; j++)
            {
                result.elements_[i][j] = elements_[i][j] + other.elements_[i][j];
            }
        }
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return result;
}

matrix_t matrix_t::operator-(matrix_t const& other) const
{
    matrix_t result;
    if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_)
    {
        result.elements_ = new float*[this->rows_];
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            result.elements_[i] = new float[this->collumns_];
        }
        result.rows_ = this->rows_;
        result.collumns_ = this->collumns_;
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            for (std::size_t j = 0; j < this->collumns_; j++)
            {
                result.elements_[i][j] = this->elements_[i][j] - other.elements_[i][j];
            }
        }
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return result;
}

matrix_t matrix_t::operator*(matrix_t const& other) const
{
    matrix_t result;
    if (this->collumns_ == other.rows_)
    {
        result.rows_ = this->rows_;
        result.collumns_ = other.collumns_;
        result.elements_ = new float*[this->rows_];
        for (std::size_t i = 0; i < this->rows_; ++i)
        {
            result.elements_[i] = new float[other.collumns_];
        }
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            for (std::size_t j = 0; j < other.collumns_; j++)
            {
                int res = 0;
                for (std::size_t k = 0; k < this->collumns_; k++)
                {
                    res += this->elements_[i][k] * other.elements_[k][j];
                }
                result.elements_[i][j] = res;
            }
        }
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return result;
}

matrix_t& matrix_t::operator-=(matrix_t const& other)
{
    if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_)
    {
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            for (std::size_t j = 0; j < this->collumns_; j++)
            {
                this->elements_[i][j] -= other.elements_[i][j];
            }
        }
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return *this;
}

matrix_t& matrix_t::operator+=(matrix_t const& other)
{

    if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_)
    {
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            for (std::size_t j = 0; j < this->collumns_; j++)
            {
                this->elements_[i][j] += other.elements_[i][j];
            }
        }
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return *this;
}

matrix_t& matrix_t::operator*=(matrix_t const& other)
{
    if (this->collumns_ == other.rows_)
    {
        matrix_t result;
        result.rows_ = this->rows_;
        result.collumns_ = other.collumns_;
        result.elements_ = new float*[this->rows_];
        for (std::size_t i = 0; i < this->rows_; ++i)
        {
            result.elements_[i] = new float[other.collumns_];
        }
        for (std::size_t i = 0; i < this->rows_; i++)
        {
            for (std::size_t j = 0; j < other.collumns_; j++)
            {
                int res = 0;
                for (std::size_t k = 0; k < this->collumns_; k++)
                {
                    res += this->elements_[i][k] * other.elements_[k][j];
                }
                result.elements_[i][j] = res;
            }
        }
        *this = result;
    }
    else
    {
        std::cout << std::endl << "fail";
        exit(0);
    }
    return *this;
}

std::istream& matrix_t::read(std::istream& stream)
{
    std::size_t rows;
    std::size_t collumns;
    char symbol;

    bool success = true;
    if (stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns)
    {
        float** elements = new float*[rows];
        for (std::size_t i = 0; success && i < rows; ++i)
        {
            elements[i] = new float[collumns];
            for (std::size_t j = 0; j < collumns; ++j)
            {
                if (!(stream >> elements[i][j]))
                {
                    success = false;
                    break;
                }
            }
        }

        if (success)
        {
            for (std::size_t i = 0; i < rows_; ++i)
            {
                delete[] elements_[i];
            }
            delete[] elements_;

            rows_ = rows;
            collumns_ = collumns;
            elements_ = elements;
        }
        else
        {
            for (std::size_t i = 0; i < rows; ++i)
            {
                delete[] elements[i];
            }
            delete[] elements;
        }
    }
    else
    {
        success = false;
    }

    if (!success)
    {
        stream.setstate(std::ios_base::failbit);
    }

    return stream;
}

std::ostream& matrix_t::write(std::ostream& stream) const
{
    stream << rows_ << ", " << collumns_;
    for (std::size_t i = 0; i < rows_; ++i)
    {
        stream << '\n';
        for (std::size_t j = 0; j < collumns_; ++j)
        {
            stream << elements_[i][j];
            if (j != rows_ - 1)
            {
                stream << ' ';
            }
        }
    }

    return stream;
}
