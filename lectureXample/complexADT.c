//
// Created by liu on 19-3-18.
//  1

typedef struct {
    float realPart;
    float imagPart;
}complex;

void assignComplex(complex &Z, float realval, float imagval);
void add(complex z1, complex z2, complex &sum){
    sum.realPart = z1.realPart + z2.realPart;
    sum.imagPart = z1.imagPart + z2.imagPart;
}

complex z1,z2,z3,z4,z;
float realPart,imagPart;
assignComplex(z1,8.0,6.0);
assignComplex(z2,4.0,3.0);
add(z1,z2,z3);
multiply(z1,z2,z3);
if(division(z4,z3,z)){
    getReal(z,realPart);
    getImag(z,imagPart);
}

