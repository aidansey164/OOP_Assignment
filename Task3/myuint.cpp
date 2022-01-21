#include "myuint.hpp"


// converting a decimal number to a binary
std::string decimalToBinary(int dec)
{
    std::string bin = "";

    while (dec != 0)
    {
        bin = (dec % 2 == 0 ? "0" : "1") + bin;
        dec /= 2;
    }

    return bin;
}

// Constructor that accepts and integer and converts it to type myuint
template <int T>
myuint<T>::myuint(int num)
{

    try
    {
        floor(log2(T)) == log2(T);  // checking criteria that correct number of bits are present
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n error number of bits, myuint  supports unsigned integers with 2^n bits" << std::endl;
    }

    if (T <= 0)
    {
        std::cerr << "\n error number of bits, myuint  supports unsigned integers with 2^n bits" << std::endl;
    }

    myuint<T>::number = decimalToBinary(num);


    while (number.size() != T)
    {
        number.insert(0, "0");
    }
}

// Empty constructor for myuint
template <int T>
myuint<T>::myuint()
{

    try
    {
        floor(log2(T)) == log2(T); // checking criteria that correct number of bits are present
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n error number of bits, myuint  supports unsigned integers with 2^n bits" << std::endl;
    }

    if (T <= 0)
    {
        std::cerr << "\n error number of bits, myuint  supports unsigned integers with 2^n bits" << std::endl;
    }
}

// setting myuint value
template <int T>
void myuint<T>::setNumber(std::string num)
{
    myuint<T>::number = num;
}

// Get the current myuint value
template <int T>
std::string myuint<T>::getNumber()
{
    return myuint<T>::number;
}

// Function that overloads the addition operator
template <int T>
myuint<T> myuint<T>::operator+(myuint<T> num)
{
    std::string firstNum = myuint<T>::number;
    std::string secondNum = num.getNumber();
    std::string resultString = "";

    int temp = 0;
    int num1_Size = firstNum.size() - 1;
    int num2_Size = secondNum.size() - 1;
    while (num1_Size >= 0 || num2_Size >= 0 || temp == 1)
    {
        temp += ((num1_Size >= 0) ? firstNum[num1_Size] - '0' : 0);
        temp += ((num2_Size >= 0) ? secondNum[num2_Size] - '0' : 0);
        resultString = char(temp % 2 + '0') + resultString;

        temp = temp / 2;
        num1_Size--;
        num2_Size--;
    }

    if (resultString.size() > T)
    {
        resultString = resultString.substr(resultString.size() - T, resultString.size()); // If  result contains more bits than the size of the declaration of bits in myuint, we shorten it to fit it in T
    }

    myuint<T> resultMyuint;
    resultMyuint.setNumber(resultString);

    return resultMyuint;
}

// Function that overloads the subtraction operator
template <int T>
myuint<T> myuint<T>::operator-(myuint<T> num)
{

    std::string subnum = num.getNumber(); // setting number to subtract

    for (int i = 0; i < subnum.size(); i++)
    {
        subnum[i] == '0' ? (subnum[i] = '1') : (subnum[i] = '0');
    }

    num.setNumber(subnum);

    num += 1;

    return myuint<T>::operator+(num);
}

// overloading  += operator
template <int T>
myuint<T> myuint<T>::operator+=(myuint<T> num)
{
    return *this = *this + num;
}

// overloading -= operator
template <int T>
myuint<T> myuint<T>::operator-=(myuint<T> num)
{
    return *this = *this - num;
}

// Overloading left shift operator
template <int T>
myuint<T> myuint<T>::operator<<(int num)
{
    std::string left_shift = myuint<T>::number;
    int i;
    for (i = 0; i < num; i++)
    {
        left_shift.erase(left_shift.begin(), left_shift.begin() + 1);
        left_shift.append("0");
    }

    myuint<T> result;
    result.setNumber(left_shift);
    return result;
}

// Overloading right shift operator
template <int T>
myuint<T> myuint<T>::operator>>(int num)
{
    std::string right_shift = myuint<T>::number;
    for (int i = 0; i < num; i++)
    {
        right_shift .insert(0, "0");
    }

    right_shift .erase(right_shift .end() - num, right_shift .end());   // If  result contains more bits than the size of the declaration of bits in myuint, we shorten it to fit it in T

    myuint<T> result;
    result.setNumber(right_shift );

    return result;
}


// Function for multiplication operator
template <int T>
myuint<T> myuint<T>::operator*(myuint<T> num)
{
    std::vector<myuint<T>> numtoADD;
    std::string numberB = num.getNumber();
    std::string numberA = myuint<T>::number;
    std::string ans = "";
    int i, j;
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            if (numberA[i] == '1' & numberB[j] == '1')
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
        myuint<T> partAns;
        partAns.setNumber(ans);

        numtoADD.push_back(partAns);
        ans = "";
    }

    myuint<T> answer(0);
    int k;
    for (k = 0; k< numtoADD.size(); k++)
    {
        answer += numtoADD.back() << k;
        numtoADD.pop_back();
    }
    return answer;
}

// Overloading greater than >= operator
template <int T>
bool myuint<T>::operator>=(myuint<T> num)
{
    return (*this > num || *this == num);
}

// Overloading the '>' operator
template <int T>
bool myuint<T>::operator>(myuint<T> num)
{
    for (int i = 0; i < T; i++)
    {
        if (myuint<T>::number[i] != num.number[i])
        {
            if (myuint<T>::number[i] == '1')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

// Overloading the '==' operator
template <int T>
bool myuint<T>::operator==(myuint<T> num)
{
    for (int i = 0; i < T; i++)
    {
        if (myuint<T>::number[i] != num.number[i])
        {
            return false;
        }
    }
    return true;
}


// Function for division operator
template <int T>
myuint<T> myuint<T>::operator/(myuint<T> num)
{
    int i = 1;
    while ((*this -= num) >= num)
    {
        i++;
    }
    myuint<T> ans = (i);
    return ans;
}
// Function for  modulus number
template <int T>
myuint<T> myuint<T>::operator%(myuint<T> num)
{
    myuint<T> answer = *this;
    while ((answer -= num) >= num)
        ;
    return answer;
}
// Converting from a type of myuinit to any number type as specified
template <int T>
template <typename type>
type myuint<T>::convert_to()
{
    type result = 0;
    int n = 0;
    for (int i = T - 1; i >= 0; i--)
    {
        if (myuint::number[i] == '1')
        {
            result += pow(2, n);
        }
        n++;
    }
    return result;
}

