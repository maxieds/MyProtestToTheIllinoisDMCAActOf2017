// ************************************************************
// *                                                          *
// *  main.cpp                                                *
// *                                                          *
// *  File for simple testing of integer array class          *
// *                                                          *
// *  Written October 2004 by Jason Zych                      *
// *                                                          *
// ************************************************************

#include <iostream>
using namespace std;

#include "intarray.h"

int main()
{
   cout << "*** We are testing array code" << endl << endl;
   cout << "*** Testing arrays of integers:" << endl << endl;
   IntArray integerArray1;
 
   cout << "*** Values for array created with no-argument constructor:";
   cout << endl; 
   cout << "lower: " << integerArray1.lower() << endl;
   cout << "upper: " << integerArray1.upper() << endl;
   cout << "size: " << integerArray1.size() << endl;
   cout << endl << endl;

   IntArray integerArray2(-6, 4);
   cout << "*** Values for array created with two-int constructor:" << endl;
   cout << "lower: " << integerArray2.lower() << endl;
   cout << "upper: " << integerArray2.upper() << endl;
   cout << "size: " << integerArray2.size() << endl;
   cout << endl << endl;

   cout << "*** Initialize and print out array:" << endl;
   int intVal = 3;
   integerArray2.initialize(intVal);
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
   {
      cout << "i: " << i << "   val: " << integerArray2[i] << endl; 
      integerArray2[i] = 4;
   }
   cout << endl << endl;

   cout << "*** print out array again:" << endl;
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray2[i] << endl; 
   cout << endl << endl;

   cout << "*** setBounds call, lower--->    and upper---->" << endl;
   integerArray2.setBounds(-4, 7);
   cout << "lower: " << integerArray2.lower() << endl;
   cout << "upper: " << integerArray2.upper() << endl;
   cout << "size: " << integerArray2.size() << endl;
   integerArray2[5] = 19;
   integerArray2[6] = 20;
   integerArray2[7] = 21;
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray2[i] << endl; 
   cout << endl << endl;

   cout << "*** setBounds call <-----lower and  <-----upper" << endl;
   integerArray2.setBounds(-8, 2);
   cout << "lower: " << integerArray2.lower() << endl;
   cout << "upper: " << integerArray2.upper() << endl;
   cout << "size: " << integerArray2.size() << endl;
   integerArray2[-8] = 360;
   integerArray2[-7] = 361;
   integerArray2[-6] = 362;
   integerArray2[-5] = 363;
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray2[i] << endl;
   cout << endl << endl;


   cout << "*** setBounds call <-----lower and  upper---->" << endl;
   integerArray2.setBounds(-13, 5);
   cout << "lower: " << integerArray2.lower() << endl;
   cout << "upper: " << integerArray2.upper() << endl;
   cout << "size: " << integerArray2.size() << endl;
   integerArray2[-13] = 91;
   integerArray2[-12] = 92;
   integerArray2[-11] = 93;
   integerArray2[-10] = 94;
   integerArray2[-9] = 95;
   integerArray2[5] = 96;
   integerArray2[4] = 97;
   integerArray2[3] = 98;
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray2[i] << endl;
   cout << endl << endl;


   cout << "*** setBounds call lower-----> and <------upper" << endl;
   integerArray2.setBounds(-2, 1);
   cout << "lower: " << integerArray2.lower() << endl;
   cout << "upper: " << integerArray2.upper() << endl;
   cout << "size: " << integerArray2.size() << endl;
   for (int i = integerArray2.lower(); i <= integerArray2.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray2[i] << endl;
   cout << endl << endl;


   cout << "*** copy constructor call:" << endl;
   const IntArray integerArray3(integerArray2);
   cout << endl;

   cout << "*** const operator[]:" << endl;
   cout << "lower: " << integerArray3.lower() << endl;
   cout << "upper: " << integerArray3.upper() << endl;
   cout << "size: " << integerArray3.size() << endl;
   for (int i = integerArray3.lower(); i <= integerArray3.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray3[i] << endl;
   cout << endl << endl;
   // integerArray3[0] = 5;
   cout << endl;

   cout << "*** assignment call:" << endl;
   integerArray1 = integerArray2;
   cout << endl;
   cout << "lower: " << integerArray1.lower() << endl;
   cout << "upper: " << integerArray1.upper() << endl;
   cout << "size: " << integerArray1.size() << endl;
   for (int i = integerArray1.lower(); i <= integerArray1.upper(); ++i)
      cout << "i: " << i << "   val: " << integerArray1[i] << endl;
   cout << endl << endl;


   return EXIT_SUCCESS; 
}

