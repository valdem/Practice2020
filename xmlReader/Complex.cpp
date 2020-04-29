#define CATCH_CONFIG_MAIN 

#include <limits>
#include "catch.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Complex
{
public:
    float real;
    float imag;

	Complex();

	Complex(float left, float right){
		real = left;
		imag = right;
	}

	void i(float a, float b) { real = a; imag = b; }
};

Complex operator+(const Complex& left, const Complex& right){
        Complex result(0, 0);
	result.real = left.real + right.real + 1; //!
        result.imag = left.imag + right.imag;
        return result;
}

Complex operator-(const Complex& left, const Complex& right){
        Complex result(0, 0);
        result.real = left.real - right.real;
        result.imag = left.imag - right.imag;
        return result;
}

Complex operator*(const Complex& left, const Complex& right){
	Complex result(0, 0);
	result.real = left.real * right.real - left.imag * right.imag;
	result.imag = left.real * right.imag + right.real * left.imag;
	return result;
}

Complex operator/(const Complex& left, const Complex& right){
	Complex result(0, 0);
	result.real = (left.real * right.real + left.imag * right.imag) / (pow(right.real, 2) + pow(right.imag, 2));
	result.imag = (left.imag * right.real - left.real * right.imag) / (pow(right.real, 2) + pow(right.imag, 2));
	return result;
}
/*
Complex con(Complex *a)
{
	Complex c(0, 0);
        c.real = a->real;
        c.imag = (a->imag)*(-1);
	return c;
}
*/
bool operator==(const Complex& left, const Complex& right){
	//typedef std::numeric_limits< double > dbl;
	//cout.precision(dbl::max_digits10);
	//cout << left.real << " --- " << left.imag << " AND " << right.real << " --- " << right.imag << endl;
	return memcmp(&left, &right, sizeof(left)) == 0;
}

bool dbl_eql(const double& left, const double& right){
	return memcmp(&left, &right, sizeof(right)) == 0;
}

double arg(Complex *a){
	double result = atan((a->imag) / (a->real));
	//typedef std::numeric_limits< double > dbl;
	//cout.precision(dbl::max_digits10);
	//cout << a->real << " --- " << a->imag << " AND " << result << endl;
	return result;
}

double mod(Complex *a){
	double result = sqrt((a->real)*(a->real) + (a->imag)*(a->imag));
	//typedef std::numeric_limits< double > dbl;
	//cout.precision(dbl::max_digits10);
	//cout << a->real << " --- " << a->imag << " AND " << result << endl;
	return result;
}

TEST_CASE("Complex") {

	Complex First( 2, 4 );
	Complex Second( 5, -6 );
	Complex wi ( 0, 0 );
	SECTION("+"){
		wi.i(7, -2);
		REQUIRE( First + Second == wi);
	}

	SECTION("-"){
		wi.i(-3, 10);
		REQUIRE( First - Second == wi);
		wi.i(3, -10);
		REQUIRE( Second - First == wi);
	}

	SECTION("*"){
		wi.i(34, 8);
		REQUIRE( First * Second == wi);
	}

	SECTION("/"){
		wi.i(-0.2295081967213115, 0.5245901639344262);
		REQUIRE( First / Second == wi);
		wi.i(-0.7, -1.6);
		REQUIRE( Second / First == wi);
	}
}

SCENARIO( "MOD AND ARG" ) {

    GIVEN( "COmplex number" ) {
        Complex v( 3, 4 );
	double res = 0;


        REQUIRE( dbl_eql(mod(&v), 5 ) );
        REQUIRE( dbl_eql(arg(&v), 0.92729520797729492 ) );

        WHEN( "Complex number changes" ) {
            v.i(-3, -6);

            THEN( "Mod and Arg changes" ) {
                REQUIRE( dbl_eql(mod(&v), 6.7082037925720215) );
                REQUIRE( dbl_eql(arg(&v), 1.1071487665176392) );
            }
        }
    }
}
